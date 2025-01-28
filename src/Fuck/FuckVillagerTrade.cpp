#include "Fuck.h"
#include <ll/api/memory/Hook.h>
#include <mc/nbt/CompoundTag.h>
#include <mc/network/packet/UpdateTradePacket.h>
#include <mc/world/item/trading/MerchantRecipe.h>

namespace FuckRestrictions {

LL_TYPE_INSTANCE_HOOK(IsOutOfUsesHook, HookPriority::Normal, MerchantRecipe, &MerchantRecipe::isOutOfUses, bool) {
    return false;
}
// Make sure continuous trading
LL_TYPE_INSTANCE_HOOK(
    UpdateTradePacketHook,
    HookPriority::Normal,
    UpdateTradePacket,
    &UpdateTradePacket::$write,
    void,
    BinaryStream& stream
) {
    for (auto& recipe : (*this->mData)["Recipes"].get<ListTag>()) {
        recipe["maxUses"] = INT_MAX;
        recipe["uses"]    = INT_MIN;
    }
    origin(stream);
}

void FuckVillagerTrade() { ll::memory::HookRegistrar<IsOutOfUsesHook, UpdateTradePacketHook>().hook(); }

} // namespace FuckRestrictions
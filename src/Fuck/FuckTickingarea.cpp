#include "Fuck.h"
#include <libhat/Scanner.hpp>
#include <libhat/Signature.hpp>
#include <ll/api/memory/Memory.h>
#include <mc/world/level/ticking/TickingAreasManager.h>

namespace FuckRestrictions {

void FuckTickingarea() {
    auto* targetFunc = reinterpret_cast<std::byte*>(ll::memory::toFuncPtr(&TickingAreasManager::_addArea));
    static constexpr auto pattern =
        hat::compile_signature<"72 0A B8 01 00 00 00 E9 A9 03 00 00 83 7E 24 64 7E 07 33 C0 E9 9C 03 00 00">();
    auto result = hat::find_pattern(targetFunc, targetFunc + 0xD0, pattern);
    if (!result.has_result()) {
        return logger.error("Failed to find pattern for TickingAreasManager::_addArea");
    }
    ll::memory::modify(result.get(), pattern.size(), [&result]() { std::memset(result.get(), 0x90, pattern.size()); });
}

} // namespace FuckRestrictions
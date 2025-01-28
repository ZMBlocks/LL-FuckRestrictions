#include "Fuck.h"
#include <libhat/Scanner.hpp>
#include <libhat/Signature.hpp>
#include <ll/api/memory/Memory.h>
#include <mc/server/commands/standard/EnchantCommand.h>

namespace FuckRestrictions {

void FuckEnchantCmd() {
    auto*                 targetFunc = reinterpret_cast<std::byte*>(ll::memory::toFuncPtr(&EnchantCommand::$execute));
    static constexpr auto pattern    = hat::compile_signature<"E8 13 2E 20 01 84 C0 0F 85 22 01 00 00">();
    auto                  result     = hat::find_pattern(targetFunc, targetFunc + 0xB5, pattern);
    if (!result.has_result()) {
        return logger.error("Failed to find pattern for EnchantCommand::execute");
    }
    ll::memory::modify(result.get(), pattern.size(), [&result]() {
        static constexpr std::array<uchar, 13> replace =
            {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9, 0x23, 0x01, 0x00, 0x00, 0x90};
        for (size_t index = 0; index < replace.size(); ++index) {
            std::memset(result.get() + index, replace[index], 1);
        }
    });
}

} // namespace FuckRestrictions
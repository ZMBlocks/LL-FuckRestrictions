#include "Fuck.h"
#include <libhat/Scanner.hpp>
#include <libhat/Signature.hpp>
#include <ll/api/memory/Memory.h>
#include <mc/server/commands/standard/FillCommand.h>

namespace FuckRestrictions {

void FuckFill() {
    auto*                 targetFunc = reinterpret_cast<std::byte*>(ll::memory::toFuncPtr(&FillCommand::$execute));
    static constexpr auto pattern    = hat::compile_signature<"41 81 FF 00 80 00 00 0F 8E 8C 02 00 00">();
    auto                  result     = hat::find_pattern(targetFunc, targetFunc + 0x158, pattern);
    if (!result.has_result()) {
        return logger.error("Failed to find pattern for FillCommand::execute");
    }
    ll::memory::modify(result.get(), pattern.size(), [&result]() {
        static constexpr std::array<uchar, 13> replace =
            {0x45, 0x3B, 0xFF, 0x90, 0x90, 0x90, 0x90, 0x0F, 0x84, 0x8C, 0x02, 0x00, 0x00};
        for (size_t index = 0; index < replace.size(); ++index) {
            std::memset(result.get() + index, replace[index], 1);
        }
    });
}

} // namespace FuckRestrictions
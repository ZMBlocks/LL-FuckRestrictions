#include "Fuck.h"
#include <libhat/Scanner.hpp>
#include <libhat/Signature.hpp>
#include <ll/api/memory/Memory.h>
#include <mc/world/level/storage/GameRules.h>

namespace FuckRestrictions {

// void FuckGameRule() {
//     auto*                 targetFunc = reinterpret_cast<std::byte*>(ll::memory::toFuncPtr(&GameRules::_setGameRule));
//     static constexpr auto pattern = hat::compile_signature<"FF 15 F3 1E 17 01 44 0F B6 C0 84 C0 0F 84 CF 00 00 00">();
//     auto                  result  = hat::find_pattern(targetFunc, targetFunc + 0x155, pattern);
//     if (!result.has_result()) {
//         return logger.error("Failed to find pattern for GameRules::_setGameRule");
//     }
//     ll::memory::modify(result.get(), pattern.size(), [&result]() { std::memset(result.get(), 0x90, pattern.size()); });
// }

// void FuckGameRule2() {
//     auto*                 targetFunc = reinterpret_cast<std::byte*>(ll::memory::toFuncPtr(&GameRules::_setGameRule));
//     static constexpr auto pattern = hat::compile_signature<"FF 15 F3 1E 17 01 44 0F B6 C0 84 C0 0F 84 CF 00 00 00">();
//     auto                  result  = hat::find_pattern(targetFunc, targetFunc + 0x155, pattern);
//     if (!result.has_result()) {
//         return logger.error("Failed to find pattern for GameRules::_setGameRule");
//     }
//     ll::memory::modify(result.get(), pattern.size(), [&result]() { std::memset(result.get(), 0x90, pattern.size()); });
// }

} // namespace FuckRestrictions
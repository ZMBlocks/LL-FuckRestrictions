#include "Fuck.h"
#include <libhat/Scanner.hpp>
#include <libhat/Signature.hpp>
#include <ll/api/memory/Memory.h>
#include <mc/world/level/block/actor/PistonBlockActor.h>

namespace FuckRestrictions {

void FuckPiston1() {
    auto* targetFunc = reinterpret_cast<std::byte*>(ll::memory::toFuncPtr(&PistonBlockActor::_attachedBlockWalker));
    static constexpr auto pattern = hat::compile_signature<"48 83 FA 0C 0F 96 C0">();
    auto                  result  = hat::find_pattern(targetFunc, targetFunc + 0x515, pattern);
    if (!result.has_result()) {
        return logger.error("Failed to find pattern for PistonBlockActor::_attachedBlockWalker");
    }
    ll::memory::modify(result.get(), pattern.size(), [&result]() {
        static constexpr std::array<uchar, 7> replace = {0x48, 0x83, 0xFA, 0x0C, 0xB0, 0x01, 0x90};
        for (size_t index = 0; index < replace.size(); ++index) {
            std::memset(result.get() + index, replace[index], 1);
        }
    });
}

void FuckPiston2() {
    auto* targetFunc = reinterpret_cast<std::byte*>(ll::memory::toFuncPtr(&PistonBlockActor::_checkAttachedBlocks));
    static constexpr auto pattern = hat::compile_signature<"48 03 D0 48 83 FA 0C 0F 87 72 01 00 00">();
    auto                  result  = hat::find_pattern(targetFunc, targetFunc + 0x1ED, pattern);
    if (!result.has_result()) {
        return logger.error("Failed to find pattern for PistonBlockActor::_checkAttachedBlocks");
    }
    ll::memory::modify(result.get(), pattern.size(), [&result]() {
        static constexpr std::array<uchar, 13> replace =
            {0x48, 0x03, 0xD0, 0x48, 0x85, 0xD2, 0x90, 0x0F, 0x84, 0x72, 0x01, 0x00, 0x00};
        for (size_t index = 0; index < replace.size(); ++index) {
            std::memset(result.get() + index, replace[index], 1);
        }
    });
}

void FuckPiston() {
    FuckPiston1();
    FuckPiston2();
}

} // namespace FuckRestrictions
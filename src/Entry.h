#include "Config.h"
#include <ll/api/mod/NativeMod.h>
#include <optional>

namespace FuckRestrictions {
class Entry {
public:
    static Entry& getInstance();

    Entry() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    bool load();

    bool enable();

    bool disable();

    bool unload();

    Config& getConfig();

private:
    ll::mod::NativeMod&   mSelf;
    std::optional<Config> mConfig;
};

} // namespace FuckRestrictions
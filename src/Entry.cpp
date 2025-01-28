#include "Entry.h"
#include "Fuck/Fuck.h"
#include <ll/api/Config.h>
#include <mc/world/level/storage/GameRules.h>
#include <ll/api/mod/RegisterHelper.h>

namespace FuckRestrictions {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() {
    auto const& path = getSelf().getConfigDir() / "config.json";
    try {
        mConfig.emplace();
        ll::config::loadConfig(*mConfig, path);
    } catch (...) {}
    ll::config::saveConfig(*mConfig, path);
    return true;
}

bool Entry::enable() {
    if (getConfig().tickingarea) {
        FuckTickingarea();
    }
    if (getConfig().fill) {
        FuckFill();
    }
    if (getConfig().piston) {
        FuckPiston();
    }
    if (getConfig().villagerTrade) {
        FuckVillagerTrade();
    }
    if (getConfig().enchantCmd){
        FuckEnchantCmd();
    }
    // if (getConfig().gamerule) {
    //     FuckGameRule();
    // }
    return true;
}

bool Entry::disable() { return true; }

bool Entry::unload() { return true; }

Config& Entry::getConfig() { return *mConfig; }

} // namespace FuckRestrictions

LL_REGISTER_MOD(FuckRestrictions::Entry, FuckRestrictions::Entry::getInstance());
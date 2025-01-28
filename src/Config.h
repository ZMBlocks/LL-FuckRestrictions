namespace FuckRestrictions {
struct Config {
    int  version       = 1;
    bool tickingarea   = false; // 常加载区域范围和数量限制
    bool fill          = false; // fill命令数量限制
    bool piston        = false; // 活塞推动数量限制
    bool villagerTrade = false; // 村民交易次数限制
    bool enchantCmd    = false; // 附魔指令等级限制
    // bool gamerule      = false; // 游戏规则最大值限制
    // bool mobSpawn      = false; // 生物生成限制
};
} // namespace FuckRestrictions
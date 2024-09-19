#include "game/console/commands/heal.h"

#include "game/game.h"
#include "game/game_string.h"
#include "game/lara/common.h"
#include "game/lara/misc.h"

static COMMAND_RESULT Console_Cmd_Heal(const char *const args)
{
    if (!Game_IsPlayable()) {
        return CR_UNAVAILABLE;
    }

    ITEM_INFO *const lara_item = Lara_GetItem();
    if (lara_item->hit_points == LARA_MAX_HITPOINTS) {
        Console_Log(GS(OSD_HEAL_ALREADY_FULL_HP));
        return CR_SUCCESS;
    }

    lara_item->hit_points = LARA_MAX_HITPOINTS;
    Lara_Extinguish();
    Console_Log(GS(OSD_HEAL_SUCCESS));
    return CR_SUCCESS;
}

CONSOLE_COMMAND g_Console_Cmd_Heal = {
    .prefix = "heal",
    .proc = Console_Cmd_Heal,
};
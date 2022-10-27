.set LOCALID_LATI, 2

SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
	end

SouthernIsland_Interior_EventScript_TryRemoveLati::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LATI
	return

SouthernIsland_Interior_OnTransition:
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatios
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatias
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
	end

SouthernIsland_Interior_EventScript_SetUpLatios::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

SouthernIsland_Interior_EventScript_SetUpLatias::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_SetUpPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SouthernIsland_Interior_EventScript_SetBrendanGfx
	goto_if_eq VAR_RESULT, FEMALE, SouthernIsland_Interior_EventScript_SetMayGfx
	end

SouthernIsland_Interior_EventScript_SetBrendanGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_SetMayGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_TryLatiEncounter::
	lockall
	setvar VAR_0x8008, 12  @ Player's Y coordinate. Not read
	goto SouthernIsland_Interior_EventScript_Lati
	end

SouthernIsland_Interior_EventScript_Lati::
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	addobject LOCALID_LATI
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_LATI
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_LatiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_RanFromLati
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SouthernIsland_Interior_EventScript_RanFromLati
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
	releaseall
	end

SouthernIsland_Interior_EventScript_LatiDefeated::
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_RanFromLati::
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_Sign::
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_SetLatiosBattleVars::
	seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_EventScript_SetLatiasBattleVars::
	seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SouthernIsland_Interior_Movement_LatiApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SouthernIsland_Interior_SignLeft::
	msgbox SouthernIslandRedDreams, MSGBOX_SIGN
	setvar VAR_ROAMER_POKEMON, 1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	end

SouthernIslandRedDreams:
	.string "The decrepit sign says....\p"
	.string "The crimson flare is extinguished\n"
	.string "as easily as it becomes ignited.\p"
	.string "You feel as if your surroundings changed.$"

SouthernIsland_Interior_SignRight::
	msgbox SouthernIslandBlueDreams, MSGBOX_SIGN
	setvar VAR_ROAMER_POKEMON, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	end

SouthernIslandBlueDreams:
	.string "The decrepit sign says....\p"
	.string "The azure spark ceases action\n"
	.string "as its course becomes grounded out.\p"
	.string "You feel as if your surroundings changed.$"

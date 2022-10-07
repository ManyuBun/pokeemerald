NavelRock_Secret_MapScripts::
	.byte 0


NavelRock_Secret_Pc::
	lock
	msgbox Text_GinFightPrompt, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Script_PlayerAnsweredNoNavelRockSecret
	DoSpecialTrainerBattle TRAINER_J_GIN, NavelRock_Secret_GinDefeat
	release
	end

Script_PlayerAnsweredNoNavelRockSecret::
	.string "ABORTING PROGRAM...$"

Text_GinFightPrompt::
	.string "INITIALIZING PROGRAM...\n"
	.string "WILL YOU INITIATE THE\p"
	.string "EXPERIMENTAL BATTLE CHALLENGE\n"
	.string "AGAINST A FAMED TRAINER?$"

NavelRock_Secret_GinDefeat:
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"

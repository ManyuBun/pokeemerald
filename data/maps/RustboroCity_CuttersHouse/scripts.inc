RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM01
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "HIDDEN MACHINE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "An HM move is one that can be used\n"
	.string "by POKéMON outside of battle.\p"
	.string "Any POKéMON that's learned CUT can\n"
	.string "chop down thin trees if the TRAINER\l"
	.string "has earned the STONE BADGE.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"

Script_GiveEggDemoRustboroCutHouse::
	lock
	faceplayer
	msgbox Text_EggQuestionRustboroCutHouse, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Script_PlayerAnsweredNoRustboroCutHouse
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq Script_PlayerHasFullPartyRustboroCutHouse
	giveegg SPECIES_EEVEE
	playfanfare MUS_RG_GAME_FREAK
	msgbox Text_ReceivedEggRustboroCutHouse, MSGBOX_DEFAULT
	waitfanfare
	release
	end

Script_PlayerHasFullPartyRustboroCutHouse::
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	msgbox Text_PlayerHasFullPartyRustboroCutHouse, MSGBOX_DEFAULT
	release
	end

Script_PlayerAnsweredNoRustboroCutHouse::
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	msgbox Text_PlayerAnsweredNoRustboroCutHouse, MSGBOX_DEFAULT
	release
	end

Text_EggQuestionRustboroCutHouse:
	.string "Grrrrrr?$"

Text_PlayerAnsweredNoRustboroCutHouse:
	.string "Gao...$"

Text_ReceivedEggRustboroCutHouse:
	.string "{PLAYER} received the Egg!$"

Text_PlayerHasFullPartyRustboroCutHouse:
	.string "Your party is full.\n"
	.string "There's no room for this Egg.$"
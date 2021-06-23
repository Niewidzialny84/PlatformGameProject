#pragma once
#include "PlayableCharacter.h"

class Multi : public PlayableCharacter
{
public:
	Multi();
	bool virtual handleInput();
};
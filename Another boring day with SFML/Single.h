#pragma once
#include "PlayableCharacter.h"

class Single : public PlayableCharacter
{
public:
	Single();
	bool virtual handleInput();
};
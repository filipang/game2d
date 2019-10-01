#pragma once
#include <set>
#include "Interfaces.h"
#include "moony/Sprite.h"
#include "IUnknown.h"

class SpriteManager : public IRegisterUnk
{
public:
	static SpriteManager* instance;

	std::set<ISpritePtr> registeredList;

public:
	static SpriteManager* getInstance();

	SpriteManager();

	virtual void registerObj(IUnknownPtr obj) override;

	virtual void unregisterObj(IUnknownPtr obj) override;

	moony::Sprite getSpriteByName(std::string sp_name);
};
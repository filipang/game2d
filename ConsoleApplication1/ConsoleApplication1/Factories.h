#pragma once

#include "Interfaces.h"
#include "moony/Sprite.h"
#include "Entity.h"

bool CreateInstance(int clsid, int iid, void** ret)
{
	bool success = false;
	switch (clsid)
	{
	case CLS_Sprite:
	{
		moony::Sprite* toret = new moony::Sprite();
		success = toret->QueryInterface(iid, ret);
		if (!success) delete toret;
	} break;
	case CLS_Texture:
	{
		moony::Texture* toret = new moony::Texture();
		success = toret->QueryInterface(iid, ret);
		if (!success) delete toret;
	} break;
	case CLS_Entity:
	{
		Entity* toret; // constructor of entity to be added
		success = toret->QueryInterface(iid, ret);
		if (!success) delete toret;
	} break;
	}
	return success;
}
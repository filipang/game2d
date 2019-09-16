#pragma once

#include <string>
#include "IUnknown.h"
#include "SFML/Graphics.hpp"

enum iterfaces
{
	IID_IResource = 1,
	IID_ITexture,
	IID_IInputReciever,
	IID_IEventReciever,
	IID_ISerialize,
	IID_ISprite
};

class IResource : public virtual IUnknown
{
public:
	static const int myType = IID_IResource;

	virtual std::string GetName() PURE;
};

class ITexture : public virtual IUnknown
{
public:
	static const int myType = IID_ITexture;
};

class ISprite : public virtual IUnknown
{
public:
	static const int myType = IID_ISprite;
};

class IInputReciever : public virtual IUnknown
{
public:
	static const int myType = IID_IInputReciever;

	virtual void handleInput() PURE;
};

class IEventReciever : public virtual IUnknown
{
public:
	static const int myType = IID_IEventReciever;

	virtual void handleEvent(sf::Event e) PURE;
};

class ISerialize : public virtual IUnknown
{
public:
	static const int myType = IID_ISerialize;

	virtual size_t popFromBuffer(unsigned char* buffer, size_t offset) PURE;
	virtual size_t pushToBuffer(unsigned char* buffer, size_t offset) PURE;
	virtual size_t getSizeInBytes() PURE;
};

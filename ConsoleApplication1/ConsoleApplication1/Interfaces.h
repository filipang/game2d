#pragma once

#include <string>
#include "IUnknown.h"
#include "SFML/Graphics.hpp"
#include "UnkSmartPtr.h"

enum iterfaces
{
	IID_IResource = 1,
	IID_ITexture,
	IID_IInputReciever,
	IID_IEventReciever,
	IID_ISerialize,
	IID_ISprite,
	IID_IDrawable
};

class IResource : public virtual IUnknown
{
public:
	static const int myType = IID_IResource;

	virtual std::string GetName() PURE;
};
typedef UnkSmartPtr<IResource>	IResourcePtr;

class ITexture : public virtual IUnknown
{
public:
	static const int myType = IID_ITexture;
};
typedef UnkSmartPtr<ITexture>	ITexturePtr;

class IDrawable : public virtual IUnknown
{
public:
	static const int myType = IID_IDrawable;

	virtual void aquireResources() PURE;
	virtual void releaseResources() PURE;
};
typedef UnkSmartPtr<IDrawable>	IDrawablePtr;

class ISprite : public virtual IUnknown
{
public:
	static const int myType = IID_ISprite;
};
typedef UnkSmartPtr<ISprite>	ISpritePtr;

class IInputReciever : public virtual IUnknown
{
public:
	static const int myType = IID_IInputReciever;

	virtual void handleInput() PURE;
};
typedef UnkSmartPtr<IInputReciever>	IInputRecieverPtr;

class IEventReciever : public virtual IUnknown
{
public:
	static const int myType = IID_IEventReciever;

	virtual void handleEvent(sf::Event e) PURE;
};
typedef UnkSmartPtr<IEventReciever>	IEventRecieverPtr;

class ISerialize : public virtual IUnknown
{
public:
	static const int myType = IID_ISerialize;

	virtual size_t popFromBuffer(unsigned char* buffer, size_t offset) PURE;
	virtual size_t pushToBuffer(unsigned char* buffer, size_t offset) PURE;
	virtual size_t getSizeInBytes() PURE;
};
typedef UnkSmartPtr<ISerialize>	ISerializePtr;

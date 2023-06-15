#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#pragma once

#include "Resource.h"
#include "ResourceIdentifiers.h"

//#include <memory>

class ResourceManager
{
private:
public:
	Resource<sf::Font, FontIDs> fonts;
	Resource<sf::Texture, TextureIDs> textures;
	Resource<sf::SoundBuffer, SoundIDs> sounds;
};


#endif // !RESOURCE_MANAGER_H

#ifndef RESOURCE_H
#define RESOURCE_H
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>

template<typename ResourceType, typename Identifier>
class Resource
{
private:
	std::unordered_map<Identifier, ResourceType> resourceMap;
public:
	Resource();
	~Resource();

	void load(Identifier id, const std::string& filePath);
	const ResourceType& get(Identifier id) const;
};

template<typename ResourceType, typename Identifier>
Resource<ResourceType, Identifier>::Resource()
{
	std::cout << "Resource init\n";
}

template<typename ResourceType, typename Identifier>
Resource<ResourceType, Identifier>::~Resource()
{
	std::cout << "Resource destr\n";
}

template<typename ResourceType, typename Identifier>
void Resource<ResourceType, Identifier>::load(Identifier id, const std::string& filePath)
{
	auto it = this->resourceMap.find(id);
	if (it != this->resourceMap.end())
	{
		std::cout << "The resource: " << id << " was already loaded" << std::endl;
		return;
	}

	ResourceType resource;

	if (!resource.loadFromFile(filePath))
	{
		throw std::runtime_error("Unable to open the resource: " + std::to_string(id) + " from: " + filePath + '\n');
	}
	this->resourceMap.emplace(id, std::move(resource));
}

template<typename ResourceType, typename Identifier>
const ResourceType& Resource<ResourceType, Identifier>::get(Identifier id) const
{
	auto it = this->resourceMap.find(id);
	if (it == this->resourceMap.end())
	{
		throw std::runtime_error("The resource: " + std::to_string(id) + " doesn't exists");
	}
	return it->second;
}

#endif // !RESOURCE_H

#include "Map.h"


int Push(MapHashTable* map, const std::string& key, const std::string& value)
{
	return AddElement(map->Map, key, value);
}


std::string Pop(MapHashTable* map, std::string& key)
{
	return RemoveItem(map->Map, key);
}


void PopAllValues(MapHashTable* map, std::string& key)
{
	RemoveAllKeyValues(map->Map, key);
}


std::string FindMapItem(MapHashTable* map, const std::string& key)
{
	return FindItem(map->Map, key);
}


void DeleteMapHashTable(MapHashTable* map)
{
	DeleteHashTable(map->Map);
	delete map;
}
#include "Common.h"

#include <iostream>


void ShowHashTable(HashTable* hashTable)
{
	std::cout << "Here is Hash table:" << std::endl;

	HashNode* current;

	for (int i = 0; i < hashTable->HashTableSize; i++)
	{
		current = hashTable->Data[i];
		if (!current)
		{
			std::cout << "---\n";
			continue;
		}
		if (!current->NextNode)
		{
			std::cout << "Key: " << current->Key << "\t Value: " << current->Value << std::endl;
			continue;
		}
		while (current)
		{
			std::cout << "Key: " << current->Key << "\t Value: " << current->Value << " -> ";
			current = current->NextNode;
		}

		std::cout << std::endl;
	}
}

void ShowMap(MapHashTable* map)
{
	std::cout << "Here is MAP powered by hash table:" << std::endl;
	HashNode* current;

	for (int i = 0; i < map->Map->HashTableSize; i++)
	{
		current = map->Map->Data[i];
		if (current == nullptr)
		{
			std::cout << "";
			continue;
		}
		while (current != nullptr)
		{
			std::cout << "Key: " << current->Key << "\t Value: " << current->Value;
			current = current->NextNode;
			std::cout << std::endl;
		}
	}
}

std::string GetKey()
{
	std::string key;

	std::cout << "Enter key: " << std::endl;
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	getline(std::cin, key);

	return key;
}
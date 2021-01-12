#include <iostream>

#include "HashTable.h"
#include "Map.h"
#include "Common.h"


enum class Menu
{
	Exit			= 0,
	Add				= 1,
	Remove			= 2,
	RemoveAllValues = 3,
	Find			= 4
};


int main()
{
	MapHashTable* map = new MapHashTable;
	InitHashTable(map->Map);

	int userChoose;
	bool endProgramm = false;
	std::string key;
	std::string value;

	while (!endProgramm)
	{
		ShowHashTable(map->Map);
		ShowMap(map);

		std::cout << "\nAdd (1)\n"
			 << "Remove *from the begining* (2)\n"
			 << "Remove *all values from the key* (3)\n"
			 << "Find  (4)\n" 
			 << "Exit (0)\n"
			 << "\nEnter command: ";

		std::cin >> userChoose;

		switch (static_cast<Menu>(userChoose))
		{
			case Menu::Add:
			{
				key = GetKey();

				std::cout << "Enter value: " << std::endl;
				getline(std::cin, value);

				if (IsNeedToRehashing(map->Map))
				{
					Rehashing(map->Map);
				}

				if (Push(map, key, value) == 0)
				{
					std::cout << "Done :)" << std::endl;
					system("pause");
					break;
				}
				
				std::cout << "Pair (key: " + key + " value: " + value
							+ ") already include in map" << std::endl;
				system("pause");
				break;
			}
			case Menu::Remove:
			{
				key = GetKey();
				
				std::cout << Pop(map, key) << std::endl;
				system("pause");
				break;
			}
			case Menu::RemoveAllValues:
			{
				key = GetKey();

				PopAllValues(map, key);
				std::cout << "Done !)" << std::endl;
				system("pause");
				break;
			}
			case Menu::Find:
			{
				key = GetKey();

				std::cout  << "Result: "<< FindMapItem(map, key) << std::endl;
				system("pause");
				break;
			}
			case Menu::Exit:
			{
				endProgramm = true;
				break;
			}
			default:
			{
				std::cout << "Unknown command, choose another" << std::endl;
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				system("pause");
				break;
			}
		}
		system("cls");
	}
	DeleteMapHashTable(map);
	return 0;
}
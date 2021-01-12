#include "HashTable.h"


void InitHashTable(HashTable* hashTable)
{
	hashTable->Data = new HashNode * [hashTable->HashTableSize];

	for (int index = 0; index < hashTable->HashTableSize; index++)
	{
		hashTable->Data[index] = nullptr;
	}
}


void DeleteHashTable(HashTable* hashTable)
{
	for (int index = 0; index < hashTable->HashTableSize; index++)
	{
		if (hashTable->Data[index])
		{
			delete hashTable->Data[index];
		}
	}

	delete[] hashTable->Data;
}


int AddElement(HashTable* hashTable, const std::string& key, const std::string& value)
{
	const int index = Hashing(hashTable, key);

	if (!hashTable->Data[index])
	{
		hashTable->Data[index] = new HashNode;
		hashTable->Data[index]->Key = key;
		hashTable->Data[index]->Value = value;

		++hashTable->Length;
		return 0;
	}
	if (hashTable->Data[index])
	{
		HashNode* temp = hashTable->Data[index];

		HashNode* newData = new HashNode;
		newData->Key = key;
		newData->Value = value;

		if (temp->Key == newData->Key && temp->Value == newData->Value)
		{
			return 1;
		}

		while (temp->NextNode)
		{
			if (temp->Key == newData->Key && temp->Value == newData->Value)
			{
				return 0;
			}

			temp = temp->NextNode;
		}

		temp->NextNode = newData;
		newData = temp->NextNode;
		return 0;
	}
	return 0;
}


std::string FindItem(HashTable* hashTable, const std::string& Key) 
{
	HashNode* temp = hashTable->Data[Hashing(hashTable, Key)];
	std::string errorMassage = "Not found ^..^";
	std::string keyValues = " \n";

	if (!temp)
	{
		return errorMassage;
	}
	if (!temp->NextNode)
	{
		if (temp->Key == Key)
		{
			keyValues = keyValues + temp->Value + ";\n";
			return keyValues;
		}
		else 
		{
			return errorMassage;
		}
	}

	while (temp)
	{
		if (temp->Key == Key)
		{
			keyValues = keyValues + temp->Value + ";\n";
		}

		temp = temp->NextNode;
	}

	return keyValues;
}


std::string RemoveItem(HashTable* hashTable, std::string& key)
{
	const int index = Hashing(hashTable, key);
	std::string tuskStatus = "Done !)";
	HashNode* temp = hashTable->Data[index];

	if (!temp || !temp->NextNode && temp->Key != key)
	{
		tuskStatus = key + " not found";
		return tuskStatus;
	}
	if (!temp->NextNode && temp->Key == key)
	{
		delete temp;

		hashTable->Data[index] = nullptr;
		--hashTable->Length;

		return tuskStatus;
	}

	if (temp->Key == key)
	{
		HashNode* nodeNext = temp->NextNode;
		delete temp;
		hashTable->Data[index] = nodeNext;
		--hashTable->Length;

		return tuskStatus;
	}

	while (temp->NextNode->Key != key)
	{
		temp = temp->NextNode;
	}

	// Сохраняем указатели на последующие элементы
	if (temp->NextNode->NextNode) 
	{
		HashNode* nodeNext = temp->NextNode->NextNode;
		delete temp->NextNode;
		hashTable->Data[index]->NextNode = nodeNext;
		--hashTable->Length;
		return tuskStatus;
	}

	delete temp->NextNode;
	hashTable->Data[index]->NextNode = nullptr;
	return tuskStatus;
}

void RemoveAllKeyValues(HashTable* hashTable, std::string& key)
{
	int count = 0;
	const int index = Hashing(hashTable, key);
	HashNode* temp = hashTable->Data[index];

	while (temp)
	{
		if (temp->Key == key)
		{
			++count;
		}

		temp = temp->NextNode;
	}

	for (count; count != 0; count--)
	{
		RemoveItem(hashTable, key);
	}
}


int Hashing(HashTable* hashTable, const std::string& key)
{
	int hash = 0;

	const int PirsonsMultiplierSecond = hashTable->HashTableSize - 2;
	int PirsonsMultiplier = 5;

	for (const char& i : key)
	{
		hash += i * PirsonsMultiplier;
		PirsonsMultiplier *= PirsonsMultiplierSecond;
	}

	return abs(hash % (hashTable->HashTableSize - 1));
}


bool IsNeedToRehashing(HashTable* hashTable)
{
	double loadFactor = 0.8;  //(hashTable->Length == (hashTable->HashTableSize - 2))
	if (loadFactor < (double)hashTable->Length/(double)hashTable->HashTableSize) 
	{
		return true;
	}

	return false;
}


void Rehashing(HashTable*& hashTable)
{
	const int growFactor = 2;
	HashTable* newHashTable = new HashTable;
	newHashTable->HashTableSize = hashTable->HashTableSize * growFactor;

	InitHashTable(newHashTable);

	HashNode* temp;

	for (int i = 0; i < hashTable->HashTableSize; i++)
	{
		temp = hashTable->Data[i];

		if (temp)
		{
			while (temp)
			{
				AddElement(newHashTable, temp->Key, temp->Value);
				temp = temp->NextNode;
			}
		}
	}

	delete[] hashTable->Data;
	delete hashTable;
	hashTable = newHashTable;
}
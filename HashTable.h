#pragma once
#ifndef _H_HASHTABLE_A911
#define _H_HASHTABLE_A911

#include <string>

/// @brief ������ ���-�������
struct HashNode
{
	std::string Key;					//< �������� �����
	std::string Value;					//< ��������, ���������� �� �����
	HashNode* NextNode = nullptr;		//< ��������� �� ��������� ������ �������� 
};

/// @brief ���-�������
struct HashTable
{
	int Length			= 0;			//< ���������� ��������� ���������
	int HashTableSize	= 8;			//< ���������� �����
	HashNode** Data;					//< ������ � ������� ����-��������
};

/// @brief ������������� ���-�������
///
/// @param hashTable ���������������� ���-�������
void InitHashTable(HashTable* hashTable);

/// @brief �������� ���-�������
///
/// @param hashTable ��������� ���-�������
void DeleteHashTable(HashTable* hashTable);

/// @brief ���������� ���� ����-�������� � ���-�������
///
/// @param hashTable	������������ ���-�������
/// @param key			����
/// @param value		��������, ���������� �� �����
/// 
/// @retval 0 ���������� ���� ����-�������� ������ �������
/// @retval 1 ���-������� �������� ��������� ���� ����-��������
/// @return ������ ���������� ���� ����-�������� � ���-�������
int AddElement(HashTable* hashTable, const std::string& key, const std::string& value);

/// @brief ����� ��������
///
/// @param hashTable ���-�������, � ������� ������������ �����
/// @param key ����, �� ������� �������� ��������
/// 
/// @retval errorMassage � ������ ���������� �����
/// @retval value ��������, ��������� �� �����
/// @return �������� �� �����, ���� ��������� �� ���������� �����
std::string FindItem(HashTable* hashTable, const std::string& key);

/// @brief �������� ���� ����-��������
///
/// @param hashTable	������������ ���-�������
/// @param key			��������� ����
///  
/// @retval Done				� ������ ��������� ��������			??
/// @retval key not found		� ������ ���������� �����		??
/// @return ����������� � ����������� ������
std::string RemoveItem(HashTable* hashTable, std::string& key);

/// @brief �������� ���� ������, ������� ��������� ���� 
///
/// @param hashTable	������������ ���-�������
/// @param key			����, ������������ ��� �������� ������
void RemoveAllKeyValues(HashTable* hashTable, std::string& key);

/// @brief ������� ����������� 
///
/// @param hashTable	������������ ���-������� 
/// @param key			������������ ���� ��� �����������
/// 
/// @return ��������������� ���-�����
int Hashing(HashTable* hashTable, const std::string& key);

/// @brief �������� �� ���������� � ���������� ����� �������
///
/// @param hashTable ����������� ���-�������
/// 
/// @retval true	���� ����� ���������
/// @retval false	���� ��� ������������� � ����������
/// @return ��� ������������ ??
bool IsNeedToRehashing(HashTable* hashTable);

/// @brief ������� ���������� ���-�������
///
/// @param hashTable ���-�������, ��������� ����������
void Rehashing(HashTable*& hashTable);
#endif 
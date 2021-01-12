#pragma once
#ifndef _H_MAP_B042
#define _H_MAP_B042

#include "HashTable.h"

/// @brief ������� �� ���-�������
struct MapHashTable
{
	HashTable* Map = new HashTable; //< �������
};

/// @brief ���������� ���� ����-�������� � �������
///
/// @param Map		������������ �������
/// @param key		����
/// @param value	��������
/// 
/// @retval 1	���� ����-�������� ��� ���������� � �������
/// @retval 0	���������� ���� ����-�������� � ������� ������ �������
///
/// @return	C�������� ���������� ���� ����-�������� � �������
int Push(MapHashTable* map, const std::string& key, const std::string& value); /// -> bool

/// @brief �������� ������ �� �����
///
/// @param Map ������������ �������
/// @param key ����, �� �������� ��������� ������
/// 
/// @return ����������� � ����������� ������
std::string Pop(MapHashTable* map, std::string& key);

/// @brief �������� ���� ������, ������� ��������� ����
///
/// @param map ������������ �������
/// @param key ����, �� �������� ��������� ������
void PopAllValues(MapHashTable* map, std::string& key);

/// @brief ����� �������� �� ����� � �������
///
/// @param Map		������������ �������
/// @param key		����
/// 
/// @return �������� �� �����, ���� ��������� �� ���������� �����
std::string FindMapItem(MapHashTable* map, const std::string& key);

/// @brief �������� �������
///
/// @param Map ��������� �������
void DeleteMapHashTable(MapHashTable* map);
#endif 
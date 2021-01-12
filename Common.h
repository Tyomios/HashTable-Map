#pragma once
#ifndef _H_COMMON_F224E
#define _H_COMMON_F224E

#include "Map.h"

/// @brief ���������� ���������� ���-�������
///
/// @param hashTable ���-�������
void ShowHashTable(HashTable* hashTable);

/// @brief ���������� ���������� �������
///
/// @param Map �������
void ShowMap(MapHashTable* map);

/// @brief ������� ����� �����
///
/// @return ������ ����
std::string GetKey();
#endif
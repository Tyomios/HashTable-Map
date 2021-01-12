#pragma once
#ifndef _H_COMMON_F224E
#define _H_COMMON_F224E

#include "Map.h"

/// @brief Показывает содержание хеш-таблицы
///
/// @param hashTable Хеш-таблица
void ShowHashTable(HashTable* hashTable);

/// @brief Показывает содержание словаря
///
/// @param Map Словарь
void ShowMap(MapHashTable* map);

/// @brief Функция ввода ключа
///
/// @return строку ключ
std::string GetKey();
#endif
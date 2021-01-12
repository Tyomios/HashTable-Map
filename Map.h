#pragma once
#ifndef _H_MAP_B042
#define _H_MAP_B042

#include "HashTable.h"

/// @brief словарь на хеш-таблице
struct MapHashTable
{
	HashTable* Map = new HashTable; //< Словарь
};

/// @brief Добавление пары ключ-значение в словарь
///
/// @param Map		Используемый словарь
/// @param key		Ключ
/// @param value	Значение
/// 
/// @retval 1	Пара ключ-значение уже содержится в словаре
/// @retval 0	Добавление пары ключ-значение в словарь прошло успешно
///
/// @return	Cостояние добавления пары ключ-значение в словарь
int Push(MapHashTable* map, const std::string& key, const std::string& value); /// -> bool

/// @brief Удаление данных по ключу
///
/// @param Map Используемый словарь
/// @param key Ключ, по которому удаляются данные
/// 
/// @return Уведомление о выполненной работе
std::string Pop(MapHashTable* map, std::string& key);

/// @brief Удаление всех данных, имеющих указанный ключ
///
/// @param map Используемый словарь
/// @param key Ключ, по которому удаляются данные
void PopAllValues(MapHashTable* map, std::string& key);

/// @brief Поиск значения по ключу в словаре
///
/// @param Map		Используемый словарь
/// @param key		Ключ
/// 
/// @return Значения по ключу, либо сообщение об отсутствии ключа
std::string FindMapItem(MapHashTable* map, const std::string& key);

/// @brief Удаление Словаря
///
/// @param Map Удаляемый словарь
void DeleteMapHashTable(MapHashTable* map);
#endif 
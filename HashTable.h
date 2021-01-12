#pragma once
#ifndef _H_HASHTABLE_A911
#define _H_HASHTABLE_A911

#include <string>

/// @brief ячейка хеш-таблицы
struct HashNode
{
	std::string Key;					//< Значение ключа
	std::string Value;					//< Значение, выдаваемое по ключу
	HashNode* NextNode = nullptr;		//< Указатель на следующую ячейку значения 
};

/// @brief Хеш-таблица
struct HashTable
{
	int Length			= 0;			//< Количество внесенных элементов
	int HashTableSize	= 8;			//< Количество ячеек
	HashNode** Data;					//< Ячейка с данными ключ-значение
};

/// @brief Инициализация хеш-таблицы
///
/// @param hashTable Инициализируемая хеш-таблица
void InitHashTable(HashTable* hashTable);

/// @brief Удаление хеш-таблицы
///
/// @param hashTable Удаляемая хеш-таблица
void DeleteHashTable(HashTable* hashTable);

/// @brief Добавление пары ключ-значение в хеш-таблицу
///
/// @param hashTable	Используемая хеш-таблица
/// @param key			Ключ
/// @param value		Значение, выдаваемое по ключу
/// 
/// @retval 0 Добавление пары ключ-значение прошло успешно
/// @retval 1 Хеш-таблица содержит указанную пару ключ-значение
/// @return Статус добавления пары ключ-значение в хеш-таблицу
int AddElement(HashTable* hashTable, const std::string& key, const std::string& value);

/// @brief Поиск значения
///
/// @param hashTable Хеш-таблица, в которой производится поиск
/// @param key Ключ, по кторому вернется значение
/// 
/// @retval errorMassage в случае отсутствия ключа
/// @retval value Значение, найденное по ключу
/// @return Значение по ключу, либо сообщение об отсутствии ключа
std::string FindItem(HashTable* hashTable, const std::string& key);

/// @brief Удаление пары ключ-значение
///
/// @param hashTable	Используемая хеш-таблица
/// @param key			Удаляемый ключ
///  
/// @retval Done				в случае успешного удаления			??
/// @retval key not found		в случае отсутствия ключа		??
/// @return Уведомление о выполненной работе
std::string RemoveItem(HashTable* hashTable, std::string& key);

/// @brief Удаление всех данных, имеющих указанный ключ 
///
/// @param hashTable	Используемая хеш-таблица
/// @param key			Ключ, используемый для удаления данных
void RemoveAllKeyValues(HashTable* hashTable, std::string& key);

/// @brief Функция хеширования 
///
/// @param hashTable	Используемая хеш-таблица 
/// @param key			Используемый ключ для хеширования
/// 
/// @return Неотрицательная хеш-сумма
int Hashing(HashTable* hashTable, const std::string& key);

/// @brief Проверка на надобность в увеличении места таблицы
///
/// @param hashTable Проверяемая хеш-таблица
/// 
/// @retval true	Если нужно увеличить
/// @retval false	Если нет необходимости в увеличении
/// @return Что возвращается ??
bool IsNeedToRehashing(HashTable* hashTable);

/// @brief Функция перезаписи хеш-таблицы
///
/// @param hashTable Хеш-таблица, требующая перезаписи
void Rehashing(HashTable*& hashTable);
#endif 
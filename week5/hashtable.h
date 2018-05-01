#pragma once

#include "list.h"

/**
 * Represents a hash table
 */
typedef struct hashTable{
	int size;
	List *table;
} HashTable;

/**
 * Create a new hashtable
 * @param n size of table
 * @return
 */
HashTable create_hashtable(int n);

/**
 * Find the hash value of a given key
 * @param key
 * @param size size of hash table
 * @return hashed value of key
 */
int hash(char* key, int size);

/**
 * Insert a new key into a hash table
 * @param self
 * @param key
 */
void hash_insert(HashTable *self, char* key);

/**
 * Remove a key from a hash table
 * @param self
 * @param key
 */
void hash_remove(HashTable *self, char* key);

/**
 * Print the contents of a hash table
 * @param self
 */
void hash_print(HashTable *self);

/**
 * Remove a hash table from memory
 * @param self
 */
void hash_destroy(HashTable *self);
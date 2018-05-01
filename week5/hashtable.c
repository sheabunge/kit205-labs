#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"

/**
 * Create a new hashtable
 * @param n size of table
 * @return
 */
HashTable create_hashtable(int n) {
	HashTable self;

	self.size = n;
	self.table = malloc(sizeof(self.table) * self.size);

	for (int i = 0; i < self.size; i++) {
		self.table[i].head = NULL;
	}

	return self;
}

/**
 * Find the hash value of a given key
 * @param key
 * @param size size of hash table
 * @return hashed value of key
 */
int hash(char *key, int size) {
	unsigned long h = 0; // unsigned long, so that when it wraps it's still positive
	int n = (int) strlen(key);

	for (int i = 0; i < n; i++) {
		// multiply by 32 (<<5) and add ascii value
		h = (h << 5) + (int) (key[i]);
	}

	return (int) h % size;
}

/**
 * Insert a new key into a hash table
 * @param self
 * @param key
 */
void hash_insert(HashTable *self, char *key) {
	int i = hash(key, self->size);
	insert_at_front(&self->table[i], key);
}

/**
 * Remove a key from a hash table
 * @param self
 * @param key
 */
void hash_remove(HashTable *self, char *key) {
	int i = hash(key, self->size);
	delete_list_item(&self->table[i], key);
}

/**
 * Print the contents of a hash table
 * @param self
 */
void hash_print(HashTable *self) {
	for (int i = 0; i < self->size; i++) {
		printf("%d: ", i);
		print_list(&(self->table[i]));
	}
}

/**
 * Remove a hash table from memory
 * @param self
 */
void hash_destroy(HashTable *self) {
	for (int i = 0; i < self->size; i++) {
		destroy_list(&self->table[i]);
	}

	free(self);
}
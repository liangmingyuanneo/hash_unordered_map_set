#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include "bool.h"
#include <stdio.h>

struct hash_node{
	char* key;
	void* val;
	struct hash_node *next;
};

struct hash_table{
	struct hash_node **hash_set;
	int n;
	void* (*hash_find)(struct hash_table*, char* key);
	bool (*hash_delete)(struct hash_table*, char* key);
};

struct hash_table* create_hash_table(int n);
void destroy_hash_table(struct hash_table*);
void hash_insert(struct hash_table*, char* key, void* value);

void* hash_find(struct hash_table*, char* key);
bool hash_delete(struct hash_table*, char* key);



#endif

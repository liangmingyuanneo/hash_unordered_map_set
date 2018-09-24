#ifndef _MAP_H_
#define _MAP_H_

#include "../hash/hash.h"

struct map{
	struct hash_table *h_t;
};

void insert(struct map*, char *key, void *);
void* get(struct map*, char *key);
struct map* create_map();

#endif

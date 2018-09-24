#ifndef _SET_H_
#define _SET_H_

#include "../hash/hash.h"

struct set{
	struct hash_table *h_t;
};

void insert(struct set*, char *key);
void* get(struct set*, char *key);
struct set* create_set();

#endif

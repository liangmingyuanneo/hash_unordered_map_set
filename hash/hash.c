#include "hash.h"

#include <malloc.h>
#include <string.h>

struct hash_table* create_hash_table(int n){
	struct hash_table* h_t = malloc(sizeof(struct hash_table));
	memset(h_t, 0, sizeof(struct hash_table));
	
	h_t->hash_set = malloc(n*sizeof(struct hash_node*));
	memset(h_t->hash_set, 0, n*sizeof(struct hash_node*));
	h_t->n = n;
	
	h_t->hash_find = &hash_find;
	h_t->hash_delete = &hash_delete;
	return h_t;
}
	
static unsigned int hash_index(char *str){
	register unsigned int h;
	register unsigned char *p;

	for(h = 0, p = (unsigned char*)str; *p; p++)
		h = 31 * h + *p;

	return h;
}

void destroy_hash_table(struct hash_table* t){}		
	
void hash_insert(struct hash_table* t, char* key, void* value){
	struct hash_node* h_n = malloc(sizeof(struct hash_node));
	memset(h_n, 0, sizeof(struct hash_node));

	h_n->key = key;
	h_n->val = value;

	int index = hash_index(key) % t->n;

	struct hash_node* header = t->hash_set[index];
	h_n->next = header;
	
	t->hash_set[index] = h_n;
}

void* hash_find(struct hash_table* t, char* key){
	int index = hash_index(key) % t->n;
	
	struct hash_node* walk = t->hash_set[index];
	
	while(walk){
		if(strcmp(key, walk->key) == 0){
			return walk->val;
		}
	}

	return "";
}

bool hash_delete(struct hash_table* t, char* key){
	int index = hash_index(key) % t->n;

	struct hash_node** walk = &(t->hash_set[index]);

	while(*walk){
		if(strcmp(key, (*walk)->key) == 0){
			struct hash_node* rm_node = *walk;
			
			*walk = (*walk)->next;
			rm_node->next = NULL;
			free(rm_node);
			return true;
		}else {
			walk = &((*walk)->next);
		} 
	}
	return false;
}


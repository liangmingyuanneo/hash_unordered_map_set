#include "set.h"
#include <malloc.h>
#include <string.h>

void insert(struct set* m, char *key){
	hash_insert(m->h_t, key, key);
}
	
void* get(struct set* m, char *key){
	return hash_find(m->h_t, key);
}

struct set* create_set(){
	struct set* m = malloc(sizeof(struct set));
	memset(m, 0, sizeof(struct set));
	
	m->h_t = create_hash_table(10);
	return m;
}

int main(){
	struct set* m = create_set();
	insert(m, "3");
	insert(m, "4");
	printf("%s\n", get(m, "3"));
	printf("%s\n", get(m, "5"));

	return 0;
}

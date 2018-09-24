#include "map.h"
#include <malloc.h>
#include <string.h>

void insert(struct map* m, char *key, void* value){
	hash_insert(m->h_t, key, value);
}
	
void* get(struct map* m, char *key){
	return hash_find(m->h_t, key);
}

struct map* create_map(){
	struct map* m = malloc(sizeof(struct map));
	memset(m, 0, sizeof(struct map));
	
	m->h_t = create_hash_table(10);
	return m;
}

int main(){
	struct map* m = create_map();
	insert(m, "3", "333");
	insert(m, "4", "444");
	printf("%s\n", get(m, "3"));
	printf("%s\n", get(m, "5"));

	return 0;
}

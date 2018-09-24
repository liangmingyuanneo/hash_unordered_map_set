#include "hash.h"

int main(){
	
	struct hash_table* t = create_hash_table(10);
	
	t->hash_find = &hash_find;
	t->hash_delete = &hash_delete;

	hash_insert(t, "3", "cale");
	hash_insert(t, "5", "5");
	hash_insert(t, "4", "4");

	//printf("%s\n", t->hash_find(t, "6"));
	printf("%s\n", hash_find(t, "5"));
	printf("%s\n", hash_find(t, "3"));
	//t->hash_delete(t, "5");
	printf("%s\n", hash_find(t, "5"));
	return 0;
}

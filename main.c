#include <stdint.h>
#include "darray.h"
#include <assert.h>
#include "hashmap.h"
#include "dbg.h"
#include "hashmap_algos.h"

int traverse_called = 0;

static int traverse_good_cb(HashmapNode *node)
{
	debug("Key: %s", (char*)node->key);
	traverse_called++;
	return 0;
}
int main(int argc, char const *argv[])
{
	Hashmap *map = Hashmap_create(NULL, Hashmap_fnv1a_hash);
	char * test1 = "test1";
	char * test2 = "test2";
	char * test3 = "test3";
	char *expect1 = "expect1";
	char *expect2 = "expect2";
	char *expect3 = "expect3";

	int rc1 = Hashmap_set(map, &test1, &expect1);
	int rc2 = Hashmap_set(map, &test2, &expect2);
	int rc3 = Hashmap_set(map, &test3, &expect3);

	int *res = Hashmap_get(map, &test1);

	printf("res = %s\n", (char *)*res);

	return 0;
}


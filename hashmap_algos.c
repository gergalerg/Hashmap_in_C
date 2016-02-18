#include "hashmap_algos.h"
#include <string.h>

const uint32_t FNV_PRIME = 167777619;
const uint32_t FNV_OFFSET_BASIS = 2166136261;

static inline char bchare(char *a, int p, char e)
{
	return (p < strlen(a) ? a[p] : e);
}

uint32_t Hashmap_fnv1a_hash(void *data)
{
	char *s = (char *)data;
	uint32_t hash = FNV_OFFSET_BASIS;
	int i = 0;

	for (i = 0; i < strlen(s); i++) {
		hash ^= bchare(s, i, 0); 
		hash *= FNV_PRIME;
	}
	return hash;
}

const int MOD_ADLER = 65521;


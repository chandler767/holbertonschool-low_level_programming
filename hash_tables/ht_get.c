#include "hashtable.h"
#include <stdio.h>

unsigned int hash(const char *key, unsigned int size);

char *ht_get(HashTable *hashtable, const char *key) 
{
	
/* return the value element (corresponding to key) of one of the node of the 
List stored in the array of your HashTable, at the index returned by hash. */

  unsigned int hash_v;

  hash_v = hash(key, hashtable->size);
  
  if (hashtable->array[hash_v] == NULL) {
    return NULL;
  }

  return (hashtable->array[hash_v]->value); 
}

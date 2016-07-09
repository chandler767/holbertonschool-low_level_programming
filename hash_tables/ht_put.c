#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

int add_node(List **, const char*, const char *);
unsigned int hash(const char *key, unsigned int size);

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
  unsigned int hash_v;

  hash_v = hash(key, hashtable->size);

  if ( (add_node(&hashtable->array[h], key, value) ) == 1) {
      return (1);
  }

  return (0);
}

int add_node(List **list, const char *key, const char *value)
{
  List *l;

  l = NULL;
  l = malloc(sizeof(List));

  if (l == NULL) {
    return (1);
  }

  if ( (l->key = strdup(key)) == NULL) {
    return (1);
  }
  if ( (l->value = strdup(value)) == NULL) {
    return (1);
  }
  
  l->next = *list;
  *list = l;

  return (0);
}

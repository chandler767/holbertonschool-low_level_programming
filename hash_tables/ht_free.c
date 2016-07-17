#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>


void ht_free(HashTable *hashtable)
{
  unsigned int i;
  List *hold;
  List *tmp;

  i = 0;
  while (i < hashtable->size) {
    tmp = hashtable->array[i];
    if (tmp != NULL) {
      /* frees all elements of the linked list */
      while (tmp->next != NULL) {
      	hold = tmp->next;
      	free(tmp->key);
      	free(tmp->value);
      	free(tmp);
      	tmp = hold;
      }
      if (tmp->next == NULL) {
      	free(tmp->key);
      	free(tmp->value); 
      	free(tmp);
      }
    }
    i++;
  }
  free(hashtable->array);
  free(hashtable);
}


#include "list.h"
#include <stdlib.h>

int list_size(List *list) { /* function that returns the number of node in a list */
  int count = 1;
  if (list == NULL) {
  	return 0; /* it's empty! */
  }

  while (list->next != NULL) {
    list = list->next;
    count++; /* increment for each and return the count */
  }

  return count;
}


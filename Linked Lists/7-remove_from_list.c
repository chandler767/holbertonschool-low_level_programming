#include <stdlib.h>
#include "list.h"

int list_size(List *list);

void remove_from_list(List **list, int index) { 
  int pos = 0;
  List *ptr = *list; 
  List *tmp;

  if (index < 0) return; /* nothing to remove */
  if (list_size(*list) <= index) return;
  
  if (index == 0) {
    *list = (*list)->next;
    return;
  }

  while (pos < index-2) {
    pos++;
    ptr = ptr->next;
  }

  tmp = ptr->next->next;
  free(ptr->next->str); /* free */
  free(ptr->next);
  ptr->next = tmp;
}

int list_size(List *list) { 
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


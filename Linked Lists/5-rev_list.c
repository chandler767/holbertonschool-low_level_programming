#include "list.h"
#include <stdlib.h>

void rev_list(List **list) { /* reverses the order of the nodes in the list */
  List *swap = *list;
  List *base;
  List *next;

  next = swap->next; 
  swap->next = NULL;
 
  while (next != NULL) { /* add to next */
    base = next;
    next = base->next;
    base->next = swap;
    swap = base;
  }

  *list = swap; 

}

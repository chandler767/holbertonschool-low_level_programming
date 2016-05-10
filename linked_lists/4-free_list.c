#include "list.h"
#include <stdlib.h>

void free_list(List *list) { 
  List *hold;
  while (list != NULL) { 
    hold = list;
    list = list->next;
    free(hold->str);
    free(hold); /* free each node */
  }
}



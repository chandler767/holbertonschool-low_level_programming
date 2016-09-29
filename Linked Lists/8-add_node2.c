#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void string_copy(char *src, char *dest) { 
  char *temp;
  
  while (*src) {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0'; 
  temp  = src;
  temp = dest; /* Copy string */
  src = temp + 1;
}

int strlength(char *str) { 
  int length = 0;
  while (str[length] != 0) {
    length++; /* Increment until end of string */
  }
  return (length + 1);
}

int add_node(List **list, char *str) { 
  List *node_to_add = malloc(sizeof(List));
  List *curr = *list;

  node_to_add->next = NULL;
  node_to_add->str = malloc(sizeof(char) * strlength(str));
  string_copy(str, node_to_add->str); /* copy string */

  if (node_to_add == NULL) {
    return 1; /* failed */
  }

  if (curr == NULL) {
    *list = node_to_add;
    return 0; 
  }

  while (curr->next != NULL) curr = curr->next;
  curr->next = node_to_add;

  return 0;
}

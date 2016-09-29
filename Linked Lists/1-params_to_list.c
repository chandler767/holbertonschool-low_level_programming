#include <stdlib.h>
#include <stdio.h>
#include "list.h"

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
  char *temp;

  node_to_add->next = curr;
  node_to_add->str = malloc(sizeof(char) * strlength(str));

  while (*str) {
    *node_to_add->str = *str;
    str++;
    node_to_add->str++;
  }
  *node_to_add->str = '\0'; 
  temp  = str;
  temp = node_to_add->str; /* Copy string */
  str = temp + 1;

  if (node_to_add == NULL) {
    return 1; /* failed */
  }

  if (curr == NULL) {
    *list = node_to_add;
    return 0; 
  }

  while (curr->next != NULL) curr = curr->next;
  curr->next = node_to_add; /* add node to end of list */

  return 0;
}

List *params_to_list(int ac, char **av) { /* function that creates a new list from the command line arguments */
  int i = 0;

  List *list = malloc(sizeof(void *) * (ac + 1)); /*malloc and get length */

  if (list == NULL) {
    return NULL; /* nothing to add */
  }
  
  while (i < ac) {
    if (add_node(&list, av[i])) { /* add each */ 
      return NULL;
    }
    i++;
  }
  return list;
}

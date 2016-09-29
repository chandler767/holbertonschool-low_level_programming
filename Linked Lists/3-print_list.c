#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int print_char(char);

void print_string(char *str) { 
  while (*str != 0) {
    print_char(*str); /* print each char in the string */
    str++;
  }
}

void print_list(List *list) {
  int hold = 1;

  if (list == NULL) {
    print_char('\n');
    return; /* nothing */
  }

  while (list != NULL) {
    if (!hold) {
      print_string(", "); /* Taking advantage of this function */
    } else {
      hold = 0;
    }
    print_string(list->str); /* Print each. */
    list = list->next;
  }
  print_char('\n');
}


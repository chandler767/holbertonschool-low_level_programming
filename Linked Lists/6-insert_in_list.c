#include <stdlib.h>
#include "list.h"

int list_size(List *list);
void string_copy_1(char *src, char *dest);

int strlength_1(char *str) { 
  int length = 0;
  while (str[length] != 0) {
	length++; /* Increment until end of string */
  }
  return (length + 1);
}

int add_node_2(List **list, char *str) { 
	List *node_to_add = malloc(sizeof(List));
	List *curr = *list;

	node_to_add->next = curr;
	node_to_add->str = malloc(sizeof(char) * strlength_1(str));
	string_copy_1(str, node_to_add->str); 

	if (node_to_add == NULL) {
		return 1; /* failed */
	}

	if (curr == NULL) {
		*list = node_to_add;
		return 0; 
	}

	*list = node_to_add;

	return 0;
}

int insert_in_list(List **list, char *content, int index) { /*creates a node at an index*/
	int pos = 0;
	List *ptr = *list;
	List *temp;

	if ((index < 0) || (list_size(*list) <= index)) return 1; /* Error */

	if (index == 0) return add_node_2(list, content); /* Add to the beginning of thr list. */


	while (pos < index-2) { /* started on first node, go back 2 */
		pos++; 
		ptr = ptr->next;
	}
	temp = ptr->next;

	ptr->next = malloc(sizeof(List));
	
	if (ptr->next == NULL) return 1; /* malloc failed */ 

	ptr->next->next = temp;

	ptr->next->str = malloc(sizeof(char) * strlength_1(content));
	string_copy_1(content, ptr->next->str); 

	return 0;
}

void string_copy_1(char *src, char *dest) { 
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

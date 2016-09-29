#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int btree_insert(BTree **tree, char *data); /* btree_insert.c */ 

BTree *array_to_btree(char **array)
{
	BTree *tree = NULL; 
	int i;

	for (i = 0; array[i] != NULL; i++) {
		btree_insert(&tree, array[i]); /* step through array and insert into tree */ 
	}
	return tree;
}
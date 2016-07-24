#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

BTree *btree_find(BTree *tree, char *str)
{
	if (!tree || !str) {
		return NULL; /* error */
	}
	comp = strcmp(str, tree->str);

	if (comp == 0) {
		return tree; /* Found */
	}
	else if (c < 0) {
		return btree_find(tree->left, str); /* search left of the node */ 
	}
	else {
		return btree_find(tree->right, str); /* search right of the node */ 
	}
	return NULL;
}

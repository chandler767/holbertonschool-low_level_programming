#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int btree_insert(BTree **tree, char *data) 
{
	BTree *new;

	if (*tree == NULL) { /* nothing in tree */ 
		new = malloc(sizeof(BTree));
		if (new == NULL) {
			return (1); /* failed to malloc */
			}
		
		new->str = strdup(data);
		new->left = NULL; /* Nothing in tree so left and right will be NULL */
		new->right = NULL;
		*tree = new;
		return (0);
	}
	/* There is already a tree - compare to see if it needs to go on the right or left side of the tree */
	if (strcmp(data, (*tree)->str) <= 0) {  /* if less or equal put it on the left */
		return (btree_insert(&((*tree)->left), data));
	}
	return (btree_insert(&((*tree)->right), data)); /* greater on the right */
}

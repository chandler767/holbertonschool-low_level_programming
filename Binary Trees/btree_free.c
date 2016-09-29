#include <stdlib.h>
#include "tree.h"

void btree_free(BTree *tree)
{
	if (!tree) {
		return; /* error - no tree*/
	}
	btree_free(tree->left); /* free the left and right sides of the tree */
	btree_free(tree->right);
	if (tree->str){
		free(tree->str); /* free the node */
	}
	free(tree); 
	
}

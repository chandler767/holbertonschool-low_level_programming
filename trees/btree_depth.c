#include "tree.h"
#include <stdio.h>


int btree_depth(BTree *tree)
{
	int left;
	int right;

	if (!tree){
		return (-1); /* error - no tree depth*/
	}
	if (tree->right != NULL) {
		right = btree_depth(tree->right) + 1; /* increase depth on right side by 1 */
	}
	if (tree->left != NULL) {
		left = btree_depth(tree->left) + 1; /* increase depth on left side by 1 */
	}
	if (right > left) { /* return the largest value */ 
		return (right);
	} else {
		return (left);
	}
}

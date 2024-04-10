#include "binary_trees.h"
/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count the leaves.
 *
 * Return: Number of leaves in the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t sum;

	sum = 0;
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	sum += binary_tree_leaves(tree->left);
	sum += binary_tree_leaves(tree->right);

	return (sum);
}

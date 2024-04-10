#include "binary_trees.h"
/**
 * binary_tree_nodes - Counts the nodes with atleast onechild in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count the nodes.
 *
 * Return: Number of nodes with at least one child in the binary tree,
 *		or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes;

	nodes = 0;
	if (!tree)
		return (0);

	if (tree->left || tree->right)
		nodes++;

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}

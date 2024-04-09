#include "binary_trees.h"
/**
 * binary_tree_node - Creates a new binary tree node.
 *
 * @parent: Pointer to the parent node of the new node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);

	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}

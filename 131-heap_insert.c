#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If tree is NULL, it is considered full */
	if (tree == NULL)
		return (1);

	/* If tree is a leaf, it is considered full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If tree has both left and right children, */
	/* recursively check both subtrees */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If tree has only one child, it is not considered full */
	return (0);
}
/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	size_t nodes = binary_tree_size(tree);
	size_t perfect_nodes = 1;

	while (height > 0)
	{
		perfect_nodes *= 2;
		height--;
	}

	return (nodes == perfect_nodes - 1);
}
/**
 * heapify_up - Moves a node up the heap to its proper position.
 * @node: A pointer to the node to move up.
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value in Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	parent = *root;
	while (parent->left && parent->right)
	{
		if (binary_tree_is_perfect(*root) || (!binary_tree_is_perfect(*root) && binary_tree_is_full(*root)))
			parent = parent->left;
		else
			parent = parent->right;
	}

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	heapify_up(new_node);

	return (new_node);
}

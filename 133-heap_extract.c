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
/**
 * heapify_down - Moves the node down the tree to maintain heap property
 *
 * @heap: Pointer to the heap root
 */
void heapify_down(heap_t **heap)
{
    heap_t *node, *child;
    int tmp;

    if (!heap || !(*heap))
        return;

    node = *heap;
    while (node->left)
    {
        child = node->left;
        if (node->right && node->right->n > node->left->n)
            child = node->right;
        if (node->n >= child->n)
            break;
        tmp = node->n;
        node->n = child->n;
        child->n = tmp;
        node = child;
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    size_t height;
    heap_t *last_node, *node;

    if (!root || !(*root))
        return (0);

    value = (*root)->n;
    height = binary_tree_height(*root);

    if (height == 1)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    last_node = *root;
    while (last_node->left && last_node->right)
    {
        if (!last_node->right || binary_tree_height(last_node->left) == binary_tree_height(last_node->right))
            last_node = last_node->left;
        else
            last_node = last_node->right;
    }

    node = *root;
    while (node->left && node->right && node->left != last_node && node->right != last_node)
    {
        if (binary_tree_height(node->right) < binary_tree_height(node->left))
            node = node->left;
        else
            node = node->right;
    }

    if (node->left && node->left == last_node)
        node->left = NULL;
    else
        node->right = NULL;

    (*root)->n = last_node->n;
    free(last_node);
    heapify_down(root);

    return (value);
}

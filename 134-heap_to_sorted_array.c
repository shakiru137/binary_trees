#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (heap == NULL)
        return NULL;

    // Count the number of elements in the heap
    size_t count = 0;
    heap_t *temp = heap;
    while (temp != NULL)
    {
        temp = temp->left;
        count++;
    }

    // Create an array to store the sorted elements
    int *sorted_array = malloc(count * sizeof(int));
    if (sorted_array == NULL)
        return NULL;

    // Heap sort
    size_t i;
    for (i = count; i > 0; i--)
    {
        sorted_array[count - i] = heap->n;
        if (heap->left != NULL)
        {
            heap->n = heap->left->n;
            heapify_down(heap, i, 0);
        }
        else if (heap->right != NULL)
        {
            heap->n = heap->right->n;
            heapify_down(heap, i, 0);
        }
        else
        {
            free(heap);
            heap = NULL;
        }
    }

    *size = count;
    return sorted_array;
}

#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return NULL;

    if (first == second)
        return (binary_tree_t *)first;

    binary_tree_t *left_LCA = binary_trees_ancestor(first->parent, second);
    binary_tree_t *right_LCA = binary_trees_ancestor(first, second->parent);

    if (left_LCA != NULL && right_LCA != NULL)
        return (binary_tree_t *)first;

    return (left_LCA != NULL) ? left_LCA : right_LCA;
}


#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (!node || !node->parent)
        return NULL;  // If node or parent is NULL, return NULL

    if (node == node->parent->left)
        return node->parent->right;

    return node->parent->left;
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 *
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (!node)
        return NULL;  // If node is NULL, return NULL

    if (!node->parent)
        return NULL;  // If parent is NULL, no uncle

    return binary_tree_sibling(node->parent);
}

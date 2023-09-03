#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, NULL if none.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *node1, *node2;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	node1 = first->parent, node2 = second->parent;

	if (first == node2 || !node1 || (!node1->parent && node2))
		return (binary_trees_ancestor(first, node2));
	if (second == node1 || !node2 || (!node2->parent && node1))
		return (binary_trees_ancestor(node1, second));

	return (binary_trees_ancestor(node1, node2));
}

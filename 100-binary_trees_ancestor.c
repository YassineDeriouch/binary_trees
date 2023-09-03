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

	binary_tree_t *n1, *n2;

	if (first == NULL || second == NULL)
		return (NULL);
		
	if (first == second)
		return ((binary_tree_t *)first);

	n1 = first->parent,
	n2 = second->parent;

	if (first == n2 || !n1 || (!n1->parent && n2))
		return (binary_trees_ancestor(first, n2));

	if (second == n1 || !n2 || (!n2->parent && n1))
		return (binary_trees_ancestor(n1, second));

	return (binary_trees_ancestor(n1, n2));
}

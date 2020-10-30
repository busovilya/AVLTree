#include "avl_tree.h"
#include <iostream>
#include <vector>

AVLTree::AVLTree()
{
	root = nullptr;
}

int AVLTree::height(Node* node)
{
	if(node == nullptr)
		return 0;
	return node->height;
}

int AVLTree::balance(Node* node)
{
	return height(node->left) - height(node->right);
}

Node* AVLTree::rotate_left(Node* node)
{
	Node* right_child = node->right;
	node->right = right_child->left;
	right_child->left = node;
	node->height = std::max(height(node->left), height(node->right));
	right_child->height = std::max(height(right_child->left), height(right_child->right));
	return right_child;
}

Node* AVLTree::rotate_right(Node* node)
{
	Node* left_child = node->left;
	node->left = left_child->right;
	left_child->right = node;
	node->height = std::max(height(node->left), height(node->right));
	return left_child;
}

bool AVLTree::search(int value)
{
	Node* node = root;
	while(node != nullptr)
	{
		if(node->key < value)
			node = node->left;
		else if(node->key > value)
			node = node->right;
		else if(node->key == value)
			return true;
	}

	return false;
}

void AVLTree::insert(int value)
{
	root = insert_node(value, root);
}

Node* AVLTree::insert_node(int value, Node* node)
{
	if(node == nullptr)
	{
		return new Node{ value, 1, nullptr, nullptr };
	}
	else if(value < node->key)
		node->left = insert_node(value, node->left);
	else if(value > node->key)
		node->right = insert_node(value, node->right);
	else 
		return node;
	
	node->height = std::max(height(node->left), height(node->right)) + 1;
	int balance = this->balance(node);
	
	if(balance > 1 && value < node->left->key)
	{
		return rotate_right(node);
	}
	else if(balance > 1 && value > node->left->key)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	else if(balance < -1 && value > node->right->key)
	{
		return rotate_left(node);
	}
	else if(balance < -1 && value < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}

	return node;
}


#pragma once

#include <queue>
#include <vector>
#include <string>

using namespace std;

class huffman
{
public:
	static pair<size_t, size_t>  code(const string& text);
private:

	// Huffman Tree node
	struct node
	{
		char code;
		unsigned int frequence;
		node *left;
		node *right;

		// leaf constructor
		node(char code, unsigned frequence)
		{
			this->code = code;
			this->frequence = frequence;
			left = right = nullptr;
		}

		// branch constructor
		node(node *left, node *right)
		{
			code = '0';
			frequence = left->frequence + right->frequence;
			this->left = left;
			this->right = right;
		}
	};

	static size_t initialize_bits(node* root, size_t count = 0);
};
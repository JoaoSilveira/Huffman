#include "stdafx.h"
#include "Huffman.h"

#include <map>

pair<size_t, size_t> huffman::code(const string& text)
{
	map<char, int> frequencies;

	// calculate frequencies of the chars in the message
	for (auto c : text)
		frequencies[c]++;

	auto comp = [](node* l, node* r) { return l->frequence > r->frequence; };

	priority_queue<node*, vector<node*>, decltype(comp)> nodes(comp);

	// initialize priority queue based on character frequence
	for (auto pair : frequencies)
	{
		nodes.push(new node(pair.first, pair.second));
	}

	// create huffman tree
	while (nodes.size() > 1)
	{
		auto left = nodes.top();
		nodes.pop();

		auto right = nodes.top();
		nodes.pop();

		nodes.push(new node(left, right));
	}

	if (frequencies.size() == 1)
		return make_pair(text.size() * 8, text.size());

	// calculate size of the message
	auto size = initialize_bits(nodes.top());

	return make_pair(text.size() * 8, size);
}

long long int huffman::initialize_bits(node* root, int count)
{
	// count is the counting of necessary bits to represents a character in the tree
	// node is leaf then return the frequence * count
	if (root->left == nullptr && root->right == nullptr)
	{
		return root->frequence * count;
	}

	// if not leaf, return the sum of the two branches
	return initialize_bits(root->left, count + 1) + initialize_bits(root->right, count + 1);
}

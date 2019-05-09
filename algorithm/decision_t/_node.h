#pragma once
#include<string>
class __node
{
public:
	__node() = default;
	~__node() = default;
	auto get_info() {
		return splitOn;
	}
	auto get_label() {
		return label;
	}
	std::string splitOn;										// Stores which attribute to split on at a particular node
	std::string label;											// Stores the class label for leaf nodes. For nodes that are not leaf nodes, it stores the value of the attribute of the parent's' split 
	bool isLeaf = false;

};

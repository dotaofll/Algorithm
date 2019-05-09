#pragma once
#include"_node.h"
#include"_header.h"
#include<vector>
#include<string>
#include<iostream>
#include<memory>
class decision_tree
{
public:
	decision_tree() = delete;
	decision_tree(decision_tree&) = delete;
	decision_tree(vvs& input_table);
	auto size() { return _size; }
	auto get_root() {
		cout << root->get_info() << endl;
	}
	~decision_tree() { children.shrink_to_fit(); }

private:
	auto tableIsEmpty(vvs&);
	auto isHomogeneous(vvs&);
	auto decideSplittingColumn(vvs&);
	auto returnColumnIndex(std::string&&, vvs&);
	vvs pruneTable(vvs&, string&, const string);
	auto _build(vvs&, shared_ptr<__node>, vvs&)->shared_ptr<__node>;
	auto generateTableInfo(vvs&)->vvs;
	vi countDistinct(vvs&, int);
	int _size = 0;
	std::vector<shared_ptr<__node>> children;
	vector<string> children_value;
	shared_ptr<__node> root;
};



#include"DTree.h"

int main() {
	vector<string> _vs{ "h1","h2" };
	vector<vector<string>> __vs;
	__vs.push_back(_vs);
	decision_tree df(__vs);
	cout << "building test pass!";
	return 1;
}
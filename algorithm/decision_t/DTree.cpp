#include "DTree.h"
#include<algorithm>
decision_tree::decision_tree(vvs& input_table)
{
	this->_size++;
	auto tableinfo = generateTableInfo(input_table);
	root=_build(input_table, root, tableinfo);
}

auto decision_tree::tableIsEmpty(vvs& table)
{
	return (table.size() == 1);
}

auto decision_tree::isHomogeneous(vvs& table)
{
	int lastCol = table[0].size() - 1;
	string firstvalue = table[1][lastCol];
	for (int i = 1; i < table.size(); i++) {
		if (firstvalue != table[i][lastCol]) {
			return false;
		}
	}
	return true;
}

auto decision_tree::decideSplittingColumn(vvs& table)
{
	auto minEntr = numeric_limits<double>::max();
	vi entropies;
	int column = 0;
	int spiltColumn = 0;
	for (column; column < table[0].size() - 1; column++) {
		string colName = table[0][column];
		msi Map;
		vi counts = countDistinct(table, column);
		vd attributeEntr;
		auto columnEntr = 0.0;
		for (int i = 1; i < table.size() - 1; i++) {
			auto entr = 0.0;
			if (Map.find(table[i][column]) != Map.end()) {
				Map[table[i][column]]++;
			}
			else
			{
				Map[table[i][column]] = 1;
				vvs temptable = pruneTable(table, colName, table[i][column]);
				vi classCounts = countDistinct(temptable, temptable[0].size() - 1);
				for (int j = 0; j < classCounts.size(); j++) {
					auto temp = static_cast<double>(classCounts[j]);
					entr -= (temp / classCounts[classCounts.size() - 1])
						* (log(temp / classCounts[classCounts.size() - 1] / log(2)));
				}
				attributeEntr.push_back(entr);
				entr = 0.0;
			}
		}
		for (int i = 0; i < counts.size() - 1; i++) {
			columnEntr += (static_cast<double>(counts[i]) * static_cast<double>(attributeEntr[i]));
		}
		columnEntr = columnEntr / (static_cast<double>(counts[counts.size() - 1]));
		if (columnEntr <= minEntr) {
			minEntr = columnEntr;
			spiltColumn = column;
		}
	}
	return table[0][spiltColumn];
}

auto decision_tree::returnColumnIndex(std::string&& columnName, vvs& tableinfo)
{
	for (int i = 0; i < tableinfo.size(); i++) {
		if (tableinfo[i][0] == columnName) {
			return i;
		}
	}
	return -1;
}

vvs decision_tree::pruneTable(vvs& attrtable, string& colName, const string value)
{
	vvs prunedtable;
	int column = -1;
	vs headerRow;
	for (int i = 0; i < attrtable[0].size(); i++) {
		if (attrtable[0][i] == colName) {
			column = i;
			break;
		}
	}
	for (int i = 0; i < attrtable[0].size(); i++) {
		if (i != column) {
			headerRow.push_back(attrtable[0][i]);
		}
	}
	prunedtable.push_back(headerRow);
	for (int i = 0; i < attrtable.size(); i++) {
		vs auxRow;
		if (attrtable[i][column] == value) {
			for (int j = 0; j < attrtable[i].size(); j++) {
				if (j != column) {
					auxRow.push_back(attrtable[i][j]);
				}
			}
			prunedtable.push_back(auxRow);
		}
	}
	return prunedtable;
}
auto decision_tree::_build(vvs& table, shared_ptr<__node> nodeptr, vvs& tableinfo)
->shared_ptr<__node>
{
	if (this->tableIsEmpty(table)) {
		return nullptr;
	}
	if (this->isHomogeneous(table)) {
		nodeptr->isLeaf = true;
		nodeptr->label = table[1][table[1].size() - 1];
		return nodeptr;
	}
	else {
		string splitCol = this->decideSplittingColumn(table);
		nodeptr->splitOn = splitCol;
		int colIndex = this->returnColumnIndex(std::move(splitCol), tableinfo);
		for (int i = 1; i < tableinfo[colIndex].size(); i++) {
			shared_ptr<__node> _new_node{ new __node };
			this->_size++;
			_new_node->label = tableinfo[colIndex][i];
			_new_node->splitOn = splitCol;
			_new_node->isLeaf = false;
			this->children_value.push_back(tableinfo[colIndex][i]);
			vvs auxtable = this->pruneTable(table, splitCol, tableinfo[colIndex][i]);
			this->children.push_back(shared_ptr<__node>(_build(auxtable, _new_node, tableinfo)));
		}
	}
	return nodeptr;
}

auto decision_tree::generateTableInfo(vvs& datatable)
->vvs
{
	vvs tableinfo;
	for (int i = 0; i < datatable[0].size(); i++) {
		vs tempinfo;
		msi Map;
		for (int j = 0; j < datatable.size(); j++) {
			if (Map.count(datatable[j][i]) == 0) {
				Map[datatable[j][i]] = 1;
				tempinfo.push_back(datatable[j][i]);
			}
			else {
				Map[datatable[j][i]]++;
			}
		}
		tableinfo.push_back(tempinfo);
	}
	return tableinfo;
}

vi decision_tree::countDistinct(vvs&, int)
{
	return vi();
}


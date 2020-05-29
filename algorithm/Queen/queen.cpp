#include<vector>
#include<string>
#include<iostream>
#include<memory>
#include<fstream>
class solution {
public:
	using vs=std::vector<std::string>;
	using vt=std::vector<int>;
	auto solveQueens(size_t n)->std::vector<vs>;
private:
	auto search(std::vector<vs>&, vs&, vt&, vt&, vt&,const int,const int&)
		->void;
};

int main(int argc,const char *argv[]) {
	if(argc<2){
		throw "args is too short";
	}
	int num=0;
	num=std::stoi(argv[1]);
	std::vector<std::vector<std::string>> ss;
	ss= solution().solveQueens(num);
	
	std::shared_ptr<std::ofstream> output{new std::ofstream};
	output->open("Out.txt",std::ios::app);
	for(auto& vs:ss){
		for(auto& _ss:vs){
			*output << _ss << std::endl;
		}
		*output << "--------------------" << std::endl;
	}
	return 0;
}

auto solution::solveQueens(size_t n)
->std::vector<vs>
{
	std::vector<vs> res;
	vs nqueen(n, std::string(n, '.'));
	vt flag_col(n,1), flag_45(2 * n - 1,1), flag_135(2 * n - 1,1);
	search(res, nqueen, flag_col, flag_45, flag_135, 0, n);
	return res;
}

auto solution::search(std::vector<vs>& res, vs& nqueen, vt& flag_col,
					  vt& flag_45, vt& flag_135, const int row, const int& n)
->void
{
	if (row == n) {
		res.push_back(nqueen);
		return;
	}
	for (int col = 0; col != n; col++) {
		if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
			flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
			nqueen[row][col] = 'Q';
			search(res, nqueen, flag_col, flag_45, flag_135, row + 1, n);
			nqueen[row][col] = '.';
			flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
		}
	}
}

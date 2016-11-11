#include "comm.h"

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ans;
		int N = matrix.size();
		if (N == 0)
			return ans;
		int M = matrix[0].size();
		if (M == 0)
			return ans;
		bool H_foward = true;
		bool V_foward = true;
		int i = 0;
		int j = -1;
		while (true) {
			if (H_foward) {
				for (int k=0; k<M; ++k) {
					ans.push_back(matrix[i][++j]);
				}
			} else {
				for (int k=0; k<M; ++k) {
					ans.push_back(matrix[i][--j]);
				}
			}
			--N;
			H_foward = !H_foward;
			if (V_foward) {
				for (int k=0; k<N; ++k) {
					ans.push_back(matrix[++i][j]);
				}
			} else {
				for (int k=0; k<N; ++k) {
					ans.push_back(matrix[--i][j]);
				}
			}
			--M;
			V_foward = !V_foward;
			if (M <= 0 || N <= 0) 
				break;
	 	}
		return ans;
	}
};

int main()
{
	vector<vector<int> > matrix;
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	matrix.push_back(array);
	array.clear();
	array.push_back(5);
	array.push_back(6);
	array.push_back(7);
	array.push_back(8);
	matrix.push_back(array);
	array.clear();
	array.push_back(9);
	array.push_back(10);
	array.push_back(11);
	array.push_back(12);
	matrix.push_back(array);
	array.clear();

	Solution sol;
	array = sol.printMatrix(matrix);
	for (int i=0; i<array.size(); ++i) {
		cout << array[i] << ' ';
	}
}

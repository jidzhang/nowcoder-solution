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
		--N;
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
			--M;
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
			--N;
			V_foward = !V_foward;
			if (M <= 0 || N <= 0) 
				break;
	 	}

	}
};

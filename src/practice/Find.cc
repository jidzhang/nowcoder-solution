#include "comm.h"
/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 
*/

class Solution {
	public:
		bool Find(vector<vector<int> > array,int target) {
			if (array.empty())
				return false;
			int i = 0;
			for (; i<array[0].size(); ++i) {
				int a = array[0][i];
				if (a == target)
					return true;
				if (a > target) 
					break;
			}
			if (i == 0)
				return false;
			int n = i-1;
			for (i=1; i<array.size(); ++i) {
				int a = array[i][n];
				if (a == target)
					return true;
			}
			return false;
			/*
			for (int i=0; i<array.size(); ++i) {
				bool b = Find(array[i], target);
				if (b)
					return true;
			}
			return false;
			*/
		}
		bool Find(const vector<int> & array, int target) {
			return binary_search(array.begin(), array.end(), target);
		}
};

int main()
{
	vector<int> a,b;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	b.push_back(1);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	vector<vector<int> > aa;
	aa.push_back(a);
	aa.push_back(b);
	Solution sol;
	bool bb = sol.Find(aa, 6);
	cout << (bb?"Found":"Not found") << endl;

	
}

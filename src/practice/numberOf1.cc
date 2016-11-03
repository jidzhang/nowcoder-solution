#include "comm.h"

class Solution {
public:
	int  NumberOf1(int n) {
		int a = 0;
		while (n != 0) {
			++a;
			n = n & (n-1);
		}	
		return a;
	}
};

int main()
{
	Solution sol;
	cout << sol.NumberOf1(-1) << endl;
}

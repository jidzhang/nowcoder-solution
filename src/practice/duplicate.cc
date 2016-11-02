#include "comm.h"

/**
 * 题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。  
 *
 */

class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication){
		int N = 0;
		int n = 0;
		int * p = duplication;
		int i = 0;
		for (i=0; i<length; ++i) {
			int a = 1 << numbers[i];
			if (N & a) {
				if ((n & a) == 0) {
					*p = numbers[i];
					++p;
				} else {
					n |= a;
				}
			} else {
				N |= a;
			}
		}

		return p != duplication;
	}
};

#define M 5
using namespace std;
int main()
{
	int a[M] = {2, 1, 3, 0, 4};
	int b[M] = {-1,-1,-1,-1,-1};
	Solution sol;
	bool c = sol.duplicate(a, M, b);
	cout << c << endl;
	for (int i=0; i<M; ++i) {
		std::cout << b[i] << std::endl;
	}	
}

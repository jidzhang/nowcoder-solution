#include "comm.h"

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() < 2)
			return;
		int i = -1;
		int j = -1;
		int n = 0;
		for (n = 0; n < array.size(); ++n) {
			if (even(array[n])) {
				i = n;
				break;
			}
		}
		if (i < 0)
			return;
		for (n = i+1; n < array.size(); ++n) {
			if (even(array[n]))
				continue;
			for (int k=n; k > i; --k) {
				swap(array[k], array[k-1]);
			}
			++i;
		}

	}
	void swap(int & a, int & b) {
		a ^= b ^= a ^= b;
	}
	bool even(int a) {
		return a % 2 == 0;
	}
};

int main()
{
	int buffer[] = {2, 3, 5, 4, 8, 0, 2, 1, 9};
	vector<int> array(buffer, buffer+9);
	for (int i=0; i<array.size(); ++i) {
		cout << array[i] << '\t';
	}
	Solution sol;
	sol.reOrderArray(array);
	for (int i=0; i<array.size(); ++i) {
		cout << array[i] << '\t';
	}
}

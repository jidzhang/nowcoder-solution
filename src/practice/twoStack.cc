#include "comm.h"
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
		return;
	}

	int pop() {
		int a = 0;
		if (!stack2.empty()) {
			a = stack2.top();
			stack2.pop();
		} else {
			while (!stack1.empty()) {
				a = stack1.top();
				stack1.pop();
				if (!stack1.empty())
					stack2.push(a);
			}
		}
		return a;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution sol;
	sol.push(1);
	sol.push(2);
	sol.push(3);
	cout << sol.pop() << endl;
	cout << sol.pop() << endl;
	cout << sol.pop() << endl;
}

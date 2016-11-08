#include "comm.h"

double power2(double a, int b)
{
	double r=1, base=a;
	while (b != 0) {
		if (b%2)
			r *= base;
		base *= base;
		b /= 2;
	}
	return r;
}

int main()
{
	cout << power2(2.0, 5) << endl;
}

#include "comm.h"

void swap(unsigned char & a, unsigned char & b) {
	a = a + b;
	printf("a+b=0x%X\n", a);
	b = a - b;
	a = a - b;
}

int main()
{
	unsigned char a = 0xFE;
	unsigned char b = 0xE0;
	printf("0x%X, 0x%X\n", a, b);
	swap(a, b);
	printf("0x%X, 0x%X\n", a, b);
}

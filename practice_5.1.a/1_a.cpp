#include <iostream>

using namespace std;

void a_1()
{
	unsigned char x = 255;
	unsigned char mask = 1;
	cout << "Result for x = 255: " << (x & ~(mask << 4)) << endl;

	x = 127;
	cout << "Result for x = 127: " << (x & ~(mask << 4)) << endl;

	x = 31;
	cout << "Result for x = 31: " << (x & ~(mask << 4)) << endl;
}

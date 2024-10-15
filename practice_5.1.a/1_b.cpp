#include <iostream>

using namespace std;

void b_1()
{
	unsigned char x = 255;
	unsigned char mask = 1;
	cout << "Result for x = 255: " << (x & (mask << 7)) << endl;
}

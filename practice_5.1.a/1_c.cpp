#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>

using namespace std;

void c_1()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int x = 25;
	const int n = sizeof(int) * 8;
	unsigned int mask = (1 << n - 1);

	cout << "Начальный вид маски: " << bitset<n> (mask) << endl;
	cout << "Результат: ";

	for (int i = 1; i <= n; i++)
	{
		cout << ((x & mask) >> (n - i));
		mask = mask >> 1;
	}
	cout << endl;
	system("pause");
}
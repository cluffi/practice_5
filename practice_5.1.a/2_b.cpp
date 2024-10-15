#include <iostream>

void b_2()
{
	using namespace std;

	unsigned int amountData, temp;
	unsigned long long bitArray = 0;

	cout << "Enter amount of numbers less than 65:" << endl;
	cin >> amountData;
	if (cin.fail() || amountData > 64)
	{
		cout << "Entered bad value" << endl;
		exit(1);
	}


	cout << "Enter " << amountData << " numbers less than 64, but more than -1:" << endl;
	for (int i = 0; i < amountData; i++)
	{
		if (cin >> temp && temp < 64)
		{
				bitArray = bitArray | ((long long)1 << (63 - temp));
		}
		else
		{
			cout << "Entered bad value" << endl;
			exit(1);
		}
	}

	cout << "Soreted entered numbers:" << endl;
	for (int i = 0; i < 64; i++)
	{
		if (bitArray & ((long long)1 << 63 - i))
		{
			cout << i << endl;
		}
	}
}
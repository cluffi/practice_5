#include <iostream>

void a_2()
{
	using namespace std;

	unsigned int amountData, temp;
	unsigned char bitArray = 0;

	cout << "Enter amount of numbers less than 9:" << endl;
	cin >> amountData;
	if (cin.fail() || amountData > 8)
	{
		cout << "Entered bad value" << endl;
		exit(1);
	}


	cout << "Enter " << amountData << " numbers less than 8, but more than -1:" << endl;
	for (int i = 0; i < amountData; i++)
	{
		if (cin >> temp && temp < 8)
		{
			bitArray = bitArray | (1 << (7 - temp));
		}
		else
		{
			cout << "Entered bad value" << endl;
			exit(1);
		}
	}

	cout << "Soreted entered numbers:" << endl;
	for (int i = 0; i < 8; i++)
	{
		if (bitArray & (1 << 7 - i))
		{
			cout << i << endl;
		}
	}
}
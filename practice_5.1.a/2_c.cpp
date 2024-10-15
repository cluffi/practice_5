#include <iostream>

void c_2()
{
	using namespace std;

	int temp;
	unsigned int amountData, maxValue;

	cout << "Enter max value of numbers more than 0:" << endl;
	cin >> temp;
	if (cin.fail() || temp < 1)
	{
		cout << "Entered bad value" << endl;
		exit(1);
	}
	maxValue = ++temp;

	cout << "Enter amount of numbers more than 0:" << endl;
	cin >> temp;
	if (cin.fail() || temp < 1)
	{
		cout << "Entered bad value" << endl;
		exit(1);
	}
	amountData = temp;

	const unsigned int MAX_LENGTH = maxValue / 8 + (maxValue % 8 != 0); //вычисление длины массива

	unsigned char* bitArray = new unsigned char[MAX_LENGTH]; //создание массива
	for (int i = 0; i < MAX_LENGTH; i++) //обнуление массива
	{
		bitArray[i] = 0;
	}

	cout << "Enter " << amountData << " numbers less than " << maxValue << ", but more than -1:" << endl;
	for (int i = 0; i < amountData; i++)
	{
		if (cin >> temp && temp < maxValue && temp > -1)
		{
			bitArray[temp / 8] = bitArray[temp / 8] | (1 << (7 - temp % 8));
		}
		else
		{
			cout << "Entered bad value" << endl;
			exit(1);
		}
	}
	
	cout << "Soreted entered numbers:" << endl;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		for (int j = 0; j < 8 && i * 8 + j < maxValue; j++)
		{
			if (bitArray[i] & (1 << 7 - j))
			{
				cout << i * 8 + j << endl;
			}
		}
	}
	
}
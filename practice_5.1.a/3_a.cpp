#include <iostream>
#include <chrono>
#include <fstream>

void a_3()
{
	#define INPUT_FILE "source.txt"
	#define OUTPUT_FILE "result.txt"
	using namespace std;


	int temp;
	unsigned int amountData = 550000, maxValue = amountData + 1;

	ofstream fout(INPUT_FILE);
	if (fout.is_open() == 0)
	{
		cout << "File " << OUTPUT_FILE << " is not opened" << endl;
		exit(1);
	}

	for (int i = 0; i < amountData; i++) //заполнение файла числами от наибольшего к наименьшему
	{
		fout << amountData - i << endl;
	}

	fout.close();

	fout.open(OUTPUT_FILE);
	if (fout.is_open() == 0)
	{
		cout << "File " << OUTPUT_FILE << " is not opened" << endl;
		exit(1);
	}


	chrono::high_resolution_clock start, end;
	auto _start = start.now();


	ifstream fin(INPUT_FILE);
	if (fin.is_open() == 0)
	{
		cout << "File" << INPUT_FILE << " is not opened" << endl;
		exit(1);
	}

	const unsigned int MAX_LENGTH = maxValue / 8 + (maxValue % 8 != 0); //вычисление длины массива

	unsigned char* bitArray = new unsigned char[MAX_LENGTH]; //создание массива
	for (int i = 0; i < MAX_LENGTH; i++) //обнуление массива
	{
		bitArray[i] = 0;
	}

	for (int i = 0; i < amountData; i++)
	{
		if (fin >> temp && temp < maxValue && temp > -1)
		{
			bitArray[temp / 8] = bitArray[temp / 8] | (1 << (7 - temp % 8));
		}
		else
		{
			cout << "Entered bad value" << endl;
			exit(1);
		}
	}



	for (int i = 0; i < MAX_LENGTH; i++)
	{
		for (int j = 0; j < 8 && i * 8 + j < maxValue; j++)
		{
			if (bitArray[i] & (1 << 7 - j))
			{
				fout << i * 8 + j << endl;
			}
		}
	}


	auto _end = end.now();
	chrono::duration<double, milli> time = _end - _start;

	cout << "Time execution " << time.count() << " milliseconds" << endl;
	cout << "Memory usage: " << MAX_LENGTH / 1024. << " kB" << endl;
}
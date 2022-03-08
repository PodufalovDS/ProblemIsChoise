#include <iostream>

bool MyArr(int** a,
	int		arrWidth,
	int		arrLength,
	int		i,
	int		j) {

	if (a[0][0] % 2 == 1 && a[0][0] < 100000) {
		a[i][j] += 100000;
		for (int ii = 0; ii < arrWidth; ii++)
			for (int jj = 0; jj < arrLength; jj++)
			{
				if (jj + 1 < arrLength)
					a[ii][jj] += 10;//to rigth
				if (jj - 1 >= 0)
					a[ii][jj] += 100;//to left
				if (ii + 1 < arrWidth)
					a[ii][jj] += 1000;//to down
				if (ii - 1 >= 0)
					a[ii][jj] += 10000;//to top
			}
	}

	if (a[i][j] % 2 == 0)
		return false;
	else
	{
		bool r = true, l = true, d = true, t = true;

		if (a[i][j] % 2 == 1 && i == arrWidth - 1 && j == arrLength - 1)
			return true;
		else
		{
			if (a[i][j] / 10 % 10 == 1) {
				a[i][j] -= 10;
				a[i][j + 1] -= 100;
				r = MyArr(a, arrWidth, arrLength, i, j + 1);
				if (r)
					return true;
			}
			if (a[i][j] / 100 % 10 == 1) {
				a[i][j] -= 100;
				a[i][j - 1] -= 10;
				l = MyArr(a, arrWidth, arrLength, i, j - 1);
				if (l)
					return true;
			}
			if (a[i][j] / 1000 % 10 == 1) {
				a[i][j] -= 1000;
				a[i + 1][j] -= 10000;
				d = MyArr(a, arrWidth, arrLength, i + 1, j);
				if (d)
					return true;
			}
			if (a[i][j] / 10000 % 10 == 1) {
				a[i][j] -= 10000;
				a[i - 1][j] -= 1000;
				t = MyArr(a, arrWidth, arrLength, i - 1, j);
				if (t)
					return true;
			}
		}
		if (!(r && l && d && t))
			return false;
	}

	return false;
}

int main() {
	std::cout << "Input sizes of array(from 2 to 50):\n";
	std::cout << "Length: ";
	short arrayLength = 0;
	std::cin >> arrayLength;
	std::cout << "Width:  ";
	short arrayWidth = 0;
	std::cin >> arrayWidth;
	if (arrayLength < 2 || arrayLength > 50 || arrayWidth < 2 || arrayWidth > 50)
	{
		std::cout << "Sorry, this program can't work with this parameters.\n Application now closed.\n";
	}

	int** a = new int* [arrayWidth];
	if (!a) {
		std::cout << "Code was broken. Program now closing.\n";
		return 0;
	}

	for (int i = 0; i < arrayWidth; i++)
	{
		a[i] = new int[arrayLength];
		if(!a[i]) {
			std::cout << "Code was broken. Program now closing.\n";
			return 0;
		}
	}

	for (int i = 0; i < arrayWidth; i++)
		for (int j = 0; j < arrayLength; j++)
			std::cin >> a[i][j];

	std::cout << '\n'  << MyArr(a, arrayWidth, arrayLength, 0, 0) << '\n';

	for (int i = 0; i < arrayWidth; i++)
		delete a[i];
	delete[] a;

	return 0;
}
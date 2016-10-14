#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{
	const  long arraysize = 500000;
	long *n = new long[arraysize];  
	n[0] = 1;
	int base = 10;
	long i, j, flag;
	for (i = 1; i < arraysize; i++) 
		n[i] = 0;
	flag = 1;
	for (i = 0; i <100000; i++)
	{
		for (j = 0; j < flag; j++)
			n[j] *= (i + 1);
		for (j = 0; j < arraysize - 1; j++)
		if (n[j] >= base) {
			n[j + 1] += n[j] / base;
			if ((j + 1) >= flag - 1)
				flag++;
			n[j] %= base;
		}
	}

	flag = 1;
	for (i = arraysize - 1; i >= 0; i--) {
		if (flag == 1)
		if (n[i] == 0)
			continue;
		else
			flag = 0;
		printf("%d", n[i]);
	}

	printf("\n");
	delete[] n;
	cout <<"final time: "clock() / 1000.0<<endl;
	system("pause");
	return 0;
}
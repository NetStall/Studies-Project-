// ASD 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define N 1000
long long int number_change = 0, number_compare = 0;





void printArray(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("A[%d]=%d\n", i, A[i]);

	}
}



int merge(int A[], int left_index, int midle_index, int right_index)
{
	int i, j, k;
	int n1 = midle_index - left_index + 1;
	int n2 = right_index - midle_index;

	int L[50*N], R[50*N];


	for (i = 0; i < n1; i++)
		L[i] = A[left_index + i];
	for (j = 0; j < n2; j++)
		R[j] = A[midle_index + 1 + j];


	i = 0;
	j = 0;
	k = left_index;
	while (i < n1 && j < n2) {
		number_compare++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
			number_change++;
		}
		else {
			A[k] = R[j];
			j++;
			number_change++;
		}
		k++;
	}


	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}


	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}

	return(A[N]);
}


int mergeSort(int A[], int left_index, int right_index)
{
	if (left_index < right_index) {

		int midle_index = (left_index + right_index) / 2;

		mergeSort(A, left_index, midle_index);
		mergeSort(A, midle_index + 1, right_index);

		merge(A, left_index, midle_index, right_index);
		return A[N];

	}
}



int mergemain(int A[], int n)
{
	int  i;
	
	

	/*printf("Unsorted arrow is\n");
	printArray(A, n);*/

	mergeSort(A, 0, n - 1);

	/*printf("\nSorted array is \n");
	printArray(A, n);*/
	printf("\nCompare number = %lli\n", number_compare);
	printf("\nChange number = %lli\n", number_change);

	return 0;
}


void Sheiker(int A[], int n) {
	int left_border = 1, right_border, i, bufer_number, k = 1;
	srand(time(NULL));
	long long int number_change = 0;
	/*printf("Unsorted arrow\n");
	printArray(A, n);*/

	right_border = n - 1;
	while (k == 1) {
		k = 0;
		for (i = 0; i < right_border; i++)
		{
			if (A[i] > A[i + 1]) {
				bufer_number = A[i + 1];
				A[i + 1] = A[i];
				A[i] = bufer_number;
				k = 1;
				number_change++;

			}
			number_compare++;
		}
		right_border--;
		for (i; i > left_border; i--)
		{
			if (A[i] < A[i - 1]) {
				bufer_number = A[i - 1];
				A[i - 1] = A[i];
				A[i] = bufer_number;
				k = 1;
				number_change++;

			}
			number_compare++;
		}
		left_border++;
		
	}

	/*printf("\nsorted arrow\n");
	printArray(A, n);*/

	printf("\nCompare number = %lli\n", number_compare);
	printf("\nChange number = %lli\n", number_change);


}


int main()
{
	int k=0, e, n, A[100*N];
	for (;;) {
		printf("n=1000 [1], n=10000[2], n=100000 [3]\n");
		scanf_s("%d", &e);
		if (e == 1) {
			n = 1000;
		}
		else if (e == 2) {
			n = 10000;
		}
		else if (e == 3) {
			n = 100000;
		}
		else {
			printf(" i cant complete this, try again\n");
			continue;
		}
		e = 0;
		printf("Best variant[1], worst variant [2], random variant [3]\n");
		scanf_s("%d", &e);
		if (e == 1) {
		
		for (int i = 0; i < n; i++) {
			A[i] = i;
		}
		}
		else if(e ==2) {
			for (int i =0 , j=n ; i != n; i++, j--) {
				A[i] = j;
			}
		}
		else if(e==3){
			srand(time(NULL));
			for (int i = 0; i < n; i++)
			{ 
				
					A[i] = (rand() + rand() + rand()) % n;
				
			}
		}
		else {
			printf(" i cant complete this, try again\n");
			continue;
		}
		

		printf("Cocktail sorting [1]  merge sorting [2]\n");
		scanf_s("%d", &k);
		if (k == 1) {
			Sheiker(A, n);
			number_change = 0;
			number_compare = 0;
		}
		else if (k == 2) {
			mergemain(A, n);
			number_change = 0;
			number_compare = 0;
		}
		else printf(" i cant complete this, try again\n");
	}
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

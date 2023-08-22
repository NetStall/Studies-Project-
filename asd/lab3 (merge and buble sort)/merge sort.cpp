// 2020 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
long long int number_change = 0, number_compare = 0;


int merge(int A[], int left_index, int midle_index, int right_index)
{
    int i, j, k;
    int n1 = midle_index - left_index + 1;
    int n2 = right_index - midle_index; 
    int L[N], R[N];
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
        long long int number_change;
        
        mergeSort(A, left_index, midle_index);
        mergeSort(A, midle_index + 1, right_index);

        merge(A, left_index, midle_index, right_index);
        return A[N];
        
	}
}


void printArray(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("A[%d]=%d\n", i, A[i]);
	}
}



int main()
{
	int  A[N], n, i;
	srand(time(NULL));
	printf("Enter n, A[n]\n");
	scanf_s("%d", &n);
	printf("Unsorted arrow is\n");
	for (i = 0; i < n; i++)
	{ 
		A[i] = (rand() + rand() + rand()) % n;
	}
	printArray(A, n);
	 mergeSort(A, 0, n - 1);
	printf("\nSorted array is \n");
	printArray(A, n);
    printf("\nCompare number = %lli\n", number_compare);
    printf("\nChange number = %lli\n", number_change);
	return 0;
}


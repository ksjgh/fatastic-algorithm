#include<stdio.h>
#include<time.h>    // time()
#include<stdlib.h>  // rand(), srand()
void iteratorSelectionSort(int *ary, int n);
void recursiveSelectionSort(int *ary, int n);
void initArray(int *ary, int n), printArray(int *ary, int n);
int  main()
{
	int numberArray[10], arySize;
	arySize = sizeof(numberArray)/sizeof(numberArray[0]);
	srand((unsigned int) time(NULL));

	initArray(numberArray, arySize);
	iteratorSelectionSort(numberArray, arySize);
	printArray(numberArray, arySize);

	initArray(numberArray, arySize);
	recursiveSelectionSort(numberArray, arySize);
	printArray(numberArray, arySize);
	getchar();
	return 0;
}
void initArray(int *ary, int n)
{
	int i;
	for(i=0; i<n; ++i)
		ary[i] = rand() % 20 + 1;
}

void printArray(int *ary, int n)
{
	int i;
	printf("배열 내용 : ");
	for(i=0; i<n; ++i)
		printf("%4d", ary[i]);
	printf("\n");
}

void iteratorSelectionSort(int *ary, int n)
{
	// TODO
	for(int i = 0 ; i < n ; i++)
    {
        int min_idx = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(ary[j]<ary[min_idx])
                min_idx = j;
        }
        int temp;
        temp = ary[i];
        ary[i] = ary[min_idx];
        ary[min_idx] = temp;
    }
        return;
}

void recursiveSelectionSort(int *ary, int n)
{
	// TODO
	if(n==1)
    {
        return;
    }
    else
    {
        int min_idx = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(ary[j]<ary[min_idx])
                min_idx = j;
        }
        int temp;
        temp = ary[0];
        ary[0] = ary[min_idx];
        ary[min_idx] = temp;
        recursiveSelectionSort( ary+1, n-1);
    }
	return;
}


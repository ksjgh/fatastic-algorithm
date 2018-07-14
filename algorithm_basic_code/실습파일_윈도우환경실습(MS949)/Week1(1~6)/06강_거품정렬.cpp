#include<stdio.h>
#include<time.h>    // time()
#include<stdlib.h>  // rand(), srand()
void iteratorBubbleSort(int *ary, int n);
void recursiveBubbleSort(int *ary, int n);
void initArray(int *ary, int n), printArray(int *ary, int n);

int  main()
{
	int numberArray[10], arySize;
	arySize = sizeof(numberArray)/sizeof(numberArray[0]);
	srand((unsigned int) time(NULL));

	initArray(numberArray, arySize);
	iteratorBubbleSort(numberArray, arySize);
	printArray(numberArray, arySize);

	initArray(numberArray, arySize);
	recursiveBubbleSort(numberArray, arySize);
	printArray(numberArray, arySize);
	getchar();
	return 0;
}

void iteratorBubbleSort(int *ary, int n)
{
	// TODO
	////printf("------ iteratorBubbleSort called ------\n");
	for(int j=n-1; j>=1; --j)
    {
        //printf("Outer Loop j = %d\n",j);
        for(int i=0; i < j ; ++i)
        {
            //printf("    Innter Loop i = %d\n",i);
            if(ary[i] > ary[i+1])
            {
                int temp;
                temp = ary[i];
                ary[i] = ary[i+1];
                ary[i+1] = temp;
            }
        }
    }
	return;
}

void recursiveBubbleSort(int *ary, int n)
{
	// TODO
	//printf("--------recursiveBubbleSort ------ \n");
	if(n==1)
        return;
    else
    {
        for(int i=0 ; i < n-1 ; ++i )
        {
            if(ary[i] > ary[i+1])
            {
                int temp;
                temp = ary[i];
                ary[i] = ary[i+1];
                ary[i+1] = temp;
            }
        }
        recursiveBubbleSort(ary,n-1);
    }
    return;

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

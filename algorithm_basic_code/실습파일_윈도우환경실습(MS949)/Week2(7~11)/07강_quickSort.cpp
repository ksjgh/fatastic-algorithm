#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quickSort(int *ary, int size);
void output(int *ary, int size);
void initArray(int *ary, int n);

//#define DEBUG

int main()
{
	#ifdef DEBUG
	    printf("----- Debug Mode -----\n");
        int dataList[3];
    #else
        int dataList[10000];
        //int dataList[10];
	#endif




	int startTime, endTime;
	int size = sizeof(dataList) / sizeof(dataList[0]);

	srand((unsigned int)time(NULL));

	initArray(dataList, size);
	#ifdef DEBUG
        printf("unsorted array\n");
        output(dataList,size);
	#endif // DEBUG

	startTime = clock();
	quickSort(dataList, size); 	/* �� ���� �Լ� ȣ�� */
	endTime = clock();
	printf("\n\n[ �� ����  �� ��� ]\n");
	output(dataList, size);
	printf("����Ʈ �˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime-startTime));

	getchar();
	return 0;
}
/*----------------------------------------------------------------------
�Լ��� �� ��� : quickSort() - �� ���� �Լ�
��������: ary - ������ ������ �迭�� �����ּ�
size - ��Ʈ�� �������� ����
���ϰ�: ����
--------------------------------------------------------------------*/
void quickSort(int *ary, int size)
{
	int idx_pivot, temp;
	int idx_l;
	int idx_r;

	if(size<=1) return; // �������� 1�����̸� sort�� �Ϸ�� �� �̹Ƿ� return

	idx_pivot = size-1;
	idx_l=0,
	idx_r=idx_pivot-1;

	while(1)
    {
         move idx_l until find value larger than pivot
        while(1)
        {
            if(ary[idx_l]>ary[idx_pivot]) break;
            if(++idx_l == idx_pivot) break;
        }

        //while(ary[idx_l] < ary[idx_pivot]) ++idx_l;

        #ifdef DEBUG
        printf("idx_l = %d\n" , idx_l );
        #endif // DEBUG

         move idx_r until find value smaller than pivot
        while(1)
        {
            if(ary[idx_r]<ary[idx_pivot]) break;
            if(--idx_r == 0) break;
        }

        //while( (ary[idx_r] > ary[idx_pivot]) && (idx_r>=0)) --idx_r;

        #ifdef DEBUG
        printf("idx_r = %d\n" , idx_r );
        #endif // DEBUG

        if(idx_l>=idx_r) break;

        // swap l,r value
        temp = ary[idx_l];
        ary[idx_l] = ary[idx_r];
        ary[idx_r] = temp;
    }

    // swap pivot with idx_l
    temp = ary[idx_pivot];
    ary[idx_pivot] = ary[idx_l];
    ary[idx_l] = temp;
    idx_pivot = idx_l;

    #ifdef DEBUG
    printf("\n");
    printf("Quick Sort Module , First Sequence\n");
    output(ary,size);
    #endif // DEBUG

	// ���� �ұ����� ���� �� ���� ��� ȣ��
//	quickSort(ary,idx_pivot);

	// ���� �ұ����� ���� �� ���� ��� ȣ��
//	quickSort(ary+idx_pivot+1,size-idx_pivot-1);
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : output() - �迭�� ��� ���� ����ϱ�
��������: ary - ������ ������ �迭�� �����ּ�
size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void output(int *ary, int size)
{
	for(int i=0; i<size; i++)
	{
		printf(" %d ", ary[i]);
	}
	printf("\n");
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : initArray() - �迭�� ���Ҹ� ������ �ʱ�ȭ
��������: ary - �ʱ�ȭ�� ������ �迭�� �����ּ�
size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void initArray(int *ary, int n)
{
	int i;

	#ifdef DEBUG
	for(i=0; i<n; ++i)
		ary[i] = rand() % 100 + 1;
	#else
	for(i=0; i<n; ++i)
		ary[i] = rand() % 1000 + 1;
	#endif // DEBUG

}

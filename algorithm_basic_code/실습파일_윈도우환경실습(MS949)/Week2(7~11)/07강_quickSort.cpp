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
	quickSort(dataList, size); 	/* 퀵 정렬 함수 호출 */
	endTime = clock();
	printf("\n\n[ 퀵 정렬  후 출력 ]\n");
	output(dataList, size);
	printf("퀵소트 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime-startTime));

	getchar();
	return 0;
}
/*----------------------------------------------------------------------
함수명 및 기능 : quickSort() - 퀵 정렬 함수
전달인자: ary - 정렬할 데이터 배열의 시작주소
size - 소트할 데이터의 개수
리턴값: 없음
--------------------------------------------------------------------*/
void quickSort(int *ary, int size)
{
	int idx_pivot, temp;
	int idx_l;
	int idx_r;

	if(size<=1) return; // 구간값이 1이하이면 sort가 완료된 것 이므로 return

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

	// 좌측 소구간에 대한 퀵 정렬 재귀 호출
//	quickSort(ary,idx_pivot);

	// 우측 소구간에 대한 퀵 정렬 재귀 호출
//	quickSort(ary+idx_pivot+1,size-idx_pivot-1);
}
/*------------------------------------------------------------------------
함수명 및 기능 : output() - 배열의 모든 원소 출력하기
전달인자: ary - 정렬할 데이터 배열의 시작주소
size - 데이터의 개수
리턴값: 없음
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
함수명 및 기능 : initArray() - 배열의 원소를 난수로 초기화
전달인자: ary - 초기화할 데이터 배열의 시작주소
size - 데이터의 개수
리턴값: 없음
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

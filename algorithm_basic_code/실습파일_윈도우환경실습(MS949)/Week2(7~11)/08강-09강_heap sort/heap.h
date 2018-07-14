#pragma once 

enum BOOL {FALSE, TRUE};

typedef struct _heap { 
	int * heap;
	int hSize; 
	int count;  /* heap�� ����Ǿ��ִ� �������� �� */
}Heap; 

BOOL createHeap(Heap *hPtr , int size);			/* �� ���� �Լ� */
void destroyHeap(Heap *hPtr);					/* �� �Ҹ� �Լ� */
//BOOL insertUpHeap(Heap *hPtr, int inData);		/* ���� ������ �ϳ��� ������ */
BOOL deleteDownHeap(Heap * hPtr, int * getData);	/* ���� ������ �ϳ��� ���� */
void downHeap(Heap *hPtr, int position);		/* ���� ��带 ��ġ�� �°� down ��Ŵ */
void printHeap(const Heap * hPtr);				/* �� ���� ������ ��� (����->���� ����) */
BOOL isHeapEmpty(Heap *hPtr);					/* ���� ������ ����ִ°� �˻� */
BOOL isHeapFull(Heap *hPtr);						/* ���� ���� �ִ°� �˻� */

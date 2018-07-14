#pragma once 
enum BOOL { FALSE, TRUE };

typedef struct rowcol { /* �࿭ ��ǥ 1 ��Ʈ�� �����ϴ� ����ü */
	int row;
	int col;
}RC;

typedef struct _queue { /* ����ť ���� ����ü */
	RC *queue;
	int size;
	int front, rear;
}Queue;

BOOL createQueue(Queue * qp, int size);		/* ť ���� �� �ʱ�ȭ �Լ� */
BOOL isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
BOOL isQueueFull(const Queue *qp);			/* ť�� �����ִ°� �˻� */
BOOL enqueue(Queue * qp, RC enqueData);		/* ť�� ������ �ϳ��� ���� �� */
BOOL dequeue(Queue * qp, RC * dequeData);	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp);			/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp);				/* ť �Ҹ� �Լ� */

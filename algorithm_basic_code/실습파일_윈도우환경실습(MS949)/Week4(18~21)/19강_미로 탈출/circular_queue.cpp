#include <stdio.h> 
#include <malloc.h> 
#include "circularQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ����ť ���� �� �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
				  size - ť�� ũ��
Returns			: ���� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL createQueue(Queue * qp, int size)
{
	if (qp == NULL) {  /* qp ������ NULL check*/
		return FALSE;
	}
	qp->queue = (RC *)calloc(size, sizeof(RC));	/* queue �޸� �Ҵ� */
	if (qp->queue != NULL) {	/* queue �޸� �Ҵ� ���� �� */
		qp->size = size;
		qp->front = 0;
		qp->rear = 0;
		return TRUE;
	}
	else {	/* queue �޸� �Ҵ� ���� �� */
		return FALSE;
	}	
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - ť�� ����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (qp->front == qp->rear)	/* queue�� �ֺ�� ������ */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueFull - ť�� �����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ���� ������ TRUE ����, �ƴϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isQueueFull(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (qp->front == (qp->rear + 1) % qp->size) /* queue�� ������ ��� ������ */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue() - ť�� ������ �ϳ��� ������
Parameters		: qp - ť ����ü�� �ּ�
			  	  enqueData - ť�� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL enqueue(Queue * qp, RC enqueData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (isQueueFull(qp))	/* queue�� ���������� enqueue �Ұ� */ 
	{
		return FALSE;
	}

	/* rear ��ġ�� ������ ���� �� rear ���� */
	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear + 1) % qp->size;
	return TRUE;

}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dequeue(Queue * qp, RC * dequeData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (isQueueEmpty(qp))	/* ť�� ��������� dequeue �Ұ� */
	{
		return FALSE;
	}

	/* �����͸� front��ġ���� ���� dequeData�� ����Ű�� ���� ���� �� */
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front + 1) % qp->size;

	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}
	/* queue���� ��� ������ ��� (dequeue �ϸ� ��µǴ� ������ ���) */
	for (int i = qp->front; i != qp->rear; i = (i + 1) % qp->size)
	{
		printf("(%d,%d) ", qp->queue[i].row, qp->queue[i].col);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}

	if (qp->queue != NULL) { /* queue�� ���Ǵ� �迭 �޸� ���� */
		free(qp->queue);
	}
	qp->queue = NULL;	/* queue ����� NULL pointer�� �ʱ�ȭ */
	qp->size = 0;		/* size����� 0���� �ʱ�ȭ */
	qp->front = qp->rear = 0;	/* front, rear ����� 0���� �ʱ�ȭ */
}

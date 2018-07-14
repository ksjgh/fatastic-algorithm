#include <stdio.h>
size_t initArray(int *ap, size_t size); /* 100�� ���Ϸ� ���ϴ� ��ŭ ������ �Է� �޾� �迭�� �����ϴ� �Լ� */
int checkMAX(int *ap, size_t count, size_t *index); /* �迭���� �ִ밪�� �� ��ġ�� ���ϴ� �Լ� */
int checkMIN(int *ap, size_t count, size_t *index); /* �迭���� �ּҰ��� �� ��ġ�� ���ϴ� �Լ� */
void output(int maxNum, int maxIndex, int minNum, int minIndex); /* ��� ��� �Լ� */
/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
int main()
{
	int ary[100]; /* �ִ� �ּҰ��� �˻��� �����͸� �����ϴ� �迭 */
	size_t count; /* �迭���� ����� �������� ���� ���� */
	int maxNum;  /* �ִ밪 ���� */
	int minNum;  /* �ּҰ� ����  */
	size_t maxIndex;  /* �ִ밪�� ��ġ(index) ����  */
	size_t minIndex;  /* �ּҰ��� ��ġ(index) ����  */

	count = initArray(ary, sizeof(ary)/sizeof(ary[0]));
	maxNum = checkMAX(ary, count, &maxIndex);
	minNum = checkMIN(ary, count, &minIndex);
	output(maxNum,maxIndex,minNum,minIndex);

	getchar(); getchar();
	return 0;
}

/*------------------------------------------------------------------
Function name 	: initArray() - 100�� ���Ϸ� ���ϴ� ��ŭ ������ �Է� �޾� �迭�� �����ϴ� �Լ�
Parameters		: ap - ������ ����迭�� �ּ�
				  size - �迭�� ���� ����
Returns			: �迭���� ����Ǿ��ִ� �������� ����
------------------------------------------------------------------*/
size_t initArray(int *ap, size_t size)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*------------------------------------------------------------------
Function name 	: checkMAX() - �迭���� �ִ밪�� �� ��ġ�� ���ϴ� �Լ�
Parameters		: ap - ������ ����迭�� �ּ�
				  count - �迭���� ����Ǿ��ִ� �������� ����
				  index - �ִ밪�� �ε����� ������ ������ �����ּҸ� ���� ������ ����
Returns			: �迭���� �ִ밪
------------------------------------------------------------------*/
int checkMAX(int *ap, size_t count, size_t *index)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*------------------------------------------------------------------
Function name 	: checkMin() - �迭���� �ּҰ��� �� ��ġ�� ���ϴ� �Լ�
Parameters		: ap - ������ ����迭�� �ּ�
				  count - �迭���� ����Ǿ��ִ� �������� ����
				  index - �ּҰ��� �ε����� ������ ������ �����ּҸ� ���� ������ ����
Returns			: �迭���� �ּҰ�
------------------------------------------------------------------*/
int checkMIN(int *ap, size_t count, size_t *index)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*------------------------------------------------------------------
Function name 	: output() - ��� ��� �Լ�
Parameters		: maxNum - �ִ밪
				  maxIndex - �ִ밪�� �ε���
				  minNum - �ּҰ�
				  minIndex - �ּҰ��� �ε���
Returns			: ����
------------------------------------------------------------------*/
void output(int maxNum, int maxIndex, int minNum, int minIndex)
{
	printf(" �ִ밪 : %d(index:%d) / �ִ밪 : %d(index:%d)\n",
			maxNum, maxIndex, minNum, minIndex);
}

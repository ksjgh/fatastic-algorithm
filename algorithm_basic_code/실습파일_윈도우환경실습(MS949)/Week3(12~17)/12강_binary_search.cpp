#include <stdio.h>
void quickSort(int *ap, int size);
int binarySearch(int *ap, int leftIndex, int rightIndex, int key);
int rbinarySearch(int *ap, int leftIndex, int rightIndex, int key);
void output(int *ap, int size);
/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
int main()
{
	int ary[]={11,3,25,7,19,10,13,35,8,19};
	int size;        // �迭��Ұ��� ����
	int key;         // ã�� ���� ����
	int index;      // �˻��� �������� �ε���
	int res;        // scanf()�Լ��� ���ϰ� ����
	size = sizeof(ary)/sizeof(ary[0]);
	quickSort(ary, size);
	output(ary, size);

	while(1)
	{
		printf("�˻��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &key);
		if(res != 1) {break;}   // �����Է� �� ����
		if( ( index = rbinarySearch(ary, 0, size-1, key) ) != -1)
		{
			printf("%d�� %d���� �������Դϴ�.\n", key, index);
		}
		else
		{
			printf("%d�� �������� �ʽ��ϴ�.\n", key);
		}
	}
	return 0;
}
/*---------------------------------------------------------------------
Function name 	: binarySearch() - �̺� �˻� �Լ�
Parameters		: ap - �˻��� ������ �迭�� �����ּ�
				  leftIndex - �˻� ������ ���� �ε���
				  rightIndex - �˻� ������ ���� �ε���
				  key - �˻��� ������
Returns			: �˻� ���� �� - ã�� ������ index / �˻� ���� �� - -1 ����
--------------------------------------------------------------------*/
int binarySearch(int *ap, int leftIndex, int rightIndex, int key)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*------------------------------------------------------------------------
Function name 	: rbinarySearch() - ���ȣ�� ����� �̺� �˻� �Լ�
Parameters		: ap - �˻��� ������ �迭�� �����ּ�
				  leftIndex - �˻� ������ ���� �ε���
				  rightIndex - �˻� ������ ���� �ε���
				  key - �˻��� ������
Returns			: �˻� ���� �� ã�� ������ index / �˻� ���� �� -1 ����
------------------------------------------------------------------------*/
int rbinarySearch(int *ap, int leftIndex, int rightIndex, int key)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------
Function name 	: quickSort() - �� ���� �Լ�
Parameters		: ary - ������ ������ �迭�� �����ּ�
				  size - ��Ʈ�� �������� ����
Returns			: ����
--------------------------------------------------------------------*/
void quickSort(int *ap, int size)
{
	int pivot, temp;
	int i, j;

	if(size <= 1) return;// �������� 1�����̸� sort�� �Ϸ�� �� �̹Ƿ� return

	pivot = ap[size-1];         // ������ ���� �������� pivot���� ����
	i = -1;        // i�� �������� ���� �˻��� ��ġ ����
	j = size-1;    // j�� �������� ���� �˻��� ��ġ ����

	while(1)       // ���� �۾�
	{
		while(ap[++i] < pivot);  // �������κ��� pivot���� ū �� ��ġ ã��
		while(j>0 && ap[--j] > pivot ); // �������κ��� pivot���� ���� �� ��ġ ã��
		if(i >= j ) break; //i�� j���� ũ�ų� �������� ������ ���̹Ƿ� while�� Ż��
		// �ƴϸ� i�� j�� ���� �� swap
		temp = ap[i];
		ap[i] = ap[j];
		ap[j] = temp;
	}
	// ������ �������� i�� ���� ���� pivot��ġ�� �� swap
	temp = ap[i];
	ap[i] = ap[size-1];    // ���⼭ pivot������ ���� �ٲ��� �ʵ��� ����
	ap[size-1] = temp;

	quickSort(ap, i);             // ���� �ұ����� ���� �� ���� ��� ȣ��
	quickSort(ap+i+1, size-i-1);  // ���� �ұ����� ���� �� ���� ��� ȣ��
}

/*------------------------------------------------------------------------
Function name 	: output() - �迭�� ��� ���� ����ϱ�
Parameters		: ary - ������ ������ �迭�� �����ּ�
				  size - �������� ����
Returns			: ����
------------------------------------------------------------------------*/
void output(int *ap, int size)
{
	for(int i=0; i<size;i++)
	{
		printf(" %d ", ap[i]);
	}
	printf("\n");
}

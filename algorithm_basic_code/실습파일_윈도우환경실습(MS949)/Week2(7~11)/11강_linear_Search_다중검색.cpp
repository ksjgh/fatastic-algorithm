#include <stdio.h>
#include <malloc.h>
int linearUniqueSearch(int *ap, size_t size, int key);	/* �����˻��Լ�(���ϰ˻�) */
size_t *linearMultiSearch(int *ap, size_t size, int key, size_t *pcnt);	/* �����˻��Լ�(���߰˻�) */
void output(int *ap, size_t size);	/* �迭�� ��� ���� ����ϱ� */
void myflush();	/* �Է¹���(stdin)���� ��� �����͸� ���� �� */
/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
int main()
{
	int ary[]={6,17,3,25,6,17,10,13,35,8,17};
	size_t size;		/* �迭��� ���� ���� */
	int key;			/* �˻��� ���� ���� */
	int index;			/* ���ϰ˻��� �������� �ε��� ���� */
	size_t i;			/* iterator */
	int res;        	/* scanf()�Լ��� ���ϰ� ���� */
	size_t *multiIndex;	/* ���߰˻��� �������� �ε��� ���� �迭�� �ּ� ���� */
	size_t findCnt;		/* ���߰˻��� �������� ���� */

	size = sizeof(ary)/sizeof(ary[0]);	/* �迭�� ���� ���� ��� */
	output(ary, size);
	/* ���� �˻� �׽�Ʈ */
	printf("------------------------------------------\n");
	printf("\t ���� �˻� �׽�Ʈ\n");
	printf("------------------------------------------\n");
	while(1){
		printf("���� �˻��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &key);
		if(res != 1) {break;}   /* �����Է� �� ���� */
		if( ( index = linearUniqueSearch(ary, size, key) ) != -1){
			printf("%d�� %d���� �������Դϴ�.\n", key, index);
		}
		else{
			printf("%d�� �������� �ʽ��ϴ�.\n", key);
		}
	}
	myflush();	/* �Է¹���(stdin)���� ��� �����͸� ���� */

	/* ���� �˻� �׽�Ʈ */
	printf("------------------------------------------\n");
	printf("\t ���� �˻� �׽�Ʈ \n");
	printf("------------------------------------------\n");
	while(1){
		printf("���� �˻��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &key);
		if(res != 1) {break;}   // �����Է� �� ����
		if( ( multiIndex = linearMultiSearch(ary, size, key, &findCnt) ) != NULL){
			printf("%d�� : ", key);
			for(i=0; i<findCnt; ++i){
				printf("%d����, ", multiIndex[i]);
			}
			printf("\b\b ������ �Դϴ�.\n");
			free(multiIndex);  /* ���ϸ� memory leak!! */
		}
		else{
			printf("%d�� �������� �ʽ��ϴ�.\n", key);
		}
	}
	myflush();
	getchar();
	return 0;
}
/*---------------------------------------------------------------------
Function name 	: linearUniqueSearch() - �����˻��Լ�(���ϰ˻�)
Parameters		: ap - �˻��� ������ �迭�� �����ּ�
				  size - �迭���� ������ ��
				  key - �˻��� ������
Returns			: �˻� ���� �� ã�� ������ index ���� / �˻� ���� �� -1 ����
--------------------------------------------------------------------*/
int linearUniqueSearch(int *ap, size_t size, int key)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*---------------------------------------------------------------------
Function name 	: linearMultiSearch() - �����˻��Լ�(���߰˻�)
Parameters		: ap - �˻��� ������ �迭�� �����ּ�
				  size - �迭���� ������ ����
				  key - �˻��� ������
				  pcnt - �˻��� �������� ������ ������ ������ �����ּ�
Returns			: ã�� index���� ����� �����Ҵ� �迭�� �����ּ� ���� / ���� �� NULL pointer ����
--------------------------------------------------------------------*/
size_t * linearMultiSearch(int *ap, size_t size, int key, size_t *pcnt)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*------------------------------------------------------------------------
Function name 	: output() - �迭�� ��� ���� ����ϱ�
Parameters		: ap - ������ ������ �迭�� �����ּ�
				  size - �������� ����
Returns			: ����
------------------------------------------------------------------------*/
void output(int *ap, size_t size)
{
	size_t i;
	printf("�迭 ������ : ");
	for(i=0; i<size;i++)
	{
		printf(" %d ", ap[i]);
	}
	printf("\n");
}
/*------------------------------------------------------------------------
Function name 	: myflush() - �Է¹���(stdin)���� ��� �����͸� ���� ��
Parameters		: ����
Returns			: ����
------------------------------------------------------------------------*/
void myflush(){
	while(getchar()!='\n'){
		;
	}
}

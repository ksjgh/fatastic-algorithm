#include <stdio.h>
#include <malloc.h>
int greaterThan(int *ap, size_t size, int key); /* key�� ���� ū ���� ó������ ��Ÿ���� ��ġ�� �����ϴ� �Լ� */
int upperBound(int *ap, size_t size, int key); /* key�� ���� ũ�ų� ���� ���� ó������ ��Ÿ���� ��ġ�� �����ϴ� �Լ� */
void bubbleSort(int *ap, int size); /* ���� ���� �Լ� */
void output(int *ap, size_t size); /* �迭�� ��� ���� ����ϱ� */
void myflush(); /* �Է¹���(stdin)���� ��� �����͸� ���� �� */
/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main() {
	int ary[] = { 15, 5, 3, 7, 15, 7, 30, 12, 20, 40, 7 };
	size_t size; /* �迭��� ���� ���� */
	int key; /* �˻��� ���� ���� */
	int position; /* ��ġ ���� */
	int res; /* scanf()�Լ��� ���ϰ� ���� */

	size = sizeof(ary) / sizeof(ary[0]); /* �迭�� ���� ���� ��� */
	bubbleSort(ary, size);
	output(ary, size);

	/* upperBound(key�� ���� ũ�ų� ���� ���� ù ��ġ) �˻� �׽�Ʈ */
	printf("------------------------------------------------\n");
	printf("  upperBound(key�� ���� ũ�ų� �������� ù ��ġ) �˻� �׽�Ʈ \n");
	printf("------------------------------------------------\n");
	while (1) {
		printf("�˻��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &key);
		if (res != 1) {
			break;
		} /* �����Է� �� ���� */
		position = upperBound(ary, size, key);
		printf("%d ���� ũ�ų� ���� ���� ù ��ġ�� %d ��° �Դϴ�.\n", key, position);
	}
	myflush(); /* �Է¹���(stdin)���� ��� �����͸� ���� */

	output(ary, size);
	/* greaterThan(key�� ���� ū���� ù��ġ) �˻� �׽�Ʈ */
	printf("------------------------------------------------\n");
	printf("    greaterThan(key�� ���� ū���� ù��ġ) �˻� �׽�Ʈ \n");
	printf("------------------------------------------------\n");
	while (1) {
		printf("�˻��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &key);
		if (res != 1) {
			break;
		} /* �����Է� �� ���� */
		position = greaterThan(ary, size, key);
		printf("%d ���� ū���� ù ��ġ�� %d ��° �Դϴ�.\n", key, position);
	}
	myflush();
	getchar();
	return 0;
}
/*---------------------------------------------------------------------
 Function name 	: upperBound() - key�� ���� ũ�ų� ���� ���� ó������ ��Ÿ���� ��ġ�� �����ϴ� �Լ�
 Parameters		: ap - �˻��� ������ �迭�� �����ּ�
 	 	 	 	  size - �迭���� ������ ��
 	 	 	 	  key - �˻��� ������
 Returns		: key�� ���� ũ�ų� ���� ���� ó������ ��Ÿ���� ��ġ�� ����
 --------------------------------------------------------------------*/
int upperBound(int *ap, size_t size, int key) {
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*---------------------------------------------------------------------
 Function name 	: greaterThan() - key�� ���� ū ���� ó������ ��Ÿ���� ��ġ�� �����ϴ� �Լ�
 Parameters		: ap - �˻��� ������ �迭�� �����ּ�
 	 	 	 	  size - �迭���� ������ ��
 	 	 	 	  key - �˻��� ������
 Returns		: key�� ���� ū ���� ó������ ��Ÿ���� ��ġ ����
 --------------------------------------------------------------------*/
int greaterThan(int *ap, size_t size, int key) {
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
 Function name 	: bubbleSort() - ���� ���� �Լ�
 Parameters		: ary - ������ ������ �迭�� �����ּ�
 	 	 	 	  size - ��Ʈ�� �������� ����
 Returns		: ����
 --------------------------------------------------------------------------------------*/
void bubbleSort(int *ap, int size) {
	int i, j, temp;
	for (i = size; i > 1; i--) {
		for (j = 1; j < i; j++) {
			if (ap[j - 1] > ap[j]) {
				temp = ap[j - 1];
				ap[j - 1] = ap[j];
				ap[j] = temp;
			}
		}
	}
}
/*------------------------------------------------------------------------
 Function name 	: output() - �迭�� ��� ���� ����ϱ�
 Parameters		: ap - ������ ������ �迭�� �����ּ�
 	 	 	 	  size - �������� ����
 Returns		: ����
 ------------------------------------------------------------------------*/
void output(int *ap, size_t size) {
	size_t i;
	printf("��       �� : ");
	for (i = 0; i < size; i++) {
		printf("|%4d", i+1);
	}
	printf("\n�迭 ������ : ");
	for (i = 0; i < size; i++) {
		printf("%5d", ap[i]);
	}
	printf("\n");
}
/*------------------------------------------------------------------------
 Function name 	: myflush() - �Է¹���(stdin)���� ��� �����͸� ���� ��
 Parameters		: ����
 Returns			: ����
 ------------------------------------------------------------------------*/
void myflush() {
	while (getchar() != '\n') {
		;
	}
}

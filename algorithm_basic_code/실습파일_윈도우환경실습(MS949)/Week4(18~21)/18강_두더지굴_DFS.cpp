
#include<stdio.h>
enum BOOL {FALSE, TRUE};
#define NL printf("\n") /* �� �ٲٱ� ��ũ�� */
#define MAX_SIZE 30		/* map�� ����(row), ����(column)�� �ִ� ũ�� */
int map[MAX_SIZE + 1][MAX_SIZE + 1];  /* �δ��� ���� ���� ����(0��, 0�� ��� ����) */
BOOL dataLoad(const char *fileName);	/* ������ ���Ͽ��� map������ �Է� �޾� map�� �ʱ�ȭ �ϴ� �Լ� */
void initTunnelInfo(); 	/* ���� ������ ������ ����ü �迭 �ʱ�ȭ �Լ� */
void solve(); 			/* �δ��� ���� ����, ũ�⸦ ����ϴ� �Լ�(���ȣ�� ������ dfs()�Լ� �̿�) */
BOOL inRange(int row, int col);	/* row, column ���� ���ռ� �Ǻ� �Լ� */
void dfs(int row, int col, int tNum);	/* row, col�� ���� �δ��� ������ dfs������� ���ȣ���ϸ� �˻��ϴ� �Լ� */
void output();			/* �δ��� �� ���� ��� �Լ� */

typedef struct tunnel_info {
	int number;  /* �� ��ȣ */
	int size;    /* �� ũ�� */
}TunnelInfo;

TunnelInfo tunnelInfo[MAX_SIZE * 2 + 1];    /* �δ��� ���� ũ�� ����(2�� ����� ���) */
int n;  			/* map�� ����(row), ����(column)�� ũ�� ���� ���� */
int tunnelNumber;  /* �δ����� ��ȣ */
/*-------------------------------------------------------------------------------------
Function name 	: main() - �׷����� �����ϰ� DFS Ž���� �ǽ��Ѵ�.
------------------------------------------------------------------------------------*/
int main()
{
	const char *fileName[] = { "d:\\data\\�δ�����1.txt" , "d:\\data\\�δ�����2.txt", "d:\\data\\�δ�����3.txt" };
	size_t i;
	for (i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
		tunnelNumber = 2; /* �δ����� ��ȣ(1�� �ͳ��� ������ �ǹ��ϹǷ� 2�� ���� ���) */
		if (dataLoad(fileName[i]) == FALSE) return 0;
		solve();
		output();
		NL;
		printf("===================================================================\n\n");
		getchar();
	}
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: dataLoad() - ������ ���Ͽ��� �˻��� �����͸� �Է� �޾� map�� �����ϴ� �Լ�
Parameters		: char *fileName - �δ��� ���� ������ ����� ������ ���ϸ�
Returns			: ���� �бⰡ �����ϸ� TRUE ����, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dataLoad(const char *fileName)
{
	FILE *fp;

	int i, j; /* iterator */
	fp = fopen(fileName, "rt");
	if (fp == NULL) {
		printf("file open error!!!\n");
		getchar();
		return FALSE;
	}
	if (fscanf(fp, "%d", &n) != 1) return FALSE;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (fscanf(fp, "%d", &map[i][j]) != 1) return FALSE;
		}
	}
	fclose(fp);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name 	: initTunnelInfo() - ���� ������ ������ ����ü �迭 �ʱ�ȭ �Լ�
Parameters		: ����
Returns			: ����
--------------------------------------------------------------------------------------*/
void initTunnelInfo()
{
	int i;
	for (i = 0; i <= MAX_SIZE*2; ++i) {
		tunnelInfo[i].number = i;
		tunnelInfo[i].size = 0;  /* extern���� ����� �迭�� ����̹Ƿ� ���ص� �� */
	}
}
/*--------------------------------------------------------------------------------------
Function name 	: solve() - �δ��� ���� ����, ũ�⸦ ����ϴ� �Լ�(���ȣ�� ������ dfs�� �̿��� Ǯ��)
Parameters		: ����
Parameters		: ����
--------------------------------------------------------------------------------------*/
void solve()
{
	// TODO
	return;
}
/*--------------------------------------------------------------------------------------
Function name 	: inRange() - row, column�� ���ռ� �Ǻ� �Լ�
Parameters		: int row - �� ��
                  int col - �� ��
Returns			: ������ �����̸� TRUE ����, �������� �����̸� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL inRange(int row, int col)
{
	if((0<row && row<=n) && (0<col && col<=n))
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name 	: dfs() - row, col�� ���� �δ��� ������ dfs������� ���ȣ���ϸ� �˻��ϴ� �Լ�
Parameters		: int row - �� ��
				  int col - �� ��
                  int tNum - �δ��� �� ��ȣ
Returns			: ����
--------------------------------------------------------------------------------------*/
void dfs(int row, int col, int tNum)
{
	// TODO
	return;
}
/*--------------------------------------------------------------------------------------
Function name 	: output() - �δ��� �� ���� ����Լ�
Parameters		: ����
Returns			: ����
--------------------------------------------------------------------------------------*/
void output()
{
	int i, j;
	printf("** �δ��� �� ���� : %d��\n", tunnelNumber-2);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			printf("%3d", map[i][j]);
		}
		NL;
	}
	NL;

	printf("** �δ��� �� ���� ��� **\n");
	for (i = 2; i < tunnelNumber; ++i) {
		printf("size of tunnel %d : %d\n", tunnelInfo[i].number, tunnelInfo[i].size);
	}

}

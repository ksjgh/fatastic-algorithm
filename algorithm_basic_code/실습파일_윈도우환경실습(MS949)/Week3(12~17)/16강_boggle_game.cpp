#include <stdio.h>
#include <string.h>
enum BOOL {FALSE, TRUE};
#define MAX_BSIZE 1000

typedef struct _relativeCoordinate
{
	int y;  /* y ��� ��ǥ */
	int x;  /* x ��� ��ǥ */
}RCoordinate;

BOOL initBoard(FILE *fp);
BOOL boggleGame(const char *searchWord);
BOOL hasWord(int y, int x, const char * word);
BOOL inRange(int y,int x);

int maxY;   /* y��ǥ�� �ִ밪 ���� */
int maxX;   /* x��ǥ�� �ִ밪 ���� */

RCoordinate RCXY[8] = { {-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1},{0,-1},{0,1} }; /* ��� ��ǥ ��� �迭 */
/* ( 0, 0 )�� ������ġ�� ������ �����ǥ ǥ��
(-1,-1) ( 0,-1) ( 1,-1)
(-1, 0) ( 0, 0) ( 1, 0)
(-1, 1) ( 0, 1) ( 1, 1)
*/
char board[MAX_BSIZE][MAX_BSIZE+2]; /* NULL���ڿ� ���๮�ڸ� ����ؼ� column�� +2 */
/*----------------------------------------------------------------------------------------
 �Լ��� : main()
----------------------------------------------------------------------------------------*/
int main()
{
	FILE *fp;
	int res;  /* �ܾ� �˻� ���� �� 1, ���� �� 0 ���� */
	const char *searchWord[] = {"LECTOPIA", "LGE", "ASDVX"};
	int count=0;  /* ���� Ƚ�� �������� */

	fp=fopen("d:\\data\\boggleGame.txt", "rt");
	if(fp==NULL) {
		printf("FILE open error!!\n");
		return 1;
	}

	while(initBoard(fp))
	{
		res = boggleGame(searchWord[count]); /* ���� ���� �Լ� ȣ�� */

		if(res == TRUE)  /* �ܾ  ã������ */
			printf("+ Existence!!(%s)\n", searchWord[count]);
		else   /* �ܾ ��ã������ */
			printf("- Nonexistence!!(%s)\n", searchWord[count]);
		++count;
		getchar();
	}
	fclose(fp);
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: initBoard() - ���Ͽ��� ���� ������ board������ �Է� �޾� �ʱ�ȭ�ϴ� �Լ�
Parameters		: fp - board������ �����ϰ� �ִ� ������ ���� ������
Returns			: board������ ���������� �ʱ�ȭ �ϸ� 1����, �����ϸ� 0 ����
--------------------------------------------------------------------------------------*/
BOOL initBoard(FILE *fp)
{
	int i; /* iterator */
	fscanf(fp, "%d %d\n", &maxY, &maxX);  /* ������ ���� ������ ���� ���� �б� */
	if(maxY==0 || maxX==0) return FALSE;  /* ���� �Ǵ� ���� ũ�Ⱑ 0�̸� �ʱ�ȭ ���� */

	for(i=0; i< maxY; ++i)
	{
		fgets(board[i], maxX+2, fp); /* ���๮�ڿ� �ι����� ũ�� ����ؼ� +2 */
		board[i][maxX]='\0';  /* �Բ� �������� �� �� ���� ���๮�� ���� */
		puts(board[i]);  /* �о���� �迭 ��� */
	}
	return TRUE;  /* board �ʱ�ȭ ���� */
}
/*--------------------------------------------------------------------------------------
Function name 	: boggleGame() - board�� ���޵� ���ڿ��� �ִ°� �˻��ϴ� �Լ�
Parameters		: searchWord - �˻��� �ܾ�ڿ��� �����ּ�
Returns			: board�� ã�� ���ڿ��� ������ TRUE ����, ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL boggleGame(const char *searchWord)
{
	int i,j;  /* iterator */
	int res;  /* �ܾ� �˻� �������� ���� */
	for(i=0; i<maxY; ++i){
		for(j=0; j<maxX; ++j){
			res = hasWord(i, j, searchWord); /* �迭 ��ü�� �� ���� �ܾ� �˻� ���������� �����Ͽ� �ݺ� ȣ�� �� */
			if(res == TRUE)  /* �ܾ ã������ �ٷ� TRUE ���� */
				return TRUE;
		}
	}
	return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name 	: inRange() - ���޵� y, x ��ǥ�� ��ȿ�� �˻� �Լ�
Parameters		: y - ��ȿ�� �˻��� y ��ǥ
             	  x - ��ȿ�� �˻��� y ��ǥ
Returns			: y,x ��ǥ�� ��� ��ȿ�ϸ� TRUE ����, �� ��ǥ�� ��ȿ���� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL inRange(int y,int x)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name 	: hasWord() - ���޵� y, x ��ǥ�� ã�� ���ڰ� �����ϴ°� �˻��ϴ� ����Լ�
Parameters		: y - �˻��� y ��ǥ
             	  x - �˻��� x ��ǥ
			 	  word - �˻��� ���ڿ��� �����ּ�
Returns			: �ش���ǥ�� ã�� ���� ������ TRUE ����, ��ǥ�� ��ȿ���� �ʰų� ã�� ���� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL hasWord(int y, int x, const char * word)
{
	// TODO
	return 0;  // ���ϰ��� �����ϼ���.
}

#include <stdio.h>
#define MAX_CONTROL 40	/* �µ��� 0~40�� �̹Ƿ� �ִ� ����Ƚ���� 40�� �ʰ����� ���� */
int currentTemperature; /* ����µ� */
int settingTemperature; /* �����µ� */
int minControl; /* �ּ� ������ ���� Ƚ�� */

void solve(int temp, int cnt);
/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main()
{
	while (1) {
		minControl = MAX_CONTROL;
		printf("# ����µ� �����µ� �Է�(�����Է� �� ����) : ");
		if (scanf("%d %d", &currentTemperature, &settingTemperature) != 2)
			break;
		solve(currentTemperature, 0);
		printf("������ �ּ� ���� Ƚ�� : %dȸ\n", minControl);
	}
	getchar(); 	getchar(); getchar();

	return 0;
}
/*---------------------------------------------------------------------
 Function name 	: solve() - �µ� ������ ���� �������� ���� �ؾ� �� Ƚ�� ���
 Parameters		: temperature - ���� �µ�
 	 	 	 	  cnt - ��������� ������ ���� Ƚ��
 Returns		: ����
 --------------------------------------------------------------------*/
void solve(int temperature, int cnt)
{
	// TODO
	return;
}

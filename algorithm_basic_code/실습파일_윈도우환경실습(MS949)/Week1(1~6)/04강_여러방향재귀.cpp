#include<stdio.h>

int cnt;
void f(int n);

int main()
{
	int  num = 10 ;
	f(num);
	printf("%d\n" , cnt) ;
	getchar();
	return 0;
}
void f(int n)
{
	if(n<=1)
		cnt++;	/* n<=1 �̸� cnt 1���� */
	else
	{
		f(n/2);	/* n�� 2�� ���� ������ ���ȣ�� */
		f(n/2);	/* n�� 2�� ���� ������ ���ȣ�� */
		f(n/2); // Quiz cnt ??
	}

	//!!!!!!!!!!!!!!! important return
    return;
}

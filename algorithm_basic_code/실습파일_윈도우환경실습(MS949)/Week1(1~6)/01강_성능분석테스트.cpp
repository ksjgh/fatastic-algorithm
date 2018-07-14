#include <stdio.h>
#include <time.h>
void getSum1(int n);
void getSum2(int n);

int main(){
	int n;			/* ������ �� ���� */
	int startTime, endTime;
	printf("# ������ �������� ������ �Է��Ͻÿ�(100000000(1��)~1000000000(10��)) : ");
	scanf("%d", &n);		/* ������ �� �Է� */
	startTime = clock();
	getSum1(n);
	endTime = clock();
	printf("getSum1()�Լ� �˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime-startTime));

	startTime = clock();
	getSum2(n);
	endTime = clock();
	printf("getSum2()�Լ� �˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime-startTime));

	getchar();  getchar();
	return 0;
}
void getSum1(int n){
	long long res=0;
	for(int i=1; i<=n; i++)
		res += i;
	printf("1~%d������ �� : %lld\n", n, res);
	return;
}
void getSum2(int n){
	printf("1~%d������ �� : %lld\n", n, (long long)n*(n+1)/2 );
	return;
}

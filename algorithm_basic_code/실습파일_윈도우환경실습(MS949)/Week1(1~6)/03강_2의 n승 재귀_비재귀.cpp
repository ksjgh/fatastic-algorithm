#include<stdio.h>
int iteratorPowerOf2(int power);
int recursivePowerOf2(int power);
int  main()
{
	int power = 10;
	printf("2�� %d���� �� =  %d\n" , power, iteratorPowerOf2(power) ) ;

	printf("2�� %d���� �� =  %d\n" , power, recursivePowerOf2(power) ) ;

	getchar();
	return 0;
}

int iteratorPowerOf2(int power)
{
	// TODO
	int res = 1;
	if(power == 0)
        return 1;
	else
    {
            for(int i = 1 ; i <= power ; i++ )
            {
                    res *= 2;
            }
    }

	return res;  // ���ϰ��� �����ϼ���.
}

int recursivePowerOf2(int power)
{
	// TODO
	if(power == 0) return 1;
	else return 2*recursivePowerOf2(power-1);
	//return 0;  // ���ϰ��� �����ϼ���.
}

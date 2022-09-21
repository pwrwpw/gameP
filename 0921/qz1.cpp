#include <stdio.h>
#include <math.h>
#include <windows.h>
int calc_frequency(int octave, int inx);
int main(void)
{
	int index[]={7,7,8,8,7,7,4,7,7,4,4,2,8,8,9,9,7,7,4,7,4,2,4,0};
	for(int i=0;i<=23;i++)
		Beep(calc_frequency(4,int(index[i])),500);
	return 0;
}


int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}


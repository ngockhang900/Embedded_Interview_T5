/*


*/
#include "C:\Users\dongo\Desktop\Embedded_Interview_T5\Ex_CheckDate\Header\CheckDate.h"

int nhuan(int nam)
{
	int hc;
	if(nam%400==0||(nam%4==0&&nam%100!=0))
		hc=1;
	else
		hc=0;
	return hc;
}


int hople(int ngay,int thang,int nam)
{
	int hc,ch,sntt;
	hc=nhuan(nam);
	switch(thang)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:sntt=31;break;
	case 4:case 6:case 9:case 11:sntt=30;break;
	case 2:sntt=(hc?29:28);break;
	}
	if(ngay<0||ngay>sntt||thang<0||thang>12||nam<0)
		ch=0;
	else
		ch=1;
	return ch;
}

int thu(int ngay,int thang,int nam)
{
	int t,t2,s;
	int ret = ngay;
	for(int i=1;i<thang;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			ret=ret+31;
		else
		{
			if(i==2)
			{
				t2=(nhuan(nam)?29:28);
				ret=ret+t2;
			}
			else
				ret=ret+30;
		}
	}
	s=nam-1+((nam-1)/4)-((nam-1)/100)+((nam-1)/400)+ret;
	t=s%7;
	return t;
}
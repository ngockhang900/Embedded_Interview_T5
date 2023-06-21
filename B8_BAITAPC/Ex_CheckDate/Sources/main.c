#include <stdio.h>
#include "C:\Users\dongo\Desktop\Embedded_Interview_T5\Ex_CheckDate\Header\CheckDate.h"


void main()
{
	int ngay = 7;
	int thang = 13;
	int nam = 2023;
	
	if(hople(ngay,thang,nam))
	{
		switch(thu(ngay,thang,nam))
		{
		case 0:printf("Chu nhat\n");break;
		case 1:printf("Thu hai\n");break;
		case 2:printf("Thu ba\n");break;
		case 3:printf("Thu tu\n");break;
		case 4:printf("Thu nam\n");break;
		case 5:printf("Thu sau\n");break;
		case 6:printf("Thu bay\n");break;
		}
	}
	else
		printf("ngay thang nam khong hop le\n");

}
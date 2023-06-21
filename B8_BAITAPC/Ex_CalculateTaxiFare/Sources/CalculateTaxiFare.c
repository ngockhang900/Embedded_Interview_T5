#include "C:\Users\dongo\Desktop\Embedded_Interview_T5\Ex_CalculateTaxiFare\Header\CalculateTaxiFare.h"

void Calculate(){
    float TotalKm;
    float Cost = 0;
    printf("\n Nhap vao so Km: ");
    scanf("%f", &TotalKm);
    if(TotalKm < 1)
    {
        Cost = TotalKm * 14;
    }
    else if(TotalKm <= 30 && TotalKm >= 1)
    {
        Cost = (TotalKm - 1)*10 + 1*14;
    }
    else
    {
        Cost = 1*14 + 29*10 + (TotalKm - 30)*8;
    }
    printf("\n So tien phai tra: %0.3f VND", Cost);
}
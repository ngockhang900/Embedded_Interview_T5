#include "stdio.h"
#include "stdint.h"

void tong(int a, int b){
    printf("Tong %d va %d = %d\n", a, b, a + b);
}

int tich(int a, int b){
    return a*b;
}

void hieu(int a, int b){
    printf("Tong %d va %d = %d\n", a, b, a - b);
}

void thuong(int a, int b){
    printf("Tong %d va %d = %.2f\n", a, b, (float)a/b);
}

void tinhToan(int a, int b, void( *phepTinh)(int, int)){
    printf("Chuong trinh toan:\n");
    phepTinh(a, b);
}

int main(int argc, char const *argv[])
{
    void(* ptr)(int, int) = NULL;
    ptr = &tong;
    ptr(9,7);
    int(* ptr_tich)(int, int) = &tich;
    printf("Tich a va b = %d\n", ptr_tich(5,6));

    tinhToan(5, 6, &thuong);

    int i = 10;
    char c = 'A';
    void *p; // con trỏ đặt biệt nó có thể trỏ đến mọi địa chỉ nhưng ko in ra giá trị được
    // để lấy giá trị được thì phải ép kiểu 
    p = &i;
    printf("i = %d\n", *(int *)p);
    p = &c;
    printf("c = %c\n", *(char *)p);
    p = &tong; 
    ((void(*)(int, int))p)(4,3);
 
    char *array = "hello";
    char *array2[] = {"hi","hello","world"}; // pointer to pointer 
    printf("test: %s\n", *(array2 +1));
    printf("test: %c\n", *(*(array2+1)+4));


    return 0;
}

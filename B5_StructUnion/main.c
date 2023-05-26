#include "stdio.h"
#include "stdint.h"
  
struct mang{
    uint8_t arr[7];   //1*7 = 7 +1
    uint64_t arr2[6]; //8*6 = 48
    uint16_t arr3[2]; //2*2 = 4 * (1*4)
    uint8_t arr4[4];  
};

typedef union{
    uint8_t a;   
    uint64_t b;
    uint16_t c;
}typeData;

void hienThi(typeData data){
    printf("a = %lu, b = %lu, c = %lu\n", data.c, data.b, data.c);
}

int main(int argc, char const *argv[])
{
    printf("size cua struct = %d byte\n",sizeof(struct mang));

    typeData data; // có thể khai báo typeData data = {10, 20, 35};
    data.a = 10;
    data.b = 20;
    data.c = 35;
    hienThi(data);
    printf("size cua uinon = %d byte\n",sizeof(typeData));
    return 0;
}

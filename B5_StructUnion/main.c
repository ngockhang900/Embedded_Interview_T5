#include "stdio.h"
#include "stdint.h"

    int a = 10;
    int b = 2;
    
struct mang{
    uint8_t arr[7];   //1*7 = 7 +1
    uint64_t arr2[6]; //8*6 = 48
    uint16_t arr3[2]; //2*2 = 4 * (1*4)
    uint8_t arr4[4];  
};

void epkieu(){
    float c = (float)a / (float)b;
    printf("c = %.2f", c);
}

int main(int argc, char const *argv[])
{
    
    printf("size = %d\n",sizeof(struct mang));
    epkieu();
    return 0;
}

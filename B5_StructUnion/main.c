#include "stdio.h"
#include "stdint.h"

struct mang{
    uint8_t arr[7];   //1*7 = 7 +1
    uint64_t arr2[6]; //8*6 = 48
    uint16_t arr3[2]; //2*2 = 4 * (1*4)
    uint8_t arr4[4];  
};

int main(int argc, char const *argv[])
{
    printf("size = %d",sizeof(struct mang));
    return 0;
}

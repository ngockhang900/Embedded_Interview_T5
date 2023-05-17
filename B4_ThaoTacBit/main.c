#include <stdio.h>
#include <stdint.h>


void readByte(uint8_t byte){            
    
    uint8_t temp = 0b10000000;          
    uint8_t kq;
    printf("0b");
    for (uint8_t i = 0; i < 8; i++)
    {
        kq = byte & temp;
        if(kq == 0){
            printf("0");
        }else{
            printf("1");
        }
        byte = byte << 1;
    }
}    


int main(int argc, char const *argv[])
{
    uint8_t test = 0b11001001;
    readByte(test);

    return 0;
}

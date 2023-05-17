#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"




int main(int argc, char const *argv[])
{
    uint8_t *ptr = (uint8_t *)malloc(sizeof (uint8_t) * 5);
    
    for (uint8_t i = 0; i < 5; i++)
    {
        ptr[i]=2*i;
    }
   
    for (uint8_t i = 0; i < 5; i++)
    {
        printf("ptr [%d]= %d\n",i, ptr[i]);
    }

    ptr = (uint8_t *)realloc(ptr, sizeof(uint8_t) * 3);
    
    

    return 0;
}

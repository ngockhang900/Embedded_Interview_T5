#include "stdio.h"
#include "stdint.h"


extern void dem();

void test(){
    static int a = 10;
    printf("a = %d\n", a);
    a++;
}

int main(int argc, char const *argv[])
{
    test();
    test();
    test();

    dem();
    return 0;
}

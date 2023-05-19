#include "stdio.h"
#include "stdint.h"

#define MAX 100

#define SUM(a,b) a+b 

#define CREATE(Ten_ham, noi_dung)    \
void Ten_ham(){                      \
    printf("%s\n", noi_dung);        \
}
// Ở trong Macro để viết chương trình có thể xuống dòng thì ta dùng dấu `\`.
CREATE(test,"Day la ham Macro");

int main(int argc, char const *argv[])
{
    printf("MAX = %d\n", MAX);

    printf("Tong a va b = %d\n", SUM(9,10));

    test();

    return 0;
} 
#include "stdio.h"
#include "stdint.h"

typedef enum{
    pin0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7,
}pins;

typedef enum{
    High,
    Low,
}s_status;

uint8_t porta = 0b00000000;
uint8_t portb = 0b11111111;

void pinHigh(pins pin){
    porta |=  (0b10000000 >> pin);
    uint8_t kq;
    printf("0b");
    for (uint8_t i = 0; i < 8; i++)
    {
        kq = porta & 0b10000000;
        if(kq == 0){
            printf("0");
        }else{
            printf("1");
        }
        porta = porta << 1;
    }
    printf("\n");
}

void pinLow(pins pin){
    portb &=  ~(0b10000000 >> pin);
    uint8_t kq;
    printf("0b");
    for (uint8_t i = 0; i < 8; i++)
    {
        kq = portb & 0b10000000;
        if(kq == 0){
            printf("0");
        }else{
            printf("1");
        }
        portb = portb << 1;
    }
    printf("\n");
}

// void readBit(uint8_t byte){
//     uint8_t kq;
//     printf("0b");
//     for (uint8_t i = 0; i < 8; i++)
//     {
//         kq = byte & 0b10000000;
//         if(kq == 0){
//             printf("0");
//         }else{
//             printf("1");
//         }
//         byte = byte << 1;
//     }
//     printf("\n");
// }

void digitalWrite(pins pin, s_status status){
    if(status == High){
        pinHigh(pin);
    }else{
        pinLow(pin);
    }
}


int main(int argc, char const *argv[])
{
    digitalWrite(pin6, High);
    digitalWrite(pin6, Low);

}

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

uint8_t porta = 0b00000000;
uint8_t portb = 0b11111111;

void pinHigh(pins pin){
    porta |=  (0b10000000 >> pin);
}

void pinLow(pins pin){
    portb &=  ~(10000000 >> pin);
}

void readBit(uint8_t byte){
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
    printf("\n");
    
}

int main(int argc, char const *argv[])
{
    pinHigh(pin3);
    readBit(porta);
    pinLow(pin3);
    readBit(portb);
    
}

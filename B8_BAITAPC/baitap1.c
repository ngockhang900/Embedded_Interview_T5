#include "stdio.h"
#include "stdint.h"


void sortList(uint8_t array[], uint8_t size){
    uint8_t temp;
    for (uint8_t i = 0; i < size -1; i++)
    {
        for (uint8_t j = i + 1; j < size; j++)
        {
            if(array[i] > array[j]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }       
    } 
    printf("\nMang da duoc sap xep tang dan: ");
    for(uint8_t i = 0; i < size; i++){
        printf("%5d", array[i]);
    }
}

int lanXuatHien(uint8_t array[],uint8_t size)
{
    uint8_t dem = 0;
    uint8_t chuan = array[0];

	for (int i = 0; i < size; i++){
		if (array[i]==chuan){
			dem++;
		}
		if (chuan!=array[i]){
			printf("\nSo %d xuat hien %d lan", array[i-1], dem);
			chuan = array[i];
			dem = 1;
		}
		if(i==size-1){
			printf("\nSo %d xuat hien %d lan", array[i], dem);

		}
	}
}

int main(){
    uint8_t array[] = {1,2,3,5,3,1,7,5,2,9};
    uint8_t size = sizeof(array)/sizeof(array[0]);
    sortList(array,size);
    lanXuatHien(array,size);
    
} 
    

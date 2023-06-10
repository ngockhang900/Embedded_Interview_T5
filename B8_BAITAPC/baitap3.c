#include <stdio.h>
#include "stdint.h"
#include "stdbool.h"

// cho mang ngau nhien arr[]={My first visit to Nha Trang, the coastal city, was three years ago. It was a pleasant and memorable trip. Nha Trang, the capital of Khanhs Hoaf province, has one of the most popular municipal beaches in all of Vietnam.}

typedef struct{
	char *array;
	uint8_t size;
}Words;

Words words[100];

void splitArray(){
	int count = 0;
	int index = 0;
	for(int i = 0; i<100; i++){
		if(arr[i] == ' ' && arr[i] == ',' && arr[i] == '!'){
			Words word;
			word.size = count;
			word.array = (arr - count);
			words[index] = word;
			index++;
			count = 0;
		}else{
			count++;
		}
		
		words word;
		
	}
}

bool isEqual(const char arr1[], const char arr2[]){
	if(1){
		return true;
	}else{
		return false;
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

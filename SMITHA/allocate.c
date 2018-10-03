#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"allocate.h"
#include"headers.h"
#include"global_variables.h"

void print();


void print(){
printf("You have entered the command to allocate memory.\n");
printf("Enter the number of 32-bit words you would like to allocate \n ");
}

void allocate(){

//int *p;

/*
extern uint32_t n_bits; //Number of 32 bits locations to be allocated
extern uint32_t st_index;
volatile extern uint32_t* st_addr;
uint32_t en_index; */

st_index = 1;
en_index = 0;


print();
scanf("%d",&n_bits); 

st_addr=(uint32_t*)malloc(n_bits * 4); //32 bit=4 bytes;

if (st_addr != NULL){	
	if (n_bits ){
		if (n_bits >=2){
			printf("'%d' 32-bits memory locations have been successfully allocated \n",n_bits);
			printf("The start-address of the allocated memory is %p, and location index is %d\n",st_addr,st_index ); //gives address range to the user//

			printf("The end-address of the allocated memory is %p, and location index is %d \n",st_addr +n_bits - 1, en_index + n_bits ); 

		//	return *st_addr;

//			printf("The end-address of the allocated memory is %p, and location index is %d 			\n",st_addr +n_bits -1 , en_index + n_bits ); 

			//return *st_addr;
				}

		else {
			printf("'%d' 32-bits memory locations have been successfully allocated\n",n_bits);
                	printf("The start-address of the allocated memory is %p, and location index is %d \n",st_addr, st_index);
		     }
		}  
	else printf("Please enter a number more than 0 \n");
	}
else printf("Null pointer returned, no memory allocated");
}



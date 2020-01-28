#include "simple_neural_networks.h"



double weight  = 0.5;
double input = 0.5;
double expected_value  = 0.8;
double step_amount = 0.001;


int main(void){

	 USART2_Init();
	
    brute_force_learning(input,weight,expected_value,step_amount,1500);

	 while(1){}
}
#ifndef __SIMPLE_NEURAL_NETWORK
#define __SIMPLE_NEURAL_NETWORK
#include "uart.h"

#include <stdint.h>

double single_in_single_out_nn(double input, double weight);

double multiple_inputs_single_output_nn(double * input, double *weight, uint32_t INPUT_LEN);

void single_input_multiple_output_nn(	double input_scalar,
																			double *weight_vector,
																			double *output_vector,
																			double VECTOR_LEN);
																			
void multiple_inputs_multiple_outputs_nn(double * input_vector,
																	uint32_t INPUT_LEN,
																	double * output_vector,
																	uint32_t OUTPUT_LEN,
																	double weights_matrix[OUTPUT_LEN][INPUT_LEN]);
	
																	
void hidden_nn( double *input_vector,
								uint32_t INPUT_LEN,
								uint32_t HIDDEN_LEN,
                double in_to_hid_weights[HIDDEN_LEN][INPUT_LEN],
								uint32_t OUTPUT_LEN,
								double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
								double *output_vector
							);
								
	double  find_error_smpl( double yhat, double y);
	double find_error_(double input, double weight, double expected_value);


void brute_force_learning( double input,
													 double weight,
													 double expected_value,
													 double step_amount,
													 uint32_t itr);								

#endif
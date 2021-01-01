#include "stdio.h"
//#include <ap_fixed.h>
#include "my_ap_fixed.h"


typedef my_ap_fixed<17,9> my_input_t;
typedef my_ap_fixed<32,13> my_pixel_t;


int main(){
	//frame1_tmp:000000a5, 0.644531
	//frame2_tmp:0000009e, 0.617188
	//frame3_tmp:000000b0, 0.687500
	//frame4_tmp:000000c8, 0.781250
	//frame5_tmp:000000cb, 0.792969
	//temp_y:0000012a, 1.164062
	//temp_z:0000c6aa, 0.097004


	const int GRAD_WEIGHTS[] =  {1,-8,0,8,-1};
	my_pixel_t temp_z = 0;
	my_input_t frame1_tmp = 0;
	my_input_t frame2_tmp = 0;
	my_input_t frame3_tmp = 0;
	my_input_t frame4_tmp = 0;
	my_input_t frame5_tmp = 0;

	frame1_tmp(16,0) = 0x000000a5;
	frame2_tmp(16,0) = 0x0000009e;
	frame3_tmp(16,0) = 0x000000b0;
	frame4_tmp(16,0) = 0x000000c8;
	frame5_tmp(16,0) = 0x000000cb;
	temp_z(31, 0) = 0x0000c6aa;




	temp_z =((my_pixel_t)(frame1_tmp*GRAD_WEIGHTS[0]
					 + frame2_tmp*GRAD_WEIGHTS[1]
					 + frame3_tmp*GRAD_WEIGHTS[2]
					 + frame4_tmp*GRAD_WEIGHTS[3]
					 + frame5_tmp*GRAD_WEIGHTS[4]))/12;
	printf("frame1_tmp:%08x, %f\n", (unsigned int) frame1_tmp(16,0), frame1_tmp.to_float());
	printf("frame2_tmp:%08x, %f\n", (unsigned int) frame2_tmp(16,0), frame2_tmp.to_float());
	printf("frame3_tmp:%08x, %f\n", (unsigned int) frame3_tmp(16,0), frame3_tmp.to_float());
	printf("frame4_tmp:%08x, %f\n", (unsigned int) frame4_tmp(16,0), frame4_tmp.to_float());
	printf("frame5_tmp:%08x, %f\n", (unsigned int) frame5_tmp(16,0), frame5_tmp.to_float());
	printf("temp_z:%08x, %f\n", (unsigned int) temp_z(31,0), temp_z.to_float());


	printf("Hello world\n");
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void init();


int main(int argc, char* argv[])
{
	int i,y,x,z;
	int A = 0;
	int W = 0;
	int P = 0;
	int autoscan;
	double R = 0;
	int T_FPGA;
        int T_GPU;

	init();
	
	printf("How many ALUS are on your GPU ? \n");
	scanf("%d", &A);
	if(A <=0)
	{
		printf("Number must be larger than 0 \n");
	}


	printf("How many Threads/Work-Items do you want to start ? \n");
	scanf("%d", &W);
	if(W <=0)
	{
		printf("Number must be larger than 0 \n");
	}

	printf("How many Operations will be in your Kernel ? \n");
	scanf("%d", &P);
	if(P <= 0)
	{
		printf("Number must be larger than 0 \n");
	}

	R = (double)W/(double)A;
	T_FPGA = W + P;
	T_GPU = P*R;

	if(R > 1)
		printf("The GPU needs to reload %f times \n The Clock Cycles  for The FPGA are %d \n The Clock Cycles for the GPU are %d \n", R, T_FPGA, T_GPU);
	else
	{
		printf("The GPU does not need to reload. \n The Clock Cycles  for The FPGA are %d \n The Clock Cycles for the GPU are %d \n", T_FPGA, T_GPU);
	}
	
	if(T_FPGA < T_GPU)
	{
		printf("\e[1;31mThe FPGA has less clock cycles\e[0m");
		if(4*T_FPGA < T_GPU)
		{
			printf("\e[1;31m andd could beat the GPU even if he has a much slower clock rate\n\e[0m");
		}
		else
		{
			printf("\e[1;33m but will may not win against the GPU due to a much slower clock rate.\n\e[0m");
		}
	}
	else
	{
		printf("\e[1;33mThe GPU has lecc clock cycles.\n\e[0m");
	}
	

}

void init()
{

	printf("\t\t\t\t\t\t\t This algorithm is hold very simple \n" "\t\t\t\tIt compares if the FPGA with the ALTERA SDK for OpenCL is faster than your GPU with OpenCL \n");
	printf("\e\t\t\t\t[1;31mCaution! The FPGA will be faster if you use vhdl code instead of the ALTERA SDK for OpenCL and take care of the design yourself.\n\e[0m");
}

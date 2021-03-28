#include "stdio.h"
#include<gsl/gsl_matrix.h>

//This function prints half of the [0,0] element of a given_gsl matrix
int print_half_00(gsl_matrix* m){
	double half = (double)1/2;
	int status = printf( "half m_{00} = %f\n", gsl_matrix_get(m,0,0)*half );
	return status;
}

int main(void)
{
	gsl_matrix* m = gsl_matrix_alloc(1,1);
	gsl_matrix_set(m,0,0,66);
	printf("half m_{00} (should be 33):\n");
	int status = print_half_00(m);
	if(status==0){
    printf("status=%d : SOMETHING WENT TERRIBLY WRONG (status=0)\n",status);}
	else{
    printf("status=%d : everything went just fine (status>0)\n",status);}
	gsl_matrix_free(m);
return 0;
}

#include <gsl/gsl_integration.h>

double f (double x, void * params);

double myQAGS(){
	gsl_function F;
	F.function=&f;
	//F.params=(void*)&z;
	int limit=999;
	gsl_integration_workspace* w;
	w = gsl_integration_workspace_alloc (limit);
	double a=0, b=1, epsabs = 1e-6, epsrel = 1e-6, result, error; 
	gsl_integration_qags(&F,a,b,epsabs,epsrel,limit,w,&result,&error);
	gsl_integration_workspace_free(w);
	return result;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "runge.h"
#include "funciones.h"

int main(){

  float h = 0.01;
  int n_pasos = ((3.0 + h)/h);
  float* x;
  float* y;
  float* z;
  float* t;
  flaot s = 10.0;
  float b = 8.0/3.0;
  float r = 28.0;
	
	
 
  t = malloc(n_pasos*sizeof(float));
  x = malloc(n_pasos*sizeof(float));
  y = malloc(n_pasos*sizeof(float));
  z = malloc(n_pasos*sizeof(float));


  if(!t || !x || !y || !z){
    printf("Problema con memoria");
    exit(1);
  }


int i;
srand48 (getpid());

for (i = 0; i < 10; i ++){

	float cond1 = drand48()*20.0 - 10.0;
        float cond2 = drand48()*20.0 - 10.0;
        float cond3 = drand48()*20.0 - 10.0;
        void rungeKuttaCuartoOrden(float *x, float *y, float *z, float h, int n_pasos, float condX, float condY, float condZ, float b, float r, float s);        

	char num[2];
	sprintf(num, "%d", i);
	FILE *export;
	export = fopen(strcat(num,".dat"), "w");

	fprintf(export,"%f %f %f %f \n", t[i],x[i],y[i],z[i]);

	
}

return 0;

}


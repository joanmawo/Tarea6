#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include "runge.h" 
#include "funciones.h"

int main(){
 
  float h = 0.01;
  int n_pasos = ((30.0 + h)/h);
  float* x;
  float* y;
  float* z;
  float* t;
  float s = 10.0;
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

    float condX = drand48()*20.0 - 10.0;
    float condY = drand48()*20.0 - 10.0;
    float condZ = drand48()*20.0 - 10.0;
    rungeKuttaCuartoOrden(x, y, z, t, h, n_pasos, condX, condY, condZ, b, r, s);        
    
    char num[30];
    sprintf(num, "%d.dat", i);
    FILE *export; 
    export = fopen(num, "w");
    if(!export){
      printf("problem with file %s\n", num);
      exit(1);
    }
    
    int j;
    for(j = 0; j < n_pasos; j ++){
      
      fprintf(export,"%f %f %f %f \n", t[j],x[j],y[j],z[j]);      
    }
      fclose(export);

}

return 0;

}

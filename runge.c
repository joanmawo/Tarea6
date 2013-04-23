#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "funciones.h"


void rungeKuttaCuartoOrden(float *x, float *y, float *z, float *t, float h, int n_pasos, float condX, float condY, float condZ, float b, float r, float s){
  
//Condiciones iniciales
 x[0] = condX;
 y[0] = condY;
 z[0] = condZ;
 t[0] = 0.0;

  int i;
  float k1_x, k1_y, k1_z;
  float k2_x, k2_y, k2_z;
  float k3_x, k3_y, k3_z;
  float k4_x, k4_y, k4_z;
  float promedio_k_x, promedio_k_y, promedio_k_z;
  float x1, t1;
  float x2, t2;
  float x3, t3;
  float y1, z1;
  float y2, z2;
  float y3, z3;

  for(i = 1; i < n_pasos; i ++){

  k1_x = f_prima_1(x[i-1], y[i-1], z[i-1], b, r, s);
  k1_y = f_prima_2(x[i-1], y[i-1], z[i-1], b, r, s);
  k1_z = f_prima_3(x[i-1], y[i-1], z[i-1], b, r, s);

  //Primer paso
 
  t1 = t[i-1] + (h/2.0);   
  x1 = x[i-1] + (h/2.0)*k1_x;
  y1 = y[i-1] + (h/2.0)*k1_y;
  z1 = z[i-1] + (h/2.0)*k1_z;

  k2_x = f_prima_1(x1, y1, z1, b, r, s);
  k2_y = f_prima_2(x1, y1, z1, b, r, s);
  k2_z = f_prima_3(x1, y1, z1, b, r, s);

  //Segundo paso

  t2 = t[i-1] + (h/2.0);
  x2 = x[i-1] + (h/2.0)*k2_x;
  y2 = y[i-1] + (h/2.0)*k2_y;
  z2 = z[i-1] + (h/2.0)*k2_z;

  k3_x = f_prima_1(x2, y2, z2, b, r, s);
  k3_y = f_prima_2(x2, y2, z2, b, r, s);
  k3_z = f_prima_3(x2, y2, z2, b, r, s);

  //Tercer paso

  t3 = t[i-1] + (h/2.0);
  x3 = x[i-1] + (h/2.0)*k3_x;
  y3 = y[i-1] + (h/2.0)*k3_y;
  z3 = z[i-1] + (h/2.0)*k3_z;

  k4_x = f_prima_1(x3, y3, z3, b, r, s);
  k4_y = f_prima_2(x3, y3, z3, b, r, s);
  k4_z = f_prima_3(x3, y3, z3, b, r, s);
 
  //Cuarto paso

  promedio_k_x = (1.0/6.0)*(k1_x + 2.0*k2_x + 2.0*k3_x + k4_x);
  promedio_k_y = (1.0/6.0)*(k1_y + 2.0*k2_y + 2.0*k3_y + k4_y);
  promedio_k_z = (1.0/6.0)*(k1_z + 2.0*k2_z + 2.0*k3_z + k4_z);

  t[i] = t[i-1] + h;   
  x[i] = x[i-1] + h*promedio_k_x;
  y[i] = y[i-1] + h*promedio_k_y;
  z[i] = z[i-1] + h*promedio_k_z;
 
}
}

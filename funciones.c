float f_prima_1(float x, float y, float z, float b, float r, float s){
     return s*(y - x);
}

float f_prima_2(float x, float y, float z, float b, float r, float s){
     return x*(r - z) - y;
}

float f_prima_3(float x, float y, float z, float b, float r, float s){
     return x*y - b*z;
}

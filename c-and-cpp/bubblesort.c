//#include "stdafx.h"
//bubble sort algortithm, unoptimised

#include "stdio.h"



void main()
{
  float X[100] = {};
  float aux = 0;
  int n = 0;

  printf_s("Input n: \n");
  scanf_s("%d", &n);

  for (int i = 0; i < n; i++) {
    printf_s("Input X[%d] = ", i);
    scanf_s("%f", &X[i]);
  }


  for (int i = 0; i < n - 1; i++) {        //we do n-1 passes
    for (int j = 0; j < n - i - 1; j++) {  //n-i-1 has to be set so that 2nd for doesn't enter the "sorted" part of array
      if (X[j] > X[j + 1]) {               //each pass has to compare every two adjacent elements
        aux = X[j + 1];                    //swap them if one at a lower index is > than its pair
        X[j + 1] = X[j];
        X[j] = aux;
      }
    }
  }


  printf_s("Array X = ");
  for (int i = 0; i < n; i++) {
    printf_s(" %.2f ;", X[i]);
  }
}


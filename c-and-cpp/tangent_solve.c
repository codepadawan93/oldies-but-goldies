/*
	finds root of an arbitrary equation using information about its derivative 
	(the tangent method)
*/
#include <stdio.h>
#include <cmath>
#include <conio.h>

float ffunc(float x) {
	//return (2*(x*x*x)) + x*x + 2; //function is 2x^3 + x^2 + 2
	return (x*x*x) - (x*x);
} 

float ffuncder(float x) {
	//return 6*(x*x) + 2*x;	//first derivative of ffunc, 6x^2 + 2x
	return x;
}

float gfuncder(float x) {
	//return ((2 * (x*x*x)) + x*x + 2)/(6 * (x*x) + 2 * x); //this is ffunc/ffunc'
	return ((x*x*x) - (x*x)) / (x); 
}

/*
n = no of iterations, eps = precision for solution
x0 = initial value, eps2 = precision for determining convergence of sequence
f = initial function, fp = f', g = (x - f(x)/f'(x))',
code = a flag to determine nature of stop condition
*/
float tangentSolve(int n, float eps,
	float x0, float eps2,				
	float(*f)(float),
	float(*fp)(float),
	float(*gp)(float),
	int *code) {

	float approx = 0;
	(*code) = 0;
	while ((n > 0) && (*code == 0)) {		//n == 0 stop
		if (abs(fp(x0)) < eps2) {		//|f'(x0)| ~= 0 ie it is in range(-eps2, eps2) stop
			(*code) = 1;
		}
		else {
			if (abs(gp(x0)) >= 1) {		//|g'(x0)| >= 1 ie sequence of candidate solutions is divergent stop
				(*code) = 2;
			} else {
				approx = x0 - (f(x0) / fp(x0));
				if (abs(approx - x0) < eps) {	//dist(x1-x0) < eps stop and we have sol
					(*code) = 3;
				} else {
					x0 = approx;
					n--;
				}
			}
		}
	}

	return approx;
}

int main()
{
	int c;
	float sol = tangentSolve(1000, 0.1, 1.2, 0.01, ffunc, ffuncder, gfuncder, &c);

	printf("S = { %.2f };", sol);
	//(c != 3) ? printf("Exited with code %d", c) : printf("S = { %.2f };", sol);;
	printf("%d", c);
	switch (c){
	
	case 0: printf("\nOut of iterations;");
		break;
	case 1: printf("\nThe derivative of the function in the point x is arbitrarily close to zero;");
		break;
	case 2: printf("\nSequence of candidate solutions is divergent;");
		break;break;
	case 3: printf("\nCandidate solution is within tolerance;");
		break;
	default: printf("");
		break;
	}
	getch();
	return 0;
}


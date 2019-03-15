/*
	finds root of an arbitrary equation given two points on the x-axis
	(via the bisection method)
*/
#include <cstdio>
#include <cmath>

/* this is the objective function */
double f(double x) {
	//return x*x*x - x*x; //pass 2 and 4 as l&r to get answer
	return cos(x); // note that u can only find one root at a time
}


/*
inputs: n = no of iterations; eps = max. tolerance; l = left endpoint of feasible segment;
r = right endpoint; func = objective function; code = info about solution
*/
double bisectionSolve(int n, double eps, 
					  double l, double r, 
					  double (*func)(double),
					  int *code) {
	double mid;
	*code = 0;
	while (n > 0 && *code == 0) {
		mid = ((l + r) / 2);
		if (func(mid) == 0) {
			*code = 1; //we have exact sol
		}
		else if ((r - l) < eps) {
			*code = 2; //result is within tolerance and we have approx sol
		}
		else if (func(l)*func(mid) < 0) {  //one of f(l) or f(mid) is negative
			r = mid;  
		}
		else {
			l = mid;
		}
		n--;
	}
	return mid;
}

int main() {
	int c;
	double sol = bisectionSolve(1000, 0.1, 4, 5, f, &c);
	switch (c) {
	case 0:
		printf("No solution; \n");
		break;
	case 1:
		printf("We have exact solution:\n");
		break;
	case 2:
		printf("We have approximate solution:\n");
		break;
	}
	printf("S = { %f };\n", sol);
	return 0;
}
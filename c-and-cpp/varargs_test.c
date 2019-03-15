//pass as many arguments to maxof as you wish, it will return max integer
#include <stdarg.h> //needed for va_start etc
#include <stdio.h>

int maxof(int n_args, ...) {
	int i, max, a;
	va_list ap;  //needed for variable no of args

	va_start(ap, n_args);
	max = va_arg(ap, int);
	for (i = 2; i <= n_args; i++) {
		if ((a = va_arg(ap, int)) > max)
			max = a;
	}

	va_end(ap);
	return max;
}

int main() {
	int ans = maxof(2, 10, 21, 9, -2);
	printf("%d\n", ans);
	return 0;
}
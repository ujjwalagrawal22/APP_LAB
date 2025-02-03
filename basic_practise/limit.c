#include <stdio.h>

int main() {
    double large = 1e10;
    double small = 1e-10;

    printf("large in fixed-point: %f\n", large);      // Fixed-point: 10000000000.000000
    printf("large in scientific: %e\n", large);       // Scientific: 1.000000e+10
    printf("large in automatic choose: %g\n", large); 

    printf("small in fixed-point: %f\n", small);      // Fixed-point: 0.000000
    printf("small in scientific: %e\n", small);       // Scientific: 1.000000e-10
    printf("small in automatic choose: %g\n", small); 

    return 0;
}

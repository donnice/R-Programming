# include <R.h>
# include <math.h>
# include <Rinternals.h>
# include <Rmath.h>

void fooC(double* a, double* b, int* n, double* res) {
    int i, j;
    for (i = 0; i < (*n); i++) {
        res[i] = 0;
        for(j = 0; j < (*n); j++) {
            res[i] += pow(a[j] + i + 1, b[j]);
        }
    }
}

// SEXP represents a R object
// REAL macro returns a pointer to corresponding memory
SEXP fooC2(SEXP aR, SEXP bR)
{
    int i, j, n = length(aR);
    double *a = REAL(aR), *b = REAL(bR);
    SEXP Rval = allocVector(REALSXP, n);
    for(i = 0; i < n; i++) {
        REAL(Rval)[i] = 0;
        for(j = 0; j < n; j++) {
            REAL(Rval)[i] += pow(a[j] + i + 1, b[j]);
        }
    }
    return Rval;
}


#include <math.h>
#include <stdio.h>
//#include "gsl_headers.h"
#include <iostream>
//#include "laplaceEP.h"
//#include "matrix.h"
#include <time.h>



//#include <dai/alldai.h>
//#include <dai/bp.h>
// #include <map>
// #include <boost/shared_ptr.hpp>
// #include <string>
// 
#include <gsl/gsl_sf_exp.h>
#include <gsl/gsl_sf_log.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_math.h>
#include "gsl/gsl_cdf.h"
#include "gsl/gsl_randist.h"


//Transformations
double f_1(double x, double w);
double f(double x, double w);


// General functions
int factorial (int N);
int poissrnd(double lambda);
//gsl_matrix *double2gsl(double *Amat, int nRows, int nCols);
void matrix_multiply(gsl_matrix *A,gsl_matrix *B,gsl_matrix *C,double alpha,double beta,CBLAS_TRANSPOSE_t TransA,CBLAS_TRANSPOSE_t TransB);
double *column_to_row_major_order(double *A,int nRows,int nCols);
//double *row_to_column_major_order(double *A,int nRows,int nCols);
double det_get(gsl_matrix *Amat, int Arows, int Acols, int inPlace);
double lndet_get(gsl_matrix *Amat, int Arows, int Acols, int inPlace);
// gsl_matrix *inverse(gsl_matrix *Amat, int Asize);
void inverse(gsl_matrix *Amat, int Asize);
double trace(gsl_matrix *Amat, int Asize);
double logFun(double x);
double expFun(double x);
//Sampling functions
int mnrnd(double *p, int nK);
void mvnrnd(gsl_matrix *X, gsl_matrix *Sigma,gsl_matrix *Mu, int K, const gsl_rng *seed);
double truncnormrnd(double mu, double sigma, double xlo, double xhi);


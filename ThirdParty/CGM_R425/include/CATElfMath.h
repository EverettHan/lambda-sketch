#ifndef CATELFMathKernel_H
#define CATELFMathKernel_H

#include "CATELFMathKernel.h"

extern "C" ExportedByCATELFMathKernel
 void getblas(int* Blas,int* SparseBlas,int* Lapack);

extern "C" ExportedByCATELFMathKernel
void getversionmkl(char buf[]);

extern "C" ExportedByCATELFMathKernel
void eagemv (char* Trans, int* M, int* N, double* alpha, double* A, int* lda,
             double* x, int* incx, double* beta, double* y, int* incy);

extern "C" ExportedByCATELFMathKernel
int easlff_nt (int *lfront, int *ncol, double* a, double* pivmin, double* rpivot,
               double* apiv, double* rpiv, int* im, int* inrtia, float* fctops,
               float* slvops, int* ierr);

extern "C" ExportedByCATELFMathKernel
 void e_dzero(int* neqns, double* adiag, int* un);

extern "C" ExportedByCATELFMathKernel
 void e_izero(int* neqns, int* adiag, int* un);

extern "C" ExportedByCATELFMathKernel
 int e_idamax(int* N, double* dx, int* incx);

extern "C" ExportedByCATELFMathKernel
 int eaxfch(int* mt, int* ni, int* ns, double* prec,double* an,int* ipiv,double* dpiv);

extern "C" ExportedByCATELFMathKernel
 int eaxfch2(int* mt, int* ni, int* ns, double* prec,double* an,int* ipiv,double* dpiv);

extern "C" ExportedByCATELFMathKernel
 int eaxfch3(int* mt, int* ni, int* ns, double* prec,double* an,int* ipiv,double* dpiv);

extern "C" ExportedByCATELFMathKernel
 int Cholesky(int* mt, int* ni, int* ns, double* prec,double* an,int* ipiv,double* dpiv);

extern "C" ExportedByCATELFMathKernel
 void ehaldb(int *Mkl);

extern "C" ExportedByCATELFMathKernel
 void eagemm (char* TransA, char* TransB, int* M, int* N, int* K, double* Alpha, double* A,
              int* Lda, double* B, int* Ldb, double* BETA, double* C, int* Ldc);

extern "C" ExportedByCATELFMathKernel
 void e_dsctr(int* neqns, double* Depl, int* Invp, double* tempo);

extern "C" ExportedByCATELFMathKernel
 void eaxmvm (int *iopt_,int *nta_,int *n_,int *ntv_,int *nv_,int *ica_,int *mpa_,double *a_,
              double *x_,double *y_);

extern "C" ExportedByCATELFMathKernel
 void eaxeig (int *n_,int *iopt_,double *amat_,double *valp_,double *vecp_,double *aux_,int *ier_);

extern "C" ExportedByCATELFMathKernel
 int eaxrmc3 ( int * npol, int * nnodes, double * coords, double * coord,
               double * values, double * value, void * ebxxxf, double * a, double * a0,
               double * a1, double * c, double * f, double * coefs, double * wgt, int * ier );


extern "C" ExportedByCATELFMathKernel
void eaxsort (int* ix, int* ni, int* nn, int* nu, int* it );

extern "C" ExportedByCATELFMathKernel
void mmd(int neqns, int *xadj, int *adjncy, int *invp, int *perm,
         int delta, int *head, int *qsize, int *liste, int *marker,
         int maxint, int *ncsub);

extern "C" ExportedByCATELFMathKernel
 void eaunln (int *ntnod_,int *ntele_,int *ntnle_,int *mpnle_,int *nle_,int *mpeln_,int *neln_,int *nolie_,int *nln_,int *ntnln_);

extern "C" ExportedByCATELFMathKernel
 void eaupnn (int *ntnod_,int *ntele_,int *ntnle_,int *mpnle_,int *nle_,int *mpeln_,int *neln_,int *nolie_,int *mpnln_,int *ntnln_);

extern "C" ExportedByCATELFMathKernel
 void eaupne (int *ntdeg_,int *ntdegn_,int *ntnod_,int *ntnoel_,int *nnedeg_,int *mpnoel_);  

extern "C" ExportedByCATELFMathKernel
void eaxraz (int* ityp, char* Tab, int* Long );

extern "C" ExportedByCATELFMathKernel
void eaxcpy (int& ityp, int& Long, void* Tab1, void* Tab2 );

extern "C" ExportedByCATELFMathKernel
void eaxrnd (int* init, double* value );

extern "C" ExportedByCATELFMathKernel
 void eaunle (int *ntnod_,int *ntele_,int *ntnle_,int *mpnle_,int *nle_,int *mpeln_,int *neln_);

extern "C" ExportedByCATELFMathKernel
 int e_dpptrs (char *Uplo, int *N, int *Nrhs, double *AP, double *B, int *Ldb, int *Info);

extern "C" ExportedByCATELFMathKernel
 int dpptrs_2 (char *Uplo, int *N, int *Nrhs, double *AP, double *B, int *Ldb, int *Info);

extern "C" ExportedByCATELFMathKernel
 int IsPentium4();

extern "C" ExportedByCATELFMathKernel
 void GetMaxSlaveMemory(int &MaxMem);

extern "C" ExportedByCATELFMathKernel
 void eacort (int *NT, int *N, double *A, double *X);
#endif

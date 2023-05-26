#ifndef CATELFSkyLineFor_h
#define CATELFSkyLineFor_h

#include "CATElfMemoryManager.h"
#include "CATELFOptimization.h"    

extern "C" ExportedByCATELFOptimization
 void eafapsk (int *mode_,int *ntdeg_,int *ntck_,int *mpk_,int *jck_,double *ak_,int *ntckf_,int *mpkf_,double *akf_);  

extern "C" ExportedByCATELFOptimization
 void eafask (int *n_,double *a_,double *d_,int *na_,int *idiag_,int *iparm_,double *dparm_,double *aux_,int *naux_,double *bx_,int *ldbx_,int *mbx_, int* ier);  

extern "C" ExportedByCATELFOptimization
 void eagadsk (int *ntdeg_,int *ntckf_,int *mpkf_,double *akf_,double *dkf_,int *nchar_,double *depl_);  

extern "C" ExportedByCATELFOptimization
 void eagarsk (int *ntdeg_,int *ntckf_,int *mpkf_,double *akf_,int *nchar_,double *depl_);  

#endif


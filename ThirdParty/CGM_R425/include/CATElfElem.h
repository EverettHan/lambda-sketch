#ifndef CATElfElem_H
#define CATElfElem_H

#include "CATElfElemShared.h"
#include "CATDataType.h"

extern "C" ExportedByCATElfElemShared
void eaxtmx (int *Ntba, int *Nta, int *Ntcr, int *n, int *Ntv, int *Nv,
             int *Mpba, int *Jca, int *Mpa, double *A, double *X, double *Lx, double *Matr, int *ier);

extern "C" ExportedByCATElfElemShared
 void ebkiwi (int *nelloc_,int *nno_,int *free_,double *cooloc_,double *w_,double *wr_,double *rigid_,double * rigidw_,double *relat_,double *relatf_,CATINTPTR *sng_,int *ntcin_,int *nkloc_,double *ckloc_,int *ier_);

extern "C" ExportedByCATElfElemShared
 int ebcstd (int* Nno, double* Coords, double* Coefs);

extern "C" ExportedByCATElfElemShared
void ebimrf (int *nelloc_,int *ndj_,int *nfi_,double *cooloc_,double *vfi_,double *vpi_);

extern "C"  ExportedByCATElfElemShared
int ebba2 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebba3 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebtr3 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebqu4 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebtr6 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebqu8 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebqu9 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebte4 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebhe8 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebte10 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebwe15 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebwe6  (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebhe20 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebpy5 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int ebpy13 (int* Opt,int *Ifa,int *Nfi,int *Ndj,int *Ipi,
           double *Xpn,double *Wpn,double *Xnode,int *Ier);

extern "C"  ExportedByCATElfElemShared
int  ebicno(int *Opt,int *Ndj,int *Nno,double *Cooloc,double *VFI,double *V);

extern "C"  ExportedByCATElfElemShared
void ebux (int *Opt,int *Nno,double *Cooloc,double *FI, double *CDGC);

#endif

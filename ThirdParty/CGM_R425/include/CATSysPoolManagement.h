#ifndef CATSysPoolManagement_H
#define CATSysPoolManagement_H
#include "CATSysAllocator.h"
//======================================================
// Copyright DASSAULT SYSTEMES 2001
//======================================================

#include <stdio.h>
struct CATPoolInfo 
{
     unsigned int        m_Flags ;
     size_t              m_Size ;
     size_t              m_Free ;
     union 
     {
     unsigned int        m_NbSupPools ;//for non paged pool
     unsigned int        m_PoolIsEmpty;//paged pools:true if pool is empty
     };
     union 
     {
       size_t              m_MaxFreeSizeInAPool;//for non paged pools
       size_t              m_UsefulSize;//for paged pools
     };
     size_t              m_MinFreeSizeInAPool;//useless for paged pools
     unsigned int        m_MinPctOccInASubPool;//useless for paged pools
     unsigned int        m_MaxPctOccInASubPool;//useless for paged pools
     unsigned int        m_PctOccupation;
     size_t              m_NbHoles    ;//useless for paged pools
     size_t              m_NbBlocks   ;
     size_t              m_HoleMaxKnownSize;//useless for paged pools
     size_t              m_HoleMaxSizeIsUnknown;//useless for paged pools
};


#define CATSysGPInfo_DumpSubPools    0x1
#define CATSysGPInfo_DumpShortFormat 0x2
#define CATSysGPInfo_ForceNodesCntrl 0x4
ExportedByCATSysAllocator void CATSysGetPoolInfo(void *iPool, FILE *iBuffer=NULL, CATPoolInfo *oInfoBuf=NULL, int iFlags =0);

// returns -1 if pools are active
// returns 0 if pools are inactivated 
ExportedByCATSysAllocator int CATSysGetPoolActivityStatus();
#endif

/**
 * @level Protected
 * @usage U1
 */
 /* CATIAModel2DInfo.h : COPYRIGHT DASSAULT SYSTEMES 2001 */
#ifndef  CATIAModel2DInfo_h
#define  CATIAModel2DInfo_h

#include "ExportedByCATIAEntity.h"

class CATIAModel;

     /*---------------------------------------------------*/
     /*  Service de parcours sur des donnees 2D           */
     /*---------------------------------------------------*/
ExportedByCATIAEntity int getmdl2DInfo(CATIAModel *const &mnum, 
				       int &icusht,
				       int &icuv2d,
				       int &icurep,
				       int &ier);

ExportedByCATIAEntity int getmdl2dinfo(CATIAModel *const &mnum, 
				       int &icusht,
				       int &icuv2d,
				       int &icurep,
				       int &ier);

#endif   /* CATIAModel2dInfo_h */

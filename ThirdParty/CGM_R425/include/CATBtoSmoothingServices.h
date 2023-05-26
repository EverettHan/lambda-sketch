/**
* @quickReview ANR 19:10:07
*/

/**
* @fullreview ANR anr 19:10:07
*/
// --------------------------------------------------------
//====================================================================
// Copyright Dassault Systemes Provence 2019, all rights reserved 
//==================================================================== 
//
//======================================================================   
// Sept,      07 th 2019 : ANR : Creation   
//======================================================================

#ifndef CATBtoSmoothingServices_H
#define CATBtoSmoothingServices_H

#include "CATBtoSmoothing.h"
#include "CATSoftwareConfiguration.h"
 
#include "CATBoolean.h"  

class CATGeoFactory ;
class CATTolerance ; 
class CATCldScan ;  
  
//=====================================================================================================================
// ...
//=====================================================================================================================

class ExportedByCATBtoSmoothing CATBtoSmoothingServices
{
public:  
    
  //Ajout ANR pour Tooling
  static int  Reordering(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, int iIndex1, int iIndex2, CATCldScan *&ioScan);

  // Suppression des points dupliques
  static void CleanOfTheInputScan(CATGeoFactory *iFactory, CATCldScan *InputScan, CATCldScan *&oCleanScan);
  // Aremplir ...
  
} ;

#endif

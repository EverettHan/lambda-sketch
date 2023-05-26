/* -*-c++-*- */
#ifndef BODynFindMode_h
#define BODynFindMode_h

#include "CATCGMBOAObject.h" 

enum CATImplementationMode 
{
  CATIAMODE     = 1515,
  CNEXTMODE     = 1664,
  UNKNOWNMODE   = 666
};


#define CATIAGeoFactoryImplName1 "CATSOLCR"
#define CATIAGeoFactoryImplName2 "CATGEO3D"
#define CATIAGeoFactoryImplName3 "CAT_1001_1"

#if defined ( CATCGMBOAObject )
#define CNEXTGeoFactoryImplName  "TIECGMCATGeoFactory"
#else
#define CNEXTGeoFactoryImplName  "CATRootContainerCGM"
#endif

class CATGeoFactory;
#include "BODYNOPELight.h"

ExportedByBODYNOPELight
CATImplementationMode BODynFindMode(CATGeoFactory*);
 

#endif

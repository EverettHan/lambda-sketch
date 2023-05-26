/*
=============================================================================

  COPYRIGHT   : DASSAULT SYSTEMES 1999       
  //==========================================================================
  DESCRIPTION  
  // CreateSurTo2DDevMapping
  // Create and remove some types of CATSurTo2DGlobalMapping
  //
  //==========================================================================
  //
  // Usage notes: 
  //
  //==========================================================================
  // August     99     Creation                                    OB                 
  //========================================================================== 
  //
*/ 
#ifndef CreateCATSurTo2DDevMapping_H 
#define CreateCATSurTo2DDevMapping_H 

#include "CATDataType.h" 
#include "AdvTopoUtil.h" 

#include "CATMathConstant.h" 
class CATGeoFactory; 
class CATBody;
class CATVertex;
class CATMathAxis;  
class CATMathLine;  
class CATSurTo2DGlobalDevDevMapping;
class CATSurTo2DGlobalDevProjMapping;
class CATSoftwareConfiguration;
/**
* Creates DevDev mapping according to an axis .
* =>All surfaces witin the shell  must be revolution surfaces or equivalent with iRevolAxis 
* => Invariant Point => X=0, Y=0
* => Y will be angle coordinate ( steching =0 at radius invariantPoint)
* => X will be generatrice direction according to curve coordinate 
*/
ExportedByAdvTopoUtil
CATSurTo2DGlobalDevDevMapping * CreateDevDevMapping(CATGeoFactory *iFactory, 
                                                    CATBody* SupportShell,
                                                    const CATBoolean iImplicitMapping, 
                                                    CATVertex *iInvariantPoint, 
                                                    const CATMathLine &iRevolAxis,
                                                    CATSoftwareConfiguration * iConfig=0);

/**
* Retrieves the Invariant Point Working axis  according to the Mapping Mode.
* =>According to Shell orientation if iImplicitMapping=0 
* =>According to exterior evaluation if iImplicitMapping=1  
*/
ExportedByAdvTopoUtil
void GetSurTo2DDevDevAxis(CATGeoFactory *iFactory, 
                          CATBody* SupportShell,
                          const CATBoolean iImplicitMapping, 
                          CATVertex *iInvariantPoint, 
                          const CATMathLine &iRevolAxis,  
                          CATMathAxis &oAxisOnSupport,  
                          CATLONG32 &oAxisInversionSuggestion,  
                          double &oSkinAxisOrientation,
                          CATSoftwareConfiguration * iConfig=0);

/**
* Creates DevProj mapping according to an axis 
* =>All surfaces witin the shell  must be revolution surfaces or equivalent with iRevolAxis 
* => Invariant Point => X=0, Y=0
* => Y will be angle coordinate ( steching =0 at radius invariantPoint)
* => X will transfered according to curve coordinate on a circle of radius iRADIUS and then projected normally to the circle on surface.
* => If RADIUS= 0. then the distance fron Invariant Point to RevolAxis is taken
*/
ExportedByAdvTopoUtil
CATSurTo2DGlobalDevProjMapping * CreateDevProjMapping(CATGeoFactory *iFactory, 
                                                      const CATBoolean iImplicitMapping,
                                                      CATVertex *iInvariantPoint, 
                                                      const CATMathLine &iRevolAxis ,
                                                      const double &iRadius=0.,
                                                      CATSoftwareConfiguration * iConfig=0)  ;
/**
* Retrieves theIvariant Point Working axis  
* Do not depend on Mapping Mode. 
*/
ExportedByAdvTopoUtil
void GetSurTo2DDevProjAxis(CATVertex *iInvariantPoint, 
                           const CATMathLine &iRevolAxis,  
                           CATMathAxis &oAxisOnSupport,
                           CATSoftwareConfiguration * iConfig=0);

/**
Removes a Mapping from Memory.
**/	
ExportedByAdvTopoUtil 
void RemoveMapping(CATSurTo2DGlobalDevDevMapping *&iMappingToRemove);  

ExportedByAdvTopoUtil 
void RemoveMapping(CATSurTo2DGlobalDevProjMapping *&iMappingToRemove) ; 


#endif



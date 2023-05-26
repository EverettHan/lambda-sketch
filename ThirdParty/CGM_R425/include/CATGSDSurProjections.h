/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=====================================================================
//
// GlobDef operator : Repeted projections onto surf in normal
//                    or in given direction in ADVANCED mode. 
//
//=====================================================================
//
// Usage notes: Do not use if only one point is to be projected.
//              No BASIC mode is provided!           
//
//=====================================================================
// Feb 99   Creation                         D. Johansson
//=====================================================================

#ifndef CATGSDSurProjections_H  
#define CATGSDSurProjections_H 

#include "FrFOpeSur.h"
#include <stdlib.h>
#include "CATCGMVirtual.h"

class CATSurface ;
class CATFace ;
class CATNurbsSurface ;
class CATIntersectionCrvSur ; 
class CATDistanceMinPtSur;
class CATMathVector ;
class CATMathDirection ; 
class CATMathPoint ;
class CATLine ; 
class CATMathSetOfPoints ; 
class CATMathSetOfVectors ; 
class FrFOpeSur  ; 
class CATGeoFactory ; 
class CATShell ;
class CATSoftwareConfiguration;

class  ExportedByFrFOpeSur CATGSDSurProjections : public CATCGMVirtual
 
{  
 public: 
  
  virtual ~CATGSDSurProjections () {} ; 
  virtual void        SetHighLevelOfPrecision  (const int iLevel) =0;
  virtual void        SetOtherSurface(const CATNurbsSurface *iRefSurf ) = 0 ;
  virtual void        SetOtherSurface(const CATSurface *iRefSurf ) = 0 ;
  // This delete "iDirection" and find closest point:
  virtual void        SetPoint ( CATMathPoint *iPoint ) = 0 ;

  // If no "iDirection" is given, previous direction is used. It must exist! The returned result
  // corresponds to the point, closest to iPoint and lying on both the iRefsurf and on a line given
  // by iPoint and iDirection.
  virtual void        SetPointAndDirection (CATMathPoint     *iPoint,
                                            CATMathDirection *iDirection = NULL ) = 0 ; 

  // To calculate derivatives by finite differences. Differences smaller than, say, 0.001*FactoryResolution. 
  // Projection is done on a paraboloide made by previous point, first and second derivaives. By "previous"
  // is understood "before VeryCloseToPrevious(1)". Then, until "VeryCloseToPrevious(0)", all given points 
  // are projected this paraboloide.
  virtual void        VeryCloseToPrevious ( CATLONG32 yes ) = 0 ;  // zero if not.

  virtual void        Run             () = 0 ; 

  virtual CATLONG32   ResultIsOK      () = 0 ;
  
  virtual CATSurParam GetSurParam     () = 0 ;
 
  virtual void        GetLocalSurData (CATMathPoint  *oSurP   ) = 0 ;  

  virtual void        GetLocalSurData (CATMathVector *oSurDu,   
                                       CATMathVector *oSurDv  ) = 0 ;  

  virtual void        GetLocalSurData (CATMathVector *oSurDuu, 
                                       CATMathVector *oSurDuv, 
                                       CATMathVector *oSurDvv ) = 0 ; 

  // Useful only at projection on a shell (multi face):
  // If the current result is found on the same face as the previous result you may
  // gain speed if you trust that projection test on other faces are not needed. 
  virtual void SetPriorityIfSameFace ( CATLONG32 yes ) = 0 ; // zero if not.

  //===================================================================
virtual int   GetMultipleProjections()  =0 ;
 
virtual void  SetMultipleProjections(int &iMultipleProjection) =0 ;

};

ExportedByFrFOpeSur CATGSDSurProjections * 
CreateCATGSDSurProjections (CATGeoFactory            * ifactory,
                            CATSoftwareConfiguration * iSoftwareConfiguration,
                            const CATNurbsSurface    * iRefSurf ) ; 

ExportedByFrFOpeSur CATGSDSurProjections * 
CreateCATGSDSurProjections (CATGeoFactory            * ifactory,
                            CATSoftwareConfiguration * iSoftwareConfiguration,
                            const CATShell           * iRefShell ) ; 

ExportedByFrFOpeSur CATGSDSurProjections * 
CreateCATGSDSurProjections (CATGeoFactory            * ifactory,
                            CATSoftwareConfiguration * iSoftwareConfiguration,
                            CATSurface    * const    * iSurfaces,
                            CATLONG32                  iNbSurf,
                            CATFace       * const    * iFaces = NULL,
                            CATLONG32                  iNbFac = 0 ) ; 

ExportedByFrFOpeSur CATGSDSurProjections * 
CreateCATGSDSurProjections (CATGeoFactory            * ifactory,
                            CATSoftwareConfiguration * iSoftwareConfiguration,
                            CATFace          * const * iFaces,
                            CATLONG32                  iNbFac ) ; 

ExportedByFrFOpeSur CATGSDSurProjections * 
CreateCATGSDSurProjections (CATGeoFactory            * ifactory,
                            CATSoftwareConfiguration * iSoftwareConfiguration,
                            const CATSurface         * iRefSurf ) ;
 
ExportedByFrFOpeSur void Remove (CATGSDSurProjections *&iCATGSDSurProjections ) ;
  
#endif  

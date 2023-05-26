//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// Operator to define a no linear Transformation of the space
//
//==========================================================================
// Usage Notes
//==========================================================================
// Dec. 99     Creation                       PMG
//
//June 2000 Modification                      APD
//
//March 2001 Move to FreeFormOperators         DR
//========================================================================== 
#ifndef CATSpatialTransfo_H
#define CATSpatialTransfo_H

//#include "GeoMorph.h"
#include "CATMathDef.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMapFunctionXYZ.h"
#include "CATSkillValue.h"
#include "CATCGMJournalList.h"
#include "CATCGMVirtual.h"


class CATSpatialTransfo : public CATCGMVirtual
{
  public:

        virtual ~CATSpatialTransfo() ;

        //===========
        //Information
        //===========
        virtual CATBoolean IsAKindOf(const char*) const = 0;


        //===========
        //Initialization
        //===========  
        virtual void Set(const CATMathPoint& iPoint) = 0;
        virtual CATBoolean OK() const = 0;
        virtual void Run() = 0;

        //===========
        // Shorter Initialization (One methode to do Set/Ok/Run)
        //===========  
        virtual CATLONG32 Init(const CATMathPoint& iPoint) = 0;



        //===========
        //Evaluators
        //===========    
        // Get the Transformed Point
        virtual void GetPoint(CATMathPoint & oPModified) const = 0;

        // Transform a vector ( a tangential vector ?)
        virtual void TransformVector(CATMathVector& iV, CATMathVector& oV) const = 0 ;

        // Transform a normal
        virtual void TransformNormal(CATMathVector& iV, CATMathVector& oV) const = 0 ;

        // Transform a second derivative
        virtual void TransformSecondDeriv(CATMathVector& inFirstDeriv, 
                                          CATMathVector& inSecDeriv, 
                                          CATMathVector& outSecDeriv ) const = 0;

        // Transform a crossed second derivative
         virtual void TransformCrossDeriv(CATMathVector &inDerivU,     
                                          CATMathVector &inDerivV,     
                                          CATMathVector &inCrossUV, 
                                          CATMathVector &outCrossUV ) const = 0;

};
ExportedByFrFObjects
CATSpatialTransfo *  CATCreateSpatialTransfo(const CATMapFunctionXYZ * iMap);

#endif

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
//June 2000 Modification					  APD
//Oct  2007 Modification					  MPS   mkarchi BAD004 R205 : class CATMapFunctionXYZ au lieu de l'include
//========================================================================== 
#ifndef CATFDFTransfo_H
#define CATFDFTransfo_H

#include "InfraMorph.h"
#include "CATMathDef.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"

#include "CATSkillValue.h"
#include "CATCGMJournalList.h"

class CATMapFunctionXYZ;

class CATFDFTransfo
{
  public:

		virtual ~CATFDFTransfo() ;

		//===========
		//Information
		//===========
		virtual CATBoolean IsAKindOf(const char*) const = 0;


		//===========
		//Initialization
		//===========  
		virtual void Set(const CATMathPoint& iPoint, const CATMathVector* iNormal= NULL) = 0;
		virtual CATBoolean OK() const = 0;
		virtual void Run() = 0;

		//===========
		// Shorter Initialization (One methode to do Set/Ok/Run)
		//===========  
		virtual CATLONG32 Init(const CATMathPoint& iPoint, const CATMathVector* iNormal= NULL) = 0;



		//===========
		//Evaluators
		//===========	
		// Get the Transformed Point
		virtual void GetPoint(CATMathPoint & oPModified) const = 0;

		// Transform a vector ( a tangential vector ?)
    // can be wrong (in case of Offset Map)
		virtual void TransformVector(CATMathVector& iV, CATMathVector& oV) const = 0 ;

    // Compute a correct tangential vector (in case of Offset Map)
    // can be wrong (in case of Offset Map)
    virtual int TransformVectorTrue(const CATMathVector& iV, CATMathVector& oV, const double iRho) const=0; 

		// Transform a normal
		virtual void TransformNormal(CATMathVector& iV, CATMathVector& oV) const = 0 ;

#ifdef FDFTransfo_G2
		// Transform a second derivative
		virtual void TransformSecondDeriv(CATMathVector& inFirstDeriv, 
										CATMathVector& inSecDeriv, 
										CATMathVector& outSecDeriv ) const = 0;

		// Transform a crossed second derivative
		 virtual void TransformCrossDeriv(CATMathVector &inDerivU,     
										  CATMathVector &inDerivV,     
										  CATMathVector &inCrossUV, 
										  CATMathVector &outCrossUV ) const = 0;
#endif

};
ExportedByInfraMorph
CATFDFTransfo *  CATCreateFDFTransfo(const CATMapFunctionXYZ * iMap, const int isens=1);

#endif

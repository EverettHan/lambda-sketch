/* -*-C++-*-*/
#ifndef CATHLRCrvParamRef_H
#define CATHLRCrvParamRef_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRCrvParamRef 
//
// DESCRIPTION :
/**
 * Reference for the curve with a discretized representation
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATCrvParamReference.h"
#include "CATCGMScaleCategoryDef.h" // for enum CATCGMScaleCategory


class ExportedByHLRGeometry CATHLRCrvParamRef : public CATCrvParamReference
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor with the size of the discretization
 */
  CATHLRCrvParamRef(int iCountPoints, CATCGMScaleCategory iScaleCategory);

/**
 * Destructor
 */
  virtual ~CATHLRCrvParamRef();

//=============================================================================
// OVERRIDEN METHODS OF COMPUTATION
//=============================================================================

// Methods to convert a global parameter to a local one
  virtual double ComputeGlobalParam(const CATParamData &iLocalPosition) const ;
 
// Methods to convert a local parameter to a global one
  virtual void ComputeLocalPosition(double         iGlobalParam,
                                    CATParamData & oPosition) const ;


// Gives the difference between to local parameters : returns First - Second
  virtual double SubstractLocalParam(const CATParamData & iFirstParam,
                                     const CATParamData & iSecondParam) const ;


public : 

  const double GetScaleFactor() const;
  const double GetInvScaleFactor() const;

  inline const CATCGMScaleCategory GetScaleCategory() const;


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  // Last arc of the curve
  struct HLRCrvParRefBitField 
  {
    unsigned int                 _IdxLastArcOnCurve : 24;

    unsigned int                 _ScaleCategory     :  8;
  };
  HLRCrvParRefBitField           _CrvParRefDATA;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline const CATCGMScaleCategory CATHLRCrvParamRef::GetScaleCategory() const {
  return (const CATCGMScaleCategory ) _CrvParRefDATA._ScaleCategory; }

#endif

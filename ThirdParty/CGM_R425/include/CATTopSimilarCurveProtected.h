// COPYRIGHT DASSAULT SYSTEMES  2010
// JSX .h en protected pour methode non CAA

#ifndef CATTopSimilarCurveProtected_h
#define CATTopSimilarCurveProtected_h

#include "CATTopSimilarCurve.h"
#include "CATIACGMLevel.h"

class ExportedByFrFTopologicalOpe CATTopSimilarCurveProtected : public CATTopSimilarCurve
{

  public:
/**
 * @nodoc
 * Constructor. 
 */
    CATTopSimilarCurveProtected(CATGeoFactory * iFacto,CATTopData * iData):CATTopSimilarCurve(iFacto,  iData){;};
    virtual ~CATTopSimilarCurveProtected() {;};

 /**
 * @nodoc
 */
  static const  CATString  *GetDefaultOperatorId();
  static CATString  _OperatorId;
  };
#endif 



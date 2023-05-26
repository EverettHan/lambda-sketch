/* -*-c++-*- */
#ifndef CATTopFastTransformFace_h
#define CATTopFastTransformFace_h
//
#include "CATTopOperator.h"
#include "BODYNOPE.h"
#include "CATMathInline.h"
#include "ListPOfCATFace.h"
//
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATFace;
class CATMathTransformation;

class ExportedByBODYNOPE CATTopFastTransformFace : public CATTopOperator  
{

 public :
 // -----

  // Constructor standard
  CATTopFastTransformFace ( CATGeoFactory * iFactory,
	                        CATTopData    * iTopData) :
  CATTopOperator(iFactory,iTopData)
  {
  }

  INLINE virtual ~CATTopFastTransformFace() 
  {
  };

  virtual int GetNbExtrapol () = 0;

};

ExportedByBODYNOPE CATTopFastTransformFace * CATCreateTopFastTransformFace ( CATGeoFactory         * iFactory,
                                                                             CATTopData            * iTopData, 
					                                                         CATBody               * iBaseBody, 
					                                                         ListPOfCATFace        & iBaseFacesList,
			                                                                 CATMathTransformation & iMathTransformation);

#endif

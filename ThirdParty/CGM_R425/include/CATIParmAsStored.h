#ifndef CATIParmAsStored_h
#define CATIParmAsStored_h

// COPYRIGHT DASSAULT SYSTEMES 1999
  
/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// export module declaration
#include "CATLifSpecs.h"

// inherited from
#include <CATBaseUnknown.h>

// forwards
#include "CATICkeRelationForwards.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIParmAsStored;
#else
extern "C" const IID IID_CATIParmAsStored;
#endif


/**   
 * Interface dedicated to value valuation in model unit.
 * <b>Role</b>: This interface is to be used to read and write parameters values 
 * corresponding to geometrical dimensions (Length and Angle).<br>
 * Length's unit is millimeter.<br>
 * Angle's unit is degree.<br>
 * This interface is implemented on parameters.
 * @see CATICkeParm
 */
class ExportedByCATLifSpecs CATIParmAsStored : public CATBaseUnknown
{

  CATDeclareInterface;

public :
  
/**
 * Valuates parameter value in model unit.
 * @param iValue : 
 *   value to be stored in model unit.	
 */
virtual void ValuateStored (const double iValue) = 0;
  
/**
 * Returns parameter value in model unit.
 */
virtual double ValueStored () const = 0;

}; 

CATDeclareHandler(CATIParmAsStored,CATBaseUnknown);

#endif



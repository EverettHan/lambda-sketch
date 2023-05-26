#ifndef CATIEnumere_h
#define CATIEnumere_h

// COPYRIGHT DASSAULT SYSTEMES 1999
  
/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */


/*  CAA2Reviewed by FRH */


// module declaration
#include "CATLifSpecs.h"

// Inherited from
#include <CATBaseUnknown.h>

// Forwords for CkeAdapter
#include <CATICkeForwards.h>

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIEnumere;
#else
extern "C" const IID IID_CATIEnumere;
#endif


/**   
 * Interface dedicated to enumerated types management.
 * <b>Role</b>: This interface gives access to enumerated types properties.<br>
 * Enumerated types also implement CATICkeType<br>
 * An enumerated type is a parameter type that allows only a list of identified string values
 * @see CATICkeType, CATICkeParm
 */
class ExportedByCATLifSpecs CATIEnumere : public CATBaseUnknown
{

public :
 
/**
 * Returns the pre-definite list of values allowed for this type.
 * @param iListNLSNames if not NULL, this list is filled with NLS name of values.<br>
 *    The mechanism to find NLS name for the value is to find it in the NLS msgcatalog file which corresponds
 *    to the .feat catalog in which the enumere is.
 * @return list of values not to be deallocated !!!.
 */
virtual CATListOfCATUnicodeString *Values (CATListOfCATUnicodeString *iListNLSNames = NULL) const = 0;

/**
 * Finds the rank (1 to N) of an enum value from its string.
 * @param iValue value to be found
 * @return rank of the value from 1 to N if found (else 0) 
 * <br><b>Legal values</b>: 
 * <tt>1 to N</tt> rank of the value in the list if found.
 * <tt>0</tt> if value hasn't been found.
 */
virtual int Find (const CATUnicodeString &iValue) const = 0;


private:

  // to define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATIEnumere,CATBaseUnknown);

#endif



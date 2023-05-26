#ifndef CATTopPreTransformation_H
#define CATTopPreTransformation_H

// COPYRIGHT DASSAULT SYSTEMES  2001


//Windows compatibility
#include "BODYNOPE.h"

#include "CATTopOperator.h"

class CATGeoFactory;
class CATTopData;

/**
* Class representing the topological operator that creates a CATBody suitable for being transformed.
* <br>
* It follows the use frame of all operator and satisfies to the smart mechanism: the
* input body is not modified. A new resulting body is created, 
* possibly sharing data with the input one.
*/
class ExportedByBODYNOPE CATTopPreTransformation: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopPreTransformation);
public:
  /**
  * Virtual constructor.<br>
  * Cannot be called. Use the <tt>CATCreateTopPreTransformation</tt> global function
  * to create a CATTopPreTransformation.
  */
  CATTopPreTransformation(CATGeoFactory* iContainer, CATTopData* iData);

  /**
   * Deprecated
   * Cannot be called. Use the <tt>CATCreateTopPreTransformation</tt> global function
   * to create a CATTopPreTransformation.
   */
  CATTopPreTransformation(CATGeoFactory* iContainer, CATCGMJournalList* iJournal=NULL);

  /**
   * Destructor.
   */
  virtual ~CATTopPreTransformation();
};
#endif

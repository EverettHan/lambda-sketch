#ifndef CATCke_h
#define CATCke_h


// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U1 
 */

/*  CAA2Reviewed by FRH */

// include module definition
#include "CATLifSpecs.h"
#include "CATUnicodeString.h"
#include "CATICkeForwards.h"


/**   
 *  Class used as a namespace. 
 *  <b>Role</b>: namespace.<br>
 */
class ExportedByCATLifSpecs CATCke
{

public:

// types
#define CATCkeDataTypesActive
#include "CATCkeDataTypes.h"

 
  /**
   * Constructor. 
   */
  CATCke () {}
  /**
   * Copy constructor. 
   */
  CATCke (const CATCke&) {}
  /**
   * Destructor. 
   */
  virtual ~CATCke() ;

   /**
   * @nodoc to be exposed
   */ 
   static CATUnicodeString EMPTYSTRING;
};

#endif


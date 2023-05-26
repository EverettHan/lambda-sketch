#ifndef CATHybSplit1_H
#define CATHybSplit1_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "CATHybSplit.h"
#include "CATHybBoolean.h"

#include "CATIACGMLevel.h"
#ifndef CATIACGMV5R19
#include "BOHYBOPE.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"
#include "CATIAV5Level.h"

class CATHybSplit;
class CATExtHybSplit;

/**
* Class defining the operator that splits two bodies.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* It follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATHybSplit is created with the <tt>CATCreateTopSplit</tt> global function. 
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the  href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
*  see CATCreateTopSplit
*/

class ExportedByBOHYBOPE CATHybSplit1 : public CATHybSplit
{
   CATCGMVirtualDeclareClass(CATHybSplit1);
   protected :
   
   /**  nodoc */
   CATHybSplit1(  CATGeoFactory * iFactory, 
                  CATTopData    * iTopData, 
                  CATExtHybSplit* iExtensible, 
                  CATBody       * iBodyToSplit, 
                  short           iSideToKeep, 
                  CATBody       * iSplittingBody, 
                  CATBody       * iCuttingBody);	
   
  
 public :

   //  Destructor
   virtual    ~CATHybSplit1();     
//#ifndef CATIACGMV5R19        
	 /**
	 * Sets or unsets the ‘keep only the no intersecting solutions of extrapolated cuttings’ mode.
	 *    param iMode
	 *      Mode on (TRUE) or off (FALSE)
	 */
	 void  SetSingleExtrapolMode(CATBoolean iMode=0);

	 /**
	 * Queries whether ‘keep only the no intersecting solutions of extrapolated cuttings’ mode is activated or not.
	 *    param oMode
	 *      Mode on (TRUE) or off (FALSE)
	 */
	 void GetSingleExtrapolMode(CATBoolean & oMode); 

   
};
#else
typedef CATHybSplit CATHybSplit1;
#endif 


#endif

#ifndef CATAdvGenericHealing_H_
#define CATAdvGenericHealing_H_

// COPYRIGHT DASSAULT SYSTEMES  2005


//
#include "AdvGenHeal.h"
#include "CATGenericHealing.h"
#include "CATExtCGMReplay.h"

//
#ifndef NULL
#define NULL 0
#endif

//
class CATBody;
class CATShell;


/**
* Class defining the Healing operator on body with given scars or G1 discontinuities
* to be treated.
*<br>
* The CATAdvGenericHealing operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input bodies are not modified. A new resulting body 
* is created, possibly sharing data with the input body.
* The Healing operator failed in case of non-manifold topology detected on an edge impacted
* by the Healing.
*<ul>
* <li>A CATAdvGenericHealing operator is created with the <tt>CATCreateAdvGenericHealing</tt> global function:
* It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. In particular, an optimized mode
* allows you to do some local operations in union mode.
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. 
*</ul>
*/



class ExportedByAdvGenHeal CATAdvGenericHealing	: public	CATGenericHealing
{

private:

/**
 * @nodoc
 * Virtual constructor of a CATAdvGenericHealing operator.<br>
 * Cannot be called. Use the <tt>CATCreateAdvGenericHealing</tt> global function
 * to create a CATAdvGenericHealing operator.
 */
  CATAdvGenericHealing (CATGeoFactory*     iContainer,
                        CATTopData*        iData,
                        CATExtTopOperator* iExtensible = NULL);

public:

/**
 * Destructor.
 */
  virtual ~CATAdvGenericHealing();

/**
 * Creates a CATAdvGenericHealing operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iPart
 * The pointer to the body to heal.
 * @param iShell
 * The pointer to the shell to heal.
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */

  static CATAdvGenericHealing* CATCreateAdvGenericHealing (CATGeoFactory*     iFactory,
                                                           CATTopData*        iData,
                                                           CATBody*           iPart,
                                                           CATShell*          iShell,
                                                           CATBoolean         iSafeJournal = TRUE);
};

#endif

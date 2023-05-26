/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2003
//------------------------------------------------------------------------------
//      
// class for Smart Projection
//       
//------------------------------------------------------------------------------
#ifndef CATTopSmartProject_h
#define CATTopSmartProject_h

/**
* Class defining the operator that projects a body (containing only wires) on another one(containing only shells)
* and gets the result which is the nearest from the original wires. The nearest is the minimum of maximum distances.
* It follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATTopSmartProject is created with the <tt>CATCreateTopSmartProject</tt> global function.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* <li>The CATTopSmartProject can be restricted on a given domain on body to project with the methods
* <tt>SetDomainToProject</tt>
* <li>An optionnal check can be done of the result to know if the complete wire has been projected
* <tt>SetNearOption</tt>
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopSmartProject
*/

#include "CATIACGMLevel.h"
#include "BOHYBOPE.h"
#include "CATHybProject.h"

class CATBody;
class CATMathDirection;


class ExportedByBOHYBOPE CATTopSmartProject : public CATHybProject
{

  CATCGMVirtualDeclareClass(CATTopSmartProject);
  public :
   
   //  Constructor
   /** @nodoc */
   CATTopSmartProject(CATGeoFactory*           iFactory,
     CATTopData*              iData,CATExtHybProject* iExtensible,
      CATBody* iBodyToProject, CATBody* iBodySupport, CATMathDirection* iDirection);

   virtual ~CATTopSmartProject();
   
   /**
	 * check that the complete wire has been projected on the shell
   * 0 : the check will be done
   * 1 : the check is not done
	 */
   virtual void SetNearOption(int iNear) =0;
    virtual void SetDomainToProject(CATDomain* iDomain) =0; 

    virtual void SetRemoveArtefacts(int iRemoveArtefacts) = 0;


  #ifdef CATIACGMR418CAA
	/** @nodoc */
    virtual void SetHandleMultiDomainBodies(CATBoolean iHandleMultiDomainBodies) = 0;
	/** @nodoc */
    virtual CATBoolean GetHandleMultiDomainBodies() const = 0; 
  #endif

   /**
	 * Returns all the computed projections in a single body.
	 * @return
	 * The pointer to the resulting body. If you do not want to keep it, use the @href CATICGMContainer#Remove method
	 * to remove it from the geometric factory after the <tt>delet</tt>ion</tt> of <tt>this</tt> operator.
	 */
   virtual CATBody * GetResult()                              =0;
   virtual CATBody * GetResult(CATCGMJournalList * iJourn)    =0;


};

ExportedByBOHYBOPE CATTopSmartProject * CATCreateTopSmartProject(CATGeoFactory*           iFactory,
                                    CATTopData*              iData,
                                    CATBody*                 iBody_To_Project,
                                    CATBody*                 iBody_Support, 
                                    CATMathDirection*        iDirection=NULL);

#endif


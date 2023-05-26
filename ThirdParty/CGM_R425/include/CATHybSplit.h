#ifndef CATHybSplit_h
#define CATHybSplit_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Protected
* @usage U1
*/

#include "CATIACGMLevel.h"
#include "CATHybBoolean.h"
#include "CATCGMOperatorDebug.h"
#include "BOHYBOPELight.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"
#include "CATIAV5Level.h"

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
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopSplit
*/
class ExportedByBOHYBOPELight CATHybSplit : public CATHybBoolean
{

   friend ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplit(CATGeoFactory*     iFactory,
                                                   CATTopData*        iData,
                                                   CATBody*           iBodyToSplit,
                                                   short              iSideToKeep,
                                                   CATBody*           iSplittingBody,
                                                   CATBody*           iCuttingBody);

   friend ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplit(CATGeoFactory*     iFactory,
                                                   CATTopData*        iData,
                                                   CATBody*           iBodyToSplit,
                                                   CATBody*           iSplittingBody,
                                                   CATBody*           iCuttingBody);

   friend ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitOnSupport(CATGeoFactory*     iFactory,
                                                            CATTopData*        iData,
                                                            CATBody*           iBodyToSplit,
                                                            short              iSideToKeep,
                                                            CATBody*           iSplittingBody,
                                                            CATBody*           iBodySupport);
	 
   friend CATHybSplit * CATCreateTopSplit(CATGeoFactory*     iFactory,
                                                   CATTopData*        iData,
                                                   CATBody*           iBodyToSplit,
                                                   short              iSideToKeep,
                                                   CATBody*           iSplittingBody,
                                                   CATBody*           iCuttingBody,
                                                   CATBoolean		      iSemiSpaceMode);
												                    
   friend CATHybSplit * CATCreateTopSplit(CATGeoFactory*     iFactory,
                                                   CATTopData*        iData,
                                                   CATBody*           iBodyToSplit,
                                                   short              iSideToKeep,
                                                   CATBody*           iSplittingBody,
                                                   CATBody*           iCuttingBody,
												                           CATBoolean		      iSemiSpaceMode,
                                                   CATBoolean		      iSingleExtrapol);

  
	 CATCGMVirtualDeclareClass(CATHybSplit);

protected :
   
   /** @nodoc */
   CATHybSplit(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybSplit* iExtensible, 
      CATBody* iBodyToSplit, short iSideToKeep, CATBody* iSplittingBody, CATBody* iCuttingBody);	
   
   /** @nodoc */
   CATHybSplit(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybSplit* iExtensible, 
      CATBody* iBodySupport,CATBody* iBodyToSplit, short iSideToKeep, CATBody* iSplittingBody);	
   
   /** @nodoc */
   CATHybSplit(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybSplit* iExtensible, 
     CATBody* iBodyToSplit, CATBody* iSplittingBody, CATBody* iCuttingBody);	

#ifdef CATIACGMR419CAA   
   /** @nodoc @nocgmitf */
   virtual int RunExactOperator();
   /** @nodoc @nocgmitf */
   virtual int RunPolyOperator();
#endif

public :

   //  Destructor
   ~CATHybSplit();     

   // (Empty macro in customer release mode; no effect on generated code)
   virtual int Run() ;
  /** @nodoc @nocgmitf */
   virtual int RunOperator() ;

         
   // desactivation of Error on SplitClosedWireWithSingleVertex (to use before run)
   // default value is : 1 --> Error is throw in case of Split a ClosedWire With Single Vertex
   /** @nodoc */
   void SetThrowErrorForClosedWireWithSingleVertex(int yes_or_no=1);
   /** @nodoc */
   int  GetErrorForClosedWireWithSingleVertexMode() const;
   
   // treatment with Simplification of the Result (to use before run)
   /** @nodoc */
   void SetSimplifyMode(int yes_or_no=1);
   /** @nodoc */
   int  GetSimplifyMode() const;

	 /**
	 * Sets or unsets the ‘Keep elements in half space’ mode.
	 *   @param iMode
	 *      Mode on (TRUE) or off (FALSE)
	 */
	 void  SetKeepHalfSpaceMode(CATBoolean iMode=0);

	 /**
	 * Queries whether ‘Keep elements in half space’ mode is activated or not.
	 *   @param oMode
	 *      Mode on (TRUE) or off (FALSE)
	 */
	 void GetKeepHalfSpaceMode(CATBoolean & oMode); 

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

   // (to use before run)
   // If iLyingOnMode == 0 : LyingOn links from CuttingBody cells onto SplittingBody cells are deleted
   // If iLyingOnMode == 1 : they are not deleted
   /** @nodoc */
   void SetLyingOnLinksKept(int iLyingOnMode=1);


   /** @nodoc  */
   inline CATExtHybSplit* GetHybSplitExtensible() const;
   
};

/** @nodoc  */
inline CATExtHybSplit* CATHybSplit::GetHybSplitExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybSplit*) _Extensible;
}

#endif

#ifndef CATHybTrim_h
#define CATHybTrim_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Protected
* @usage U1
*/

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATHybBoolean.h"
#include "CATCGMOperatorDebug.h"
#include "BOHYBOPELight.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"
#include "CATIAV5Level.h"


class CATExtHybTrim;

#ifdef CATIACGMV5R21
   class CATHybTrimContextForFastRun;
#endif

/**
* Class defining the operator that trims two bodies.
* The input bodies must intersect.
* The two bodies must have the same dimensionality and be wires or shells.
* Each body is split by the other one. The Trim operation cannot complete if the bodies do not intersect.
* It follows the general frame of all operators and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
* <ul>
* <li><tt>CATHybTrim</tt> can be created by different global functions:
*   <ul>
*     <li><tt>CATCreateTopTrim</tt></li>
*     <li><tt>CATCreateTopTrimOnSupport</tt> </li>
*     <li><tt>CATCreateTopTrimShell</tt> </li>
*     <li><tt>CATCreateTopTrimShellWithKeepRemove</tt></li>
*     <li><tt>CATCreateTopTrimWire</tt></li>
*     <li><tt>CATCreateTopTrimWireWithKeepRemove</tt></li>
*   </ul>
* <li>It must be
* directly deleted with the usual C++ delete <tt>operator</tt> after use.
* It is not streamable. 
* <li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopTrim
* @see CATCreateTopTrimOnSupport
* @see CATCreateTopTrimShell
* @see CATCreateTopTrimShellWithKeepRemove
* @see CATCreateTopTrimWire
* @see CATCreateTopTrimWireWithKeepRemove
*/
class ExportedByBOHYBOPELight CATHybTrim : public CATHybBoolean
{
#ifndef CATIACGMR420CAA
   friend ExportedByBOHYBOPELight CATHybTrim* CATCreateTopTrim(CATGeoFactory*     iFactory,
                                                CATTopData*        iData, 
                                                CATBody*           iFirstBodyToCut,
                                                short              iFirstSideToKeep,
                                                CATBody*           iSecondBodyToCut,
                                                short              iSecondSideToKeep,
                                                CATBody*           iCuttingBody);

   friend ExportedByBOHYBOPELight CATHybTrim* CATCreateTopTrim(CATGeoFactory*     iFactory,
                                                CATTopData*        iData, 
                                                CATBody*           iFirstBodyToCut,
                                                CATBody*           iSecondBodyToCut,
                                                CATBody*           iCuttingBody);

   friend ExportedByBOHYBOPELight CATHybTrim* CATCreateTopTrimOnSupport(CATGeoFactory*     iFactory,
                                                         CATTopData*        iData, 
                                                         CATBody*           iFirstBodyToCut,
                                                         short              iFirstSideToKeep,
                                                         CATBody*           iSecondBodyToCut,
                                                         short              iSecondSideToKeep,
                                                         CATBody*           iBodySupport);
#endif

  CATCGMVirtualDeclareClass(CATHybTrim);

protected :
   
#ifndef CATIACGMR420CAA
   /** @nodoc */
   CATHybTrim(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybTrim* iExtensible, 
      CATBody* iBodyToCut1, short iSideToKeep1, CATBody* iBodyToCut2, short iSideToKeep2, CATBody* iCuttingBody);	
   
   /** @nodoc */
   CATHybTrim(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybTrim* iExtensible, 
      CATBody* iBodySupport, CATBody* iBodyToCut1, short iSideToKeep1, CATBody* iBodyToCut2, short iSideToKeep2);	
   
   /** @nodoc */
   CATHybTrim(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybTrim* iExtensible, 
      CATBody* iBodyToCut1, CATBody* iBodyToCut2,  CATBody* iCuttingBody);	
#endif

 public :

#ifdef CATIACGMR420CAA
   /** @nodoc @nocgmitf */
   CATHybTrim(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybTrim* iExtensible);
#endif
   
   //  Destructor
   ~CATHybTrim();     
   
   /** @nodoc  */
   #ifdef CATIACGMV5R20
   #define CATHybTrimDefineRunOperator
   #endif
   // (Empty macro in customer release mode; no effect on generated code)
    #ifdef CATCGMOperatorDebugMode
   #define CATHybTrimDefineRunOperator
    #endif
   #ifdef CATHybTrimDefineRunOperator
   virtual int Run() ;
  /** @nodoc @nocgmitf */
   virtual int RunOperator() ;
#ifdef CATIACGMR419CAA   
   /** @nodoc @nocgmitf */
   virtual int RunExactOperator();
   /** @nodoc @nocgmitf */
   virtual int RunPolyOperator();
#endif
   #endif

   /**
   * Activates or deactivates simplification of the result.
   * Set the simplify mode before running the operator.
   * @param yes_or_no
   * <ul>
   * <li>0: deactivates the "simplify" mode
   * <li>1: activates the "simplify" mode.
   * </ul>
   */
   void SetSimplifyMode(int yes_or_no=1);

  /**
  * Retrieves the simplify mode.
  * @return
  * <ul>
  * <li>0: the "simplify" mode is not activated
  * <li>1: the "simplify" mode is activated.
  * </ul>
  */
   int  GetSimplifyMode() const;
   
  
   /** @nodoc  */
   inline CATExtHybTrim* GetHybTrimExtensible() const;

#ifdef CATIACGMV5R21
   /**
   * @nodoc
   * Returns the context for fast run specific of CATHybTrim operator.
   * @param iGetOnly
   * If FALSE and context doesn't exist, it is created.
   * @return [out, IUnknown#Release]
   * The context for fast run.
   */
   CATHybTrimContextForFastRun * GetHybTrimContextForFastRun(CATBoolean iGetOnly);
#endif
   
};

/** @nodoc  */
inline CATExtHybTrim* CATHybTrim::GetHybTrimExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybTrim*) _Extensible;
}

#endif

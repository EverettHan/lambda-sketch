/* -*-C++-*-*/

#ifndef CATHybBoundary_h
#define CATHybBoundary_h

// COPYRIGHT DASSAULT SYSTEMES  2003

/**
* @level Protected
* @usage U1
*/ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "BOHYBOPELight.h"
#include "CATHybOperatorImp.h"
#include "CATCGMOperatorDebug.h"
#include "CATCreateTopBoundary.h"

class CATExtHybBoundary;


/**
* Class defining the operator that computes the boundary of a wire or a shell.
*<br>
* This operator follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATHybBoundary is created with the <tt>CATCreateTopBoundary</tt> global function.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopBoundary 
*/
class ExportedByBOHYBOPELight CATHybBoundary : public CATHybOperatorImp
{

   friend ExportedByBOHYBOPELight CATHybBoundary* CATCreateTopBoundary(CATGeoFactory* iGeoFactory, CATTopData* iData, 
      CATBody* iBody, CATDomain* iDomain, CATCell* iCell, CATHybPropagateMode iPropagateMode);

  CATCGMVirtualDeclareClass(CATHybBoundary);
protected :
	/** @nodoc */
    CATHybBoundary(CATGeoFactory* iGeoFactory, CATTopData* iData, CATExtHybBoundary* iExtensible,
       CATBody* iBody, CATDomain* iDomain, CATCell* iCell, CATHybPropagateMode iPropagateMode);
    
public:
	//  Destructor
    virtual ~CATHybBoundary();

   /** @nodoc  */
   #ifdef CATIACGMV5R20
   #define CATHybBoundaryDefineRunOperator
   #endif
   // (Empty macro in customer release mode; no effect on generated code)
    #ifdef CATCGMOperatorDebugMode
   #define CATHybBoundaryDefineRunOperator
    #endif
   #ifdef CATHybBoundaryDefineRunOperator
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

   
   /** @nodoc  */
   inline CATExtHybBoundary* GetHybBoundaryExtensible() const;
   
};

/** @nodoc  */
inline CATExtHybBoundary* CATHybBoundary::GetHybBoundaryExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybBoundary*) _Extensible;   
}

#endif

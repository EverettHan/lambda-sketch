/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// CATHybConfusion : base class for Hybrid Confusion Operators 
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
// 09/12/08 NLD Ajout Run() et RunOperator() pour instrumentation
//              Utilisation de CATCGMOperatorDebug pour outillage standard de debug/mesure
//
//==========================================================================
#ifndef CATHybConfusion_h
#define CATHybConfusion_h

#include "CATHybOperatorImp.h"
#include "CATCreateTopConfusion.h"
#include "BOHYBOPE.h"
#include "CATMathInline.h"

class CATExtHybConfusion;

class ExportedByBOHYBOPE CATHybConfusion : public CATHybOperatorImp
{
 
   friend ExportedByBOHYBOPE CATHybConfusion* CATCreateTopConfusion(CATGeoFactory* iFactory, CATTopData* iData, 
    CATBody* iBodyCandidate, CATBody* iBodySupport); 
 

  CATCGMVirtualDeclareClass(CATHybConfusion);
protected :
   
   //  Constructor
   CATHybConfusion(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybConfusion* iExtensible, 
      CATBody* iBodyCandidate, CATBody* iBodySupport);	
   
   
public :
   
	//  Destructor
   ~CATHybConfusion();     

   /** @nodoc */
   virtual int Run() ;
  /** @nodoc @nocgmitf */
   virtual int RunOperator() ;
      
   void SetCandidateDomain(CATDomain* iDomain);   // Set a Domain operande in iBodyCandidate
   void SetSupportDomain(CATDomain* iDomain);     // Set a Domain operande in iBodySupport
   
   //--------------------------------------------------------------------------
   //  Diagnostic CATHybConfusionDiagnostic{ NO_CONFUSION, FULL_CONFUSION, CONTACT };
   //  
   //  * Defines the differents results of a confusion diagnostic.
   //  * @param NO_CONFUSION
   //  * There is no confusion at all between the bodies.
   //  * @param FULL_CONFUSION
   //  * There is a full confusion between the bodies.
   //  * @param CONTACT
   //  * There is an intersection between the bodies but not a full confusion.
   //  
   //--------------------------------------------------------------------------
   CATHybConfusionDiagnostic GetConfusionDiagnostic();

   
   /** @nodoc  */
   INLINE CATExtHybConfusion* GetHybConfusionExtensible() const;
   
};

/** @nodoc  */
INLINE CATExtHybConfusion* CATHybConfusion::GetHybConfusionExtensible() const
{
   if (_Extensible)
      return (CATExtHybConfusion*) _Extensible;
   else 
      CATThrowForNullPointerReturnValue(NULL);
}
#endif

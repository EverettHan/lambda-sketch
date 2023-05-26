/* -*-C++-*- */
//	COPYRIGHT DASSAULT SYSTEMES 1996
//===================================================================
//  CATHybRegularize : transform a body onto a body with elimination of
// too small entities ( edges , faces or volumes less than tolerance )
// 09/12/08 NLD Ajout Run() et RunOperator() pour instrumentation
//===================================================================
#ifndef CATHybRegularize_h
#define CATHybRegularize_h
//
#include "CATHybOperatorImp.h"
#include "CATListOfCATCells.h"
#include "BOHYBOPE.h"
#include "CATMathInline.h"

class CATExtHybRegularize;

class ExportedByBOHYBOPE CATHybRegularize : public CATHybOperatorImp
{

   friend ExportedByBOHYBOPE CATHybRegularize * CATCreateTopRegularize(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToRegularize);
     
  CATCGMVirtualDeclareClass(CATHybRegularize);
protected :
   
   /** @nodoc */
   CATHybRegularize (CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybRegularize* iExtensible);
public :

   //  Destructor
   ~CATHybRegularize();     

   /** @nodoc */
   virtual int Run() ;
  /** @nodoc @nocgmitf */
   virtual int RunOperator() ;
   
   /** @nodoc */
   virtual void SetCellsToRegularize ( CATLISTP(CATCell)& iCellsToRegularize );

   /** @nodoc */
   virtual void SuppressOnlySmallClosedEdges();


   
   /** @nodoc  */
   INLINE CATExtHybRegularize* GetHybRegularizeExtensible() const;
   
};

/** @nodoc  */
INLINE CATExtHybRegularize* CATHybRegularize::GetHybRegularizeExtensible() const
{
   if (_Extensible)
      return (CATExtHybRegularize*) _Extensible;
   else 
      CATThrowForNullPointerReturnValue(NULL);
}
#endif

/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2010
//------------------------------------------------------------------------------
//      
// class for Top Slicing multibody
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATTopSlicingOperator_h
#define CATTopSlicingOperator_h
/**
 * @nodoc
 */ 
//#include "ExportedByBasicTopology"
#include "BasicTopology.h"
#include "CATTopCreateSlicingOperator.h"
#include "CATTopOperator.h"
//#include "CATHybIntersect.h"
//#include "CATGeoFactory.h"
//#include "CATGeoFactoryProtected.h"
//#include "CATTopData.h"

#include "CATIAV5Level.h"
#include "CATIACGMLevel.h"

#include "ListPOfCATBody.h"

//#include "CATString.h"

//
// The callback called after each slice iteration.
//
typedef void (*CATSliceCallback)( CATBody* iBody, int iIteration);

class CATBody;

class ExportedByBasicTopology CATTopSlicingOperator :public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopSlicingOperator);

protected:

 CATTopSlicingOperator (CATGeoFactory * iFactory, CATTopData * iTopData, CATExtTopOperator * iExtensible); 
 //CATTopSlicingOperator (CATGeoFactory * iFactory, CATTopData * iTopData);
  public:

 //  Destructor
   ~CATTopSlicingOperator ();

  
   //  Methods 
     /**
      * Runs the operator.
      */
      //virtual int  Run() = 0;
      /**
      * @nodoc @nocgmitf
      */
      //virtual void Dump(ostream & iOutStream) const = 0;
      /**
      * Returns the body resulting from the sewing operation.
      * @param ioJournal
      * The topological journal.
      * @return
      * The resulting body. 
      */

   virtual CATBody * GetResult(CATCGMJournalList * ioJournal = NULL) = 0;

   /** @nodoc  ...*/
   virtual          CATBoolean GetCheckJournal()                   const  = 0;
   virtual void   SetCheckJournal(CATBoolean iCheckMode)          = 0;
  /** @nodoc CATCGMReplay ...*/
   //static const CATString * GetDefaultOperatorId() { return & _OperatorId; };
   
	virtual void SetSliceCallback( CATSliceCallback iCallback) = 0;

protected:
  
  /** @nodoc CATCGMReplay ...*/
  //const CATString * GetOperatorId() const;
  
  /** @nodoc CATCGMReplay ...*/
  //CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  
  /** @nodoc CATCGMReplay ...*/
  //int RunOperator();
  
//   // Data
//  CATLONG32          _NbSlices;
//  double                     _Offset;
//  ListPOfCATBody*   _BodyList;
//  double                    _PlaneEquation[4];
//  CATBody*              _ResultBody;
//  CATTopData*        _TopData; 
////private:

   //static CATString _OperatorId;
};
#endif

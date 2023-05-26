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
#ifndef CATTopSlicingOperatorCGM_h
#define CATTopSlicingOperatorCGM_h
/**
* @nodoc
*/ 
#include "CATTopSlicingOperator.h" 
#include "CATExtTopOperator.h" 
#include "CATBasicBodyPlanarEquation.h"
//#include "BasicTopology.h"
#include "CATHybIntersect.h"
#include "CATGeoFactory.h"
#include "CATGeoFactoryProtected.h"
#include "CATTopData.h"
#include "CATTopCompatible.h"

#include "ListPOfCATBody.h"

#include "CATDataType.h"
#include "CATString.h"

class CATGeoFactory;
class CATTopData;
class CATCGMJournalList;
class CATBody;
class CATLISTP(CATBody);

class CATTopSlicingOperatorCGM :public CATExtTopOperator
{
   public:
      CATCGMNewClassArrayDeclare;

      CATTopSlicingOperatorCGM(CATGeoFactory*      iFactory, 
        CATTopData*          iData, 
        CATLISTP(CATBody) *iBodyList,
        double *                   iPlaneEquation,
        double                      iOffset,
        int                             NbSlices);

      CATTopSlicingOperatorCGM(CATGeoFactory * iFactory, CATTopData * iTopData); 
      //public:

      //  Destructor
      ~CATTopSlicingOperatorCGM();

  //virtual CATBoolean GetCheckJournal()                   const  = 0;


  //===================================================================================================
  // Methode Dump
  //===================================================================================================

 void Dump(CATCGMOutput & iOutStream) const;

  //===================================================================================================
  // results Methods  (INTERFACES)
  //===================================================================================================

  CATBoolean GetCheckJournal() const;
  /*virtual */CATBody * GetResult(CATCGMJournalList * ioJournal);
  /*virtual */CATBody * GetResult();

  //===================================================================================================
  // Methods
  //===================================================================================================

	void SetSliceCallback( CATSliceCallback iCallback);
	CATSliceCallback GetSliceCallback() const;

  int RunOperator();
  //int Run();

private:

	CATSliceCallback _SliceCallback;

 protected:
  //===================================================================================================
  // // Data
  //===================================================================================================  
  CATLONG32          _NbSlices;
  double                     _Offset;
  ListPOfCATBody    _BodyList;
  double                     _PlaneEquation[4];
  CATBody*              _ResultBody;
  //CATTopData*        _TopData; 
  CATCGMJournalList * _Journal;

//public:
//
//  static const CATString *GetDefaultOperatorId() { return &_OperatorId; }
//  CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
//
//protected :
//
//  static CATString   _OperatorId;
//  const  CATString  *GetOperatorId();

  //===================================================================================================
  // Methodes pour le CGMReplay (dupliquees, elles existent identiques dans CATTopSewSkinImpl)
  //===================================================================================================

public:

  ////CATCXBody * GetRunBodyForReplay() {return _RunBody;}
  //    CATCGMJournalList * GetRunJournalForReplay() {return _RunJournal;}
  //    CATCXBody * GetSkinBodyForReplay() {return _SkinBody;}
  //    CATCXBody * GetTrimmingBodyForReplay() {return _TrimmingBody;}
  //    CATSubdBoolean GetSimplificationForReplay() {return _Simplification;}
  //    CATSubdBoolean GetNoGeometricProjectionForReplay() {return _NoGeometricProjection;}
      int GetNbSlices() {return _NbSlices;}
      double  GetOffset() {return _Offset;}
      void GetPlaneEquation( double & A, double & B , double & C, double & D);
      ListPOfCATBody  *GetBodyList() {return &_BodyList;}

       void SetCheckJournal(CATBoolean iCheckMode);


  static const CATString *GetDefaultOperatorId() { return &_OperatorId; }
  CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);

protected :

  static CATString   _OperatorId;
  const  CATString  *GetOperatorId();
  CATBoolean _CheckJournal;

 //virtual CATBody * GetResult(CATCGMJournalList * ioJournal) = 0;
 //virtual CATBody * GetResult() = 0;

//private:

  //static CATString _OperatorId;
};
#endif

/* -*-C++-*- */

#ifndef CATCVMGeoOperator_H
#define CATCVMGeoOperator_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoOperator
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June 2006    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATTopOperator.h"
#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCVMBody.h"
#include "CATCVMDef.h"

class CATCVMGeoContainer;
class CATTopData;
class CATCVMGeoOperatorExt;
class CATCVMLog;
class CATCGMJournalList;
class CATCVMGeoOpDiag;
class CATCVMGeoCheckup;

class ExportedByCATCVMGeoOperators CATCVMGeoOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATCVMGeoOperator);
  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoOperator(CATCVMGeoContainer   *iCVMGeoContainer,
                    CATTopData           *iTopData,
                    CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoOperator(CATTopData           *iTopData,
                    CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoOperator();

  //------------------------------------------------------------------------------
  // Safe run
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT RunSafe();

  //------------------------------------------------------------------------------
  // Get the diagnostic
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMGeoOpDiag *GetDiag();

  //------------------------------------------------------------------------------
  // Use GetDiag method instead!
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean GetOutOfScaleFailure();

  //------------------------------------------------------------------------------
  // Get the CVM objects that are been Logged during the run 
  // Please note: this must be called after the Run method
  //
  // oCVMBodyList.Size(N)   for N CVMBody including Logged CVMBObjects, 
  //        one may be NULL for extra CVMObject such as CVMInstance or CVMReference 
  //
  // oCVMObjectNumber.Size(3*N) 
  //        with  oCVMObjectNumber (1,i)  = Number of CreatedCVMObject  for  oCVMBodyList[i]
  //        with  oCVMObjectNumber (2,i)  = Number of ModifiedCVMObject for  oCVMBodyList[i]
  //        with  oCVMObjectNumber (3,i)  = Number of ReleasedCVMObject for  oCVMBodyList[i]
  //
  //   Note: if oCVMBodyList[i] is fully deleted, oCVMObjectNumber (j,i) = (0,0,1) 
  //
  // oCVMObjectList.Size(P)  P = sum((oCVMObjectNumber(j,k);j=1,3);k=1,N)  
  //     Structure:
  //                CreatedCVMObjectList  !                   
  //                ModifiedCVMObjectList ! for oCVMBodyList[1]
  //                ReleasedCVMObjectList !   
  //                .....................................
  //                CreatedCVMObjectList  !                   
  //                ModifiedCVMObjectList ! for oCVMBodyList[i]
  //                ReleasedCVMObjectList !   
  //                .....................................
  //                CreatedCVMObjectList  !                   
  //                ModifiedCVMObjectList ! for oCVMBodyList[N]
  //                ReleasedCVMObjectList !   
  //
  //   Note: if oCVMBodyList[i] is fully modified, oCVMObjectList (p) = NULL 
  //         p = sum((oCVMObjectNumber(j,k);j=1,3);k=1,i)   
  //         with
  //               oCVMObjectNumber(1,i)=0
  //               oCVMObjectNumber(2,i)=1
  //               oCVMObjectNumber(3,i)=0
  //
  //  example 
  /*
  int idxBody=0;
  int idxNumber=0;
  int idxObject=0;
  
  int nbCVMBody=CVMBodyIndex.Size();
  
  ListPOfCATCVMObject CVMCreatedGeometry;
  ListPOfCATCVMObject CVMModifiedGeometry;
  ListPOfCATCVMObject CVMReleasedGeometry;
  // Loop sur les bodies uniquement
  while (idxBody<nbCVMBody)
  {
    CATCVMBody * CVMBody=oCVMBodyList[++idxBody];
    
    int nbCVMObject=0;
    
    CATBoolean BodyIsCreated=FALSE;
    CATBoolean BodyIsModified=FALSE;
    CATBoolean BodyIsReleased=FALSE;
      
    ListPOfCATCVMObject CVMCreatedGeometry;
    ListPOfCATCVMObject CVMModifiedGeometry;
    ListPOfCATCVMObject CVMReleasedGeometry;
   
    nbCVMObject=oCVMObjectNumber[++idxNumber]; // number of created Object for this CVMBody
    CVMCreatedGeometry.Size(0);
    while (nbCVMObject-->0)
    {
      int idx=CVMGeometryIndex[++idxGeometry];
      CATCVMObject * CVMObject=oCVMObjectList[++idxObject];
      if (CVMObject)
        CVMCreatedGeometry.Append(CVMObject);
      else
        BodyIsCreated=TRUE;  
    }
    
    nbCVMObject=oCVMObjectNumber[++idxNumber]; // number of modified Object for this CVMBody
    CVMModifiedGeometry.Size(0);
    while (nbCVMObject-->0)
    {
      int idx=CVMGeometryIndex[++idxGeometry];
      CATCVMObject * CVMObject=oCVMObjectList[++idxObject];
      if (CVMObject)
        CVMModifiedGeometry.Append(CVMObject);
      else
        BodyIsModified=TRUE;  
    }
    
    nbCVMObject=oCVMObjectNumber[++idxNumber]; // number of released Object for this CVMBody
    CVMReleasedGeometry.Size(0);
    while (nbCVMObject-->0)
    {
      int idx=CVMGeometryIndex[++idxGeometry];
      CATCVMObject * CVMObject=oCVMObjectList[++idxObject];
      if (CVMObject)
        CVMReleasedGeometry.Append(CVMObject);
      else
        BodyIsReleased=TRUE;  
    }
    
    // Your treatment
    if (NULL==CVMBody) continue;   // if only CVMObjects belonging to a CVMBody are treated 
    .................................
    .................................
    // End of your treatment  
  }
  // End of example
  */
  //------------------------------------------------------------------------------
  public:
  void GetLoggedCVMObjects(ListPOfCATCVMBody &oCVMBodyList, CATListOfInt &oCVMObjectNumber, ListPOfCATCVMObject &oCVMObjectList);
  
  //------------------------------------------------------------------------------
  // Get the new CVM objects
  // Deprecated 
  // Please note: this must be called after the Run method
  //------------------------------------------------------------------------------
  public:
  void GetNewCVMObjects(ListPOfCATCVMObject &oNewObjectList, CATCVMObjectType iType = CATCVMAtomType);

/**
 *@nodoc
 *DO NOT CALL
 */
  void SetLog(CATCVMLog *iCVMLog);
  CATCGMJournalList *GetJournalList(CATBoolean iSurrenderJournalList = FALSE);
  virtual int  RunOperator();
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  void WriteInput(CATCGMStream  & ioStream);
  //    void RequireDefinitionOfInputAndOutputObjects();
  void Dump(CATCGMOutput& os);
  void SetNoInputObjects();
  CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

  public:
  void WriteOutput(CATCGMStream & ioStream);
  CATBoolean ValidateOutput(CATCGMStream & iRefStream,
                            CATCGMOutput & os,
                            int            VersionNumber=1);
  CATBoolean ValidateTopOutput(CATTopCheckJournal * iEquivalent,
                               CATCGMOutput       & os);
  CATBody *GetCVMTopOutput();

  public:
  void SetResultForCGMReplay(CATBody *iCGMBody);

  private:
    /**
    *This method is called internally after Run if the Run was successful.
    *If the property _Dirtify is true (default), then the container is marked as dirty
    *If the property _Dirtify is false, then nothing is done
    *Operators that do not dirtify must set _Dirtify to false
    */
    virtual CATBoolean Checkup(CATBoolean iOutput);
    virtual void UpdateContainerDirtyState();
    CATBoolean IsUndoRedoAllowed();

  public :
      virtual void SetCGMReplaySession ();
      void SetDataFileName (CATUnicodeString &iFilepath);
      void GetDataFileName (CATUnicodeString &oFilepath);

  protected:
  
	  CATLONG32  _Dirtify;
	  CATBoolean _CheckupOutputFailed;
	  CATBoolean _CheckupInputFailed;
	  CATBoolean _CGMModification;

    CATCVMGeoCheckup *_Checkup;
  
    static int _CallRecursivityLevel;
};
#endif

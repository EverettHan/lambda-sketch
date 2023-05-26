// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//===================================================================
//
// CATGMJournalProliferationOpe.cpp
// Header definition of CATGMJournalProliferationOpe
//
//===================================================================

//===================================================================
//  Jan 2023
//  VB7
//
//  Inputs  :
//   From DOCO 
//    - CATTopData     & iTopData,        // the topdata contains the Journal of previous operator
//    - ListPOfCATBody & iInputBodyList,  // toDisconnect Body (must be the first element) + disconnectingBodies
//    - CATBody        & iResultBodyOfInputJournal);
//   From other operators
//    - CATTopData     & iTopData,        // the topdata contains the Journal of previous operator
//    - ListPOfCATBody & iInputCopyBodyList,
//    - ListPOfCATBody & iInputNoCopyBodyList,
//    - CATBody        & iResultBodyOfInputJournal);
//  Outputs :
//    - Updated journal
//    - Updated Body
//  Purpose :
//    Proliferation of info data through cells of same group.
//
//===================================================================

#ifndef CATGMJournalProliferationOpe_H
#define CATGMJournalProliferationOpe_H

#include "CATTopOperator.h"
#include "PersistentCell.h"
#include "ListPOfCATBody.h"

class CATTopData;
class CATBody;
class CATCGMStream;
class CATCGMOutput;
class CATCell;
class CATGeoFactory;
class CATGMJournalProliferationImpl;

class ExportedByPersistentCell CATGMJournalProliferationOpe : public CATTopOperator
{
   
  CATCGMVirtualDeclareClass(CATGMJournalProliferationOpe);

public:

  //==============================================================================
  // Constructor 
  //==============================================================================
  CATGMJournalProliferationOpe(CATGeoFactory * iFactory,  CATTopData * iTopData, CATGMJournalProliferationImpl * iImp);

  //==============================================================================
  // Destructor 
  //==============================================================================
  virtual ~CATGMJournalProliferationOpe();

  //==============================================================================
  // Set method 
  //==============================================================================
  void SetSiblingCellGroupOnInputBody(CATBody & iInputBody, ListPOfCATCell & iSiblingCellGroup);

  //==============================================================================
  //
  // CGMREPLAY METHODES
  //
  //==============================================================================
  /** @nodoc @nocgmitf */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nodoc @nocgmitf */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();
  /** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId();
  /** @nodoc @nocgmitf */
  void DumpOutput(CATCGMOutput &os);
  /** @nodoc @nocgmitf */
  virtual void WriteInput(CATCGMStream  & os);
  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short & oNumReplayVersion);
  /** @nodoc @nocgmitf */
  virtual void Dump( CATCGMOutput& os ) ;

  //==============================================================================
  // Run 
  //==============================================================================
  /** @nodoc @nocgmitf */
  virtual int RunOperator();

protected:
  CATGMJournalProliferationImpl * GetCATGMJournalProliferationImpl() const;

};

//==============================================================================
// CATCreateJournalProliferationOpe for DOCO only
//==============================================================================
ExportedByPersistentCell CATGMJournalProliferationOpe * CATCreateJournalProliferationOpe(
  CATTopData     & iTopData,        // the topdata contains the Journal of previous operator
  ListPOfCATBody & iInputBodyList,  // toDisconnect Body (must be the first element) + disconnectingBodies
  CATBody        & iResultBodyOfInputJournal);

//==============================================================================
// CATCreateJournalProliferationOpe
//==============================================================================
ExportedByPersistentCell CATGMJournalProliferationOpe * CATCreateJournalProliferationOpe(
  CATTopData     & iTopData,        // the topdata contains the Journal of previous operator
  ListPOfCATBody & iInputCopyBodyList,
  ListPOfCATBody & iInputNoCopyBodyList,
  CATBody        & iResultBodyOfInputJournal);


#endif


#ifndef CATIPGMJournalProliferationOpe_h_
#define CATIPGMJournalProliferationOpe_h_

// COPYRIGHT DASSAULT SYSTEMES 2023

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopOperator.h"

class CATBody;
class CATCGMOutput;
class CATCGMStream;
class CATCell;
class CATGMJournalProliferationImpl;
class CATGeoFactory;
class CATTopData;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMJournalProliferationOpe;

class ExportedByCATGMOperatorsInterfaces CATIPGMJournalProliferationOpe: public CATIPGMTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMJournalProliferationOpe();

  //==============================================================================
  // Set method 
  //==============================================================================
  virtual void SetSiblingCellGroupOnInputBody(
    CATBody &iInputBody,
    CATLISTP(CATCell) &iSiblingCellGroup) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMJournalProliferationOpe(); // -> delete can't be called
};

//==============================================================================
// CATCreateJournalProliferationOpe for DOCO only
//==============================================================================
ExportedByCATGMOperatorsInterfaces CATIPGMJournalProliferationOpe *CATPGMCreateJournalProliferationOpe(
  CATTopData &iTopData,
  CATLISTP(CATBody) &iInputBodyList,
  CATBody &iResultBodyOfInputJournal);

//==============================================================================
// CATCreateJournalProliferationOpe
//==============================================================================
ExportedByCATGMOperatorsInterfaces CATIPGMJournalProliferationOpe *CATPGMCreateJournalProliferationOpe(
  CATTopData &iTopData,
  CATLISTP(CATBody) &iInputCopyBodyList,
  CATLISTP(CATBody) &iInputNoCopyBodyList,
  CATBody &iResultBodyOfInputJournal);

#endif /* CATIPGMJournalProliferationOpe_h_ */

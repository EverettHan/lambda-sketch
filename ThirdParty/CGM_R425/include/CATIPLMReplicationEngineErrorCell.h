
// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMReplicationEngineErrorCell.h
// Define the CATIPLMReplicationEngineErrorCell interface
//
//===================================================================
//
//===================================================================
/**
* @level Protected
* @usage U3
*/


#ifndef CATIPLMReplicationEngineErrorCell_H
#define CATIPLMReplicationEngineErrorCell_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMErrorCell.h"
#include "CATCollec.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMReplicationEngineErrorCell;
#else
extern "C" const IID IID_CATIPLMReplicationEngineErrorCell ;
#endif

class CATLISTV(CATPLMID);

//------------------------------------------------------------------

/**
 * This interface is dedicated to describe an replication-engine error.
 * It can be obtained from error-cell objets returned by the replication-engine.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMReplicationEngineErrorCell: public CATIPLMErrorCell
{
  CATDeclareInterface;

public:
  

  /**
  * Returns the PLM components associated to the error, if existing
  * @param oCompIds
  *    The PLMIDs on which the error happend, if the error is relative to a particular PLM components. 
  *    Empty list in case of an error not relative to a PLM component (global error).
  */
  virtual HRESULT GetComponents (CATLISTV(CATPLMID) &  oCompIds)=0;
  

};

//------------------------------------------------------------------

#endif

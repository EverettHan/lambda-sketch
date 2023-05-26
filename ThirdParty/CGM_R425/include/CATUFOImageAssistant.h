#ifndef CATUFOImageAssistant_H
#define CATUFOImageAssistant_H

/**
* @level Private
* @usage U1       
*/

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATUFODiffLogInformation;

class ExportedByCATPLMTos CATUFOImageAssistant
{
public:

  ////////////////////////////////////////////////////////////
  //              CONSTRUCTOR / DESTRUCTOR                  //
  ////////////////////////////////////////////////////////////

  CATUFOImageAssistant();
  virtual ~CATUFOImageAssistant();

  /**
  * Size of the UFO image
  *
  * @return
  *   the size
  */
  int Size();

  /*
  * Merge two diff logs
  *
  * @param iDiffLogToMerge
  *   the diff log to merge
  *
  * @return
  *   S_OK if success
  *   E_FAIL otherwise
  */
  HRESULT Merge(CATUFODiffLogInformation & iDiffLogToMerge);

private:
  friend class CATOxMemUFO;

  CATUFODiffLogInformation * GetDiffLogInformation();

  // Forbidden operators 
  CATUFOImageAssistant (CATUFOImageAssistant&);
  CATUFOImageAssistant& operator=(CATUFOImageAssistant&);

  // letter
  CATUFODiffLogInformation  * _impl;

};

#endif

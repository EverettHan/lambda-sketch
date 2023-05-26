// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef CATOmbDocumentTransaction_H
#define CATOmbDocumentTransaction_H

/**
 * @level Private
 * @usage U1
 */

#include <time.h>

#include "AC0XXLNK.h"
#include "IUnknown.h" // for HResult
#include "CATIContainer.h"
#include "CATUuid.h"
#include "CATOmxSharable.h"

/**
 * This object is in charge 
 *
 */
class CATUnicodeString;
class ExportedByAC0XXLNK CATOmbDocumentTransaction: public CATOmxSharable
{
public :
  CATOmbDocumentTransaction() ;
  ~CATOmbDocumentTransaction();
  HRESULT ContainerHasBeenSaved(CATIContainer_var iContainer) ;
  HRESULT LastTimeModificationOfDocument(time_t& oTimeOfModification) ;
private :
  time_t lastTimeApplicativeModification ;

} ; 


#endif 

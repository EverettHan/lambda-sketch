#ifndef CATPLMTosInternalError_h
#define CATPLMTosInternalError_h
/**
* @COPYRIGHT DASSAULT SYSTEMES 2004
* ----------------------------------------------------------------------------------------------------------------------
*   Origin         : Physical Layer Software Component for local running of remote persistency entity 
*   Specification  : internal small implementation 
*   Remarks : for more detailled specification (UML sequence diagram, statechart, ..)  consult associated Lotus Database 
* ----------------------------------------------------------------------------------------------------------------------
*/
#include "CATPLMIdentificationAccess.h"
#include "CATErrors.h"
#include "CATInternalError.h"

// definition du fichier de message
#ifndef PLMTosIntFile
#define PLMTosIntFile "CATPLMTos"
#endif


class ExportedByCATPLMIdentificationAccess CATPLMTosInternalError : public CATInternalError
{
  public:

    CATDeclareError(CATPLMTosInternalError, CATInternalError)
};



#endif

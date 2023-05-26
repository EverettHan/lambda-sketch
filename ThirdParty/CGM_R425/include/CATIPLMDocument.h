/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
#ifndef CATIPLMDocument_H
#define CATIPLMDocument_H

/**
 * @level Private
 * @usage U1
 */
 // COPYRIGHT Dassault Systemes 2004


#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"
#include "CATOmxDeprecated.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentification IID IID_CATIPLMDocument;
#else
extern "C" const IID IID_CATIPLMDocument;
#endif

//------------------------------------------------------------------

/** R201 obsolete */
class ExportedByCATPLMIdentification CATIPLMDocument : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  enum PersistencyMode
  {
    NotDefined = 0,
    VolatileExposed = 4
  };
  /** does nothing */
  OMX_DEPRECATED("meaningless, not implemented") inline void SetPersistencyMode(CATIPLMDocument::PersistencyMode) {}

  /** meaningless */
  virtual HRESULT GetPersistencyMode(CATIPLMDocument::PersistencyMode * oMode) = 0;
};

CATDeclareHandler(CATIPLMDocument, CATBaseUnknown);
//------------------------------------------------------------------

#endif

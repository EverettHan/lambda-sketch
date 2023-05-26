//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATPLMMLEngineFactorySimplePush.h
//  Define the CATPLMMLEngineFactorySimplePush interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Execution of a navigation described using Modeler language (ML) grammar 
// and creation of a table containing datas extracted from database.
//
// Grammar of this language is described in a wiki:
// http://osmwebdsy/wiki/index.php/1-Modeler_Language:_Navigation
//
// Factory used to retrieve a handler on CATIPLMMLEngine
// WE USE RETURN A SMART POINTER TO REDUCE THE RISK OF LEAKS
// PLEASE USE SMART POINTER WHEN YOU USE CATIPLMMLEngine INTERFACE
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 


#ifndef CATPLMMLEngineFactorySimplePush_H
#define CATPLMMLEngineFactorySimplePush_H


#include "CATPLMModelerLanguageRestricted.h"

#include "CATSysErrorDef.h"// SpecialAPI PublicInterfaces HRESULT

class CATIPLMMLEngineSimplePush_var;

class ExportedByCATPLMModelerLanguage CATPLMMLEngineFactorySimplePush
{
public:
  static HRESULT Create(CATIPLMMLEngineSimplePush_var& ospEngine);

};


#endif

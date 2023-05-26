//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATPLMMLEngineFactorySimple.h
//  Define the CATPLMMLEngineFactorySimple interface
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


#ifndef CATPLMMLEngineFactorySimple_H
#define CATPLMMLEngineFactorySimple_H


#include "CATPLMModelerLanguageRestricted.h"

#include "CATSysErrorDef.h"// SpecialAPI PublicInterfaces HRESULT

class CATIPLMMLEngineSimple_var;

class ExportedByCATPLMModelerLanguage CATPLMMLEngineFactorySimple
{
public:
  static HRESULT Create(CATIPLMMLEngineSimple_var& ospEngine);

};


#endif

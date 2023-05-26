//===================================================================
// COPYRIGHT  Dassault  Systemes  2014
//===================================================================
//
//  CATIPLMMLEngineAsyncSimple.h
//  Define  the  CATIPLMMLEngineAsyncSimple  interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Execution of a navigation described using Modeler language (ML) grammar 
// and creation of a table containing datas extracted from database.
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 


#ifndef CATIPLMMLEngineAsyncSimple_H
#define CATIPLMMLEngineAsyncSimple_H

#include "CATUnicodeString.h"          // System PublicInterfaces
#include "CATBaseUnknown.h"            // CATPLMModelerLanguage ProtectedInterfaces

#include "CATPLMModelerLanguageSimpleRestricted.h"                // CATPLMModelerLanguage ProtectedInterfaces

class CATPLMMLOptionsSimple;
class CATError;
class CATPLMMLEngineParametersSimple;
class CATIPLMMLEngineAsyncSimpleTaskCB;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerLanguage IID IID_CATIPLMMLEngineAsyncSimple;
#else
extern "C" const IID IID_CATIPLMMLEngineAsyncSimple ;
#endif

class ExportedByCATPLMModelerLanguage CATIPLMMLEngineAsyncSimple : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  
  /**
  * <br><b>Role</b>: Validation of the input string value passed as argument regarding Modeler language grammar.
  *
  * @param iFileNameWithoutExtensionName
  *  We should find this file in <your Fw>\resources\ML. You should promote your file in <Your Fw>\resources\ML.
  *  DON T FORGET TO DO mkrtv!!!!!!!!!!
  *  Name of the file containing the description of the ML without the extension ".ml".
  * @param iOptions
  *  engine options
  * @param opError out. 
  *  Don't forget to delete this pointer if necessary.
  *  Don't do new CATError...we do it for you if necessary.
  *  error describing which rule of Modeler language grammar has been violated.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT Init( const CATPLMMLOptionsSimple& iOptions,
                        const CATUnicodeString& iFileNameWithoutExtensionName,
                        CATError* & opError ) = 0;

  /**
  * <br><b>Role</b>: Execution of the navigation.
  * @param iParam
  *  Object containing roots of the navigation (instantiated model level)
  *  Different custo added on each node of the navigation (custo used to filter or enrich existing node).
  * @param opError [out,CATBaseUnknown#Release]
  *  Don't do new CATError...we do it for you if necessary.
  *  Error describing the problem during the execution of the query or during the the table build.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT Execute(  const CATPLMMLEngineParametersSimple& iParam,
                            CATIPLMMLEngineAsyncSimpleTaskCB* ipCallBack,
                            CATError*& opError ) = 0;

};

CATDeclareHandler( CATIPLMMLEngineAsyncSimple, CATBaseUnknown );

#endif

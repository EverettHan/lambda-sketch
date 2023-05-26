//===================================================================
// COPYRIGHT  Dassault  Systemes  2012
//===================================================================
//
//  CATIPLMMLEngineSimplePush.h
//  Define  the  CATIPLMMLEngineSimplePush  interface
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
// July 2012    Creation:  EPB
//=================================================================== 


#ifndef CATIPLMMLEngineSimplePush_H
#define CATIPLMMLEngineSimplePush_H

#include "CATUnicodeString.h"               // System PublicInterfaces
#include "CATBaseUnknown.h"            

#include "CATPLMModelerLanguageSimplePushRestricted.h"                // CATPLMModelerLanguage ProtectedInterfaces

#include "CATPLMMLOptionsSimple.h"                // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLEngineParametersSimple.h"       // CATPLMModelerLanguage ProtectedInterfaces

class CATError;
class CATIPLMExpandResultHandler;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerLanguage IID IID_CATIPLMMLEngineSimplePush;
#else
extern "C" const IID IID_CATIPLMMLEngineSimplePush ;
#endif

class ExportedByCATPLMModelerLanguage CATIPLMMLEngineSimplePush : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  
  /**
  * <br><b>Role</b>: Validation of the input string value passed as argument regarding Modeler language grammar.
  *
  * @param iFileNameWithoutExtensionName
  *  We should find this file in <OS>\resources\ML. You should promote your file in <Your Fw>\resources\ML.
  *  DON T FORGET TO DO mkrtv!!!!!!!!!!
  *  Name of the file containing the description of the ML.
  * @param iOptions
  *  engine options
  * @param opError [out,CATBaseUnknown#Release]
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
                            CATIPLMExpandResultHandler* iopResult,
                            CATError*& opError) = 0;


};

CATDeclareHandler( CATIPLMMLEngineSimplePush, CATBaseUnknown );

#endif

//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATIPLMMLEngineSimpleRestricted.h
//  Define  the  CATIPLMMLEngineSimpleRestricted  interface
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


#ifndef CATIPLMMLEngineSimpleRestricted_H
#define CATIPLMMLEngineSimpleRestricted_H

#include "CATBaseUnknown.h"

#include "CATPLMModelerLanguageSimpleRestricted.h"      // CATPLMModelerLanguage ProtectedInterfaces

class CATUnicodeString;
class CATPLMMLOptionsSimple;
class CATPLMMLEngineParametersSimple;
class CATError;
class CATIPLMCompRecordReadSet;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerLanguage IID IID_CATIPLMMLEngineSimpleRestricted;
#else
extern "C" const IID IID_CATIPLMMLEngineSimpleRestricted ;
#endif

class ExportedByCATPLMModelerLanguage CATIPLMMLEngineSimpleRestricted : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  
  /**
  * <br><b>Role</b>: Validation of the input string value passed as argument regarding Modeler language grammar.
  *
  * @param iInputString
  *  String that contain the description of ML
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
  virtual HRESULT Init( const CATUnicodeString& iInputString,
                        const CATPLMMLOptionsSimple& iOptions,
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
                            CATIPLMCompRecordReadSet*& opRecordSet,
                            CATError*& opError) = 0;


};

CATDeclareHandler( CATIPLMMLEngineSimpleRestricted, CATBaseUnknown );

#endif

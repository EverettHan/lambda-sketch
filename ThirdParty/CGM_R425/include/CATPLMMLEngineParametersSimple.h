//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATPLMMLEngineParametersSimple.h
//  Define  the  CATPLMMLEngineParametersSimple  object
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Modeler language (ML) describes navigation on Modeler level (To sum up, we
// recall that it exists 3 different levels: Core Level, Modeler Level, Custo Level)
// Using the current object, we are able to describe custo(s) to apply on each node of the navigation.
// 2 modes exist: filter with a specific custo or enrich with all custo.
//
// There is a characteristic node in the navigation described using ML grammar:
// The root of the navigation (it is the first element of the navigation) (metamodel level).
// Using the current object, we are able to pass the roots of the navigation (instantiated model level).
//
// difference between CATPLMMLEngineParametersSimple and CATPLMMLParsingOptions:
// CATPLMMLEngineParametersSimple dedicated to manage PLM (custo, plmids, fiter).
// CATPLMMLParsingOptions dedicated to parsing option.
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATPLMMLEngineParametersSimple_H
#define CATPLMMLEngineParametersSimple_H

#include "CATPLMModelerLanguage.h"

#include "CATString.h"            // System ProtectedInterfaces

#include "CATLISTV_CATPLMID.h"    // CATPLMIdentificationAccess ProtectedInterfaces CATPLMIdentifier.m CATPLMIdentificationAccess.dll

#include "CATOmxArray.h"

class CATPLMTypeH;
class CATError;

class ExportedByCATPLMModelerLanguage CATPLMMLEngineParametersSimple
{
public:
  CATPLMMLEngineParametersSimple();
  ~CATPLMMLEngineParametersSimple();

  /**
  * <br><b>Role</b>: Roots of navigation.
  * @param iListOfPLMID
  *   Root of navigation
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  void SetListPlmid(CATLISTV(CATPLMID)& iListOfPLMID);

  CATLISTV(CATPLMID) GetListPlmid() const;

  CATPLMMLEngineParametersSimple (const CATPLMMLEngineParametersSimple &);
  CATPLMMLEngineParametersSimple& operator=(const CATPLMMLEngineParametersSimple&);

private:
  

  friend class CATPLMMLEngineCompAdapter;

  CATLISTV(CATPLMID) _iListOfPLMID;
};

#endif

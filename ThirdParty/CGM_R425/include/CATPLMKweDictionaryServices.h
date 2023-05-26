// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
//  Jan 2005  Creation: LJE
//
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMKweDictionaryServices_H
#define CATPLMKweDictionaryServices_H

#include "CATPLMKweDicoServices.h"

#include "IUnknown.h"
#include "CATVariant.h"
#include "CATBooleanDef.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATICkeParm.h"
#include "CATIType.h"

class VPMIDicMgr;
class VPMIDicClass;
class VPMIDicSimple;
class VPMIDicElement;
class VPMIDicExtension;
class VPMIDicEnum;
class VPMIDicRelationClass;
class CATString;
class CATICkeParm_var;
class CATUnicodeString;
class CATListPtrIUnknown;
class CATListValCATAttributeInfos;
class CATICkeUnit_var;

class ExportedByCATPLMKweDicoServices CATPLMKweDictionaryServices
{
public:
  /**
  * Load Knowledge Dictionary from PLM Dictionary content
  * @return
  *   HRESULT
  *	S_OK if succeded
  *	E_FAIL if failed
  */ 
  static HRESULT LoadKweDictionary();

private:
  static HRESULT Initialize();
  static HRESULT Cleanup();
  static HRESULT CreateERKweRootTypes (const CATIType_var &iDataBaseObjectType);
  static void DumpKweDico();

  static HRESULT AddPropertiesInKweDico ( VPMIDicElement *iElement, const CATIType_var &iKweType );
  static int InheritancePLMEntity_BusinessType ();
  static int InheritanceInstance_RelationType ();
};

//------------------------------------------------------------------

#endif

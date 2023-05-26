//===================================================================
// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATPLMNoInstTypeMappingHelpers
//
//===================================================================
//
// Usage notes:
// This class is a helper for all providers. All providers are impacted by no instance type mapping project.
//
// Small summary:
// Instance ans Rep Instance INHERITS from RelationType and their strong relation are from/to instead of V_Owner/V_InstanceOf
//¨PLMConnection/PLMPort still use V_Owner, they are seen like BusinessType.
// Only one method keeps its old behaviour CATPLMType::IsERType() <=> IsHistoricalERType() (Port, Connection, Ref, RepRef, Inst, Rep, Inst S_FALSE)
// All other methods MUST exposed the behaviour: from/to and right inheritance
//
// PLMAdapter is on from/to with activation of this project
// PLM1, TST, TSTV5 are on from/to with activation of this project. TST/TSTV5 are able to read all datas based on V_Owner/V_InstanceOf...
// Dictionary of TST, TSTV5 and PLM1 are based on from/to with activation of this project
//
// Providers load themselves their own dictionary, they must expose from/to and inheritance between instance/repinstance and RelationType.
// CATPLMType::ListRelations MUST return from/to and not V_Owner/V_InstanceOf for all providers
// If you do something else, you will be BROKEN on adapter layer and/or on TOS layer
// I advice you to contact FRH/CHD or me (EPB) if you encounter issues to retrieve from/to on custo V1 types. PLMProductInstanceDS for example
//
// Remark: Dont forget that dico provided by FRH don't know what are providers....
// It means that if you have a VPMReference on VPMV5 and a VPMReference on PLM1, if you are connected to both providers, VPMReference is an horrible mix of VPMReference coming from VPMV5 and PLM1...
// So you have no choice. You MUST provide a view of instance/repinstance on your own provider based on from/to. CATPLMType::ListRelations MUST return from/to.
// If you don't do that, we could have an instance with V_Owner/V_InstanceOf/from/to when you are connected to more than one provider...and the nightmare should begin...
// if internally, in layer dedicated to your provider, you want to use V_Owner/V_InstanceOF, you have to do the mapping. Your layer is still your own Business but not what is exposed by your layer...
//
// Again I repeat, in the specific code dedicated to the provider, you can still keep and use V_Owner/V_InstanceOf.
// Don't forget that all adapter methods will call you with from/to. 
// This class provides method to do mapping between NEW naming of strongs relation (from/to) and OLD naming of strong relations (V_Owner/V_InstanceOf)
//
// How can I switch in my code?
// Please use the method:
// if(CATUnicornLevel::InstanceTypeMappingSuppressed()==TRUE)
//
// If your convergence becomes a nightmare, don't hesitate to contact me and pray a bit...
//===================================================================
// August 2015  Creation: EPB
//===================================================================

#ifndef CATPLMNoInstTypeMappingHelpers_H
#define CATPLMNoInstTypeMappingHelpers_H

#include "CATPLMImplAdapterBase.h"

#include "CATSysErrorDef.h"

class CATPLMType;
class CATPLMID;
class CATUnicodeString;
class CATString;

class ExportedByCATPLMImplAdapterBase CATPLMNoInstTypeMappingHelpers
{
public:
  static HRESULT ReplaceV_OwnerAndV_InstanceOfByFromAndToIfNeeded(const CATPLMID& iPlmid,CATUnicodeString& ioStrongRel);

  static HRESULT ReplaceV_OwnerAndV_InstanceOfByFromAndToIfNeeded(const CATPLMID& iPlmid,CATString& ioStrongRel);

  static HRESULT ReplaceV_OwnerAndV_InstanceOfByFromAndToIfNeeded(CATPLMType* ipType,CATUnicodeString& ioStrongRel);

  static HRESULT ReplaceV_OwnerAndV_InstanceOfByFromAndToIfNeeded(CATPLMType* ipType,CATString& ioStrongRel);

  static HRESULT ReplaceFromAndToByV_OwnerAndV_InstanceOfIfNeeded(const CATPLMID& iPlmid,CATUnicodeString& ioStrongRel);

  static HRESULT ReplaceFromAndToByV_OwnerAndV_InstanceOfIfNeeded(const CATPLMID& iPlmid,CATString& ioStrongRel);

  static HRESULT ReplaceFromAndToByV_OwnerAndV_InstanceOfIfNeeded(CATPLMType* ipType,CATUnicodeString& ioStrongRel);

  static HRESULT ReplaceFromAndToByV_OwnerAndV_InstanceOfIfNeeded(CATPLMType* ipType,CATString& ioStrongRel);

  // Need to provide a method to retrieve from/to on V1 Type. Indeed those types inherited from old typing mode are still class (et c'est vraiment pas joli-joli)
  // Need to provide and optimized way to compute that...
  //CATUnicodeString coreTypeName;
  //iVClass.GetPLMCoreTypeName (coreTypeName);

  //CATOmxList<VPMIDicRelationship> relations;
  //if (CATUnicornLevel::InstanceTypeMappingSuppressed()==TRUE && iVClass.IsCusto() && !iVClass.IsSpecialization() 
  //  && (coreTypeName==CATPLMDicCstDef::s().PLMCoreInstance || coreTypeName==CATPLMDicCstDef::s().PLMCoreRepInstance))
  //{
  //  VPMIDicGenericClass_var spGenericClass=&iVClass,spSuperGenericClass=NULL_var;
  //  while(SUCCEEDED(spGenericClass->GetSuperGenericClass (spSuperGenericClass)) && spSuperGenericClass!=NULL_var)
  //  {
  //    CATString superName;
  //    spSuperGenericClass->GetName(&superName);
  //    CATOmxKeyString ksSuperName(superName);
  //    if(ksSuperName==CATPLMDicCstDef::s().ksPLMInstance)
  //    {
  //      // I catch from/to with PLMInstance
  //      VPMIDicRelationClass_var spRelClass(spSuperGenericClass);
  //      CHK_AND_RET_HR(spRelClass);
  //      VPMIDicRelationClass* pRelClass=spRelClass;
  //      CHK_SUCCESS_AND_RET_HR(CATPLMxMetaDataRelationsProcessor::_ProcessClass(*pRelClass,pSourceType));
  //      break;
  //    }
  //    spGenericClass=spSuperGenericClass;
  //    spSuperGenericClass=NULL_var;
  //  }
  //}


};

#endif

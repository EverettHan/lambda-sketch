//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATIPLMMLEngine.h
//  Define  the  CATIPLMMLEngine  interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
// At this step, you have described a navigation using Modeler Language (ML)
// Using method HRESULT CATIPLMMLEngine::ListNode(CATLISTV(CATPLMMLNodeInfo)& oListAlias),
// you can retrieve informations on nodes used to describe navigation.
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATPLMMLNodeInfo_H
#define CATPLMMLNodeInfo_H

#include "CATPLMModelerLanguage.h"

#include "CATSysErrorDef.h"
#include "CATBooleanDef.h"
#include "CATOmxArray.h"
#include "CATOmxOSet.h"
#include "CATString.h"
#include "CATOmxSR.h"

class CATIPLMMLDicoNavNode;
class CATPLMTypeH;
class CATIPLMMLDicoAlias;

class ExportedByCATPLMModelerLanguage CATPLMMLNodeInfo
{
  friend class CATPLMMLNodeInfoIterator;

public:

CATPLMMLNodeInfo();

CATPLMMLNodeInfo(const CATPLMMLNodeInfo& obj);

~CATPLMMLNodeInfo();

CATPLMMLNodeInfo& operator=(const CATPLMMLNodeInfo& copy);

/**
* Name of node used to describe navigation.
* <br><b>Role</b>: Name of node used to describe navigation.
*/
CATString GetAlias() const;


/**
* Type of node used to describe navigation.
*
* <br><b>Role</b>: Type of node used to describe navigation.
* Type declared in Modeler Language is returned (DS type). Custo type is not returned.
*
* @param oTypeH
* type of node.
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT GetType(CATPLMTypeH& oTypeH) const;

/*
* iterator giving Alias+Attributes in Modeler Language (ML).
* <br><b>Role</b>: iterator giving Alias+Attributes in Modeler Language (ML).
* Today, custo level not returned.
* We return attribute found in [COLUMNS] and [INTERNALCOLUMNS].
*
* ORDER CAN CHANGE AT ANY TIME!
* ORDER CAN CHANGE AT ANY TIME!
* ORDER CAN CHANGE AT ANY TIME!
* 
* @param oKey
* aliasOrTypeName.iAttr
* aliasOrTypeName.Ext(iObjExtType).iAttr
*
* <dt><code>S_OK</code><dd>
* <dt><code>E_FAIL</code>end of iterator reached E_FAIL and oKey==""<dd>
*/
HRESULT Next(CATString& oKey);

/*
* iterator giving access to attr declared in Modeler Language (ML)
* <br><b>Role</b>: iterator giving access to attr declared in Modeler Language (ML)
* Today, custo level not returned.
* We return attribute found in [COLUMNS] and [INTERNALCOLUMNS].
* 
* ORDER CAN CHANGE AT ANY TIME!
* ORDER CAN CHANGE AT ANY TIME!
* ORDER CAN CHANGE AT ANY TIME!
* 
* @param oTypeNameExt
* empty if no extension
* @param oAttr
* name of Attr
*
* <dt><code>S_OK</code><dd>
* <dt><code>E_FAIL</code>end of iterator reached E_FAIL and oKey==""<dd>
*/
HRESULT Next(CATPLMTypeH& oTypeExtH,CATString& oAttr);

CATBoolean IsLeaf();

// restart at the beginning
void ResetKey();

void ResetAttr();

private:

HRESULT Init(CATIPLMMLDicoNavNode* ipNode,CATBoolean isLeaf);

HRESULT _InitAttr( CATIPLMMLDicoAlias* ipAlias);

int _PosKey;
int _PosAttr;
CATIPLMMLDicoNavNode* _pNode;
CATBoolean _isLeaf;
CATBoolean _IsInitAttrCalled;
CATOmxArray<CATString> _lAttr;
CATOmxArray<CATString> _lTypeNameExt;
CATString _alias;
CATOmxSR<CATIPLMMLDicoAlias> _spAlias;

};

#endif

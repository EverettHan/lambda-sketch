#ifndef CATIPLMLogState_H
#define CATIPLMLogState_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/*
* @COPYRIGHT DASSAULT SYSTEMES 2004
* ----------------------------------------------------------------------------------------------------------------------
*   Origin              : Local running (inside wintop) of remote persistency entity
*                            associative kernel change/data set of ... actors ...
*                            made as simple as possible to be affordable for enhanced infrastructure integration
*   Software's Category : Physical Layer (Middleware services) dedicated to client side
*                            (in a kind of software classification similar to the layered OSI Network
*                             upper (logical) Layer is mainly about two main axis  (
*                                  Modeler (domain) specialisation (for Data and Attributes ...)
*                                  Upper Levering Operand Integration exchange (QEOPS,
*   Premilinary         : Do not forget to contact your Database Administrators or any other representative
*                            (Authoring definition) for more convenient support
*                          (Just to be sure that appropriate schema (Table for Data , or Services) are supported
*                              when reference persistency occured when dealing with local work realized  )
*   Specification       : Simple genuine (re-usable) services about
*                            - associativity between local insulated implementation and shared remote repository
*                            - synthetic change set (persistency intents)
*   Limitations         : No attributes vocabulary provided to let this current functional component software
*                              be as comprehensible in specifications
*                         Status is slaved to Modelers deployement and Behaviors
*                             for more detailled specification (UML sequence diagram, statechart, ..)
*                             consult specialized specifications database relative to upper Logical Software layer
*                             it means Product Structure Legacy, PLM Client Core, Representation Model
*   Favorites entry-point for developpers :
*                         CATPLMRepositoryName : Repository classification
*                         CATProxySpace   : Instance of a domain resolution
*                         CATComponentId  : Handle on primary associativity between local and remote entity
* ------------------ ----------------------------------------------------------------------------------------------------
*//**
 * @level Private
 * @usage U3
 */

#include "ExportedByCATPLMIdentification.h"
#include "CATPLMTypeH.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATDataType.h"
class CATComponentId;

#include "CATAdpCodOp.h"
#include "CATAdpMetaData.h"
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentification IID IID_CATIPLMLogState;
#else
extern "C" const IID IID_CATIPLMLogState;
#endif

/**
 * This class has elementary item of LOG analysis
 */

class ExportedByCATPLMIdentification CATIPLMLogState : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  *  Query if the LOG Status is defined
  *
  * @return
  *      S_OK if Log Status is defined <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT IsLogStatusDefined() const = 0;

  /**
  *  Access to status LOG
  *
  * @param oStatus
  *        Log status
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT GetStatus(CATPLMLogStatus & oStatus) const = 0;

  /**
  *  Access to the associated Object associated to the LOG state
  *
  * @param oHandle
  *   Handle on Component that may be present or not
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT GetComponentId(CATComponentId & oHandle) const = 0;

  /**
  *  Query if the LOG Modification Status is modified (Based on explicite & implicite logging)
  *
  * @param iModificationType
  *   kind of modification
  *
  * @param iAppData
  *   Attribute (to be used only id modificationType is UserAttribute)
  *
  * @return
  *      S_OK    if Log Modification Status is modified as asked in Input<br>
  *      S_FALSE if Log Modification Status is not modified like asked<br>
  *      E_FAIL if request failed (not associated to a modification status) <br>
  */
  virtual HRESULT IsModified(CATPLMLogModified iModificationType, const CATOmxKeyString& iAppData = CATOmxKeyString()) const = 0;

  /**
  *  Query if the LOG Modification Status is Exclusively modified (Based on explicite & implicite logging)
  *
  * @param iModificationType
  *   kind of modification
  *
  * @param iAppData
  *   Attribute (to be used only id modificationType is UserAttribute)
  *
  * @return
  *      S_OK      if Log Modification Status is Exclusively modified as asked in Input<br>
  *      S_FALSE   if Log Modification Status is not modified like asked<br>
  *      E_FAIL    if request failed (not associated to a modification status)<br>
  */
  virtual HRESULT IsExclusivelyModified(CATPLMLogModified iModificationType, const CATOmxKeyString & iAppData = CATOmxKeyString()) const = 0;

  /**
  *  Access to number of type of modifications
  *
  * @param oNumber
  *   Number of type of modifications
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT GetModified(int & oNumber) const = 0;

  /**
  *  Access to a given modifcation type
  *
  * @param iNumber
  *   index of type of modifications ( 1 <=    <= NumberOfType )
  *
  * @param oModifiedStatus
  *   Number of type of modifications
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT GetModified(const int iNumber, CATPLMLogModified & oModifiedStatus) const = 0;

  /**
  *  Access to Application Data
  *
  * @param oAppData
  *   application data
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT GetAppData(CATOmxArray<CATOmxKeyString> & oAppData) const = 0;
  virtual HRESULT GetAppData(CATLISTV(CATUnicodeString) & oAppData) const = 0;
};

CATDeclareHandler(CATIPLMLogState, CATBaseUnknown);



/** @nodoc  deprecated Historical equivalence  */
typedef CATIPLMLogState CATPLMLogState;




#endif

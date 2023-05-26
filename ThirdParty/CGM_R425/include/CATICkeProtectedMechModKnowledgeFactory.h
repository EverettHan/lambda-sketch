/**
 * @fullReview XGR XGR 22:11:16 
 */
// Copyright Dassault Systemes 2000
#ifndef CATICkeProtectedMechModKnowledgeFactory_H
#define CATICkeProtectedMechModKnowledgeFactory_H

// include root of extension CKE
#include "CATBaseUnknown.h"

//LiteralFeatures
#include "KnowledgeItf.h"

class CATIProxyParameter_var;

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeProtectedMechModKnowledgeFactory;
#else
extern "C" const IID IID_CATICkeProtectedMechModKnowledgeFactory;
#endif

/**
* Interface dedicated to Knowledge relations creation.
* <b>Role</b>: manages the creation of Knowledge relations.
* This interface is implemented on feature container.<br>
* Note that the behavior of a Knowledge relation is that it does not need to be evaluated "by hand".<br>
* By default, the creation methods are creating an active relationship, that is evaluated within the method.<br>
* @see CATIParmPublisher, CATIParmManipulator
*/
class ExportedByKnowledgeItf CATICkeProtectedMechModKnowledgeFactory : public CATBaseUnknown
{
    CATDeclareInterface;
public:
  /**
  * Creates a Proxy Relation feature.<br>
  * @return The feature Proxy Relation
  */
  virtual CATIProxyParameter_var CreateProxyParmRelation(CATBaseUnknown_var spInterfacePointed, CATBaseUnknown_var spParamType, CATBoolean ibToAggregateUnderModule = TRUE) = 0;

};
CATDeclareHandler(CATICkeProtectedMechModKnowledgeFactory, CATBaseUnknown);

#endif

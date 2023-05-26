// Copyright Dassault Systemes 2000
#ifndef CATICkeProtectedRelationFactory_H
#define CATICkeProtectedRelationFactory_H

// include root of extension CKE
#include "CATICkeRelationFactory.h"

//LiteralFeatures
#include "KnowledgeItf.h"

class CATIKwePythonScript_var;

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeProtectedRelationFactory;
#else
extern "C" const IID IID_CATICkeProtectedRelationFactory;
#endif

/**
* Interface dedicated to Knowledge relations creation.
* <b>Role</b>: manages the creation of Knowledge relations.
* This interface is implemented on feature container.<br>
* Note that the behavior of a Knowledge relation is that it does not need to be evaluated "by hand".<br>
* By default, the creation methods are creating an active relationship, that is evaluated within the method.<br>
* @see CATIParmPublisher, CATIParmManipulator
*/
class ExportedByKnowledgeItf CATICkeProtectedRelationFactory : public CATICkeRelationFactory
{
    CATDeclareInterface;
public:
    /**
    * Creates a python script feature.<br>
    * @return The feature python script
    */
    virtual CATIKwePythonScript_var CreateKwePythonScript() = 0;

};


CATDeclareHandler(CATICkeProtectedRelationFactory, CATBaseUnknown);


#endif





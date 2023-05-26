/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIGraphFactory_H_
#define CATIGraphFactory_H_

/**
 * @level Protected 
 * @usage U3
 */

#include <GenericFactory.h>
#include "CATBaseUnknown.h"

#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATIGraphFactory;

class CATIGraphNode;
class CATIGraphNode_var;
class CATIGraphLink;
class CATNavigInstance;

class ExportedByCATOmnMain CATIGraphFactory : public GenericFactory
{
	CATDeclareInterface;

  public:
    virtual CATIGraphNode* CreateNode (const CATIGraphNode_var& father,CATNavigInstance* inst,int extensionMode=0) = 0 ;

    virtual CATIGraphLink* CreateLink (const CATIGraphNode_var& father,const CATIGraphNode_var& child ) = 0 ;
} ;
  
// Declaration du handler

CATDeclareHandler ( CATIGraphFactory, GenericFactory);


#endif



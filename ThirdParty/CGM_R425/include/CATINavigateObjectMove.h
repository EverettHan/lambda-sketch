/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATINavigateObjectMove_h
#define _CATINavigateObjectMove_h

#include "CATIReorderList.h"

/**
 * Interface to move an object in the graph.
 * <b>Role</b>: Works with CATINavigateObject interface
 *              
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATINavigateObjectMove;
#else
extern "C" const IID IID_CATINavigateObjectMove;
#endif

class ExportedByUIModelInterfaces CATINavigateObjectMove : public CATIReorderList
{ 
public:
  CATDeclareInterface;
};

#endif      


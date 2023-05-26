//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicColumn_h
#define _VPMIDicColumn_h

#include "VPMIDicInterfaces.h"

#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicColumn;
#else
extern "C" const IID IID_VPMIDicColumn;
#endif

/**
* Interface to manage the Column.
*/
class ExportedByVPMIDicInterfaces VPMIDicColumn : public VPMIDicElement
{
  CATDeclareInterface;

public:



};

CATDeclareHandler( VPMIDicColumn, VPMIDicElement );

#endif /*_VPMIDicColumn_h*/

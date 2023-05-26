//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicFlatTable_h
#define _VPMIDicFlatTable_h

#include "VPMIDicInterfaces.h"

#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicFlatTable;
#else
extern "C" const IID IID_VPMIDicFlatTable;
#endif

/**
* Interface to manage the FlatTable.
*/
class ExportedByVPMIDicInterfaces VPMIDicFlatTable : public VPMIDicElement
{
  CATDeclareInterface;

public:



};

CATDeclareHandler( VPMIDicFlatTable, VPMIDicElement );

#endif /*_VPMIDicFlatTable_h*/

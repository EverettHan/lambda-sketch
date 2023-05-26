//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicRange_h
#define _VPMIDicRange_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

// class VPMIDicClass;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicRange;
#else
extern "C" const IID IID_VPMIDicRange;
#endif

/**
 * Interface to manage the VPMIDicRange.
 */

class  ExportedByVPMIDicInterfaces VPMIDicRange: public VPMIDicElement
{
    CATDeclareInterface;

  public:
    /**
    * Get the RangeClause list of the Range.
    * FIXME: explain what it is
    * @param oDicRangeClauseList the RangeClause list (nb: each element of the list must be released) 
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded, oDicRangeClauseList contains at least one RangeClause.</li>
    *    <li>E_FAIL   Operation failed, oDicRangeClauseList is empty.</li>
    *    </ul>
    */
    virtual HRESULT GetRangeClauseList ( CATListOfIUnknown & oDicRangeClauseList ) const = 0;
};
#endif

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicRangeClause_h
#define _VPMIDicRangeClause_h

#include "VPMIDicInterfaces.h" 

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

// class VPMIDicClass;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicRangeClause;
#else
extern "C" const IID IID_VPMIDicRangeClause;
#endif

/**
 * Interface to manage the VPMIDicRangeClause.
 */

class  ExportedByVPMIDicInterfaces VPMIDicRangeClause: public VPMIDicElement
{
    CATDeclareInterface;

  public:
    /**
    * Get the Tag of the RangeClause.
    * @param oTag the Tag of the RangeClause
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded, oTag is valuated.</li>
    *    <li>E_FAIL   Operation failed, oTag is not valuated.</li>
    *    </ul>
    */
    virtual HRESULT GetTag ( CATUnicodeString & oTag ) const = 0;

    /**
    * Get the Value of the RangeClause.
    * @param oValue the Value of the RangeClause
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded, oValue is valuated.</li>
    *    <li>E_FAIL   Operation failed, oValue is not valuated.</li>
    *    </ul>
    */
    virtual HRESULT GetValue ( CATUnicodeString & oValue ) const = 0;

    /**
    * Get the RangeSubClause list of the RangeClause.
    * @param oDicRangeSubClauseList the RangeSubClause list (nb: each element of the list must be released) 
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded, oDicRangeSubClauseList contains at least one RangeSubClause.</li>
    *    <li>E_FAIL   Operation failed, oDicRangeSubClauseList is empty.</li>
    *    </ul>
    */
    virtual HRESULT GetRangeSubClauseList ( CATListOfIUnknown & oDicRangeSubClauseList ) const = 0;


    /**
    * TO BE COMPLETED
    */
    virtual HRESULT GetProgramName ( CATUnicodeString & oValue ) const = 0;
    virtual HRESULT GetProgramArgument ( CATUnicodeString & oValue ) const = 0;
};
#endif

#ifndef CATIPLMAliasSpecifications_H
#define CATIPLMAliasSpecifications_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U3
 */

//================================================================
//
// CATIPLMAliasSpecifications.h
// Defines the CATIPLMAliasSpecifications interface
//
//================================================================
//
// Usage notes:
//    This interface is used as a software bridge between CATPLMIdentification and PLMNavigationServices.
//    It allows CATPLMIdentification to access the spec of a component alias, i.e the attributes used to
//    construct it.
//
//================================================================
// Jun 2007 Creation LPQ
//================================================================


#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATIPLMAliasSpecifications;
#else
extern "C" const IID IID_CATIPLMAliasSpecifications;
#endif

class CATUnicodeString;
class CATLISTV( CATUnicodeString );
class CATIComponent;
class CATIAdpType;

/**
 * Usage:
 *  Transforms an alias to/from its specifications
 */
class ExportedByCATPLMTos CATIPLMAliasSpecifications : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
     * Retrieves the specifications of the alias of a component.
     *
     * @param ipAdpType
     *    The component.
     * @param oAttributes
     *    List of attributes used to build the alias.
     * @param oValues
     *    List of values used to build the alias.
     * @return
     *    S_OK: oAttributes and oValues are valuated.
     *    E_FAIL: error
     */
    virtual HRESULT GetAliasSpecifications(
        CATIComponent *ipAdpType,    
        CATLISTV( CATString ) &oAttributes,
        CATLISTV( CATUnicodeString ) &oValues ) = 0;

    /**
     * Constructs an alias for a given CATIAdpType using a set of PLM
     * Attributes. The alias is built with the current alias customization.
     * Attributes required by the customization, but missing from this call are
     * replaced by '?'.
     *
     * @param ipAdpType
     *    The CATIAdpType of the component whose alias is being constructed.
     * @param iAttributes
     *    List of attributes provided to build the alias.
     * @param iValues
     *    List of values provided to build the alias.
     * @param oAlias
     *    The alias
     * @return
     *    S_OK: oAlias is valuated.
     *    E_FAIL: error
     */
    virtual HRESULT GetAliasFromSpecifications(
        CATIAdpType *ipAdpType,
        CATLISTV( CATString ) &iAttributes,
        CATLISTV( CATUnicodeString ) &iValues,
        CATUnicodeString &oAlias ) = 0;
};

#endif

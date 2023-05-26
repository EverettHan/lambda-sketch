// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// PLMPSIAttrInfos.h
// Header definition of PLMPSIAttrInfos
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2004  Creation: Code generated by the CAA wizard  aif
//===================================================================

/**
 * @level Protected
 * @usage U3
 */

#ifndef PLMPSIAttrInfos_H
#define PLMPSIAttrInfos_H

#include "PLMPSISessionInterfaces.h"
#include "CATUnicodeString.h"
#include "CATIType.h"
#include "CATBoolean.h"


//-----------------------------------------------------------------------

/**
 * @nodoc : Use CATAttributeInfos instead.
 * Class describing an attribute of a typed PLM entity.
 * <b>Role</b>: This class gives information on an attribute of a PLM entity.
 * @see CATIPsiPLMProperties
 */
class ExportedByPLMPSISessionInterfaces PLMPSIAttrInfos 
{

  public:

	/**
     * Constructor.
     * @param iType 
	 *	 Type of the attribute.
     * @param iName            
	 *	 Internal name of the attribute.
     * @param iAlias 
	 *	 Alias of the attribute.
     * @param iIsMandatory 
	 *	 TRUE if the attribute is mandatory (default is FALSE).
     * @param iIsIdentifier 
	 *	 TRUE if the attribute belongs to the Identifier Set (default is FALSE).
     * @param iIsWritable 
	 *	 TRUE if the attribute can be changed (default is TRUE).
	  * @param iIsMultiValuated
	 *	 TRUE if the attribute is multi valuated (default is FALSE).
     */
     PLMPSIAttrInfos(const CATIType_var & iType, 
					 const CATUnicodeString& iName, 
					 const CATUnicodeString& iAlias,
					 const CATBoolean iIsMandatory     = FALSE,
					 const CATBoolean iIsIdentifier    = FALSE,
					 const CATBoolean iIsWritable      = TRUE, 
					 const CATBoolean iIsMultiValuated = FALSE);

	/**
     * Copy Constructor.
     */
	 PLMPSIAttrInfos (const PLMPSIAttrInfos &);
	
	/**
	 * Destructor. 
	 */
   virtual ~PLMPSIAttrInfos ();

	/**
     * Returns the attribute's type.
     * @return
	 *    The attribute's type.
     */
	 CATIType_var GetType() const;
	
	 /**
     * Indicates whether the attribute is mandatory.
     * @return
	 *  <ul>
	 * 	 <li> E_FAIL  if the attribute is not mandatory </li>
	 * 	 <li> S_OK	if the attribute is mandatory </li>
	 *  </ul>
     */
	 HRESULT IsMandatory () const;
	
	/**
     * Indicates whether the attribute belongs to the Identification Set.
     * @return
	 *  <ul>
	 * 	 <li> E_FAIL  if the attribute does not belong to the Identification Set </li>
	 * 	 <li> S_OK	if the attribute belongs to the Identification Set </li>
	 *  </ul>
     */
	 HRESULT IsOfIdentifier () const;
	 
	/**
     * Indicates whether the attribute can be changed or not.
     * @return
	 *  <ul>
	 * 	 <li> E_FAIL  if the attribute is read-only </li>
	 * 	 <li> S_OK	if the attribute is read/write </li>
	 *  </ul>
     */
	 HRESULT IsWritable () const;

	/**
	 * Returns the internal name of the attribute.
	 * @return 
	 *    The internal name of the attribute.
	 */
	 CATUnicodeString GetName() const;
	 
	 /**
	 * Returns the NLS name of the attribute.
	 * @return 
	 *    The NLS name of the attribute.
	 */
	 CATUnicodeString GetAliasName() const;

	/** 
	* Operator ==: Tests if This AttrInfos is the same as @param iInfos.
	*
	* @param iInfos [in]
	*   The Information to be compared with This.
	*
	* @return
	*   Returns TRUE if this has same data as @param iInfos, else FALSE.
	*
	*/
	CATBoolean           operator==(const PLMPSIAttrInfos& iInfos ) const;

	/** 
	* Operator !=: Tests if This AttrInfos is different from @param iInfos.
	*
	* @param iInfos [in]
	*   The Information to be compared with This.
	*
	* @return
	*   Returns FALSE if this has same data as @param iInfos, else TRUE.
	*
	*/
	CATBoolean           operator!=(const PLMPSIAttrInfos& iInfos ) const;

	/** 
	* Operator = : Valuates This with @param iInfos data.
	*
	* @param iInfos [in]
	*   The Information to be set.
	*
	* @return
	*   No return.
	*
	*/
	PLMPSIAttrInfos &operator=(const PLMPSIAttrInfos& iInfos ) ;
 
	/**
     * Indicates whether the attribute is multi-valuated.
     * @return
	 *  <ul>
	 * 	 <li> E_FAIL  if the attribute is not multi-valuated </li>
	 * 	 <li> S_OK	if the attribute is multi-valuated </li>
	 *  </ul>
     */
	HRESULT IsMultiValuated () const;
	
  private :

    // Default constructor - Not implemented
    PLMPSIAttrInfos();

    CATIType_var _prdType;
    CATUnicodeString _attrName;
    CATUnicodeString _attrAlias;
    CATBoolean _isMandatory;
    CATBoolean _isIdentifier;
    CATBoolean _isWritable;
    CATBoolean _isMultiValuated;
};
//-----------------------------------------------------------------------

#endif
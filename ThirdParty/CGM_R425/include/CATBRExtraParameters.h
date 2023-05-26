#ifndef CATBRExtraParameters_h
#define CATBRExtraParameters_h

// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATLifSpecs.h"
#include "CATListValCATICkeParm.h"
#include "CATUnicodeString.h"

class CATICkeObject_var;

/**
* Class to be used to pass additional parameters to business rules, through different layers of software.<br>
* <b>Role</b>: Contains additional information and parameters that need to be passed to business rules. <br>
* <p>

* @see CATIBRExecutionServices
*/

class ExportedByCATLifSpecs CATBRExtraParameters 
{
public:

	/**
	* Constructor for applications that need to pass additional informations to Modeler APIs.
	*
	* @param iBRid			      Identifier of the business rule opening. Optional argument. May be ""
	* @param iOperationDetail   Name of the operation detailed for the opening. Optional argument. May be "" 
   	* @param iListAttributeValuesForContext  List of values for the attributes. The CATICkeParm name must correspond to names of attributes. This list may be empty.
	*                                        Note that the list duplicates the parameters (for safety)
	*/
	CATBRExtraParameters(	const CATUnicodeString			&iBRId,
							const CATUnicodeString			&iOperationDetail,
							const CATLISTV(CATICkeParm_var) &iListAttributeValuesForContext);

	/**
	* Constructor for Modelers implementing Business rules for a given PLM Opening.
	*
	* @param iBRid			      Identifier of the business rule opening.
	* @param iOperationID		  Name of the operation ID for the opening. Optional argument. May be "" 
	* @param iOperationDetail   Name of the operation detailed for the opening. Optional argument. May be "" 
   	* @param iListAttributeValuesForContext  List of values for the attributes. The CATICkeParm name must correspond to names of attributes. This list may be empty.
	*                                        Note that the list duplicates the parameters (for safety)
	*/
	CATBRExtraParameters(	const CATUnicodeString			&iBRId,
							const CATUnicodeString			&iOperationID,
							const CATUnicodeString			&iOperationDetail,
							const CATLISTV(CATICkeParm_var) &iListAttributeValuesForContext);

	/** 
	 * Destructor.
	 */
	virtual  ~CATBRExtraParameters();

	/** 
	 * Copy constructor.
	 * @param iExtraParameters attribute to be copied.
	 */
	CATBRExtraParameters( const CATBRExtraParameters& iExtraParameters );

	/**  
	 * Operator to affect Extra parameters.
	 * @param iExtraParameters Value to valuate with.
	 * @return Handler on the Extra parameters itself
	 */
	CATBRExtraParameters &operator=(const CATBRExtraParameters& iExtraParameters ) ;

	/**
	* Returns the BR id.
	*
	* @return a string.
	*/
	CATUnicodeString GetBRId() const;

	/**
	* Returns the operation Detail.
	*
	* @return a string.
	*/
	CATUnicodeString GetOperationDetail() const;

	/**
	* Returns the operation ID.
	*
	* @return a string.
	*/
	CATUnicodeString GetOperationID() const;

	/**
	* Returns the list of attribute values. Do not deallocate.
	*
	* @return the list.
	*/
	const CATLISTV(CATICkeParm_var) *ListOfAttributesValues() const;
	

	/** 
	 * Generates the BR context to be passed to the business rule.<br>
	 * The BRID used is in priority the one passed to this method. If not, it will use the one on the BRExtraParameters.
	 * This method fills the OperationDetail and OperationID if any defined on BR Extra parameters
	 * @param iName
	 * Name of the created object
	 * @param iBRUsageID
	 *  If not NULL, it will override the BR ID defined on the BR Extra parameters
	 * @param iListAttributeValuesForContext
	 *  List of values for the attributes. The CATICkeParm name must correspond to names of attributes. This list may be empty.
	 *  This list will be added with the list given by the extra parameters. 
	 * @param oContextGenerated
	 *  Context object generated.
	 */
	virtual HRESULT DeduceBRContext ( const CATUnicodeString		  &iName,
									  const CATUnicodeString		  &iBRUsageID,
									  const CATLISTV(CATICkeParm_var) &iListAttributeValuesForContext,
									  CATICkeObject_var				  &oContextGenerated) const;

	/** 
	 * Merges the BR Extra parameters into one.<br>
	 * The BRID, additional parameters and operationID operationDetail of the one passed as an argument are taken in priority
	 * @param iExtraParameters
	 * parameters to be added to the current one
	 */
	HRESULT Merge ( const CATBRExtraParameters& iExtraParameters);

	/** 
     * Adding a parameter (watch out, the parameter is not copied. So copy if first if necessary)
	 * @param iParm
	 * parameters to be added to the current one
	 */
	HRESULT AddParameter ( const CATICkeParm_var & iParm);




protected:
	

	CATUnicodeString _BRId;
	CATUnicodeString _OperationID;
	CATUnicodeString _OperationDetailed;
	CATLISTV(CATICkeParm_var) _ListAttributeValuesForContext;
};

#endif 

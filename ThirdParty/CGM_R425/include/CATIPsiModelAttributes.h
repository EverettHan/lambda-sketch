// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPsiModelAttributes.h
// Define the CATIPsiModelAttributes interface
//
//===================================================================
//
//  Sept 2006  Creation: JIT
//===================================================================
#ifndef CATIPsiModelAttributes_H
#define CATIPsiModelAttributes_H

/**
* @level Private
* @usage U3
*/
#include "PLMPSISessionInterfaces.h" 
#include "CATBaseUnknown.h"

#include "CATIPsiPrivateComponentTypeInfraOnly.h"
#include "CATCollec.h"
#include "CATListOfCATBoolean.h"
class CATString;
class CATUnicodeString;
class CATIValue;
class CATBinary;
class CATTime;

extern ExportedByPLMPSISessionInterfaces IID IID_CATIPsiModelAttributes;
//------------------------------------------------------------------

/**
 * Interface representing direct access on model attributes.
 * This is dedicated to modeler integration.
 * In order to be as fast as possible, no data integrity checks are done.
 * So do not use this API without a good understanding of the way to use it.
 */

class ExportedByPLMPSISessionInterfaces CATIPsiModelAttributes: public CATBaseUnknown
{
	CATDeclareInterface;

	public:

		/**
		 * Sets the value of a single (Sva) or multiple (Mva) valuated string property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iValue
		 *    Value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT SetStringSva(const CATString& iAttrName, const CATUnicodeString& iValue) = 0;
		/**
		 *
		 */
		virtual HRESULT SetStringMva(const CATString& iAttrName, const CATListOfCATUnicodeString& iValue) = 0;

		/**
		 * Gets the value of a single (Sva) or multiple (Mva) valuated string property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param oValue
		 *    Returned value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not found </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetStringSva(const CATString& iAttrName, CATUnicodeString& oValue) = 0;
		/**
		 *
		 */
		virtual HRESULT GetStringMva(const CATString& iAttrName, CATListOfCATUnicodeString& oValue) = 0;

		/**
		 * Sets the value of a single valuated boolean property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iValue
		 *    Value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT SetBooleanSva(const CATString& iAttrName, CATBoolean iValue) = 0;
		/**
		 *
		 */
		virtual HRESULT SetBooleanMva(const CATString& iAttrName, const CATListOfCATBoolean &iValue) = 0;

		/**
		 * Gets the value of a single valuated boolean property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param oValue
		 *    Returned value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not found </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetBooleanSva(const CATString& iAttrName, CATBoolean& oValue) = 0;
		/**
		 *
		 */
		virtual HRESULT GetBooleanMva(const CATString& iAttrName, CATListOfCATBoolean& oValue) = 0;

		/**
		 * Sets the value of a single (Sva) or multiple (Mva) valuated double property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iValue
		 *    Value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT SetDoubleSva(const CATString& iAttrName, double iValue) = 0;
		/**
		 *
		 */
		virtual HRESULT SetDoubleMva(const CATString& iAttrName,const CATListOfDouble & iValue) = 0;

		/**
		 * Gets the value of a single (Sva) or multiple (Mva) valuated double property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param oValue
		 *    Returned value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not found </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetDoubleSva(const CATString& iAttrName, double& oValue) = 0;
		/**
		 *
		 */
		virtual HRESULT GetDoubleMva(const CATString& iAttrName, CATListOfDouble & oValue) = 0;

		/**
		 * Sets the value of a single (Sva) or multiple (Mva) valuated integer property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iValue
		 *    Value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT SetIntegerSva(const CATString& iAttrName, int iValue) = 0;
		/**
		 *
		 */
		virtual HRESULT SetIntegerMva(const CATString& iAttrName, const CATListOfInt &iValue) = 0;

		/**
		 * Gets the value of a single (Sva) or multiple (Mva) valuated string property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param oValue
		 *    Returned value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not found </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetIntegerSva(const CATString& iAttrName, int& oValue) = 0;
		/**
		 *
		 */
		virtual HRESULT GetIntegerMva(const CATString& iAttrName, CATListOfInt& oValue) = 0;

		/**
		 * Sets the value of a single  valuated binary property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iValue
		 *    Value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT SetBinary(const CATString& iAttrName, CATBinary iValue) = 0;

		/**
		 * Gets the value of a single  valuated binary property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param oValue
		 *    Returned value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not found </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetBinary(const CATString& iAttrName, CATBinary& oValue) = 0;

		/**
		 * Sets the value of a single (Sva) or multiple (Mva) valuated date property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iValue
		 *    Value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT SetDateSva(const CATString& iAttrName, const CATTime& iValue) = 0;

		/**
		 * Sets the value of  a multivaluated (ONLY!) date property. .
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iValue
		 *    Value of the property attribute.
 		 * @param iindex
		 *    The position to replace.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT SetDateMva(const CATString& iAttrName, const  CATTime & iValue, int iindex) = 0;

		/**
		 * Gets the value of a single (Sva)valuated date property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param oValue
		 *    Returned value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not found </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetDateSva(const CATString& iAttrName, CATTime& oValue) = 0;

		/**
		 * Gets the value of a multivaluated (ONLY!) date property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param iindex
		 *    The position to get.
		 * @param oValue
		 *    Returned value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not found </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetDateMva(const CATString& iAttrName, CATTime& oValue, int iindex) = 0;

		/**
		 * Sets the value of a property.
		 * @param iAttrName
		 *    The name of the property attribute.
		 * @param ipiValue
		 *    Value of the property attribute.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iAttrName</tt> is not set properly </li>
		 *    <li> S_OK if <tt>iAttrName</tt> is set properly </li>
		 *    </ol>
		 */
		virtual HRESULT InitialSetValue(const CATString& iAttrName, CATIValue* ipiValue) = 0;

		/**
		 * Set/Get the terminal property on a Product Reference.
		 * @param oCustoAlias
		 *    The alias of custo type.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iCustoName</tt> is not found </li>
		 *    <li> S_OK if <tt>iCustoName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT SetTerminalProperty( const CATBoolean& iValue) = 0;
		/**
		*
		*/
		virtual HRESULT GetTerminalProperty(CATBoolean& oValue) = 0;

		/**
		 * Set the usage value on a Reference.
		 * @param oCustoAlias
		 *    The alias of custo type.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iCustoName</tt> is not found </li>
		 *    <li> S_OK if <tt>iCustoName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT SetUsage( const CATUnicodeString& iValue) = 0;

		/**
		 * Set the discipline value on a Reference.
		 * @param oCustoAlias
		 *    The alias of custo type.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iCustoName</tt> is not found </li>
		 *    <li> S_OK if <tt>iCustoName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT SetDiscipline( const CATUnicodeString& iValue) = 0;

		/**
		 * Set the CustoDiscipline value on a Reference.
		 * @param iValue
		 *    The CustoDiscipline value.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>CustoDiscipline</tt> is not valid </li>
		 *    <li> S_OK </li>
		 *    </ol>
		 */
		virtual HRESULT SetCustoDiscipline( const CATUnicodeString& iValue) = 0;

    /**
		 * Set the nature value on a Reference.
		 * @param oCustoAlias
		 *    The alias of custo type.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>iCustoName</tt> is not found </li>
		 *    <li> S_OK if <tt>iCustoName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT SetNature( const CATUnicodeString& iValue) = 0;

		/**
		 * Get the V_isOnceinstanciable value on a RepReference.
		 * @param oCustoAlias
		 *    The alias of custo type.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>oValue</tt> is not found </li>
		 *    <li> S_OK if <tt>oValue</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT GetOnceInstanciableProperty( CATBoolean& oValue) = 0;

		/**
		 * Set the V_isOnceinstanciable value on a RepReference (only unset works on PC2)
		 * @param oCustoAlias
		 *    The alias of custo type.
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>oValue</tt> is not found </li>
		 *    <li> S_OK if <tt>iCustoName</tt> is found </li>
		 *    </ol>
		 */
		virtual HRESULT SetOnceInstanciableProperty( CATBoolean iValue) = 0;

		/**
		 * Get the V_isUptodate value on a RepReference 
		 * @return
		 *    <ol>
		 *    <li> E_FAIL if <tt>oValue</tt> is not found </li>
		 *    <li> S_OK else </li>
		 *    </ol>
		 */
		virtual HRESULT GetisUptodateProperty( CATUnicodeString& oValue)= 0;

};

CATDeclareHandler(CATIPsiModelAttributes,CATBaseUnknown);

#endif

//------------------------------------------------------------------

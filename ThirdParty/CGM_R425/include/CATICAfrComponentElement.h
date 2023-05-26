// COPYRIGHT DASSAULT SYSTEMES 2011/09/28

#ifndef CATICAfrComponentElement_H
#define CATICAfrComponentElement_H

/**
 * @level Protected
 * @CAA2Usage U3
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATUnicodeString.h"

class CATICAfrProperty;

extern ExportedByCATAfrItf  IID IID_CATICAfrComponentElement ;

//-----------------------------------------------------------------------------
/**
* Interface to manage the Afr component element.
*/
class ExportedByCATAfrItf CATICAfrComponentElement: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Sets the name  idof the component.
	*  @param iName
    *    The name id to set
    */
    virtual void SetName( const CATString & iName ) = 0;

    /**
	* Gets the name id of the component. 
    * @Return
	*   The name id of the component.
    */
    virtual const CATString& GetName() const = 0;

    /**
    * Sets the visibility flag of the component.
	*  @param iVisibility
    *    The visibility flag
    */
    virtual void SetVisibility (const CATBoolean& iVisibility) = 0;

    /**
    * Gets the visibility flag of the component. 
    * @Return 
	*   The visibility flag of the component
    */
    virtual CATBoolean GetVisibility() const = 0;

    /**
    * Gets the representation type of the model object. 
    * @Return 
	*   The representation type of the model object.
    */
    virtual const CATString  &  GetRepresentationType() = 0;

    /**
    * Sets the representation type of the model object.
	*  @param irepresentationType
    *    The representation type to set
    */
    virtual void SetRepresentationType(CATString & irepresentationType ) = 0;

    /**
    *  Retrieves a property.
    *
    * <br><b>Role</b>: This method retrieves a property by its id.
	*  If this method is called after AddProperty, it doesn't work.
    *
    *  @param iPropId
    *    The id of the property.
    *
    *  @param opiAfrProperty
    *    The property element [out, CATICAfrProperty#Release]
    *
	*  @return 
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *    <li><b>S_OK</b>The function was executed successfully.</li>
    *    <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT GetProperty( const CATString& iPropId, CATICAfrProperty** opiAfrProperty ) = 0;

    /**
    * Adds a new sub object element.
    *
    *  @param ispSubObject
    *   The sub object to add
    *
	*  @return 
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *    <li><b>S_OK</b>The function was executed successfully.</li>
    *    <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT AddSubObject( const CATBaseUnknown_var ispSubObject ) = 0;

    /**
    * Returns the sub object element.
    *
    *  @param ospSubObject
    *    The sub object element
    *
    *  @return 
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *    <li><b>S_OK</b>The function was executed successfully.</li>
    *    <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT GetSubObject( CATBaseUnknown_var& ospSubObject ) = 0;

   /**
    * Access rights.
    * @param ReadWrite
    * @param ReadOnly,
	* @param WriteOnly
    */
    enum Access
    {
      ReadWrite = 0,
      ReadOnly,
      WriteOnly
    };


    /**
    * Adds a property.
    *  <b>Role</b>: Use this method if you don't have Sub Objects.
    * @param i_name
	*   The name of the property to add
    * @param i_type 
	*   The type of the property to add
    * @param i_readOnlyFlag
	*    A flag indicating whether the property is read-only
    * @param i_tweakType 
    *   The type of the property
	*    <br><b>Legal values</b>:
    *    <ul>
	*     <li>CATMathPoint2Df</li>
	*     <li>CATMathVector2Df</li>
	*     <li>CATUnicodeString</li>
	*     <li>CATVidColor</li>
	*     <li>CATVidImageBlender</li>
	*     <li>double</li>
	*     <li>int</li>
	*    </ul>
	 * @param i_value
    *   The property value.
    * @param i_valueTypeFlag 
    *   A flag indicating if the property is a semantic of value or entity.
    * @return 
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *    <li><b>S_OK</b>The function has been executed successfully.</li>
    *    <li><b>S_FALSE</b>If a new property has the same name as one previously registered.</li>
    *    <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    *
    */
    virtual HRESULT AddProperty( const CATUnicodeString & i_name, 
                                 const CATUnicodeString & i_type, 
                                 const CATICAfrComponentElement::Access i_access, 
                                 const CATUnicodeString & i_tweakType, 
                                 const CATBaseUnknown_var & i_value, 
                                 int i_valueTypeFlag = 1 ) = 0;

    /**
    * Gets the previous object in the list.
    *
    *  @param opiPrevious
    *    The previous element [out, CATICAfrComponentElement#Release]
    *
	*  @return 
    *    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *      <li><b>S_OK</b>The function was executed successfully.</li>
    *      <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT GetPreviousElement( CATICAfrComponentElement** opiPrevious ) = 0;

    /**
    * Gets the next object in the list.
    *
    *  @param opiNext
    *    The next element [out, CATICAfrComponentElement#Release]
    *
	*  @return 
    *    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *      <li><b>S_OK</b>The function was executed successfully.</li>
    *      <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT GetNextElement( CATICAfrComponentElement** opiNext ) = 0;

    /**
    * Gets the parent object.
    * @Return
	*   The parent object of the component element.
	*   <br> returns NULL if there is no parent (i.e. the element is the root of the tree).
    */
    virtual HRESULT GetParentElement( CATICAfrComponentElement** opiFather ) = 0;

};
CATDeclareHandler( CATICAfrComponentElement, CATBaseUnknown );
#endif

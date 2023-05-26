#ifndef IVISUIElement_H
#define IVISUIElement_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVISUIEntity.h"
#include "IVInterfaces.h"
#include "CATSysErrorDef.h"

class IVISUIElement_var;

extern ExportedByIVInterfaces IID IID_IVISUIElement;

/**
* Interface representing a SUI Element.
*
* <strong>Role</strong>: This interface is the base interface for all SUI Elements.
* It provides all necessary methods to manage the relations between Elements instances, as well as Elements–to-Parameters relations.
*
* @see IVISUIEntity
*/
class ExportedByIVInterfaces IVISUIElement: public IVISUIEntity
{

  CATDeclareInterface;

public:

  /**
  * Get the number of children Elements attached to the current Element instance.
  *
  * @param oNbChildren [out]
  *   The number of child @href IVISUIElement instances.
  * <br><strong>Precondition</strong>:
  * <tt>oNbChildren</tt> should be set to <tt>0</tt> before calling this method.
  * <br><strong>Legal values</strong>: 
  * The number of children ranges from <tt>0</tt> to <tt>n-1</tt>.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd><tt>oNbChildren</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd><tt>oNbChildren</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oNbChildren</tt> parameter was not set to <tt>0</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetChildCount(unsigned int& oNbChildren) const = 0;

  /**
  * Get the number of children Elements attached to the current Element instance.
  *
  * @return
  *   The number of child @href IVISUIElement instances.
  */
  virtual unsigned int GetChildCount() const = 0;

  /**
  * Get a child by its index.
  *
  * @param iChildIndex [in] 
  *   The index of the child @href IVISUIElement.
  * <br><strong>Legal values</strong>:
  * <tt>iChildIndex</tt> range starts with <tt>0</tt>. Use @href #GetChildCount to get the @href IVISUIElement count.
  * @param oChild [out]
  *   The retrieved child @href IVISUIElement.
  * <br><strong>Precondition</strong>:
  * <tt>oChild</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oChild</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oChild</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oChild</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetChild(const unsigned int iIndex, IVISUIElement*& oChild) const = 0;

  /**
  * Get a child by its index.
  *
  * @param iChildIndex [in]
  *   The index of the child @href IVISUIElement.
  * <br><strong>Legal values</strong>:
  * <tt>iChildIndex</tt> range starts with <tt>0</tt>. Use @href #GetChildCount to get the @href IVISUIElement count.
  * @return
  *   The retrieved child @href IVISUIElement.
  */
  virtual IVISUIElement_var GetChild(const unsigned int iIndex = 0) const = 0;

 /**
  * Get a child by its name.
  *
  * @param [in] iName
  *   The name of the child @href IVISUIElement.
  * @param [out] oChild
  *   The retrived child @href IVISUIElement.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oChild</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oChild</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oChild</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT FindChild(const CATUnicodeString& iName, IVISUIElement*& oChild) const = 0;

  /**
  * Get a child by its name.
  *
  * @param [in] iName
  *   The name of the child @href IVISUIElement.
  * @return
  *   The retrived child @href IVISUIElement.
   */
  virtual IVISUIElement_var FindChild(const CATUnicodeString& iName) const = 0;

 /**
  * Get a child by its name by searching recursively in the SUI tree.
  *
  * @param [in] iName
  *   The name of the child @href IVISUIElement.
  * @param [out] oChild
  *   The retrived child @href IVISUIElement.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oChild</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oChild</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oChild</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT RecursiveFindChild(const CATUnicodeString& iName, IVISUIElement*& oChild) const = 0;

  /**
  * Get a child by its name by searching recursively in the SUI tree.
  *
  * @param [in] iName
  *   The name of the child @href IVISUIElement.
  * @return
  *   The retrived child @href IVISUIElement.
  */
  virtual IVISUIElement_var RecursiveFindChild(const CATUnicodeString& iName) const = 0;

 /**
  * Get the parent of the current Element.
  *
  * @param [out] oParent
  *   The retrieved @href IVISUIElement.
  * <br><strong>Precondition</strong>:
  * <tt>oParent</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oParent</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oParent</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oParent</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetParent(IVISUIElement*& oParent) const = 0;

 /**
 * Get the parent of the current Element.
 *
 * @return
 *   The retrieved @href IVISUIElement.
 */
  virtual IVISUIElement_var GetParent() const = 0;

};

CATDeclareHandler(IVISUIElement, IVISUIEntity);

#endif

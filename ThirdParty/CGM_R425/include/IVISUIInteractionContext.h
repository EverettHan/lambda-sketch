#ifndef IVISUIInteractionContext_H
#define IVISUIInteractionContext_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIElement.h"

class IVISUIPhysicalEnvironment;
class IVISUIPhysicalEnvironment_var;
class IVISUIUser;
class IVISUIUser_var;
class CATMathTransformation;

extern ExportedByIVInterfaces IID IID_IVISUIInteractionContext;

/**
* Interface representing an interaction context.
* <strong>Role</strong>: This interface provides methods to access the User Element entities and the PhysicalEnvironment entity attached to the InteractionContext.
* An important aspect of the inateraction context is that it provides the transformation between the real and the virtual worlds. See #GetMatrix
*
* @see IVISUIManager, IVISUIElement, IVISUIUser, IVISUIPhysicalEnvironment
*/
class ExportedByIVInterfaces IVISUIInteractionContext: public IVISUIElement
{

  CATDeclareInterface;

public: 

  /**
  * Get the physical environment of the interaction context.
  * @param oEnvironment [out, IUnknown#Release]
  *   The retrieved @href IVISUIPhysicalEnvironment.
  * <br><strong>Precondition</strong>:
  * <tt>oEnvironment</tt> should be set to <tt>NULL</tt> before calling this method.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oEnvironment</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oEnvironment</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oEnvironment</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetPhysicalEnvironment(IVISUIPhysicalEnvironment*& oEnvironment) const = 0;

  /**
  * Get the physical environment of the interaction context.
  * @return
  *   The retrieved @href IVISUIPhysicalEnvironment.
  */
  virtual IVISUIPhysicalEnvironment_var GetPhysicalEnvironment() const = 0;

  /**
  * Get the number of users in the interaction context.
  *
  * @param oNbUsers [out]
  *   The number of users in the context.
  * <br><strong>Precondition</strong>:
  * <tt>oNbUsers</tt> should be set to <tt>0</tt> before calling this method.
  * <br><strong>Legal values</strong>: 
  * The number of Parameters ranges from <tt>0</tt> to <tt>n-1</tt>.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd><tt>oNbUsers</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd><tt>oNbUsers</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oNbUsers</tt> parameter was not set to <tt>0</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetUserCount(unsigned int& oNbUsers) const = 0;

  /**
  * Get the number of users in the interaction context.
  *
  * @return
  *   The number of users in the context.
  */
  virtual unsigned int GetUserCount() const = 0;

  /**
  * Get a user by its index.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIUser.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetUserCount to get the @href IVISUIUser count.
  * @param oUser [out, IUnknown#Release]
  *   The retrieved @href IVISUIUser.
  * <br><strong>Precondition</strong>:
  * <tt>oUser</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oUser</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oUser</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oUser</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetUser(const unsigned int iIndex, IVISUIUser*& oUser) const = 0;

  /**
  * Get a user by its index.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIUser.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetUserCount to get the @href IVISUIUser count.
  * @return
  *   The retrieved @href IVISUIUser.
  */
  virtual IVISUIUser_var GetUser(const unsigned int iIndex = 0) const = 0;

  /**
  * Get the Matrix of the interaction context.
  * This matrix represents the transformation from the real world to the virtual world.
  *
  * @return
  *   A @href CATMathTransformation representing the position and orientation of the interaction context.
  */
  virtual CATMathTransformation GetMatrix() const = 0;

  /**
   * Set the Matrix of the interaction context.
   *
   * @param iMatrix [in]
   *   The matrix represents the transformation from the real world to the virtual world.
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>The matrix has been correctly setted</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>The matrix has not been correctly setted</dd>
   *   </dl>
   */
  virtual HRESULT SetMatrix(const CATMathTransformation& iMatrix) = 0;

  /**
  * Get the scale of the interaction context.
  *
  * @return
  *   A double representing the scale applied to the interaction context.
  */
  virtual double GetScale() const = 0;

  /**
  * Get the scale of the model.
  *
  * @return
  *   A double representing the scale applied to the model.
  */
  virtual double GetModelScale() const = 0;
};

CATDeclareHandler(IVISUIInteractionContext, IVISUIElement);

#endif

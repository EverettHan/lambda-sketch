#ifndef IVISUIUser_H
#define IVISUIUser_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIPositionedElement.h"

class IVISUIHand;
class IVISUIHand_var;
class IVISUIHead;
class IVISUIHead_var;
class IVISUIPelvis;
class IVISUIPelvis_var;
class IVISUIController_var;

extern ExportedByIVInterfaces IID IID_IVISUIUser;

/**
* Interface representing a User.
*
* <strong>Role</strong>: The User is a specialization of PositionedElement representing the entire body of the user.
* The position and orientation of the User can be retrieved using @see IVISUIPositionedElement#GetPose .
* This Element is used as the root entity describing the user.
* Typical child entities are the User's Head and Hands.
* A useful information is the User's dominant hand, which is most likely to hold an interaction device, such as a wand.
*
* @example
* As an example, the following diagram represents a typical User with Head and Hands.
* <pre>
*             User
*              |
*     +--------+---------+
*     |        |         | 
* LeftHand    Head    RightHand
*              |
*           Cyclops
*              |
*         +----+----+
*         |         |
*      LeftEye   ightEye
*
* </pre>
*
* @see IVISUIPositionedElement, IVISUIInteractionContext, IVISUIHead, IVISUIHand, IVISUICyclops, IVISUIEye
*/
class ExportedByIVInterfaces IVISUIUser: public IVISUIPositionedElement
{

  CATDeclareInterface;

public:

  /**
  * Get the head of the user.
  *
  * @param [out] oHead
  *   A @href IVISUIHead representing the head of the user.
  * <br><strong>Precondition</strong>:
  * <tt>oHead</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oHead</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oHead</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oHead</tt> was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetHead(IVISUIHead*& oHead) const = 0;

  /**
  * Get the head of the user.
  *
  * @return
  *   A @href IVISUIHead representing the head of the user.
  */
  virtual IVISUIHead_var GetHead() const = 0;
  
  /**
  * Get the left hand of the user.
  *
  * @param [out] oLeftHand
  *   A @href IVISUIHand representing the left hand of the user.
  * <br><strong>Precondition</strong>:
  * <tt>oLeftHand</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oLeftHand</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oLeftHand</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oLeftHand</tt> was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetLeftHand(IVISUIHand*& oLeftHand) const = 0;

  /**
  * Get the left hand of the user.
  *
  * @return
  *   A @href IVISUIHand representing the left hand of the user.
  */
  virtual IVISUIHand_var GetLeftHand() const = 0;

  /**
  * Get the right hand of the user.
  *
  * @param [out] oRightHand
  *   A @href IVISUIHand representing the right hand of the user.
  * <br><strong>Precondition</strong>:
  * <tt>oRightHand</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oRightHand</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oRightHand</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oRightHand</tt> was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetRightHand(IVISUIHand*& oRightHand) const = 0;

  /**
  * Get the right hand of the user.
  *
  * @return
  *   A @href IVISUIHand representing the right hand of the user.
  */
  virtual IVISUIHand_var GetRightHand() const = 0;

  /**
  * Get the dominant hand of the user.
  * <strong>Role:</strong> The dominant hand, as opposed with the weak hand, is the hand with which the user is most likely to hold an interaction device, such as a wand.
  *
  * @param [out] oDominantHand
  *   A @href IVISUIHand representing the dominant hand of the user.
  * <br><strong>Precondition</strong>:
  * <tt>oDominantHand</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oDominantHand</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oDominantHand</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oDominantHand</tt> was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  *
  * @see #GetWeakHand
  */
  virtual HRESULT GetDominantHand(IVISUIHand*& oDominantHand) const = 0;

  /**
  * Get the dominant hand of the user.
  * <strong>Role:</strong> The dominant hand, as opposed with the weak hand, is the hand with which the user is most likely to hold an interaction device, such as a wand.
  *
  * @return
  *   A @href IVISUIHand representing the dominant hand of the user.
  */
  virtual IVISUIHand_var GetDominantHand() const = 0;
  
  /**
  * Get the WeakHand of the user.
  *
  * @param [out] oWeakHand
  *   A @href IVISUIHand representing the weak hand of the user.
  * <br><strong>Precondition</strong>:
  * <tt>oWeakHand</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oWeakHand</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oWeakHand</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oWeakHand</tt> was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetWeakHand(IVISUIHand*& oWeakHand) const = 0;

  /**
  * Get the WeakHand of the user.
  *
  * @return
  *   A @href IVISUIHand representing the weak hand of the user.
  */
  virtual IVISUIHand_var GetWeakHand() const = 0;

 /**
  * Allows to tell whether the user is right-handed or not.
  *
  * @param [out] oIsRightHanded
  *   An integer allowing to tell if the user is right-handed.
  * <br><strong>Precondition</strong>:
  * <tt>oIsRightHanded</tt> should be set to <tt>0</tt> before calling this method.
  * <br><strong>Legal values</strong>:
  * <tt>oIsRightHanded</tt> is either <tt>0</tt> or <tt>1</tt>.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oIsRightHanded</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oIsRightHanded</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oIsRightHanded</tt> was not set to <tt>0</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT IsRightHanded(unsigned int& oIsRightHanded) const = 0;

  /**
  * Allows to tell whether the user is right-handed or not.
  *
  * @return
  *   An integer allowing to tell if the user is right-handed.
  */
  virtual unsigned int IsRightHanded() const = 0;

 /**
  * Allows to set whether the user is right-handed or not.
  *
  * @param [in] iIsRightHanded
  *   An integer allowing to set if the user is right-handed.
  * <br><strong>Legal values</strong>:
  * <tt>iIsRightHanded</tt> is either <tt>0</tt> or <tt>1</tt>.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>iIsRightHanded</tt> is successfully set</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>iIsRightHanded</tt> could not be set</dd>
  *   </dl>
  */
  virtual HRESULT SetRightHanded(const unsigned int iIsRightHanded) = 0;

  /**
  * @nodoc
  * Get controller of the dominant hand of the user.
  * <strong>Role:</strong> The dominant hand, as opposed with the weak hand, is the hand with which the user is most likely to hold an interaction device, such as a wand.
  *
  * @return
  *   A @href IVISUIController representing controller of the dominant hand of the user.
  */
  virtual IVISUIController_var GetDominantController() const = 0;

  /**
  * @nodoc
  * Get controller of the weak hand of the user.
  * <strong>Role:</strong> The dominant hand, as opposed with the weak hand, is the hand with which the user is most likely to hold an interaction device, such as a wand.
  *
  * @return
  *   A @href IVISUIController representing controller of the weak hand of the user.
  */
  virtual IVISUIController_var GetWeakController() const = 0;

  /**
  * @nodoc
  * Get the pelvis of the user.
  *
  * @param [out] oPelvis
  *   A @href IVISUIPelvis representing the pelvis of the user skeleton.
  * <br><strong>Precondition</strong>:
  * <tt>oPelvis</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oPelvis</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oPelvis</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oPelvis</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetPelvis(IVISUIPelvis*& oPelvis) const = 0;

  /**
  * @nodoc
  * Get the pelvis of the user.
  *
  * @return
  *   A @href IVISUIPelvis representing the pelvis of the user skeleton.
  */
  virtual IVISUIPelvis_var GetPelvis() const = 0;

};

CATDeclareHandler(IVISUIUser, IVISUIPositionedElement);

#endif

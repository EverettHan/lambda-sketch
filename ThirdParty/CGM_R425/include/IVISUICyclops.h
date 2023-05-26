// COPYRIGHT DASSAULT SYSTEMES 2011
#ifndef IVISUICyclops_H
#define IVISUICyclops_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"

#include "IVISUIPositionedElement.h"

class IVISUIEye;

extern ExportedByIVInterfaces IID IID_IVISUICyclops;

/**
* Interface representing a point between the eyes of the user.
* <strong>Role</strong>: Cyclops is a specialization of PositionedElement representing the point between the user's eyes.
* Through inheritance, its position and orientation in the world can be retrieved. 
* The Cyclops provides access to information related to the user's eyes.
* It can be associated with two Eye Elements, each representing a user's eye.
* The Cyclops is also defined by an InterEyeDistance Parameter, representing the distance separating the user's eyes.
*
* @see IVISUIPositionedElement, IVISUIEye
*/
class ExportedByIVInterfaces IVISUICyclops: public IVISUIPositionedElement
{

  CATDeclareInterface;

public:

 /**
  * Retrieves the distance between the user's eyes as a double value.
  * It provides a more straightforward wy to retrieve the distance between the eyes than the @href #GetInterEyeDistanceParameter method.
  *
  * @param [out] oDistance
  *   The retrieved distance between the eyes of the user, expressed as a double value.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oDistance</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oDistance</tt> could not be retrieved</dd>
  *   </dl>
  */
  virtual HRESULT GetInterEyeDistance(double& oDistance) const = 0;

  /**
   * Sets the distance between the user's eyes.
   *
   * @param [in] iDistance
   *   The desired distance between the user's eyes.
   *
   * @return
   *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The desired <tt>iDistance</tt> is successfully set</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The desired <tt>iDistance</tt> could not be set</dd>
  *   </dl>
  */
  virtual HRESULT SetInterEyeDistance(double& iDistance) = 0;

 /**
  * Retrieves the left eye of the user.
  *
  * @param oLeftEye [out, IUnknown#Release]
  *   A @href IVISUIEye representing the left eye of the user.
  * <br><strong>Precondition</strong>:
  * <tt>oLeftEye</tt> should be set to <tt>NULL</tt> before calling this method.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oLeftEye</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oLeftEye</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oLeftEye</tt> Element was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetLeftEye(IVISUIEye*& oLeftEye) const = 0;

 /**
  * Retrieves the right eye of the user.
  *
  * @param oRightEye [out, IUnknown#Release]
  *   A @href IVISUIEye representing the right eye of the user.
  * <br><strong>Precondition</strong>:
  * <tt>oRightEye</tt> should be set to <tt>NULL</tt> before calling this method.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oRightEye</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oRightEye</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oRightEye</tt> Element was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetRightEye(IVISUIEye*& oRightEye) const = 0;
};

CATDeclareHandler(IVISUICyclops, IVISUIPositionedElement);

#endif

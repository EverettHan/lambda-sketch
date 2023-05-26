#ifndef IVISUIHead_H
#define IVISUIHead_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIPositionedElement.h"

class IVISUICyclops;
class IVISUICyclops_var;
class IVISUIScreen;
class IVISUIScreen_var;

extern ExportedByIVInterfaces IID IID_IVISUIHead;

/**
* Interface representing the user's head.
* <strong>Role</strong>: Head is a specialization of PositionedElement representing the head of the user.
* Through inheritance, its position and orientation in the world can be retrieved.
* In terms of semantic, the Head can be associated to a Cyclops Element.
* This Head-Cyclops association comes from the usage of tracking systems.
* Generally a tracker is associated with the head so that the information it provides is directly mapped to the head position and orientation.
* Nevertheless, depending on the kind of physical tracker used and its exact position relative to the head, an offset is used to accurately position the Cyclops relatively to the head position.
* The Cyclops position and orientation is then used to determine where exactly the user is looking.
*
* @see IVISUIPositionedElement, IVISUICyclops
*/

class ExportedByIVInterfaces IVISUIHead: public IVISUIPositionedElement
{

  CATDeclareInterface;

public:
  
 /**
  * @nodoc
  * Get the cyclops of the user.
  *
  * @param oCyclops [out, IUnknown#Release]
  *   A @href IVISUICyclops representing the cyclops of the user's head.
  * <br><strong>Precondition</strong>:
  * <tt>oCyclops</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oCyclops</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oCyclops</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oCyclops</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetCyclops(IVISUICyclops*& oCyclops) const = 0;

  /**
  * @nodoc
  * Get the cyclops of the user.
  *
  * @return
  *   A @href IVISUICyclops representing the cyclops of the user's head.
  */
  virtual IVISUICyclops_var GetCyclops() const = 0;
  
  /**
  * @nodoc
  * Get the screens count attached to the user'head for Head Mounted Displays.
  *
  * @param oNbScreens [out]
  *   The retrieved screens count associated with the user's head.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oNbScreens</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oNbScreens</tt> could not be retrieved</dd>
  *   </dl>
  */
  virtual HRESULT GetScreenCount(unsigned int& oNbScreens) const = 0;

  /**
  * @nodoc
  * Get the screens count attached to the user'head for Head Mounted Displays.
  *
  * @return
  *   The retrieved screens count associated with the user's head.
  */
  virtual unsigned int GetScreenCount() const = 0;
  
  /**
  * @nodoc
  * Get the screens attached to the user'head for Head Mounted Displays.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIScreen.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetScreenCount to get the @href IVISUIScreen count.
  * @param oScreen [out, IUnknown#Release] 
  *   A @href IVISUIScreen representing one screen associated with the user's head.
  * <br><strong>Precondition</strong>:
  * <tt>oScreen</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oScreen</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oScreen</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oScreen</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetScreen(const unsigned int iIndex, IVISUIScreen*& oScreen) const = 0;

  /**
  * @nodoc
  * Get the screens attached to the user'head for Head Mounted Displays.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIScreen.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetScreenCount to get the @href IVISUIScreen count.
  * @return
  *   A @href IVISUIScreen representing one screen associated with the user's head.
  */
  virtual IVISUIScreen_var GetScreen(const unsigned int iIndex = 0) const = 0;

};

CATDeclareHandler(IVISUIHead, IVISUIPositionedElement);

#endif

#ifndef IVISUIPhysicalEnvironment_H
#define IVISUIPhysicalEnvironment_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIPositionedElement.h"

class IVISUIScreen;
class IVISUIScreen_var;
class IVISUIMarker;
class IVISUIMarker_var;

extern ExportedByIVInterfaces IID IID_IVISUIPhysicalEnvironment;

/**
* Interface representing the physical environment.
* <strong>Role</strong>: PhysicalEnvironment is a specialization of PositionedElement representing the physical environment in which the interaction occurs.
* Through inheritance, its position and orientation in the world can be retrieved.
* This Element is used as the root entity to describe the physical environment.
* Only one physical environment can exist per interaction context.
*
* @see IVISUIPositionedElement, IVISUIInteractionContext
*/

class ExportedByIVInterfaces IVISUIPhysicalEnvironment: public IVISUIPositionedElement
{

  CATDeclareInterface;

public:

 /**
  * @nodoc
  * Get the number of screens in the physical environement.
  *
  * @param oNbScreens [out]
  *   The number of screens into the physical environment.
  * <br><strong>Precondition</strong>:
  * <tt>oNbScreens</tt> should be set to <tt>0</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd><tt>oNbScreens</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd><tt>oNbScreens</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oNbScreens</tt> parameter was not set to <tt>0</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetScreenCount(unsigned int& oNbScreens) const = 0;

  /**
  * @nodoc
  * Get the number of screens in the physical environement.
  *
  * @return
  *   The number of screens into the physical environment.
  */
  virtual unsigned int GetScreenCount() const = 0;

 /**
  * @nodoc
  * Get a screen by its index.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIScreen.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetScreenCount to get the @href IVISUIScreen count.
  * @param oScreen [out, IUnknown#Release]
  *   The retrieved @href IVISUIScreen.
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
  * Get a screen by its index.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIScreen.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetScreenCount to get the @href IVISUIScreen count.
  * @return
  *   The retrieved @href IVISUIScreen.
  */
  virtual IVISUIScreen_var GetScreen(const unsigned int iIndex = 0) const = 0;

 /**
  * @nodoc
  * Get the number of markers in the physical environement.
  *
  * @param oNbMarkers [out]
  *   The number of markers into the physical environment.
  * <br><strong>Precondition</strong>:
  * <tt>oNbMarkers</tt> should be set to <tt>0</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd><tt>oNbMarkers</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd><tt>oNbMarkers</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oNbMarkers</tt> parameter was not set to <tt>0</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetMarkerCount(unsigned int& oNbMarkers) const = 0;

  /**
  * @nodoc
  * Get the number of markers in the physical environement.
  *
  * @return
  *   The number of markers into the physical environment.
  */
  virtual unsigned int GetMarkerCount() const = 0;

 /**
  * @nodoc
  * Get a marker by its index.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIMarker.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetMarkerCount to get the @href IVISUIMarker count.
  * @param oMarker [out]
  *   The retrieved @href IVISUIMarker.
  * <br><strong>Precondition</strong>:
  * <tt>oMarker</tt> should be set to <tt>NULL</tt> before calling this method.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oMarker</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oMarker</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oMarker</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetMarker(const unsigned int iIndex, IVISUIMarker*& oMarker) const = 0;

  /**
  * @nodoc
  * Get a marker by its index.
  *
  * @param iIndex [in]
  *   The index of the @href IVISUIMarker.
  * <br><strong>Legal values</strong>:
  * <tt>iIndex</tt> range starts with <tt>0</tt>. Use @href #GetMarkerCount to get the @href IVISUIMarker count.
  * @return
  *   The retrieved @href IVISUIMarker.
  */
  virtual IVISUIMarker_var GetMarker(const unsigned int iIndex = 0) const = 0;

};

CATDeclareHandler(IVISUIPhysicalEnvironment, IVISUIPositionedElement);

#endif

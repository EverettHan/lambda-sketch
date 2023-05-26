/* -*-c++-*- */
#ifndef CATIVisPropertiesAbstract_H
#define CATIVisPropertiesAbstract_H

//
// COPYRIGHT DASSAULT SYSTEMES 1999
//

/**
 * @CAA2Level L1
 * @CAA2Usage U6
 */

class CATPathElement;
class CATIModelEvents;

#include "CATBaseUnknown.h"
#include "CATPickMode.h"
#include "CATShowAttribut.h"
#include "CATSymbolType.h"
#include "CATVisPropertiesValues.h"
#include "CATGraphicAttributeSet.h"
#include "CATVisPropertyAction.h"
#include "CATVisPropertyType.h"
#include "CATVisPropertyEditorType.h"
#include "CATVisGeomType.h"
#include "CATErrorDef.h"

#ifndef S_READONLY
/** @nodoc */
#define S_READONLY  MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 0x200 + 01 )
#endif

#ifndef S_UNDEFINED
/** @nodoc */
#define S_UNDEFINED MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 0x200 + 02 )
#endif

#ifndef S_AUTOMATIC
/** @nodoc */
#define S_AUTOMATIC MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 0x200 + 03 )
#endif

/**
 * Base class  for graphic properties interface.
 * <b>Role</b>: This class defines all methods of @href CATIVisProperties.
 */

class ExportedByCATVisItf CATIVisPropertiesAbstract : public CATBaseUnknown
{
public:

  /** @nodoc */
  virtual HRESULT SetProperties   ( CATVisPropertiesValues & iValues,
                                    CATVisPropertyType       iPropertyType,
                                    CATPathElement         & iPathElement,
                                    int                      iNotify = 1)                   = 0;

  /** @nodoc */
  virtual HRESULT ResetProperties ( CATVisPropertyType       iPropertyType,
                                    CATPathElement         & iPathElement, 
                                    int                      iNotify = 1)                   = 0;
  /** @nodoc */
  virtual HRESULT GetProperties   ( CATVisPropertiesValues & ioValues,
                                    CATVisPropertyType       iPropertyType,
                                    CATPathElement         & iPathElement)                  = 0;

  /**
  * Sets a graphic properties set.
  * <br><b>Role</b>: Sets graphic properties on the component.
  * @param iValues
  * The set of graphic properties
  * @param iPropertyType
  * Define the type of property: color, opacity, ... To know the valid property types 
  * for iGeomType see @href CATVisGeomType
  * @param iGeomType
  * Define the type of geometry: edge, line, mesh , ... 
  * <br><b>Default value</b>:CATVPGlobalType.
  * @param iPropertyNumber
  * Parameter not yet used.
  * <br><b>Default value</b>:0
  * @param ifromSetProperties
  * Parameter not yet used.
  * <br><b>Default value</b>:0
  * @return
  * <b>Legal values:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The operation is OK
  * <dt><tt>E_FAIL</tt>
  * <dd>
  * <ul>
  * <li>iGeomType is not defined for the object </li>
  * <li>The object doesn't implement CATIProperty</li>
  * <li>The property iPropertyType of iValues are not set</li>
  * <li> iPropertyType is not <tt>CATVPShow</tt>, <tt>CATVPPick</tt> or 
  * <tt>CATVPLayer</tt> if iGeomType is <tt>CATVPGlobalType</tt>
  * </ul>
  * </dl>
  */
  virtual HRESULT SetPropertiesAtt   ( CATVisPropertiesValues & iValues,
                                       CATVisPropertyType       iPropertyType,
                                       CATVisGeomType           iGeomType = CATVPGlobalType,
                                       unsigned int             iPropertyNumber   = 0,
                                       int                      ifromSetProperties = 0)      = 0;

  /**
  * Resets a graphic property.
  * <br><b>Role</b>: The graphic property becomes the standard. see @href #GetStandardProperties 
  * to know the standard value of the graphic property.
  * <br>The graphic property becomes invalid and so the
  * property becomes unknown for @href CATIProperty.  
  * @param iPropertyType
  * Define the type of property: color, opacity, ... To know the valid property types 
  * for a iGeomType see @href CATVisGeomType
  * @param iGeomType
  * Define the type of geometry: edge, line, mesh , ... 
  * <br><b>Default value</b>:CATVPGlobalType.
  * @param iPropertyNumber
  * Parameter not yet used.
  * <br><b>Default value</b>:0
  * @param ifromSetProperties
  * Parameter not yet used.
  * <br><b>Default value</b>:0
  * @return
  * <b>Legal values:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The operation is OK
  * <dt><tt>E_FAIL</tt>
  * <dd>Fail's causes:
  * <ul>
  * <li>iGeomType is not defined for the object </li>
  * <li>The object doesn't implement CATIProperty</li>
  * <li> iPropertyType is not <tt>CATVPShow</tt>, <tt>CATVPPick</tt> or 
  * <tt>CATVPLayer</tt> if iGeomType is <tt>CATVPGlobalType</tt>
  * </ul>
  * </dl>
  */
  virtual HRESULT ResetPropertiesAtt ( CATVisPropertyType iPropertyType,
                                       CATVisGeomType     iGeomType = CATVPGlobalType,
                                       unsigned int       iPropertyNumber     = 0,
                                       int                ifromResetProperties = 0)          = 0;

  /**
  * Retrieves a graphic properties set.
  * <br><b>Role</b>:This method returns the value set by @href #SetPropertiesAtt, or the 
  * the value given by @href #GetStandardProperties, if the graphic properties has not been set
  * or the property has been reseted by @href #ResetPropertiesAtt
  * @param ioValues
  * The set of graphic properties
  * @param iPropertyType
  * Define the type of property: color, opacity, ... To know the valid property types 
  * for a iGeomType see @href CATVisGeomType
  * @param iGeomType
  * Define the type of geometry: edge, line, mesh , ... 
  * <br><b>Default value</b>:CATVPGlobalType.
  * @param iPropertyNumber
  * Parameter not yet used.
  * <br><b>Default value</b>:0
  * @param ifromSetProperties
  * Parameter not yet used.
  * <br><b>Default value</b>:0
  * @return
  * <b>Legal values:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The operation is OK, and the value is not the standard
  * <dt><tt>S_AUTOMATIC</tt>
  * <dd>The operation is OK, and the value is the standard
  * <dt><tt>E_FAIL</tt>
  * <dd>Fail's causes:
  * <ul>
  * <li>iGeomType is not defined for the object </li>
  * <li>The object doesn't implement CATIProperty</li>
  * <li> iPropertyType is not <tt>CATVPShow</tt>, <tt>CATVPPick</tt> or 
  * <tt>CATVPLayer</tt> if iGeomType is <tt>CATVPGlobalType</tt>
  * <li> There is no standard value for this property</li>
  * </ul>
  * </dl>
  */
  virtual HRESULT GetPropertiesAtt   ( CATVisPropertiesValues & ioValues,
                                       CATVisPropertyType       iPropertyType,
                                       CATVisGeomType           iGeomType  = CATVPGlobalType,
                                       unsigned int             iPropertyNumber   = 0,
                                       int                      ifromGetProperties = 0)      = 0;


 /**
  * Retrieves standard graphic properties set.
  * @param ioValues
  * The set of graphic properties
  * @param iPropertyType
  * Define the type of property: color, opacity, ... To know the valid property types 
  * for a iGeomType see @href CATVisGeomType
  * @param iGeomType
  * Define the type of geometry: edge, line, mesh , ... 
  * <br><b>Default value</b>:CATVPGlobalType. 
  * @return
  * <b>Legal values:</b>
  * <dl>
  * <dt><tt>S_AUTOMATIC</tt>
  * <dd>A standard value exists.
  * <dt><tt>E_FAIL</tt>
  * <dd>Fail's causes:
  * <ul>
  * <li>iGeomType is not defined for the object </li>
  * <li>The object doen't implement CATIProperty</li>
  * <li> iPropertyType is not <tt>CATVPShow</tt>, <tt>CATVPPick</tt> or 
  * <tt>CATVPLayer</tt> if iGeomType is <tt>CATVPGlobalType</tt>
  * <li> There is no standard value for this property</li>
  * <li> No standard value exists for this property.
  * </ul>
  * </dl> 
  */
  virtual HRESULT GetStandardProperties ( CATVisPropertiesValues & ioValues,
                                          CATVisPropertyType       iPropertyType,
                                          CATVisGeomType           iGeomType = CATVPGlobalType) = 0;


  /**
  * Gives the appropriated geometry type for the Graphic Properties Toolbar.
  * <br><b>Role</b>: 
  * Suppose you have selected a Solid. The solid has a color for its edges and a color
  * for faces. In the Edit Properties Command you can affect a color for each composant of your
  * solid. But in the Graphic Properties Toolbar, there is only one combo to choose a color. 
  * This method allows you to select the type of geometry in relationship for a given property type.
  * <br>This method must be mandatory redefined in your own data extension. 
  * @param iPathElement
  *  Precise the environment of the component. In most case you don't have need of this entry. 
  * @param iPropertyType
  *   The type of property 
  * @param oGeomType
  *   Return the geometric type valid for iPropertyType
  * @param oPropertyNumber
  *   Return the property number to use. Set 0
  * @return
  * <dt><tt>S_OK</tt>
  * <dd>
  * <dt><tt>E_FAIL</tt>
  * <dd>
  * </dl>
  */
  virtual HRESULT GetSubTypeFromPath(CATPathElement     & iPathElement,
                                     CATVisPropertyType   iPropertyType,
                                     CATVisGeomType     & oGeomType,
                                     unsigned int       & oPropertyNumber )    = 0;



  /**
  * Retrieves if a given geometry type is defined.
  * <br><b>Role</b>
  * This method allows you to know if a given type of geometry is valid for your
  * component. 
  * <br>This method must be mandatory redefined in your own data extension. 
  * @param iGeomType
  *   The geometric type
  * @return
  *  <b>Legal value</b>:
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>iGeomType is defined for the object.
  * <dt><tt>E_FAIL</tt>
  * <dd>iGeomType isn't defined for the object.
  * </dl>
  */
  virtual HRESULT IsGeomTypeDefined (CATVisGeomType& iGeomType) = 0;


  /**
  * @nodoc
  * This function must return the real owner of the visualization properties.
  * @param iAction
  *   The type of action in use Get, Set or Reset
  * @return
  *   A CATIVisuPropertiesAbstract* on the owner. 
  */
  virtual CATIVisPropertiesAbstract * GetPropertyOwner(CATVisPropertyAction iAction,
                                                       CATVisGeomType       iGeomType,
                                                       unsigned int         iPropertyNumber=0) = 0;
  
   /**
  * @nodoc 
  * This function is called to find the most appropriated CATIModelEvents sender to use
  * to send a notification to update the visualization.
  *
  * @param iPathElement
  *   CATPathElement that precise the environment of the object 
  *   you want to modify the visu properties.
  * @return
  *   The CATIModelEvents pointer to use.
  */
  virtual CATIModelEvents* FindSender (CATPathElement & iPathElement) = 0;


   /**
  * @nodoc
  * Gives the number of properties defined for a given type of property.
  *
  * @param iVisProperty
  *   The type of property to read or write.
  * @return
  *   The total of property defined for this type of property.
  */
  virtual unsigned int GetPropertyNumber (CATVisGeomType iVisProperty) = 0;


  /** @nodoc */
  virtual HRESULT GetGraphicAttributSet (CATGraphicAttributeSet & oAttributSet,
                                         CATVisGeomType           iGeomType,
                                         unsigned int             iPropertyNumber = 0)       = 0;
  /** @nodoc */
  virtual HRESULT IsEditableBy(CATVisPropertyEditorType iEditorType) = 0;
};

#endif

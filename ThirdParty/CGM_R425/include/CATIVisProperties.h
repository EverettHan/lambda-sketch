/* -*-c++-*- */
#ifndef CATIVisProperties_H
#define CATIVisProperties_H

//
// COPYRIGHT DASSAULT SYSTEMES 1999
//


/**
 * @CAA2Level L1
 * @CAA2Usage U4  CATExtIVisProperties
 */

#include "CATIVisPropertiesAbstract.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIVisProperties;
#else
extern "C" const IID IID_CATIVisProperties;
#endif


/**
 * Interface to manage graphic properties.
 * <b>Role</b>:Your component has a set of "objects" , line, surface, ..., 
 * which are defined by their @href CATVisGeomType. 
 * Each "object" has a set of graphic properties. With this 
 * interface you read / write these "objects". 
 * <br>
 * You should implement this interface in a data extension of the component that implements
 * an interface which derives from @href CATIVisu, such as @href CATI3DGeoVisu or @href
 * CATI2DGeoVisu. This data extension should derive from the supplied @href CATExtIVisProperties
 * adapter class. 
 * <br>
 * To store properties on your component there is the @href CATIProperty. When you set 
 * graphic properties thanks to <tt>CATIVisProperties</tt>, you also modify the value in 
 * <tt>CATIProperty</tt>. So your component must implement these 2 interfaces to have
 * graphic properties.
 * <br>
 * All methods of this interface are defined in the 
 * @href CATIVisPropertiesAbstract base interface.
 * In this base class you find the methods to manage the graphic 
 * properties on your component.
 * <ul>
 * <li> @href CATIVisPropertiesAbstract#SetPropertiesAtt </li>
 * <br>To set a graphic property
 * <li> @href CATIVisPropertiesAbstract#GetPropertiesAtt </li>
 * <br>To retrieve a graphic property
 * <li> @href CATIVisPropertiesAbstract#ResetPropertiesAtt </li>
 * <br>To reset a graphic property to the standard, 
 * <li> @href CATIVisPropertiesAbstract#IsGeomTypeDefined </li>
 * <br>To know if your component is assigned a valid geometry type
 * </ul>
 * <p><b>BOA information</b>: this interface can be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page. 
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 * @see CATVisPropertiesValues, CATVisGeomType, CATVisPropertyType 
 */

class ExportedByCATVisItf CATIVisProperties : public CATIVisPropertiesAbstract
{
  // macros
  CATDeclareInterface;

public:


};


/** @nodoc */

CATDeclareHandler(CATIVisProperties,CATBaseUnknown);

#endif // CATIVisProperties

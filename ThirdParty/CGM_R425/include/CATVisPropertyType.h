/* -*-c++-*- */
#ifndef CATVisPropertyType_H
#define CATVisPropertyType_H
//
// COPYRIGHT DASSAULT SYSTEMES 1999
//
#include "CATIAV5Level.h"

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
* Defines the type of graphic property. 
* <b>Role</b>: Defines the graphic information to read/write on a @href CATVisPropertiesValues.
* <br>This enumeration is used in these methods:
* <ul>
* <li>@href CATIVisPropertiesAbstract#GetPropertiesAtt  </li>
* <li>@href CATIVisPropertiesAbstract#SetPropertiesAtt  </li>
* <li>@href CATIVisPropertiesAbstract#ResetPropertiesAtt </li> 
* </ul>
* @param   CATVPColor
* The information is a color. 
* @param   CATVPOpacity
* The information is an opacity.
* @param   CATVPSymbol
* The information is a symbol point.
* @param   CATVPLineType
* The information is a line type.
* @param   CATVPWidth
* The information is a line width.
* @param   CATVPInheritance
* The information is the <i>set</i> of all inheritance flags. 
* @param   CATVPLayer
* The information is a number of layer
* @param   CATVPShow
* The information is the visibility 
* @param   CATVPPick
* The information is the selectionability 
* @param   CATVPAllPropertyType
* With this value you read/write a set of property. So with an unique call you have
* information which regroup these properties:
* <ul>
* <li>CATVPColor</li>
* <li>CATVPOpacity</li>
* <li>CATVPSymbol</li>
* <li>CATVPLineType</li>
* <li>CATVPWidth</li>
* <li>CATVPInheritance</li>
* </ul>
* @see CATIVisProperties, CATIVisPropertiesAbstract
*/


enum CATVisPropertyType {
  CATVPColor,
  CATVPOpacity,
  CATVPSymbol,
  CATVPLineType,
  CATVPWidth,
  CATVPInheritance,
  CATVPLayer,
  CATVPShow,
  CATVPPick,
  CATVPLowInt,
  CATVPRenderingStyle,
  CATVPEffect,
  CATVPAllPropertyType
};

#endif

/* -*-c++-*- */
#ifndef CATVisGeomType_H
#define CATVisGeomType_H
//
// COPYRIGHT DASSAULT SYSTEMES 1999
//

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/** 
* Defines a geometric type with its own graphic properties.
* <b>Role</b>: This type is used in the @href CATIVisProperties interface.
* <br> For each type we give the set of @href CATVisPropertyType to use in these methods:
* <ul>
* <li>@href CATIVisPropertiesAbstract#GetPropertiesAtt  </li>
* <li>@href CATIVisPropertiesAbstract#SetPropertiesAtt  </li>
* <li>@href CATIVisPropertiesAbstract#ResetPropertiesAtt </li> 
* </ul>
* <br>To know if a geometric type is valid of your component, use the 
* @href CATIVisPropertiesAbstract#IsGeomTypeDefined. 
* <br><br><b>Legal values </b>:
* <dl>
* <b><dt><tt>CATVPGlobalType</tt></b>
* <dd>This type defines the group of property types:
* <ul>
* <li></tt>CATVPPick</tt>
* <li></tt>CATVPShow</tt>
* <li></tt>CATVPLayer</tt>
* </ul>
* <b><dt><tt>CATVPMesh</tt></b>
* <dd> The geometry is surfacic. 
* <br>This geometry uses these property types:
* <ul>
* <li></tt>CATVPColor</tt>
* <li></tt>CATVPOpacity</tt>
* </ul>
* <b><dt><tt>CATVPEdge</tt></b>
* <dd> The geometry is an edge.
* <br>This geometry uses these property types:
* <ul>
* <li></tt>CATVPColor</tt>
* <li></tt>CATVPWidth</tt>
* <li></tt>CATVPLineType</tt>
* </ul>
* <b><dt><tt>CATVPLine</tt></b>
* <dd>The geometry is a line.
* <br>This geometry uses these property types:
* <ul>
* <li></tt>CATVPColor</tt>
* <li></tt>CATVPWidth</tt>
* <li></tt>CATVPLineType</tt>
* </ul>
* <b><dt><tt>CATVPPoint</tt></b>
* <dd>The geometry is a point.
* <br>This geometry uses these property types:
* <ul>
* <li></tt>CATVPColor</tt>
* <li></tt>CATVPSymbol</tt>
* </ul>
* <b><dt><tt>CATVPAsm</tt></b>
* <dd>The geometry is a set of geometry. This type allows you to have inheritance. 
* <br>This geometry uses these property types:
* <ul>
* <li></tt>CATVPColor</tt>
* <li></tt>CATVPInheritance</tt>
* <li></tt>CATVPWidth</tt>
* <li></tt>CATVPLineType</tt>
* <li></tt>CATVPOpacity</tt>
* </ul>
* </dl>
*/
typedef int CATVisGeomType;

/** @nodoc 
* the zero value is reserved and must not be used for an application type
*/
#define CATVPGlobalType 0       
/** @nodoc */
#define CATVPMesh       1
/** @nodoc */
#define CATVPEdge       2
/** @nodoc */
#define CATVPLine       3    
/** @nodoc */
#define CATVPPoint      4
/** @nodoc */
#define CATVPAsm        5


#endif

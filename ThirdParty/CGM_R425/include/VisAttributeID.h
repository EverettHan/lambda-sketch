#ifndef VISATTRIBUTEID_H
#define VISATTRIBUTEID_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * Defines the kind of attributes that can be retrieved or set on a Visualization object.
 * @param VIS_INDEXED_COLOR
 * The indexed color of an object.
 * <br><b>Legal values</b>: This color ranges from 0 to 255. See @href CATPredefinedColorName to have the list of predefined colors.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_RED_COLOR_COMPONENT
 * The red component of an object color.
 * <br><b>Legal values</b>: This color ranges from 0 to 255, corresponding to the 0.0 to 1.0 interval.
 * <br>They can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * <br> - @href VIS_FLOAT
 * <br> - @href VIS_DOUBLE
 * @param VIS_GREEN_COLOR_COMPONENT
 * The green component of an object color.
 * <br><b>Legal values</b>: This color ranges from 0 to 255, corresponding to the 0.0 to 1.0 interval.
 * <br>They can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * <br> - @href VIS_FLOAT
 * <br> - @href VIS_DOUBLE
 * @param VIS_BLUE_COLOR_COMPONENT
 * The blue component of an object color.
 * <br><b>Legal values</b>: This color ranges from 0 to 255, corresponding to the 0.0 to 1.0 interval.
 * <br>They can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * <br> - @href VIS_FLOAT
 * <br> - @href VIS_DOUBLE
 * @param VIS_ALPHA_COLOR_COMPONENT
 * The alpha component of an object color.
 * <br><b>Legal values</b>: This color ranges from 0 to 255, corresponding to the 0.0 to 1.0 interval.
 * <br>They can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * <br> - @href VIS_FLOAT
 * <br> - @href VIS_DOUBLE
 * @param VIS_RGBA_COLOR
 * The red, green, blue and alpha components of an object color.
 * <br><b>Legal values</b>: All four colors range from 0 to 255, corresponding to the 0.0 to 1.0 interval.
 * <br>They can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR_4
 * <br> - @href VIS_UNSIGNED_SHORT_4
 * <br> - @href VIS_UNSIGNED_INT_4
 * <br> - @href VIS_SHORT_4
 * <br> - @href VIS_INT_4
 * <br> - @href VIS_FLOAT_4
 * <br> - @href VIS_DOUBLE_4
 * @param VIS_LINE_TYPE
 * The line type.
 * <br><b>Legal values</b>: the line type ranges from 0 to 63.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_CHAR
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_LINE_THICKNESS
 * The line type.
 * <br><b>Legal values</b>: the line thickness ranges from 0 to 63.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_CHAR
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_ELEMENT_TYPE
 * The element type.
 * <br><b>Legal values</b>: the element type ranges from 0 to 3.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_CHAR
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_PICK_MODE
 * The picking mode.
 * <br><b>Legal values</b>: the picking mode ranges from 0 to 1.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_CHAR
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_PRIORITY
 * The selection priority.
 * <br><b>Legal values</b>: the selection type ranges from 0 to 15.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_CHAR
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_INHERITANCE_MODE
 * The inheritance mode of a Node. This attribute doesn't exist for Primitives.
 * <br><b>Legal values</b>: This mode can be any combination of the following values:
 * <br> - @href CATRep::COLOR_INHERITANCE
 * <br> - @href CATRep::LINEWIDTH_INHERITANCE
 * <br> - @href CATRep::LINETYPE_INHERITANCE
 * <br> - @href CATRep::RESET_INHERITANCE
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_INT
 * @param VIS_SHOW_MODE
 * The show mode.
 * <br><b>Legal values</b>: the show mode ranges from 0 to 1.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_CHAR
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_TRANSPARENCY_MODE
 * The transparency mode.
 * <br><b>Legal values</b>: the transparency mode ranges from 0 to 1.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_CHAR
 * <br> - @href VIS_UNSIGNED_SHORT
 * <br> - @href VIS_UNSIGNED_INT
 * <br> - @href VIS_CHAR
 * <br> - @href VIS_SHORT
 * <br> - @href VIS_INT
 * @param VIS_POSITION_MATRIX
 * The positioning matrix of a Node. This attribute doesn't exist for Primitives.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_FLOAT_16
 * <br> - @href VIS_DOUBLE_16
 * <br> - @href VIS_MATRIX_4x4
 * @param VIS_TEXTURE_MATRIX
 * The texture matrix of a Node. This attribute doesn't exist for Primitives.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_FLOAT_16
 * <br> - @href VIS_DOUBLE_16
 * <br> - @href VIS_MATRIX_4x4
 * @param VIS_RENDERING_MODE
 * The rendering mode of a Node. It is is a Bitwise OR of masks. This attribute doesn't exist for Primitives.
 * <br><b>Legal values</b>: VIS_GOURAUD, VIS_WIREFRAME, VIS_MATERIAL.
 * <ul>
 *   <li> VIS_SMOOTH_SHADING : Faces of 3D objects are seen in smooth shading.</li>
 *   <li> VIS_TEXTURED_SHADING : Face of 3D objects are seen in smooth + texture shading.</li>
 *   <li> VIS_WIREFRAME : Points and Lines of 3D objects are seen.</li>
 * </ul>
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_UNSIGNED_INT
 * @param VIS_FIXED_SIZE : DEPRECATED Use VisSG3DFixedSizeNodeGroup
 * Fix the screen size in mm of a Node. This attribute doesn't exist for Primitives.
 * <br>It can be retrieved or set in the following types: 
 * <br> - @href VIS_FLOAT
 * <br> - @href VIS_DOUBLE
 */
typedef enum _VisAttributeID
{
  VIS_INDEXED_COLOR,
  VIS_RED_COLOR_COMPONENT,
  VIS_GREEN_COLOR_COMPONENT,
  VIS_BLUE_COLOR_COMPONENT,
  VIS_ALPHA_COLOR_COMPONENT,
  VIS_RGBA_COLOR,
  VIS_LINE_TYPE,
  VIS_LINE_THICKNESS,
  VIS_PICK_MODE,
  VIS_ELEMENT_TYPE,
  VIS_PRIORITY,
  VIS_SHOW_MODE,
  VIS_TRANSPARENCY_MODE,
  VIS_INHERITANCE_MODE,
  VIS_POSITION_MATRIX,
  VIS_TEXTURE_MATRIX,
  VIS_RENDERING_MODE,
  VIS_FIXED_SIZE,
  VIS_POINT_TYPE,
  VIS_POINT_SIZE,
  VIS_USER_ATTRIBUTE_0,
  VIS_USER_ATTRIBUTE_1,
  VIS_USER_ATTRIBUTE_2,
  VIS_USER_ATTRIBUTE_3,
  VIS_PRIVATE_INSTANCING,
  VIS_PRIVATE_TRANSIENT_RAWBUFFERPTR

} VisAttributeID;

typedef enum _VisRenderingModeValue
{
  VIS_SMOOTH_SHADING = 1,
  VIS_WIREFRAME = 2,
  VIS_TEXTURED_SHADING = 8,
} VisRenderingModeValue;

/**  @nodoc  */ 
#define VIS_ATTRIBURE_ID_COUNT 26

#endif // VISATTRIBUTEID_H

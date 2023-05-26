#ifndef _AnchorPoint_H
#define _AnchorPoint_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
* Position of an AnnotationText relatively to its base point.
*
* @param BOTTOM_LEFT     The base point is at the bottom and on the left of the text
* @param BOTTOM_CENTER   The base point is at the bottom and at the center of the text
* @param BOTTOM_RIGHT    The base point is at the bottom and on the right of the text
* @param BASE_LEFT       The base point is on the base line and on the left of the text
* @param BASE_CENTER     The base point is on the base line and at the center of the texqt
* @param BASE_RIGHT      The base point is on the base line and a the right of the text
* @param TOP_LEFT        The base poit is at the top and at the left of the text
* @param TOP_CENTER      The base point is at the top and at the center of the text
* @param TOP_RIGHT       The base point is at the top and at the right of the text
* @see CAT2DAnnotationTextGP, CAT3DAnnotationTextGP
*/
enum CATAnchorPoint
{
 BOTTOM_LEFT,
 BOTTOM_CENTER,
 BOTTOM_RIGHT,
 BASE_LEFT,
 BASE_CENTER,
 BASE_RIGHT,
 TOP_LEFT,
 TOP_CENTER,
 TOP_RIGHT
};

/** @nodoc */
typedef CATAnchorPoint AnchorPoint;

#endif

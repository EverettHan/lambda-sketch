/* -*-c++-*- */
#ifndef _CATREPMODE_H_
#define _CATREPMODE_H_
// COPYRIGHT DASSAULT SYSTEMES  2005
/** @CAA2Required */

/**
 * Representation mode.
 * @param CATPrd3D
 *     representation of 3D kind.
 * @param CATPrd2D
 *     representation of 2D kind. Do not use.
 * @param CATPrdText
 *     representation of text kind. Do not use.
 * @see CATIMovable
 */
enum CATRepMode
{
	CATPrd3D,
	CATPrd2D,
	CATPrdText
};
#endif

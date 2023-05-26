//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/06/21
//===================================================================
// CATVisInvalidationToken.h
//===================================================================
//  2010/06/21 Creation: jov
//===================================================================
#ifndef CATVisInvalidationToken_H
#define CATVisInvalidationToken_H
/**
 * @CAA2Level L0
 * @CAA2Usage U0
 */
 
/** @file */ //necessary for doxygen documentation purpose

/**
* Enumerates the way a viewer can be invalidated.
* It is used by the VisuManager and CATViewpoint for example.
*/
enum CATVisInvalidationToken{
  /** The PickPath is the result of the picking. It can be invalidate 
  for example if a representation located under the mouse disappear.*/
  PickPath       = 1,
  /** The pixels are very often invalidated, involving a redraw 
  of the scene. This redraw can be decicated to a given RepresentationRole */
  Pixels         = 1<<1,
  /** The environment is invalidated automatically in some scenario, for example
  when the bounding element of the scene is invalidated. But an update can be
  necessary independently, for example after deletion of some reprentations*/
  Environment    = 1<<2
};

#endif

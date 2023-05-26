#ifndef IVISUIPositionedElement_H
#define IVISUIPositionedElement_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIElement.h"

class CATMathTransformation;
class CATMathPoint;

extern ExportedByIVInterfaces IID IID_IVISUIPositionedElement;

/**
* Interface representing a Positioned Element.
* <strong>Role</strong>: A Positioned Element is an Element with pose information, i.e. a position and an orientation.
* This pose is typically modified by an interaction device, and can be retrieved using #GetPhysicalLocalMatrix
* The position of the Element in the virtual world can be easily obtained by calling #GetVirtualGlobalMatrix
*
* @see IVISUIElement, IVIDevice
*/
class ExportedByIVInterfaces IVISUIPositionedElement : public IVISUIElement
{

  CATDeclareInterface;

public:

  /**
  * Get the global pose of the current Element in the virtual world.
  * This pose is obtained by recusrively multiplying the physical local matrix, given by #GetPhysicalLocalMatrix, with each physical local matrix of the Element's hierarchy.
  * Eventually, the matrix is multiplied by the matrix of the Interaction Context, i.e. the transformation from the real to the virtual world.
  * Use this method when you need to position a representation of an Element in the virtual world.
  *
  * @return
  *   A @href CATMathTransformation representing the position and orientation of the Element relative to the origin of the virtual world.
  */
  virtual CATMathTransformation GetVirtualGlobalMatrix() const = 0;

  /**
  * Get the global pose of the current Element in the virtual world.
  * This pose is obtained by recusrively multiplying the physical local matrix, given by #GetPhysicalLocalMatrix, with each physical local matrix of the Element's hierarchy.
  * Eventually, the matrix is multiplied by the matrix of the Interaction Context, i.e. the transformation from the real to the virtual world.
  * Use this method when you need to position a representation of an Element in the virtual world.
  *
  * @return
  *   A @href CATMathTransformation representing the position and orientation of the Element relative to the origin of the virtual world.
  */
  virtual CATMathPoint GetVirtualGlobalPose() const = 0;

  /**
  * Get the local pose of the Element in the real world.
  * Use this method when you need to know the pose of an element in the real world relative to its parent.
  *
  * @return
  *   A @href CATMathTransformation representing the position and orientation of the Element in the real world relative to its parent.
  */
  virtual CATMathTransformation GetPhysicalLocalMatrix() const = 0;

   /**
   * Set the local pose of the currrent Element is the real world.
   *
   * @param iPhysicalLocalMatrix [in]
   *   The @href CATMathTransformation representing the position and orientation of the Element in the real world relative to its parent.
   */
  virtual void SetPhysicalLocalMatrix(const CATMathTransformation& iPhysicalLocalMatrix) = 0;

  /**
  * Get the global pose of the current Element in the real world.
  * This pose is obtained by recusrively multiplying the physical local matrix, given by #GetPhysicalLocalMatrix, with physical each local matrix of the Element's hierarchy.
  * Use this method when you need to know the absolute pose of an element in the real world.
  *
  * @return
  *   A @href CATMathTransformation representing the position and orientation of the Element relative to the origin of the real world.
  */
  virtual CATMathTransformation GetPhysicalGlobalMatrix() const = 0;

  /**
  * Get the Virtual Mapping of the current Element.
  * This is a local matrix used to adjust the virtual pose of the Element.
  * It is typically used as an offset between a measured physical pose retrieved by #GetPhysicalLocalMatrix and the desired pose of the Element in the virtual world.
  *
  * @return
  *   A @href CATMathTransformation representing the virtual mapping.
  */
  virtual CATMathTransformation GetVirtualMapping() const = 0;

  /**
   * Sets the Virtual Mapping if the current Element.
   *
   * @param iVirtualMapping [in]
   *   The @href CATMathTransformation representing an offset between a measured physical pose retrieved by #GetPhysicalLocalMatrix and the desired pose of the Element in the virtual world.
   */
  virtual void SetVirtualMapping(const CATMathTransformation& iVirtualMapping) = 0;

};

CATDeclareHandler(IVISUIPositionedElement, IVISUIElement);


#endif

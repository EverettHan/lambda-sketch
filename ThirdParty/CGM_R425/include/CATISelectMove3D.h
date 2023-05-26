#ifndef CATISelectMove3D_h
#define CATISelectMove3D_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATMathTransformation;

extern ExportedByCATAfrSelection IID IID_CATISelectMove3D;

/**
 * Interface to be manipulated by Compass in select command.
 */
class ExportedByCATAfrSelection CATISelectMove3D : public CATBaseUnknown
{
  /** @nodoc */
  CATDeclareInterface;

public:

  /**
   * @nodoc
   * Initialize manipulators on object representations, or anything needed
   * to be able to move object. This method is called just after object
   * has been selected.
   */
  virtual HRESULT Init(CATBaseUnknown ** ioMoveAgent) = 0;

  /**
   * @nodoc
   * This method removes manipulators on object representation or anything
   * needed after object has been moved. This method is called just after object
   * has been unselected.
   */
  virtual HRESULT End() = 0;

  /**
   * @nodoc
   * This method is called when the objects start being moved. Transformation matrix
   * can be modified to take into account displacement constraints.
   */
  virtual HRESULT BeginMove(CATMathTransformation * ioTransformation) = 0;

  /**
   * @nodoc
   * Move the object between its initial position and current position.
   * Initial position is the position when BeginMove method was called.
   * Transformation matrix can be modified to take into account displacement
   * constraints.
   */
  virtual HRESULT Move(CATMathTransformation * ioTransformation) = 0;

  /**
   * @nodoc
   * Finish the object movement. Transformation matrix is the same as the one
   * in the last Move call. Since this is the last interaction of the move, heavy
   * computation can be done at this stage.
   */
  virtual HRESULT EndMove(CATMathTransformation * ioTransformation) = 0;
};

/** @nodoc */
CATDeclareHandler(CATISelectMove3D, CATBaseUnknown);

#endif

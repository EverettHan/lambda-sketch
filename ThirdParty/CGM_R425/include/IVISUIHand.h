#ifndef IVISUIHand_H
#define IVISUIHand_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIPositionedElement.h"

extern ExportedByIVInterfaces IID IID_IVISUIHand;

/**
* Interface representing the user's hand.
* <strong>Role</strong>: This interface is a specialization of PositionedElement representing a user's physical hand.
* Through inheritance, its position and orientation in the world can be retrieved.
* This element can be attached to a User Element (in which case, it will benefit from this Element's semantic), or to any other kind of Element (with no semantic in that case).
*
* @see IVISUIPositionedElement, IVISUIUser
*/
class ExportedByIVInterfaces IVISUIHand: public IVISUIPositionedElement
{
  CATDeclareInterface;

public:

};

CATDeclareHandler(IVISUIHand, IVISUIPositionedElement);

#endif

/**
 * @level Private
 * @usage U3
 */
#ifndef CATIApplicativeUndo_H
#define CATIApplicativeUndo_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATIAbstractApplicativeUndo.h"

#include "CATObjectModelerItf.h"
extern ExportedByCATObjectModelerItf IID IID_CATIApplicativeUndo;
 

/**   
 * Interface dedicated to implementing UndoRedo Applicative Treatment on a specialization of Feature Container.
 *
 * <b>Role</b>: provide an application a way to overload Undo/Redo Global Treatment for a Feature container.
 *  Set of template methods dedicated to defer some parts of a @href CATIUndoTransaction global implementation
 *  to an applicative object inheriting this adhesion.
 *  @see CATIUndoTransaction for global mechanism
 *
 */
class ExportedByCATObjectModelerItf CATIApplicativeUndo: public CATIAbstractApplicativeUndo
{
	CATDeclareInterface;

public:

};

CATDeclareHandler(CATIApplicativeUndo, CATBaseUnknown) ;

#endif

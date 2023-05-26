#ifndef VizUtilities_H
#define VizUtilities_H

/* COPYRIGHT DASSAULT SYSTEMES 2002 */

#include "CATVisFoundation.h"
#include "CATVizBaseManipulatorMediator.h"
#include "CATVizManipulatorMediatorAbstractFactory.h"

ExportedByCATVisFoundation void fSetManipulatorMediatorFactory(CATVizManipulatorMediatorAbstractFactory * iFactory);
ExportedByCATVisFoundation const CATVizManipulatorMediatorAbstractFactory *fGetManipulatorMediatorFactory();

#endif

#ifndef CATVizManipulatorMediatorAbstractFactory_H
#define CATVizManipulatorMediatorAbstractFactory_H

// COPYRIGHT DASSAULT SYSTEMES 2002

/* This class is an abstract class which defines a Factory Pattern for 
 * object creation.
 * This abstract class provides an interface for creating a family of objects without
 * specifying their concrete classes.
 * This class holds in a method whose aim is to instantiate a concrete object
 * of type @href CATVizManipulatorMediator.
 */

#include "CATVisFoundation.h"
#include "CATVizBaseManipulatorMediator.h"

class ExportedByCATVisFoundation CATVizManipulatorMediatorAbstractFactory 
{
public:
  virtual CATVizBaseManipulatorMediator * Instantiate (char * iKindOfObject) const =0;
};



#endif

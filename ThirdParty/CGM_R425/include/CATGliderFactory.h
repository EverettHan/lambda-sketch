#ifndef CATGliderFactory_h
#define CATGliderFactory_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

// This class is for instanciating a compass
//
// usage : CATGliderFactory::Create();
//
// note : 
//
// - It must not be used by people using a CATFrmGraphAnd3DWindow
//   or a class derivated since compass is automatically instanciated
//   in the CATFrmGraphAnd3DWindow constructor
//
// - In other cases, it must be used only once at document
//   creation (there can be only one compass).

class CATFrmEditor;

class ExportedByCATAfrSelection CATGliderFactory : public CATBaseUnknown
{
  CATDeclareClass;
public:
  static void Create(CATFrmEditor * Editor);
};

#endif

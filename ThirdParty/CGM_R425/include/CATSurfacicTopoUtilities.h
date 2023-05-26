#ifndef CATSurfacicTopoUtilities_H
#define CATSurfacicTopoUtilities_H

#include "CATSurfacicTopoOperators.h"
#include "CATBoolean.h"

class CATBody;
class CATFace;
class CATTopData;

class  ExportedByCATSurfacicTopoOperators CATSurfacicTopoUtilities
{
	public :
	/** @nodoc */
	static CATBoolean GetFaceOrientOK (CATBody *iBody, CATFace *iFace);

  static int InvertShellBody(CATBody*  iBodyToInvert,
                             CATBody*& oInvertedBody,
                             CATTopData* iTopData); 
};

#endif


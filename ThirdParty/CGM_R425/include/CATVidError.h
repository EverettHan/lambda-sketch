// COPYRIGHT DASSAULT SYSTEMES  2014
//=============================================================================
//
// CATVidError
//
//=============================================================================


#ifndef CATVidError_h
#define CATVidError_h

#include <VisuDialog.h>
#include <CATError.h>

class ExportedByVisuDialog CATVidError : public CATError
	{
  public :    

		CATDeclareError(CATVidError, CATError)    
	};
#endif

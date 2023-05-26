#ifndef CATIFrmEditorOtherSelection_H
#define CATIFrmEditorOtherSelection_H

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATOtherSelections;

extern ExportedByCATAfrSelection IID IID_CATIFrmEditorOtherSelection;

//===================================================================================
//              CATIFrmEditorOtherSelection :  D E C L A R A T I O N S
//===================================================================================

class ExportedByCATAfrSelection CATIFrmEditorOtherSelection : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
  
public:

   virtual void	SetOtherSelectionsPanel (CATOtherSelections *d)	= 0;
   virtual CATOtherSelections *GetOtherSelectionsPanel ()			= 0;
   virtual void KillOtherSelectionsPanel() = 0;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIFrmEditorOtherSelection, CATBaseUnknown ) ;

#endif

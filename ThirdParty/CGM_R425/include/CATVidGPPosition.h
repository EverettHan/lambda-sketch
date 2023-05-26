// COPYRIGHT Dassault Systemes 2005
//===================================================================
#ifndef CATVidGPPosition_H
#define CATVidGPPosition_H

#include "VisuDialog.h"
#include "CATVidGP.h"
#include "CATUnicodeString.h"

class CAT3DRep;

/**
 * Deprecated class.
 * @deprecated no bassociated behavior.
 */
class ExportedByVisuDialog CATVidGPPosition: public CATVidGP
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATVidGPPosition (CATCommand *i_pParent, const CATString & i_pIdentifier);

  void AddChild(CAT3DRep* i_pRep);

protected:
  virtual ~CATVidGPPosition ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidGPPosition (CATVidGPPosition &);
  CATVidGPPosition& operator=(CATVidGPPosition&);
};

//-----------------------------------------------------------------------

#endif

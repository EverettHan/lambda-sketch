//===================================================================
// COPYRIGHT Dassault Systemes 2018-07-19
//===================================================================
// CATVidCtlButtonChangeEventArgs.cpp
// Header definition of class CATVidCtlGenericEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018-07-19 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATVidCtlGenericEventArgs_H
#define CATVidCtlGenericEventArgs_H

// VisuImmersiveDialog framework
#include "VisuDialog.h"
#include "CATSYPEventArgs.h"

//-----------------------------------------------------------------------

class ExportedByVisuDialog CATVidCtlGenericEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:

  CATVidCtlGenericEventArgs(CATSYPEvent * i_pEvent, CATBaseUnknown_var& i_userdata);

  const CATBaseUnknown_var& GetUserData() const;

protected:

  virtual ~CATVidCtlGenericEventArgs();


private:
  CATVidCtlGenericEventArgs(CATVidCtlGenericEventArgs &);
  CATVidCtlGenericEventArgs& operator=(CATVidCtlGenericEventArgs&);

  CATBaseUnknown_var _userdata;
};

//-----------------------------------------------------------------------

#endif

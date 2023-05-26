//===================================================================
// COPYRIGHT Dassault Systèmes 2012/07/06
//===================================================================
// CATDlgContainerPresenter.cpp
// Header definition of class CATDlgContainerPresenter
//===================================================================
//
// Usage notes: Class extention of CATDlgContainer that inherits the
// behavior of CATDlgPresenter
//===================================================================
//  Author : K8N
//===================================================================

#ifndef CATDlgContainerPresenter_H
#define CATDlgContainerPresenter_H

#include "DialogDeclarativeEngine.h"
#include "CATDlgPresenter.h"

//-----------------------------------------------------------------------

class ExportedByDialogDeclarativeEngine CATDlgContainerPresenter: public CATDlgPresenter
{

  CATDeclareClass;
  friend class CATDlgCollection;

public:

  CATDlgContainerPresenter ();
  virtual ~CATDlgContainerPresenter ();

  virtual void SetChild( CATBaseUnknown_var i_spChild );

private:

  CATDlgContainerPresenter (CATDlgContainerPresenter &);
  CATDlgContainerPresenter& operator=(CATDlgContainerPresenter&);

};

//-----------------------------------------------------------------------

#endif

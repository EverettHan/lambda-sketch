//===================================================================
// COPYRIGHT Dassault Systèmes 2012/07/06
//===================================================================
// CATDlgPresenter.h
// Header definition of class CATDlgCollection
//===================================================================
//
// Usage notes: Base class for all objects in Dialog that can layout
// a single elements in a declarative file
//===================================================================
//  Author : K8N
//===================================================================

#ifndef CATDlgPresenter_H
#define CATDlgPresenter_H

#include <DialogDeclarativeEngine.h>
#include <CATBaseUnknown.h>
#include <CATSYPArray.h>

class CATDialog;
class CATISYPCollection_var;


class ExportedByDialogDeclarativeEngine CATDlgPresenter : public CATBaseUnknown
{

  CATDeclareClass;
  friend class CATDlgCollection;

public:

  virtual ~CATDlgPresenter ();

  virtual void SetChild( CATBaseUnknown_var i_spChild );

  virtual CATBaseUnknown_var GetChild();


protected:

  /** Constructor. */
  CATDlgPresenter ();

  /** 
    * The Dialog element
    * ripped out from the presenter
    * during SetChild
    */
  CATDialog* _pDlgChild;

  /** 
    * The non-Dialog-casted element
    * ripped out from the presenter
    * during SetChild
  */
  CATBaseUnknown_var _pChild;

};


#endif

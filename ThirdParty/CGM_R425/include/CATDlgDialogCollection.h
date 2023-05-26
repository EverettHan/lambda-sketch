//===================================================================
// COPYRIGHT Dassault Systèmes 2012/07/06
//===================================================================
// CATDlgDialogCollection.h
// Header definition of class CATDlgDialogCollection
//===================================================================
//
// Usage notes: Class extention of CATDlgDialog that inherits the
// behavior of CATDlgCollection
//===================================================================
//  Author : K8N
//===================================================================

#ifndef CATDlgDialogCollection_H
#define CATDlgDialogCollection_H

#include "DialogDeclarativeEngine.h"
#include "CATDlgCollection.h"
class CATDlgDialog;

//-------------------------------------------------- Introspection Infrastructure
#include "CATSYPArray.h"
class CATISYPCollection_var;


//-----------------------------------------------------------------------

class ExportedByDialogDeclarativeEngine CATDlgDialogCollection : public CATDlgCollection
{

  CATDeclareClass;

public:

  CATDlgDialogCollection ();
  virtual ~CATDlgDialogCollection ();

  //------------------------------------------------- CATISYPCollection methods

  virtual CATBaseUnknown_var GetAt( int i_index );
  virtual int GetCount();
  virtual void Append( const CATBaseUnknown_var &i_spObject );
  virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  virtual void Remove( const CATBaseUnknown_var &i_spObject );
  virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  virtual void Clear();
  virtual int Contains( const CATBaseUnknown_var &i_spObject );
  virtual void Append( const CATLISTV(CATBaseUnknown_var) &i_list );

private:

  CATDlgDialog* _pCollectionDialog;

  CATDlgDialogCollection (CATDlgDialogCollection &);
  CATDlgDialogCollection& operator=(CATDlgDialogCollection&);

  HRESULT ReparentCollection();

};

//-----------------------------------------------------------------------

#endif

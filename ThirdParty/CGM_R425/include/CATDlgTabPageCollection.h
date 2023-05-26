//===================================================================
// COPYRIGHT Dassault Systèmes 2012/07/06
//===================================================================
// CATDlgContainerPresenter.h
// Header definition of class CATDlgTabPageCollection
//===================================================================
//
// Usage notes: Class extention of CATDlgTabPage that inherits the
// behavior of CATDlgCollection
//===================================================================
//  Author : K8N
//===================================================================

#ifndef CATDlgTabPageCollection_H
#define CATDlgTabPageCollection_H

#include "DialogDeclarativeEngine.h"
#include "CATDlgCollection.h"
class CATDlgTabPage;

//-------------------------------------------------- Introspection Infrastructure
#include "CATSYPArray.h"
class CATISYPCollection_var;

//-----------------------------------------------------------------------

class ExportedByDialogDeclarativeEngine CATDlgTabPageCollection : public CATDlgCollection
{

  CATDeclareClass;

public:

  CATDlgTabPageCollection ();
  virtual ~CATDlgTabPageCollection ();

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

  CATDlgTabPage* _pCollectionTabPage;

  CATDlgTabPageCollection (CATDlgTabPageCollection &);
  CATDlgTabPageCollection& operator=(CATDlgTabPageCollection&);

  HRESULT ReparentCollection();

};

//-----------------------------------------------------------------------

#endif

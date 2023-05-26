#ifndef CATDlgSplitterCollection_H
#define CATDlgSplitterCollection_H

#include <DialogDeclarativeEngine.h>
#include <CATDlgCollection.h>

class CATDlgSplitter;
class CATISYPCollection_var;

class ExportedByDialogDeclarativeEngine CATDlgSplitterCollection : public CATDlgCollection
{

  CATDeclareClass;

public:

  CATDlgSplitterCollection ();
  virtual ~CATDlgSplitterCollection ();


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

  CATDlgSplitter* _pCollectionSplitter;

  CATDlgSplitterCollection (CATDlgSplitterCollection &);
  CATDlgSplitterCollection& operator=(CATDlgSplitterCollection&);

  HRESULT ReparentCollection();

};

#endif

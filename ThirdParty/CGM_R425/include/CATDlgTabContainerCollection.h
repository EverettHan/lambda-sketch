//===================================================================
// COPYRIGHT Dassault Systèmes 2012/07/06
//===================================================================
// CATDlgContainerPresenter.h
// Header definition of class CATDlgTabContainerCollection
//===================================================================
//
// Usage notes: Class extention of CATDlgTabContainer that inherits the
// behavior of CATDlgCollection
//===================================================================
//  Author : K8N
//===================================================================

#ifndef CATDlgTabContainerCollection_H
#define CATDlgTabContainerCollection_H

#include "DialogDeclarativeEngine.h"
#include "CATDlgCollection.h"
class CATDlgTabContainer;

//-------------------------------------------------- Introspection Infrastructure
#include "CATSYPArray.h"
class CATISYPCollection_var;

//-----------------------------------------------------------------------

class ExportedByDialogDeclarativeEngine CATDlgTabContainerCollection : public CATDlgCollection
{

  CATDeclareClass;

  public:

    CATDlgTabContainerCollection ();
    virtual ~CATDlgTabContainerCollection ();

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

    CATDlgTabContainer* _pCollectionTabContainer;

    CATDlgTabContainerCollection (CATDlgTabContainerCollection &);
    CATDlgTabContainerCollection& operator=(CATDlgTabContainerCollection&);

    HRESULT ReparentCollection();

};

//-----------------------------------------------------------------------

#endif

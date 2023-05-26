//===================================================================
// COPYRIGHT Dassault Systèmes 2012/07/06
//===================================================================
// CATDlgContainerPresenter.h
// Header definition of class CATDlgFrameCollection
//===================================================================
//
// Usage notes: Class extention of CATDlgFrame that inherits the
// behavior of CATDlgCollection
//===================================================================
//  Author : K8N
//===================================================================

#ifndef CATDlgFrameCollection_H
#define CATDlgFrameCollection_H

#include "DialogDeclarativeEngine.h"
#include "CATDlgCollection.h"
class CATDlgFrame;

//-------------------------------------------------- Introspection Infrastructure
#include "CATSYPArray.h"
class CATISYPCollection_var;

//-----------------------------------------------------------------------

class ExportedByDialogDeclarativeEngine CATDlgFrameCollection : public CATDlgCollection
{

  CATDeclareClass;

  public:

    CATDlgFrameCollection ();
    virtual ~CATDlgFrameCollection ();

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

    CATDlgFrame* _pCollectionFrame;

    CATDlgFrameCollection (CATDlgFrameCollection &);
    CATDlgFrameCollection& operator=(CATDlgFrameCollection&);

    HRESULT ReparentCollection();

};

//-----------------------------------------------------------------------

#endif

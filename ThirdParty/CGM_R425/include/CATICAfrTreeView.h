#ifndef CATICAfrTreeView_H
#define CATICAfrTreeView_H

// COPYRIGHT Dassault Systemes 2013/09/23

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATPathElement;
class CATITreeViewModel_var;
class CATString;

extern ExportedByCATAfrItf  IID IID_CATICAfrTreeView ;

//-----------------------------------------------------------------------------
/**
* Interface representing The Tree Component.
*/
class ExportedByCATAfrItf CATICAfrTreeView: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Sets the view parent. Can be NULL. In this case, 
    * the view will created a panel box that contains the component.
    * Sets the view parent, if parent is a CATVizViwer, the view will created aa the top left corner of the vizviewer.
    * Use the method CATCAfrComponentServices::AddComponentViewDeletedCB with the name of your component to be called when the view is deleted in 
    * order to manage your life cycle.
    */
    virtual void SetViewParent( const CATBaseUnknown_var& i_spViewParent ) = 0;

    /**
    * Set visibility
    **/
    virtual void SetVisibility( int iVisibility ) = 0;

    /**
    * Set the Model
    **/
    virtual void SetModel( CATITreeViewModel_var ispModel ) = 0;

    /**
    * Get the Model
    **/
   virtual CATITreeViewModel_var GetModel() const = 0;

    /**
    * Get root node
    **/
    virtual CATPathElement *GetRoot(void) = 0;

    /**
    * Set root node
    **/
    virtual void SetRoot( CATPathElement *iRoot ) = 0;

    /**
    * Expand a node
    **/
    virtual void Expand( CATBaseUnknown *iNode ) = 0;

    /**
    * Collapse a node
    **/
    virtual void Collapse( CATBaseUnknown *iNode ) = 0;

    /**
    * Collapse all expanded model items.
    */
    virtual void CollapseAll() = 0;

    /**
    * Collapse a branch starting from a node
    **/
    virtual void CollapseBranch( CATBaseUnknown *iNode ) = 0;

    /**
    * Center Graph
    **/
    virtual HRESULT MakeVisibleGraph( CATBaseUnknown* ipNode ) = 0;

    /**
     * Empty selection, if iNotify=1 a notification is sent.
     **/
    virtual void ClearSelection( const int& iNotify = 1 ) = 0;

    /**
     * Add a node to the selection, if iNotify=1 a notification is sent.
     **/
    virtual void AddToSelection( CATBaseUnknown *ipNode, const int& iNotify = 1 ) = 0;

    /**
     * Remove a node from the selection, if iNotify=1 a notification is sent.
     **/
    virtual void RemoveFromSelection( CATBaseUnknown *ipNode, const int& iNotify = 1 ) = 0;

};
#endif

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011
//===================================================================
// CATAfrModelBase.cpp
// Header definition of class CATAfrModelBase
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2011/08/29 Creation: ERS
// ApplicationFrame components Infrastructure.
// CATAfrModelBase est une classe abstraite qui contient :
// -	Les propriétés « Next », « Previous », « FirstChild » et « Parent » qui permettent de naviguer dans l’arbre.
//    Les méthodes Set et Get ne sont pas virtuelles. Ces propriétés ne doivent pas être accessibles par le XML, elles ne sont donc pas exposées dans le fichier sypintro associé à la classe.
// -	La propriété « Name » qui permet d’identifier un objet du modèle.
//    Les méthodes Set et Get ne sont pas virtuelles. Cette propriété doit être accessible par le XML, elle est donc exposée dans le fichier sypintro associé à la classe.
// -	La propriété « Visibility » qui permet d’afficher/cacher la représentation de l’objet.
//    Le premier affichage crée la représentation.
//    La modification de cette propriété sur un objet de l’arbre modèle applique la même modification à tous les objets du sous-arbre modèle de cet objet.
//    Cette propriété doit être accessible par le XML, elle est donc exposée dans le fichier sypintro associé à la classe.
// -	La méthode virtuelle pure SortProperties qui permet d’ordonner les propriétés représentables.
//    Chaque classe dérivée choisit d’appeler ou pas cette méthode dans sa méthode non-virtuelle qui renvoie la liste des propriétés.
//===================================================================

#ifndef CATAfrModelBase_H
#define CATAfrModelBase_H

#include "CATAfrComponentsModel.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATICAfrComponentElement.h"

class CATAfrModelEventListener;
class CATSYPEventFactory;
class CATSYPEventHandlersSupport;
class CATSYPEventArgs;
class CATSYPEventHandler;
class CATSYPEvent;
class CATSYPDataBlockFactory;
class CATSYPDataBlock;
class CATCommand;
class CATSysWeakRef;
class CATAfrModelView;
class CATSYPTemplateData;
class CATICAfrProperty;
class CATISYPIntrospectable_var;
class CATAfrModelBaseData;
//-----------------------------------------------------------------------
class ExportedByCATAfrComponentsModel CATAfrModelBase: public CATBaseUnknown
{
  CATDeclareClass;

  public:

    CATAfrModelBase ();
    virtual ~CATAfrModelBase ();

    /**
     * Removes an object.
     * Removes links of the object to its parent, childs and brothers.
     * Does not delete the object.
     */
    virtual void Remove ();

    //---------------- Navigation in the model tree ----------------

    /**
     * Sets an object as the next of this.
     * Also sets this as the previous of ipNext.
     * Also sets the parent of ipNext to the parent of this.
     * If this already had a Next, this Next becomes the Next of ipNext.
     * The default Next of an object is NULL. NULL marks the end of list.
     * Setting the Next of an object to NULL will not remove any object. Use Remove method to remove an object from the structure or Relese to delete it.
     */
    virtual void SetNextElement (CATAfrModelBase * ipNext);
    /**
     * Gets the next object in the list.
     * Returns NULL if this is the last object in the list.
     */
    virtual CATAfrModelBase * GetNextElement() const;

    /**
     * Sets an object as the previous of this.
     * Also sets this as the next of ipPrevious.
     * Also sets the parent of ipPrevious to the parent of this.
     * If this already had a Previous, this Previous becomes the Previous of ipPrevious.
     * The default Previous of an object is NULL. NULL marks the beginning of list.
     * Setting the Previous of an object to NULL will not remove any object. Use Remove method to remove an object from the structure or Relese to delete it.
     */
    virtual void SetPreviousElement (CATAfrModelBase * ipPrevious);
    /**
     * Gets the previous object in the list.
     * Returns NULL if this is the first object in the list.
     */
    virtual CATAfrModelBase * GetPreviousElement() const;

    /**
     * Sets an object as the parent of this.
     * Also sets this and its brothers as the childs of ipParent.
     * If this already had a Parent, this Parent becomes the Parent of ipParent and has no other child.
     * The default Parent of an object is NULL. NULL marks the end of list.
     * Setting the Parent of an object to NULL will not remove any object. Use Remove method to remove an object from the structure or Relese to delete it.
     */
    virtual void SetParentElement (CATAfrModelBase * ipParent);
    /**
     * Gets the parent object of this.
     * Returns NULL if this has no parent (i.e. this is the root of the tree).
     */
    virtual CATAfrModelBase * GetParentElement() const;

    /**
     * Sets an object as the first child of this.
     * Also sets this as the parent of ipChild.
     * If this already had a Child, this Child becomes the Next of ipChild.
     * The default Child of an object is NULL. NULL marks the end of list.
     * Setting the Child of an object to NULL will not remove any object. Use Remove method to remove an object from the structure or Relese to delete it.
     */
    virtual void SetFirstChildElement (CATAfrModelBase * ipChild);
    /**
     * Gets the first child object of this.
     * Returns NULL if this has no child (i.e. this is a leaf in the tree).
     */
    virtual CATAfrModelBase * GetFirstChildElement() const;
    /**
     * Gets a child object of this having a name.
     * Returns NULL if this has no child (i.e. this is a leaf in the tree).
     */
    virtual CATAfrModelBase * GetChildElement (const CATString & iName) const;
    /**
     * Adds an object at the end of the child list of this.
     * Also sets this as the parent of ipChild.
     * Also sets the Previous of ipChild to the previous last child of this.
     * Also sets the Next of ipChild to NULL.
     */
    virtual void AddChildElement (CATAfrModelBase * ipChild);




    /**
    * Returns the representation type of the model object. 
    */
    virtual const CATString  &  GetRepresentationType();

    /**
    * Set the representation type of the model object. 
    */
    virtual void SetRepresentationType(CATString &);


    //---------------- Properties useable thru XML ----------------

    /**
     * Name property.
     * Identification of a model object.
     */
    virtual void SetName (const CATString & iName);
    const CATString & GetName() const;

    /**
     * NlsFile
     */
    virtual void SetResourceFile( const CATString& iFileName );
    const CATString & GetResourceFile() const;

    /**
     * Visibility property.
     * Hide/Show representations of the model object.
     * The first display (show) creates the representations.
     * Modifying this property on a model object modifies recursively the property on all the sub tree of this model object.
     */
    virtual void SetVisibility (const CATBoolean& ipVisibility);
    const CATBoolean GetVisibility() const;
    /**
     * Tootip property.
     */
    void SetTooltip(const CATUnicodeString & i_tooltip);
    virtual const CATUnicodeString & GetTooltip() const;

    
    // CATISYPTemplate
    virtual void SetTemplateName(const CATUnicodeString& i_templateName);
    virtual const CATUnicodeString& GetTemplateName() const;
    virtual void SetVariationName(const CATUnicodeString& i_variationName);
    virtual const CATUnicodeString& GetVariationName() const;
    virtual void SetTemplatedView(CATBaseUnknown_var& i_spView, CATSYPTemplateData* i_pTemplateData);
    virtual CATSYPTemplateData* GetTemplateData() const{return NULL;};

    // CATICAfrComponentElement
    virtual HRESULT GetProperty( const CATString& iPropId, CATICAfrProperty** opiAfrProperty );
    virtual HRESULT AddSubObject( const CATBaseUnknown_var ispSubObject );
    virtual HRESULT GetSubObject( CATBaseUnknown_var& ospSubObject );
    virtual HRESULT AddProperty( const CATUnicodeString & i_name, 
                                 const CATUnicodeString & i_type, 
                                 const CATICAfrComponentElement::Access i_access, 
                                 const CATUnicodeString & i_tweakType, 
                                 const CATBaseUnknown_var & i_value, 
                                 int i_valueTypeFlag = 1 );
    virtual HRESULT GetPreviousElement( CATICAfrComponentElement** opiPrevious );
    virtual HRESULT GetNextElement( CATICAfrComponentElement** opiNext );
    virtual HRESULT GetParentElement( CATICAfrComponentElement** opiFather );

    // Nls Management
    void LoadResources( CATBaseUnknown_var ispSubObject );

    static CATSYPEvent * ModelModified();

    //SYP Handler Event
  // Add a handler for a given event.
   //
   // The handlers will be called in the order of their registration.
   //
   // If this function is called during the dispatch of an event, the
   // registered event handler won't be called for this dispatch but
   // will only be called for next dispatches.
   //
   // It is possible to call mutliple times this function with the same
   // event and the same handler instance. In that case there will be
   // multiple registrations; no checks are made for duplication (the
   // caller will have to call @ref #RemoveHandler multiple times).
   //
   // @param i_pEvent the event that we are interested in. Note that @c
   // AddRef will be called on the event. Can't be @c NULL.
   //
   // @param i_pHandler the handler to call. Can't be @c NULL. 
   // @c AddRef will be called on this pointer. Note that the type of 
   // @c CATSYPEventArgs supported by this handler will be compared to
   // the type of arguments of the event. It must be a super-type of
   // the one of the event.
   //
   // @param i_handleConsumedEvents @c !=0 if the handler should be
   // called for consumed events.
   //
   // @return @c !=0 if succeeded, @c 0 if failed to add handler due to
   // invalid input or internal error (in that case a @ref FAILURE has
   // been raised).
   //
   // @see #AddHandlerFunction
   // @see @AddHandlerWRefMeth
   // @see #RemoveHandler 
   int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);

   // Remove an handler for an event.
   //
   // If this function is called during the dispatch of an event, the
   // unregistered event handler will be called for this dispatch but
   // will not be called for next dispatches.
   //
   // If the same handler has been added multiple times, this function
   // removes the first found registration (starting the look up from
   // the most ancient registration).
   //
   // @param i_pEvent the event. Can't be @c NULL.
   //
   // @param i_pHandler the handler. Can't be @c NULL.
   //
   // @return @c !=0 if succeeded, @c 0 if failed to remove handler due
   // to invalid input or internal error (in that case a @ref FAILURE has
   // been raised) or if the handler was never registered for the given
   // event (in that case NO @ref FAILURE is raised, it is valid to do
   // so; this is important for auto-remove handlers).
   //
   // @see #AddHandler
   int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);
   // Dispatch the event.
   //
   // The event will be dispatched in the tree hierarchy depending on
   // the porpagation mode of the event (@ref
   // CATSYPEvent#GetPropagation).
   //
   // The list of handlers that will be called will be frozen before
   // the first handler is called; as a consequence, changes in the
   // tree hierarchy or in the handlers for the event at each node
   // won't have any effect on the dispatch of this event (but will
   // have effect on next dispatches, even on dispatches that may be
   // triggered by handlers of this event).
   //
   // This call is synchronous; it is blocking until the dispatch is
   // ended.
   //
   // The origin on the event argument (@ref CATSYPEventArgs#GetOrigin)
   // must be either @c NULL or equal to this object. If @c NULL, it
   // will be positioned by this function to this object.
   //
   // The instance of arguments used on this function will be passed to
   // all handlers called during the dispatch.
   // 
   // @param i_pArgs the arguments of the event to dispatch (the
   // dispatched event is retreived though @ref
   // CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
   // either this object of @c NULL.
   //
   // @return @c !=0 if the dispatch succeeded, @c 0 if failed.
   int Dispatch(CATSYPEventArgs *i_pArgs);

     /** 
   * Get the event factory to use to build widgets' events.
   *
   * This function should be used through the @ref
   * CATImplementSYPEvent macro.
   *
   * @return the event factory. Never @c NULL.
   *
   * @see CATImplementSYPEvent
   */
  static CATSYPEventFactory *GetEventFactory();

  virtual HRESULT IfBuildChildView( );

  CATAfrModelBaseData * GetModelData() const {return _pBaseData;};

  protected:
    CATString         _name;
    CATString         _representationType;
    CATBoolean        _visibility;
    //extension AfrFoundation
    CATSysWeakRef * _viewWeakRef;
    CATBaseUnknown * GetComponentFromMemberWeakRef(CATSysWeakRef * WeakRef) const;
    CATAfrModelView * GetModelView()const;
    CATBaseUnknown * _pDataBlock;


    //---------------- Representation type abstraction ----------------


    /**
    * Creates a generic representation for an access. 
    * @nodoc
    * @author ld3
    */
    virtual CATCommand *  GenericRepCreation(CATCommand *);

    /**
    * Deletes generic representation of an access.. 
    * @nodoc
    * @author ld3
    */
    virtual void  GenericRepDeletion();
    /**
    *
    * <br><b>Role</b>: Method to override to allow to remove properies of the generated datablock.
    * This method is called after that all properties of component has been copied into the datablock. 
    * Remove properties you don't want by overriding this method and by using the method of DataBlock factory
    * to remove a property: <code>ipFactory->RemoveProperty("APropertyThatIDontWantTo");</code>.
    * It is possible to add new property on the datablock that not belong to the model but an other object that you know.</br>
    *
    * You can also add an event handler to connect an event by using the method <code> ipFactory->AddEventHandler(..)</code>.
    * @param ipFactory the factory which allow to remove property
    * 
    * 
    */
    virtual CATBaseUnknown * CreateViewDataBlock();


    /** Refresh the view if build */
    virtual void RefreshView( );

    CATSYPEvent * GetEventFromName(const CATUnicodeString & iName);

    void SetModelView(CATAfrModelView * pView);
    CATBoolean                    _forceCreateView;

    CATAfrModelBase *             _pNext;
    CATAfrModelBase *             _pPrevious;
    CATAfrModelBase *             _pFirstChild;
    CATAfrModelBase *             _pParent;
    CATAfrModelBaseData *         _pBaseData;
    CATBoolean                    _IsNowRemove;

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAfrModelBase (CATAfrModelBase &);
    CATAfrModelBase& operator=(CATAfrModelBase&);

    CATString                     _ResourceFile;
    CATUnicodeString              _TemplateName;
    CATUnicodeString              _VariationName;

    CATUnicodeString              _tooltip;
    CATSYPEventHandlersSupport *  _pSupport;
    CATBoolean                    _partiallyBuild;


      /**
   * The factory of events for widgets.
   *
   * It will be instantiated  the first time it is needed.
   *
   * @see #GetEventFactory
   */
  static CATSYPEventFactory *     _pEventFactory;
  friend class CATCAfrMenu;
  friend class CATAfrModelBaseEventPathBuilder;
  friend class CATAfrModelBaseData;
  friend class CATCAfrForm;
  friend class CATCAfrTree;

};
//-----------------------------------------------------------------------
#endif

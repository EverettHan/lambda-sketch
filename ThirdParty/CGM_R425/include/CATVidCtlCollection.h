#ifndef CATVidCtlCollection_h
#define CATVidCtlCollection_h

// COPYRIGHT Dassault Systemes 2014

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATVidLayConstraintsAndWidget.h>

// IntrospectionInfrastructure framework
#include <CATISYPCollection.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

// System framework
#include <CATBoolean.h>

class CATVidLayConstraints;
class CATSYPEvent;

/**
 * Base class for containers embedding a collection of widgets.
 */
class ExportedByVisuDialog CATVidCtlCollection : public CATVidCtl
{
  CATDeclareClass;

public:

  /**
   * Default constructor.
   */
  CATVidCtlCollection();

  /**
   * Creates a CATVidCtlCollection. 
   * @param i_pParent the parent command
   * @param i_identifier name of the widget
   */
  CATVidCtlCollection(CATCommand *i_pParent, const CATString & i_identifier);

  /**
   * Sets the constraints of the given widget in the collection.
   * If the widget doesn't belong to the collection, it is automatically added. 
   * If the widget is already in the collection, its constraints are updated.
   * @param i_pWidget the widget to associate the constraints to and to add if necessary. 
   * Must not be NULL.
   * @param i_constraints the constraints to associate to the widget in the collection.
   */
  void SetConstraints(CATVidWidget * i_pWidget, const CATVidLayConstraints& i_constraints);
  
  /**
   * Removes the given widget from the collection.
   */
  void RemoveWidget(CATVidWidget * i_pWidget);
  
  /**
   * Specifies the indexed constraints of the given child.
   */
  void SetIndexedConstraints(const CATBaseUnknown_var& i_spChild, const CATBaseUnknown_var & i_constraints);

  /**
   * Returns the indexed constraints of the given child.
   */
  const CATBaseUnknown_var GetIndexedConstraints(const CATBaseUnknown_var& i_spChild) const;

  /**
   * Inserts a widget in a collection at a given index.
   * @param i_object the widget to insert.
   * @param i_index the index at which to insert
   */
  void InsertAt(const CATBaseUnknown_var& i_object, int i_index);

  /**
   * Moves a widget from its i_from index to the i_to index.
   * Note that it could have no influence on the rendering/picking of some collection, depending of the layouting type.
   * It will be especially usefull in case of collection without specific constraints (LayLayer, LayFlow, LayStack...)
   * @param i_from the current widget index in the collection's list. Asserts if out of bounds. Must be <tt> >=0 </tt> and <tt> < GetCount() </tt>.
   * @param i_to the index to move the widget to, in the collection's list. Asserts if out of bounds. Must be <tt> >=0 </tt> and <tt> <= GetCount() </tt>.
   */
  void MoveTo(int i_from, int i_to);

  /**
   * Specifies whether the collection must dispatch the ConstraintsModified or not.
   * By default, the EventDispatchEnabledFlag property is set to FALSE.
   * @see ConstraintsModified
   */
  void SetEventDispatchEnabledFlag(CATBoolean i_eventDispatchEnabledFlag);
  
  /**
   * Returns TRUE if the collection must dispatch the ConstraintsModified, FALSE otherwise.
   */
  CATBoolean GetEventDispatchEnabledFlag() const;

  /**
   * Returns the @c ConstraintsModified event.
   * The @c ConstraintsModified event is emitted whenever the layout of a widget in the collection is modified.
   * @par EventProperties
   *   - Name: @c "ConstraintsModified"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidConstraintsModifiedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * ConstraintsModified();

  /**
   * Returns the @c WidgetRemoved event.
   * The @c WidgetRemoved event is emitted whenever a widget is removed from the collection.
   * @par EventProperties
   *   - Name: @c "WidgetRemoved"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidWidgetRemovedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * WidgetRemoved();

  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
  /** @copydoc CATISYPCollection#GetAt */
  virtual CATBaseUnknown_var GetAt(int i_index);
  /** @copydoc CATISYPCollection#GetCount */
  virtual int GetCount();
  /** @copydoc CATISYPCollection#Append */
  virtual void Append(const CATBaseUnknown_var &i_spObject);
  /** @copydoc CATISYPCollection#AppendList */
  virtual void AppendList(const CATSYPConstArray<CATBaseUnknown_var> &i_list);
  /** @copydoc CATISYPCollection#Remove */
  virtual void Remove(const CATBaseUnknown_var &i_spObject);
  /** @copydoc CATISYPCollection#RemoveList */
  virtual void RemoveList(const CATSYPConstArray<CATBaseUnknown_var> &i_list);
  /** @copydoc CATISYPCollection#Clear */
  virtual void Clear();
  /** @copydoc CATISYPCollection#Contains */
  virtual int Contains(const CATBaseUnknown_var &i_spObject);
  /** @copydoc CATISYPCollection#Append */
  virtual void Append(const CATLISTV(CATBaseUnknown_var) &i_list);
  /*@}*/

  /**
   * Returns the CATISYPCollection interface handler.
   */
  CATISYPCollection_var GetItems();

  /**
   * Returns the children list
   */
  INLINE const CATListOfCATVidLayConstraintsAndWidget& GetChildList() const {return _childList;}

protected:
  
  virtual ~CATVidCtlCollection();

  /**
   * Creates a constraint compatible with the inherited collection class.
   * This method is called when #Append is called directly on the component, 
   * and not within the SetConstraints method.
   */
  virtual CATVidLayConstraints* CreateConstraints() = 0;

  /**
   * Called by SetConstraints, it is overloaded by some 
   * inherited collection that need to addd an action at the end of a SetConstraints method.
   * @param i_pConstraintsAndWidget the added widget and its associated constraints
   * @param i_newWidget specifies whether the widget is new in the collection or not
   * @param i_pOldConstraints old constraints of the widget if this one was already in the collection
   */
  virtual void InternalSetConstraints(CATVidLayConstraintsAndWidget * i_pConstraintsAndWidget, CATBoolean i_newWidget, CATVidLayConstraints * i_pOldConstraints) {};

  /**
   * Called by RemoveWidget, it is overloaded by some 
   * inherited collection that need to addd an action at the end of a RemoveWidget method.
   * @param i_pConstraintsAndWidget the removed widget and its associated constraints
   * @param i_widgetDeleted specifies whether the widget has been deleted or not
   */
  virtual void InternalRemoveWidget(CATVidLayConstraintsAndWidget * i_pConstraintsAndWidget, CATBoolean i_widgetDeleted) {};

  /**
   * Removes the given widget from the collection.
   */
  void _RemoveWidget(CATVidWidget * i_pWidget, CATBoolean i_widgetDeleted);

protected:

  CATListOfCATVidLayConstraintsAndWidget _childList;

private:
  
  CATVidCtlCollection (CATVidCtlCollection &);
  CATVidCtlCollection& operator=(CATVidCtlCollection&);

  void WidgetDeletedCB(CATCallbackEvent, void *i_pInput, CATNotification *, CATSubscriberData i_pSubscriberData, CATCallback);

  CATBoolean _eventDispatchEnabledFlag;
};

#endif // CATVidCtlCollection_h


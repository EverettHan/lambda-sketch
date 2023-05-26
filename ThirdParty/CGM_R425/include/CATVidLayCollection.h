// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidLayCollection.h
// Header definition of CATVidLayCollection
//
//===================================================================
//
//  Oct 2005  Creation: jov
//===================================================================
#ifndef CATVidLayCollection_H
#define CATVidLayCollection_H

#include <VisuDialog.h>
#include <CATVidContainer.h>
#include <list.h>
#include <CATVidColor.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <UIVCoreToolsInline.h>

class CATVidLayConstraints;
class CATVidGPSquare;
class CATISYPCollection_var;
class CATVidLayConstraintsAndWidget;
class CATVidLayIterator;
class CATSYPEvent;
class CATMathPointf;
class l_CATVidLay;

/**
 * Base class to manage a collection of widget.
 * <b>Role</b>:<br/> 
 * This is a base class inherited by concrete layout managers, as GridLayout, 
 * FlowLayout, StackLayout, etc...
 * A LayCollection determines the size and the position of the children 
 * it contains. It will take into accounts some propoerties of its children, 
 * as their minimum dimension for example.
 * CATVidLayCollection implements the interface CATISYPCollection, which allow
 * it to be used directly by introspection mechanisms and XML style definition.
 * However, the usage of this component by code is possible, as it is quite 
 * simple and powerfull to use it programmatically.
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLayCollection: public CATVidContainer
{
  CATDeclareClass;

public:

  /**
   * Construct a CATVidLayCollection
   * @see CATVidWidget#Constructor
   */
  CATVidLayCollection(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Sets the constraints of a widget on the collection.
   * If the widget doesn't belong to the collection, it is automatically added, 
   * and set the collection as its father widget. 
   * Note that it is fully different from the command father, set by CATCommand#SetFather.
   * In case of destruction of the collection, all its children will be 
   * automatically destroyed. Be aware to destroy ther widgets you created but 
   * that don't belong to the widget tree.
   * If the widget is in the collection, the constraints is simply updated
   * This method will involve an update of the layouting. It can be performance consuming.
   * @param i_pWidget the widget to associate the constraints to and to add if necessary. 
   * Must not be NULL.
   * Set itself as widget parent of i_pWidget.
   * @param i_constraints the constraints to associate to the widget in the collection.
   */
  virtual void SetConstraints(CATVidWidget *i_pWidget, const CATVidLayConstraints& i_constraints);

  /**
   * Removes a widget of the collection, without destroying it. 
   * Its indexed constraitns are destroyed.
   * Reset the widget's parent.
   * Call internally i_pWidget->SetFatherWidget(NULL).
   * @param i_pWidget the widget to remove from the collection. 
   * Must not be NULL.
   */
  void RemoveWidget(CATVidWidget* i_pWidget);

  /**
   * @copydoc CATVidWidget#TunnelInformation
   */
  virtual void TunnelInformation(const CATVidInformation& i_information);

  /**
   * Sets a flag allowing layout to modify the position strictly computed 
   * from the constraints for visilibity purpose.
   * For example it allow to be sure that a Balloon stay always inside the screen.
   * A notification is sent when a position is overwritten by a layout.
   * @param i_constraintUpdateAllowedFlag a on/off flag. Value can be 0 or 1.
   */
  void SetConstraintUpdateAllowedFlag(CATBoolean i_constraintUpdateAllowedFlag);

  /**
   * @return a flag indicating if the position computed by the layout can be 
   * modified for visibility purpose.
   */
  CATBoolean GetConstraintUpdateAllowedFlag( ) const;
	/**
	* Returns a flag that determin if we use the preferred dimension on resize interaction in order to compact(resize reduce)
	* And restore them (size inscrease).
	* @see CATVidLayConstraints#GetPreferredWidth
	* @see CATVidLayConstraints#GetPreferredHeight
	*/
	CATBoolean GetUsePreferredDimensionFlag() const;

	/**
	* Set user preferred dimension flag.
	* @see GetUsePreferredDimensionFlag
	*/
	void SetUsePreferredDimensionFlag(CATBoolean i_usePreferredDimensionFlag);

  /**
   * @return a notification sent whenever the position computed by the layout 
   * on a widget is modified for visibility purpose.
   * @see #SetConstraintUpdateAllowedFlag
   */
  CATNotification *GetLayoutConstraintsModifiedNotification() const;

  void AppendPointerList(const CATSYPArray<CATVidWidget *> &i_list);
  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
	/** @copydoc CATISYPCollection#GetAt */
	virtual CATBaseUnknown_var GetAt( int i_index );
	/** @copydoc CATISYPCollection#GetCount */
	virtual int GetCount();
	/** @copydoc CATISYPCollection#Append */
	virtual void Append( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#AppendList */
	virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Remove */
	virtual void Remove( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#RemoveList */
	virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Clear */
	virtual void Clear();
  /** @copydoc CATISYPCollection#Contains */
  virtual int Contains( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#Append */
	virtual void Append( const CATLISTV(CATBaseUnknown_var) &i_list );
  /*@}*/

  /**
   * Specifies the indexed constraints of the given child.
   */
  void SetIndexedConstraints(const CATBaseUnknown_var& i_spChild, const CATBaseUnknown_var & i_constraints);

  /**
   * Returns the indexed constraints of the given child.
   */
  const CATBaseUnknown_var GetIndexedConstraints(const CATBaseUnknown_var& i_spChild) const;

  /**
   * @return a handler on CATISYPCollection. Used by XML StyleProcessor.
   */
  CATISYPCollection_var GetItems();

  /**
   * Creates ther most appropriate iterator for the collection.
   * @return the iterator on the collection.
   * @see CATVidLayIterator
   */
  virtual CATVidLayIterator* CreateIterator() const;

  /**
   * @deprecated use an iterator instead.
   * @see CATVidLayCollection#CreateIterator
   */
  CATVidWidget* GetWidgetAt(unsigned int i_index) const;

  /**
   * Returns the index in a collection from a given widget.
   * This function is time consuming.
   * @param i_pWidget the widget to get the index.
   * @return the index.
   * @deprecated
   */
  int GetIndex(CATVidWidget* i_pWidget) const;

  /** @copydoc CATVidContainer#UpdateContainer
  public as some client :( call it directly... */
  virtual void UpdateContainer();

  /**
   * Returns the index in a collection from at a given position.
   * @param i_Point the position relative to this container.
   * @return the index.
   */
  virtual int GetIndexAtPos(const CATMathPointf& i_Point) const;

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
   * Returns a flag indicating if a widget will be layoutable by a collection.
   * @param i_pWidget the widget to determine if it is layoutable. 
   * A widget is layoutable if its property VisibleFlag is true or if its
   * property LayoutWhenUnvisibleFlag is true, and its constraints are not NULL
   * @return a boolean. Can be 0 or 1.
   */
  static CATBoolean IsWidgetLayoutable(const CATVidWidget* i_pWidget);

  /**
   * Returns TRUE if the collection must dispatch the WidgetRemoved, FALSE otherwise.
   * By default, the EventDispatchEnabledFlag property is set to FALSE.
   */
  CATBoolean GetEventDispatchEnabledFlag() const;

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
	* Returns the @c WidgetCompacted event.
	*
	* The @c WidgetCompacted event is emitted when a widget dimension has been reduced during
	* the layout for visibility reason because there is not enough space.
	*
	* @par EventProperties
	*   - Name: @c "WidgetCompacted"
	*   - Type of propagation: @c NoPropagation
	*   - Type of argument: @ref CATVidConstraintsModifiedEventArgs
	*
	* @return the event instance. @c AddRef has NOT been called on
	* the returned pointer.
	*/
	static CATSYPEvent * WidgetCompacted();

	/**
	* Returns the @c WidgetPreferredDimensionChanged event.
	*
	* The @c WidgetPreferredDimensionChanged event is emitted when a widget has its preferred dimension that 
  * has been changed during the layout.
	*
	* @par EventProperties
	*   - Name: @c "WidgetPreferredDimensionChanged"
	*   - Type of propagation: @c NoPropagation
	*   - Type of argument: @ref CATVidConstraintsModifiedEventArgs
	*
	* @return the event instance. @c AddRef has NOT been called on
	* the returned pointer.
	*/
	static CATSYPEvent * WidgetPreferredDimensionChanged();

protected:

  /**
   * Construct a CATVidLayCollection
   * @see CATVidWidget#Constructor
   */
  CATVidLayCollection(CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);

  /**
   * Determine the position and size of all the children of the collection.
   * This class is pure virtual, and has to be implemented by inherited class.
   */
  virtual void Layout() {};

  /**
   * Creates a constraint compatible with the inherited layout class.
   * This method is called when #Append is called directly on the component, 
   * and not within the SetConstraints method.
   */
  virtual CATVidLayConstraints* CreateConstraints() = 0;

  /** @copydoc CATVidWidget#ChildWidgetDeleted */
  virtual void ChildWidgetDeleted(CATVidWidget* i_pDeletedChild);

  /**
   * Called by SetConstraints, it is overloaded by some 
   * inherited layout that need to addd an action at the end of a SetConstraints method.
   * @param i_pWidget the child widget to associate the constraints to.
   * @param i_constraints the constraints associated to i_pWidget.
   */
  virtual void InternalSetConstraints(CATVidWidget *i_pWidget, const CATVidLayConstraints& i_constraints) {};

  /**
   * Called by RemoveWidget, it is overloaded by some 
   * inherited layout that need to addd an action at the end of a RemoveWidget method.
   * @param i_pWidget the child widget to remove.
   * @param i_constraints the constraints associated to i_pWidget.
   */
  virtual void InternalRemoveWidget(CATVidWidget *i_pWidget, const CATVidLayConstraints& i_constraints) {};

  /**
   * Destructor.
   * @see CATVidWidget#~CATVidWidget
   */
	virtual ~CATVidLayCollection();

private:

  CATVidLayCollection (CATVidLayCollection &);
  CATVidLayCollection& operator=(CATVidLayCollection&);
  
  void _SetConstraints(CATVidWidget *i_pWidget, const CATVidLayConstraints* i_pConstraints);

  void _InsertAt(CATVidWidget *i_pWidget, int i_index, const CATVidLayConstraints* i_pConstraints);

private:

  CATBoolean _constraintUpdateAllowedFlag;
  CATBoolean _collectionDyingFlag;
	CATBoolean _usePreferredDimensionFlag;

#ifndef VID_DEPRECATED_LEVEL_2
private:
  CATVidGPSquare* _pSquareGP;
  CATVidColor _color;
public:
  /** @deprecated use composition instead with CATVidLayLayer and CATVidGPSquare for example*/
  void SetColor(const CATVidColor& i_color);
  /** @deprecated use composition instead with CATVidLayLayer and CATVidGPSquare for example*/
  const CATVidColor& GetColor() const;
  /** @deprecated use composition instead with CATVidLayLayer and CATVidGPSquare for example*/
  void SetColor(unsigned char i_r, unsigned char i_g, unsigned char i_b, unsigned char i_a);
  /** @deprecated use composition instead with CATVidLayLayer and CATVidGPSquare for example*/
  void SetBackgroundTexture(const char* i_pName);
  /** @deprecated use composition instead with CATVidLayLayer and CATVidGPSquare for example*/
  void ColorizeTexture(const CATVidColor& i_color, float i_fromR, float i_fromG, float i_fromB);
  /** @deprecated use composition instead with CATVidLayLayer and CATVidGPSquare for example*/
  void ResetColorize();
#endif

  friend class l_CATVidLay;
};

//-----------------------------------------------------------------------

#endif

// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATVidCtlForm
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Jun. 2011                                                            T. Pech
//=============================================================================
#ifndef CATVidCtlForm_H
#define CATVidCtlForm_H

#include "VisuDialogEx.h"
#include "CATVidCtl.h"
#include "CATISYPIntrospectable.h"
#include "CATListOfCATUnicodeString.h"
#include "CATVidColor.h"
#include "CATSYPArray.h"
//------------------------------------------------- IntrospectionInfrastructure
#include "CATISYPCollection.h"
#include <CATSYPDeclareEnumFactory.h>
#include <CATSYPBindingData.h>

class l_CATVidCtlForm;
class CATSYPEventArgs;
class CATSYPEvent;

/**
* Base class for form.
* <b>Role</b>:
* This widget is used to display tweaker components.
* It inherits the generic component CATVidCtl.
* <br>
* Create this CATVidCtlForm by using factory static method CreateForm.
* @ingroup VIDControls
*/
class ExportedByVisuDialogEx CATVidCtlForm: public CATVidCtl
{
  CATDeclareClass;

public:
  /**
  * Constructs a CATVidCtlForm.
  * No associsated style, use static factory CreateForm
  */
  CATVidCtlForm();

  /**
  * Constructs a CATVidCtlForm with standard style.
  * @param i_pParent
  *   The parent of the widget.
  * @param i_pIdentifier
  *   The name of the widget.
  */
  static CATVidCtlForm* CreateForm( CATCommand *ipParent, const CATString& iIdentifier );

  /**
  * Add a property
  * @param iNls
  *   The name of the property( Nls value).
  * @param iPropName
  *   The name of the property.
  * @param ispObject
  *   Introspectable object
  * @param iEnable
  *   allow to enable/disable tweaker
  * @param i_pBindingData : if property bound, the binding source data
  * @param iUndefined
  *   Specifies whether the tweaker is undefined or not.
  */
  HRESULT AddProperty( const CATUnicodeString& iNls, 
    const CATUnicodeString& iPropName, 
    const CATISYPIntrospectable_var& ispObject, 
    const CATBoolean& iEnable = TRUE, 
    CATSYPBindingSourceData* i_pBindingData = NULL,
    const CATBoolean& iUndefined = FALSE );

  /**
  * Add a attached property
  * @param iNls
  *   The name of the property( Nls value).
  * @param iPropName
  *   The name of the property.
  * @param ispObject
  *   Introspectable object
  * @param ispObjectAttach
  *   Introspectable attached object
  * @param iEnable
  *   allow to enable/disable tweaker
  * @param iUndefined
  *   Specifies whether the tweaker is undefined or not.
  */
  HRESULT AddAttachProperty( const CATUnicodeString& iNls, 
    const CATUnicodeString& iPropName, 
    const CATISYPIntrospectable_var& ispObject, 
    const CATISYPIntrospectable_var& ispObjectAttach, 
    const CATBoolean& iEnable = TRUE,
    const CATBoolean& iUndefined = FALSE );

  /**
  * Add a property, the property is disable.
  * @param iNls
  *   The name of the property( Nls value).
  * @param iPropName
  *   The name of the property.
  * @param iTypeName
  *   The type of the property( CATMathPoint2Df, CATMathVector2Df, CATUnicodeString, .
  *   CATVidColor, CATVidImageBlender, double, int,...)
  * @param iTypeTweak
  *   The tweak type of the property.
  * @param ispData
  *   Boxing Proterty value.
  * @param iEnable
  *   allow to enable/disable tweaker
  * @param iUndefined
  *   Specifies whether the tweaker is undefined or not.
  */
  HRESULT AddProperty( const CATUnicodeString& iNls, 
    const CATUnicodeString& iPropName, 
    const CATUnicodeString& iTypeName, 
    const CATUnicodeString& iTypeTweak, 
    const CATBaseUnknown_var& ispData, 
    const CATBoolean& iEnable = TRUE,
    const CATBoolean& iUndefined = FALSE );

  /**
  * Add a property
  * @param ispObject
  *   Introspectable object to connect with CATSYP::Connect
  * @param iListToDisplay
  *   List properties to display
  */
  HRESULT AddProperty( const CATISYPIntrospectable_var& ispObject, 
    const CATListOfCATUnicodeString& iListToDisplay );

  /**
  * Gets the data block
  */
  CATISYPIntrospectable_var GetData();

  /**
  * Sets the data block
  */
  void SetData( CATISYPIntrospectable_var ispDataBlock );

  /**
  * Sets the grid Flag of the form.
  * @param iGridFlag
  * The grid Flag of the form to set.
  *   <br>
  *   <b>Legal values</b> : It can be set to either :
  *   <dl>
  *   <dt><tt>FALSE</tt><dd> the grid is not displayed,
  *   <dt><tt>TRUE</tt><dd> the grid is displayed
  *   </dl>
  */
  void SetGridFlag( const CATBoolean iGridFlag );

  /**
  * @return the grid Flag of the form
  *   <br>
  * The grid Flag of the form can be:
  *   <dl>
  *   <dt><tt>FALSE</tt><dd> not display the grid,
  *   <dt><tt>TRUE</tt><dd> the grid is displayed.
  *   </dl>
  */
  CATBoolean GetGridFlag() const;

  /**
  * Sets the alternate background Flag of the form.
  * @param iFlag
  * The alternate background Flag of the form to set.
  *   <br>
  *   <b>Legal values</b> : It can be set to either :
  *   <dl>
  *   <dt><tt>FALSE</tt><dd> the alternate background is not displayed,
  *   <dt><tt>TRUE</tt><dd> the alternate background is displayed
  *   </dl>
  */
  void SetAlternateBackgroundFlag( const CATBoolean iFlag );

  /**
  * @return the alternate background Flag of the form
  *   <br>
  * The alternate background Flag of the form can be:
  *   <dl>
  *   <dt><tt>FALSE</tt><dd> not display the alternate background,
  *   <dt><tt>TRUE</tt><dd> the alternate background is displayed.
  *   </dl>
  */
  CATBoolean GetAlternateBackgroundFlag() const;

  /**
  * Sets the alternate background color of the form.
  * @param i_color
  * The alternate background color of the form to set.
  */
  void SetAlternateBackgroundColor( const CATVidColor& i_color );

  /**
  * @return the alternate background color of the form
  *   <br>
  * The alternate background color of the form can be:
  */
  CATVidColor GetAlternateBackgroundColor() const;

  /**
  * Sets the crop policy for the labels.
  */
  void SetLabelsCropPolicy( CATVid::CropPolicy i_LabelsCropPolicy);

  /**
  * @return the crop policy for the labels.
  */
  CATVid::CropPolicy GetLabelsCropPolicy() const;

  /**
  * Sets the alignment of labels in form.
  */
  void SetLabelsAlignment( CATVid::Alignment i_LabelsAlignment);

  /**
  * @return the alignment of labels in form.
  */
  CATVid::Alignment GetLabelsAlignment() const;

  //implements methods of CATISYPCollection--------------------------------------
  /**
  * Gets item at at requested index.
  * @param i_index the index of the element to retrieve in the collection
  * @return the emelent to retrieve. Will be NULL_var if not found
  */
  virtual CATBaseUnknown_var GetAt( int i_index ) ;
  /**
  * @return the number of elements of the collection
  */
  virtual int GetCount() ;
  /**
  * Adds an item to the collection.
  * The implementation of this extention must AddRef the given CATBaseUnknown.
  * The implementation should assert if the object is already contained by the collection.
  * @param i_spObject the object to append to the collection
  */
  virtual void Append( const CATBaseUnknown_var &i_spObject ) ;
  /**
  * Adds a list of items to the collection.
  * The implementation of this extention must AddRef the given objects.
  * @param a list of objects to add
  */
  virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list ) ;
  /**
  * Removes an item of the collection.
  * The implementation should assert if the object is not member of the collection.
  */
  virtual void Remove( const CATBaseUnknown_var &i_spObject ) ;
  /**
  * Removes an item of the collection.
  * The implementation should assert if the object is not member of the collection.
  */
  virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list ) ;
  /**
  * Clears the collection, by removing and releasing all elements.
  */
  virtual void Clear() ;
  /**
  * Determine if an object is member of the collection
  */
  virtual int Contains( const CATBaseUnknown_var &i_spObject ) ;
  /** @deprecated */
  virtual void Append( const CATLISTV(CATBaseUnknown_var) &i_list ) ;

  CATISYPCollection_var  GetItems();    
  const CATString & GetNlsFiles() const;

  void SetNlsFiles(const CATString & i_nlsFiles);

  /*
  * Sets the undo button Flag of the form.
  * @param iFlag
  * The undo button Flag of the form to set.
  *   <br>
  *   <b>Legal values</b> : It can be set to either :
  *   <dl>
  *   <dt><tt>FALSE</tt><dd> the undo button is not displayed,
  *   <dt><tt>TRUE</tt><dd> the undo button is displayed
  *   </dl>
  */
  void SetUndoButtonFlag( const CATBoolean iFlag );

  /*
  * @return the undo button Flag of the form
  *   <br>
  * The undo button Flag of the form can be:
  *   <dl>
  *   <dt><tt>FALSE</tt><dd> not display the undo button,
  *   <dt><tt>TRUE</tt><dd> the undo button is displayed.
  *   </dl>
  */
  CATBoolean GetUndoButtonFlag() const;

  /**
  * Specifies whether the form uses transactions for editing the property or not.
  * When the form uses an edition transaction, the following events are emitted :
  *   - EditingStarted : event emitted at the beginning of the edition transaction before any value modification
  *   - ValueLiveChanged : event emitted (potentially several times per transaction) when the 
  *     value is modified during the end user interaction (e.g the drag of a slider or the multipress of a 
  *     spinbox in a tweaker of double)
  *   - ValueChanged : event emitted when the transaction is about to finish and when the value has been 
  *     modified during this transaction
  *   - EditingFinished : event emitted at the end of the edition transaction after any value modification
  *
  * When the form does not use any edition transaction (the default behavior), only the ValueChanged event is 
  * emitted when the property value is modified.
  *
  * By default, the UseTransactionFlag property is set to FALSE.
  *
  * @see EditingStarted
  * @see ValueLiveChanged
  * @see ValueChanged
  * @see EditingFinished
  */
  void SetUseTransactionFlag(CATBoolean i_useTransactionFlag);

  /**
  * Returns TRUE if the form uses transactions for editing the property, FALSE otherwise.
  * By default, the UseTransactionFlag property is set to FALSE.
  * @see SetUseTransactionFlag
  */
  CATBoolean GetUseTransactionFlag() const;

  /**
  * Define  if display bindings data or not
  */
  void SetDisplayBindingsFlag(CATBoolean i_displayBindingsFlag);

  /**
  * Get Display bindings flag
  */
  CATBoolean GetDisplayBindingsFlag() const;


  /**
  * Specifies whether the duration of the edition transaction is related to the display of the 
  * tweaker detailed view or not.
  * Some tweakers are using a detailed view displayed in a popup window to edit the property (e.g the the Color tweaker).
  * When the tweaker uses an edition transaction and when the UseDetailedViewTransactionFlag property is set to TRUE,
  * the following events are emitted :
  *   - EditingStarted : event emitted at the beginning of the edition transaction when the tweaker detailed view is displayed
  *   - EditingFinished : event emitted at the end of the edition transaction when the tweaker detailed view is closed
  *
  * By default, the UseDetailedViewTransactionFlag property is set to FALSE.
  * Note that this property has an effect only when the other UseTransactionFlag property is set to TRUE.
  *
  * @see EditingStarted
  * @see EditingFinished
  * @see SetUseTransactionFlag
  */
  void SetUseDetailedViewTransactionFlag(CATBoolean i_useDetailedViewTransactionFlag);

  /**
  * Returns TRUE if the duration of the edition transaction is related to the display of the 
  * tweaker detailed view, FALSE otherwise.
  * By default, the UseDetailedViewTransactionFlag property is set to FALSE.
  * @see SetUseDetailedViewTransactionFlag
  */
  CATBoolean GetUseDetailedViewTransactionFlag() const;


  /**
  * Sets the inner cell spacing (inter-cells space between two property).
  * By default, the InnerCellSpacing property is equal to 1.
  */
  void SetInnerCellSpacing(int i_innerCellSpacing);

  /**
  * @return the inner cell spacing (inter-cells space).
  */
  int GetInnerCellSpacing() const;



  /**
  * Returns the @c EditingStarted event.
  * The @c EditingStarted event is emitted at the beginning of the edition transaction 
  * before any value modification.
  * This event is emitted only when the UseTransactionFlag property is set to TRUE.
  *
  * @see SetUseTransactionFlag
  * @see EditingFinished
  * @par EventProperties
  *   - Name: @c "EditingStarted"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPPropertiesChangedEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * EditingStarted();

  /**
  * Returns the @c ValueLiveChanged event.
  * The @c ValueLiveChanged event is emitted (potentially several times per transaction) by the form when 
  * a value is modified during the end user interaction (e.g the drag of a slider or the multipress of a 
  * spinbox in a tweaker of double)
  * This event is emitted only when the UseTransactionFlag property is set to TRUE.
  *
  * @see SetUseTransactionFlag
  * @par EventProperties
  *   - Name: @c "ValueLiveChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPPropertiesChangedEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * ValueLiveChanged();

  /**
  * Returns the @c ValueChanged event.
  * The @c ValueChanged event is emitted when a tweaker value is modified.
  * When the form uses an edition transaction, the ValueChanged event is emitted when the transaction is
  * about to finish and when the value has been modified during this transaction.
  * When the form does not use any edition transaction, the ValueChanged event is 
  * emitted whenever the property value is modified.
  *
  * @see SetUseTransactionFlag
  * @see ValueLiveChanged
  * @par EventProperties
  *   - Name: @c "ValueChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPPropertiesChangedEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * ValueChanged();

  /**
  * Returns the @c EditingFinished event.
  * The @c EditingFinished event is emitted at the end of the edition transaction 
  * after any value modification.
  * This event is emitted only when the UseTransactionFlag property is set to TRUE.
  *
  * @see SetUseTransactionFlag
  * @see EditingStarted
  * @par EventProperties
  *   - Name: @c "EditingFinished"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPPropertiesChangedEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * EditingFinished();

  /**
  * Returns the @c BindingRemoved event.
  * The @c BindingRemoved event is emitted when a binded tweaker is removed
  *
  * @par EventProperties
  *   - Name: @c "BindingRemoved"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPPropertiesChangedEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* BindingRemoved();

  /**
  * Returns the @c BindingAdded event.
  * The @c BindingAdded event is emitted when a binded tweaker is removed
  *
  * @par EventProperties
  *   - Name: @c "BindingAdded"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPPropertiesChangedEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* BindingAdded();

  /**
  * Handles the EditingStarted event dispatched by the tweakers.
  */
  void OnEditingStarted(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
  * Handles the ValueLiveChanged event dispatched by the tweakers.
  */
  void OnValueLiveChanged(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
  * Handles the ValueChanged event dispatched by the tweakers.
  */
  void OnValueChanged(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
  * Handles the EditingFinished event dispatched by the tweakers.
  */
  void OnEditingFinished(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
  * Handles the BindingRemoved event dispatched by the tweakers.
  */
  void OnBindingRemoved(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
  * Handles the BindingAdded event dispatched by the tweakers.
  */
  void OnBindingAdded(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
  * Set tootlip on tweakers
  */
  void SetPropertyTooltip(const CATUnicodeString& i_propertyName, const CATUnicodeString& i_shortHelptooltip, const CATUnicodeString& i_longHelptooltip);

protected:

  virtual ~CATVidCtlForm();

  /**
  * This function is called once the template data have been
  * collected from the style processor. We use those data to access objects in our xml style template by their 
  * @c syp:name 
  */
  virtual void TemplateDataUpdated();

  void _DispatchEvent(CATBaseUnknown * i_pSender, CATSYPEvent * i_pEvent);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlForm (CATVidCtlForm &);
  CATVidCtlForm& operator=(CATVidCtlForm&); 

  CATVidCtlForm( CATCommand* ipParent, const CATString& iIdentifier );

  CATISYPIntrospectable_var  _spData;
  unsigned int               _GridMode : 1;
  unsigned int               _AlternateBackground : 1;
  unsigned int               _UndoButtonFlag : 1;
  CATVidColor                _Color;
  CATString                 _nlsFiles;
};
#endif

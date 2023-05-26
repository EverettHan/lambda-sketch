// COPYRIGHT Dassault Systemes 2001
#ifndef CATIParameterEditor_H
#define CATIParameterEditor_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIParameterEditor ;
#else
extern "C" const IID IID_CATIParameterEditor ;
#endif

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

class CATICkeParm;
class CATDlgFrame;
class CATUnicodeString;
class CATICkeUnit_var;



//------------------------------------------------------------------
/**
*  Parameter Editor Style.
*  @param    WithoutLabel
*  Whithout label
*  @param    WithoutSpinner			
*  Whithout spinner
*  @param    KeepCxtMenuWhenDisable
*  even when the editor is disabled, the contextual menu is still available
*  @param    RelationButtonDisabled	
*  the relation button is disable
*  @param    NoCxtMenuOnParam	
*  the contextual menu is disable
*  @param    NoCtxAddTolerance	
*  the add tolerance item of the contextual menu is disable
*  @param    NoCtxAddRange				
*  the add range item of the contextual menu is disable
*  @param    NoCtxAddFormula			
*  the add formula item of the contextual menu is disable
*  @param    NoCtxAddMeasure			
*  the add measure item of the contextual menu is disable
*  @param    NoCtxParamRename			
*  the parameter can not be renamed
*  @param    WithCtxParamUnset	
*  the unset item of the contextual menu is enable
*/
typedef unsigned long CATParameterEditorStyle;

/**
 * Interface to the standard parameter editor. 
 * <b>Role</b>: It allows the user to manipulate a parameter editor.<br>
 * To create a standard parameter editor instance, use the @href CATIParameterEditorFactory
 * This editor is dedicated for two kind of parameters: literal and volatile value.
 * @see CATIParameterEditorFactory
 */ 
class ExportedByKnowledgeItf CATIParameterEditor: public CATBaseUnknown
{
  CATDeclareInterface;

  public:


/**  @nodoc  */ 
#define       WithoutLabel				(1 << 0)
/**  @nodoc  */ 
#define  	  WithoutSpinner			(1 << 1)
/**  @nodoc  */ 
#define  	  KeepCxtMenuWhenDisable	(1 << 2)
/**  @nodoc  */ 
#define  	  RelationButtonDisabled	(1 << 3)
/**  @nodoc  */ 
#define  	  NoCxtMenuOnParam			(1 << 4)
/**  @nodoc  */ 
#define  	  NoCtxAddTolerance			(1 << 5)
/**  @nodoc  */ 
#define  	  NoCtxAddRange				(1 << 6)
/**  @nodoc  */ 
#define  	  NoCtxAddFormula			(1 << 7)
/**  @nodoc  */ 
#define  	  NoCtxAddMeasure			(1 << 8)
/**  @nodoc  */ 
#define  	  NoCtxParamRename			(1 << 9)
/**  @nodoc  */ 
#define  	  WithCtxParamUnset			(1 << 10)


    /**
     * Sets the parameter to be edited.
	 * @param iParameter
	 * The parameter to be edited. If this argument is NULL, the editor is emptied and cannot be used
	 */
	  virtual void SetEditedParameter(const CATICkeParm *iParameter) = 0;

	  /**
	  * Returns the edited parameter. It can be NULL. If it is not NULL, AddRef is called on the returned pointer.
	  */
	  virtual CATICkeParm * GetEditedParameter() = 0;

	  /**
	  * Sets the editor wisible text width of the editor.
	  * This method has no effect if the parameter editor's frame has been attached using its right hand side and if its grid column is resizable.
	  * @param iWidth
	  * The width of the text editor expressed in number of characters.
	  */
	  virtual void SetVisibleTextWidth(const int iWidth) = 0;

	  /**
	  * Use this method to retrieve the parameter editor frame. 
		* This frame can be used, for example to manage the dialog layout.
	  * @return
	  * The frame that contains the parameter editor.
	  */
	  virtual CATDlgFrame * GetFrame() = 0;

	  /**
	  * Sets a style to the parameter editor frame (available only on R16 and upper level).
	  * The style allows to customize the editor display and the contextual menu.
	  * @param iStyle
	  * The style of the parameter editor.
	  * for example : WithoutLabel | NoCtxAddTolerance | RelationButtonDisabled
	  */
	  virtual void SetEditorStyle(const CATParameterEditorStyle &iStyle) = 0;

	  /*
       * Enable to manipulate a dimensioned attribute.
	   */
	  virtual HRESULT SetUnitToUse(const CATICkeUnit_var & ispUserDefinedUnitToDisplay) = 0;
};

//------------------------------------------------------------------

#endif

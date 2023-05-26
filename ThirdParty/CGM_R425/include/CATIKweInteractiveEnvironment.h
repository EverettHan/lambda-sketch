// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIKweInteractiveEnvironment.h
// Define the CATIKweInteractiveEnvironment interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  tvq
//===================================================================
#ifndef CATIKweInteractiveEnvironment_H
#define CATIKweInteractiveEnvironment_H

#include "CATLifSpecs.h"
#include "CATString.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKweInteractiveEnvironment;
#else
extern "C" const IID IID_CATIKweInteractiveEnvironment ;
#endif

// copi� tel quel de CATKweMessages.h, c'est pour permettre de faire la migration le plus rapidement possible
// ca serait mieux d'en faire un enum d'interface. 
#define AnswerOK 1
#define AnswerCancel 2
#define AnswerYes 3
#define AnswerNo 4
#define AnswerRetry 5
#define AnswerAbort 6
#define AnswerIgnore 7

class CATUnicodeString;
//class CATIAApplication;
class CATPathElement;
class CATCommandSelector;

//------------------------------------------------------------------

/**
 * This interface gives access to various services using the interactive environment 
 */
class ExportedByCATLifSpecs CATIKweInteractiveEnvironment: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Sets the cursor to the busy cursor. This busy cursor will be changed to standard one the next time main loop will be executed
     */
	  virtual void CATSetBusyCursor() = 0;

	  /**
	  * Shows an information popup
	  */ 
	  virtual void CATShowInformation(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Info") = 0;

	  /**
	  * Shows a warning popup
	  */ 
	  virtual void CATShowWarning(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Warning") = 0;

	  /**
	  * Shows an error popup
	  */ 
	  virtual void CATShowError(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Error") = 0;

	  /**
	  * Shows a question popup with Yes No
	  */
	  virtual int CATAskQuestion(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Question") = 0;

	  /**
	  * Shows a question popup with Yes No Cancel
	  */
	  virtual int CATAskQuestionWithCancel(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "QuestionCancel") = 0;
	  
	  /**
	  * Shows a question popup with OK Cancel
	  */
	  virtual int CATAskConfirmation(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Question") = 0;

	  /**
	  * Starts a command defined in the module iModule which class is iClass and which header name is or will be iName. The argument iForce says if the command is to be looked for
	  * in not yet loaded workbenchs
	  */
	  virtual HRESULT CATStartCommand(const CATUnicodeString &iName, const CATUnicodeString &iModule, const CATUnicodeString &iClassName, int iForce = 0, int setAvailability = 0, int unlock = 0) = 0;

	  /**
	  * Searchs an element that implements given interface in the UIActiveObject path element.
	  */
	  virtual HRESULT SearchElementInActiveObject(const CATString &iInterface, CATBaseUnknown_var &oElement) = 0;

	  /*
	  * Inits the Error Manager UI
	  */
	  virtual void InitErrorManagerUI() = 0;

    /*
    * Checks if we have an CATApplicationFrame
    */
    virtual CATBoolean CheckApplicationFrame() = 0;

    /*
    * Return element idx from the cso from the current editor
    */
    virtual CATPathElement* GetCurrentSelectedElement(const int & idx) = 0;

    /*
    * Return the number of selected elements from the cso from the current editor
    */
    virtual int GetNbSelectedElements() = 0;

    /*
    * Checks if we have a current editor
    */
    virtual CATBoolean CheckCurrentEditor() = 0;

	/*
	* Return UI active Object
	*/
	virtual CATPathElement GetUIActiveObject() = 0;

    /*
    * Get the command selector from the current editor
    */
    virtual CATCommandSelector* GetCurrentCommandSelector() = 0;

    /*
    * Returns the CATBaseUnknown* associated to the CATIApplicationFrame 
    * #Release
    */
    virtual CATBaseUnknown* GetBUApplicationFrame() = 0;

    /*
    * Run Error Panel on main window
    */
    virtual HRESULT RunErrorPanel() = 0;
    
    /*
    * Calls CATAfrRepCreation
    */
    virtual void CallCATAfrRepCreation(CATBoolean CreateOrNot) = 0;

    /*
    * Calls CATAfrForceRepCreation
    */
    virtual void CallCATAfrForceRepCreation() = 0;




};
CATDeclareHandler(CATIKweInteractiveEnvironment, CATBaseUnknown);

//------------------------------------------------------------------

#endif
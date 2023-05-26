// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATAfrPLMMultiRootEditor.h
// Header definition of CATAfrPLMMultiRootEditor
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2006  Creation: Code generated by the CAA wizard  fsd
//===================================================================
#ifndef CATAfrPLMMultiRootEditor_H
#define CATAfrPLMMultiRootEditor_H

#include "CATAfrFoundation.h"
#include "CATFrmEditor.h"
#include "CATOmbLifeCycleRootsBag.h"
//-----------------------------------------------------------------------

class ExportedByCATAfrFoundation CATAfrPLMMultiRootEditorNotification : public CATNotification
{
	  CATDeclareClass;

  public: 
	  CATAfrPLMMultiRootEditorNotification (CATBaseUnknown * iRoot);
	  virtual ~CATAfrPLMMultiRootEditorNotification();

	  void GetRoot(CATBaseUnknown *& oRoot);	  

  private:
	  CATBaseUnknown * _root;
};

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href CATAfrPLMMultiRootEditor constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new CATAfrPLMMultiRootEditor;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByCATAfrFoundation CATAfrPLMMultiRootEditor: public CATFrmEditor
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     CATAfrPLMMultiRootEditor ();
     virtual ~CATAfrPLMMultiRootEditor ();

    /**
    * Event sent after a root is inserted to the editor.
   	* <br><b>Role:</b><br>this event is sent by the CATAfrPLMMultiRootEditor.
   	* <br>Sample of callback:
   	* <pre>
     * ::AddCallback(this,
     *              <an_instance_of_CATAfrPLMMultiRootEditor_class>,
   	*	           CATAfrPLMMultiRootEditor::AFTER_ROOT_ADDED(),
   	*	           (CATSubscriberMethod)&MyClass::MyCBMethod,
   	*	           NULL);
   	* </pre>
   	*/
     CATDeclareCBEvent (AFTER_ROOT_ADDED);

    /**
    * Event sent before a root is removed from the editor.
   	* <br><b>Role:</b><br>this event is sent by the CATAfrPLMMultiRootEditor.
   	* <br>Sample of callback:
   	* <pre>
     * ::AddCallback(this,
     *              <an_instance_of_CATAfrPLMMultiRootEditor_class>,
   	*	           CATAfrPLMMultiRootEditor::BEFORE_ROOT_REMOVED(),
   	*	           (CATSubscriberMethod)&MyClass::MyCBMethod,
   	*	           NULL);
   	* </pre>
   	*/
     CATDeclareCBEvent (BEFORE_ROOT_REMOVED);

	 /*
	virtual void                  Activate();
	virtual void                  Deactivate();
	virtual CATFrmWindow *        CreateDefaultWindow() = 0;
	virtual int                   CloseDocument();
	*/
	virtual int                   Close();


    /*
     * Method called by RemoveRoot before removing the root.
     * This method can be override by derived classes.
     */
    virtual void BeginRemoveRoot(CATBaseUnknown * iRoot );

	void DeclareRootToEditor(CATBaseUnknown * iRoot);
	void RemoveRoot(CATBaseUnknown * iRoot );

private:
	CATOmbLifeCycleRootsBag m_roots;

};

//-----------------------------------------------------------------------

#endif

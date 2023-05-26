#ifndef GraphicsOptimizerDocument_H
#define GraphicsOptimizerDocument_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATDlgDocument.h"
#include "CATErrorDef.h"

class GraphicsOptimizerBuilder;

/**
 * This is the Graphics Optimizer document base-class.
 * You have to inherit from this class and override the necessary methods for being able to create
 * an interactive document allowing the end-user to optimize the rendering parameters accessible to him.
 * This document can later be integrated in the @href GraphicsOptimizerApplication interactive application or
 * in any other @href CATInteractiveApplication of your choice.
 * If you choose the second option, your application will have to override the @href AnalyseNotification method
 * and listen to @href GraphicsOptimizerDeletionNotification notifications that will be emitted by the document 
 * to signal its intention of being destroyed. You will have to take this into account to execute all necessary
 * clean-up process.
 */
class ExportedByGraphicsOptimizer GraphicsOptimizerDocument : public CATDlgDocument
{
  DeclareResource(GraphicsOptimizerDocument, CATDlgDocument);

	CATDeclareClass;
	
public:
	
  /**
   * Destructor.
   */
	virtual ~GraphicsOptimizerDocument();

  /**
   * If you create your own interactive application, you have to call this method to build the document.
   * If you're using an inherited class of the @href GraphicsOptimizerApplication base class, you don't need to call this
   * method as it is automatically called for you in the @href GraphicsOptimizerApplication::BeginApplication() method. 
   */
  HRESULT BuildDocument();

  /**
   * Do not override this method as it is necessary for the @href GraphicsOptimizerDocument to work properly.
   */
  virtual CATNotifPropagationMode AnalyseNotification(CATCommand* ipFromClient, CATNotification* ipNotification);

protected:

  /**
   * The Graphics Optimizer document constructor.
   * This method is protected so that only inherited classes can call it. The document is defined by its name and
   * the application that uses it.
   */
  GraphicsOptimizerDocument(CATInteractiveApplication *iParent, const CATString& iDocumentName);

  /**
   * Call this method to retrieve the @href GraphicsOptimizerBuilder object associated to this document.
   */
  GraphicsOptimizerBuilder* GetBuilder();

  /**
   * This method is called when it is necessary to create the document builder associated to this document.
   * The builder has to inherit from the @href GraphicsOptimizerBuilder class.
   */
  virtual HRESULT CreateBuilder(GraphicsOptimizerBuilder** opBuilder) = 0;

  /**
   * This method is called when it is necessary to create the document interface.
   * A document may possess an interactive interface or no interface at all, depending of implementation.
   */
  virtual HRESULT BuildDocumentInterface() = 0;

  /**
   * This method is called when it is necessary to update the document interface, as the consequence of tests execution.
   */
  virtual HRESULT UpdateDocumentInterface() = 0;

  /**
   * This method is called when it is necessary to clean the document interface.
   * This process is executed before the document deletion.
   */
  virtual HRESULT CleanDocumentInterface() = 0;

private:

  /**
   * Copy not allowed.
   */
  GraphicsOptimizerDocument();
  GraphicsOptimizerDocument(const GraphicsOptimizerDocument&);
  GraphicsOptimizerDocument& operator=(const GraphicsOptimizerDocument&);

  void OnTestsFinished(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

  void ExitDocument();

  GraphicsOptimizerBuilder* _pBuilder;

  CATCallback _OnEndOfTestsCB;
};

#endif

#ifndef GraphicsOptimizerDocument_OneShot_H
#define GraphicsOptimizerDocument_OneShot_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "GraphicsOptimizerDocument.h"
#include "CATErrorDef.h"

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
class ExportedByGraphicsOptimizer GraphicsOptimizerDocument_OneShot : public GraphicsOptimizerDocument
{
	CATDeclareClass;
	
public:
	
  /**
   * Destructor.
   */
	virtual ~GraphicsOptimizerDocument_OneShot();

protected:

  /**
   * The Graphics Optimizer interactive document constructor.
   * This method is protected so that only inherited classes can call it. The document is defined by its name and
   * the application that uses it.
   */
  GraphicsOptimizerDocument_OneShot(CATInteractiveApplication *iParent, const CATString& iDocumentName);

  /**
   * This method is called when it is necessary to create the document interface.
   * A document may possess an interactive interface or no interface at all, depending of implementation.
   */
  virtual HRESULT BuildDocumentInterface();

  /**
   * This method is called when it is necessary to update the document interface, as the consequence of tests execution.
   */
  virtual HRESULT UpdateDocumentInterface();

  /**
   * This method is called when it is necessary to clean the document interface.
   * This process is executed before the document deletion.
   */
  virtual HRESULT CleanDocumentInterface();

private:

  /**
   * Copy not allowed.
   */
  GraphicsOptimizerDocument_OneShot();
  GraphicsOptimizerDocument_OneShot(const GraphicsOptimizerDocument_OneShot&);
  GraphicsOptimizerDocument_OneShot& operator=(const GraphicsOptimizerDocument_OneShot&);
};

#endif

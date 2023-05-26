#ifndef GraphicsOptimizerApplication_H
#define GraphicsOptimizerApplication_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATInteractiveApplication.h"
#include "CATErrorDef.h"

class GraphicsOptimizerDocument;

/**
 * This is the Graphics Optimizer application base-class.
 * You have to inherit from this class and override the necessary methods for being able to create
 * an interactive application allowing the end-user to optimize the rendering parameters accessible to him.
 */
class ExportedByGraphicsOptimizer GraphicsOptimizerApplication : public CATInteractiveApplication 
{
  CATDeclareClass;

public:  

  /**
   * Destructor.
   */
  virtual ~GraphicsOptimizerApplication();
	
  /**
   * Do not override this method as it is necessary for the @href GraphicsOptimizerApplication to work properly.
   */
  virtual void BeginApplication();

  /**
   * Do not override this method as it is necessary for the @href GraphicsOptimizerApplication to work properly.
   * This method is listening to @href GraphicsOptimizerDeletionNotification notifications that can be emitted by
   * the @href GraphicsOptimizerDocument document to signal its intention of being destroyed.
   */
  virtual CATNotifPropagationMode AnalyseNotification(CATCommand* ipFromClient, CATNotification* ipNotification);

protected:

  /**
   * The Graphics Optimizer application constructor.
   * This method is protected so that only inherited classes can call it. The application is defined by a name.
   */
  GraphicsOptimizerApplication(const CATString &ApplicationName);

  /**
   * This method is called when it is necessary to build the document contained in this application.
   * The document has to inherit from the @href GraphicsOptimizerDocument class.
   */
  virtual HRESULT CreateDocument(CATInteractiveApplication* ipApplication, GraphicsOptimizerDocument** opDocument) = 0;

  /**
   * This method is called whenever it is necessary to perform any clean-up process before the application destruction.
   */
  virtual void CleanApplication() = 0;

private:

  /**
   * Copy not allowed.
   */
  GraphicsOptimizerApplication();
  GraphicsOptimizerApplication(const GraphicsOptimizerApplication&);
  GraphicsOptimizerApplication& operator=(const GraphicsOptimizerApplication&);

  void ExitApplication();

  void OnDeletionRequest(CATCommand *iCmd, CATNotification *iNotif, CATCommandClientData iData);

  GraphicsOptimizerDocument* _pDocument;
};

#endif

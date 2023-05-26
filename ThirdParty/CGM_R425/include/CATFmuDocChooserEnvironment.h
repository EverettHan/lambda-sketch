/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002
#ifndef _CATFmuDocChooserEnvironment_h
#define _CATFmuDocChooserEnvironment_h

/**
  * Flags to determine which environment the user may use to choose a document with <tt> @href CATIFmuDialogFactory </tt>.
  *  @see CATIFmuDialogFactory#CreateDocumentChooser
  *
  *  @param CATDocChooserInSession
  *  To allow the user to select among Loaded Documents
  *  @param CATDocChooserCatalogBrowser
  *  To allow the user to select a document using the Catalog Browser, if available.
  */
typedef unsigned long CATFmuDocChooserEnvOptions;  

/**  @nodoc 
  *  @param CATDocChooserInSession
  *  To allow the user to select among Loaded Documents
  *  @see CATIFmuDialogFactory#CreateDocumentChooser
  */
#define CATDocChooserInSession      (1<<0)

/**  @nodoc 
  *  @param CATDocChooserCatalogBrowser
  *  To allow the user to select a document using the Catalog Browser, if available.
  *  @see CATIFmuDialogFactory#CreateDocumentChooser
  */
#define CATDocChooserCatalogBrowser (1<<1)

/** @nodoc */
#define CATDocChooserNoDefault      (1 << 10)

#endif

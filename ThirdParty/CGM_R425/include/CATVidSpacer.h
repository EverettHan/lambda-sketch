// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidSpacer.h
// Header definition of CATVidSpacer
//
//===================================================================
//
//  Oct 2005  Creation: jov
//===================================================================
#ifndef CATVidSpacer_H
#define CATVidSpacer_H

#include <VisuDialog.h>
#include <CATVidWidget.h>
/**
 * @ingroup VIDCore
 */
/**
 * Layout class used to size layout with no graphic primitive.
 * Must be created and layouted like any widget, and sized with 
 * the RequestedMinimumDimension property.
 */
class ExportedByVisuDialog CATVidSpacer: public CATVidWidget
{
  CATDeclareClass;
public:
  /** Constructor. */
  CATVidSpacer ();
protected:
  /** Constructor. */
  CATVidSpacer(CreateLetterFunc i_pCreateLetterFunc);
  /** Destructor. */
  virtual ~CATVidSpacer ();
private:
  /** Copy constructor. */
  CATVidSpacer(const CATVidSpacer& iToCopy);
  /** Equal operator. */
  CATVidSpacer& operator=(CATVidSpacer&original);
};
//-----------------------------------------------------------------------

#endif


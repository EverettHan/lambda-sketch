#ifndef CATVidConstraintsModifiedEventArgs_h
#define CATVidConstraintsModifiedEventArgs_h

// COPYRIGHT Dassault Systemes 2014

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATSYPEventArgs.h>

// System framework
#include <CATBaseUnknown_WR.h>

class CATVidWidget;
class CATVidLayConstraints;

/** 
 * Event argument used in the @ref CATVidCtlCollection::SetConstraints method when the layout of 
 * a widget is modified.
 *
 * @see CATVidCtlCollection
 */
class ExportedByVisuDialog CATVidConstraintsModifiedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:

  /** 
   * Constructor.
   *
   * @param i_pEvent the event dispatched. Cannot be @c NULL.
   * @param i_pWidget the widget whose layout constraints has been modified. Cannot be @c NULL. 
   * Only a weak reference is kept.
   * @param i_constraints the new layout constraints of the widget.
   */
  CATVidConstraintsModifiedEventArgs(CATSYPEvent * i_pEvent, CATVidWidget * i_pWidget, const CATVidLayConstraints& i_constraints);

  /** 
   * Destructor. 
   */
  virtual ~CATVidConstraintsModifiedEventArgs();

  /**
   * @return the widget whose layout constraints has been modified. 
   */
  CATVidWidget * GetWidget() const;

  /**
   * @return the new layout constraints of the widget. 
   */
  CATVidLayConstraints * GetConstraints() const;

private:

  /** Copy constructor. */
  CATVidConstraintsModifiedEventArgs (CATVidConstraintsModifiedEventArgs &);
  /** Equal operator. */
  CATVidConstraintsModifiedEventArgs& operator=(CATVidConstraintsModifiedEventArgs&);

private:

  CATBaseUnknown_WR _widget;
  CATVidLayConstraints * _pConstraints;
};

#endif // CATVidConstraintsModifiedEventArgs_h

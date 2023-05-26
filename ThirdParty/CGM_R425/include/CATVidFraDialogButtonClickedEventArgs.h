#ifndef CATVidFraDialogButtonClickedEventArgs_h
#define CATVidFraDialogButtonClickedEventArgs_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraDialog.h>

// IntrospectionInfrastructure framework
#include <CATSYPEventArgs.h>

class CATSYPEvent;

/**
 * Arguments for the event dispatched when a standard button of a CATVidFraDialog has been clicked.
 * @see CATVidFraDialog
 */
class ExportedByVisuDialog CATVidFraDialogButtonClickedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

  public:
  
    /**
     * Constructor
     * @param i_pEvent the event dispatched. Can't be @c NULL.
     * @param i_button the standard button associated to the event
     */
    CATVidFraDialogButtonClickedEventArgs(CATSYPEvent *i_pEvent, CATVidFraDialog::StandardButton i_button);
    
    /**
     * Destructor
     */
    virtual ~CATVidFraDialogButtonClickedEventArgs();

    /**
     * Returns the standard button associated to the event.
     */
    CATVidFraDialog::StandardButton GetStandardButton() const;

  private:
    
    CATVidFraDialogButtonClickedEventArgs(CATVidFraDialogButtonClickedEventArgs&);
    CATVidFraDialogButtonClickedEventArgs& operator=(CATVidFraDialogButtonClickedEventArgs&);

    CATVidFraDialog::StandardButton _button;
};

#endif // CATVidFraDialogButtonClickedEventArgs_h

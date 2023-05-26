#ifndef CATVidDashboardPageChangedEventArgs__H
#define CATVidDashboardPageChangedEventArgs__H

// COPYRIGHT Dassault Systemes 2016

// VisuImmersiveDialog framework
#include <VisuDialog.h>

// IntrospectionInfrastructure framework
#include <CATSYPEventArgs.h>

class CATSYPEvent;
class CATVidCtlDashboardPage;
class CATSysWeakRef;

/**
 * Arguments for the event dispatched when a CATVidFraGridWindow has been
 * attached to a new dashboard page.
 *
 * @see CATVidFraGridWindow
 */
class ExportedByVisuDialog CATVidDashboardPageChangedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  /**
   * Constructor
   *
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   *
   * @param i_pPreviousDashboardPage the dashboard page from which the
   * CATVidFraGridWindow object will be dettached.
   *
   * @param i_pNewDashboardPage the dashboard page to which the
   * CATVidFraGridWindow object will be attached.
   */
  CATVidDashboardPageChangedEventArgs(CATSYPEvent *i_pEvent, CATVidCtlDashboardPage * i_pPreviousDashboardPage, CATVidCtlDashboardPage * i_pNewDashboardPage);

  /**
   * Destructor
   */
  virtual ~CATVidDashboardPageChangedEventArgs();

  /**
   * Returns the dashboard page from which the CATVidFraGridWindow object
   * has been dettached.
   *
   * @return [CATBaseUnknown#Release] the dashboard page from which the
   * CATVidFraGridWindow object has been dettached.AddRef has been called
   * on it.
   */
  CATVidCtlDashboardPage * GetPreviousDashboardPage() const;

  /**
  * Returns the dashboard page to which the CATVidFraGridWindow object
  * has been attached.
  *
  * @return [CATBaseUnknown#Release] the dashboard page to which the
  * CATVidFraGridWindow object has been attached. AddRef has been called
  * on it.
  */
  CATVidCtlDashboardPage * GetNewDashboardPage() const;

private:
  // Not implemented
  CATVidDashboardPageChangedEventArgs(const CATVidDashboardPageChangedEventArgs&);
  CATVidDashboardPageChangedEventArgs& operator=(const CATVidDashboardPageChangedEventArgs&);

  CATSysWeakRef * _pPreviousDashboardPageWR;
  CATSysWeakRef * _pNewDashboardPageWR;
};

#endif

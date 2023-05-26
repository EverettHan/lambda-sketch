#ifndef CATCmdGhostStarter__H
#define CATCmdGhostStarter__H

#include <CATCmdAccess.h>
#include "CATAfrFoundation.h"
#include "CATString.h"

/**
 * CATCmdGhostStarter is a node of the Afr workbench/workshop model class.
 *
 * This class represents at a workbench level the fact that a CATCmdStarter
 * part of the customization of the global workshop should not be displayed
 * in the UI.
 * So, it's a node in the model that prevents the display of an associated
 * CATCmdStarter customized at the global level.
 */
class ExportedByCATAfrFoundation CATCmdGhostStarter : public CATCmdAccess
{
  CATDeclareClass;

public:
  /** Default constructor */
  CATCmdGhostStarter();
  /**
   * Constructor 
   *
   * @param i_name name of the instance
   * @param i_persistence persistence of the instance
   */
  CATCmdGhostStarter (const CATString & i_name, Persistence i_persistence = Code);
  /**
   * Copy constructor
   *
   * Used by clone member function.
   * @param i_toCopy the instance to copy
   */
  CATCmdGhostStarter (CATCmdGhostStarter & i_toCopy);
  /** Destructor */
  virtual ~CATCmdGhostStarter();

  /**
   * Clone a CATCmdGhostStarter object.
   *
   * @param noNext flag indicating whether or not brother of this object should
   * also be cloned.
   * @param toBeCompleted Not used.
   */
  virtual CATCmdAccess * Clone(int noNext = 0,CATCmdAccess * toBeCompleted = NULL);

  /**
   * Get the command header name of the CATCmdStarter object associated to
   * this CATCmdGhostStarter.
   *
   * @return the name of the command header of the CATCmdStarter object
   * associated to this CATCmdGhostStarter.
   */
  const CATString & GetStarterCommandHeaderName() const;
  /**
   * Set the command header name of the CATCmdStarter object associated to
   * this CATCmdGhostStarter.
   *
   * @param i_starterCommandHeaderName the name of the command header of the
   * CATCmdStarter object associated to this CATCmdGhostStarter.
   */
  void SetStarterCommandHeaderName(const CATString & i_starterCommandHeaderName);

  /**
   * Indicates whether or not the associated CATCmdStarter is local to the
   * workbench.
   *
   * @return 1 if the associated CATCmdStarter is local to the workbench,
   * 0 otherwise.
   */
  int IsStarterLocalToWorkbench() const;
  /**
   * Indicates whether or not the associated CATCmdStarter is local to the
   * workshop.
   *
   * @return 1 if the associated CATCmdStarter is local to the workshop,
   * 0 otherwise.
   */
  int IsStarterLocalToWorkshop() const;
  /**
   * Set the local mode of the associated CATCmdStarter.
   *
   * @param i_starterLocalMode the local mode of the associated CATCmdStarter.
   */
  void SetStarterLocalMode(CATCmdAccess::LocalMode i_starterLocalMode);

  /**
   * Get the persistence of the associated CATCmdStarter object.
   *
   * @return the persistence of the associated CATCmdStarter object.
   */
  CATCmdAccess::Persistence GetStarterPersistence() const;
  /**
   * Set the persistence of the associated CATCmdStarter object.
   *
   * @param i_starterPersistence the persistence of the associated
   * CATCmdStarter object.
   */
  void SetStarterPersistence(CATCmdAccess::Persistence i_starterPersistence);

private:
  // Not implemented
  CATCmdGhostStarter & operator=(const CATCmdGhostStarter &);

  /**
   * Value indicating that the associated CATCmdStarter object is local to the
   * workbench
   */
  static const int StarterLocalToWorkbench;
  /**
   * Value indicating that the associated CATCmdStarter object is local to the
   * workshop
   */
  static const int StarterLocalToWorkshop;

  /** Name of the command header of the associated CATCmdStarter object */
  CATString _starterCommandHeaderName;
  /** Local mode of the associated CATCmdStarter object */
  int _starterLocalMode;
  /** Persistence of the associated CATCmdStarter object */
  CATCmdAccess::Persistence _starterPersistenceMode;

  friend class CATMarshallableCmdGhostStarter;
};

#endif

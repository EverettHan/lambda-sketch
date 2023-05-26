#ifndef CATDlgStyleProcessor_H
#define CATDlgStyleProcessor_H

#include "DialogDeclarativeEngine.h"
#include <CATBaseUnknown.h>
#include <CATSYPStyleProcessor.h>

class CATUnicodeString;
class CATISYPIntrospectable_var;

/**
  * This class encapsulates a Style Processor for Declarative Dialog uses.
  * It gives access to a static instance of Style Processor that can be used
  * to process and generate a sypstyle template.
  * CATDlgStyleProcessor is used during SetStyle in CATDlgDeclarativeManager
  *
  * @see CATDlgDeclarativeManager
  *
  * Please note that this style processor is global. This unique instance can be shared 
  * by all requesters during the session. 
  */

class ExportedByDialogDeclarativeEngine CATDlgStyleProcessor : public CATBaseUnknown
{
  CATDeclareClass ;

public:

  /**
   * Request an instance of the CATDlgStyleProcessor
   */
  static CATDlgStyleProcessor* Instance();

  /**
   * Kill the CATDlgStyleProcessor. Before you call this method,
   * please make sure that CATDlgStyleProcessor won't be used anymore
   * during the session. 
   */
  static void Kill();

  /**
   * Add a sypstyle file to Style Processor's internal model.
   *
   * @param i_path is the path of the sypstyle you want to add. Please note that this path is relative.
   * Please take a look at the AddResources documentation of CATStyleProcessor to know what a relative path is.
   * @see CATStyleProcessor#AddResources
   */
  void AddResources(const CATUnicodeString & i_path);

  /**
   * Generate an instance of a template that was previously added to CATDlgStyleProcessor's internal model
   * with @ref AddResources.
   * @param i_Object is the introspectable object from wich you want to generate an instance. This object must implement
   *        CATISYPTemplate and must be referenced as the template target class of the sypstyle view you want to generate. 
   * @return a CATBaseUnknown_var which will be an instance of the root of the templated view.
   */
  CATBaseUnknown_var Generate(const CATISYPIntrospectable_var & i_Object);

  /**
   * @copydoc CATSYPResourcesFinder#SetPathFolderList
   */
  void SetPathFolderList(const CATUnicodeString& i_pathFolderList);

  /**
   * @copydoc CATSYPResourcesFinder#SetSubDirectoriesPathList
   */
  void SetSubDirectoriesPathList(const CATUnicodeString& i_pathFolderList);

private:

  /**
   * The global CATDlgStyleProcessor. Is accessible through @ref Instance.
   */
  static CATDlgStyleProcessor* _instance;

  /** Constructor. */
  CATDlgStyleProcessor();

  /** Destructor. */
  ~CATDlgStyleProcessor();

  /**
   * The internal instance of CATDlgStyleProcessor. Is not accessible
   * from outside and is used exclusively for this class' internal operations.
   */
  CATSYPStyleProcessor* _sp;

};

#endif

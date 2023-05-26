#ifndef CATSYPEventActionLaunchedArgs_H
#define CATSYPEventActionLaunchedArgs_H

#include <VisuDialogEx.h>
#include "CATSYPEventArgs.h"
#include "CATVidMdlIndex.h"
class CATSYPEvent;

//-----------------------------------------------------------------------------
/**
 * @ingroup groupVIDDnD
 * 
 * Dispatching events of @ref CATVidActionBar#ActionLaunched to the responsible of the command launching.
 * 
 * @see CATVidActionBar#ActionLaunched
 */
class ExportedByVisuDialogEx CATSYPEventActionLaunchedArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initializes this class.
   *
   * @param i_pEvent the dispatched event. Cannot be @c NULL.
   * @param i_index the index of the command in the model.
   */
  CATSYPEventActionLaunchedArgs(CATSYPEvent * i_pEvent, 
    CATVidMdlIndex& i_index);
  /** Destroys this class. */
  virtual ~CATSYPEventActionLaunchedArgs();
  /**
   * @return the index of the item launching a command.
   */
  const CATVidMdlIndex& GetMdlIndex() const{return _mdlIndex;}

private:
  /** Copy constructor. */
  CATSYPEventActionLaunchedArgs (CATSYPEventActionLaunchedArgs &);
  /** Assignment operator. */
  CATSYPEventActionLaunchedArgs& operator=(CATSYPEventActionLaunchedArgs&);

  /** @see #GetMdlIndex */
  CATVidMdlIndex _mdlIndex;
};

//-----------------------------------------------------------------------

#endif

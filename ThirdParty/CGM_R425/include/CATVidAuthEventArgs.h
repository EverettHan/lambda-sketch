//===================================================================
// COPYRIGHT Dassault Systemes 2015-11-16
//===================================================================
// 2015-11-16 Creation: D6K
//===================================================================

#ifndef CATVidAuthEventArgs_H
#define CATVidAuthEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// UIVCoreTools
#include <CATSYPEventArgs.h>

class CATSYPEvent;

/**
 * Dispatching arguments for authentication events.
 * Classic scenario with an embedded web browser:
 *   - In the native client, the user session expires.
 *   - Login panel pops up.
 *   - The user tries to authenticate.
 *   - The event is dispatched.
 */
class ExportedByVisuDialog CATVidAuthEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  CATVidAuthEventArgs(CATSYPEvent*, const bool);
  ~CATVidAuthEventArgs();

  /**
   * Returns true if the authentication succeeded, else returns false.
   */
  bool GetSuccess() const;

private:
  CATVidAuthEventArgs();
  CATVidAuthEventArgs(CATVidAuthEventArgs&);
  CATVidAuthEventArgs& operator=(CATVidAuthEventArgs&);

  const bool _success;
};

#endif

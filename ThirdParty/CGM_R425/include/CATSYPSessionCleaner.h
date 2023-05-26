#ifndef CATSYPSessionCleaner_H
#define CATSYPSessionCleaner_H

#include <UIVCoreTools.h>
#include <CATSYPArray.h>

/** CATSYPSessionCleaner
*   Life cycle management for VID
*/
class ExportedByUIVCoreTools CATSYPSessionCleaner
{
public:
  static bool Initialize();
  static bool IsInitialized();
  static bool IsDestroyed();
private:
  static void RegisterVID(bool (*iFunction)());
  static void RegisterVisu(bool (*iFunction)());
  static void RegisterMultimedia(bool (*iFunction)());
  static int OnExit(int iCode);
private:
  static bool (*_pVidCleanerFunction)();
  static bool (*_pVisuCleanerFunction)();
  static bool (*_pMultimediaCleanerFunction)();
  friend class CATVidSessionCleaner;
  friend class vRELifeCycle;
  friend class CATHeadlessLifeCycle;
};

#endif

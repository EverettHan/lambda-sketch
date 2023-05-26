#ifndef CATJournalMode_h
#define CATJournalMode_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include <CATAfrFoundation.h>
#include <CATCallbackManager.h>

class ExportedByCATAfrFoundation CATJournalMode : public CATCallbackManager
{
  CATDeclareCBEvent(ModeChanged);
  
public:
  
  CATDeclareClass;

  CATJournalMode();
  ~CATJournalMode();
  
  static CATJournalMode * GetJournalMode();
  
  enum Mode { On, Off };
  static void SetMode(Mode);
  static Mode GetMode();
  
  static CATCallbackEvent GetConnection();
  
private:
  
  Mode _mode;
};

#endif

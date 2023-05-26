#ifndef CATVidEventData_H
#define CATVidEventData_H

#include <VisuDialog.h>
#include <CATSYPProperties.h>
#include <CATNotification.h>
#include <CATBoolean.h>
#include "CATMacForRtti.h"
class CATHashDico;
class CATUnicodeString;

class ExportedByVisuDialog CATVidEventData : public CATSYPProperties
{
public:
  CATVidEventData();
  virtual ~CATVidEventData();

  void SetGeneralModifier(int i_generalModifier);

  CATBoolean GetKeyboardShiftFlag () const;
  CATBoolean GetKeyboardCtlFlag () const;

private:
  void *operator new(size_t){return NULL;};
  void operator delete(void *){};

private:
  int   _generalModifier;
};

#endif

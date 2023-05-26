#ifndef CATVidCtlTweakerMagnitude_h
#define CATVidCtlTweakerMagnitude_h

#include <VisuDialogEx.h>
#include <CATVidCtlTweakerdouble.h>
#include <CATUnicodeString.h>
#include <CATICkeParm.h>

class CATCommand;
class CATString;
class CATBaseUnknown_var;
class CATVidWidget;

/**
 */
class ExportedByVisuDialogEx CATVidCtlTweakerMagnitude : public CATVidCtlTweakerdouble
{
  CATDeclareClass;
public:
  static CATVidCtlTweakerMagnitude* BuildTweakerLength();
  static CATVidCtlTweakerMagnitude* BuildTweakerDate();
  static CATVidCtlTweakerMagnitude* BuildTweakerAngle();
  static CATVidCtlTweakerMagnitude* BuildTweakerTime();
  static CATVidCtlTweakerMagnitude* BuildTweakerMass();

  CATVidCtlTweakerMagnitude();

  void SetCkeParm(const CATICkeParm_var& i_spCkeParm);
  const CATICkeParm_var& GetCkeParm() const;
protected:
  virtual ~CATVidCtlTweakerMagnitude();
private:
  CATICkeParm_var _spCkeParm;
};

#endif // CATVidCtlTweakerMagnitude_h

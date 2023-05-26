#include "CATIPGMTopMultiResultImplDeclare.h"

  // ---------- CATTopSweepWireSkin

  virtual void SetShellOrientation(const int iOrientation);

  virtual void SetGuideOrientation(const int iOrientation);

  virtual void GetResultInformation(
    int &ioShellOrientation,
    int &ioWireOrientation,
    int &ioIndex);

/* Already defined in a parent class
  virtual int Run();
*/

  virtual CATSweepProfileInfo *GetProfileInfo();

  virtual void SetModeTrim(const int iMode);

  virtual void SetReconfigFillFunction(CATFilletReconfigFillFunction iFillFct);

  virtual CATFilletReconfigFillFunction GetFilletReconfigFillFunction() const;

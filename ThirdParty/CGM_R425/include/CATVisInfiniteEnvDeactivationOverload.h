// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisInfiniteEnvDeactivationOverload_H
#define CATVisInfiniteEnvDeactivationOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATVisInfiniteEnvironmentOverload.h"

class CATVisInfiniteEnvironmentExtendedData;
class ExportedByCATVisFoundation CATVisInfiniteEnvDeactivationOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvDeactivationOverload* Create();

  void DeactivateGrid();
  void RestoreGridActivation();

  void DeactivatePlane();
  void RestorePlaneActivation();

  void DeactivateLighting();
  void RestoreLightingActivation();

  void DeactivateBackground();
  void RestoreBackgroundActivation();

  void DeactivateAdvancedEffects();
  void RestoreAdvancedEffects();

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;
  virtual void Overload(CATVisAmbiance& ioData) const;
  virtual void Overload(CATVisPostEffects& ioData) const;

private:
  CATVisInfiniteEnvDeactivationOverload();
  virtual ~CATVisInfiniteEnvDeactivationOverload();

  unsigned int _gridDeactivation            : 1;
  unsigned int _planeDeactivation           : 1;
  unsigned int _lightingDeactivation        : 1;
  unsigned int _backgroundDeactivation      : 1;
  unsigned int _advancedEffectsDeactivation : 1;
};

//-----------------------------------------------------------------------

#endif

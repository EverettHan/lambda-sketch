#pragma once

// System&co
#include "CATTolerance.h"
#include "CATSoftwareConfiguration.h"

// PolyhedralBodyOperators
#include "CATPolyBodyRepair.h"
#include "PolyBodyBoolean.h"
#include "CATPolyBodyOverlayOptions.h"

template<>
class ExportedByPolyBodyBoolean CATPolyBodyRepair::Options<CATPolyBodyRepair::Mode::eFromTesselationToBodyReady>
{
public:
  Options(const CATTolerance & iTol);
  Options(const Options & iToCopy);
  ~Options();

  /**
    * Sets the software configuration.
    * AddRef is performed on the set configuration.
    * The life cycle of the set instance should be longer than the life cycle of this instance.
    */
   void SetSoftwareConfiguration(const CATSoftwareConfiguration * iSoftConfig);

  /**
   * Returns the software configuration.
   * Unless an AddRef is performed, the returned instance should not be released.
   */
  const CATSoftwareConfiguration * GetSoftwareConfiguration() const;

  /**
   * Returns the geometric modeler tolerance.
   * Unless an AddRef is performed, the returned instance should not be released.
   */
  const CATTolerance * GetGMTolerance();

  /**
   * Set the SAG information used to tesselate the CATPolyBody.
   * This information ise useful to clean micro volume for instance or too thin elements.
   */
  void SetSAG(double SAG);

  /**
   * Returns the SAG information set.
   */
  double GetSAG() const;

  enum ExpectedResultType
  {
    eOneVolume,
    eAllVolumes,
    eSurfacic
  };
  inline void SetExpectedResultType(ExpectedResultType iMode) { _mode = iMode; };
  inline ExpectedResultType GetExpectedResultType() { return _mode; };

private:
  CATPolyBodyOverlayOptions _overlayOptions;
  ExpectedResultType _mode;
  double _sag;
};

using CATPolyBodyRepairFromTesselationOptions = CATPolyBodyRepair::Options<CATPolyBodyRepair::Mode::eFromTesselationToBodyReady>;


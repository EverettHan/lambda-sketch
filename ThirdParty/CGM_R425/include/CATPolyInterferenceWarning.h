// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceWarning.h
//
//===================================================================
//
// Usage notes:
// Class describing warnings that may occure during interference computation.
//
//===================================================================
//
// Jan 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterferenceWarning_h
#define CATPolyInterferenceWarning_h

#include "CATPolyBoundingVolumeOperators.h"

#include "CATBoolean.h"


/**
 * Class describing warnings that may occure during interference computation.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceWarning
{
public:

  enum WarningType
  {
    NONE,
    INVALID_VOLUMIC_OBJECT,
    UNSTABLE_INTERFERENCE,
    OTHER,
    SURFACIC_OBJECT,
    INTERSECTION_VOLUME_NON_VOLUMIC_OBJECT,
    INTERSECTION_VOLUME_NON_WATERTIGHT_OBJECT,
    INTERSECTION_VOLUME_FAILED
  };

  CATPolyInterferenceWarning(int firstObjectId, WarningType firstWarningType,
                             int secondObjectId, WarningType secondWarningType);
  CATPolyInterferenceWarning(const CATPolyInterferenceWarning & warning);
  ~CATPolyInterferenceWarning();

  /**
   * Get the id of the first object involved in the warning.
   */
  int GetFirstObjectId() const;

  /**
   * Get the id of the second object involved in the warning.
   */
  int GetSecondObjectId() const;

  /**
   * Get the type of warning relative to the first object
   * or NONE if only the other object has flaws.
   */
  WarningType GetFirstObjectWarning() const;

  /**
   * Get the type of warning relative to the second object
   * or NONE if only the other object has flaws.
   */
  WarningType GetSecondObjectWarning() const;

  /**
   * Compare two warnings.
   */
  CATBoolean operator==(const CATPolyInterferenceWarning & other) const;


private:

  int _iFirstObjectId;
  int _iSecondObjectId;
  WarningType _eFirstWarningType;
  WarningType _eSecondWarningType;
};

#endif // CATIPolyInterferenceWarning_h


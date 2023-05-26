//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//==============================================================================================================

// CATVRepType : type of VRep (octree + corner client data including a distance field)

//==============================================================================================================
// Creation : CHU/DPS , march / 2006 
//==============================================================================================================

#ifndef CATVRepType_H
#define CATVRepType_H

#include "VRepGen.h"             // ExportedBy
#include "CATErrorDef.h"         // HRESULT definition
#include "CATIAV5Level.h"        // CATIA V5

class CATCGMOutput;

class ExportedByVRepGen CATVRepType
{

public :

  static CATVRepType _UnsetVRepType;

  // Bit-field description :
  unsigned int _Invalid          : 1; // 0=normal type, 1="unset" type, not qualifying to build a vrep
  unsigned int _DistanceInDouble : 1; // 0=float 1=double
  unsigned int _Signed           : 1; // 0=unsigned, 1=signed
  unsigned int _Squared          : 1; // 0=not squared, 1=square distances (and signed, as stated by _SignedDistance)
  unsigned int _CompactedGradientNumberOfBytes : 4; // 0 if no gradient, else 4 to 8 (4 = int, 8 = vector in float)
  unsigned int _EnableUndefinedSign : 1 ; // 1=compact the distance in 31 bits to reserve "bit 0" in case of undefined sign
  unsigned int _SmoothingMode : 2; // 0=none, 1=metaball, 2=soft union
  unsigned int _BooleanMode : 2; // 0=none, 1=limit, 2=union
  unsigned int _WrappingSmoothnessMode : 1; // 0=none, 1=wrapping without smoothness mode
  unsigned int _DualContouringMode : 1; // 0=custom, 1 = strict default (historic) value, 2 = coarse (more tolerant to distance fluctuations)
  unsigned int _ScalarFieldMode : 1; // 0=none, 1=VRep generated from a scalarField (not a distance field)
  unsigned int _FreeArea         :17; // 0

  enum SmoothingMode {
    NONE = 0,
    METABALL = 1,
#ifdef CATIAR420
    SOFT_UNION = 2,
    GAUSSIAN = 3,
    GAUSSIAN_ISO_VOLUME = 4
#else
    SOFT_UNION = 2
#endif // CATIAR420
  };

  enum BooleanMode {
    WITHOUT = 0,
    LIMIT = 1,
    UNION = 2
  };

  enum WrappingSmoothnessMode {
    NOWRAPPING = 0,
    WITHOUTSMOOTHNESS = 1
  };

  enum ScalarFieldMode {
    NOSCALARFIELD = 0,
    WITHSCALARFIELD = 1
  };

  float _SmoothingAmpl;

  enum DualContouringMode {
    CUSTOMDISTANCECHECK = 0,
    STRICTDISTANCECHECK = 1,
    COARSEDISTANCECHECK = 2
  };

  volatile static const double _strictDistanceTreshold; // = 1.1;
  volatile static const double _coarseDistanceTreshold; // = 1.9;

  // Factory (one creation method per sub-class of CATPolyVoxelClient)
  // Note : gradient types are as follows:
  //  1 = two float (vector's X and Y, Z being inferred by X*X+Y*Y+Z*Z=1)
  //  2 = two float (latitude [-pi/2,pi/2] and longitude [0,2pi] of vector
  //  3 = two double (vector's X and Y, Z being inferred by X*X+Y*Y+Z*Z=1)
  static CATVRepType UnsetType();
  static CATVRepType TypeOfCATPolyDistanceField(int iIsSquared, int iIsSigned, int iIsUndefinedSignEnabled);
  static CATVRepType TypeOfCATPolyGradientField(int iIsSquared, int iIsSigned, int iIsUndefinedSignEnabled, int iGradientType);
  static CATVRepType TypeOfCATPolyScalarField(int iIsSquared, int iIsSigned, int iIsUndefinedSignEnabled);

  // Check if a VRep bearing "this" as type has corner clients that are castable to a specific class
  int CastableToCATPolyDistanceField() const;
  int CastableToCATPolyGradientField() const;

  unsigned int GetUnsignedIntCompilData(int * iVersionNum=0);
  void SetUnsignedIntCompilData(unsigned int iCompilData, int * iVersionNum=0);

  // Dump
  HRESULT Dump( CATCGMOutput & s) const;

};

#ifdef CATIAR420
#ifdef _MOBILE_SOURCE

class LatticeNBModel
{
public:
    LatticeNBModel() {}
    ~LatticeNBModel() {}
};
#endif
#endif

#endif

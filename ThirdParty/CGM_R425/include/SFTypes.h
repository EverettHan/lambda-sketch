#ifndef SFTypes_h
#define SFTypes_h

#include "ScalarFields.h"
#include "ScalarFieldUtils.h"

// System
#include "IUnknown.h"

#include <stdio.h>
#include <string.h>

// Mathematics
#include "CATMathPoint.h"

// STD
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <istream>
#include <limits>
#include <chrono>
#include <algorithm>

// ScalarFields
#include "EnableVRep.h"
#include "EnableGradient.h"
#include "ScalarFieldUtils.h"
#include "SFEvaluationContext.h"

class CATImplicitExpressionBuilder;
struct ExprHandleHashFct;
struct ExprHandleEqualFct;

namespace SF
{

#undef max
#undef min

  using namespace std::chrono;

  using SFTimeStamp = steady_clock::time_point;

  struct ScalarGrid {
    double              voxelSize, offset;
    double              xmin, xmax, ymin, ymax, zmin, zmax;
    double              origin[3];
    unsigned int        udim[3];
    int                 dim[3];
    std::vector<float>  scalarField;
  };

  typedef std::shared_ptr<ScalarGrid> ScalarGridPtr;

  class SFDomain {
  public:
    SFDomain() : _grid(nullptr)
    {}

    SFDomain(ScalarGrid* iGrid) : _grid(iGrid)
    {}

    SFDomain(const SFDomain* iOther) : _grid(iOther->_grid)
    {}

    const double GetVoxelSize() const { return (_grid.get()!=nullptr) ? _grid->voxelSize : 0.0; }
    const double GetOffset() const { return (_grid.get() != nullptr) ? _grid->offset : 0.0; }

    const double GetXMin() const { return (_grid.get() != nullptr) ? _grid->xmin : 0.0; }
    const double GetXMax() const { return (_grid.get() != nullptr) ? _grid->xmax : 0.0; }
    const double GetYMin() const { return (_grid.get() != nullptr) ? _grid->ymin : 0.0; }
    const double GetYMax() const { return (_grid.get() != nullptr) ? _grid->ymax : 0.0; }
    const double GetZMin() const { return (_grid.get() != nullptr) ? _grid->zmin : 0.0; }
    const double GetZMax() const { return (_grid.get() != nullptr) ? _grid->zmax : 0.0; }

    const double GetOriginX() const { return (_grid.get() != nullptr) ? _grid->origin[0] : 0.0; }
    const double GetOriginY() const { return (_grid.get() != nullptr) ? _grid->origin[1] : 0.0; }
    const double GetOriginZ() const { return (_grid.get() != nullptr) ? _grid->origin[2] : 0.0; }

    const unsigned int GetUDimX() const { return (_grid.get() != nullptr) ? _grid->udim[0] : 0; }
    const unsigned int GetUDimY() const { return (_grid.get() != nullptr) ? _grid->udim[1] : 0; }
    const unsigned int GetUDimZ() const { return (_grid.get() != nullptr) ? _grid->udim[2] : 0; }

    const int GetDimX() const { return (_grid.get() != nullptr) ? _grid->dim[0] : 0; }
    const int GetDimY() const { return (_grid.get() != nullptr) ? _grid->dim[1] : 0; }
    const int GetDimZ() const { return (_grid.get() != nullptr) ? _grid->dim[2] : 0; }
  protected:
    ScalarGridPtr _grid;
  };

  typedef std::shared_ptr<SFDomain> SFDomainPtr;

  /**
  * Discretization accuracy has a huge impact on performances thus
  * most of the time you might want to generate things with the
  * coarsest level compatible with your usage.
  * As for discretization of poly body we use sag values as specified
  * in the CATTolerance but we also want to be able to specify
  * based on context that we want to use coarse, optimized or fine mode.
  *
  * This enum should mimic the values in CATGMTessAccuracyLevel even
  * though it means a different things they are tightly related when we discretized
  * a scalar field which involve existing geometries via their polyhedral representation.
  */
  enum ExportedByScalarFields CATGMSFDiscretizationAccuracyLevel {
    FineDiscretizationAccuracy = 0,
    OptimizedDiscretizationAccuracy = 1,
    CoarseDiscretizationAccuracy = 2,
    FixedGrid64 = 3,
    FixedGrid128 = 4,
    FixedGrid256 = 5,
    FixedGrid512 = 6,
    TreeDepthForcedViaEnvVar = 7,
    OldLatticeAPI = 8
  };

/**
 * This is just to make a distinctions between node types of
 * different semantic levels. Don't comment out these defines
 * when you want to restrict the semantic level used in a program
 * this is done dynamically via the SFSWContext object and all classes
 * that should have different behaviors based on semantic level need to 
 * be SFContextedObject. 
 */
#define V1NODETYPES
#define V2NODETYPES

  /**
   * Defines the basic node types known at ScalarFields level.
   * IT DOES NOT INCLUDE RESOURCE TYPES AS THESE ARE MEANT TO BE DEALT
   * BY HIGHER LEVEL FW. SO ALL RESOURCES EXCEPT SPECIFIC ONES DEFINED
   * IN SCALARFIELDS SHOULD BE TAGGED AS RESOLVEDREF/UNRESOLVEDREF.
   *
   * PLEASE REFRAIN TO THE TEMPTATION TO ADD SPECIFIC TYPE FOR THESE :).
   * 
   * !!WARNING!! POLY and POLYGRADIENT are there for legacy reasons
   * but you should not have to use them anymore for new developments
   * you should be able to rely completely on UNRESOLVEDREF, RESOLVEDREF
   * and REFGRADIENT.
   */
  enum class SFNodeType {
#ifdef V1NODETYPES
    UNDEF, END, X, Y, Z, SCALAR, POLY,
#ifdef ENABLE_GRADIENT
    POLYGRADIENT,
#endif // ENABLE_GRADIENT
    PLUS, SQUARE, MINUS, MULT, MIN, MAX, NOT, COS, SIN, ROOT,
    DIV, ABS, EXP, LN, POW, SYMDIFF, WITHOUT, ACOS, ASIN, TAN, ATAN,
    SIGN, UNRESOLVEDREF, RESOLVEDREF, DELETED,
#ifdef V2NODETYPES
    VAR, AFFINETRANSFORM, BLEND, DISCRETETRANSFORM,
    CYLINDRICALTRANSFORM, GCGUIDEDTRANSFORM,
    OFFSET, FUNCTOR, REFGRADIENT
#endif // V2NODETYPES
#endif // V1NODETYPES
  };

  enum class SFOperand { LHS, RHS };

  typedef std::string                   SFString;
  typedef std::vector<SFString>         SFStrings;
  typedef SFString                      SFExpression;
  typedef std::vector<SFExpression>     SFExpressions;

  // Number of decimals in stream
  // If you need more use operations in the graph
  // to achieve it.
  const int SFScalarPrecisionInExpression = 6; 

  /**
   * From C++ standard, std::locale("C") should ensure that we stick
   * to default C locale/convention, which is US. It is an invariant independent
   * from global settings. And sometime
   * it is precisely what we want.
   */
  template<typename T>
  HRESULT ToSFString(const T& iT, SFString& oTAsString) {
    HRESULT hr = E_FAIL;

    std::ostringstream valueAsOStringStream;
    valueAsOStringStream.imbue(std::locale::classic());
    valueAsOStringStream.precision(SFScalarPrecisionInExpression);
    valueAsOStringStream << iT;

    SFString valueAsSFString(valueAsOStringStream.str());

    // Some basic checks, in case someone broke the STL
    // std::locale::classic().
    CHECK_CONDITION(SFString::npos == valueAsSFString.find(" "));
    CHECK_CONDITION(SFString::npos == valueAsSFString.find(","));

    oTAsString = valueAsSFString;
    hr = S_OK;
    return hr;
  }

  /**
   * From C++ standard, std::locale("C") should ensure that we stick
   * to default C convention, which are US. This method
   * is the symmetric of TOSFString.
   * 
   * WARNING !! This is not a generic stod replacement it is specific
   * to how we do format our strings for ScalarFields.
   */
  SFINLINE double DoubleFromSFString(const SFString& iString, size_t& oOffset) {

    double doubleValue = 0.0;
    // Some time this function might be called with string coming from GUI
    // or elsewhere so let's do a little check and repair first just in case
    // someone submitted a string with a different numeric separator.
    // If someone also insert spaces we have a problem but let's do our best.
    size_t startAt = 0;
    size_t spaceAt = iString.find(" ");
    while (spaceAt == startAt && spaceAt < iString.length()) {
      startAt += 1;
      spaceAt = iString.find(" ", startAt);
    }
    if(SFString::npos!=spaceAt && spaceAt!=iString.length()) {
      size_t comaAt = iString.find(",");
      if(comaAt<spaceAt) {
        std::string toInsert = iString.substr(0, spaceAt);
        std::replace(toInsert.begin(), toInsert.end(), ',', '.');
        std::string toModify(iString);
        toModify.replace(0, spaceAt, toInsert);
        std::stringstream stringAsStringStream(toModify);
        stringAsStringStream.imbue(std::locale::classic());
        stringAsStringStream.precision(SFScalarPrecisionInExpression);
        stringAsStringStream >> doubleValue;

        if (stringAsStringStream.fail() || stringAsStringStream.bad()) {
          oOffset = 0;
        }
        else {
          oOffset = spaceAt;
        }

        return doubleValue;
      }
      else {
        std::stringstream stringAsStringStream(iString);
        stringAsStringStream.imbue(std::locale::classic());
        stringAsStringStream.precision(SFScalarPrecisionInExpression);
        stringAsStringStream >> doubleValue;

        if (stringAsStringStream.fail() || stringAsStringStream.bad()) {
          oOffset = 0;
        }
        else {
          oOffset = spaceAt;
        }

        return doubleValue;
      }
    }

    std::stringstream stringAsStringStream(iString);
    stringAsStringStream.imbue(std::locale::classic());
    stringAsStringStream.precision(SFScalarPrecisionInExpression);
    stringAsStringStream >> doubleValue;

    if (stringAsStringStream.fail() || stringAsStringStream.bad() || !stringAsStringStream.eof()) {
      oOffset = 0;
    } else {
      oOffset = iString.length();
    }

    return doubleValue;
  }

  const int SFDAGLeftBranch = 0;
  const int SFDAGRightBranch = 1;

  class ExportedByScalarFields SFExpressionPath : public std::vector<int>
  {
  public:
    typedef std::unique_ptr<SFExpressionPath>            UPtr;
    typedef std::shared_ptr<SFExpressionPath>            Ptr;
    typedef std::vector<SFExpressionPath::Ptr>           Ptrs;
    typedef std::map<std::string, SFExpressionPath::Ptr> Map;

    bool IsEmpty() {
      return (size()==0) ? true : false;
    }

    static SFExpressionPath GetEmpty() {
      SFExpressionPath empty;
      return empty;
    }
  };

  SFINLINE const char* SFExpressionAsCharPtr(const SFExpression& iExpr) {
    return iExpr.c_str();
  }

  class ExportedByScalarFields  SFExpressionPaths : public std::vector<SFExpressionPath>
  {
  public:
    virtual ~SFExpressionPaths();
  protected:
  };

  typedef double SFScalar;

  struct SFGradient
  {
	  SFGradient() : _IsInit(0), _DistanceVal(0.0) {
	    _GradientVal[0] = 0.0; _GradientVal[1] = 0.0; _GradientVal[2] = 0.0;
	  }
	  void SetValue(const double iDistanceVal, const double (&iGradientVal)[3]) {
	    _IsInit = 1; _DistanceVal = iDistanceVal;
	    _GradientVal[0] = iGradientVal[0]; _GradientVal[1] = iGradientVal[1]; _GradientVal[2] = iGradientVal[2];
	  }

	  int _IsInit;
	  double _DistanceVal;
	  double _GradientVal[3];
  };

  SFINLINE SFScalar GetSFMaxScalar() {
    return  std::numeric_limits<double>::max();
  }

  typedef double SFReal;
  typedef int    SFNodeRank;

  SFINLINE int GUIDCmp(const GUID iGuid0, const GUID iGuid1)
  {
      return memcmp(&iGuid0, &iGuid1, sizeof(GUID));
  }

  SFINLINE int GUIDEqual(const GUID iGuid0, const GUID iGuid1)
  {
    return (GUIDCmp(iGuid0, iGuid1)==0) ? true : false;
  }

  // {F3224954-7EAA-4BC6-9D4A-D1EC211F4645}
  static const GUID NotAValidTypeGUID =
  { 0xf3224954, 0x7eaa, 0x4bc6, { 0x9d, 0x4a, 0xd1, 0xec, 0x21, 0x1f, 0x46, 0x45 } };

  template <typename T>
  T NAT() {
    // Force Specialization
  }

  template <>
  SFINLINE SFScalar NAT() { return GetSFMaxScalar(); }

  template <typename T>
  class SFTypeInfo
  {
  public:
    static const GUID& GetTypeGUID()
    {
      // Force Specialization
    }

    static const T& NAT() {
      // Force Specialization
    }
  };

  // {A68488F3-4856-4ea7-A3AA-6AD6D118CB72}
  static const GUID UndefinedGUID =
  { 0xa68488f3, 0x4856, 0x4ea7, { 0xa3, 0xaa, 0x6a, 0xd6, 0xd1, 0x18, 0xcb, 0x72 } };

  template<typename T>
  const IID GetIID(const T& iT) {
    // GetGuid should be specialized per types.
    return UndefinedGUID;
  }

  template<typename T>
  const IID GetIID(const T* iT) {
    // GetGuid should be specialized per types.
    return UndefinedGUID;
  }

  template <typename T>
  class SFInterfaceInfo
  {
  public:
    static const IID& GetIID()
    {
      // Force Specialization
    }
  };

  template <typename T>
  class SFTypeUtils
  {
  public:
    static const bool Equal(const T& iT0, const T& iT1) {
      // Force Specialization
    }

    static const bool IsValid(const T& iT) {
      // Force Specialization
    }
  };

  template <>
  class SFTypeUtils<SFScalar>
  {
    static const bool Equal(const SFScalar& iT0, const SFScalar& iT1) {
      return iT0 == iT1;
    }

    static const bool IsValid(const SFScalar& iT) {
      return (!SFTypeUtils<SFScalar>::Equal(iT, GetSFMaxScalar())) ? true : false;
    }
  };

  class ExportedByScalarFields SFExpressionNodeHandle
  {
    friend class ::CATImplicitExpressionBuilder;
    friend struct ::ExprHandleHashFct;
    friend struct ::ExprHandleEqualFct;

    public:

    bool IsNull() {
      return (_handler==nullptr || _nodeQuery ==nullptr || _ctrl==0 ) ? true : false;
    }

    static SFExpressionNodeHandle GetEmpty();

    SFExpressionNodeHandle();
    SFExpressionNodeHandle(void* iHandler, void* iNode, int ctrl);
    SFExpressionNodeHandle(const SFExpressionNodeHandle& iOther);

    SFINLINE void* GetHandler()
    {
      return _handler;
    }

    SFINLINE void* GetNodeQuery()
		{
			return _nodeQuery;
		}

		SFINLINE int GetCtr()
		{
			return _ctrl;
		}


    private:

    void*       _handler;
    void*       _nodeQuery;
    int         _ctrl;
  };

  // {00000000-0000-0000-0000-000000000000}
  static const GUID NAGUID =
  { 0x00000000, 0x0000, 0x0000, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };

  // {BE4F5832-3F83-41f4-B063-D27D3C79F0B9}
  static const GUID UndefinedResourceTypeGUID =
  { 0xbe4f5832, 0x3f83, 0x41f4, { 0xb0, 0x63, 0xd2, 0x7d, 0x3c, 0x79, 0xf0, 0xb9 } };
};

#endif // SFTypes_h

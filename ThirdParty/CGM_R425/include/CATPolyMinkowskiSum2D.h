// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMinkowskiSum2D
//
// Compute the Minkowski sum between two CATPolyPolygon2D
// Minkowski difference can be computed by setting a CATMathTransformation2D : (-1  0) on the second polygon
//                                                                             (0  -1)
//
// Input polygons must have several non connected faces, holes, wires and free vertices.
// But they must not have any self-intersections : their elements (bars and vertices) must form a simplicial complex.
//===================================================================
#ifndef CATPolyMinkowskiSum2D_H
#define CATPolyMinkowskiSum2D_H

#include "PolygonalBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATPolyPolygonOverlayOptions2D.h"

#include "CATExpInterval.h"
#include "CATExpFloatRingExtensionTS.h"

#include <memory>
#include <utility>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <optional>

class CATPolyPolygon2D;
class CATPolyPolygonWNBuilder2D;
class CATMathPoint2D;
class CATMathTransformation2D;
class CATPolyLoop2D;
class CATPolyBar2D;
class CATPolyVertex2D;
class CATPolyFace2D;
class CATPolyWire2D;
class CATMathBox2D;
class CATPolyMinkowskiSumObserver2D;

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)
#define CATPolyMinkowskiSum2D_NoDiscard [[nodiscard]]
#else
#define CATPolyMinkowskiSum2D_NoDiscard
#endif

class CATPolyMinkowskiSum2D final
{

public:
  ExportedByPolygonalBoolean CATPolyMinkowskiSum2D(CATPolyPolygonOverlayOptions2D const& iOptions);
  CATPolyMinkowskiSum2D(CATPolyMinkowskiSum2D const&) = delete;
  CATPolyMinkowskiSum2D& operator=(CATPolyMinkowskiSum2D const&) = delete;
  CATPolyMinkowskiSum2D(CATPolyMinkowskiSum2D &&) = default;
  CATPolyMinkowskiSum2D& operator=(CATPolyMinkowskiSum2D &&) = default;
  ExportedByPolygonalBoolean ~CATPolyMinkowskiSum2D ();

  /**
   * Sets the working polygon for the operator.
   * This polygon is edited by the operator.
   */
  void Set(CATPolyPolygon2D& ioResult);

  /**
   * Sets the working polygon operands for the operator.
   */
  void SetFirstOperand(CATPolyPolygon2D const& iOperand, CATMathTransformation2D const *ipTransformation = nullptr);
  void SetSecondOperand(CATPolyPolygon2D const &iOperand, CATMathTransformation2D const* ipTransformation = nullptr);

  /*
   * When open mode is active (default false), the operator compute the minkowski sum considering
   * that polygons are open sets instead of closed sets.
   */
  void SetOpenMode(bool iOpen);
  CATPolyMinkowskiSum2D_NoDiscard bool IsOpenMode() const;

  /**
   * Performs the Minkowski operation :
   * _pTransformation1 * FirstOperand + _pTransformation2 * SecondOperand
   * 
   * @return
   *   The method returns S_OK when it runs successfully and E_FAIL otherwise.
   */
  ExportedByPolygonalBoolean CATPolyMinkowskiSum2D_NoDiscard HRESULT Run ();

  /**
   * Compute the bounding box of
   * _pTransformation1 * FirstOperand + _pTransformation2 * SecondOperand
   *
   * @return
   *   The method returns the bounding box of the Minkowski sum.
   */
  ExportedByPolygonalBoolean static CATMathBox2D ComputeBox(CATPolyPolygon2D const &iFirstOperand, CATMathTransformation2D const *ipFirstOperandTransformation,
    CATPolyPolygon2D const& iSecondOperand, CATMathTransformation2D const* ipSecondOperandTransformation);

  /**
    * Compute the Minkowski sum of ipTransformation * iPolygon and a tesselation a circle of radius iOffset
    *
    * @return
    *   The method returns the offset of the polygon.
    */
  ExportedByPolygonalBoolean static CATPolyMinkowskiSum2D_NoDiscard std::unique_ptr<CATPolyPolygon2D> CreateOffset(
    CATPolyPolygon2D const& iPolygon, CATMathTransformation2D const* ipTransformation, CATPolyPolygonOverlayOptions2D const& iOptions, double iOffset, double iSag);

  void SetObserver(CATPolyMinkowskiSumObserver2D* ipObserver);

  void SetSimplify(bool iActive);

private:
  CATPolyMinkowskiSum2D_NoDiscard HRESULT ComputeSkippedHoles();
  CATPolyMinkowskiSum2D_NoDiscard HRESULT Process();
  CATPolyMinkowskiSum2D_NoDiscard HRESULT Process(CATPolyLoop2D const&iLoop1);
  CATPolyMinkowskiSum2D_NoDiscard HRESULT Process(CATPolyWire2D const&iWire1);
  CATPolyMinkowskiSum2D_NoDiscard HRESULT ProcessVertices(int iOperand1);
  CATPolyMinkowskiSum2D_NoDiscard HRESULT Process(int iOperand1, CATPolyVertex2D const& iVertex1);
  template<class Element1, class Element2>
  CATPolyMinkowskiSum2D_NoDiscard HRESULT Process(int iOperand1, Element1 const& iE1, Element2 const& iE2);
  CATPolyMinkowskiSum2D_NoDiscard HRESULT SimplifyResult();

  CATPolyMinkowskiSum2D_NoDiscard CATPolyVertex2D* AddVertex(int iOperand1, CATPolyVertex2D const& iVertex1, CATPolyVertex2D const& iVertex2);
  CATPolyMinkowskiSum2D_NoDiscard HRESULT CreateMSBar(int iOperand1, CATPolyVertex2D const& iVertex, CATPolyBar2D const& iBar, int iMultiplicity, bool iConvexVertex);
  CATPolyMinkowskiSum2D_NoDiscard HRESULT CreateWNBar(int iOperand1, CATPolyVertex2D const& iVertex, CATPolyVertex2D const& iStartVertex, CATPolyVertex2D const& iEndVertex, int iMultiplicity);

  CATPolyMinkowskiSum2D_NoDiscard std::pair<int, std::optional<CATMathPoint2D>> GetSymbolicPerturbation(CATPolyVertex2D const& iVertex) const;
  CATPolyMinkowskiSum2D_NoDiscard std::tuple<int, std::optional<CATMathPoint2D>, int, std::optional<CATMathPoint2D>> GetSymbolicPerturbation(CATPolyBar2D const& iBar) const;
  CATPolyMinkowskiSum2D_NoDiscard bool IsLowerArea(int iOperand1, CATPolyLoop2D const& iLoop1, CATPolyLoop2D const& iLoop2);
  CATPolyMinkowskiSum2D_NoDiscard HRESULT IsSkipped(int iOperand1, CATPolyLoop2D const& iLoop1, CATPolyLoop2D const& iLoop2);
  std::pair<CATMathTransformation2D const*, CATMathTransformation2D const*> GetTransformations(int iOperand1) const;
  template<class Element>
  CATPolyMinkowskiSum2D_NoDiscard static std::vector<std::pair<CATPolyBar2D const*, bool>> CreateSortedBars(Element const& iE, CATMathTransformation2D const* ipT);
  CATPolyMinkowskiSum2D_NoDiscard std::vector<std::pair<CATPolyBar2D const*, bool>> const& GetSortedBars(int iOperand, CATPolyLoop2D const& iLoop);
  CATPolyMinkowskiSum2D_NoDiscard std::vector<std::pair<CATPolyBar2D const*, bool>> const& GetSortedBars(int iOperand, CATPolyWire2D const& iWire);
  CATPolyMinkowskiSum2D_NoDiscard static std::vector<bool> CreateConvexVertices(CATPolyLoop2D const& iLoop, CATMathTransformation2D const* ipT);
  CATPolyMinkowskiSum2D_NoDiscard std::vector<bool> const& GetConvexVertices(int iOperand, CATPolyLoop2D const& iLoop);

  class WindingRule;
  friend class CATPolyMinkowskiSum2D::WindingRule;

  class OpenCompare;
  friend class CATPolyMinkowskiSum2D::OpenCompare;

  class OpenCloseCompare;
  friend class CATPolyMinkowskiSum2D::OpenCloseCompare;

  class CATPolyMinkowskiSumPolygonObserver2D;

  struct HashPair final
  {
    template<class T, class U>
    std::size_t operator()(std::pair<T, U> const& iPair) const;
  };

  struct LoopData
  {
    CATExpInterval _intervalArea;
    CATExpFloatRingExtensionTS _bigIntegerArea;
    std::vector<std::pair<CATPolyBar2D const*, bool>> _sortedBars;
    std::vector<bool> _convexVertices;
  };

  CATPolyPolygonOverlayOptions2D _options;
  CATPolyPolygon2D const* _pPolygon1 = nullptr;
  CATMathTransformation2D const* _pTransformation1 = nullptr;
  CATPolyPolygon2D const* _pPolygon2 = nullptr;
  CATMathTransformation2D const* _pTransformation2 = nullptr;
  CATPolyMinkowskiSumObserver2D* _pObserver = nullptr;
  bool _open = false;
  bool _simplify = true;
  CATPolyPolygon2D* _pResult = nullptr;
  std::unique_ptr<CATPolyPolygonWNBuilder2D> _pWNBuilder;
  std::unique_ptr<CATPolyMinkowskiSumPolygonObserver2D> _pPolygonObserver;
  std::unordered_map<std::pair<CATPolyVertex2D const*, CATPolyVertex2D const*>, CATPolyVertex2D*, HashPair> _mWNBuilderSumVertices;
  std::unordered_map<std::pair<CATPolyVertex2D const*, CATPolyVertex2D const*>, CATPolyVertex2D*, HashPair> _mWNPolygonSumVertices;
  std::unordered_multimap<CATPolyVertex2D const*, CATPolyBar2D*> _mVertexBars;
  std::unordered_map<CATPolyVertex2D const*, std::optional<CATMathPoint2D>> _symbolicPerturbations;
  std::unordered_map<CATPolyLoop2D const*, LoopData> _mLoopData[2];
  std::unordered_map<CATPolyWire2D const*, std::vector<std::pair<CATPolyBar2D const*, bool>>> _mWireData[2];
  std::unique_ptr<CATPolyPolygon2D> _pWNPolygon;
};

class CATPolyMinkowskiSumObserver2D
{
public:
  virtual ~CATPolyMinkowskiSumObserver2D() = default;

  /*
   * Observer is called after creation of a sum vertex ioSumVertex = iVertex1 + iVertex2
   * @param iVertex1     Vertex of the first operand
   * @param iVertex2     Vertex of the second operand
   * @param ioSumVertex  Created sum vertex
   */
  virtual void ReactToAddVertex(CATPolyVertex2D const& iVertex1, CATPolyVertex2D const& iVertex2, CATPolyVertex2D& ioSumVertex) = 0;

  /*
   * Observer is called after creation of a sum bar ioSumBar = iVertex + iBar
   * @param iVertexOperand  0 (resp 1) if vertex belongs to first (resp second) operand
   * @param iVertex         Vertex of iVertexOperand operand
   * @param iBar            Bar of the (1 - iVertexOperand) operand
   * @param ioSumBar        Created sum bar
   */
  virtual void ReactToAddBar(int iVertexOperand, CATPolyVertex2D const& iVertex, CATPolyBar2D const& iBar, CATPolyBar2D& ioSumBar) = 0;
};

inline void CATPolyMinkowskiSum2D::Set(CATPolyPolygon2D& ioResult)
{
  _pResult = &ioResult;
}

inline void CATPolyMinkowskiSum2D::SetFirstOperand(CATPolyPolygon2D const& iOperand, CATMathTransformation2D const* ipTransformation)
{
  _pPolygon1 = &iOperand;
  _pTransformation1 = ipTransformation;
}

inline void CATPolyMinkowskiSum2D::SetSecondOperand(CATPolyPolygon2D const& iOperand, CATMathTransformation2D const* ipTransformation)
{
  _pPolygon2 = &iOperand;
  _pTransformation2 = ipTransformation;
}

inline void CATPolyMinkowskiSum2D::SetOpenMode(bool iOpen)
{
  _open = iOpen;
}

inline bool CATPolyMinkowskiSum2D::IsOpenMode() const
{
  return _open;
}

inline void CATPolyMinkowskiSum2D::SetObserver(CATPolyMinkowskiSumObserver2D* ipObserver)
{
  _pObserver = ipObserver;
}

inline void CATPolyMinkowskiSum2D::SetSimplify(bool iActive)
{
  _simplify = iActive;
}

#endif

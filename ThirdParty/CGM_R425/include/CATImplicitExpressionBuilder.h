#ifndef CATImplicitExpressionBuilder_H
#define CATImplicitExpressionBuilder_H

#include "GMScalarFieldsOperators.h"

// System
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

// Scalar Fields
#include "SFTypes.h"
#include "SFContextedObject.h"

// GM Scalar Fields
#include "CATSFDagNodeQuery.h"
#include "CATImplicitExpressionQuery.h"

// STD
#include <functional>
#include <unordered_map>

class CATBody;
class CATFace;
class CATShell;
class CATVolume;
class CATWire;

namespace SF {
  class SFResourceResolver;
};

/**
 * unordered_map used in the CATImplicitExpressionBuilder. We need to define a hash function
 * (and one for equality) for the unordered_set. ExprHandleHashFct is used for that.
 */
struct ExportedByGMScalarFieldsOperators ExprHandleHashFct {
  size_t operator()(SF::SFExpressionNodeHandle iExprNodeHandle) const {
    CATSFDagNodeQuery* query = static_cast<CATSFDagNodeQuery*>(iExprNodeHandle.GetNodeQuery());
    return CATSFDagNodeQueryRawPtrHashFct{}(query);
  }
};

/**
  * unordered_map used in the CATImplicitExpressionBuilder.
  */
struct ExportedByGMScalarFieldsOperators ExprHandleEqualFct {
  bool operator ()(SF::SFExpressionNodeHandle iExprNodeHandle1, SF::SFExpressionNodeHandle iExprNodeHandle2) const {
    CATSFDagNodeQuery* query1 = static_cast<CATSFDagNodeQuery*>(iExprNodeHandle1.GetNodeQuery());
    CATSFDagNodeQuery* query2 = static_cast<CATSFDagNodeQuery*>(iExprNodeHandle2.GetNodeQuery());
    return CATSFDagNodeQueryRawPtrEqualFct{}(query1, query2);
  }
};

typedef std::unordered_map < SF::SFExpressionNodeHandle, CATSFDagNodeQuery::Ptr, 
    ExprHandleHashFct, ExprHandleEqualFct> CATImplicitHandleMap;

typedef std::unordered_map<SF::SFString, SF::SFExpressionNodeHandle> CATImplicitRefMap;

class ExportedByGMScalarFieldsOperators CATImplicitExpressionBuilder : public SF::SFContextedObject
{

public:
  CATImplicitExpressionBuilder(const SF::SFSWContext& iCtx);
  virtual ~CATImplicitExpressionBuilder();

  SF::SFExpressionNodeHandle  CreateAffineTransform(const double* iMat44, const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateBlend(const double iBlendStrength, const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateDiscreteTransform(const SF::SFExpressionNodeHandle iSrcTetMeshH, const SF::SFExpressionNodeHandle iDstTetMeshH, const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateCylindricalTransform(const CATMathPoint& iOrigin, const CATMathVector& iAxis, const double iRefPeriodicity, const SF::SFExpressionNodeHandle iLHS);
  //SF::SFExpressionNodeHandle  CreateGCGuidedTransform(const int iCrossSectionCount, SF::CrossSections& iCrossSections, const SF::SFExpressionNodeHandle iLHS);

  SF::SFExpressionNodeHandle  CreateScalar(const SF::SFScalar iScalarValue);
  SF::SFExpressionNodeHandle  CreateOffset(const SF::SFScalar iScalarValue);
  SF::SFExpressionNodeHandle  CreateParameter(const SF::SFString& iName, const SF::SFScalar iDefaultValue);

  SF::SFExpressionNodeHandle  CreateX();
  SF::SFExpressionNodeHandle  CreateY();
  SF::SFExpressionNodeHandle  CreateZ();

  SF::SFExpressionNodeHandle  CreatePlus(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateMinus(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateMult(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateMin(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateUnion(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS); // Min
  SF::SFExpressionNodeHandle  CreateSpecialUnion(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateMax(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateIntersection(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS); // Max
  SF::SFExpressionNodeHandle  CreateDIV(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);
  SF::SFExpressionNodeHandle  CreateWithOut(const SF::SFExpressionNodeHandle iLHS, const SF::SFExpressionNodeHandle iRHS);

  SF::SFExpressionNodeHandle  CreateNot(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateCOS(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateSIN(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateTAN(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateACOS(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateASIN(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateATAN(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateSQRT(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateSQUARE(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateABS(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateEXP(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreateLN(const SF::SFExpressionNodeHandle iLHS);
  SF::SFExpressionNodeHandle  CreatePOW(const SF::SFExpressionNodeHandle iLHS);

  SF::SFExpressionNodeHandle  GetRef(const SF::SFString& iExpressionId, SF::SFResourceResolver* iResolver = nullptr);
  SF::SFExpressionNodeHandle  CreateRef(const SF::SFString& iTypePrefix, SF::SFString& oExpressionId, SF::SFResourceResolver* iResolver = nullptr);

  /**
   * If one day you think you need to add to this builder methods like CreateTetMeshtoSF or CreateBodyToSF
   * or any of the below one please don't. These methods don't exist on purpose, this force you to set these
   * as CGM dependency or sf resource on your CGMGeometry (ex. ImplicitSurface) and then to use the GetRef method above
   * with the right resolver. By doing so you ensure that your CGM dependency or sf resource will be correctly handled
   * if it need to be persisted in the end.
   */
  /*
  SF::SFExpressionNodeHandle  CreateTetMeshToSF(SF::TetMeshPtr iTetMesh);
	SF::SFExpressionNodeHandle  CreateBodyToSF(
    const CATTolerance& iTolerance,
		const double iDiscretizationStep, 
    CATBody& iBody,
		const SF::CATGMSFDiscretizationAccuracyLevel iAccuracyLevel = SF::CATGMSFDiscretizationAccuracyLevel::CoarseDiscretizationAccuracy,
		const SF::SFDomain* iDomain = nullptr
  );
  SF::SFExpressionNodeHandle  CreateFaceToSF(
    const CATTolerance& iTolerance,
    const double iDiscretizationStep,
    CATFace& iFace,
    const SF::CATGMSFDiscretizationAccuracyLevel iAccuracyLevel = SF::CATGMSFDiscretizationAccuracyLevel::CoarseDiscretizationAccuracy,
    const SF::SFDomain* iDomain = nullptr
  );
  SF::SFExpressionNodeHandle  CreateShellToSF(
    const CATTolerance& iTolerance,
    const double iDiscretizationStep,
    CATShell& iShell,
    const SF::CATGMSFDiscretizationAccuracyLevel iAccuracyLevel = SF::CATGMSFDiscretizationAccuracyLevel::CoarseDiscretizationAccuracy,
    const SF::SFDomain* iDomain = nullptr
  );
  SF::SFExpressionNodeHandle  CreateVolumeToSF(
    const CATTolerance& iTolerance,
    const double iDiscretizationStep,
    CATVolume& iVolume,
    const SF::CATGMSFDiscretizationAccuracyLevel iAccuracyLevel = SF::CATGMSFDiscretizationAccuracyLevel::CoarseDiscretizationAccuracy,
    const SF::SFDomain* iDomain = nullptr
  );
  SF::SFExpressionNodeHandle  CreateWireToSF(
    const CATTolerance& iTolerance,
    const double iDiscretizationStep,
    CATWire& iWire,
    const SF::CATGMSFDiscretizationAccuracyLevel iAccuracyLevel = SF::CATGMSFDiscretizationAccuracyLevel::CoarseDiscretizationAccuracy,
    const SF::SFDomain* iDomain = nullptr
  );
  */

  SF::SFExpressionNodeHandle  CreateFromExistingExpression(const SF::SFExpression& iExpression, SF::SFResourceResolver* iResolver = nullptr);

  void                        SetRoot(SF::SFExpressionNodeHandle iPathToRoot);
  HRESULT                     Build(SF::SFExpression& oExpression);
  HRESULT                     Build(CATUnicodeString& oExpression);
  
	CATImplicitExpressionQuery  GetExpressionQuery(
    SF::SFExpressionNodeHandle  iExpressionHandle,
		SF::SFExpressionPath  oExpressionPath);

  CATSFDagNodeQuery::Ptr              GetNodeQuery(SF::SFExpressionNodeHandle iExpressionNodeHandle);

private:

  SF::SFExpressionNodeHandle  CreateOp(const SF::SFNodeType iNodeType);
  SF::SFExpressionNodeHandle  CreateUnaryOp(const SF::SFNodeType iNodeType, SF::SFExpressionNodeHandle iLhs);
  SF::SFExpressionNodeHandle  CreateBinaryOp(
    const SF::SFNodeType iNodeType, 
    SF::SFExpressionNodeHandle iLhs,
    SF::SFExpressionNodeHandle iRhs
    );
  
  SF::SFExpressionNodeHandle          _rootHandle;
  CATImplicitHandleMap                _handleToNodesQueries;
  CATImplicitRefMap                   _expressionIdsToHandles;

  // Here we don't really care about the initial value, this is just
  // to discriminate between two different expression builder 
  // that might have been created during the same session (life of process)
  // at the same exact memory address. Value comes from atomic<int>, 
  // int is sufficient as it is dubious
  // that in one interactive session you would create/destroy that much
  // expression builder.
  int                                 _ctrl;                                                                 
};

#endif // CATImplicitExpressionBuilder_H

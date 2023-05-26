// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATCSStreamTool.h
// Header definition of CATCSStreamTool
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2006  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSStreamTool_H
#define CATCSStreamTool_H

#include "CATCDS.h"

class CATConstraintSolver;
class CATCSCurve2D;
class CATCSCurve;
class CATCSSketch;
class CATCSSkin;
class CATCSSkinParam;
class CATCSSurface;
class CATCSVariable;
class CATCSEquation;
class CATCSInterpolationNURBSCurve2D;
class CATCSInterpolationNURBSCurve;
class CATCSPoint2D;
class CATCSPoint;
class CATCSLine2D;
class CATCSLine;
class CATCSRigidSet;
class CATCSVariable;
class CATCSNEntity;
class CATCDSString;
class CATCDSExpressionTerm;
class CATCDSStream;
class CATCDSParsedGeometry;

#include "CATCDSEnums.h"
#include "CATCDSBoolean.h"

enum CATCDSStreamMode {
  smFILE,
  smSTREAM
};

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSStreamTool
{
public:
  CATCSStreamTool();
  virtual ~CATCSStreamTool();

  void SetConstraintSolver(CATConstraintSolver * ipCS);

  virtual CATCDSStreamMode GetStreamMode();

  /**
   *  This function should be called at the beginning of a streaming session.
   *  @param iaReplayName
   *    the path and the name (without extension) of the CDSReplay being created
   */
  virtual void BeginStream(const char * iaReplayName);

  /**
   *  This function should be called at the beginning of a streaming session (in the smSTREAM mode).
   *  @param ioStream
   *    stream of the replay being created
   *  @param iaReplayName
   *    the path and the name (without extension) of the CDSReplay being created
   */
  virtual void BeginStream(CATCDSStream & ioStream, const char * iaReplayName);

  /**
   *  This function should be called at the end of a streaming session.
   */
  virtual void EndStream();

  /**
   *  This function should be called at the beginning of an unstreaming session.
   *  @param iaReplayName
   *    the path and the name (without extension) of the CDSReplay being read
   */
  virtual void BeginUnstream(const char * iaReplayName);

  /**
   *  This function should be called at the end of an unstreaming session.
   */
  virtual void EndUnstream();

  /**
   *  Writes the curve into an external file.
   *  @param ipCurve
   *    pointer to Curve2D callback
   *  @param oType
   *    curve type (ordinary, dependent, multi, etc..)
   *  @return
   *    reference to be used in the CDSReplay
   *    -1 in case of error
   */
  virtual unsigned int Stream2DCurve(CATCSCurve2D * ipCurve, unsigned int & oType);

  /**
   *  Creates the curve from the reference read in the CDSReplay.
   *  @param ipSketch
   *    pointer to sketch callback
   *  @param iaParams
   *    first two elements curve direction
   *  @param iReference
   *    curve id
   *  @param iType
   *    curve type (ordinary, dependent, multi, etc..)
   *  @return
   *    pointer to newly created curve
   *    NULL in case of error
   */
  virtual CATCSCurve2D * Unstream2DCurve(double * iaParams, unsigned int iReference, unsigned int iType);

  /**
   *  Writes the curve into an external file.
   *  @param ipCurve
   *    pointer to Curve callback
   *  @param oType
   *    curve type (ordinary, dependent, multi, etc..)
   *  @return
   *    reference to be used in the CDSReplay
   *    -1 in case of error
   */
  virtual unsigned int Stream3DCurve(CATCSCurve * ipCurve, unsigned int & oType);

  /**
   *  Creates the curve from the reference read in the CDSReplay.
   *  @param iReference
   *    curve id
   *  @param iType
   *    curve type (ordinary, dependent, multi, etc..)
   *  @return
   *    pointer to newly created curve
   *    NULL in case of error
   */
  virtual CATCSCurve * Unstream3DCurve(unsigned int iReference, unsigned int iType);

  /**
   *  Writes the surface into an external file.
   *  @param ipSurface
   *    pointer to Surface callback
   *  @param oType
   *    surface type (ordinary, dependent, multi, etc...)
   *  @return
   *    reference to be used in the CDSReplay
   *    -1 in case of error
   */
  virtual unsigned int StreamSurface(CATCSSurface * ipSurface, unsigned int & oType);

  /**
   *  Creates the surface from the reference read in the CDSReplay.
   *  @param iReference
   *    surface id
   *  @param iType
   *    surface type (ordinary, dependent, multi, etc..)
   *  @return
   *    pointer to newly created surface
   *    NULL in case of error
   */
  virtual CATCSSurface * UnstreamSurface(unsigned int iReference, unsigned int iType);

  /**
   *  Writes the equation into an external file.
   *  @param ipEquation
   *    pointer to Equation callback
   *  @param oType
   *    equation type
   *  @return
   *    reference to be used in the CDSReplay
   *    -1 in case of error
   */
  virtual unsigned int StreamEquation(CATCSEquation * ipEquation, unsigned int & oType);

  /**
   *  Creates the equation from the reference read in the CDSReplay.
   *  @param iNbVariables
   *    number of variables in equations
   *  @param iaVariables
   *    pointer to an array of variables
   *  @param iReference
   *    equation id
   *  @param iType
   *    equation type
   *  @return
   *    pointer to newly created equation
   *    NULL in case of error
   */
  virtual CATCSEquation * UnstreamEquation(int iNbVariables, CATCSVariable** iaVariables, unsigned int iReference, unsigned int iType);

  /**
  *  Writes the skin into an external file.
  *  @param ipSkin
  *    pointer to Skin callback
  *  @param oType
  *    skin type
  *  @return
  *    reference to be used in the CDSReplay
  *    -1 in case of error
  */
  virtual unsigned int StreamSkin(CATCSSkin * ipSkin, unsigned int & oType);

  /**
  *  Creates the skin from the reference read in the CDSReplay.
  *  @param iReference
  *    skin id
  *  @param iType
  *    skin type
  *  @return
  *    pointer to newly created skin
  *    NULL in case of error
  */
  virtual CATCSSkin * UnstreamSkin(unsigned int iReference, unsigned int iType);

  /**
  *  Writes the skin parameter into an external file.
  *  @param ipSkinParam
  *    pointer to SkinParam callback
  *  @param oType
  *    parameter type
  *  @return
  *    reference to be used in the CDSReplay
  *    -1 in case of error
  */
  virtual unsigned int StreamSkinParam(CATCSSkinParam * ipSkinParam, unsigned int & oType);

  /**
  *  Creates the skin param from the reference read in the CDSReplay.
  *  @param ipSkin
  *    pointer to parent Skin callback
  *  @param iReference
  *    parameter id
  *  @param iType
  *    parameter type
  *  @return
  *    pointer to newly created skin parameter
  *    NULL in case of error
  */
  virtual CATCSSkinParam * UnstreamSkinParam(CATCSSkin * ipSkin, unsigned int iReference, unsigned int iType);

  // FCX 26/09/2012
  virtual unsigned int StreamRigidSet(CATCSRigidSet * ipRigidSet, unsigned int & oType);
  virtual unsigned int StreamVariable(CATCSVariable * ipVariable, unsigned int & oType);

  // TE9 : For CDS test infra
  virtual void GetParabolicCurveData(CATCSCurve2D *ipCurve, double oaFocus[2], double oaApex[2]);
  virtual void GetCGMCurveData(CATCSCurve *ipCurve, int & oIdx, unsigned int & oType);
  virtual void GetCGMSurfaceData(CATCSSurface *ipSurface, int & oIdx, unsigned int & oType);
  virtual void GetCGMCurve2DData(CATCSCurve2D *ipCurve, int & oIdx, unsigned int & oType);
  virtual void GetParserSkinData(CATCSSkin *ipSkin, int & oIdx, int & oType);
  virtual void GetParserSkinParamData(CATCSSkinParam *ipSkinParam, int & oIdx, int & oType);
  virtual void GetBezierDependences(CATCSCurve *ipCurve, int & onPoints, CATCSNEntity **&oapPoints);
  virtual void GetBezier2DDependences(CATCSCurve *ipCurve, int & onPoints, CATCSNEntity **&oapPoints);
  virtual void GetParserEquationData(CATCSEquation *ipEquation, int & oRefIdx, unsigned int & oStreamEquationType, CATCDSString & oType);
  virtual void GetAlgebraicCurve2DData(CATCSCurve2D *ipCurve, double oaaMatrix[3][3], CATCDSExpressionTerm **oapRootTerms, CATCDSString const *iaNames);
  virtual void GetCompositeCurve2DData(CATCSCurve2D *ipCurve, int & onPoints, CATCSNEntity **&oapPoints);
  virtual void GetArcCurve2DData(CATCSCurve2D *ipCurve, CATCSNEntity **oapPoints, CATCAlignment & oAlign);
  virtual void GetSegmentCurve2DData(CATCSCurve2D *ipCurve, CATCSNEntity **oapPoints, CATCSNEntity *&opParamVar1, CATCSNEntity *&opParamVar2);
  virtual void GetCircleArcCurve2DData(CATCSCurve2D *ipCurve, CATCSNEntity **oapPoints, CATCAlignment & oAlign);
  virtual void GetLineSegmentCurve2DData(CATCSCurve2D *ipCurve, CATCSNEntity **oapPoints);
  virtual void GetAlgebraicCurveData(CATCSCurve *ipCurve, double oaaMatrix[3][3], double oaTranslation[3], CATCDSExpressionTerm **oapRootTerms, CATCDSString const *iaNames);
  virtual void GetAlgebraicSurfaceData(CATCSSurface *ipSurface, double oaaMatrix[3][3], double oaTranslation[3], CATCDSExpressionTerm **oapRootTerms, CATCDSString const *iaNames);
  
  // CHU : copy validating constraints (which belong to input section) into the CDSReplay produced in output
  virtual void PrepareToWriteValidatingConstraints(CATCDSParsedGeometry * iPGeom);
  virtual void WriteValidatingConstraints(CATCDSStream & ioStream);

  // FCX 10/2015 : unstream from a data string
  virtual CATCSCurve * Unstream3DCurve(unsigned int iType, CATCDSString const *ipDataString);
  virtual CATCSCurve2D * Unstream2DCurve(unsigned int iType, CATCDSString const *ipDataString);
  virtual CATCSSurface * UnstreamSurface(unsigned int iType, CATCDSString const *ipDataString);
  virtual CATCSSkin * UnstreamSkin(unsigned int iType, CATCDSString const *ipDataString);
  virtual CATCSSkinParam * UnstreamSkinParam(CATCSSkin * ipSkin, unsigned int iType, CATCDSString const *ipDataString);

  // FCX : For CDS test infra
  virtual void StreamData(CATCDSStream & ioStream);

protected:
  CATConstraintSolver * _pCS;
};

//-----------------------------------------------------------------------

#endif

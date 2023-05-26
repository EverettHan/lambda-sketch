#ifndef CATFrFEdgesComb_H
#define CATFrFEdgesComb_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "FrFTopologicalOpe.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATMathSetOfPointsND.h"
#include "CATListOfInt.h"
class CATEdge;
class CATFace;
class CATMathVector;
class CATMathPoint;
class CATCurve;
class CATCrvParam;
class CATGeoFactory;
class CATMathDirection;
class CATFrFComb;
class CATLaw;
class CATCrvLimits;
class CATMath3x3Matrix;

//--------------------------------------------------------------------------
/**
 * Class defining the operator that dynamically evaluates a comb.
 * <br> The comb is a bi-parametric ruled object. Its first direction is a set
 * of connected edges and its second direction is defined
 * <ul><li>either with a set of vectors that are then interpolated (free comb)
 *     <li>or implicitly with surfaces: the default vectors are such that the generated comb
 * is always tangent to the given surfaces (tangent comb). 
 * This direction is oriented along the cross product of the edge tangent 
 * (possibly re-oriented, see the constructor ) and the face normal. 
 * During the <tt>Run</tt>, this direction can be locally modified to keep the G0 constraint.
 * </ul>
 * A given CATFrFEdgeComb operator can mix free edges 
 * (the vectors at their vertices must then be defined) and tangent edges 
 * (the corresponding faces must be given to retrieve the underlying surface). 
 * The operator does not create the comb object by itself, but gives the means to evaluate 
 * it and its tangent, normal and second derivatives.
 * <br>To use the CATFrfEdgeComb operator:
 * <ul><li> Create it with the constructor
 * <li>Set additional information: set the vectors at given points on the edges in case of a free comb
 * (one vector per point),
 * or ask for closing the profile for example.
 * Note that 
 * <ul><li>if you want a free comb, and if the edges bound faces, 
 * <li> or if you want a tangent comb,
 * </ul>you do not need to add
 * any additional information.
 * <li>Run the operator
 * <li>Evaluate the comb or its normal and/or first and second derivatives
 * <li>Optionally modifies some settings and run again the operator.
 * <li>Delete the operator.
 *</ul>
 *
 */
class ExportedByFrFTopologicalOpe CATFrFEdgesComb
{
 public:
  /**
   * Constructs an operator to evaluate a comb.
   * @param iFactory
   * The pointer to the geometry factory.
   * @param iListOfEdges
   * The list of pointers to the connected edges defining the first direction of the comb.
   * @param iListOfFaces
   * The list of pointers to the faces: if an edge is free, the corresponding pointer
   * to the face is null.
   * @param iListOfOrn
   * The list of the relative orientation for each edge.
   * <br><b>Legal values</b>:
   * <dl><dt><tt>1</tt></dt><dd>The edge is used in is original orientation.
   * <dt><tt>-1</tt></dt><dd>The edge is used with an opposite orientation.
   * </dl>
   * These specifications must insure that the end of
   * one edge (possibly reversed) is the beginning of the following.
   */
  CATFrFEdgesComb(      CATGeoFactory  *iFactory, 
                  const ListPOfCATEdge *iListOfEdges, 
                  const ListPOfCATFace *iListOfFaces ,
                  const CATListOfInt   *iListOfOrn);

  virtual ~CATFrFEdgesComb();

  //--------------------
  // Set
  //--------------------
  /**
   * Defines the vector at a given point of an edge.
   * <br> To use in case of a free edge.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iParam
   * The parameter on the corresponding edge of the point.
   * @param iDir
   * The vector to take into account at <tt>iParam</tt>.
   */
  void SetDirection(CATLONG32 iEdgeRank,const CATCrvParam &iParam,const CATMathVector &iDir);

  /**
   * Defines the vector of the cross derivative at a given point of an edge.
   * <br> To use to insure the compatibility between two combs for example.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iParam
   * The parameter on the corresponding edge of the point.
   * @param iDir
   * The vector to take into account at <tt>iParam</tt> to be the cross derivative.
   */
  void SetCrossDerivative(CATLONG32 iEdgeRank,const CATCrvParam &iParam,const CATMathVector &iDir);

  /**
   * Defines that the set of edges is closed: the first and last vertices are the same. 
   */
  void SetIsClosed();

  /** 
   * Defines which curve of the edge curve to be taken as geometry of the
   * first direction of the comb.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iCrvForEdge
   * The pointer to the curve of the edge curve definining the geometry of the first 
   * direction of the comb.
   */
  void SetCurveForAnEdge(CATLONG32 iEdgeRank,const CATCurve *iCrvForEdge);

  /** 
   * Returns the pointer to the curve of the edge curve to be taken as geometry of the
   * first direction of the comb.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iLim
   * The limits on the returned curve of the edge of rank <tt>iEdgeRank</tt>. If NULL, 
   * the argument is not filled.
   * @return 
   * The pointer to the curve of the edge curve definining the geometry of the first 
   * direction of the comb.
   */
  const CATCurve * GetCurveForAnEdge(CATLONG32 iEdgeRank,CATCrvLimits * iLim=NULL);

  /**
   * @nodoc
   * Default is No/0. If you want to create a comb on 3D Curves.
   */
  void Set3DCombCreationOption(CATBoolean iYesNo);

  /**
   * @nodoc
   */
  CATBoolean Get3DCombCreationOption();

  /**
   * Retrieves the definition of a section of the comb.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param oEdge
   * The pointer to the corresponding edge.
   * @return
   * The pointer to the face given to compute the tangents. <tt>NULL</tt> for a free edge.
   */
  const CATFace * GetEdgeAndFace(CATLONG32 iEdgeRank,const CATEdge *& oEdge);

  /**
   * Checks whether the comb defined by <tt>this</tt> can be evaluated.
   * @return
   * The result of the test.
   * <br><b>Legal values</b>: <tt>0</tt> if it is, not null if a problem is detected.
   */
  CATLONG32 Check();

  /**
   * Runs <tt>this</tt> operator.
   * <br> To be called to access the evaluations.
   */
  void UpdateComb();


  //--------------------
  // Eval methods
  //--------------------
  /**
   * Evaluates the comb.
   * <br>To use after the <tt>Run</tt> method.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iParam
   * The parameter on the edge of the point to evaluate.
   * @param ioPt
   * The corresponding 3D point.
   */
  void EvalPoint(CATLONG32 iEdgeRank,const CATCrvParam &iParam,CATMathPoint &ioPt);

  /**
   * Evaluates the first derivatives of the comb.
   * <br>To use after the <tt>Run</tt> method.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iParam
   * The parameter on the edge of the point to evaluate.
   * @param ioDu
   * The first derivative w.r.t. to the first direction at the corresponding point. 
   * If <tt>NULL</tt>, the argument is not filled.
   * @param ioDv
   * The first derivative w.r.t. to the second direction at the corresponding point. 
   * If <tt>NULL</tt>, the argument is not filled.
   */
  void EvalFirstDerivatives(      CATLONG32       iEdgeRank,
                            const CATCrvParam    &iParam   ,
                                  CATMathVector  *ioDu     ,
                                  CATMathVector  *ioDv     );

  /**
   * Evaluates the second derivatives of the comb.
   * <br>To use after the <tt>Run</tt> method.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iParam
   * The parameter on the edge of the point to evaluate.
   * @param ioDuu
   * The second derivative w.r.t. to the first direction at the corresponding point. 
   * If <tt>NULL</tt>, the argument is not filled.
   * @param ioDuv
   * The cross derivative at the corresponding point. 
   * If <tt>NULL</tt>, the argument is not filled.
   * @param ioDvv
   * The second derivative w.r.t. to the second direction at the corresponding point. 
   * If <tt>NULL</tt>, the argument is not filled.
   */
  void EvalSecondDerivatives(      CATLONG32       iEdgeRank,
                             const CATCrvParam   & iParam, 
                                   CATMathVector * ioDuu,
                                   CATMathVector * ioDuv, 
                                   CATMathVector * ioDvv);

  /**
   * Evaluates the normal to the comb.
   * <br>To use after the <tt>Run</tt> method.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param iParam
   * The parameter on the edge of the point to evaluate.
   * @param ioDir
   * The normal to the comb at the corresponding point.
   */
  void EvalNormal(CATLONG32 iEdgeRank,const CATCrvParam &iParam,CATMathDirection &ioDir);

  /**
   * Inverts the second direction of the entire comb. 
   * <br>To use after a first call to the <tt>Run</tt> method.
   */
  void InvertCombOrientation();

  /**
   * Returns the maximal angular deformation. 
   * <br>To use after the <tt>Run</tt> method.
   * @return
   * The result maximal angular deformation expressed in radian.
   */
  double GetAngularDeviation();

  /**
   * Evaluates the maximal angular deformation on an edge.
   * <br>To use after the <tt>Run</tt> method.
   * @param iEdgeRank
   * The rank (beginning at 1) of the edge.
   * @param ioLim
   * The limits on the corresponding curve of the edge of rank <tt>iEdgeRank</tt>. If NULL, 
   * the argument is not filled.
   * @return
   * The result maximal angular deformation expressed in radian on the corresponding edge.
   */
  double GetAngularDeviation(CATLONG32 iEdgeRank,const CATCrvLimits *ioLim=NULL);

  //--------------------
  // Private methods.
  //--------------------
  /**
   * @nodoc
   */
  void ComputeSystemForCrossDeriv(      CATLONG32          iEdgeRank ,
                                  const CATCrvParam      & iParam    ,
                                        CATLONG32        & iOrn      ,
                                        CATMath3x3Matrix & iMatrix   ,
                                        double           * iSecMember);

 protected:

  void      CleanConstraints();
  void      ComputeTargetDirections();
  void      ComputeOneDirection    (CATLONG32 iCurr, CATLONG32 iRef, const CATCrvParam &iCurrParam, const CATCrvParam &iRefParam);
  void      ComputeLaw();
  void      ComputeDirectionLaw    (CATLONG32 iIndex, CATMathSetOfPointsND &iParam, CATMathSetOfPointsND &iAngle, double * StartTg=0, double * EndTg=0);
  void      ComputeDeformationLaw  (CATLONG32 iIndex, CATMathSetOfPointsND &iParam, CATMathSetOfPointsND &iAngle, double * StartTg=0, double * EndTg=0);
  void      ComputeLengthLaw       (CATLONG32 iIndex, CATMathSetOfPointsND &iParam, CATMathSetOfPointsND &iAngle, double * StartTg=0, double * EndTg=0);

  void      FromGlobalToLocalParam(double iGlobalParam, CATLONG32 &iEdgeRank, CATCrvParam &iParamOnEdge, CATLONG32 *Spec=0);
  void      FromLocalToGlobalParam(CATLONG32 iEdgeRank, const CATCrvParam &iParamOnEdge, double &iGlobalParam);
  void      FromEdgeToCrv         (CATLONG32 iEdgeRank, const CATCrvParam &iParamOnEdge, CATCrvParam &iParamOnCrv);
  CATLONG32 OrnListvsCrv(CATLONG32 iEdgeRank);

  //Datas
  //Input
  CATGeoFactory            * _Fact;
  const ListPOfCATEdge     * _ListOfEdges;
  const ListPOfCATFace     * _ListOfFaces;
  const CATListOfInt       * _ListOfOrn;

  //Option
  CATLONG32                  _IsClosed; //0 (ouvert) ou 1 (ferme)
  CATMathSetOfPointsND     * _ArrayOfDeriv; //To store Input Direction - Dim=4 : 0->GlobalParam , 1,..,3->Coordinates
  CATLONG32                  _Create3DComb;

  //Local
  CATLONG32                  _IsUpToDate; //0 (pas a jour) ou 1 (a jour)
  double                     _ParamInter;
  CATMathSetOfPointsND     * _ArrayOfDerivExt; //To store Internal Direction ...
  CATFrFComb              ** _Comb;
};
#endif

// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSGeomConstraint.h
// Header definition of CATCSGeomConstraint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation                 Evgueni ROUKOLEEV
//===================================================================

#ifndef CATCSGeomConstraint_H
#define CATCSGeomConstraint_H

#include "CATCDSVirtual.h"
#include "CATCDSBoolean.h"
#include "CATCDS.h"
#include "CATCSConstraint.h"
#include "CATCDSEnums.h"
#include "CATCDSListP.h"

class CATCSGeometryLeaf;
class CATCSSketch;
class CATCSSkinParam;

//-----------------------------------------------------------------------

/**
 * A basic class for all logical constraints.
 */
class ExportedBySolverInterface CATCSGeomConstraint : public CATCSConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSGeomConstraint();

  virtual ~CATCSGeomConstraint();

  /**
   * Checks whether the entity is matched to a specific type. The entity can
   * be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
   * Retrieves geometries connected with the constraint.
   * @param opGeom1
   *   The first geometry.
   * @param opGeom2
   *   The second geometry.
   * @param opGeom3
   *   The third geometry.
   */
  void GetGeometries(CATCSGeometryLeaf *&opGeom1, CATCSGeometryLeaf *&opGeom2, CATCSGeometryLeaf *&opGeom3);

  /**
   * Retrieves a sketch which includes the constraint. This method is
   * deprecated and should not be used in newly-written code.
   * @return
   *   Pointer to the sketch.
   */
  virtual CATCSSketch *GetSketch();

  /**
   * Retrieves alignment of the constraint.
   * @return
   *   An alignment of the constraint.
   * @see #SetAlignment
   */
  virtual CATCAlignment GetAlignment();

  /**
   * Sets alignment of the constraint.
   * @param iAlignment
   *   An alignment of the constraint.
   * @see #GetAlignment
   */
  virtual void SetAlignment(CATCAlignment iAlignment);

  /**
   * Retrieves help point of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param oaPoint
   *   An array of coordinates of the help point.
   * @see #UpdateHelpPoint
   */
  virtual CATCDSBoolean GetHelpPoint(CATCSGeometryLeaf *ipGeom, double oaPoint[3]);

  /**
   * Updates help point of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param iaPoint
   *   An array of coordinates of the help point.
   * @see #GetHelpPoint
   */
  virtual void UpdateHelpPoint(CATCSGeometryLeaf *ipGeom, double iaPoint[3]);

  /**
   * BE CAREFUL : THIS METHOD IS NOT IMPLEMENTED IN DERIVED CLASSES
   * USE ONLY FOR PUBLIC API
   */
  virtual CATCDSBoolean GetHelpParametersRet(CATCSGeometryLeaf *ipGeom, double &oFirstParam, double &oSecondParam);

  /**
   * Retrieves help parameters of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param oFirstParam
   *   A value of the first help parameter.
   * @param oSecondParam
   *   A value of the second help parameter.
   * @see #UpdateHelpParameters
   */
  virtual void GetHelpParameters(CATCSGeometryLeaf *ipGeom, double &oFirstParam, double &oSecondParam);

  /**
   * Updates help parameters of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param iFirstParam
   *   A value of the first help parameter.
   * @param iSecondParam
   *   A value of the second help parameter.
   * @see #GetHelpParameters
   */
  virtual void UpdateHelpParameters(CATCSGeometryLeaf *ipGeom, double iFirstParam, double iSecondParam);

  /**
   * Retrieves help parameter of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @return
   *   A value of the help parameter.
   * @see #UpdateHelpParameter
   */
  virtual double GetHelpParameter(CATCSGeometryLeaf *ipGeom);

  /**
   * BE CAREFUL : THIS METHOD IS NOT IMPLEMENTED IN DERIVED CLASSES
   * USE ONLY FOR PUBLIC API
   */
  virtual CATCDSBoolean GetHelpParameter(CATCSGeometryLeaf *ipGeom, double &oParam);

  /**
   * Updates help parameter of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param iParam
   *   A value of the help parameter.
   * @see #GetHelpParameter
   */
  virtual void UpdateHelpParameter(CATCSGeometryLeaf *ipGeom, double iParam);

  /**
   * Retrieves skin help parameter of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @return
   *   A pointer to the skin help parameter.
   * @see #UpdateSkinHelpParameter
   */
  virtual CATCSSkinParam *GetSkinHelpParameter(CATCSGeometryLeaf *ipGeom);

  /**
   * Updates skin help parameter of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param ipSkinParam
   *   A pointer to the skin help parameter.
   * @see #GetSkinHelpParameter
   */
  virtual void UpdateSkinHelpParameter(CATCSGeometryLeaf *ipGeom, CATCSSkinParam *ipSkinParam);

  /**
   * Checks whether an argument is leading.
   * @param iArgIdx
   *   An index of the argument.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the argument is leading,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   * @see #SetArgLeading
   */
  virtual CATCDSBoolean IsArgLeading(int iArgIdx);

  /**
   * Sets leading status of an argument.
   * @param iArgIdx
   *   An index of the argument.
   * @param iLeading
   *   <ul>
   *     <li><tt>TRUE</tt> - if the argument is leading,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   * @see #IsArgLeading
   */
  virtual void SetArgLeading(int iArgIdx, CATCDSBoolean iLeading);

   /**
   * specify sorftness of the constraint.
   * @param iSoftness
   *  value of the softness
   */
  virtual void SetSoftness(double iSoftness);

  /**
   * Retrieves stiffness of the constraint.
   * @return
   *   A value of the stiffness.
   */
  double GetStiffness();

  /**
   * Retrieves surface orientation of the constraint.
   * @return
   *   A surface orientation of the constraint.
   */
  virtual CATCSurfaceOrientation GetSurfaceOrientation();

  /**
   * Sets surface orientation of the constraint.
   * @param iSurfaceOrientation
   *   Surface orientation of the constraint.
   * @see #GetSurfaceOrientation
   */
  virtual void SetSurfaceOrientation(CATCSurfaceOrientation iSurfaceOrientation);

private:
  CATCSGeometryLeaf *_pArg[MAX_CONSTRAINT_PARAMS];
  double _aPoints[MAX_CONSTRAINT_PARAMS][3];
  CATCSSkinParam *_pSkinParam[MAX_CONSTRAINT_PARAMS];
  CATCAlignment _Alignment;
  CATCSurfaceOrientation _SurfaceOrientation;
  int _helpTypes[MAX_CONSTRAINT_PARAMS]; // 0 none, 1 point, 2 param, 3 skin param
  CATCDSBoolean _aIsArgLeading[3];
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSGeomConstraint, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif

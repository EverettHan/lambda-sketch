#ifndef CATWbrData_H
#define CATWbrData_H

#include "CATCGMVirtual.h"
#include "CATMathInline.h"
#include "CATCGMNewArray.h"
#include "CATGeoFactory.h"
#include "ListPOfCATWbrData.h"
#include "ListPOfCATFace.h"
#include "CATMathLine.h"
#include "CATMathPlane.h"
#include "CATAppendList.h"
#include "CATVolume.h"

//------------------------------------------------------------
// CATWbrVirtualElement
//------------------------------------------------------------
class CATWbrVirtualElement : public CATCGMVirtual
{
public:
  CATWbrVirtualElement();
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrVirtualElement();

  INLINE virtual CATWbrSimpleElement* GetAsWbrSimpleElement() { return NULL; };
  INLINE virtual CATWbrPlaneData* GetAsWbrPlaneData() { return NULL; };
  INLINE virtual CATWbrRevolutionData* GetAsWbrRevolutionData() { return NULL; };
  INLINE virtual CATWbrCylinderData* GetAsWbrCylinderData() { return NULL; };
  INLINE virtual CATWbrConeData* GetAsWbrConeData() { return NULL; };
  INLINE virtual CATWbrFacingElement* GetAsWbrFacingElement() { return NULL; };
  INLINE virtual CATWbrWallData* GetAsWbrWallData() { return NULL; };
  INLINE virtual CATWbrBendData* GetAsWbrBendData() { return NULL; };
  
  virtual void GetRep(ListPOfCATFace &oRep) = 0;

  virtual HRESULT IsConfused(CATWbrVirtualElement &iOtherVElt, double &iLinearTol, double &iAngularTol) = 0;
  HRESULT IsConfused(ListPOfCATWbrVirtualElement &iOtherVElts, double &iLinearTol, double &iAngularTol);

  // static
  static void GetAllReps(ListPOfCATWbrVirtualElement &iVElts, ListPOfCATFace &oRep);
  static void GetAllReps(ListPOfCATWbrSimpleElement &iSElts, ListPOfCATFace &oRep);
  static void GetAllReps(ListPOfCATWbrPlaneData &iPlanes, ListPOfCATFace &oRep);
  static void GetAllReps(ListPOfCATWbrCylinderData &iCylinders, ListPOfCATFace &oRep);
  static void GetAllReps(ListPOfCATWbrConeData &iCones, ListPOfCATFace &oRep);

  static HRESULT AreConfused(ListPOfCATWbrVirtualElement &iVElts, double &iLinearTol, double &iAngularTol);
  static HRESULT AreConfused(ListPOfCATWbrVirtualElement &iVElts1, ListPOfCATWbrVirtualElement &iVElts2, double &iLinearTol, double &iAngularTol);
  static HRESULT AreConfused(ListPOfCATWbrWallData &iWalls1, ListPOfCATWbrWallData &iWalls2, double &iLinearTol, double &iAngularTol);

  static HRESULT GetGroupsOfConfused(ListPOfCATWbrVirtualElement &iVElts, double &iLinearTol, double &iAngularTol, ListPOfListPOfCATWbrVirtualElement &oGroupsOfVElts);

  // debug
  int GetTag();

private:
  // data
};

//------------------------------------------------------------
// CATWbrSimpleElement
//------------------------------------------------------------
class CATWbrSimpleElement : public CATWbrVirtualElement
{
public:
  CATWbrSimpleElement(ListPOfCATFace &iRep, CATVolume &iVolume);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrSimpleElement();

  INLINE CATWbrSimpleElement* GetAsWbrSimpleElement() { return this;  };

  INLINE void GetRep(ListPOfCATFace &oRep) { oRep = _Rep; };
  INLINE void SetRep(ListPOfCATFace &iRep) { _Rep = iRep; };

  HRESULT SameVolume(CATWbrSimpleElement &iOtherSElt);
  HRESULT IsConfused(CATWbrVirtualElement &iOtherVElt, double &iLinearTol, double &iAngularTol);

  virtual HRESULT AreParallel(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol) = 0;
  virtual HRESULT DistanceTo(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol, double &oDistance) = 0;

  // static
  static HRESULT DistanceTo(ListPOfCATWbrSimpleElement &iSElts1, ListPOfCATWbrSimpleElement &iSElts2, double &iLinearTol, double &iAngularTol, double &oDistance);

private:
  // data
  ListPOfCATFace _Rep;
  CATVolume *_Volume;
};

//------------------------------------------------------------
// CATWbrPlaneData
//------------------------------------------------------------
class CATWbrPlaneData : public CATWbrSimpleElement
{
public:
  CATWbrPlaneData(ListPOfCATFace &iRep, CATMathPlane &iPlane, CATVolume &iVolume);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrPlaneData();

  INLINE CATWbrPlaneData* GetAsWbrPlaneData() { return this; };

  INLINE CATMathPlane GetPlaneRep() { return _PlaneRep; };

  HRESULT AreParallel(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol);
  HRESULT DistanceTo(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol, double &oDistance);

private:
  // data
  CATMathPlane _PlaneRep;
};

//------------------------------------------------------------
// CATWbrRevolutionData
//------------------------------------------------------------
class CATWbrRevolutionData : public CATWbrSimpleElement
{
public:
  CATWbrRevolutionData(ListPOfCATFace &iRep, CATMathLine &iAxis, CATVolume &iVolume);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrRevolutionData();

  INLINE CATWbrRevolutionData* GetAsWbrRevolutionData() { return this; };

  INLINE CATMathLine GetRevolutionAxis() { return _Axis; };

  HRESULT AreParallel(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol);
  HRESULT AreConcentric(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol);

private:
  // data
  CATMathLine _Axis;
};

//------------------------------------------------------------
// CATWbrCylinderData
//------------------------------------------------------------
class CATWbrCylinderData : public CATWbrRevolutionData
{
public:
  CATWbrCylinderData(ListPOfCATFace &iRep, CATMathLine &iAxis, double &iRadius, CATVolume &iVolume);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrCylinderData();

  INLINE CATWbrCylinderData* GetAsWbrCylinderData() { return this; };

  INLINE double GetCylinderRadius() { return _Radius; };

  HRESULT DistanceTo(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol, double &oDistance);

private:
  // data
  double _Radius;
};

//------------------------------------------------------------
// CATWbrConeData
//------------------------------------------------------------
class CATWbrConeData : public CATWbrRevolutionData
{
public:
  CATWbrConeData(ListPOfCATFace &iRep, CATMathLine &iAxis, double &iMaxRadius, double &iMinRadius, double &iConeAngle, CATVolume &iVolume);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrConeData();

  INLINE CATWbrConeData* GetAsWbrConeData() { return this; };

  INLINE double GetConicalMaxRadius() { return _MaxRadius; };
  INLINE double GetConicalMinRadius() { return _MinRadius; };

  INLINE double GetConeAngle() { return _ConeAngle; };

  HRESULT DistanceTo(CATWbrSimpleElement &iOtherSElt, double &iLinearTol, double &iAngularTol, double &oDistance);
  
private:
  // data
  double _MaxRadius;
  double _MinRadius;
  double _ConeAngle;
};

//------------------------------------------------------------
// CATWbrFacingElement
//------------------------------------------------------------
class CATWbrFacingElement : public CATWbrVirtualElement
{
public:
  CATWbrFacingElement(double &iThickness);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrFacingElement();

  INLINE CATWbrFacingElement* GetAsWbrFacingElement() { return this; };

  INLINE double GetThickness() { return _Thickness; };

  void GetRep(ListPOfCATFace &oRep);
  void GetRep(ListPOfCATFace oRep[2]);
  virtual void GetEltRep(ListPOfCATWbrSimpleElement oRep[2]) = 0;

  HRESULT IsConfused(CATWbrVirtualElement &iOtherVElt, double &iLinearTol, double &iAngularTol);
  HRESULT IsConfused(CATWbrVirtualElement &iOtherVElt, double &iLinearTol, double &iAngularTol, CATBoolean &oReversed);

private:
  // data
  double _Thickness;
};

//------------------------------------------------------------
// CATWbrWallData
//------------------------------------------------------------
class CATWbrWallData : public CATWbrFacingElement
{
public:
  CATWbrWallData(ListPOfCATWbrPlaneData iPlanes[2], double &iThickness);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrWallData();

  INLINE CATWbrWallData* GetAsWbrWallData() { return this; };

  INLINE void GetEltRep(ListPOfCATWbrSimpleElement oRep[2]) { APPENDLIST(oRep[0], _Planes[0]); APPENDLIST(oRep[1], _Planes[1]); };
  INLINE void GetPlaneRep(ListPOfCATWbrPlaneData oRep[2]) { oRep[0] = _Planes[0]; oRep[1] = _Planes[1]; };

private:
  // data
  ListPOfCATWbrPlaneData _Planes[2];
};

//------------------------------------------------------------
// CATWbrBendData
//------------------------------------------------------------
class CATWbrBendData : public CATWbrFacingElement
{
public:
  CATWbrBendData(ListPOfCATWbrCylinderData iCylinders[2], double &iThickness, ListPOfCATWbrWallData iConnectedWalls[2], CATListOfInt iIsReversedForEachWall[2]);
  //RL1
  CATWbrBendData(ListPOfCATWbrConeData iCones[2], double &iThickness, ListPOfCATWbrWallData iConnectedWalls[2], CATListOfInt iIsReversedForEachWall[2]);
  CATCGMNewClassArrayDeclare; // Pool allocation
  ~CATWbrBendData();

  INLINE CATWbrBendData* GetAsWbrBendData() { return this; };

  INLINE void GetEltRep(ListPOfCATWbrSimpleElement oRep[2]) { APPENDLIST(oRep[0], _Cylinders[0]); APPENDLIST(oRep[1], _Cylinders[1]); APPENDLIST(oRep[0], _Cones[0]); APPENDLIST(oRep[1], _Cones[1]); };
  INLINE void GetCylinderRep(ListPOfCATWbrCylinderData oRep[2]) { oRep[0] = _Cylinders[0]; oRep[1] = _Cylinders[1]; };
  INLINE void GetConeRep(ListPOfCATWbrConeData oRep[2]) { oRep[0] = _Cones[0]; oRep[1] = _Cones[1]; };
  INLINE void GetConnectedWalls(ListPOfCATWbrWallData oConnectedWalls[2]) { oConnectedWalls[0] = _ConnectedWalls[0]; oConnectedWalls[1] = _ConnectedWalls[1]; };
  INLINE void GetIsReversedForEachWall(CATListOfInt oIsReversedForEachWall[2]) { oIsReversedForEachWall[0] = _IsReversedForEachWall[0]; oIsReversedForEachWall[1] = _IsReversedForEachWall[1]; };

  CATMathLine GetBendAxis();

  INLINE void SetLateralFaces(ListPOfCATFace iLateralFaces[2]) { _LateralFaces[0] = iLateralFaces[0]; _LateralFaces[1] = iLateralFaces[1]; };
  INLINE void GetLateralFaces(ListPOfCATFace oLateralFaces[2]) { oLateralFaces[0] = _LateralFaces[0]; oLateralFaces[1] = _LateralFaces[1]; };

private:
  // data
  ListPOfCATWbrCylinderData _Cylinders[2];
  ListPOfCATWbrConeData _Cones[2];
  
  ListPOfCATWbrWallData _ConnectedWalls[2];
  CATListOfInt _IsReversedForEachWall[2];

  ListPOfCATFace _LateralFaces[2];
};

#endif

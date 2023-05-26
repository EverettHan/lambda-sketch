// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=================================================================================
// CATVolumeSupportFillet:
//  Interface of fillet operator around one volume support for additive manufacturing 
//=================================================================================
// 09 03 2020 TAT3 Creation 
// 

#ifndef CATVolumeSupportFillet_H
#define CATVolumeSupportFillet_H
#include "AdvTopoOpeItf.h"

// Math
#include "CATMathPoint.h"
// Poly
#include "CATPolyBody.h"

// std
#include <vector>

// Base class
#include "CATSupportFillet.h"

class CATLoopFillet;

/** 
* class to create fillet at the bottom intersection of a polyhedral volume support and a plane.
*/
class ExportedByAdvTopoOpeItf CATVolumeSupportFillet : public CATSupportFillet {
  CATCGMVirtualDeclareClass(CATVolumeSupportFillet);
public:
  /* Use CATCreateVolumeSupportFillet instead. */
  CATVolumeSupportFillet(CATGeoFactory *iFactory, CATSoftwareConfiguration *config);
  virtual ~CATVolumeSupportFillet();

/** 
 * @brief Define the (only) external loop of the Volume support. The fillet direction is inward if the winding is Counter Clock Wise.
 * @param iTopLoop Points corresponding to the upper contour. 
 * @param iBottomLoop Points corresponding to the lower contour (each bottom point must match with the top point with same index)
 * Bottom loop is assumed to lie on a plane. They must have same length.
 * @param iHeight Height of tangency between fillet and vertical. 
 * @param iiFilletRadius Width of the fillet from bottom to tangency with the tray. */
  virtual void SetOuterLoop(const int N, const CATMathPoint * iTopLoop, const CATMathPoint *iBottomLoop);

/**
 * @brief Define an inner loop of the Volume support. The fillet direction is inward if the winding is Counter Clock Wise.
 * @param iTopLoop Points corresponding to the upper contour.
 * @param iBottomLoop Points corresponding to the lower contour (each bottom point must match with the top point with same index)
 * Bottom loop is assumed to lie on a plane. They must have same length. 
 * @param iHeight Height of tangency between fillet and vertical. 
 * @param iFilletRadius Width of the fillet from bottom to tangency with the tray. 
 * @returns The index of the current loop. */
  virtual int AddInnerLoop(const int N, const CATMathPoint * iTopLoop, const CATMathPoint *iBottomLoop);
  
/**
 * @brief Remove one InnerLoop. 
 */
  virtual void RemoveInnerLoop(int idx);

/**
 * @brief Define Fillet Parameter of one of the inner loops.
 * @param iIndex index returned by AddLoop.
 * @param iFilletRadius Horizontal width of the fillet.
 * @param iFilletHeight Vertical Height of the fillet.
 */
  virtual void SetInnerFilletParam(int iIndex, double iFilletRadius, double iFilletHeight);

/**
 * @brief Define Fillet Parameter of the outer loop.
 * @param iIndex index returned by AddLoop.
 * @param iFilletRadius Horizontal width of the fillet.
 * @param iFilletHeight Vertical Height of the fillet.
 */
  virtual void SetOuterFilletParam(double iFilletRadius, double iFilletHeight);

/**
 * @brief Global setter for height and radius. 
 */
  virtual void SetFilletParam(double iFilletRadius, double iFilletHieght);

/**
 * @brief Define the top and bottom Mesh of the support. 
 * if provided the vertices of the mesh should coincide with the top and bottom loops. 
 * if the mesh are not provided (nullptr) the algo will create 2d mesh based on the input loops, only work for flat curves.
 * @param iTopMesh The Top is along the body to support, oriented upward.
 * @param iBottomMesh The Bottom is flat on the tray, also oriented upward.
 */
  virtual void SetTopBottomMesh(CATIPolyMesh *iTopMesh, CATIPolyMesh *iBottomMesh);



  int RunOperator();


  //static const CATString * GetDefaultOperatorId() { return &_OperatorId; }

  /** @nodoc @nocgmitf Used for ODT Reference Traces */
  //void Dump(CATCGMOutput& os);

  
protected:
  /* {CGMReplay */
  /** @nodoc @nocgmitf CGMReplay Mandatory */
  //static CATString _OperatorId;

  /** @nodoc @nocgmitf CGMReplay Mandatory */
  //const CATString * GetOperatorId();

  /** @nodoc @nocgmitf CGMReplay Mandatory */
  //CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  
  /** @nodoc @nocgmitf Mandatory */
  //void WriteInput(CATCGMStream  & ioStream);
  
  /** @nodoc @nocgmitf */
  //void WriteOutput(CATCGMStream & Str);

  /* CGMReplay} */


  /* ODT Debug */
  /** @brief Performs CATPolyBodyChecker and CATPolyBodyGeoChecker on CATPolyBody. */
  void CheckPolyBody(CATCGMSharedPtr<CATPolyBody> iPolyBody);

private:

  CATBody * ConvertMeshToBodyPH(CATCGMSharedPtr<CATPolyBody> iPolyBody);

  /** Contains each loop Top points, Bottom points, Radius, Height, Orientation */
  std::vector<CATLoopFillet> _ListOfLoops;

  /** @brief Top Mesh used to reclose the volume support. */
  CATCGMSharedPtr<CATIPolyMesh> _TopMesh;
  /** @brief Bottom Mesh used to reclose the volume support. */
  CATCGMSharedPtr<CATIPolyMesh> _BottomMesh;

  CATCGMSharedPtr<CATPolyBody> _PolyBodyResult;

  CATCGMSharedPtr<CATPolyBody> JoinMesh(std::vector<CATCGMSharedPtr<CATIPolyMesh>> &ioLeftHandSide);

  void FlipMesh(CATCGMSharedPtr<CATIPolyMesh> pMesh);

  void RemoveIntersections(CATCGMSharedPtr<CATIPolyMesh> &pMesh);

  CATBody * ConvertMeshToBodyPH(CATCGMSharedPtr<CATIPolyMesh> iMesh);

  CATCGMSharedPtr<CATIPolyMesh> ConvertPolyBodyToPolyMesh(CATCGMSharedPtr<CATPolyBody> pPolyBody);

  void WriteMesh(CATCGMStream & Str, CATCGMSharedPtr<CATIPolyMesh> iPolyMesh);

  void ExportLoop(CATUnicodeString iFilename, const int N, const CATMathPoint * iLoop);

};


/**
 * @brief global function to create instance of CATVolumeSupportFillet.
 * @param iFactory Pointer to the geometry factory that create the result bodies.
 * @param iConfig Pointer to the software configuraiton.
*/
ExportedByAdvTopoOpeItf CATVolumeSupportFillet *CATCreateVolumeSupportFillet(CATGeoFactory *iFactory,  CATSoftwareConfiguration *config);

#endif


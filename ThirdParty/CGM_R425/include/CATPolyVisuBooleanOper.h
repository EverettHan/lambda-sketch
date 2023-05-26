// COPYRIGHT DASSAULT SYSTEMES 2006-2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuBooleanOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// February 2016 Creation: JXO, from CATPolyVisuIntersectOper
//===================================================================
#ifndef CATPolyVisuBooleanOper_H
#define CATPolyVisuBooleanOper_H

#include "PolyVisuBoolOper.h"
#include "CATErrorDef.h" // Definition of HRESULT
#include "CATBoolean.h"
#include "CATMathBox.h"

class CAT3DBagRep;
class CAT3DRep;
class CATRep;
class CATMathBox;

class CATIPolyMesh;
class CATIPolySurfaceVertexPositionLayer;
class CATPolyMeshVertexNNormalsLayer;
class CATPolyMeshTriangleVizLayer;
class CATPolyBars;
class CATPolyBarsBarVizLayer;
class CATPolyGriddedPositions;
class CATPolyGriddedMeshAndBars;
class CATPolyExactArithmetic;


/*
 * Boolean operator calculating the intersection of two CAT3DRep.
 */
class ExportedByPolyVisuBoolOper CATPolyVisuBooleanOper
{

public :

  /*
   * Construct a boolean operator.
   * @param iBox
   *    Bounding box of the domain that contains the operands.
   */
  CATPolyVisuBooleanOper (const CATMathBox& iBox);

  ~CATPolyVisuBooleanOper ();

public:

  /**
   * Sets the type of boolean operation to perform.  (See CATPolyBoolean::BooleanOperation.)
   * @param iOperation
   *   <ul> 
   *     <li> CATPolyBoolean::eBooleanNone to perform no boolean operation. 
   *          This is the mode that should be set if one wants to clip Operand 0 by Operand 1 just according to the intersection traces 
   *          and the orientation of the operands.
   *     <li> CATPolyBoolean::eBooleanUnion to perform a union between Operand 0 and Operand 1.
   *     <li> CATPolyBoolean::eBooleanIntersection to perform an intersection between Operand 0 and Operand 1.
   *     <li> CATPolyBoolean::eBooleanSubtraction to subtract Operand 1 from Operand 0.
   *   </ul>
   */
  inline void SetBooleanOperation (const int iOperation);

  /*
   * Turn on or off an option to disregard the normals of the operand.
   * By default, normals are processed (option set to FALSE).
   */
  inline void DisregardNormals (const CATBoolean iDisregard);

  /*
   * Turn on or off an option to process custom reps.
   * By default, custom reps are processed (option set to TRUE).
   */
  inline void TakeCustomReps (const CATBoolean iTakeCustomReps);

public:

  /*
   * Set the two operands
   * An operand of Type 3 is processed as a volume.  
   * An operand of Type 2 is processed as a surface.
   * The second operand should always be a volume.
   */
  HRESULT SetOperands (CAT3DRep* iOperand0, CAT3DRep* iOperand1);

  /*
   * Set the two operands.  
   * @param iOperand0
   *   The first operand.
   * @param iOperand0IsVolume
   *   A flag set to TRUE to process the operand as a volume.
   * @param iOperand1
   *   The second operand.  For clipping, this should be the clipping volume.
   *   The second operand should always be a volume.
   * @param iOperand1IsVolume
   *   A flag set to TRUE to process the operand as a volume.
   */
  HRESULT SetOperands (CAT3DRep* iOperand0, const CATBoolean iOperand0IsVolume, 
                       CAT3DRep* iOperand1, const CATBoolean iOperand1IsVolume);

public:

  /* 
   * Run the operator and calculate the intersection between the two operands.
   */
  HRESULT Run ();

public:

  /*
   * Returns the intersection result.  If the intersection result is one of the input operands, 
   * then the pointer oRep is equal to the input operand pointer. If the intersection result is 
   * empty, then oRep is NULL.
   * The method returns S_OK when it runs successfully and E_FAIL otherwise.
   */
  HRESULT GetResult (CATRep*& oRep);

  /*
   * Returns the number of different connected components in the result (number of surfacic reps).
   */
  inline int GetNbDomains () const ;

  /*
   * Return a diagnostic code when an error occurs.
   * TO BE DEFINED.
   */
  int GetErrorID () const;

protected:

  CATBoolean _DisregardSurfaceVolumeType;  // Default is FALSE.
  CATBoolean _DisregardNormals;
  CATBoolean _TakeCustomReps;
  CATBoolean _ClipWires;                   // Default is TRUE.

  CATMathBox _Box;
  CAT3DRep* _Operand[2];
  int _IsVolume[2];  // Surface or volume operands? (Default is unknown: -1).

  CATIPolyMesh* _PolyMesh[2];
  CATIPolySurfaceVertexPositionLayer* _PositionLayer[2];
  CATPolyMeshVertexNNormalsLayer* _VertexNormalLayer[2];
  CATPolyMeshTriangleVizLayer* _TriangleVizLayer[2];

  CATPolyBars* _PolyBars[2];
  CATPolyBarsBarVizLayer* _BarVizLayer[2];

  CATPolyGriddedPositions* _GriddedPositions[2];
  CATPolyGriddedMeshAndBars* _GriddedOperand[2];

  CAT3DBagRep* _Result;

  int _NbDomains;
  int _ErrorID;

  unsigned int m_Operation;

protected:

  void Clear ();

  CATBoolean IsOperandAVolume (const int iOperand) const;

  // Construction of the operands (CATPolyMesh, CATPolyBars, Layers) from the CAT3DReps.
  HRESULT InitializePolyOperands ();  

  // Construction of the exact arithmetic from the bounding box of the operands.
  HRESULT InitializeExactArithmetic (CATPolyExactArithmetic*& oExactArithmetic);

  HRESULT InitializeGriddedOperands (const CATPolyExactArithmetic& exactArithmetic);

  HRESULT CleanOperands ();

  virtual HRESULT RunBooleanOperator ();

  HRESULT ConstructSurfacicReps (CAT3DBagRep& ioResult);

  // Destruction of the operands.
  HRESULT FinalizePolyOperands ();
  //HRESULT FinalizeExactArithmetic ();
  HRESULT FinalizeGriddedOperands ();    

public:

  // DEPRECATED.
  inline CATBoolean IsRepInOtherRep (const CAT3DRep* iRep) const;

  // DEPRECATED.
  inline void DisregardSurfaceVolumeType (const CATBoolean iDisregard);

  // DEPRECATED.
  inline void ClipWires (const CATBoolean iClipWires);

};


inline void CATPolyVisuBooleanOper::DisregardSurfaceVolumeType (const CATBoolean iDisregard)
{
  _DisregardSurfaceVolumeType = iDisregard;
}

inline void CATPolyVisuBooleanOper::DisregardNormals (const CATBoolean iDisregard)
{
  _DisregardNormals = iDisregard;
}

inline void CATPolyVisuBooleanOper::TakeCustomReps (const CATBoolean iTakeCustomReps)
{
  _TakeCustomReps = iTakeCustomReps;
}

inline void CATPolyVisuBooleanOper::ClipWires (const CATBoolean iClipWires)
{
  _ClipWires = iClipWires;
}

inline int CATPolyVisuBooleanOper::GetNbDomains () const
{
  return _NbDomains;
}

inline void CATPolyVisuBooleanOper::SetBooleanOperation (const int iOperation)
{
  m_Operation = iOperation;
}


// Obsolete.
inline CATBoolean CATPolyVisuBooleanOper::IsRepInOtherRep (const CAT3DRep* iRep) const
{
  return FALSE;
}


#endif

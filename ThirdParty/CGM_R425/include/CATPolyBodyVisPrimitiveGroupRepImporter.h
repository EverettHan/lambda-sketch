// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyVisPrimitiveGroupRepImporter.h
//
//===================================================================
// July 2012  Creation: NDO
//===================================================================
#ifndef CATPolyBodyVisPrimitiveGroupRepImporter_H
#define CATPolyBodyVisPrimitiveGroupRepImporter_H

#include "PolyVizAdapters.h"
#include "CATPolyBodyRepAdapter.h"
#include "CATErrorDef.h"

class VisPrimitiveGroupRep;
//class Vis3DNodeGroupRep;
class CATMathTransformation;
class CAT4x4Matrix; 

class CATPolyBody;
class CATPolyBodyRepDiagnosis;
class CATPolyBodyVisLayer;


/**
This class constructs a CATPolyBody from a VisPrimitiveGroupRep.
It imports the data from the VisPrimitiveGroupRep.  It is not an adapter 
(unlike CATPolyBodyRepAdapter) meaning that the constructed CATPolyBody has no reference 
to the VisPrimitiveGroupRep instance.
*/
class ExportedByPolyVizAdapters CATPolyBodyVisPrimitiveGroupRepImporter
{

public:

  /**
   * Default constructor.
   */
  CATPolyBodyVisPrimitiveGroupRepImporter ();

  ~CATPolyBodyVisPrimitiveGroupRepImporter ();

public:

  /**
   * Constructs a CATPolyBody from a VisPrimitiveGroupRep.
   * @param iRep
   *   The input CATRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (VisPrimitiveGroupRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, 
               int iCellTypes = CATPolyBodyRepAdapter::eFace | CATPolyBodyRepAdapter::eEdge | CATPolyBodyRepAdapter::eVertex);

  /**
   * Constructs a CATPolyBody from a VisPrimitiveGroupRep.
   * @param iRep
   *   The input CATRep.
   * @param iPositionMatrix
   *   An optional position matrix that is applied to the vertex positions.
   * @param iTextureMatrix
   *   An optional texture matrix that is applied to the texture vertex coordinates.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (VisPrimitiveGroupRep& iRep, const CATMathTransformation* iPositionMatrix, const CATMathTransformation* iTextureMatrix,
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, 
               int iCellTypes = CATPolyBodyRepAdapter::eFace | CATPolyBodyRepAdapter::eEdge | CATPolyBodyRepAdapter::eVertex);

public:

  // With CATPolyBodyVisLayer.

  HRESULT Run (VisPrimitiveGroupRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, CATPolyBodyVisLayer* ioVisLayer,
               int iCellTypes = CATPolyBodyRepAdapter::eFace | CATPolyBodyRepAdapter::eEdge | CATPolyBodyRepAdapter::eVertex);

  HRESULT Run (VisPrimitiveGroupRep& iRep, const CATMathTransformation* iPositionMatrix, const CATMathTransformation* iTextureMatrix,
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, CATPolyBodyVisLayer* ioVisLayer,
               int iCellTypes = CATPolyBodyRepAdapter::eFace | CATPolyBodyRepAdapter::eEdge | CATPolyBodyRepAdapter::eVertex);

public:

  // Reserved.  For internal use only.
  HRESULT ApplyPositionMatrix (const CATMathTransformation& iPositionMatrix, CATPolyBody& ioPolyBody) const;

  // Reserved.  For internal use only.
  HRESULT ApplyTextureMatrix (const CATMathTransformation& iTextureMatrix, CATPolyBody& ioPolyBody) const;

public:

  // Do not use.  Get rid of me.
  HRESULT Run (VisPrimitiveGroupRep& iRep, const CAT4x4Matrix* iPositionMatrix, const CAT4x4Matrix* iTextureMatrix,
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, 
               int iCellTypes = CATPolyBodyRepAdapter::eFace | CATPolyBodyRepAdapter::eEdge | CATPolyBodyRepAdapter::eVertex);

  // Do not use.  Get rid of me.
  HRESULT Run (VisPrimitiveGroupRep& iRep, const CAT4x4Matrix* iPositionMatrix, const CAT4x4Matrix* iTextureMatrix,
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, CATPolyBodyVisLayer* ioVisLayer,
               int iCellTypes = CATPolyBodyRepAdapter::eFace | CATPolyBodyRepAdapter::eEdge | CATPolyBodyRepAdapter::eVertex);

  // Do not use.  Get rid of me.
  HRESULT ApplyPositionMatrix (const CAT4x4Matrix& iPositionMatrix, CATPolyBody& ioPolyBody) const;

  // Do not use.  Get rid of me.
  HRESULT ApplyTextureMatrix (const CAT4x4Matrix& iTextureMatrix, CATPolyBody& ioPolyBody) const;

};


#endif // !CATPolyBodyVisPrimitiveGroupRepImporter_H

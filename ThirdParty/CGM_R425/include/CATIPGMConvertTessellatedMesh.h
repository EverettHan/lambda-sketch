#ifndef CATIPGMConvertTessellatedMesh_h_
#define CATIPGMConvertTessellatedMesh_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopOperator.h"

class CATFace;
class CATPolyGeometricForm;
class CATIPolyMesh;
class CATPolyIntegerSetPartition;
class CATPolySegmentLayer;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMConvertTessellatedMesh;

class ExportedByCATGMOperatorsInterfaces CATIPGMConvertTessellatedMesh: public CATIPGMTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMConvertTessellatedMesh();

  // la segm prend des float ? alors penser au cast : (float) toto;
  virtual void SetSegmentationParams(
    double iTolExact = 0.01,      // @NumValidated()
    double iTolSag = 0.3,         // @NumValidated()        
    double iTolAlignExact = 0.01, // @NumValidated()
    double iTolAlign = 5.,        // @NumValidated()
    double iTolSNT = 0.1) = 0;    // @NumValidated()

  // Les faces non generees sont segmentees et recalculees
  virtual void SetSegmKOFaces(CATBoolean iMode = FALSE) = 0;

  // si on split les faces fillets en morceaux ou non ---> Pour la reconstruction seulement (P2S KO car pas de pts dans le tesselle)
  virtual void SetTrimFillets(CATBoolean iMode = FALSE) = 0;

  //
  virtual void SetToleranceAssemble(double iTol = 0.1) = 0; // @NumValidated()

  //
  virtual void SetSegmentation(CATPolyIntegerSetPartition *iPartition, CATPolySegmentLayer *iSegmentLayer) = 0;

  // 0  : tout est OK
  // 1  : Invalid Input data
  // 2  : Error in segmentation step
  // 3  : Error in BuildPolyBod step
  // 4  : Error in Reconstruction step
  // 5  : Error in Get Canonicity of faces
  // 6  : Error in update Journal
  virtual int RunOperator() = 0;

  //
  virtual CATBody *GetBody() = 0;

  //
  virtual int GetNbFaces() = 0;
 
  //
  virtual void Get_Canonicity_Info(CATFace *iFace, CATPolyGeometricForm &oForm) = 0;

  //if oRadius = 0. :No Fillet
  virtual void Get_Info_if_face_is_fillet(CATFace *iFace, double &oRadius) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMConvertTessellatedMesh(); // -> delete can't be called
};

ExportedByCATGMOperatorsInterfaces CATIPGMConvertTessellatedMesh *CATPGMCreateConvertTessellatedMesh(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATIPolyMesh *iPolyMesh);

#endif /* CATIPGMConvertTessellatedMesh_h_ */

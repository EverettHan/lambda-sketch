//==================================================================================
// Copyright Dassault Systemes Provence 2010-2019, All Rights Reserved
//==================================================================================
//
// CATPolyBuildPartitionOfMesh.h
//
//==================================================================================
//
// Usage notes: 
//
//==================================================================================
// 27 Mars,  2019 : ANR : Création (deplacement de CATCloudCGMUtilities\ProtectedInterfaces\CATPolyBuildPartitionOfMesh.h
//==================================================================================
#ifndef CATPolyBuildPartitionOfMesh_H
#define CATPolyBuildPartitionOfMesh_H
 
#include "CATPolyCanonicOperators.h"
 
#include "CATIPolyMesh.h"
#include "CATPolyBody.h"
#include "CATMapOfPtrToPtr.h"

#include "CATPolySegmentLayer.h"
#include "CATPolyIntegerSetPartition.h"
#include "CATPolyCanonicDetectOper.h"

  
class CATMathPoint;
class CATPolyVertex;
class CATSoftwareConfiguration ;
  
class ExportedByCATPolyCanonicOperators CATPolyBuildPartitionOfMesh
{
public:

  //Constructeur
  CATPolyBuildPartitionOfMesh(CATIPolyMesh *iPolyMesh, CATSoftwareConfiguration *iConfig);
  
  //Destructeur
  virtual ~CATPolyBuildPartitionOfMesh();

  //
  void SetSegmentationParams(const float iTolExact=0.01,      // @NumValidated()
                             const float iTolSag=0.3,         // @NumValidated()
                             const float iTolAlignExact=0.01, // @NumValidated()
                             const float iTolAlign=5.,        // @NumValidated()
                             const float iTolSNT=0.1) ;       // @NumValidated()

  // par defaut iMode = TRUE : On calcule nous meme la sag
  void ForceComputeSag(CATBoolean iMode) ;

  //maillage pas vraiment tesselle ou grossier ... Pr CPU dans les etapes de marge
  //WithAllStep = FALSE : On donne que l'init
  //WithAllStep = TRUE : On fait les etapes de merges mais on limite les iteratoins des que la zone est complexe
  void SetProcessingCoarseMesh(CATBoolean iWithAllStep = TRUE) ;

  //
  int Run() ;

  //
  int RunOnSelectedTriangles (const CATListOfInt &itriangles);

  //
  void GetResult(CATPolyIntegerSetPartition *&oPartition, CATPolySegmentLayer *&oSegmentLayer) ;

  // On rend la liste de triangles qui ne sont pas pris dans la segmentation
  void GetSmallAngleTriangles(CATListOfInt &oListOfTr) ;

  // Get the sag tolerance used when fitting canonic surfaces to segmented
  // faces. When _AutoComputeSag is true, this may not be the same as the value
  // of iTolSag passed to SetSegmentationParams.
  double GetTolSag() const;

private:

  //-------- Data: 
  CATIPolyMesh*  _PolyMesh;
  CATSoftwareConfiguration *_Config ;

  float _TolExact, _TolSag, _TolAlignExact, _TolAlign, _TolSNT ;
  CATBoolean _AutoComputeSag ;
  double _TolSagUsed;

  CATPolySegmentLayer *_SegmentLayer ;
  CATPolyIntegerSetPartition *_Partition ;
  CATPolyCanonicDetectOper * _SegmentationOperator ;

  CATListOfInt _SmallAngleTriangles ;
  CATBoolean _ProcessingCoarseMesh, _WithAllStep  ;
};




#endif


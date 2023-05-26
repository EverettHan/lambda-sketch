//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//==============================================================================================================

// CATPolyDEnvelopeEroder : Skeleton extraction from a Volumetric Representation of a D-Envelope

//==============================================================================================================
// Creation : DPS , 04 / 04 / 2006
//==============================================================================================================

#ifndef CATPolyDEnvelopeEroder_H
#define CATPolyDEnvelopeEroder_H


#include "CATErrorDef.h"          // HRESULT definition
#include "PolyDual.h"             // export definition
#include "CATTolerance.h"

class CATIPolyFactory;
class CATIPolyMesh;
class CATVRepTree;
class CATPolyIEOper;
class CATPolyMedialAxisContext;
class CATPolyMedialAxisScenario;

class CATCGMOutput;
class CATUnicodeString;
class CATSoftwareConfiguration;

class ExportedByPolyDual CATPolyDEnvelopeEroder
{

public :

  //==============================================================================================================
  // Deprecated constructor
  // MedialAxis creator : unsafe method
  // iVRep is a mandatory not null argument, corner clients have to verify the type of GradientField
  // iPolyMesh is a mandatory not null argument
  // iDilationOffsetValue allows to search only the isosurface for an input constraint value
  // If iSoftwareConfiguration==NULL -> behavior is like open config (last CGMLevel)
  //==============================================================================================================
  static CATPolyDEnvelopeEroder * CreateDEnvelopeMedialAxis(CATVRepTree & iVRep,
                                                            CATIPolyFactory & iPolyFactory, CATIPolyMesh & iPolyMesh,
                                                            double iDilationOffsetValue, double iDilationTolerance,
                                                            CATSoftwareConfiguration * iSoftwareConfiguration = NULL, 
                                                            const CATTolerance & iTol = CATGetDefaultTolerance());

  //==============================================================================================================
  // Deprecated constructor
  // MedianMesh creator : unsafe method
  // iVRep is a mandatory not null argument, corner clients have to verify the type of GradientField
  // iPolyMesh is a mandatory not null argument
  // iDilationOffsetValue allows to search only the isosurface for an input constraint value
  // If iSoftwareConfiguration==NULL -> behavior is like open config (last CGMLevel)
  //==============================================================================================================
  static CATPolyDEnvelopeEroder * CreateDEnvelopeMedianMesh(CATVRepTree & iVRep,
                                                            CATIPolyFactory & iPolyFactory, CATIPolyMesh & iPolyMesh,
                                                            double iDilationOffsetValue, double iDilationTolerance,
                                                            CATSoftwareConfiguration * iSoftwareConfiguration = NULL, 
                                                            const CATTolerance & iTol = CATGetDefaultTolerance(),
															                              int iModeExtractMedian=0);

  //==============================================================================================================
  // MedialAxis creator : unsafe method
  // iVRep is a mandatory not null argument, corner clients have to verify the type of GradientField
  // iPolyMesh is a mandatory not null argument
  // iDilationOffsetValue allows to search only the isosurface for an input constraint value
  // If iSoftwareConfiguration==NULL -> behavior is like open config (last CGMLevel)
  //==============================================================================================================
  static CATPolyDEnvelopeEroder * CreateDEnvelopeMedialAxis(CATVRepTree & iVRep, CATIPolyMesh & iPolyMesh,
                                                            double iDilationOffsetValue, double iDilationTolerance,
                                                            CATSoftwareConfiguration * iSoftwareConfiguration = NULL, 
                                                            const CATTolerance & iTol = CATGetDefaultTolerance());

  //==============================================================================================================
  // MedianMesh creator : unsafe method
  // iVRep is a mandatory not null argument, corner clients have to verify the type of GradientField
  // iPolyMesh is a mandatory not null argument
  // iDilationOffsetValue allows to search only the isosurface for an input constraint value
  // If iSoftwareConfiguration==NULL -> behavior is like open config (last CGMLevel)
  //==============================================================================================================
  static CATPolyDEnvelopeEroder * CreateDEnvelopeMedianMesh(CATVRepTree & iVRep, CATIPolyMesh & iPolyMesh,
                                                            double iDilationOffsetValue, double iDilationTolerance,
                                                            CATSoftwareConfiguration * iSoftwareConfiguration = NULL, 
                                                            const CATTolerance & iTol = CATGetDefaultTolerance(),
															                              int iModeExtractMedian=0);
															

  virtual ~CATPolyDEnvelopeEroder();


  //=============================================================================
  // Client can customize the minimal angle between 2 consecutive gradient fields,
  // to trigger the skeleton computation.
  // Default minimal angle is CATPIBY2 (MinAngleCosinus = 0)
  // iMinAngleCosinus must be positive (angle between 0 and CATPIBY2)
  void SetMinAngleCosinus(double iMinAngleCosinus);


  //=============================================================================
  // Activate the treatment to make the result Manifold, cleaning unexpected parts
  void ActivateManifoldCleanerMode();


  //==============================================================================================================
  // To activate the mode generating OBJ file with quads and/or tiangles
  void ActivatePolygonOBJGeneration(const CATUnicodeString &iFileName);

  
  //==============================================================================================================
  // To activate the creation of specific info on generated mesh vertices
  void ActivateVtxMAInfoTag();

  
  //==============================================================================================================
  // To activate the MultiTask Mode to be candidate to MultiThread behavior
  void ActivateMultiTaskMode();


  //=============================================================================
  // Execution de l'extraction d'isosurface a partir de la VRep courante
  HRESULT Run();


  // Recuperation de l'erreur de fin de transaction (typiquement, incapacite a orienter le Mesh final)
  // ==============================================
  HRESULT GetEndTransactionDiag();


  // Lecture des infos binaires sur un sommet du Mesh
  // ================================================
  void GetVtxInfo(int iMeshVtxIndex, int &oNonManifoldInfo, int &oOutDilationInfo);



protected :

  // Constructor (protected use only)
  CATPolyDEnvelopeEroder(CATSoftwareConfiguration * iSoftwareConfiguration,
    CATPolyMedialAxisContext & iMAContext);


private:


  //==============================================================================================================
  // DATA

  CATSoftwareConfiguration  * _SoftwareConfiguration;

  CATPolyMedialAxisScenario & _MAScenario;
  CATPolyMedialAxisContext  & _MedAxisContext;
  CATPolyIEOper             * _IEOperImpl;

  int                         _ManifoldCleanerMode;

  // Callbaks pour le cleaner
  static CATBoolean EroderTriangleExtractionRule(void * iEroderContext, int iTriangleIndex_1_to_n);
  static CATBoolean EroderPropagationBarRule(void * iEroderContext, int iVertexIndex_1_to_n[2], int iTriangleIndex_1_to_n[2]);

  struct EroderContext {                
    CATIPolyMesh &_Mesh;
    CATPolyDEnvelopeEroder &_DEnvelopeEroder;
    EroderContext(CATIPolyMesh &iMesh, CATPolyDEnvelopeEroder &iDEnv) :
    _Mesh(iMesh), _DEnvelopeEroder(iDEnv) 
    {
    }
  };

  // ----------------------------------------------------------------------------
  // Compute the treatment to make the result Manifold, cleaning unexpected parts
  HRESULT ComputeManifoldCleaner();
};
  

#endif

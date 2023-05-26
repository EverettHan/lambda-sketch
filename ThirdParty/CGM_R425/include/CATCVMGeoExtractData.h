#ifndef CATCVMGeoExtractData_h 
#define CATCVMGeoExtractData_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATCVMGeoExtract :
// Classe générique permettant la gestion du CopyPaste
//
//=============================================================================
// mars    2007  Création                    Etienne Bartholomot
//=============================================================================
#include "CATCVMGeoObjects.h"
#include "CATBaseUnknown.h"
#include "CATCGMNewArray.h"

#include "CATCollec.h"
#include "CATDataType.h"
#include "CATUnicodeString.h"

#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATVertex.h"

#include "CATListOfInt.h"
#include "CATMathTransformation.h"
#include "CATMathBox.h"

#include "CATCVMObject.h"
#include "CATMathPlane.h"
#include "CATMathLine.h"
#include "CATLISTP_CATMathLine.h"
#include "CATBoolean.h"
#include "CATTopDefine.h"
#include "CATString.h"
#include "CATMathSetOfPoints.h"

#include "CATCVMGeoContainer.h"
#include "CATCGMOutput.h"

#include "ListPOfCATCVMGeoCopilot2Magnet.h"
#include "CATCVMGeoCopilot2.h"

class CATCell;
class CATFace;
class CATEdge;
class CATCVMBody;
class CATMathPoint;
class CATMathVector;
class CATCVMPSContainer;
class CATCVMInstancePath;
class CATCVMGeoMesh;
class CATCVMGeoCopy;
class CATCGMJournalList;

class ExportedByCATCVMGeoObjects CATCVMGeoExtractData : public CATBaseUnknown
{
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
  public:
  CATDeclareClass;

  enum Type
  {
    _CopyPaste = 1,
    _Insert    = 2
  };
  
  //------------------------------------------------------------------------------
  // Create CATCVMGeoExtractData
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoExtractData *Create(CATCVMGeoContainer *iContainer);
  public:
  static CATCVMGeoExtractData *Create(CATCVMPSContainer          *iContainer,
                                      CATCVMGeoExtractData::Type  iType = CATCVMGeoExtractData::_CopyPaste);
  //------------------------------------------------------------------------------
  // Create CATCVMGeoExtractData with a previously imported RootReference
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoExtractData *Create(CATCVMPSContainer *iContainer,
                                      CATUnicodeString  &iReferenceName );
                                      
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoExtractData(CATCVMGeoContainer *iContainer);
  CATCVMGeoExtractData(CATCVMPSContainer          *iContainer,
                       CATCVMGeoExtractData::Type  iType = CATCVMGeoExtractData::_CopyPaste);
  
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoExtractData();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  //CATBoolean IsA(CATCVMObjectType iObjectType);
  //CATCVMObjectType GetType();
  CATCVMGeoExtractData::Type GetExtractDataType();

  //------------------------------------------------------------------------------
  // Release
  //------------------------------------------------------------------------------
  public:
  static void Release(CATCVMGeoExtractData *ioObject); //= NULL);

  //------------------------------------------------------------------------------
  // Release data
  //------------------------------------------------------------------------------
  public:
  virtual void ReleaseData();

  //------------------------------------------------------------------------------
  // Extracted Object (CVMBody) List
  //------------------------------------------------------------------------------
  public:
  void GetObjectList(ListPOfCATCVMObject & oObjectList);

  //------------------------------------------------------------------------------
  // CVMBody for Interface definition
  //------------------------------------------------------------------------------
  public:
  CATCVMObject * GetInterface();
  
  //------------------------------------------------------------------------------
  // Reference Plane definition according with the interface
  //------------------------------------------------------------------------------
  public:
  HRESULT GetReferencePlane(CATMathPlane &oMathPlane );

  //------------------------------------------------------------------------------
  // Set Reference Plane
  //------------------------------------------------------------------------------
  private:
  HRESULT SetReferencePlane(CATMathPoint  &iOrigin,
                            CATMathVector *iFirstVector  = NULL,
                            CATMathVector *iSecondVector = NULL );

  //------------------------------------------------------------------------------
  // Reference Plane definition according with the interface
  //------------------------------------------------------------------------------
  public:
  HRESULT SetReferencePoint(CATMathPoint &iMathPoint );

  //------------------------------------------------------------------------------
  // Is Intelligent Merge possible
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsIntelligentMergeAllowed();
  //------------------------------------------------------------------------------
  // View Plane definition mandatory for right Reference point Computation
  //------------------------------------------------------------------------------
  public:
  void SetViewPlane(CATMathPlane &iMathPlane );

  //------------------------------------------------------------------------------
  // Target Plane (mouse point, normal to the target interface, taking care about rotation
  //------------------------------------------------------------------------------
  public:
  void SetTargetPlane(CATMathPlane &iMathPlane, CATBoolean iResetTransfo = FALSE );
  
  //------------------------------------------------------------------------------
  // Set the TargetInterface
  //------------------------------------------------------------------------------
  public:
  void SetTargetInterface(CATCVMObject * iTargetInterface, CATBoolean iResetTransfo = FALSE);
  
  //------------------------------------------------------------------------------
  // Init TargetInterface choice
  //------------------------------------------------------------------------------
  public:
  void InitInterface();
 
  //------------------------------------------------------------------------------
  // Get the TargetInterface
  //------------------------------------------------------------------------------
  public:
  CATCVMObject * GetTargetInterface();
 
  //------------------------------------------------------------------------------
  // Get the Target Body
  //------------------------------------------------------------------------------
  public:
  CATCVMBody  * GetTargetBody();
 
  //------------------------------------------------------------------------------
  // Target Plane definition 
  //------------------------------------------------------------------------------
  public:
  HRESULT GetTargetPlane(CATMathPlane &oMathPlane );
  
  //------------------------------------------------------------------------------
  // Available magnet position
  //------------------------------------------------------------------------------
  public:
  HRESULT GetMagnetList(ListPOfCATCVMGeoCopilot2Magnet & oListMagnet);
  
  private:
  HRESULT ComputeMagnetPosition();

  //------------------------------------------------------------------------------
  // Plane modification regardin Absolute Z axis
  //------------------------------------------------------------------------------
  private:
  HRESULT PlaneAdaptation (CATMathPlane &iViewPlane,CATMathPlane &iMathPlane,CATMathPlane &oMathPlane,
                           CATMathPlane *RefPlane=NULL);

  //------------------------------------------------------------------------------
  // Target View Plane to get the material direction 
  //------------------------------------------------------------------------------
  public:
  void SetTargetViewPlane(CATMathPlane &iMathPlane );
  
  //------------------------------------------------------------------------------
  // Tramsformation matrix from Reference Plane to Target Plane
  //------------------------------------------------------------------------------
  public:
  HRESULT GetTransformation(CATMathTransformation &oMathTransformation );

  //------------------------------------------------------------------------------
  // Set temporary transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT SetTemporaryTransformation(CATMathTransformation &iTemporaryTransformation );

  //------------------------------------------------------------------------------
  // Get temporary transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT GetTemporaryTransformation(CATMathTransformation &oTemporaryTransformation );

  //------------------------------------------------------------------------------
  // Commit temporary transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT CommitTemporaryTransformation();

  //------------------------------------------------------------------------------
  // Reset temporary transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT ResetTemporaryTransformation();

  //------------------------------------------------------------------------------
  // Set the interface: CGM Body and list of CGM Edges
  //------------------------------------------------------------------------------
  public:
  void AddInterface(CATCVMBody * CVMBody_Input     , ListPOfCATCell &iCGMInterFaceList 
                   ,CATCVMBody * CVMBody_Extracted , ListPOfCATCell &iCGMSewList
                                                   , CATListOfInt   &iCATSideList);
  //------------------------------------------------------------------------------
  // Get the Outside of the original interface for a given Sew extracted Edge
  //------------------------------------------------------------------------------
  public:
  CATSide GetSewCATSide (CATCell * iCGMEdge, CATCell * iCGMFace, CATCell *&oCGMEdge, CATCGMJournalList * iCGMJournalList=NULL ) ; 
  void SetSewImage (CATCVMGeoCopy * ipCVMCopy=NULL , CATMathTransformation * iMathTransfo=NULL ) ; 
  
  private:
  CATMathLine * GetSewZenith  (CATFace * iCGMFace, CATEdge * iCGMEdge);
  //------------------------------------------------------------------------------
  // add a CVMObject to the list of Extracted CVM Body 
  //------------------------------------------------------------------------------
  public:
  void AddCVMObjectToList(CATCVMObject * iCVMObject,int iIsToDelete=0);

  //------------------------------------------------------------------------------
  // Get the ImageList of Object to be pasted into the TargetGeoContainer
  //------------------------------------------------------------------------------
  public:
  HRESULT GetImageList(CATCVMInstancePath  *iCVMInstancePath,
                       ListPOfCATCVMObject &oCVMClipboardedObjects,
                       ListPOfCATCVMObject &oCVMTargetObjects);
  
  //------------------------------------------------------------------------------
  // recover the CVMGeoContainer definition of the ExtractData
  //------------------------------------------------------------------------------
  public:
  CATCVMGeoContainer * GetCVMGeoContainer();

  //------------------------------------------------------------------------------
  // recover the CVMPSContainer definition of the ExtractData
  //------------------------------------------------------------------------------
  public:
  CATCVMPSContainer * GetCVMPSContainer();

  //------------------------------------------------------------------------------
  // Set the CVMPSContainer definition of the ExtractData
  //------------------------------------------------------------------------------
  private:
  void SetCVMPSContainer(CATCVMPSContainer *iCVMPSContainer);

  //------------------------------------------------------------------------------
  // transfer the Extract definition to a Clipboard
  // (new CVMContainer (Geo or PS) and GeoFactory/GeoFactories)
  //------------------------------------------------------------------------------
  public:
  HRESULT TransferToClipBoard(CATCVMContainer * iCVMContainer );
  //------------------------------------------------------------------------------
  // evaluate if the current transformation will produce a pasted body inside the modele boundaries
  //------------------------------------------------------------------------------
  public:
  HRESULT GetOutOfScaleFailure();
  private:
  HRESULT IsBoxContaining (CATCVMReference       * iCVMReference,
                           CATMathBox            & iMathBox,
                           CATMathTransformation & iCVMInstance_Transformation);
  HRESULT IsBoxContaining (CATCVMBody            * iCVMBody,
                           CATMathBox            & iMathBox,
                           CATMathTransformation & iCVMInstance_Transformation);
  HRESULT IsBoxContaining (CATCVMGeoMesh         * iCVMGeoMesh,
                           CATMathBox            & iMathBox,
                           CATMathTransformation & iCVMInstance_Transformation);
  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L) const;

  //------------------------------------------------------------------------------
  // compute the reference plane regarding the view plane
  //------------------------------------------------------------------------------
  private:
  void ComputeReferencePlane();
  //------------------------------------------------------------------------------
  // compute the internal reference plane regarding the sew
  // RI  0637109B, 0637747B
  //------------------------------------------------------------------------------
  private:
  HRESULT GetSewReferencePlane(CATMathPlane &oPointsPlane);


  //------------------------------------------------------------------------------
  private:
  CATCVMGeoExtractData(const CATCVMGeoExtractData &);
  void operator = (const CATCVMGeoExtractData &);

  protected:
  CATCVMGeoExtractData();

  //------------------------------------------------------------------------------
  // InitData
  //------------------------------------------------------------------------------
  private:
  void InitData();

  private:
  CATCVMGeoContainer *_CVMGeoContainer ;
  CATCVMPSContainer  *_CVMPSContainer ;

  CATCVMGeoExtractData::Type  _Type;
  
  ListPOfCATCVMObject _ExtractedCVMObjectsList;
  CATListOfInt        _ExtractedCVMObjectsInfoList;
  
  ListPOfCATCVMObject _CVMImageObjectList;
  CATListOfInt        _CVMOriginalTagList; //CATRCOLL(CATULONG32)
  CATCVMObject       *_CVMTargetInterface;
  
  ListPOfCATCVMObject    _CVMInterFaceList;
  ListPOfCATCVMGeometry  _SewCVMEdgeList;
  CATLISTP(CATCell)      _SewCGMEdgeList;
  CATListOfInt           _SewCATSideList;
  CATLISTP(CATMathLine)  _SewNormalList;
  CATLISTP(CATMathLine)  _SewNormalImageList;
    
  ListPOfCATCVMGeometry  _SewCVMVertexList;
  ListPOfCATCVMGeometry  _SewCVMEdgeFaceList;
  
  CATMathBox             _MathBoxForReferencePlane;
  CATBoolean             _MathBoxForReferencePlaneHasBeenComputed;
  CATMathSetOfPoints     _LowerMidPoints;
  
  ListPOfCATCVMGeoCopilot2Magnet   _ExtractedMagnetList;
 
  
  CATMathPlane        _ReferencePlane    ;
  CATMathPlane        _TargetPlane  ;
  CATMathPlane        _PrevTargetPlane  ;
  CATMathPlane        _PrevReferencePlane    ;

  CATMathTransformation _DeltaTransformation  ;
  CATMathTransformation _TemporaryTransformation  ;
  CATBoolean            _TransformationIsUpToDate  ;
  
  CATMathPlane        _ViewPlane  ; 
  CATMathPlane        _TargetViewPlane  ; 
  CATMathPoint        _ReferencePoint;
  double              _TolOutOfScale ; 
  double              _ModelSize ; 
  
  int                 _idxInterface;
  CATBoolean          _IntelligentMergeIsPossible;
  //int                 _InstanceMode;
  
  CATBoolean          _ViewPlaneHasBeenSet;
  
  CATBoolean          _TargetPlaneHasBeenSet;
  CATBoolean          _TargetViewPlaneHasBeenSet;
  CATBoolean          _PrevTargetPlaneHasBeenSet;
  CATBoolean          _PrevReferencePlaneHasBeenSet;

  CATBoolean          _InterfaceHasBeenSet ;

  CATBoolean          _ReferencePlaneHasBeenComputed ;
  CATBoolean          _ReferencePointHasBeenSet;
  CATBoolean          _ExtractDataHasBeenClipboarded ;
};
#endif

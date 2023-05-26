// COPYRIGHT Dassault Systemes 2004
//===================================================================
/*
=============================================================================

 DESCRIPTION : Common functions for Ruled and Free Form Top Shell Unfold

=============================================================================
*/

//=============================================================================
//
// <ClassName>: CATTopShellUnfoldCommon
//
//=============================================================================
// Usage Notes:
//  Do not use
//=============================================================================
// Sept 2004   Creation                 SUH
// Oct  2013   Add Method ForSticker    JSX
//=============================================================================

#ifndef CATTopShellUnfoldCommon_H
#define CATTopShellUnfoldCommon_H

#include "FrFTopologicalOpe.h"    // exported by
#include "CATTopShellUnfold.h"
#include "ListPOfCATBody.h"
#include "CATListOfCATGeometries.h"
#include "CATListOfCATSurfaces.h"
#include "ListPOfCATFace.h"
#include "CATLISTP_CATMathTransformation.h"
#include "CATCell.h"
#include "CATMathTransformation2D.h"
#include "CATMathTransformation.h"
#include "CATCGMOutput.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "CATListOfDouble.h"

class CATGeoFactory;
class CATBody;
class CATFrFNurbsBipar;
class CATSurface;
class CATFace;
class CATPCurve;
class CATCrvLimits;
class CATMathPoint;
class CATMathTransformation;
class CATShell;
class CATPlane;
class CATPoint;
class CATVertex;
class CATLayDownOperator;
class CATWire;
class CATMathAxis;
class CATTopShellUnfoldTransferImpl;
class CATTopTearEdges;
class CATIPolyMesh;

typedef HRESULT(*FMTMeshingFunc)(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody,
  CATIPolyMesh*& oFMTMesh, CATLISTP(CATFace)& oFacesFMT, CATLISTP(CATCell)& oCellsUV, CATListOfDouble& oU, CATListOfDouble& oV);

class ExportedByFrFTopologicalOpe CATTopShellUnfoldCommon : public CATTopShellUnfold
{
public:
  
/** @nodoc 
  * cannot be called
  * use CATCreateTopShellUnfold to create the operator
  */

  // Constructor
  CATTopShellUnfoldCommon(CATGeoFactory      * iFactory,
                          CATTopData         * iTopData,
                          CATBody            * iBody,
                          CATShell           * iShell,
                          CATLISTP(CATEdge)  * iEdgeList);

  // Constructor notes that _Result has been provided, not computed.
  // This signifies that no unfolding computations shall take place. 
  // Only RunTransfer can happen.
  CATTopShellUnfoldCommon(CATGeoFactory     * iFactory,
                          CATTopData        * iTopData,
                          CATBody           * iBody,
                          CATShell          * iShell,
                          CATBody           * iFlattenedBody,
                          CATLISTP(CATFace) & iListOfInputFaces,
                          CATLISTP(CATFace) & iListOfFlattenedFaces);
  
  // Destructor
  virtual ~CATTopShellUnfoldCommon();

  // Changes the method of development action
  virtual void SetUnfoldMethod(CATShellUnfoldMethod iMethod);

  //Set parameters to define location of unfolded body
  void SetUnfoldLocation(CATPlane* iPlaneForUnfolding, CATPoint* iOrigin = NULL);

  //Set edges to tear
  //iEdgesToTear:     Edges to tear in case of ambiguity
  //                  If this is not sufficient to remove all ambiguities, and
  //                  later, one doesn't remove all ambiguities using SetEdgesToTear again, the
  //                  remaining ambiguities are removed by automatically choosing additional
  //                  edges to tear. This automatic selection depends on order of faces in the 
  //                  "list of faces"/"shell" if provided to the constructor, else on the shell
  //                  of Body provided to the constructor
  //
  //oNbAmbiguities:   Number of ambiguities, still unresolved with iEdgesToTear
  //
  //oCandidateEdgesToTear: Edges which can be selected further to reduce ambiguity
  //
  //oInvalidInputEdges:    * Edges out of iEdgesToTear, which cannot be used for tearing.
  //                         Example: Common edge in a shell of two faces, since it will create
  //                         disconnected result  
  //                       * It can be same as iEdgesToTear if iEdgesToTear cannot be, together,
  //                         taken for tearing.
  //                         Example: All internal edges in a closed shell                      
  CATBoolean SetEdgesToTear(const CATLISTP (CATEdge)  & iEdgesToTear          ,
                                  CATLONG32           & oNbAmbiguities        ,
                                  CATLISTP(CATEdge)   & oCandidateEdgesToTear ,
                                  CATLISTP(CATEdge)   & oInvalidInputEdges    ,
                                  CATLISTP(CATEdge)  *  ioMandatoryCandidates = 0,
                                  CATLISTP(CATEdge)  *  ioOptionalCandidates  = 0);

  // Returns the edges which are to be compulsorily torn
  CATLISTP(CATEdge) GetEdgesMustToTear();

  //Set parameters to define an initial axis system
  // iVertxOrign: Vertex on initial shell to be taken as origin
  // iEdgeX:      An edge bounded by iVertxOrign, this defines X-axis (N.B. Currently, this should ONLY be one of the border edges or edges-to-tear)
  // iFace:       A face bounded by iEdgeX, this governs Y-axis. Necessary to give if iEdgeX is not a border edge
  int SetInitialLocation(CATVertex * iVertxOrign, CATEdge * iEdgeX, CATFace * iFace = 0);

  //Set parameters to define location of unfolded shell
  // iFixedWire:will keep the same location, tangent and normal to shell at its beginning vertex
  // iFixedWire is a Body containing only one Wire
  // It must be possible to laid down iFixedWire on shell (compatible with CATLayDownOperator).
  // First Edge of iFixedWire should not lie on a Sharp Edge.

  void SetInitialLocation(CATBody* iFixedWire);

  //Set target axis system; to be called only after InitialLocation has been set, throws otherwise.
  // iTargetPlane: Plane defining a target axis system  
  void SetTargetLocation(const CATMathPlane * iTargetPlane);

  virtual void CreateUnfoldedShellTrackingAttribute(CATBoolean iDoCreate);

  // Set options for output journal
  void SetJournalOptions(const CATBoolean iDifferentiateTearedEdges=FALSE, const CATCGMJournal::Type iItemType = CATCGMJournal::Creation);
  
  // Returns the result of the transformation  
  //CATBody* GetResult();  use TopOperator's

  //Operate wire or vertex transfert from fold to unfold, or reverse. Input elements are layed by the operator. Output elements are not.
  // iBody : Body containing elements to transfert. It can be multi-domain from R18
  // oBody : Resulting body (created by the operator)
  // iReport : Journal
  // iReverse : FALSE by default, TRUE if the input elements are to lay on the previously unfolded body
  void RunTransfer(CATBody * iBody, CATBody *& oBody,  CATCGMJournalList * iReport, CATBoolean iReverse=FALSE);

  // Change the lying on tolerance for transfert
  void SetTransfertTolerance(double iTol);

  // Get 2D transformation
  // return resulting face if transformation is found
  CATFace * GetTransformation2D(CATFace                 * iFace            ,
                                CATMathTransformation2D & oTransformation2D);

  /**
  * GetFacesInAssembleOrder
  * To get the folded and flattened faces mapped in assembly order
  */
  void GetFacesInAssembleOrder(CATLISTP(CATFace) & iListOfFoldedFaces, CATLISTP(CATFace) & iListOfUnfoldedFaces);

  //=========================================================================================
  // New Methods
  //=========================================================================================  
  
  // --- Requested by GSD, ONLY USEFUL FOR R16. Use it to define the initial axis system ---
  // Takes a plane, tangential to a face, subject to the following condition:
  // o  Origin of the plane should be near enough (within 0.1 mm) to the shell so that it 
  //    can be laid down on a face. 
  // o  Also, this lay down should not occur on an Edge-to-tear (which is a candidate for 
  //    future versions of FreeForm operator), because it will make positioning unstable as 
  //    there are going to be two images of the Edge-to-tear (one per bounded face) in the
  //    flattened skin. In such case, one should specify the support face to avoid a throw.
  virtual int SetInitialLocation(const CATMathPlane & iIniPlane,
                                 CATFace * iSuppFace = NULL);

  //------------------------------------------------------------------------------------------
  // Methods for pre-visualization of distortion, only useful for Free Form Shell Unfold
  //------------------------------------------------------------------------------------------

  //Provides important tesselation statistics
  //Returns non-zero if called before Run
  virtual int GetPreviewStats(int & oNbTriangles, int & oNbNodes);

  //Provides flattening data:
  // ioUV            : Parametric values for nodes scaled to unit square. Size = 2 * NbNodes. Not filled if NULL
  // ioXYZAfter      : 3d flattened coordinates. Size = 3 * NbNodes. Not filled if NULL
  // ioXYZBefore     : 3d un-flattened (of input skin) coordinates. Size = 3 * NbNodes. Not filled if NULL
  // ioNormalAfter[3]: 3D Normal of the plane of flattened skin. Not filled if NULL
  // ioNormalsBefore : 3D Normals of the input skin at nodes. Size = 3 * NbNodes. Not filled if NULL
  // ioTriangles     : Indices of bounding nodes of each triangle. Size = 3 * NbTriangles. Not filled if NULL
  //
  //Returns non-zero if called before Run
  virtual int GetPreviewData( double * ioUV              ,
                              double * ioXYZAfter        ,
                              double * ioXYZBefore       ,
                              double   ioNormalAfter  [3],
                              double * ioNormalsBefore   ,
                              int    * ioTriangles       );

  //Triggers Distortion computation
  //Returns non-zero if called before Run or invalid iType
  virtual int ComputeDistortion(
                                const int    & iType, //0 for specifying length, 1 for angle or 2 for area distortion
                                      double & oMinDistortion,
                                      double & oMaxDistortion, 
                                      double & oMedianDistortion);
  
  //Provides distortion value at a node of tesselation
  //Returns non-zero if called before ComputeDistortion or invalid iNodeIndex is used
  virtual int GetDistortionAtNode(const int &iNodeIndex, double & oDistortion);
  
  //To play with the distortion if the requested type is not angle
  //
  //iRatio: in [0,1], to scale distortion to desired value. This ratio indicates the
  //        fraction of points with positive/stretching distortion.
  //
  //Examples:
  //iRatio = 0   corresponds to only shrinking (i.e. the distortion at 0% of the computation
  //             points is positive, i.e. the distortion is negative at all the points). 
  //             This means the flattened body is smaller than the input body.
  //iRatio = 1   corresponds to only stretching (i.e. the distortion at 100% of the 
  //             computation points is positive). This means the flattened body is larger
  //             than the input body. 
  //iRatio = 0.5 corresponds to even distortion (i.e. there are as many (50%) points with 
  //            stretching distortion as there are with shrinking distortion)  
  //An intermediate value, say 0.85, means 85% points have stretching distortion, which
  //implies 15% of the points have shrinking distortion
  //
  //
  //Returns non-zero if called before ComputeDistortion or invalid iRatio or ...
  //if requested distortion type is Angle type in ComputeDistortion
  virtual int ApplyCorrection( const double & iRatio           ,
                                     double & oMinDistortion   ,
                                     double & oMaxDistortion   ,
                                     double & oMedianDistortion);
  
  //Provides distortion value at a point by giving its parametric values
  //Returns non-zero if called before ComputeDistortion or if point(iU, iV) is out of mesh
  virtual int GetDistortionForUV(const double & iU, // iU in [0,1]
                                 const double & iV, // iV in [0,1]
                                       double & oDistortion);

  //------------------------------------------------------------------------------------------
  // New Result retrieval methods
  //------------------------------------------------------------------------------------------

  //Provides the output image of a cell in the input body or vice-versa
  //Requested by ship-building team, to avoid use of journal.
  //
  //iCell: The Cell whose image is needed, if iReverse is FALSE, iCell should be in the 3D body
  //oCellsInOtherImage: The image Cells in the flattened body, if iReverse is FALSE, these will be in flattened body
  //iReverse : FALSE by default, TRUE if the iCell is in flattened body and oCellsInOtherImage are needed in 3D body
  //
  //Returns non-zero if iCell is not in 3D body if iReverse is FALSE, or if iCell is not in flattened body if iReverse is TRUE
  virtual int GetCellImage(CATCell * iCell, CATLISTP(CATCell) &oCellsInOtherImage, CATBoolean iReverse = FALSE);

  //Operate wire or vertex transfer from fold to unfold, or reverse. Input elements are layed by the operator. Output elements are not.
  // iBodiesToTransfer : Bodies to transfer.
  // ioBodiesTransferred : Resulting bodies (created by the operator)
  // iReport : Journal
  // iReverse : FALSE by default, TRUE if the input elements are to lay on the previously unfolded body
  //
  //Returns 0 if successful. Returns the non-zero index of the body in iBodiesToTransfer which fails to transfer, in such case...
  //the caller needs to manage the first index-1 transferred bodies, available in ioBodiesTransferred.
  virtual int RunTransfer(const CATLISTP(CATBody) & iBodiesToTransfer ,
                                CATLISTP(CATBody) & ioBodiesTransferred,
                                CATCGMJournalList * iReport            , //Not filled if NULL
                                CATBoolean          iReverse           = FALSE); //TRUE to transfer from result body to input body

  virtual void GetSharpCornerInfo(CATLISTP(CATCell) &oSharpCorners);

  //To constrain edges from distorting
  //ACCESS: For FrF Shell Unfold only
  //
  virtual void SetCellsToFix(const CATLISTP(CATCell) & iCellsToFix        ,
                             const CATListOfDouble  *  iAnglesAtWireEnd   = NULL);
  virtual void SetWireImages(const CATLISTP(CATBody) & iWiresToConstraint ,
                             const CATLISTP(CATBody) & iWiresImages       ,
                             const CATListOfDouble   & iWireEndAngles     ,
                             const CATLaw          **  iLaws              );


  void TreatEdgesToTearAsCluster(int iMakeCluster);

  //To request forcing bijection (less gaps or smaller slides) among the 
  // constituent curves of an edge. This will try to have better representation
  // at the edges and in thus, make the computations SLOW.
  //ACCESS: For FrF Shell Unfold only
  virtual void SetAccurateEdgeMerging();

  // FrF Only 
  virtual void SetRigidifiedFlatArea(double iMinMaxRadiusLimit[2], double SolvingRatio );
  
  // FrF Only 
  virtual void SetAutoScalingOnFlateArea(CATLONG32 AutoScalingOn);

#if !defined(_AIX_SOURCE) && defined(CATIAR423)
  // FrF Only 
  /**
   * Sets a flag that enables improvement in length or area distortions in unfold output with respect to input shell
   * @param iMode
   *   If <tt>1</tt> it will reduce boundary length distortion: Should be used for singly curved input surfaces. Output is body with Nurbs surfaces
   *   If <tt>2</tt> it will reduce area distortion: Should be used for singly curved input surfaces. Output is body with Nurbs surfaces
   *   If <tt>3</tt> it will reduce boundary length distortion: Can be used for singly as well as doubly curved input surfaces. Output is body with plane surface
   *   For any other value, there will not be any effect and previous setting (if any) will be used
   */
  virtual void ReduceDistortions(short iMode);
#endif

#if !defined(_AIX_SOURCE) && defined(CATIAR424)
  //Internal method to debug purpose
  virtual void SetMeshingFunction(FMTMeshingFunc iMeshingFunc)
  {
    //To be overridden by FrfShellUnfold
  }
#endif

protected:

  //checks if the set of edges can be taken to tear, if iUpdateAsslyOrder = 1, it updates the faces for assembly order
  CATBoolean AreEdgesToTear(CATLISTP(CATEdge) &iEdgeList, CATBoolean iUpdateAsslyOrder = 0);

  CATBody * MoveResultBody();  

  void ClusterTheEdgesIfPossible(const CATLISTP(CATCell) &commonEdges);

  inline void GetTopDataLocal(CATTopData& oTopData)
  {
    GetTopData(oTopData);
    oTopData.SetJournal(GetJournalLocal()); //never use _JournalLocal directly here
  }

  inline CATCGMJournalList* GetJournalLocal()
  {
    if(_JournalLocal)//after Run and GetResult, _JournalLocal will be available with parent journal if any
      return _JournalLocal;
    
    return GetJournal();
  }

  void InsertJournalInParent();  

  inline void GetApplied3DTransformation(CATMathTransformation &oTransfo)
  {
    oTransfo = _AppliedTransfo;
  }


  //------------------------------------------------------------------------------------------
  // sticker
  //------------------------------------------------------------------------------------------
  // Force the computation of the mappingFunction
  void SetForceMappingFunctionComputation()
    {
    _ComputeMappingFunction = TRUE;
    }
  //
  void GetMappingFunction(CATPolyMeshMappingFunction *& oMappingFunction)
    {
    oMappingFunction = _MappingFunction;
    }

  // Force the of Advanved mesh
  void SetAdvancedMesh(double *Tol)
    {
    ;
    }

  /**
  * SetUVBoxLowerCorner 
  * To define the lower corner of the resulting UVBox.
  * @param iLowerCornerUV
  * the coordinates uv of the lower corner
  */
  void SetUVBoxLowerCorner(const double iLowerCornerUV[2])
  {    
    _LowerCornerUV[0] = iLowerCornerUV[0];
    _LowerCornerUV[1] = iLowerCornerUV[1];
    _IsDefinedUVBoxLowerCorner = TRUE;
  }

  /**
  * SetUVBoxMaxLength
  * To define the length of the largest UV directions. 
  * Do not change anisotropy (lengthU/lengthV) of the result.
  * @param iLenght
  * the Max(Umax-Umin, Vmax-Vmin) will be equal to the given value of iLenght.
  */
  void SetUVBoxMaxLength(const double iLenght)
  {

    _LenghtUVBox             = iLenght;
    _IsDefinedUVBoxMaxLength = TRUE;
  }

  /**
  * @SetTexturingContext
  * To define the uv coordinates in the range [0,1].
  * Do not change anisotropy (lengthU/lengthV) of the result.
  * CAREFUL : this method calls SetResultLowerCorner( (0,0) and SetTheLargestUVDirectionsLength( 1. ).
  *           So do not call @SetResultLowerCorner or @SetTheLargestUVDirectionsLength after SetTexturingContext
  */
  void SetTexturingContext()
  {
    _DefineTexturingContext = TRUE;
  }

  // Saves the complete journal to be used by cell tracker
  void SaveCompleteJournal();

	// Makes the journal CGM compliant by removing entries corresponding to internal edges and vertices
	void CleanJournal();

private:

  //
  // Tool[0] : Type of Tool
  // Type==1
  // Tool[1] : Stretch ( L(2D) = Tool[1] * L(3) in the "non" ruled direction
  void SetToolData(const CATLISTP(CATFace)*ListOfCATFace, double *Tool);


  //does data member initialization
  void Init();

  // Fill report with lay down informations
  //************************** DEPRECATED **************************
  void FillReportLayDown(CATBody * iBody, CATTopData * iData, CATCGMJournalList * iReport);
  //************************** DEPRECATED **************************
  void FillReportWireExtremities(CATWire * iWire, CATWire * oWire, CATCGMJournalList * iReport);
  
  // Transfert one domain (wire or point in volume)
  //************************** DEPRECATED **************************
  CATDomain * TransfertOneDomain(CATDomain         * iDom                 ,
                                 CATBody           * iInitialTransfertBody,
                                 CATBoolean          iReverse             ,
                                 CATBody           * iCreationBody        ,
                                 CATCGMJournalList * iReport              );
  
  //************************** DEPRECATED **************************
  void GetTransfoInformations(CATCell                *  iCell,
                              CATBody                *  iInitialTransfertBody,
                              CATBoolean                iReverse,
                              CATCell                *& TrueSupport,
                              CATFace                *& FaceSupp,
                              CATSurface             *& SurfSupp,
                              CATFace                *& FaceIma,
                              CATSurface             *& SurfIma, 
                              CATMathTransformation2D & Transfo2D);

  // Get 2D transformation for the face iIndex in _FacesInAsslyOrder
  // returns FALSE if iIndex is beyond _FacesInAsslyOrder/_inputFaceList size
  virtual CATBoolean GetTransformation2D(const int                     & iIndex,
                                               CATMathTransformation2D & oTransformation2D) = 0;

  //Get all the transformations 2D in one go, note that memory is managed by this class
  virtual const CATMathTransformation2D * GetTransformation2DTable();

  //RunTransfer calls this, iBody has to be mono-domain
  //************************** DEPRECATED **************************
  void PrivateRunTransferOnMonoDomainBody(CATBody           *  iBody               ,
                                          CATBody           *& oBody               ,
                                          CATBody           *& oLayDownWire        ,
                                          CATCGMJournalList *  iReport             ,
                                          CATBoolean           iReverse            = FALSE,
                                          CATBoolean           iDontCleanAndFreeze = FALSE);

  void GetAxisFromWire                   (CATBody           *  iWire               ,
                                          CATBody           *  iBody               ,
                                          CATShell          *  iShell              ,
                                          CATMathAxis        & oAxis               );

  //Clean the provided wire body on the support _Result/_pBody depending on iReverse = FALSE/TRUE
  //it is necessary that the child class affirms on cleaning, else returns FALSE
  //************************** DEPRECATED **************************
          CATBoolean        CleanWire    (CATBody           *& ioBody              ,
                                          CATCGMJournalList *  iReport             ,
                                          CATBoolean           iReverse           );

  //to know from the child class whether to perform cleaning or not
  virtual CATBoolean        ShallCleanWire();

  //allowed maximum assembly tolerance for skin and wire
  virtual double            GetMaxAsslyTolerance();

  //implementation of positioning based on CATMathPlane
          void              PlanePositioning(CATMathAxis &oInitialAxis, CATMathAxis &oFinalAxis);
          void              PlanePositioningOld(CATMathAxis &oInitialAxis, CATMathAxis &oFinalAxis);

          void              ClubClusterEdges(CATLISTP(CATEdge) &iEdges);

  //finds which edges can be torn, if iMust = 1, calculates edges must-to-tear and initial candidates
  virtual CATLISTP(CATEdge) FindCandidateEdgesToTear(const CATLONG32 iMust = 0) = 0;

  //break the input list into two groups
  virtual void RegroupEdgesToTear(const CATLISTP(CATEdge) & iCandidateEdges     ,
                                        CATLISTP(CATEdge) * ioMandatoryCandidates,
                                        CATLISTP(CATEdge) * ioOptionalCandidates);

  //The old function
  CATBoolean SetEdgesToTearOld( const CATLISTP (CATEdge) & iEdgesToTear,
                                      CATLONG32          & oNbAmbiguities,
                                      CATLISTP(CATEdge)  & oCandidateEdgesToTear,
                                      CATLISTP(CATEdge)  & oInvalidInputEdges );

  // Merges close vertices which lie with in a tolerance
  //************************** DEPRECATED **************************
  CATBoolean RegularizeWires  (        CATBody           *  iInputWire,
                                       CATBody           *  iCreationBody,
                                       ListPOfCATDomain   & ListeWireResult,
                                       CATCGMJournalList *  iReport);

  //Checks whether the body is Non-Manifold
  //************************** DEPRECATED **************************
  CATBoolean IsNonManifold(CATBody          * iWire   ,
                           ListPOfCATVertex & oVertex1, CATListOfInt & oNumDom1, CATListOfInt & oNumExtr1,
                           ListPOfCATVertex & oVertex2, CATListOfInt & oNumDom2, CATListOfInt & oNumExtr2);

  //If the input body _pOriginalBody is torn at edge-to-tear (like in FrFUnfold case),
  // the face in torn body corresponding to iFace of _pOriginalBody is returned.
  virtual CATFace* GetFaceAfterPreTear(CATFace* iFace);

  void CreateTransferService();


//=============================================================================================================
//=============================================================================================================
  // DATA
//=============================================================================================================
//=============================================================================================================
public:
protected:
  //TODO bring the related functions here and review above ones
  //TODO better to use Set/Get functions instead of having protected members
  CATBody                       * _pOriginalBody; //input body; _pBody shall be treated as working body now
  CATBody                       * _pBody; //the working body
  CATShell                      * _pShell, *_pOriginalShell; //the input shell
  CATLISTP(CATEdge)               _edges2TearList; //selected edge list

  CATPlane                      * _InputPlane; //input plane where unfolded body is laid
  CATPoint                      * _PlaneOrigin; //origin for _DestinationPlane

  // Lying on tolerance for transfert
  double                          _TransfertTolerance;

  CATVertex                     * _pInitialVertex;
  CATEdge                       * _pInitialEdge, * _pFinalEdge;
  CATFace                       * _pInitialFace;
  CATBoolean                      _InitialLocation;
  CATBody                       * _pFixedWire;

  //new positioning data
  CATMathPlane                  * _NewPositionPlane;
  CATFace                       * _NewPositionFace;

  CATMathPlane                  * _TargetPlane;

  CATBoolean                      _JournalDifferentiateTearedEdges;
  CATCGMJournal::Type             _JournalItemType;

  //faces (of _pBody, which may be the torn body) in order for proper assembly
  CATLISTP(CATFace)               _FacesInAsslyOrder;
  //resulting faces, same order as _FacesInAsslyOrder
  CATLISTP(CATFace)               _ResultFaces;

  CATLISTP(CATEdge)               _edgesMustToTear;
  CATLISTP(CATEdge)               _edgesCanTear; //initial edges to tear, less must to tear

  //total number of common edges
  CATLONG32                       _NbCommonEdges; //to be populated by child class

  //selected face list
  CATLISTP(CATFace)               _inputFaceList; //to be populated by child class

  CATLISTP(CATCell)               _CommonEdgesCluster; //to be populated by child class
  int                             _CorrectionForNbAmbiguities; //to be populated by child class

  //faces as reference face for each above, to calculate transformation
  CATLISTP(CATFace)               _BaseFacesForAssly; //useful only for Ruled Unfold
  //common edges between above faces
  CATLISTP(CATCell)               _CommEdgesForAssly; //useful only for Ruled Unfold


  // List Of UserInfo
  //CATListOfInt _UserInfoList;
  
  // List of User Strech Ratio
  CATListOfDouble                 _StrechInAsslyOrder;

  //certain enhancements are activated according to this, default is 0
  //int _SpecialityLevel; //0: do nothing; 1: Accept holes in FrF unfold; 2: Enhanced mesh leads stable FrF; 4: better GetCellImage
  //int _SpecialityLevel; //0: do nothing; 1: fix for IR 0527383, transfo is isoparam/along with surface

  int                             _MakeCluster;

  CATBoolean                      _ResultProvided; //Flattened result (_Result) is already known

  // Sticker
  CATBoolean                      _ComputeMappingFunction; // Force the computation of the mapping funcation
  CATPolyMeshMappingFunction    * _MappingFunction;
  CATBoolean                      _IsDefinedUVBoxLowerCorner;
  CATBoolean                      _IsDefinedUVBoxMaxLength;
  double                          _LowerCornerUV[2];
  double                          _LenghtUVBox;
  CATBoolean                      _DefineTexturingContext;

  private:
  //Temporary item that have to be cleaned
  CATLayDownOperator            * _PoseOperator;    //***DEPRECATED***
  CATBody                       * _TransfertPose;   //***DEPRECATED*** // body after lay down (= initial body if already laid down)
  CATBoolean                      _HasBeenLaidDown; //***DEPRECATED*** // indicate if the body has been laid down

  CATCGMJournalList             * _JournalLocal;
  CATMathTransformation           _AppliedTransfo;
  CATTopShellUnfoldTransferImpl * _TransferService;

  protected:
    CATTopTearEdges * _pTopTearEdges;

};

#endif

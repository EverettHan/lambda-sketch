#ifndef ExtrusionRecogniser_H
#define ExtrusionRecogniser_H


// COPYRIGHT DASSAULT SYSTEMES 2004
#include "Draft.h"

#include "CATBoolean.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATTopDefine.h"
#include "CATPLine.h"
#include "CATListPV.h"

class CATFace;
class CATBody;
class CATMathVector;
class CATVertex;
class CATShell;
class CATSurface;
class CATDomain;

class CATSoftwareConfiguration;

//------------------------------------------------------------------------------
//class which clubs extrusion data related to a extrusion profile edge
class ExtrusionUnit
{
  public:
     ExtrusionUnit();
  
    ~ExtrusionUnit();

    CATEdge* _pProfileEdge; //extrusion profile edge
    CATEdge* _pExtrEdge; //previous extrusion edge
    CATFace* _pExtrFace; //extrsion face corresponding to the _pProfileEdge
    CATVertex* _pExtrVertex; //vertex common between _pExtrEdge and _pProfileEdge
    CATTopSharpness _TopSharpness; //sharpness of the extrusion edge

    void Init();
};

//------------------------------------------------------------------------------

class ExportedByDraft ExtrusionRecogniser{
  public:
    
    //use CreateFunction to instantiate this class
    //iFaces is the list of faces on the basis of which the decision will be taken
     static ExtrusionRecogniser* CreateExtrusionRecogniser(CATBody* iBody, CATShell* iShell
                                                           ,const CATLISTP(CATFace) &iFaces, CATSoftwareConfiguration* iConfig);

     //destructor, use C++ delete
    ~ ExtrusionRecogniser();
    
    //launch the recogniser algo.
     void Run();

     //returns TRUE is Extrusion found else returns FALSE
     CATBoolean IsExtrusion();

     //returns TRUE if IsExtrusion returns TRUE
     //get the extrusion vector and support face
     //the edges of outer loop of the support face are the profile edges
     //ioExtrusionUnits - the list of ordered extrusion units. one needs to free the memory associated with each elemet of the list after usage
     //oStartSubProfiles - start indieces of sub-profiles which will be drafted
     //oEndSubProfiles - end indiced of sub-profiles which will be drafted
     //oNumSharpCommonEdges - number of internal sharp vertices corresponding to each sub-profile
     CATBoolean GetExtrusionSpecs(CATMathVector &oExtrusionVec, CATFace* &oSupportFace
                                 ,CATListPV &ioExtrusionUnits
                                 ,CATListOfInt &oStartSubProfiles
                                 ,CATListOfInt &oEndSubProfiles
                                 ,CATListOfInt &oNumSharpCommonEdges); 


  private:
    //constructor destructor
    //iFaces is the list of faces on the basis of which the decision will be taken
    ExtrusionRecogniser(CATBody* iBody, CATShell* iShell, const CATLISTP(CATFace) &iFaces, CATSoftwareConfiguration* iConfig);

    CATBoolean IsParallelTabCylinder(CATSurface* iTabCylinder);

    CATBoolean IsParallelCylinder(CATSurface* iCylinder);

    CATBoolean IsParallelPlane(CATSurface* iPlane);

    //check if given edge is parallel to given refernce direction
    //oSenseFactor = 1 => edge has same sense w.r.t iRefDir
    //oSenseFactor = -1 => edge has opposite sense w.r.t iRefDir
    CATBoolean IsEdgeParallel(CATEdge* iEdge, const CATMathVector &iRefDir, CATFace* iFace, int &oSenseFactor, CATBoolean iCheckFace = TRUE);

    //in outer loop of iFace find a edge parallel to iRefDir
    //oSenseFactor = 1 => edge has same sense w.r.t iRefDir
    //oSenseFactor = -1 => edge has opposite sense w.r.t iRefDir
    //only useful if iFace is of type cylinder, plane or tabulated cylinder.
    CATBoolean GetParallelEdge(CATFace* iFace, const CATMathVector &iRefDir, CATEdge* &oParEdge, int &oSenseFactor, CATBoolean iCheckFace = TRUE);

    //check if given edge is IsoParametric on given face
    //iRefType is the Iso-Parameter type which is searched for
    //returns TRUE if condition is satisfied.
    CATBoolean IsIsoParametric(CATEdge* iEdge, CATFace* iFace, CATIsoParameter iRefType);

    //get the edges and faces bounded by the vertex, other than stopping edges 
    CATBoolean GetBoundedEdges(CATVertex* iVert, CATLISTP(CATEdge) &ioEdges, const CATLISTP(CATEdge) &iStoppingEdges);

    CATBoolean CheckIfExtrusion(CATFace* iFace);

    //use given extrusion edge to find remaining extrusion specifications
    CATBoolean FindExtrusionSpecs(CATEdge* iEdge);

    CATBoolean PropagateProfile(const CATTopSharpness &iRefSharpness);

    CATBoolean PropagateOffsetProfile(CATEdge *iEdge, CATVertex* iVertex,const CATTopSharpness &iRefSharpness
                                      ,CATFace* iOffSetFace,const CATListPV &iExtrusionUnits);

    //returns index of the Extrusion unit in which iEdge is found as profile edge
    //returns 0 if it is not found
    int FoundProfileEdge(CATEdge* iEdge);

    //returns index of the Extrusion unit in which iEdge is found as extrusion edge
    //returns 0 if it is not found
    int FoundExtrEdge(CATEdge* iEdge);

    //returns index of the Extrusion unit in which iFace is found as extrusion face
    //returns 0 if it is not found
    int FoundExtrFace(CATFace* iFace);

    //intialise some members
    void Init();

    void InitialiseExtrusionUnits();

    CATBoolean _IsExtrusion; //TRUE if extrusion is found
    CATBoolean _RunDone;  //TRUE if run is done
    CATMathVector* _pExtrDir; //extrusion direction
    CATLISTP(CATFace) _Faces; // input faces
    CATLISTP(CATFace) _PropagFaces; // propagated faces
    CATFace* _SupportFace; //support of the extrusion profile.
    
    CATListOfInt _StartSubProfile; //start indices of sub-profiles which will be drafted, sub-profiles are disconnected parts of profile
    CATListOfInt _EndSubProfile; //end indices of sub-profiles which will be drafted, 
    CATListOfInt _NumSharpCommonEdges; //number of sharp common edges found corresponding to each sub-profile

    CATBody* _Body;//body of faces to draft
    CATShell* _Shell;//shell of faces to draft
    CATSoftwareConfiguration* _pConfig;

    CATListPV _ExtrusionUnits; //list of ordered extrusion units  

    //DSH1 Start March 2015 For IR-338355
  public:    
    CATBoolean GetIsExtrudedHole();
  private:
    void SetIsExtrudedHole(CATBoolean iValue);
    CATBoolean _IsExtrudedHole;
    //DSH1 End
};

#endif



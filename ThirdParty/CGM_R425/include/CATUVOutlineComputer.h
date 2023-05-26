#ifndef CATUVOutlineComputer_h
#define CATUVOutlineComputer_h

//COPYRIGHT DASSAULT SYSTEMES 2009

//------------------------------------------------------------------------------
//  Abstract:
//  ---------
//  Main Object to compute outlines on CAT3DUVRep.
//
//------------------------------------------------------------------------------
//  Usage:
//  ------
//  The CATUVOutlineComputer is used in CATDrawRender to perform computation &
//  display of outlines.
//
//  CATUVOutlineComputer is created with a viewpoint which will be used to compute
//  outlines.
//  Then the following sequence has to be used for each CATVizUV3DRep:
//  -Call StartRep for each new UV3DRep (iOptimizedVB is VB for stripped UVRep)
//    -Call AddRefinableFace for each face of current UV3DRep.
//          internal (i.e non border) outlines are computed for each face
//  -Call ComputeOutlinesOnEdges to compute outlines on faces' borders.
//          (this can be skipped if caller know that edges are drawn anyway for example)
//  -Call DrawOutlines to display results.
//  -Call TerminateRepProcessing to clear all transient datas & results.
//
//------------------------------------------------------------------------------
//  Inheritance:
//  ------------
//                 
//
//------------------------------------------------------------------------------
//  Main Methods:
//  -------------
//------------------------------------------------------------------------------

#include "CATUVOutlineConnectivityMatrix.h"
#include "CATVizPtrList.h"
#include "CATSysBoolean.h"
#include "CAT3DViewpoint.h"
#include "CAT3DViewport.h"
#include "CATRefinementEngine.h"

class CATUVOutlineCellPool;
class CATVizVertexBuffer;
class CATVizUV3DFace;
class CATVizUV3DEdge;
class CATDrawRender;
class CAT4x4Matrix;


//----------------------------------------------------------------------------------------
//
//                                  CATUVOutlineComputer
//
//----------------------------------------------------------------------------------------

class ExportedBySGInfra CATUVOutlineComputer
{
public:

  //Constructor
  CATUVOutlineComputer(CAT3DViewpoint& iViewpoint);

  //Destructor
  virtual ~CATUVOutlineComputer();

  //Management of CAT3DUVRep
  void StartRepProcessing(CATVizVertexBuffer *iOptimizedVB = NULL, CAT4x4Matrix *iMatrix = 0);
  void TerminateRepProcessing();//stop current rep processing and deletion of results
  void ComputeOutlinesOnEdges();//compute outlines on faces' borders

  //Management of Faces
  HRESULT AddRefinableFace (CATVizUV3DFace *iFace, CATRefinementEngine *engine, CATBoolean iVisible = TRUE);

  //Display of Result
  void DrawOutlines(CATDrawRender &iRender);//draw results

private:

  struct line
  {
    float *points;
    unsigned int nbPoints : 30;
    unsigned int lineType :  2;

    line(float *iPoints, unsigned int iNbPoints, unsigned int iLineType)
    {
      points    = iPoints;
      nbPoints  = iNbPoints;
      lineType  = iLineType;
    }
    ~line()
    {
      free(points);
    }
  };

  struct UVFaceOutline
  {
    CATVizUV3DFace                 *face;
    CATUVOutlineConnectivityMatrix *connect;
    UVOutlineTriangleStatus         status;
    unsigned int                    processed;
    //CATVizPtrList<CATViz3DLine>     resultLines;
    CATVizPtrList<CATVizUV3DEdge>   resultEdges;
    CATVizPtrList<line>             resultLines;

    UVFaceOutline()
    {
      face      = NULL;
      connect   = NULL;
      status    = UNINITIALIZED;
      processed = 0;
    }
    ~UVFaceOutline()
    {
      int i=0;
      for(i=resultLines.Length()-1;i>=0;i--)
        delete resultLines[i];
      
      if (connect)   connect  ->Release();
    }
    void AddResultLine(float *iPoints, unsigned int iNbPoints, int iLineType)
    {
      line *currentLine = (iPoints && iNbPoints > 0) ? new line(iPoints,iNbPoints,iLineType) : NULL;
      if(currentLine)
        resultLines.AddTail(currentLine);
    }
  }; 

  //Copy constructor
  CATUVOutlineComputer (const CATUVOutlineComputer &);
  CATUVOutlineComputer & operator= (const CATUVOutlineComputer &);

  //Management of Faces and Outlines
  void ProcessFaceAsStatic(UVFaceOutline *iFace);
  static void UVFaceCB    (void * user_data, CATRefinementEngine::MeshCBData & iData);
  void BuildOutlineOnEdge (CATVizUV3DEdge *iUVEdge, UVFaceOutline *iFace1, UVFaceOutline *iFace2);

  //Utilities
  HRESULT CheckFaceUniformity(CATVizUV3DFace *iFace, CATVizVertexBuffer *iVB, UVOutlineTriangleStatus &oStatus) const;
  void GetViewpointData(int &oProjectionType, float oProjectionDataArray[3]) const;
  void ClearTransientDatas();


  //Data members
  CATUVOutlineCellPool           *_cellPool;
  CAT3DViewpoint                  _viewpoint;
  CAT3DViewpoint                  _working_viewpoint;
  CAT3DViewport                   _working_viewport;
  float                           _epsForAngleTest;
  float                           _toleranceScale;

  
  CATVizPtrList<UVFaceOutline>    _FaceList;
  CATUVOutlineConnectivityMatrix *_strippedMatrix;
  unsigned int                    _repRegistered;
};

#endif

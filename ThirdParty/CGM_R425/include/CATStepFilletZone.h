#ifndef CATStepFilletZone_H
#define CATStepFilletZone_H

#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "AdvOpeInfra.h"
#include "ListPOfCATFace.h"

class CATBody;
class CATCGMOutput;

class ExportedByAdvOpeInfra CATStepFilletZone
{
public:
  CATStepFilletZone(ListPOfCATEdge iTrackEdges[2], 
                    CATListOfInt   iOrientations[2],
                    int            iContinuityType[2]);

  virtual ~CATStepFilletZone();

  void SetTrackEdges(ListPOfCATEdge iTrackEdges[2], CATListOfInt iOrientations[2], int iContinuityType[2]);
  void SetLimitingBodies(CATBody *iLimitingBodies[2]);
  void SetExtrapolationValues(double iExtrapolValues[2]);
  void SetKeepEdgeAttributes(CATBoolean iTrackEdgesAreKeepEdges[2]);
  void SetFilletType(int iType);//Used for tritangent fillet
  void AppendTritangentFaces(ListPOfCATFace & iTritangentFacesList);//Used for tritangent fillet

  void GetTrackEdges(ListPOfCATEdge oTrackEdges[2], CATListOfInt oOrientations[2], int oContinuityType[2]);
  void GetTrackEdges(ListPOfCATEdge oTrackEdges[2], CATListOfInt oOrientations[2], int oContinuityType[2], CATBoolean oAreKeepEdges[2]);
  void GetLimitingBodies(CATBody *& oLimitingBody1, CATBody *& oLimitingBody2);
  void GetExtrapolationValues(double &oExtrapolVal1, double &oExtrapolVal2);
  int GetFilletType(); //Used for tritangent fillet  
  void GetTritangentFaces(ListPOfCATFace & ioTritangentFacesList);//Used for tritangent fillet  
  void Dump(CATCGMOutput& os);

private:
  ListPOfCATEdge _TrackEdges[2];
  CATListOfInt   _Orientations[2];
  int            _ContinuityType[2];
  CATBody       *_LimitingBodies[2];
  double         _ExtrapolValues[2];
  CATBoolean     _TrackEdgesAreKeepEdges[2];
  int            _FilletType;
  ListPOfCATFace _TritangentFacesList;
};


#endif


/* -*-C++-*-*/
#ifndef CATHLREdgeClashInfo_H
#define CATHLREdgeClashInfo_H






class CATFace;



#include "HLREngine.h"

#include "CATListOfDouble.h"
#include "HLREngine.h"
#include "CATSetOfCrvParams.h"



class ExportedByHLREngine CATHLREdgeClashInfo
{
  //=============================================================================
  // CONSTRUCTORS AND DESTRUCTOR
  //=============================================================================

public :


  // Default constructor
  CATHLREdgeClashInfo();


  // Destructor
  ~CATHLREdgeClashInfo();

  // Methode Set et Get
  inline void SetIntersectedCATFaceEntityId(int iFaceId);
  inline void SetIntersectedCATFace(CATFace * iFace);
  void SetEdgeClashPoints(CATListOfDouble &iClashPoints); 
  void SetSetOfCrvParams(CATSetOfCrvParams &iSetOfCrvParams); 


  inline int GetIntersectedCATFaceEntityId();
  inline CATFace * GetIntersectedCATFace();
  inline CATListOfDouble & GetClashPoints();
  inline CATSetOfCrvParams & GetSetOfCrvParams(); 


private :

  int                _FaceEntityId;
  int                _NbClashPoints;
  CATFace *          _IntersectedFace;
  CATListOfDouble    _ClashPoints;
  CATSetOfCrvParams  _ClashCrvParams;
  
};

// Methodes inline 
// ---------------

inline void CATHLREdgeClashInfo::SetIntersectedCATFaceEntityId(int iFaceId) {
  _FaceEntityId=iFaceId; }

inline void CATHLREdgeClashInfo::SetIntersectedCATFace(CATFace * iFace) {
  _IntersectedFace=iFace; }

inline int CATHLREdgeClashInfo::GetIntersectedCATFaceEntityId() {
  return _FaceEntityId; }

inline CATFace * CATHLREdgeClashInfo::GetIntersectedCATFace() {
  return _IntersectedFace; }

inline CATListOfDouble & CATHLREdgeClashInfo::GetClashPoints() {
  return _ClashPoints; }

inline CATSetOfCrvParams & CATHLREdgeClashInfo::GetSetOfCrvParams() {
  return _ClashCrvParams; }


#endif


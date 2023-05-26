// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATCVMGeoCopilot2Magnet_H
#define CATCVMGeoCopilot2Magnet_H

/**
* 14.09.17 KJD : Addition of the WriteMagnet + StoreGeo APIs to enable the record  the GMCopilot CGMReplay during CVM Run
*                 => extract of the data from CVMMagnet to GMMagnet
*/

#include "CATCVMGeoOperators.h"

#include "CATCVMGeoDef.h"
#include "CATBoolean.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTV_CATMathPoint2D.h"
#include "CATBaseUnknown.h"
#include "ListPOfCATCVMGeoCopilot2Snap.h"

class CATCVMGeometry;
class CATMathCircle;

#include "CATCVMGeoCopilot2.h"
#ifdef  ActivateCVMInstancePath
class CATCVMInstancePath;
#endif

class ExportedByCATCVMGeoOperators CATCVMGeoCopilot2Magnet : public CATBaseUnknown
{
public:

  virtual ~CATCVMGeoCopilot2Magnet();

  /**
  * return this magnet's type : point, segment, segmentUV, edge or face
  * (definition of CATCVMMagnetType in CATCVMGeoDef.h)
  */
  virtual CATCVMMagnetType GetType() = 0;

  /**
  * return TRUE if this magnet is a CATCVMMagnetType_Point.
  * oPoint : mathematical point representing this magnet
  */
  virtual CATBoolean GetPoint(CATMathPoint & oPoint) = 0;

  /**
  * return TRUE if this magnet is a CATCVMMagnetType_Segment.
  * oListPoint : 2 extremities of the segment representing this magnet
  * (in the case of an infinite line, an intersection with the domain
  * box is performed)
  */
  virtual CATBoolean GetSegment(CATLISTV(CATMathPoint) & oListPoint) = 0;

  /**
  * return TRUE if this magnet is a CATCVMMagnetType_SegmentUV.
  * oListPoint : 2 extremities of the segment representing this magnet
  * oCVMFace : Support face of this UV magnet
  * oCVMInstancePath : Instance path of support face
  */
  virtual CATBoolean GetSegmentUV(CATLISTV(CATMathPoint2D) & oListPoint, CATCVMGeometry *& oCVMFace) = 0;

  /**
  * return TRUE if this magnet is a CATCVMMagnetType_Edge.
  * oCVMEdge : CVM edge representing this magnet
  * oCVMInstancePath : instance path of CVM edge
  */
  virtual CATBoolean GetEdge(CATCVMGeometry *& oCVMEdge) = 0;

  /**
  * return TRUE if this magnet is a CATCVMMagnetType_Face.
  * oCVMFace : CVM face representing this magnet
  * oCVMInstancePath : instance path of CVM face
  */
  virtual CATBoolean GetFace(CATCVMGeometry *& oCVMFace) = 0;

   /**
  * return TRUE if this magnet is a CATCVMMagnetType_Circle.
  * oCircle : mathematical circle representing this magnet
  */
  virtual CATBoolean GetCircle(CATMathCircle & oCircle) = 0;

  /**
  * return the list of snaps that cause this magnet.
  */
  virtual void GetSnapList(ListPOfCATCVMGeoCopilot2Snap & oListSnap) = 0;
  
  /**
  * return TRUE if a snap of type iType is found within this magnet, FALSE otherwise.
  */
  virtual CATBoolean FindSnap(CATCVMSnapType iSnapType) = 0;

  /**
  * return TRUE if this magnet is a CATCVMMagnetType_Point.
  * oPoint : mathematical point representing this magnet
  * oIsIntersection : TRUE if the point is the result of an intersection
  */
  virtual CATBoolean GetPoint(CATMathPoint & oPoint, CATBoolean & oIsIntersection) = 0;

   /**
  * return TRUE if this magnet is a CATCVMMagnetType_PointList.
  * oPoint : mathematical point representing this magnet
  */
  virtual CATBoolean GetPointList(CATLISTV(CATMathPoint) & oPointList) = 0;

  virtual void WriteMagnet(CATCGMStream  & ioStream) = 0;
  virtual int StoreGeo(CATLISTP(CATGeometry) & ListGeo, CATListOfInt & oListRepartition) = 0;
  virtual void Dump(CATCGMOutput & os, CATGeoFactory * pFactory) = 0;

private:

  CATCVMGeoCopilot2Magnet(const CATCVMGeoCopilot2Magnet &);
  void operator = (const CATCVMGeoCopilot2Magnet &);

protected:

  CATCVMGeoCopilot2Magnet();

#ifdef  ActivateCVMInstancePath
public:
  /**
  * return TRUE if this magnet is a CATCVMMagnetType_SegmentUV.
  * oListPoint : 2 extremities of the segment representing this magnet
  * oCVMFace : Support face of this UV magnet
  * oCVMInstancePath : Instance path of support face
  */
  virtual CATBoolean GetSegmentUV(CATLISTV(CATMathPoint2D) & oListPoint, CATCVMGeometry *& oCVMFace, CATCVMInstancePath *& oCVMInstancePath) = 0;

   /**
  * return TRUE if this magnet is a CATCVMMagnetType_Edge.
  * oCVMEdge : CVM edge representing this magnet
  * oCVMInstancePath : instance path of CVM edge
  */
  virtual CATBoolean GetEdge(CATCVMGeometry *& oCVMEdge, CATCVMInstancePath *& oCVMInstancePath) = 0;

  /**
  * return TRUE if this magnet is a CATCVMMagnetType_Face.
  * oCVMFace : CVM face representing this magnet
  * oCVMInstancePath : instance path of CVM face
  */
  virtual CATBoolean GetFace(CATCVMGeometry *& oCVMFace, CATCVMInstancePath *& oCVMInstancePath) = 0;
#endif
};

#endif

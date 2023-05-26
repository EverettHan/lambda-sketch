#ifndef WireUtilities_H
#define WireUtilities_H


// COPYRIGHT DASSAULT SYSTEMES 2004
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATMath.h"
#include "CATBoolean.h"
#include "CATTopDefine.h"
#include "CATTopRibDef.h"

#include "ListPOfCATEdge.h"
#include "CATListOfCATCurves.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CATListOfCATCrvLimits.h"
#include "CATFace.h"

class CATMassProperties1D;
class CATEdge;
class CATWire;
class CATVertex;
class CATBody;

class CATGeoFactory;
class CATCrvParam;
class CATSurface;
class CATMathDirection;
class CATMathPoint;

class CATSoftwareConfiguration;

class ExportedByRIBLight WireUtilities
{
  public:


    static WireUtilities* CreateWireUtilities(CATLISTP(CATEdge) &iSortedEdges, CATListOfInt &iOrient, int iIndexShift
                                             ,CATGeoFactory* iFactory,CATSoftwareConfiguration* iConfig);
    
    static WireUtilities* CreateWireUtilities(CATWire* iWire, CATVertex *iSpecifiedStartVertex, CATGeoFactory* iFactory,CATSoftwareConfiguration* iConfig);

#ifdef DRAFT_AUTOMATIC_FATPARAM_CALC
    //if you want any of these methods bring it out of DRAFT_AUTOMATIC_FATPARAM_CALC, don't unprotect other methods
    CATBoolean FindNearestIntersectionAlongWire(CATSurface* iSurface, int iRefEdgeIndex, const CATCrvParam &iRefParam
                                                ,CATTopRibSign iDirWrtWire, int &oEdgeIndex, CATCrvParam &oIntParam) const;

#endif

    virtual ~ WireUtilities();

    CATBoolean Evaluate(int iEdgeIndex, const CATCrvParam &iParam, CATMathPoint *oPoint, CATMathDirection* oTgtToWire=0 ,CATOrientation* oOriCrvVsWire=0) const;

    CATBoolean FindIntersection(CATSurface* iSurface, const CATMathPoint &iRefPoint
                                ,int &oEdgeIndex, CATCrvParam &oIntParam) const;

    CATBoolean CalcCrvDistance(int iEdgeIndex1, const CATCrvParam &iParam1, int iEdgeIndex2
                              , const CATCrvParam &iParam2, CATTopRibSign iDirWrtWire, double &oDistance) const;

    CATBoolean CalcCrvDistance(int iEdgeIndex1, const CATCrvParam &iParam1, const CATMathPoint &iPoint2, CATTopRibSign iDirWrtWire, double &oDistance) const;

    CATBoolean CalcPosition(int iRefEdgeIndex, const CATCrvParam &iRefParam, const double &iDistance
                           ,CATTopRibSign iDirWrtWire ,int &oEdgeIndex, CATCrvParam &oParam) const;

    CATBoolean IsClosed() const { return _IsClosed;}
    CATBoolean IsPseudoClosed() const { return _IsPseudoClosed;}

    double GetTol() const {return _Tol;}

    void GetValidEdgeIndex(int &ioEdgeIndex) const;

    CATBoolean GetLength(int iEdgeIndex, double &oLength) const;

    CATBoolean GetExtremity(CATBoolean iStart, int &oEdgeIndex, CATCrvParam &oParam
                          , CATMathPoint* oPoint = 0, CATMathDirection* oTgtToWire = 0) const;

    double GetTotalLength() const {return _TotalLength;}

    CATBoolean IntersectionIndex(CATFace* pFace, int &oIndx, CATCrvParam *oIntCrvParam, CATSurParam *oIntSurParam, CATEdge* &oEdge);

    CATBoolean FindMidPoint(CATMathPoint &oMidPoint, int &oEdgeIndex, CATCrvParam &oParam, CATEdge** oEdge = 0) const;

    void CheckIfPseodoClosed();

  protected:

    CATLISTP(CATEdge)       _Edges;
    CATListOfInt            _EdgeVsWireOrients;
    CATListOfDouble         _Lengths;
    CATLISTP(CATCurve)      _Curves;
    CATListOfInt            _CurveVsWireOrients;
    CATLISTP(CATCrvLimits)  _CrvLimits;
    CATBoolean              _IsClosed; 
    CATBoolean              _IsPseudoClosed; 
    int                     _NumEdges; 
    CATMassProperties1D**   _pOpes;
    CATSoftwareConfiguration* _pConfig;
    CATGeoFactory*            _pGeoFactory;
    double                  _TotalLength;
    double                  _Tol;
    int                     _IndexShift; //input index - _IndexShift as actual index and output index + _IndexShift as actual index
    CATBody*                _pBody;
    CATWire*                _pWire;

  private:

    WireUtilities(CATLISTP(CATEdge) &iSortedEdges, CATListOfInt &iOrient, CATBoolean isClosed
                 ,int iIndexShift, CATGeoFactory* iFactory,CATSoftwareConfiguration* iConfig
                 ,CATBody* iBody, CATWire* iWire);

    WireUtilities() {}

    void Init();

    CATBoolean CalcLengths();

    CATBoolean SwapParams(CATCrvParam &ioParam1 ,CATCrvParam &ioParam2 ) const;

    void GetValidIndex(int &ioIndex) const;

};
#endif

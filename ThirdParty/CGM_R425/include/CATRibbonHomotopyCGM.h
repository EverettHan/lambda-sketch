#ifndef CATRibbonHomotopyCGM_H
#define CATRibbonHomotopyCGM_H

// COPYRIGHT DASSAULT SYSTEMES 1999
// fCH 2002
//===========================================================================
// 22/11/19 NLD Ajout Init0()
//              Ajout argument oError à Init() et Init_TriTangent()
//              Ajout argument oError aux  quatre constructeurs
//===========================================================================
#include "Fillet.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATTopRibbonHomotopy.h"
#include "CATFace.h"
#include "CATIACGMLevel.h"
#include "CATPoint.h"
#include "CATBlendParams.h"
#include "CATCGMNewArray.h"

class CATBody;
class CATCurve;
class CATPlane;

class CATEdge;
class CATGeoFactory;
class CATConnectTool;
class CATConnectStartHomotopy;
class CATConnectStartInPlane;
class CATIPGMConnectTool;
class CATStartOnNonAdjacentFaces;
class CATMathPoint;
class CATMathDirection;
class CATXParam;
class CATConnectStartInPlaneBase;
class CATError;


//--------------------------------------------------------------------------
// class CATRibbonHomotopyCGM
// -------------------------------------------------------------------------

class ExportedByFillet CATRibbonHomotopyCGM : public CATTopRibbonHomotopy
{
  public :

//--------------------------------------------------------------------------
// Constructor
// With an Edge of a Body and a point on this edge,
// returns the previsu of a fillet or a chamfer.
//--------------------------------------------------------------------------

// in all constructors; error ùmay be given back if oError received
// if no error is thrown
// NLD221119
    CATRibbonHomotopyCGM(       CATGeoFactory        *  iFactory    ,
                                CATTopData           *  iTopData    ,
                                CATBody              *  iBody       ,
                                CATEdge              *  iEdge       ,
                          const CATMathPoint          & iPoint      ,
                          const CATConnectTool       *  iProfilePtr ,
                                CATError             ** oError      = NULL);

    CATRibbonHomotopyCGM(       CATGeoFactory        *  iFactory    ,
                                CATTopData           *  iTopData    ,
                                CATBody              *  iBody       ,
                                CATEdge              *  iEdge       ,
                          const CATMathPoint          & iPoint      ,
                                CATIPGMConnectTool   *  iIProfilePtr,
                                CATError             ** oError      = NULL);

// New constructor introduced to deal with TriTangent configuration
    CATRibbonHomotopyCGM(       CATGeoFactory        *  iFactory    ,
                                CATTopData           *  iTopData    ,
                                CATBody              *  iBody       ,
                                CATFace              *  iLeftFace   ,
                                CATFace              *  iRightFace  ,
                                CATFace              *  iCentreFace ,
                          const CATOrientation       *  iOrientation,
                          const CATMathDirection     *  iDir        ,
                          const CATMathPoint          & iPoint      ,
                          const CATConnectTool       *  iProfilePtr ,
                                CATError             ** oError      = NULL);

    CATRibbonHomotopyCGM(       CATGeoFactory        *  iFactory    ,
                                CATTopData           *  iTopData    ,
                                CATBody              *  iBody       ,
                                CATFace              *  iLeftFace   ,
                                CATFace              *  iRightFace  ,
                                CATFace              *  iCentreFace ,
                          const CATOrientation       *  iOrientation,
                          const CATMathDirection     *  iDir        ,
                          const CATMathPoint          & iPoint      ,
                                CATIPGMConnectTool   *  iIProfilePtr,
                                CATError             ** oError      = NULL);

  CATCGMNewClassArrayDeclare;      // Pool allocation

//--------------------------------------------------------------------------
// Destructor
//--------------------------------------------------------------------------
  ~CATRibbonHomotopyCGM ();

//--------------------------------------------------------------------------
// Assign Ribbon Params
//--------------------------------------------------------------------------
  void SetRibbonParams(CATBlendParams &iRibbonParams);

//--------------------------------------------------------------------------
// Method GetCurve
// returns a circle (fillet) or a line (chamfer)
//--------------------------------------------------------------------------
  /**
  *  Method GetCurve : Available when Diagnostic=1 or 2
  *  returns the curve solution
  *  is a line (chamfer) or a circle (fillet).
  */
  CATCurve * GetCurve();
//--------------------------------------------------------------------------
// Method GetResult
// returns a circular surface Body
//--------------------------------------------------------------------------

  CATBody* GetResult();

//--------------------------------------------------------------------------
// GetPoints
// gives the UV-point solutions.
// returns TRUE if points have been computed.
//--------------------------------------------------------------------------
  CATBoolean GetPoints(CATSurParam  & oPointOnSupport1, CATSurface *& oSupport1,
                       CATSurParam  & oPointOnSupport2, CATSurface *& oSupport2);

//--------------------------------------------------------------------------
// GetPoints
// gives the 3D points solutions.
// returns TRUE if points have been computed.
//--------------------------------------------------------------------------
  CATBoolean GetPoints(CATMathPoint  & oPointOnSupport1,
                       CATMathPoint  & oPointOnSupport2);

//--------------------------------------------------------------------------
  //--------------------------------------------------------------------------
  CATBoolean GetNormal(CATMathVector  & oNormal);

//--------------------------------------------------------------------------



// Method Run
//--------------------------------------------------------------------------

  int Run();

//--------------------------------------------------------------------------
// Method GetDiagnostic
// Returns
// 0 if there is no solution
// 1 if there is an exact solution
// 2 if the solution is obtained with the tangent planes
//--------------------------------------------------------------------------

  CATLONG32 GetDiagnostic();

  void GetInitialSupports(CATFace *& Support1, CATFace *& Support2);
  void GetSupports       (CATCell *& Support1, CATCell *& Support2);
  void GetBumpers        (CATCell *& oBumper1, CATCell *& oBumper2);
  void GetXParams        (CATXParam &oParamOnSupport1, CATXParam &oParamOnSupport2);
  void GetInitialSupports(ListPOfCATCell &oListSup);

//--------------------------------------------------------------------------
// GetCrescentBody
// returns a crescent shape plane Body
//--------------------------------------------------------------------------

  CATBody*  GetCrescentBody();

  //KY1 : 04-02-2011

  /**  @nodoc @nocgmitf*/
  static const  CATString  *GetDefaultOperatorId();

protected:
  //KY1 : 04-02-2011

  /**  @nodoc*/
                 int         RunOperator();
  /**  @nodoc @nocgmitf */
  static         CATString  _OperatorId;
  /**  @nodoc @nocgmitf */
          const  CATString  *GetOperatorId();
  /**  @nodoc @nocgmitf */
                 void        RequireDefinitionOfInputAndOutputObjects();


private:
  CATBody*  GetCircularBody();

  void Init0          ();
  void Init           (       CATGeoFactory       *  iFactory     ,
                              CATTopData          *  iTopData     ,
                       const CATConnectTool       *  iProfilePtr  ,
                             CATIPGMConnectTool   *  iIProfilePtr ,
                             CATError             *& oError       );

  void Init_TriTangent(      CATGeoFactory        * iFactory      ,
                             CATTopData           * iTopData      ,
                       const CATConnectTool       * iProfilePtr   ,
                             CATIPGMConnectTool   * iIProfilePtr  ,
                             CATError             *& oError       );

  void GetDiscDefiningPoints_TriTangent          ( CATMathPoint &Centre, CATMathPoint &Point1, CATMathPoint &Point2, double &radius );
  void AdjustDiscDefiningPointsWithDir_TriTangent( CATSoftwareConfiguration *Config,
                                                   CATMathPoint &Centre, CATMathPoint &Point1, CATMathPoint &Point2, double &radius );
//---------------------------------------------------------------------------
// CreateCrescentBody
// Create a crescent shape face on a plane defined by 4 points
//---------------------------------------------------------------------------
  CATBody* CreateCrescentBody(CATMathPoint  & iPoint1,
                              CATMathPoint  & iPoint2,
                              CATMathPoint  & iCentre1,
                              CATMathPoint  & iCentre2,
                              CATTopData    * iTopData);

private :
  CATBlendParams               _RibbonParams;
  CATCurve                   * _CurveOut;
  CATBoolean                   _IsExecuted, _StartNonAdjacent, _OrientationGuess;
  CATFace                    * _Face[2];
  CATStartOnNonAdjacentFaces * _NonAdjOpe;
  CATBoolean                   _ValidForRun;
  const CATConnectTool       * _Profile;

  CATBody                    * _iBody;
  CATEdge                    * _iEdge;
  CATFace                    * _iLeftFace;
  CATFace                    * _iRightFace;
  CATFace                    * _iCentreFace;
  CATOrientation               _Orientation[3];
  const CATMathDirection     * _iDir;
  CATMathPoint                 _iPoint;
  CATMathVector                _TgtVect;
  CATConnectStartHomotopy    * _CoSt;
  CATConnectStartInPlaneBase * _CoStInPl;
};

#endif


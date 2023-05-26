// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATSketchGeodesicCx2 :
// Implementation class for Geodesic Topological Point Dir operator.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//=============================================================================
// July 98  Creation                                                  GDR
// Feb 2002 Modification  -> derivation de CATTopOperator             AOV
// Nov 2005 Ajout ModeJorn pour suivi des vertex extr dans le journal AOV
//=============================================================================
#ifndef CATSketchGeodesicCx2_H
#define CATSketchGeodesicCx2_H

#include "CATSketchGeodesic.h"
#include "CATMathDef.h"
//#include "AdvTopoSketch.h"
#include "AdvTopoSketchLight.h"
#include "ListPOfCATFace.h"


class CATSketchOperatorsCx2;
class CATGeoFactory;
class CATMathVector;
class CATBody;
class CATShell;
class CATFace;
class CATEdge;
class CATSurface;
class CATVertexInFace;
class CATVertex;
class CATPointOnSurface;
class CATSurParam;
class CATCurve;
class CATPCurve;
class CATCGMJournalList;
class CATTopData;
class CATAdvTopoOpeInputError;
class CATTopoGeodesicResultCx2;
class CATSketchResultIteratorCx2;

#include "CATTopOperator.h" // Temporaire
//-----------------------------------------------------------------------------
class ExportedByAdvTopoSketchLight CATSketchGeodesicCx2 : public CATSketchGeodesic
{
 public:
   
   //Constructor 
   //wk 43 2005 aov:ajout iModeJourn pour suivi des vertex extremites de la line dans le journal
   CATSketchGeodesicCx2 (CATGeoFactory     * iFactory, 
                         CATTopData        * iData,
                         CATGeometry       * iSupport,
                         CATGeometry       * iPoint,
                         CATMathVector     * iTangent,
                         CATPositiveLength   Length,
                         CATBody           * iTargetBody,
                         int                 iModeJourn=0);
   //  Deprecated 
   CATSketchGeodesicCx2 (CATGeoFactory     * iFactory, 
                         CATGeometry       * iSupport,
                         CATGeometry       * iPoint,
                         CATMathVector     * iTangent,
                         CATPositiveLength   Length,
                         CATBody           * iTargetBody,
                         CATCGMJournalList * iReport);
    
   //  Destructor 
   virtual ~CATSketchGeodesicCx2          ();
   
   //  Methods 
   void       SetTolerance (double iTolerance); // Tolerance de calcul passee a la fonctionnelle
   
   int        Run                         ();
   void       RemoveWire                  ();   
   
   void       ChangeSupport               (CATGeometry * iSupport);
   void       ChangePoint                 (CATGeometry * iPoint);
   void       ChangePoint                 (CATGeometry * iFace,CATSurParam * iParam);
   void       ChangeTangent               (CATMathVector * iTangent);
   void       ChangeLength                (CATPositiveLength iLength);
   
   void       GetResult                   (CATBody *& oBody);
   CATLONG32       GetNumberOfResults          () const ;
   void       BeginningResult             ();
   CATBoolean NextResult                  ();
   void       GetWire                     (CATWire *& iWire) const ;
   void       GetInternalResult  (CATSketchResultIteratorCx2 *& oRes);

   void       GetFinalPoint      (CATLONG32 & oNbFace,CATFace **& oFace,CATSurParam *& oParam,CATLength & oLength) const ;
   void       SetMeasureCrossedGaps(int iMeasureCrossedGaps);
   void       SetCrossedGaps(double *ioCrossedGaps);
   void       GetSupportFaces(CATLISTP(CATFace)& ioSupportFaces);

   // ---------------
   // methods for CGM Replay 
   // ---------------
   static const CATString *GetDefaultOperatorId() { return &_OperatorId; }

protected :
  static CATString  _OperatorId;
  int               RunOperator ();
  CATBody          *GetResult ();
  const  CATString *GetOperatorId ();
  CATExtCGMReplay  *IsRecordable (short &LevelOfRuntime, short &VersionOfStream);
  CATBoolean        GivesValidJournalAsResult(CATCGMJournalList **ioDuplicatedButExpectedValid) const;
  void              WriteInput (CATCGMStream &ioStream);
  void              RequireDefinitionOfInputAndOutputObjects ();
  void              Dump (CATCGMOutput &os);
 
  void   Cleaner                         ();
  CATAdvTopoOpeInputError * InitSupportGeometry (CATGeometry* iSupport);
  CATAdvTopoOpeInputError * InitPointGeometry (CATGeometry  * iPoint);
  CATAdvTopoOpeInputError * InitPointGeometry (CATGeometry  * iSupportPoint,CATSurParam  * iParam);
  CATAdvTopoOpeInputError * ValidGeometry     ();
  
private:
  
  CATGeoFactory             * _Factory;
  CATBody                   * _TargetBody;
  CATBody                   * _FinalBody;
  CATCGMJournalList         * _Report;
  CATMathVector             * _Tangent;
  CATPositiveLength           _Length;
  
  CATBody                   * _BodySupport;
  CATShell                  * _ShellSupport;
  CATFace                   * _FaceSupport;
  CATSurface                * _SurfaceSupport;
  
  CATVertexInFace           * _VtxInFace;
  CATVertex                 * _Vtx;
  CATPointOnSurface         * _PtOnSurface;
  CATFace                   * _FaceSupportPoint;
  CATSurface                * _SurfaceSupportPoint;
  CATSurParam               * _ParamOnSurface;
  
  CATSketchOperatorsCx2     * _StartResult;
  CATSketchOperatorsCx2     * _CurrentResult;
  
  double                      _FunctionTolerance;
  int                         _ModeJourn;//aov wk43 2005 pour suivi des vertex dans le journal
  int                         _MeasureCrossedGaps;//ize wk29 2008 Measure gap lengths
  double                    * _CrossedGaps;

	CATBoolean _InsertJournalAttheEndOfRun;

};
#endif


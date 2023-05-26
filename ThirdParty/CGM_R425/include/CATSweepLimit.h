#ifndef CATSWEEPLIMIT_H
#define CATSWEEPLIMIT_H

//--------------------------------------------------------------------------
// classe des Limits de Sweep
//--------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999
//--------------------------------------------------------------------------

#include "CATMathDef.h"
#include "BO0SWEEP.h"
#include "CATBooleanType.h"
#include "ListPOfCATCell.h"
#include "CATTopData.h"
#include "CATCGMOutput.h"
#include "CATSweepLimitDef.h"
#include "CATMathInline.h"
#include "CATListOfCATGeometries.h"
#include "CATExtrudeLimitSide.h"
#include "CATExtrudeLimitThicknessOrOffsetType.h"
#include "CATExtrudeLimitName.h"

class CATBody;
class CATCell;
class CATVertex;
class CATMathLine;
class CATMathBox;
class CATMathBox2D;
class CATGeometry;
class CATMathPoint;
class CATMathPlane;
class SweepOper;
class CATSweepReferenceWire;
class CATSweep;
class CATCGMJournalList;
class CATLISTP(CATGeometry);
class CATSweepRelimit3;

#ifdef CATIACGMR418CAA
#define LIST_NAMING_ACTIVE
#endif

//
//
//--------------------------------------------------------------------------
// classe des Limits de Sweep
// --------------------------
//
//
//
//
//
class ExportedByBO0SWEEP CATSweepLimit
{

public :

  // Constructeur
  // Constructor for when we want to set a limiting geometry.
  // If we have a dimension limit, don't set the propagation body to NULL or the flag to Single because
  // we rely on the propagation body in CGMOldTopologyTests.tst, CGMTest_ThinSolid.
  CATSweepLimit ( CATTopData         & iData           ,
                  CATLimit             iId             ,
                  CATLimitType         iType           ,
                  CATBoolean           iIsAxisReverted ,
                  CATLength            iOffset         ,
                  CATGeometry        * iLimit          ,
                  CATBody            * iPropagationBody,
                  CATPropagationType   iPropagationFlag,
                  CATBoolean           iIsThickness    = CATBoolean(0));

  // Constructor for when we want to set a list of limiting cells.
  // If we have a dimension limit, don't set the propagation body to NULL or the flag to Single because
  // we rely on the propagation body in CGMOldTopologyTests.tst, CGMTest_ThinSolid.
  CATSweepLimit ( CATTopData         & iData           ,
                  CATLimit             iId             ,
                  CATLimitType         iType           ,
                  CATBoolean           iIsAxisReverted ,
                  CATLength            iOffset         ,
                  ListPOfCATCell     & iLimitCells     ,
                  CATBody            * iPropagationBody,
                  CATPropagationType   iPropagationFlag,
                  CATBoolean           iIsThickness    = CATBoolean(0));
  CATSweepLimit (const CATSweepLimit & iLimit);

  // Destruteur
  ~CATSweepLimit();

  // Acces en lecture
         CATLimit                             GetId                 ();
         CATBoolean                           GetAxisWasAutoInverted();
  INLINE CATLimitType                         GetType               ();
  INLINE CATBoolean                           IsAxisReverted        ();
  INLINE CATLength                            GetOffset             ();
  INLINE CATBody                            * GetPropagationBody    ();
  INLINE CATBoolean                           GetPropagationBodyToDelete ();
  INLINE CATPropagationType                   GetPropagationFlag    ();
  INLINE double                               GetExtraValue         ();
  INLINE CATVertex                          * GetAssociateCell      ();
  INLINE int                                  GetStatus             ();
  INLINE CATBoolean                           GetThickness          ();
  INLINE CATExtrudeLimitThicknessOrOffsetType GetThicknessOrOffsetType ();
  INLINE CATExtrudeLimitSide                  GetSide               ();
  INLINE CATLONG32                          * GetIntersectionNumber ();
  INLINE CATSweepReferenceWire              * GetSweepReferenceWire ();
  INLINE CATBoolean                           GetExtrudeLimitNamingRequested();
  INLINE CATBoolean                           GetConvertedFromDim   ();
  INLINE CATBoolean                           GetConvertedAfterSelection();
  INLINE CATBoolean                           GetConvertedFromContextualOffset();
  INLINE CATBoolean                           GetNamingDone         ();

         CATGeometry                        * GetLimit              ();
         CATGeometry                        * GetLimitInitial       ();
         void                                 GetLimitsNonInitial   (CATLISTP(CATGeometry)&);
   const ListPOfCATCell                     * GetListOfLimitCells   (); 
   const ListPOfCATCell                     & GetBrepCellList       ();
         ListPOfCATCell                     * GetFinalBrepCell      ();
         SweepOper                          * GetOperation          ();
  
         CATBody                            * GetInitialLimitAsBody (  CATGeoFactory * iGeoFactory, CATBoolean & oNewBodyCreated );
         void                                 GetExtrudeLimitNaming ( CATListPOfCATExtrudeLimitName * oPosibleLimits );
         void                                 GetExtrudeLimitNaming ( CATListPV * oPosibleLimits );
  // Acces en ecriture
  INLINE void                                 SetPropagationFlag    (CATPropagationType);
  INLINE void                                 SetExtraValue         (double               iValue);
  INLINE void                                 SetAssociateCell      (CATVertex          * iVertex);
  INLINE void                                 SetBrepCellList       (int                  iSize);
  INLINE void                                 SetSide               (CATExtrudeLimitSide iSide);
         void                                 SetIntersectionNumber (CATLONG32          * iIntersectionNumber);
  INLINE void                                 SetAxisReversion      (CATBoolean           iAxisReversion);
  INLINE void                                 SetStatus             (int                  iStatus);
         void                                 SetType               (CATLimitType         iType);  
         void                                 SetOffset             (CATLength            iOffset);
         void                                 SetBrepCell           (int                  ipos   ,
                                                                     CATCell            * iBrepCell);  
         void                                 SetFinalBrepCell      (ListPOfCATCell     * iFinalBrepCell ,
                                                               const int                  iReplaceMode = 0      );
         void                                 SetRelimitationMode   (short                iMode        ,
                                                                     short                iAutomaticDirectionInversion);
         void                                 SetLimit              (CATGeometry        * iLimit,
                                                               const int                  iResetInitial = 0 );
         void                                 SetPropagationBody    (CATBody            * iPropagtionBody,
                                                                     CATBoolean           iPropagationBodyToDelete = FALSE);
         void                                 SetConvertedFromDim   (CATBoolean           iConverted);
         void                                 SetConvertedAfterSelection(CATBoolean       iConverted);
         void                                 SetConvertedFromContextualOffset(CATBoolean iConverted);
         void                                 SetLimitThickness     (CATLength            iOffset,
                                                                     CATExtrudeLimitThicknessOrOffsetType iThicknessOrOffsetType );
         void                                 SetExtrudeLimitNamingRequested
                                                                    (CATBoolean           iRequested );
  INLINE void                                 SetSweepReferenceWire (CATSweepReferenceWire * iSweepReferenceWire,
                                                                     CATBoolean           iManageSweepRefWireDestruction );


  // Divers
         void                                 Dump                  (CATCGMOutput       & os );
         double                               ExtraEvaluation       (CATMathBox2D       * Box2D,
                                                                     CATMathLine        * iLine,
                                                                     double               iEpaisseur,
                                                                     double             & oMin,
                                                                     double             & oMax);
         double                               ExtraCalculation      (double               iFixlimit,
                                                                     double               iVarMin,
                                                                     double               iVarMax,
                                                                     double               iVarMean);
  
         void                                 CreateNaming         ( CATSweep           * iSweep   ,
                                                                     CATCGMJournalList  * iReport  ,
                                                                     CATBody            * iProfBodyInitial );
  // Create a copy of the limit or an inverse of it.
         CATSweepLimit                      * CreateCopyLimit      ( CATBoolean           iCreateInverse);

protected :

  // Methods
         void                                 Init                 (
                                                                    CATLimit             iId             ,
                                                                    CATLimitType         iType           ,
                                                                    CATBoolean           iIsAxisReverted ,
                                                                    CATLength            iOffset         ,
                                                                    ListPOfCATCell     * iLimitCells     ,
                                                                    CATGeometry        * iLimit          ,
                                                                    CATBody            * iPropagationBody,
                                                                    CATPropagationType   iPropagationFlag,
                                                                    CATBoolean           iIsThickness    );

         void                                 BoxEvaluation        (CATMathBox2D       * Box2D           ,
                                                                    CATMathLine        * iLine           ,
                                                                    double             & oMin            ,
                                                                    double             & oMax            );
         CATBoolean                           InterEvaluation      (CATMathLine        * iLine           ,
                                                                    double             & oMean           );
         void                                 CreateListNaming     ();

  //=============================================================
  // Datas
  //-------------------------------------------------------------
  // InputData
  // 
  CATTopData            _TopData;
  CATLimit              _Id;
  CATLimitType          _Type;
  CATBoolean            _IsAxisReverted;          // suivant l'axe ou son oppose
  CATLength             _Offset;                  // offset
  CATLISTP(CATGeometry) _Limits;                  // List of initial limit and any derived limits
  CATBody             * _PropagationBody;         // body de propagation
  CATBoolean            _PropagationBodyToDelete; // If the propagationBody is an intermediate body.
  CATPropagationType    _PropagationFlag;         // single/closing/extrapolated

  CATExtrudeLimitSide   _Side;
  CATLONG32           * _IntersectionNumber; //Number of the intersection on the requested sid in the direction of extrusion.
  CATSweepReferenceWire * _SweepReferenceWire;
  CATBoolean            _ManageSweepRefWireDestruction;
  CATBoolean            _ExtrudeLimitNamingRequested;
  CATBoolean            _NamingDone;
  CATSweepRelimit3    * _SweepRelimitForNaming;
  CATTopData          * _TopDataForNaming;

  CATBoolean            _IsThickness;      // thickness par rapport a la limitante
  CATExtrudeLimitThicknessOrOffsetType _ThicknessOrOffsetType;  // if we must offset the contextual limit before extrusion
                                                                // (mostly for SW and surfacic cases),
                                                                //  or apply a thickness on the final result

  // Output
#ifdef LIST_NAMING_ACTIVE
  CATListPOfCATExtrudeLimitName _PossibleLimits;
#else
  CATListPV _PossibleLimits;
#endif

  //------------------------------------------------------------
  // InternalData
  ListPOfCATCell   _LimitCells;
  double           _ExtrapolationValue;
  CATVertex      * _AssociateCntCell;
  ListPOfCATCell   _BrepCellList;
  int              _Status;
  ListPOfCATCell * _FinalBrepCell;
  // For limit selection, we replace the old limit by a new one coming from the transition 
  // calculated in CATSweepRelimit3
  CATBody        * _TransitionLimitBody;

  /**
 * Enables the choice of the limitation algorithm.
 * _RelimitationMode
 * 1 just as Mode 2 plus SetOldShapeRequested(1).
 * 2 is the first enabled mode.
 * 3 has been enabled since the V5R6.
 * 4 has been enabled since the V5R7.
 * 5 has been enabled since the V5R10.
 * 6 has been enabled since the V5R11.
 */
  short            _RelimitationMode;
  /*
  * @param _AutomaticDirectionInversion
  * This parameter has an effect when one of the limit is a offset value and the second one is the contextual limit ( UP TO .. )
  * Mode 0 : the contextual limit is searched according only to the extrusion direction.
  * Mode 1 : enable to automatic revert the extrusion direction when no limit was found in the extrusion direction ( default mode ).
  */
  short            _AutomaticDirectionInversion;

  CATBoolean       _ConvertedFromDim;
  CATBoolean       _ConvertedAfterSelection;
  CATBoolean       _ConvertedFromContextualOffset;
  CATBoolean       _AxisWasAutoInverted;		// Whether the axis was automatically inverted.
  //=================================================================
};
//
//
//--------------------------------------------------------------------------
// fonctions globales
// ------------------
//
//
CATMathPoint * BoxGravityCenter(CATMathBox &iBox);
//
void           BoxCalculation  (CATMathBox   &iBox,
                                CATMathLine * iLine,
                                double       &oMin,
                                double       &oMax);
//
void           MeanCalculation (CATMathBox   &iBox,
                                CATMathLine * iLine,
                                double       &oMean);
//
CATMathBox2D * Box2DCalculation(CATMathBox   &iBox,
                                CATMathLine * iLine);
//
ExportedByBO0SWEEP
CATMathBox     BoxCalculation  (CATGeometry * iGeometry);
//
int            PlanePositioning(CATMathPlane &iPlane, CATBody * iBody,
                                double & oPuissanceMean);
//
CATBoolean     BodyProjection  (ListPOfCATCell VertexList,
                                CATBody      * CenterContour,
                                int          & oNumEdge,
                                double       & oMean,
                                double       & oMin,
                                double       & oMax,
                                CATVertex  * & VertexMin,
                                CATVertex  * & VertexMax,
                                CATSoftwareConfiguration * iConfig);
//
CATBoolean     BodyProjection  (ListPOfCATCell VertexList,
                                CATMathLine  & iLine,
                                int          & oNumEdge,
                                double       & oMean,
                                double       & oMin,
                                double       & oMax,
                                CATVertex  * &VertexMin,
                                CATVertex  * &VertexMax);

//-----------------------------------------------------------------------
//                             INLINE
//-----------------------------------------------------------------------
INLINE double   CATSweepLimit::GetExtraValue ()
{
 return _ExtrapolationValue; 
}
//
INLINE void CATSweepLimit::SetExtraValue (double iValue)
{
 _ExtrapolationValue = iValue; 
}
//
INLINE CATVertex * CATSweepLimit::GetAssociateCell ()
{
 return _AssociateCntCell; 
}
//
INLINE void CATSweepLimit::SetAssociateCell (CATVertex * iVertex)
{
 _AssociateCntCell = iVertex; 
}
//
INLINE void CATSweepLimit::SetBrepCellList (int iSize)
{
 _BrepCellList.Size(iSize); 
}
//
INLINE void CATSweepLimit::SetStatus (int iStatus)
{
 _Status = iStatus; 
}
//
INLINE int CATSweepLimit::GetStatus ()
{
 return  _Status;
}
//
INLINE CATBoolean CATSweepLimit::GetThickness ()
{
 return _IsThickness;
}
//
INLINE CATExtrudeLimitThicknessOrOffsetType CATSweepLimit::GetThicknessOrOffsetType ()
{
 return _ThicknessOrOffsetType;
}
//
INLINE CATLimitType CATSweepLimit::GetType ()
{
 return _Type;
}
//
INLINE CATBoolean CATSweepLimit::IsAxisReverted ()
{
 return _IsAxisReverted;
}
//
INLINE void CATSweepLimit::SetAxisReversion (CATBoolean iAxisReversion)
{
 _IsAxisReverted =iAxisReversion;
}
//
INLINE CATLength  CATSweepLimit::GetOffset ()
{
 return _Offset;
}
//
INLINE CATBody *  CATSweepLimit::GetPropagationBody ()
{
 return _PropagationBody;
}
//
INLINE CATBoolean CATSweepLimit::GetPropagationBodyToDelete ()
{
 return _PropagationBodyToDelete;
}
//
INLINE void  CATSweepLimit::SetPropagationFlag (CATPropagationType iPropag)
{
  _PropagationFlag = iPropag;
}
//
INLINE CATPropagationType CATSweepLimit::GetPropagationFlag ()
{
 return _PropagationFlag;
}


INLINE CATBoolean CATSweepLimit::GetConvertedFromDim()
{
 return _ConvertedFromDim;
}

INLINE CATBoolean CATSweepLimit::GetConvertedAfterSelection()
{
 return _ConvertedAfterSelection;
}

INLINE CATBoolean CATSweepLimit::GetConvertedFromContextualOffset()
{
 return _ConvertedFromContextualOffset;
}

INLINE CATExtrudeLimitSide CATSweepLimit::GetSide ()
{
 return _Side;
}

INLINE CATLONG32 * CATSweepLimit::GetIntersectionNumber()
{
 return _IntersectionNumber;
}

INLINE CATSweepReferenceWire * CATSweepLimit::GetSweepReferenceWire ()
{
 return _SweepReferenceWire;
}
INLINE void CATSweepLimit::SetExtrudeLimitNamingRequested( CATBoolean iRequested )
{
 _ExtrudeLimitNamingRequested = iRequested;
}
INLINE CATBoolean CATSweepLimit::GetExtrudeLimitNamingRequested()
{
 return _ExtrudeLimitNamingRequested;
}
INLINE CATBoolean CATSweepLimit::GetNamingDone()
{
 return _NamingDone;
}
INLINE void CATSweepLimit::SetSide ( CATExtrudeLimitSide iSide)
{ 
   _Side = iSide;
   if ( iSide != CATExtrudeLimitSideUnset )
      _ExtrudeLimitNamingRequested = TRUE;
}
INLINE void CATSweepLimit::SetSweepReferenceWire( CATSweepReferenceWire * iSweepReferenceWire,
                                                  CATBoolean              iManageSweepRefWireDestruction )
{
   _SweepReferenceWire = iSweepReferenceWire;
   _ManageSweepRefWireDestruction = iManageSweepRefWireDestruction;
}

//
//--------------------------------------------------------------------------
// classe des operations  de Sweep
// -------------------------------
//
class ExportedByBO0SWEEP SweepOper
{
  protected :
  CATBoolType      _Type;
  CATGeometry *    _TrimBody;
//
//
  public :
// constructeur
  SweepOper  (CATBoolType iBoolType,
              CATGeometry * iTrimBody);
// destruteur
  ~SweepOper();
// acces en lecture
  INLINE CATBoolType GetType ();
  INLINE CATGeometry *  GetBody ();
};
//-----------------------------------------------------------------------
//                             INLINE
//-----------------------------------------------------------------------
INLINE CATBoolType SweepOper::GetType ()
{
 return _Type;
}
//
INLINE CATGeometry * SweepOper::GetBody ()
{
 return _TrimBody;
}
//
#endif

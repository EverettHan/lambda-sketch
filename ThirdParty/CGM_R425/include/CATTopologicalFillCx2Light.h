// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
//
// CATTopologicalFillCx2Light :
// Implementation class for light topological Fill operator.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//          tpg Creation Fill                                    Tuan-Anh Phung
// Nove  08 ASE Creation (split light)                               Alex State
// 15/10/10 ky1 RequireDefinitionOfInputAndOutputObjects()
// 15/12/10 ky1 _OperatorId, GetOperatorId(), GetDefaultOperatorId(), RunOperator()
// 15/02/11 ky1 _InsertJournalAttheEndOfRun
// 24/03/11 mps WriteInput(), Dump()
//              _ContinuityInfo, _TangencyInfo,
//              _CenterPoint, _ListOfEdges, _ListOfFaces
// 18/05/11 mps IsRecordable()
// 24/10/18 dps RunExactOperator(), RunPolyOperator()
// 21/10/20 NLD Ajout InitData12()
// 02/11/20 NLD Ajout _PureLight
//=============================================================================
#ifndef CATTopologicalFillCx2Light_H
#define CATTopologicalFillCx2Light_H

#include "FrFTopologicalOpeLight.h"
#include "CATTopologicalFillLight.h"
#include "CATMathDef.h"
#include "CATLISTP_Define.h"
//define DEBUGValidateEdge

class CATGeoFactory;
class CATBody;
class CATGeometry;
class CATSurface;
class CATNurbsSurface;
class CATCurve;
class CATPCurve;
class CATCrvLimits;
class CATPLine; 
class CATMathPoint;
class CATMathVector;
class CATKnotVector;
class CATFillSurfaceResult;
class CATFrFCompositeCurve;
class CATFillSurface;
class CATFrFCCvLimits;
class CATFrFCCvParam;
class CATCGMJournalList;
class CATPlane;
class CATVertex;
class CATEdge;
class CATFrFNurbsMultiForm;
class CATShell;
class CATFrFMultiComb;
class CATCrvParam;


//-----------------------------------------------------------------------------
class ExportedByFrFTopologicalOpeLight CATTopologicalFillCx2Light : public CATTopologicalFill
{
 public:
//=============
//  Constructor
//=============
  CATTopologicalFillCx2Light (      CATGeoFactory  * iFactory,
                                    CATTopData     * iTopData,
                                    CATLONG32        iNumberOfWires,
                              const CATBody       ** iTableOfWires);

  CATTopologicalFillCx2Light (      CATGeoFactory  * iFactory,
                                    CATTopData     * iTopData,
                                    CATLONG32        iNumberOfWires,
                              const CATBody       ** iTableOfBodyWires,
                              const CATBody       ** iTableOfBodySupports);

  CATTopologicalFillCx2Light (      CATGeoFactory  * iFactory,
                                    CATTopData     * iTopData,
                              const ListPOfCATEdge * iListOfEdges,
                              const ListPOfCATFace * iListOfFaces,
                              const CATBody        * iBody);
  
//============
//  Destructor 
//============
  virtual ~CATTopologicalFillCx2Light ();

//=========
//  Methods
//=========
  virtual int         Run               ();

//Validation methods
  virtual double      GetG0MaxDeviation ();

  virtual CATAngle    GetG1MaxDeviation ();

  virtual double      GetG0MaxAccuracy  ();

  virtual double      GetG0MaxDeviation (const CATEdge * iEdge, CATMathPoint * ioMaxPoint=NULL);

  virtual CATAngle    GetG1MaxDeviation (const CATEdge * iEdge, CATMathPoint * ioMaxPoint=NULL);

// return the result from the fill operator.
  virtual CATBody   * GetResult();

// returns the type of Fill result  
// in  this case  it returns  analytic 
  virtual CATFillType GetFillType ();

// Geometrical check of Fill result
// 1 : the result  is ok
// 0 : the result is not ok  
  virtual CATLONG32   Check();


//
//  Set the transition
//
  virtual void        SetTransitionContinuity(const CATLONG32 iSide, const CATLONG32 icont);
//
//  Set the tangency parameter 
//
  virtual void        SetTangencyParameter(const CATLONG32 iside,
                                           const double iTangencyParameter);

//
//  Set the Simplify option. Only available in FreeStyle.
//
  virtual void        SetSimplifyOption(CATBoolean iSimplify=TRUE);


//
//  The required maximum  tolerance on the result surface 
//
  virtual void        SetGapTolerance( const double iTolerance);

//-----------------------------------------------------------------------------
//  Center point management
//  useless when filling a four side hole
//-----------------------------------------------------------------------------
//
  virtual void        GetCenterPoint(CATVertex &ioCenterPoint);
  virtual CATBoolean  IsCenterPointCreated() const;
  virtual void        SetCenterPoint(CATVertex & iCenterPoint);  
  virtual void        ResetCenterPoint(); 

//-----------------------------------------------------------------------------
// Input validation mode, it is the default mode
// + iMode = 1 : activate the input validation mode
// + iMode = 0 : turn off the input validation mode
//-----------------------------------------------------------------------------
// 
// Set Methods 
// 
  virtual void        SetInputValidationMode(const CATLONG32 iMode = 1);

//-----------------------------------------------------------------------------
// Flat face mode (to create a flat face if the hole is flat), it is not
// the default mode
// + iMode = 1 : activate the flat face mode
// + iMode = 0 : turn off the flat face mode
//-----------------------------------------------------------------------------
// 
// Set Methods 
// 
  virtual void        SetFlatFaceMode(const CATLONG32 iMode = 1);

//-----------------------------------------------------------------------------
// Change the standart Fill skin orientation
//-----------------------------------------------------------------------------
  virtual void        OrientationByFirstEdge();

//-----------------------------------------------------------------------------
// Set and Get the Fill Topology creation arguments
// The available creation parameters are :
//   * Level of topology s link. This flag is to be set before the first Run,
//     then it will not be taken into account. The available values are :
//        + Level = 0 : the created topology is not linked,
//                      it is the default value for the Fill use.
//        + Level = 1 : the created topology is linked with the input topology,
//                      it is the default value for the Extrapol use.
//-----------------------------------------------------------------------------
// 
// Set Methods 
//
  virtual void        SetLinkedTopology    (const CATLONG32 iLevel);

  virtual void        SetBody              (CATBody * ioBody, CATShell * ioShell);

  virtual void        SetSurfaceParameters (int  iDegreeU, int  iDegreeV, int  iNumberUOfPatch, int  iNumberVOfPatch);
  virtual void        GetSurfaceParameters (int &oDegreeU, int &oDegreeV, int &oNumberUOfPatch, int &oNumberVOfPatch);

// 
// Get Methods 
// 
  virtual CATLONG32   GetLinkedTopology    () const;

#ifdef CATIACGMV5R20
  virtual void        SetCanonicalDetection();
#endif

  //KY1 : 10-12-2010

  /**  @nodoc @nocgmitf*/ 
  static const  CATString  *GetDefaultOperatorId();

  //KY1 : 10-12-2010
  /**  @nodoc @nocgmitf*/
          int         RunOperator();

protected:

  /** Exact/PH management  */
  virtual int         RunExactOperator();
  virtual int         RunPolyOperator();

protected:
  /**  @nodoc @nocgmitf */
  static  CATString  _OperatorId;

  /**  @nodoc @nocgmitf */
  const  CATString  * GetOperatorId();

  /**  @nodoc @nocgmitf */
  void                RequireDefinitionOfInputAndOutputObjects();
  CATExtCGMReplay   * IsRecordable   (short & LevelOfRuntime, short &VersionOfStream);
  void                WriteInput     (CATCGMStream &Str);
  void                Dump           (CATCGMOutput& os );

 protected:

//=========
//  Methods
//=========
  virtual void       SetData                      (      CATGeoFactory     * iFactory,
                                                         CATLONG32           iNumberOfWires,
                                                   const CATBody          ** iTableOfBodyWires,
                                                   const CATBody          ** iTableOfBodySupports,
                                                         CATCGMJournalList * iJournal = NULL);

  virtual void       SetDataFromWires();

  virtual void       SetDataFromEdges             (const ListPOfCATEdge    * iListOfEdges,
                                                   const ListPOfCATFace    * iListOfFaces);

  virtual CATBoolean ProcessSingleEdgeWiresAsEdges(      ListPOfCATEdge     &iListOfEdges,
                                                         ListPOfCATFace     &iListOfFaces);

  virtual void       TrySetData                   (      CATGeoFactory     * iFactory,
                                                         CATLONG32           iNumberOfWires,
                                                   const CATBody          ** iTableOfBodyWires,
                                                   const CATBody          ** iTableOfBodySupports,
                                                         CATCGMJournalList * iJournal = NULL);

  virtual void       ValidateWires                ();
  virtual int        GeometryCreation             ();
  virtual void       ComputeTabOfCurves           ();

#ifdef DEBUGValidateEdge
  virtual void       ValidateEdges                ();
#endif


  // Creer les peignes au niveau topologique, si _MultiFormMode==1.
  // Cas ou les wires en entrees sont Multi cellules. Uniquement avec _GSDMode==1.
  virtual void        ExtractCombOfWires          ();
  virtual double      CalculJonction              (const CATMathPoint *Extr, const CATMathPoint *ExtrPrec, CATLONG32 &oE, CATLONG32 &oEPrec);
  virtual void        JournalConfigEtoile         ();
  virtual void        JournalConfigCarre          ();
  virtual void        JournalConfigMultiForm      ();

  //Merge de Body.
  //Pretraitement pour le merge de body ; recherche de parite edges entrees et sorties.
  virtual CATLONG32 * FindPairEdge                (CATEdge**& TabOfEdgeFill, int*& Inversion);

  //Realisation du merge.
  virtual int                    MergeCurrentsBodiesWithOutputBody();

  //Calcul de l'erreur sur le resultat (C0 et G1).
  //Met a jour les donnees _ErrG0 et _ErrG1.
  virtual void                   ComputeDeviation ();

//-------------------------------------------------------
// Methodes suivantes dediees au cas Pseudo 4 cotes.
// Les tableaux en entrees des methodes sans specification de taille,
// sont donc de taille 4.
//-------------------------------------------------------
  //Permet de simplifier les entrees. Detectections de continuite
  //sur les elements en entrees. Si simplification, _MultiFormMode==2.
  virtual void                   SimplifyInput    ();

  //Equivalent de ExtractCombOfWires, mais dans le cas _MultiFormMode==2. 
  virtual void                   ExtractCombOfCurves ();
  
  // Calcul de la longueur des nouvelles courbes apres concatenation en fonction
  // des continuites
  virtual void                   ComputeLenghtOfNewCrv(double* ioTabOfNewCrvLength);
  
  // Calcul de la tangente en un point interne d'une nouvelle courbe
  virtual void                   ComputeInternalTgt   (CATLONG32* Cont, CATLONG32 j,
                                                       CATLONG32 Ind, CATFrFMultiComb* Multi, CATCrvParam& LocalPar, CATMathVector* Tg,
                                                       double& ratio, CATMathVector& oTangente);

  // Approximation de 1 multicombs + OptimizeContinuities.
  // Si longueur, prise en compte dans l'optimize (les tolerances sont ramenees a 1).
  virtual CATFrFNurbsMultiForm * ApproximMultiComb    (CATFrFMultiComb * iMulti, const double * iMinLength=0);

  // Calcul des longueurs des peignes. Les multiforms sont "paralleles" et de meme orientations
  // et deja homogeneisees.
  virtual void                   ComputeLengthForCombs(CATFrFNurbsMultiForm * iMulti1, double &oRatio1Start, double &oRatio1End);

  virtual void                   ComputeLengthForCombs(CATFrFMultiComb      * iMulti1, double &oRatio1Start, double &oRatio1End);

  
  virtual void                   RescaleCombs         (CATFrFNurbsMultiForm * iMult, double iFactOnComb);

  // Creation des MultiCombs et eventuelle prise en compte de longueur pour les peignes.
  virtual CATFrFMultiComb     ** ComputeMultiComb     (const double * iLengthOfWires, double * iNormOfCombs=0);

  // Mise en compatibilite des peignes.
  virtual void                   RunCompatibility     (CATFrFMultiComb ** iMultiComb);

  // Utilisee par GetG0MaxDeviation et GetG1MaxDeviation, lorsque qu'une edge est passee.
  // Renvoie -1 si l'edge n'appartient pas a la topo en entree.
  virtual CATLONG32              RetrieveEdgeIndex    (const CATEdge * iEdge);

  virtual void                   InitData             ();
  
  private:
          void                   InitData12            (      CATTopData    * iTopData            ,
                                                              CATLONG32       iNumberOfWires      ,
                                                        const CATBody      ** iTableOfBodyWires   ,
                                                        const CATBody      ** iTableOfBodySupports);
  
  //======
  //  Data
  //======

  protected:

// Fill input
//------------
  CATGeoFactory                 *    _IFactory;
  CATLONG32                          _NumberOfWires;
  const CATBody                **    _TableOfWires;
  const CATBody                **    _TableOfSupports;
  CATPositiveLength                  _Resolution;
  CATCGMJournalList             *    _Journal;
  CATBody                       *    _BodyInput;
  CATShell                      *    _ShellInput;
  CATLONG32                          _OrnByFirstEdge; //Default is 0
  double                             _InputAccuracy;

// Fill output
//-------------
  CATBody                       *    _Skin; 

// Fill internal
//--------------
  CATLONG32                          _GSDMode;
  CATLONG32                          _MultiFormMode;
  CATFrFNurbsMultiForm         **    _MultiForms;
  int                                _PureLight; // permettra de distinguer classe mère et classe dérivée

  CATLONG32                          _NumberOfInitialCurves;
  CATLONG32                          _NumberOfCurves;
  CATEdge                      **    _TabOfInitialEdges;
  CATCurve                     **    _TabOfCurves;
  CATLISTP(CATGeometry)              _ListOfCurvesToDelete;
  CATCrvLimits                  *    _TabOfCrvLimits;
  CATLONG32                     *    _TransitionContinuityCrv;
  double                        *    _TangencyParameterCrv;

  CATFillSurface                *    _FillOpe;
  CATFrFCompositeCurve         **    _CompositeCurves;
  CATNurbsSurface              **    _SubSurfaces;
  CATLONG32                          _NumberOfSubSurfaces;

  CATPlane                      *    _SupportingPlane;
  CATPCurve                    **    _TabOfProjectedCurves;

  CATLONG32                     *    _CCvSize;

  CATMathPoint                  *    _fillcentre;
  CATMathPoint                  *    _imposedfillcentre;

  // parameters
  CATLONG32                     *    _WireOrientation;
  CATLONG32                     *    _TransitionContinuitySide;
  double                        *    _TangencyParameterSide;

  // computing state
  CATLONG32                          _ComputeState;

  // flat face mode
  CATLONG32                          _FlatFaceMode;
  CATBoolean                         _IsFlatFace;

  // triangular patch mode
  CATLONG32                          _TriangularPatchCreation;

  // input validation mode
  CATLONG32                          _InputValidationMode;

  // erreurs en sortie.
  double                             _AccuG0;
  double                             _ErrG0;
  double                             _ErrG1;
  double                        *    _ErrG0PerEdge;
  double                        *    _ErrG1PerEdge;
  CATMathPoint                  *    _LocErrG0PerEdge;
  CATMathPoint                  *    _LocErrG1PerEdge;

  //Topologie simplifier via ::SimplifyInput , i.e. _MultiFormMode==2.
  CATLONG32                          _SimplifyMode;
  CATLONG32                          _SimplifyModeSet;
  CATLONG32                          _NewNbWires;
  CATLONG32                     *    _Bloc;
  CATLONG32                     *    _OrnCrv;
  CATLONG32                     *    _NewTransitionContinuityCrv;
  double                        *    _NewTangencyParameterCrv;

  //Pour l'approx dans le cas 4 cotes
  CATLONG32                          _MDegreeU;
  CATLONG32                          _MDegreeV;
  CATLONG32                          _NumberUOfPatch;
  CATLONG32                          _NumberVOfPatch;
  
  CATLONG32                          _TrySetData;
  CATLONG32                     *    _ContinuitySide;
  CATLONG32                     *    _ContinuityInfo;
  double                        *    _TangencySide;
  double                        *    _TangencyInfo;
  int                                _NbRun;
  int                                _CanonicalDetection;
  CATBoolean                         _InsertJournalAttheEndOfRun;
  CATVertex                     *    _CenterPoint;
  ListPOfCATEdge                *    _ListOfEdges;
  ListPOfCATFace                *    _ListOfFaces;
    
};

#endif




/* -*-c++-*-*/
#ifndef CATMassProperties3D_H
#define CATMassProperties3D_H

#ifndef NULL
#define NULL 0
#endif
//=============================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 1998
//
// DESCRIPTION : CATMassProperties3D  class declaration ( internal use )
//
// This class is useful to compute the mass characteristics 
// ( area , center of gravity and inertia ) of a closed set of PCurves
// lying on a surface.
//
// Note : instead of "Run" method , "CalculateOnCurrentPCurve" method must be called
// for each PCurves in a closed set order. If the PCurve are not closed
// the program will compute junction PLine.
//=============================================================================
// Historic:
//    10-Dec-2003 : FDS - Creation.
//    23-Jan-2015 : F1Z - Add the global context information to help the global tol respect.
//    03-Nov-2016 : F1Z - Remove the possible throw in the operator construction.
//    17-Nov-2019 : JSX - Add IsCrossingRefV
//    09-Dec-2022 : JSX - Add _nbEvalGridFace pour evaluer les perfos
//=============================================================================

// Geometric operator
#include "Y30UIUTI.h"
#include "CATUtilMassProperties3D.h"

// Mathematics
#include "CATMathPoint.h"
#include "CATMathVector.h"

// Advanced Mathematics
#include "CATMassArray.h"

// Geometric Objects
#include "CATSurParam.h"
#include "CATSurLimits.h"

// ---------
// System
class CATSoftwareConfiguration;

// Mathematics
class CATTolerance;
class CATMathBox;

// Advanced Mathematics
class CATMathFunctionXY;
class CATNewMassProperties3DFunctionXY;

// Geometric Object
class CATPCurve;
class CATCrvParam;
class CATSurface;
class CATSurLimits;
// ---------

//#define MASS_DEBUG // Trace de debug

#ifdef MASS_DEBUG
#include "CATCGMOutput.h"
#include "CATMathDebug.h"

static CATLONG32  MASS_TRACE_LEVEL = CATMathDebug::integerGetEnv("CGM_MassProperties_Traces");

#define TRACE_MASS(level, text) {if (level <= MASS_TRACE_LEVEL) {cgmout<<" ("<<level<<") MassProperties::"<<text<<cgmendl;}}
#else
#define TRACE_MASS(level,text)
#endif

class ExportedByY30UIUTI CATMassProperties3D
{
   // This friend class is only used to allow the record of a CalculateOnCurrentPCurve call
   friend class CATMassProperties3DPartialFace;

public:

   // Constructor for "pseudo face" area , center of gravity and inertia computation
   // iNbPCurves   : Nb of PCurves of the closed set
   // iTol         : relative error expected on results
   // iBoundingBox : 3D bouding box
   // iSurface     : surface support of the PCurves
   // iFaceLimits  : 2D bounding box of the set of PCurves
   CATMassProperties3D(      CATSoftwareConfiguration *  iSoftwareConfiguration,
                       const int                         iNbPCurves            ,
                       const double                    & iTol                  ,
                       const double                    & iScale                ,
                             CATMathBox                & iBoundingBox          ,
                             CATSurface               *  iSurface              ,
                       const CATSurLimits             *  iFaceLimits           );


   // Constructor for volume computation ( stricly internal )
   CATMassProperties3D(      CATSoftwareConfiguration *  iSoftwareConfiguration              ,
                       const short                       iSurfacicMode                       ,
                             CATMathPoint              & iCoordMean                          ,
                       const int                         iSwapIndice[6]                      ,
                       const double                      iErrorMax[CATMASS_ARRAY_SIZE]       ,
                       const double                      iLatticeErrorMax[CATMASS_ARRAY_SIZE],
                             CATSurface               *  iSurface                            ,
                       const CATSurLimits             *  iFaceLimits                         );


   // Construction to compare the results between the differents methods
   // /!\ DO NOT USE ! Only reserved to display the differences, very bad perfo & no result
   CATMassProperties3D(      CATSoftwareConfiguration *  iSoftwareConfiguration,
                       const short                       iSurfacicMode         ,
                             CATMathPoint              & iCoordMean            ,
                       const int                         iSwapIndice[6]        ,
                             CATSurface               *  iSurface              ,
                       const CATSurLimits             *  iFaceLimits           );

   // Destructor
   ~CATMassProperties3D();

   // --------------------------------------------------
   // Static methods (stricly internal)
   // --------------------------------------------------
   static void CalculateErrorMax(const short          iDimension                          ,
                                 const int            iNbEdges                            ,
                                 const double       & iTol                                ,
                                 const double       & iScale                              ,
                                       CATMathBox   & iBoundingBox                        ,
                                       double       & oMaxVolume                          ,
                                       CATMathPoint & oCoordMean                          ,
                                       int            oSwapIndice      [6]                ,
                                       double         oErrorMax       [CATMASS_ARRAY_SIZE],
                                       double         oLatticeErrorMax[CATMASS_ARRAY_SIZE] );


   static void SwapCoordinates(const int             iSwapIndice[6]         ,
                                     CATMathPoint  & ioCenterOfGravity      ,
                                     double          ioInertia[6]           ,
                                     CATMathVector & ioCenterOfGravityError );


   static void UpdateInertiaToOrigin(const double       & iDimIndependantVolume ,
                                           CATMathPoint & iCenterOfGravity      ,
                                           CATMathPoint & iReferencePoint       ,
                                           double         ioLocalIData[6]       );


   static void UpdateInertia(const double       & iTol                    ,
                             const double       & iVolume                 ,
                             const double       & iArea                   ,
                             const double       & iLength                 ,
                                   CATMathPoint & iCenterOfGravity        ,
                             const int            isA2DBody               ,
                             const short          iLineicMode             ,
                             const int            iCorrectionForWire      ,
                                   double         ioLocalIData[6]         ,
                             const double       * iMaxError         = NULL);

   static void CATMass_Array2Value(double val[11], double& oVolume, double& oWetArea, CATMathVector& oCOG, double oInertia[6]);

   // --------------------------------------------------
   // Options before the first computation (commun to the whole computation on each PCurve)
   // --------------------------------------------------
   // Set the way we want to integrate the surface.
   // /!\ : No change if the compute started
   // @return : TRUE is the change was possible, FALSE otherwise.
   CATBoolean SetIntegrationV(CATBoolean actif);

   // Set the information of the global mass properties context.
   // This is useful in case of relaunch in order to get a better respect of the tolerance given.
   // ErrorMax/LatticeError will still be used, but wtih the respect of global context given.
   void SetGlobalContext(const double &iVolume, const double &iVolumeError,
                         const double &iArea  , const double &iAreaError  ,
                         const double &iTol                                );

   void SetGlobalContext(const CATMassProperties3DInfo & iGlobalMassProperties, const double &iTol);

   void SetGlobalContext(const CATMassPropertiesGlobalContext & iGlobalContext);

   // --------------------------------------------------
   // Options before a run (to change the way the computation will be done for the next(s) computation(s)).
   // --------------------------------------------------
   enum IntegrationType
   {
      LATTICE_INT_METH, // The lattice method
      OLD_INT_METH,     // The old method (before lattice, with 2 int 2D with no optimization).
      BEST_INT_METH,    // The choise of the algorism.
      ACCURATE_INT_METH // /!\ : ACCURATE_INT_METH will use lattice with a strengh tol and cutting meth : huge time consuming.
   };
   // @nocgmitf
   /** Set the type of integration we want (choose between IntegrationType value).
   * /!\ : The method is general. For canonical part, other method exist. Choose BEST_INT_METH to access them.
   */
   void SetIntegrationType(IntegrationType type);

   // --------------------------------------------------
   // Run methods
   // --------------------------------------------------
   // CalculateOnCurrentPCurve : 
   // This method is too be called on EACH PCurve of the "pseudo face" boundary
   // iIsNewLoop     : = 1 if new loop , = 0 if not new loop
   // iCurPCurve     : current PCurve
   // iIsCATSideLeft : PCurve orientation ( 1 if positive , 0 else )
   // iPCStart       : Crv Start Param
   // iPCEnd         : Crv Start Param
   void CalculateOnCurrentPCurve(const short    iIsNewLoop    ,
                                 const short    iIsCATSideLeft,
                                 CATPCurve    * iCurPCurve    ,
                                 CATCrvParam  & iPCStart      ,
                                 CATCrvParam  & iPCEnd         );

   // --------------------------------------------------
   // Iteration partial reset methods
   // --------------------------------------------------
   /// Signal that you want to enable exta refinements in the algorithm
   ///
   /// (at the cost of time). Calling this multiple times will progressively
   /// enable extra refinements. Computed data is cached for each
   /// (PCurve,start,end) and will only be recomputed with those extra
   /// refinements if the cached data doesn't fit the provided error
   /// tolerance levels.
   ///
   /// Typical use should thus be something like (pseudo code):
   ///  do:
   ///    for curve on face:
   ///      MassProperties.CalculateOnCurrentPCurve(face,curve)
   ///  while (not MassProperties.CheckTolerance()) and MassProperties.NextIteration()
   ///
   /// @return TRUE if another iteration is possible, FALSE if the ultimate
   /// level of algorithmic refinement was already reached.
   CATBoolean NextIteration( void );

   // --------------------------------------------------
   // Output methods
   // --------------------------------------------------
   // GetResult 
   // oVolume          : if not NULL , give volume value ( = 0 for surfacic )
   // oWetArea         : if not NULL , give area value
   // oCenterOfGravity : if not NULL , give center of gravity
   // oInertia         : if not NULL , give inertia value 
   //                    ( 6 values , I11 , I22 , I33 , I23 , I13 , I12 )
   // CAUTION : oCenterOfGravity and oInertia value have to be permuted
   // according to "oSwapIndice" value ( see "GetSwapIndice" method )
   void GetResult(double        * oVolume                     ,
                  double        * oWetArea                    ,
                  CATMathPoint  * oCenterOfGravity            ,
                  double        * oInertia                    ,
                  double        * oVolumeError          = NULL,
                  double        * oAreaError            = NULL,
                  CATMathVector * oCenterOfGravityError = NULL );

   void GetResult(CATMassProperties3DInfo &oMassPropertiesInfo);

   void GetComputationInformation(CATMassProperties3DGeoComputationInfo &oMassPropertiesComputationInfo);

   // Retrieve the integration direction
   // TRUE => cut along V param, FALSE => cut along U param
   CATBoolean GetIntegrationDirection();

   /// Check if current results are withing error tolerance bounds
   ///
   /// @return TRUE if error is inside tolerance bounds, FALSE otherwise.
   CATBoolean CheckTolerance( void );


private :

   // --------------------------------------------------
   // Initialisation
   // --------------------------------------------------
   void InitVersionning(CATSoftwareConfiguration * iSoftwareConfiguration);

   void DefaultInit    (      CATSurface         * iSurface              ,
                        const CATSurLimits       * iFaceLimits           );

   void InitRun        ();
   // --------------------------------------------------
   // Computation main methods
   // --------------------------------------------------
   void CalculateOnPCurve(const int             iIsAFaceGap ,
                          const CATCrvParam   & ipStart     ,
                          const CATCrvParam   & ipEnd       ,
                                CATPCurve     * ipCurve     ,
                                double        & oVolume     ,
                                double        & oWetArea    ,
                                double          oInertia[6] ,
                                CATMathVector & oCOG        ,
                                double        & oVolumeError,
                                double        & oAreaError  ,
                                CATMathVector & oCOGError    );

   void CalculateOnFaceGap(const CATSurParam & pStart,
                           const CATSurParam & pEnd   );

   // Integration methods
   void CanonicalIntegration(      CATPCurve     * ipCurve     ,
                             const CATCrvParam   & ipStart     ,
                             const CATCrvParam   & ipEnd       ,
                                   double        & oVolume     ,
                                   double        & oWetArea    ,
                                   double          oInertia[6] ,
                                   CATMathVector & oCOG        ,
                                   double        & oVolumeError,
                                   double        & oAreaError  ,
                                   CATMathVector & oCOGError    );

   void LatticeIntegration(      CATPCurve     * ipCurve       ,
                           const CATCrvParam   & ipStart       ,
                           const CATCrvParam   & ipEnd         ,
                                 double        & oVolume       ,
                                 double        & oWetArea      ,
                                 double         oInertia[6]    ,
                                 CATMathVector & oCOG          ,
                                 double        & oVolumeError  ,
                                 double        & oAreaError    ,
                                 CATMathVector & oCOGError     ,
                                 int             IsoU          ,
                                 double          u           =0.);

   void AdaptativeIntegration(      CATPCurve         * ipCurve           ,
                              const CATCrvParam       & ipStart           ,
                              const CATCrvParam       & ipEnd             ,
                                    double            & oVolume           ,
                                    double            & oWetArea          ,
                                    double              oInertia[6]       ,
                                    CATMathVector     & oCOG              ,
                                    double            & oVolumeError      ,
                                    double            & oAreaError        ,
                                    CATMathVector     & oCOGError         ,
                                    double            * iErrorMax    =NULL );


   // --------------------------------------------------
   // Geometric methods
   // --------------------------------------------------
   void DefineIntegrationDirection(CATSurParam &LowParam,
                                   CATSurParam &HightParam);

   int  MethodSelection (          CATPCurve *ipCurve ); // Choose the best integration method in case of mixed.

   int  IsAlmostIsoV    (          CATPCurve   * iPCurve      ,
                             const CATCrvParam & ipStart      ,
                             const CATCrvParam & iPend        ,
                                   double       iRatio /*= 0.002*/ ); // jsx pas de valeur par defaut svp!

   int  IsCrossingRefV(          CATPCurve   * iPCurve        ,
                             const CATCrvParam & ipStart      ,
                             const CATCrvParam & iPend         ); 
   void LastTreatments();
   void LastGapManagement();
   void FinalTreatmentForExternal();
   // --------------------------------------------------
   // Debug methods
   // --------------------------------------------------
   //Give back values to the user
   //ival : values
   //iLatticeIntegrator : if the Lattice method was used
   //iClassicIntegrator : if the Classic method was used
   void Debug(double *ival, CATNewMassProperties3DFunctionXY *iClassicIntegrator);


//===============================================================================================
//    DATA
//===============================================================================================
   private:

#ifdef MASS_DEBUG
   static CATLONG32                   _Static_DBG_FaceCounter ; // index de la face en ciurs de traitement (pas le tag, mais l'ordre de passage)
#endif
   // --------------------------------------------------
   // Attributs
   // --------------------------------------------------
   // Input datas (constant)
   // ----------------------------------
   short                              _SurfacicMode;    // 

   CATSurface                       * _Surface;

   CATMathPoint                       _CoordMean;       // coord dans l'espace de calcul
   double                             _Tol;
   double                             _ErrorMax[CATMASS_ARRAY_SIZE];
   double                             _LatticeErrorMax[CATMASS_ARRAY_SIZE];

   CATBoolean                         _C1;              // Factory is C1 (30 odts c1)
   const short                        _InternalUse;     // ==0 for very sepcific usage by swweep only 26 odts
   // Input datas after initialisation
   // ----------------------------------
   // (constant)
   CATBoolean                         _InitDone;
   short                              _CGMVersionNumber;
   short                              _CanonicalIntegration;
   int                                _NewLatticeMethod;

   CATBoolean                         _SurLocked;
   CATSurLimits                       _SurLimits;
   CATLONG32                          _uMidPatch;
   CATLONG32                          _vMidPatch;
   double                             _uMid;
   double                             _vMid;
   CATBoolean                         _IntegrationWRTV;   // Iso de ref: ( default false =>isoU), on parcourt en w la pcurve en integrant le domaine [(u(w),v(w))  <>  (_uMid,v(w))]

   CATNewMassProperties3DFunctionXY * _NewGlobalFunction;
   const CATMathFunctionXY          * _FunctionXY[3];     // Equation de la surface (dans l'ordre de _SwapIndice)


   // (!constant)

   // Options
   // -----------------------------------
   int                                _SwapIndice[6];               // rotation de XYZ pour integrer toujours avec les meme variables
   CATMassPropertiesGlobalContext     _MassPropertiesGlobalContext; // Donn�e provenant d'un calcul prcededant , permetant d'affiner les tolerance a utiliser

   // Algorism datas
   // -----------------------------------
   // Global
   int                                _IterationCount;      // Algorithmic refinement level. See NextIteration(). ITERATION_BASIC / ITERATION
   CATBoolean                         _UsingLattice;        // Set to TRUE if Lattice integration was used at least once
   CATBoolean                         _IntegrationHasStarted;


   // PCurves

   short                              _IsFirstLoop;         // Set to 1 by Ctor , to 0 at the first pcurve (useful for gap computation at the ned a loop)
   int                                _CurveCount;          // nombre de courbe deja tarit�es
   // Loop    Gestion des gaps
   CATSurParam                        _FirstSurParamOfLoop; // Premier point 2D d'une loop ( repere grace a _IsFirstLoop)
   CATSurParam                        _LastSurParam;        // Dernier point de la pcurve precedemment trait�e
 


   // Accuulation des infos des concernant les pcurves pour lesquelles les calcules on ete valid�s : en mode Lattice 
   // on relance sur la face si necessaire avec _IntegrationMethod plus fotr 
   CATBoolean                         _UsingLatticeSub;     //  : en lattice a la fin d'une face on sait si il faut relancer si une edge n'a pas respecte la qualit� 
                                                            //        mais une face ne suffit pas pour connaitre le volume : Remplce maintetant par le contexte de Flavien 
   // Relaunch
   CATBoolean                       * _ErrorTooBig;         //  Used Size=_CurveCount  ==TRUE if relaunch is needed, FALSE otherwise
   int                                _ErrorTooBigSize;     // for Array manaegment
   IntegrationType                    _IntegrationMethod;   // a changer pourle recalcul 

   double                             _ValidVolume;
   double                             _ValidArea;
   double                             _ValidInertia[6];
   CATMathPoint                       _ValidCenterOfGravity;
   double                             _ValidVolumeError;
   double                             _ValidAreaError;
   CATMathVector                      _ValidCenterOfGravityError;


   // Output datas
   // -----------------------------------
   short                              _LastDone;  // indicate that "last gap" has been computed

   double                             _Volume;
   double                             _Area;
   double                             _Inertia[6];
   CATMathPoint                       _CenterOfGravity;
   
   double                             _VolumeError;
   double                             _AreaError;
   CATMathVector                      _CenterOfGravityError;

   const CATTolerance               & _ToleranceObject;

#ifdef  MASS_DEBUG
   const  CATLONG32                   _dbgFaceIDX;      // index de l'instance sert au debug uniquement
#endif

   public:
   CATLONG32                          _nbEvalGridFace; // information sur le nb d'evalation effectu�es

protected:
   CATSoftwareConfiguration         * _SoftwareConfiguration;
};

#endif 

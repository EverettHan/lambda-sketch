// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// Interface CATBuildPlateDeform
// 
// from constraints and an initial surface S (given or computed) computation of 
// a deformation of S with respect to these contraints. 
//
//=============================================================================
// Usage Notes:
//
//
//=============================================================================
// April. 99 Creation                                          MPS
//=============================================================================
// Aout 2019   MPS : - AJout ComputePlaneByFluxForFitting => utilisation de la methode du flux  a la place de l'inertie
//                     pour SurfaceNetWork avec Fitting
// Aout 2009   MPS : - Smart Geometry => introduction de la projection totale
// May  2009   MPS : - Add AllowOnlyOneClosedBoundary   pour correction SWK  
// July 2008   KTU : - Add SetMaxErrorG0G0IncompAllowed pour correction Pbs SWK-SPR279444(G0G0>45) et SWK-SPR442012(G0G0<0.7)
// Jan  2005   KTU : - Ajout SetMarginCoef
// Fev  2006   KTU : - Add int FixedExtremities( unsigned int  iExtRanks[4] );
// Jan  2005   KTU : - Ajout SetMarginCoef
// Juil 2004   KTU : - Ajout ForceParamLimits , GetRatioOkMax
// Mars 2004   KTU : - Ajout  ResetInitialSurface( .., .. ) = > for GDD
// Nov  2003   KTU : - Ajout de la methode NoFilter() 
// Sept 2003   KTU : - Progress Bar integration 
//=============================================================================


#ifndef CATBuildPlateDeform_h
#define CATBuildPlateDeform_h

#include "GeoPlate.h"
#include "CATCGMOperator.h"
#include "CATMathDef.h"
#include "CATIncompatibilityType.h"
class CATGeoFactory;
class CATSurface;
class CATCurve;
class CATPCurve;
class CATICContact;
class CATIPContact;
class CATOptionPlateFE;
class CATCContactLocation;
class CATPContactLocation;
class CATMathSetOfPointsND;
class CATPlane;
class CATMathPoint;
class CATSoftwareConfiguration;
class CATICldLocation;
class CATICldContact;
class CATFrFNurbsBipar;
class CATCGMProgressBar;



class ExportedByGeoPlate CATBuildPlateDeform : public CATCGMOperator
{
public:

  //  Destructor.
  virtual  ~CATBuildPlateDeform() ;
  
  // Constructors

          CATBuildPlateDeform                 (      CATGeoFactory            * i_Factory,
                                                     CATSoftwareConfiguration * iConfig=NULL);
 
  
  // initializations


  virtual int                   SetResolParam (const int iNbIter     = 3,
                                               const int iNbPtsOncur = 10)=0;
 // this method returns 1 if iNbIter<1; 

  virtual int                   SetDegree(const int iDegree=3)=0;
  //this  method returns 
  //  1 if the order of one constraint is G1 and  iDegree <3
  //  2 if the order of one constraint is G2 and  iDegree <4
  //  3 if iDegree<2
  //  4 if iDegree>8 
    // In all this cases nothing is done.

  virtual int                   SetAnisotropie(const CATBoolean iAnisotropie      = 0,
                                               const double     iAnisotropieValue = 1.0,
                                               const CATBoolean iPrec             = TRUE)=0;
  /*
   * ktu 23/05/2002
   * Laisse le choix a l'algo de calculer l'anisotropie et de l'utiliser s'il
   * juge necessaire 
   * l'appel SetAnisotropie inhible cette liberte
   */
  virtual int                   SetFreeAnisotropie(const CATBoolean iFreeAnis0 = TRUE)=0;

  // initialization of the approximation  parameters  
  
  virtual void                  SetApproxParam (const int iUorder ,
                                                const int iVorder,
                                                const int iMaxdegU,
                                                const int iMaxdegV, 
                                                const int iMaxsegment)=0;

// initialization of the approximation  parameters 
  
  virtual void                  SetApproxParam (const int iUorder ,
                                                const int iVorder,
                                                const int iMaxdegU,
                                                const int iMaxdegV, 
                                                const int iMaxUsegment,
                                                const int iMaxVsegment)=0;

    // Set the MinimalContinuity to impose  at discontinuities point
  virtual int                   SetMinimalContinuity(const int iCont)=0;

  // liberation des contacts 
  virtual void                  ContactFreedom()=0;

  // load of the initial surface  
  // if iDeformAll==1 the complete surface will be deformed
    // else only a usefull limitation will be deformed8
  virtual void                  SetInitialSurface  (      CATSurface * iSurfInit,
                                                    const CATBoolean iDeformAll = 0)=0;
  
  //  ktu : mars  2004 :
  //  To reset Initial Surface = > for GDD
  virtual int                   ResetInitialSurface(      CATSurface * iSurfInit,
                                                    const CATBoolean iDeformAll = 0) = 0;
  
  // load of the constraints 
  // warning Cloc and Ploc are input/output arguments   

  virtual  int                  Add                (      CATCContactLocation * ioCLoc ,
                                                          CATICContact        * iFinalContact,
                                                          CATICContact        * iInitialContact=0)=0;
  //this  method returns 
  //  -1 if the order of the constraint is G1 and  the Degree <3
    //     (the degree is updated to 3)
  //  -2 if the order of one constraint is G2 and  the Degree <4
    //     (the degree is updated to 4)
  //  -3 if initial contact is not 0
  //  the number of constraint otherwise 

  virtual int                   Add                (      CATPContactLocation * ioPLoc ,
                                                          CATIPContact        * iFinalContact,
                                                          CATIPContact        * iInitialContact=0)=0;


   //
  virtual int                   Add                (      CATICldLocation * PLoc, 
                                                          CATICldContact  * FinalContact,
                                                          CATICldContact  * InitialContact) = 0;

  //this  method returns 
  //  -1 if the order of the constraint is G1 and  the Degree <3
    //     (the degree is updated to 3)
  //  -2 if the order of one constraint is G2 and  the Degree <4
    //     (the degree is updated to 4)
  //  the number of constraint otherwise 

  virtual int                   SetFinalCContact   (int iNumconstraint, const CATICContact        * iFinalContact)=0;
  virtual int                   SetInitialCContact (int iNumconstraint, const CATICContact        * iInitialContact)=0;
  virtual int                   SetCLocation       (int iNumconstraint, const CATCContactLocation * iLoc)=0;
  virtual int                   SetFinalPContact   (int iNumconstraint, const CATIPContact        * iFinalContact)=0;
  virtual int                   SetInitialPContact (int iNumconstraint, const CATIPContact        * iInitialContact)=0;
  virtual int                   SetPLocation       (int iNumconstraint, const CATPContactLocation * iLoc)=0;

  //gestion des free pour une contrainte 
  // @nodoc @nocgmitf 
  virtual void                  SetIsOrderFree(const int iNumconstraint, CATBoolean IsOrderFree) = 0;

  // @nodoc @nocgmitf 
  virtual CATBoolean            GetIsOrderFree(const int iNumconstraint) = 0;


  virtual CATICContact        * GetFinalCContact   (int iNumconstraint)=0;
  virtual CATICContact        * GetInitialCContact (int iNumconstraint)=0;
  virtual CATCContactLocation * GetCLocation       (int iNumconstraint)=0;

  virtual CATIPContact        * GetFinalPContact  (int iNumconstraint)=0;
  virtual CATIPContact        * GetInitialPContact(int iNumconstraint)=0;
  virtual CATPContactLocation * GetPLocation      (int iNumconstraint)=0;
  // access to the initial surface 
  virtual CATSurface          * GetInitialSurface () const=0;
  
  
  //set the type of the result 
  // 0 : procedural surface
  // 1 : approached surface 
  // 2 : PlateFE
  // 3 : automatic type : best result between approached surface and surface computed with PlateFE 
  // by default iType=3 
  virtual void                  SetResultType (const int iType=3 )=0;

  // Verification of PCurve intersection
  virtual void                  SetComputeIntersection (const CATBoolean iIntersecte=TRUE)=0;

    // Verification of PCurve tangence
  virtual void                  SetAnalyseTang (const CATBoolean iAnalyse=TRUE)=0;

  // Verification de la surface finale
  // par calcul de distance
  virtual void                  SetVerifFinale (const CATBoolean iVerifFinale=TRUE)=0;


  // coefficient de securite lors des tests concernant les deformations nulles
  virtual void                  SetSecurityCoef (const double  iSecurityCoef=0.95)=0;
  
  virtual void                  SetPmax(const double ipmax)=0;

  virtual int                   SetForceDiscC1OnTang (const CATBoolean iForce)=0; 

  virtual int                   SetChainage2D (const double iTolForChainage = 0.0)=0; 


    // SetDiscretizationByLength : CATMassProperties1D::GetParamFromLength  is used to discretize curves 
    /**  @nodoc @nocgmitf */ 
  virtual void                  SetDiscretizationByLength()=0;

    // Controle ou non les chargements ponctuelles (defaut = TRUE)
  virtual void                  CheckPasMinisOnPoints(const CATBoolean iCheckPasMinisOnPoints)=0;

  // Gere les niveaux de code
  virtual void                  SetCodeLevel (const int iLevel)=0;
  virtual int                   GetCodeLevel () const =0;


  // gere le pb des limites  pour l'intersection des MathLine  dans GeoPlateUtilities::VerifInterPolygon2D
//  en attendant une gestion appropriee par CodeLevel 
  virtual void                  SetNewIntersectionSegment ()=0;

 //  the result a  always a Nurbs Surface
 // even  if it is a plane 
  virtual void                  SetNurbsResult()=0;

    //  Set a BSpline to initalize the PlateFE Solver
  //  This BSpline must be have the save parametrization and Geometrie than the initial Surface;
  virtual int                   SetNurbsInit(CATFrFNurbsBipar * iBiPar)=0;

     // Choix d'integer le gap sur le contour dans le calcul des tolerances.
  virtual void                  SetTolWithGap(const CATBoolean iWithGap)=0;

  // Option sur le calcul du plan
  virtual void                  SetOnlyInertiaPlane(const CATBoolean isOnlyByInertia)=0;

  // ExactUVBox
  virtual void                  SetExactUVBox(const CATBoolean iExactUVBox = TRUE)=0;

  // CheckRational
  virtual void                  SetCheckRational(const CATBoolean iCheckRational = TRUE)=0;
    //NbArcsUAndV pour calculer les nombres d'arcs max en U et en V
    // en fonction de ceux de la surface d'init
  virtual void                  SetCheckNbArcsUAndV(const int iCheckNbArcsUAndV=1)=0; 

  // CheckExtremities
  virtual void                  SetCheckExtremities(const CATBoolean iCheckExtremities = TRUE)=0;

  // PntInterWithMinTol
  virtual void                  SetPntInterWithMinTol(const CATBoolean iPntInterWithMinTol = TRUE)=0;

  // StabilizeRatio
  virtual void                  SetStabilizeRatio(const CATBoolean iStabilizeRatio = TRUE)=0;

  
  // @nodoc @nocgmitf 
  //Limited use only for SurfaceNetWork 
  // In case of  Fitting and All G0 constraints and G0G1 constraints the initial plane is computed by flux method instead for inertia  
  virtual void                  ComputePlaneByFluxForFitting() = 0;

 // this method returns:
  // -1 :the initial surface has been loaded by the method SetInitialSurface 
  // 0 : the initial surface is computed and is not a plane
  // 1 : the initial surface is computed and is a plane
  // this method must be called before the method Run()
  virtual int                   IsInitialSurfacePlane()=0;

  // this methode returns the constraint  which corresponding to the small curve
 // with null projection if isInitialSurfacePlane=2 otherwise it returns 0

  virtual int                   GetNumSmallCurve()=0;
   
  
  virtual void                  GetPlaneCharacteristics(CATPlane *  & oPlane,CATAngle & oMaxAnglePoints,
                                                        CATAngle & oMaxAngleNormals)=0;


  // computation 

 // COMPUTATION 
//  errors: 
// 1 : inputs not valids 
// 2 : problem in the projection 
// 3 : problem in the computation of the procedural surface 
// 4 : problem in  the approximation 

  virtual int                   Run()=0;


 /**
    * Returns the number of incompatibilities  of <tt>this</tt> CATGeoFilling operator 
    * This method must be used after the <tt>Run</tt> method. 
    */
  virtual int                   GetNumberOfIncompatibilities  () const = 0;

    /**
    * Initializes the iterator of the resulting incompatibilities.
    * This method must be used after the <tt>Run</tt> method. 
    */
  virtual void                  BeginningIncompatibility () = 0;

  /**
   * Skips to the next incompatibility  of <tt>this</tt> CATGeoFilling operator.
   *<br>After <tt>BeginningIncompatibility/tt>, it skips to the first incompatibility 
   * @return
   * The existence of the next incompatibility.
   * <br><b>Legal values</b>:
   *<dl><dt><tt>TRUE</tt> <dd>if there is an incompatibility
   *    <dt><tt>FALSE</tt> <dd>no more incompatibility.</dl>
   * @params oNumCont1 oNumCont2
   * The numbers of constraints between which an incompatibility  exists.
   * @param oParam1
   * The parameter on constraint <tt>oNumCont1</tt> where the incompatibility is located.
   * @param oParam2
   * The parameter on constraint <tt>oNumCont2</tt> where the incompatibility is located.
   * @param oType 
   * The kind of incompatibility between the constraints <tt>oNumCont1</tt> and <tt>oNumCont2</tt>. 
   * @oValue 
   * The value of incompatibility.
   * <ul>
   *<li><tt>if oType= G0andG0Incompatible</tt>, <tt>oValue</tt> is a distance 
   * <li><tt>if oType= G0andG1Incompatible</tt>, <tt>oValue</tt> is an angle 
   * <li><tt>if oType= G1andG1Incompatible</tt>, <tt>oValue</tt> is an angle 
   * <li><tt>if oType= G2Incompatible</tt>, <tt>oValue</tt> curvature value. 
   * </ul>
   */
  virtual CATBoolean GetNextIncompatibility( int & oNumCont1,
                                             int & oNumCont2,
                                             double & oParam1,
                                             double & oParam2, 
                                             FillingIncompatibilityType & oType,
                                             double & oValue)=0;
    

  virtual int                   Update()=0;

  
  // by default the result is the procedural surface 
  // to  have the approached surface the method SetResultType (with iType=1) must be used
  // before the method Run 
  
  virtual CATSurface  * GetResult () const=0;
  

  //  Get only the deformation 
  //  a definir 
  
  //  this methods returns :
 // 0 :  the tolerance G0  is  not reached
 // 1 :  the  tolerance G0 is reached  
  virtual CATBoolean isFillG0OK ()=0;
  virtual CATBoolean isFillG1OK ()=0;
  virtual CATBoolean isFillG2OK ()=0;
   /*
    * ktu 03/10/01
    * verifie si la tol est atteinte en tenant compte des incompatibilites
    */
          CATBoolean isFillG0MaxOK();
  //the errors  
  virtual double G0MaxError()=0;
  virtual double G1MaxError()=0; 
  virtual double G2MaxError()=0;

  virtual double G0MaxDeviation()=0;
  virtual double G1MaxDeviation()=0; 
  virtual double G2MaxDeviation()=0; 
  // maximum errors on each constraint
  virtual double G0MaxError(const int inumcont)=0;
  virtual double G1MaxError(const int inumcont)=0; 
  virtual double G2MaxError(const int inumcont)=0;

  virtual double G0MaxDeviation(const int inumcont,CATMathPoint * ioMaxPoint=NULL)=0;
  virtual double G1MaxDeviation(const int inumcont,CATMathPoint * ioMaxPoint=NULL)=0; 
  virtual double G2MaxDeviation(const int inumcont,CATMathPoint * ioMaxPoint=NULL)=0;


  // maximum accuracies on each constraint
  virtual double GetTolG0Max(const int inumcont)=0;
  virtual double GetTolG1Max(const int inumcont)=0; 
  virtual double GetTolG2Max(const int inumcont)=0;

  /** 
  * Get a ratio between delta on vertices's surface and constraint delta.
  * ***WARNING*** is corect only with G0 constraint.
  *
  * @return
  *   The ratio.
  *
  */
  virtual double GetRatioDelta() const=0;

  // Acces a la loi de Mapping
  virtual CATMathSetOfPointsND * GetMapping(const int inumcont)=0;
  virtual CATMathSetOfPointsND * GetMappingTotal(const int inumcont)=0;

    // To Read or modify the Options for PlateFE
  virtual CATOptionPlateFE * PlateFEOptions()=0;

  // Get the anisotropie Value : return 0 if not computed
  virtual double GetAnisotropie()=0;

// this method returns 1 if all the ponctual contraints are too close of the contour to fill 
  // this method returns 2 if all the ponctual contraints are outside of the contour to fill 

  virtual int                    isInvalidPoint ()=0; 

  //////////// ktu : 10/05/01 0 to set progressive load of the points in FE
    //// si l'option est active, la priorite entre les niveaux est l'ordre decroissant:
  /// ie le niveau 0 est priotaire esuite vient le niv 1 puis 2;
  /// iOption : pour activer ou non le processus
  /// dans le cas ou le process est ativer on peut ou non jouer sur ces options
  /// iNbLevel : le nombre de niveaux 2 ou 3
  /// Seulement si iNbLevel==2, on pour jouer ou non sur le dernier argument
  /// iSameNbPt : si vrai on prendra le meme nbre de points un peut + ou 2x+ 
  //////////////
  virtual void                  SetProgressiveLoad(const CATBoolean iOption, const int iNbLevel=3, const CATBoolean iSameNbPt =0 ) = 0;

    // options pour le plan d'init:
    // 0
    // 1 : on prend plus de points pour l'analyse des tangentes.
  virtual void                  SetSurfInitOption(const int iOption ) = 0;
     
    // if iIsFree =1  the constraint iNumConstraints is free 
    //(it is not take into account in the computation of the surface    for QSR)
  virtual void                  IsFreeConstraint (const int iNumConstraints,const CATBoolean iIsFree)=0;


  // permet de savoir si une contrainte est en dehors des limites de la frontiere interne 
  virtual CATBoolean  IsCurveConstraintOutside(const int & iConstIndex)=0;
  virtual CATBoolean  IsPointConstraintOutside(const int & iConstIndex)=0;
  virtual void                  AllowPartialResult()=0;

    /*
    * ktu 26/10/01
    * To know which type of Constraint
    * type de contrainte:
    * 0 => Non Bord
    * 1 => Bord Externe (valeur par default)
    * 2 => Bord interne
    * 
    * iConstIndex from 1 to nbConstraint
    */
  virtual void                  SetConstraintType(const int & iConstIndex, const int & iType) = 0;
   ////virtual int                    GetConstraintType();   
   
      /*
    * ktu 21/12/2001
    * definir le sens de deformation 
    * Ce mode n'est valide que si le level >=3
    */
  virtual void                  SetOrientation(CATBoolean iKeepConvention=TRUE) = 0;

   /*
    * ktu 
    */
  virtual void                  SetModelSize( const double & iSize ) = 0;

  /**
   * pour activer les transverse
   * par defaut non activer
   * 0 succes, 1 autre echec
   * iIsG2Transverse:
   *     - true => chagement des contrainte transverses.
   *     - fasle=> pas de chargement des contraintes transverses.
   * Les 2derniers arg sont valable que si  ler le 1er arg == true
   * dans ces cas:
   * iIsAbsoluteTolG2:
   *      - true =>  on utilise la tolerance G2 des contact comme tolerance absolue
   *                 le dernier argument est inutile.
   *      - false => alors la tolG2 est un pourcentage donnes par iPercentTolG2 qui par
   *                 defaut == 5%. On n' utilise plus la tolG2 du contact.
   */
  virtual int                   SetG2Transverse( const CATBoolean iIsG2Transverse,
                               const CATBoolean iIsAbsoluteTolG2 = 1,
                               const double iPercentTolG2 = 0.05)= 0;

  virtual int                   SetMinCurvature( const double  iMinCurvature ) = 0;
   /**
   * 0  il n'y a pas de contraintes G2
   * 1  le G2 est charge  
   * 2  le G2 n'est pas charge car forte pente 
   * 3  le G2 n'est pas charge car incompatibilites 
   */
  virtual int                    G2ConstraintsLoaded( )= 0;

  /**
   **/
   
   /** a point  which does not belong to the 2D bounding box
   * of the bounds to fill is kept for the computation of the surface.
   *To use only for regularisator project
   */

   virtual void                  SetNoUseUVBox ()=0;
   
   /**
    * Set Callback function to update Progress Bar
    * iNbTops : 0<iNbTops<=100 : number of times to call iFunc.
    * WARNING : iFunc will be called EXACTLY iNbTops times.
    */
  virtual int                   SetProgressBarEvolFunction( void (*iFunc)(), unsigned short iNbTops ) = 0;
  virtual void                  SetCallback( CATCGMProgressBar *ipProgressBar ) = 0;

     /*
     @nodoc
     */
  virtual void                  SetWithStats(const CATBoolean iWithStats)=0;


   /*
    *
    */
  virtual void                  SetOldLevel1() = 0;

   /*
    */
  virtual double GetRatioOkMax() const = 0;

   /*
    * nodoc
    */
  virtual void                  SetMarginCoef( const double iCoef ) = 0;
  virtual void                  SetMaxAngles(const double iMaxAnglesPoint , const double iMaxAnglesNormal)=0;
  virtual  CATPCurve          * GetTotalProjection (int iNumconstraint)=0;

    /**
     * That makes it possible to fix a consecutive number of Ranks of Control points.
     * iExtRanks[i] : Contains the numbers of row to fix for Iso i.
     * if iExtRanks[i]==0, no row will be fixed.
     * Convention adopted for Iso :
     *
     *                           Iso V= Vmax
     *                           iExtRanks[3]
     *         vmax +-------------------------------------+
     *              |                                     |
     *              |                                     |
     *              |                                     |
     *              |                                     |
     * Iso U= umin  |                                     |  Iso U= umax
     * iExtRanks[0] |                                     |  iExtRanks[1]
     *              |                                     |
     *              |                                     |
     *              |                                     |
     *              |                                     |
     *              vmin +-------------------------------------+
     *             umin                                  umax 
     *                           Iso V= Vmin
     *                           iExtRanks[2]
     *
     **/
  virtual int                   FixedExtremities( const unsigned int  iExtRanks[4] )= 0;

    //  ktu 06/06/06
    /** 
     * To Enable or not 2d filter
     */
  virtual int                   Set2DFiltering4Cld( const CATBoolean iFiltered2D ) = 0;

    /**  
    *  Set the maximum threshold of G0G0 incompatibilities from which the computation will stop.  
    *  @param  iMaxErrorG0G0IncompAllowed  
    *  Maximum threshold of G0G0 incompatibilities 
    *  @return  
    *      0  if  it is  successfully  returned  and  none zero  otherwise  
    */  
  virtual int                   SetMaxErrorG0G0IncompAllowed( const double iMaxErrorG0G0IncompAllowed ) = 0;
  virtual void                  AllowOnlyOneClosedBoundary(const CATBoolean isAllow=FALSE)=0;

    /* Allow SmartGeometry Treatment.
    If two constraints have the same curve . The Total projection of this curve is realized in order to use it
    to construct topology 
    */
  virtual void                  SetSmartGeometry()=0;
    

    // to stabilize the direction of the initial plane 
  virtual  void                 SetStabilizationPlaneDirection()=0;

    // only for SolidWorks Used  
  virtual void                  SetC2CuttingsForNotClosedBoundaries()=0;


};

#endif

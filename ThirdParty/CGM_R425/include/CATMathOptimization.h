#ifndef CATMATHOPTIMIZATION_H
#define CATMATHOPTIMIZATION_H
// COPYRIGHT DASSAULT SYSTEMES 2007
//==========================================================================
//
// Optimization with evolutionary algorithms
//
// DO NOT USE: utiliser CATMathOptimizer dans AdvancedMathematics
//
// Global Optimization Solver
// Objective function oJX = J(iX)
//              
//   Finds oX that realizes the minimum value of J(iX) inside given bounds 
//   [iXMin, iXMax].               
//   J may or not be differentiable, no gradient evaluation is required.
//   The two evolutionary algorithms  (EA) introduced are
//      - Particle Swarm Optimization (PSO)
//      - Differential Evolution      (DE)
//   An initial population evolves during several generations to converge to 
//   the global optimum.
//
//==========================================================================
//          PSH Creation                                        Pascal SEBAH
// 20/08/07 JSX Livraison temporaire dans le code de FreeForm
//              Removed all Tab !! {ctrl R CtrlW)
// 08/02/16 NLD Mise au propre
// 11/02/16 NLD Ajout (transitoire?) de GlobalBestUpdatePSO()
//              RunPSO() remplace PSO()
//              RunDE()  remplace DE()
//==========================================================================

//==========================================================================
// Le code ne concernant pas la methode PSO n'est pas actif
   #define CATMathOptimization_PSO_ONLY


// Permet d'utiliser le mode non synchrone
// #define CATMathOptimization_NonSynchrone

// activation pour evolution envisagée de CATMathOptimization_CurvedSpace
// #define CATMathOptimization_CurvedSpace

// le code de trace n'est pas actif (coverage)
//  #define CATMathOptimization_TraceSystem
//==========================================================================

//==========================================================================
#include "CATDataType.h"  // JSX CATLONG32
#include "CATBoolean.h"   // JSX CATBoolean
#include "FrFAdvancedObjects.h"

class ExportedByFrFAdvancedObjects CATMathOptimization
  {
  public:
    //
    ////////////////////////////
    // Constructor-Destructor //
    ////////////////////////////
    //
    // iN is the space's dimension (the number of variables)
    CATMathOptimization (CATLONG32 iN);
    //
    ~CATMathOptimization ();
    //
    //
    ////////////////////////////////////////////
    // Evaluator of the function to minimize: //
    //   iX -> oJX = J(iX)                    //
    ////////////////////////////////////////////
    //
    // The objective function
    virtual void              Eval                        (double           * iX                  ,
                                                           double           & oJX                 ) = 0;
    //
    // Returns the number of variables (the space's dimension)
            CATLONG32         GetNumberOfVariables        ();
    //
    //
    //////////////////////////
    // Select the algorithm //
    //////////////////////////
    //
    // ParticleSwarm: Stochastic algorithm inspired by the bees' swarms. Each 
    // particle is defined by a position and a speed. The speed of each particle 
    // is randomly divided into its best memory position and the best memory position
    // of its neightbourhood (which could be all the swarm or just few neighbours). 
    // Finally the swarm converges to the global minimum.
    //
    // DifferentialEvolution: Stochastic algorithm inspired by the rules of mutation, 
    // crossover and selection. For each position, a new one is created by mutation with 
    // few other positions randomly chosen (mutation). It is crossed over the original position,
    // (crossover) and then if this new position is better than the original position, it replaces
    // it, else the original position is kept (selection).
    enum OptimizationMethod {ParticleSwarm        ,
                             DifferentialEvolution};

            void              SetMethod                   (OptimizationMethod iMethod);
    //
    //
    /////////////////////
    // Solver settings //
    /////////////////////
    //
    // iSeed initializes the function Rand to create the initial 
    // position of the particles randomly
            void              SetInitialSeed              (CATLONG32          iSeed               = 499911233);
    //
    // iX is in [iXMin, iXMax]
            void              SetBounds                   (double           * iXMin               ,
                                                           double           * iXMax               );
    //
    // The number of particles is iNumberOfParticles
            void              SetPopulationSize           (CATLONG32          iNumberOfParticles  = 20);
    //
    // The number of iterations (or generations) is iNumberOfIterations
            void              SetNumberOfGenerations      (CATLONG32          iNumberOfIterations = 500);
    //
    // iNumberOfInformants is the number of informants for each particle, for 
    // the Particle Swarm Optimization
            void              SetNeighbourhoodSize        (CATLONG32          iNumberOfInformants = 3);
    //
    // iConstrictionRatio is the factor F in Particle Swarm Optimization: 
    // V[k] = F*K*(V[k]+ c1*r0*(XB[k] - X[k]) + c2*r1*(XBN[k] - X[k]));
    // with K: constriction factor
    //      r0, r1: random factors
    //      c1, c2: constants
    //      XB:  the best known position of the particle
    //      XBN: the best known position of the informants of the particle
    // F must be positive, and preferably near to 1
            void              SetRatioOfConstrictionFactor(double             iConstrictionRatio  = 1);
    //
    // Selects the updates' mode. Two modes are available: Synchronous and Asynchronous.
    //   
    //   Synchronous mode: all the new positions are calculated from all the 
    //   precedent positions.
    //
    //   Asynchronous mode: the new first position is estimated from all the  
    //   precedent positions, then the second new position is calculated from the 
    //   new first one and all the other precedent positions and so forth.
    enum ModeUpdates {Synchrone,
                      Asynchrone};
            void              SetMode                     (ModeUpdates        iMode               = Synchrone);
    //
    // iNumberOfGivenParticles is the number of particles for which a non-random 
    // initialization is required.
    // SuggestParticle is to call for each particle to suggest.
    // The size of iXInit must be space's dimension.
            void              SetNumberOfSuggestedParticles(CATLONG32         iNumberOfGivenParticles);
            void              SuggestParticle              (double          * iXInit              = 0);
    //
    // To use when an hybridization is required (to accelerate the convergence). 
    // Several types of accelerators are available : RadialInterpolation and 
    // BarycenterApproximation.
    enum Accelerator {RadialInterpolation,
                      BarycenterApproximation};
            void              SetHybridization             (Accelerator       iAcc                = RadialInterpolation);
   //
    // When the solver reaches iJ0 with the precision iPrecision, it is stopped and 
    // the solution is iJ0.
            void              SetStopValue                 (double            iJ0                 ,
                                                            double            iPrecision          );
    //
#ifdef CATMathOptimization_CurvedSpace
    // JSX Direction de B vue de A  ( == (B-A) dans une espace non ""courbé""
    virtual void              ComputeDirFromTo             (double          * A                   ,
                                                            double          * B                   ,
                                                            double          * oDir                );
#endif
    //
    //////////////////////
    // Debug trace file //
    //////////////////////
    //
    enum ModeTrace {Compact, Maple};
#ifdef CATMathOptimization_TraceSystem
    // To use when a debug trace file is required.
    // Several formats are available : Compact, Maple.
            void              SetTraceFile                 (char            * iFileName           ,
                                                            ModeTrace         iTrace              = Compact);
    // debug
            void              PrintOpen                    ();
            void              PrintIteration               (double          * iXPart              ,
                                                            double          * iXBest              ,
                                                            double            iFG                 );
            void              PrintClose                   ();
#endif
    //
    //
    ///////////////////
    // Run minimizer //
    ///////////////////
    //
            CATLONG32         Minimize                     (double          * oX                  );
    //
  private:
            void              InitializationPSO            (double          * oXX                 ,
                                                            double          * oFX                 ,
                                                            double          * oXB                 ,
                                                            double          * oFXB                ,
                                                            double          * oVX                 ,
                                                            double          * oX                  ,
                                                            double          & oFG                 ,
                                                            CATLONG32       * oSeed               ,
                                                            CATLONG32       * oT                  ,
                                                            double          * oXBN                ,
                                                            double          * oFBN                );

            CATLONG32         RunPSO                       (double          * oX                  );

            // Mise a jour des parametres de meilleure particule pour le PSO
            void              GlobalBestUpdatePSO    (const int               ii                  ,
                                                      const CATLONG32       * T                   ,
                                                            double          * X                   , // en fait cest seulement une entree
                                                      const double          * XB                  ,
                                                      const double          * FXB                 ,
                                                      const double          * oX                  ,
                                                      // sorties:
                                                            double          * FN                  ,
                                                            double          * XBN                 ,
                                                            double          * FBN                 ,
                                                            double          & Min                 ) ;


#ifndef CATMathOptimization_PSO_ONLY
            void              InitializationDE             (double          * oXX                 ,
                                                            double          * oFX                 ,
                                                            double          & oFU                 ,
                                                            CATLONG32       * oSeed               ,
                                                            double          * oX                  ,
                                                            double          & oFG                 );

            CATLONG32         RunDE                        (double          * oX                  );
#endif

            void              Hybridization                (double          * X                   ,
                                                            double          * FX                  ,
                                                            double          * oX                  ,
                                                            double          & ioFG                ,
                                                            double          * iXMin               ,
                                                            double          * iXMax               ,
                                                            Accelerator       iAcc                );

// ==========================================
// DATA
// ==========================================
  private:
    CATLONG32   _N; 
    CATLONG32   _Method;
    CATLONG32   _NbParticles;
    CATLONG32   _IsSynchrone;
    CATLONG32   _NbIterations;
    CATLONG32   _NbInformants;
    CATLONG32   _Seed;
    CATLONG32   _NbGivenParticles;
    CATLONG32   _Acceleration;
    CATLONG32   _Counter1,
                _Counter2,
                _Counter3;
    CATLONG32   _Error;
    Accelerator _Acc;
    double      _Constriction;
    double      _Threshold;
    double      _Precision;
    double    * _XMin,
              * _XMax,
              * _XInit,
              * _XRestart;

    // JSX
    CATBoolean  _CurvedSpace; // un peu pompeux, disons que vue de A, B n'est pas dans la direction B-A

    // debug
    CATLONG32   _Debug;
    char      * _FileName;
    ModeTrace   _Mode;

  };
#endif

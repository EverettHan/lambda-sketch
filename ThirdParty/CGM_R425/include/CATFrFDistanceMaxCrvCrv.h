   #define ImplementCATFrFDistanceMaxCrvCrvCGMReplay

// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFDistanceMaxCrvCrv est un objet temporaire pour calculer la distance
// entre 2 courbes (en attendant de l objet mathematique).
//
//==========================================================================
//
// Usage notes: Objet servant a calculer la distance entre 2 courbes.
// Un cheminement est effectue sur la 1ere courbe (!! traitement non
// symetrique) et pour chaque point on calcule le min distance avec la 
// courbe opposee ; le resultat est le max de ces min distances.
// 
//========================================================================== 
// 01/98    JBX  Creation
// 08/12/03 MNA  Ajout de _SoftwareConfig + Ajout dans le constructeur
// 17/06/22 NLD Instrumentation CGMReplay en escroc via macros CATFrFOperator
//              *** le filtre d'enregistrement (Keep=) doit etre strivtement egal à CATFrFDistanceMaxCrvCrv ***
//                        - ajout RunOperator()
//                        - Run() devient de type int au lieu de void
//                          (avec classe mère CATPGMFrFDistanceMaxCrvCrv)
//                        - ajout WriteInput()
//                                Dump()
//                                IsRecordable()
//                                RunOperator()
//                                WriteOutput()
//                                ValidateOutput()
//                                DumpOutput()
//                                CheckOutput()
//                                GetOperatorId()
//                         //     GetBodyWireIn()
//                                ReadOutput()
//                        - ajout _LoadedFromReplay
//                                _LoadingOperator
//                                _OperatorId
//                         //     _BodyIn
//                                _ScaleRatio
//                        - ajout _DistanceMaxPoints et _NbDistanceMaxPoints
//========================================================================== 

#ifndef CATFrFDistanceMaxCrvCrv_H
#define CATFrFDistanceMaxCrvCrv_H

#include "FrFOpeUtil.h"

#include "CATSkillValue.h"
#include "CATPGMFrFDistanceMaxCrvCrv.h"

#ifdef ImplementCATFrFDistanceMaxCrvCrvCGMReplay
#include "CATCGMStream.h"
#include "CATFrFOperator.h"
#endif

#ifdef ImplementCATFrFDistanceMaxCrvCrvCGMReplay
#include "CATCrvLimits.h"
#else
class CATCrvLimits;
#endif
class CATSoftwareConfiguration;
class CATCurve;
class CATGeoFactory;
class CATFrFCheckGeometricContinuity;

#ifdef ImplementCATFrFDistanceMaxCrvCrvCGMReplay
class CATFrFDistanceMaxCrvCrvReplay;
class CATFrFDistanceMaxCrvCrvSister;
class CATExtCGMReplay;
class CATFrFDistanceMaxCrvCrvSister;
#endif

//-----------------------------------------------------------------------------
class ExportedByFrFOpeUtil CATFrFDistanceMaxCrvCrv  : public CATPGMFrFDistanceMaxCrvCrv
{
 #ifdef ImplementCATFrFDistanceMaxCrvCrvCGMReplay
  friend class CATFrFDistanceMaxCrvCrvSister;
 #endif
  public :

    //-------------------  Basic Methods ------------------- 
    //  constructors
    CATFrFDistanceMaxCrvCrv(      CATGeoFactory            * iFactory               ,
                            const CATCurve                 * CRef                   ,
                            const CATCurve                 * C2                     ,
                            const CATCrvLimits             & CLRef                  ,
                            const CATCrvLimits             & CL2                    ,
                            const CATSkillValue            & iMode                  = BASIC,
                                  CATSoftwareConfiguration * iSoftwareConfiguration = NULL);
  
    //  destructor
 virtual                            ~CATFrFDistanceMaxCrvCrv();
  
    //------------------- Data Access Methods -------------------  
  
    // Recuperation de la distance max ; la methode Run doit avoir ete appelee
    // auparavent ou le createur doit avoir ete appele avec iMode = BASIC.
         double                      GetMaxDistance() const ;
  
    // impose les courbes et leur crvlimits
         void                        SetCurveRef(const CATCurve* CRef, const CATCrvLimits& CLRef);
         void                        SetCurveTwo(const CATCurve* C2  , const CATCrvLimits& CL2);

    // Impose le nombre de points discretises ou se feront les tests 
    // de continuite (10 par defaut).
         void                        SetNbOfDiscretizedPoints(int NbOfDiscretizedPoints);


    //------------------- Compute Methods -------------------  
    //   void                        Run (); // anciennement void à passer en int; attention à classe mère CATPGMFrFDistanceMaxCrvCrv
         int                         Run (); // anciennement void à passer en int; attention à classe mère CATPGMFrFDistanceMaxCrvCrv
         int                         RunOperator();

#ifdef ImplementCATFrFDistanceMaxCrvCrvCGMReplay
         // Méthodes relatives au CGMReplay
         void                        WriteInput                       (CATCGMStream             & ioStream      );
         void                        Dump                             (CATCGMOutput             & os            );
         CATExtCGMReplay*
                                     IsRecordable                     (short                    & LevelOfRuntime  ,
                                                                       short                    & VersionOfStream);
         void                        WriteOutput                (      CATCGMStream             & os            );
 
         CATBoolean                  ValidateOutput             (      CATCGMStream             & ioStream      ,
                                                                       CATCGMOutput             & os            ,
                                                                       int                        VersionNumber = 1);

         void                        DumpOutput                 (      CATCGMOutput             & os            );
         void                        DumpOutput                 (      CATCGMStream             & ioStream      ,
                                                                       CATCGMOutput             & os            ,
                                                                       int                        VersionNumber = 1);

         CATCGMOperator::CATCheckDiagnostic
                                     CheckOutput                (      CATCGMOutput             & os         );

   const CATString                 * GetOperatorId              ();
#endif


  private :

    //-------------------PrivateMethods-----------------------------


    //------------------- Datas -------------------
          CATFrFCheckGeometricContinuity* _CheckGeo;
          CATSoftwareConfiguration      * _SoftwareConfig;

#ifdef ImplementCATFrFDistanceMaxCrvCrvCGMReplay
          CATGeoFactory                 * _Factory;
    const CATCurve                      * _Curve1;
    const CATCurve                      * _Curve2;
          CATCrvLimits                    _CrvLimits1;
          CATCrvLimits                    _CrvLimits2;
          int                             _NbOfDiscretizedPoints;

    // Management data for CGMReplay
          int                             _LoadedFromReplay;          // internal
          CATFrFDistanceMaxCrvCrvReplay * _LoadingOperator;           // internal
          double                          _ScaleRatio;

          CATCartesianPoint            ** _DistanceMaxPoints;
          int                             _NbDistanceMaxPoints;

 public:
   static CATString                       _OperatorId;

#endif

};

#ifdef ImplementCATFrFDistanceMaxCrvCrvCGMReplay
// Definition d'un pseudo operateur CATFrFDistanceMaxCrvCrvReplay permettant l'enregistrement des CGMReplays. NLD170622
CATFrFOperatorDefineReplayOperator(CATFrFDistanceMaxCrvCrv, CATFrFDistanceMaxCrvCrvReplay) 
#endif

#endif



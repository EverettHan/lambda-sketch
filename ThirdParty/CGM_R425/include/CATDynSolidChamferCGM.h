/* -*-c++-*- */
#ifndef CATDynSolidChamfer_H_
#define CATDynSolidChamfer_H_

#include "CATCGMNewArray.h"
#include "CATDynSolidXCGM.h"

#include <CATDynChamfer.h>
#include <CATDynChamferRibbon.h>
#include "CATTopOpPrevisualization.h"  // pour enum previsu

#include "BOIMPOPE.h"

class CATDynFilletRibbon;
class CATBlendParams;
class CATGenericHealing;
class CATChamferTool;
class CATConnexComponentManager;
class CATDrawerCollector;
class CATRibbonsReorderTracker;
class CATParting; // Support for limiting element

#include "CATSafe.h"
#include "CATDynChamferContextForFastRun.h"
CATSafeDefine(CATDynSolidChamferCGM);

class ExportedByBOIMPOPE CATDynSolidChamferCGM : public CATDynSolidXCGM
{
 public:
  CATDynSolidChamferCGM (CATGeoFactory    & iContainer,
                         CATTopData       & iData,    
                         CATBody          * iPart);
  CATCGMNewClassArrayDeclare;        // Pool allocation
  virtual ~CATDynSolidChamferCGM();
  
  int RunOperator();
  
  void Append ( CATDynChamferRibbon* );

  void AddLimitingElement (CATBody* iBody, CATDomain* iSkin , const CATOrientation iOrientation);

  void GetSplittingElements (int iSupport, CATLISTP(CATGeometry)&oElementsList, CATListOfInt& oSides);

  // checks if healing is needed, heals chamfer result if yes
  CATBoolean GenericHealChamferResult( CATCGMJournalList *ioJournal);

  virtual void AddDeclarativeManifoldAgents(CATCellManifoldsManager& iCellManifoldsManager,
    ListPOfCATBody &iListOfInputBodies, 
    ListPOfCATBody &iListOfNoCopyInputBodies, 
    CATBody * iOutputBody, 
    CATCGMJournalList* iTopOpJournal);

  void ActivateDrivenChamferRecognition(); //for testing purpose
  //-----------------------------------------------------------------------
  // Data
  //-----------------------------------------------------------------------  
private:

  CATLISTP(CATDynChamferRibbon)   _Ribbons;
  CATLISTP(CATDynChamferRibbon) * _SymetricRibbons; // To clean memory

  // Information about cutting cells generated on the supports 
  // GetSplittingElements
  //----------------------------------------------------------
  ListPOfCATCell              _SplitCell;
  CATListOfInt                _SideKeep;
  CATListOfInt                _NuSupportForSplitCell;

  // Information about limiting elements 
  //----------------------------------------------------------
  CATLISTP(CATBody)           _LimitingBodies;
  CATLISTP(CATDomain)         _LimitingDomains;
  CATListOfInt                _LimitingOrientations;

public :
  void SetCornerCap();
  void SetFilletLongPropagation ();
  void SetKeepFeature ( CATBoolean iKeepFeature );
  void SetRibbonsReorderTracker(CATRibbonsReorderTracker* iTracker); 
  
private:
  CATBoolean                   _CornerCap;
  CATBoolean                   _FilletLongPropagation;
  CATBoolean                   _KeepFeature;
  CATBoolean                   _SetReconfigFillFunc;
  CATBoolean                   _SetBadShapeTreatmentOn;
  CATBoolean                   _DrivenChamferRecognition;
  CATBoolean                   _ApproxChamferMode;
  CATRibbonsReorderTracker*    _RibbonsReorderTracker;
//-----------------------------------------------------------------------
  //- Gestion Mode Record 
  //-----------------------------------------------------------------------  
  static CATString _OperatorId;
  const CATString * GetOperatorId() const;
  int GetCGMApproximateChamferMode();

  //-----------------------------------------------------------------------  
  // Support for limiting element
  //-----------------------------------------------------------------------  
  CATLISTP(CATDynChamferRibbon)   _OldRibbons;
  CATParting*                     _MultiParting;
  CATBoolean UpdateInputBodyWithParting (CATBody* InputBody, CATBody* iCreationBody, CATCGMJournalList * iJournal);
  void GetAllInitialShells (CATBody* InputBody, CATLISTP(CATShell) &InitialShells,int& oSegmentation);
  void UpdateInputs (CATCGMJournalList& iPrivateEdgesJournal, CATBody* InputBody, CATBody* iCreationBody, CATCGMJournalList * iJournal = 0 );
  void RestoreInputData();

public:
  static CATCGMOperator* UnStream(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);
  static const CATString * GetDefaultOperatorId() { return & _OperatorId; };
  void Dump( CATCGMOutput& os ) ;
  void RequireDefinitionOfInputAndOutputObjects();
  void WriteInput(CATCGMStream  & ioStream);
  CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

  void SetReconfigFillFunction();

  void SetBadShapeTreatmentOn();

  void SetApproxChamferMode();

  
  // Useful only for Approximate Chamfer, Retrieve the original Input distances D1 & D2 using Chamfered and Un-Chamfered Body  
  CATBoolean GetOriginalInputSpecsForApproximateChamfer(CATBody * iChamferedBody,
                                                        CATBody * iUnChamferedBody,
                                                        CATEdge * iEdgeToChamfer,
                                                        CATLISTP(CATFace) & iChamferFaces,
                                                        CATFace * iOriginalInputRefFace,
                                                        CATListOfDouble  & iStoredDistancesd1d2,
                                                        CATListOfDouble  & ioOriginalInputsD1D2);

  CATBoolean ComputeOriginalDistancesForApproxChamfer(CATBody * iChamferedBody,
                                                      CATBody * iUnChamferedBody,
                                                      CATShell * iUnChamferedShell,
                                                      CATEdge * iSelectedEdge,
                                                      CATLISTP(CATFace) & iChamferFaces,
                                                      CATFace * iOriginalInputRefFace,
                                                      CATListOfDouble & iStoredDistancesd1d2,
                                                      double & iMinAngle,
                                                      double & iMinCrvParam,
                                                      CATBoolean iIsConvex,
                                                      CATListOfDouble & ioOriginalInputsD1D2);

  void GetOrientedSurfNormal(CATFace * iFace,
                             CATEdge * iInitEdge,
                             CATCrvParam & iCrvParam,
                             CATShell * iShell,
                             CATMathDirection & ioSurNormal);

  void GetG1Faces(CATLISTP(CATFace)* ioFaceList,
                  CATFace * iFirstFace, 
                  CATFace * iSecondFace,
                  CATGeoFactory * iFactory,
                  CATTopData * iTopData,
                  CATBody * iBody,
                  CATShell * iShell);

  CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent, CATCGMOutput& os);

  //-----------------------------------------------------------------------
  // Fast Update
  //-----------------------------------------------------------------------  
   public :
   CATContextForFastRun*            GetContextForFastRun();
   CATDynChamferContextForFastRun*  GetDynChamferContextForFastRun();
   CATContextForFastRun*            GetOrCreateContextForFastRun();
   CATDynChamferContextForFastRun*  GetOrCreateDynChamferContextForFastRun();
   CATBody*                         GetInputBody();
   int                              FastRun(); // Mis ici en attendant que le booléen ne fasse plus appel au code generique. 
   int                              PartialRun(CATBody * ipFastRunResultBody, CATCGMJournalList * ipFastRunJournal);
   int                              GetNbRibbons();
   CATBoolean                       FindCorrespondingInput(CATLISTP(CATFace) &iFacesList);
   int                              FindArgumentsForFastRun(CATConnexComponentManager *  iEdgesConnexComponents,
                                                            CATDrawerCollector *& oRelation_Ribbon_ConnexeComponents,
                                                            CATDrawerCollector *& oRelation_ConnexeComponent_Ribbons
                                                            );
  //-----------------------------------------------------------------------
  // VoB
  //----------------------------------------------------------------------- 
  virtual CATBoolean IsVoBSupported();
};

#endif

#ifndef CATFrFOperator_H
#define CATFrFOperator_H
//==========================================================================
//
// DESCRIPTION : set of macros for defining fake CGMOperator for FrF operators,
//               for quick and easy CGMReplay implement
//               Restricted use
//
//==========================================================================
//
#include <LesBonnesRecettesDuPereLochard.h>
LesBonnesRecettesDuPereLochard(UnpublishedCATFrFOperator, "17/01/17 CGMReplay recording on a non CGM operator through CATFrFOperator set of macros");
//
// Usage notes:
//               let CATFrFSampleOperator be a FreeForm operator not heriting from CATCGMOperator,
//               with no modifiable interface (for instance because of CAA Level1 usage)
//               (we suppose CGMReplay specific methods addition is allowed;
//               this is the case if thers is a generic class and and implementation class:
//               only the implementation class will have new methods)
//
//              (for absolutely non modifiable classes (no possible method add),
//               is would preferable to add a friend class definition
//               for recording)
//
//               we will define a CATCGMOperator associated to CATFrFSampleOperator.
//               let CATFrFSampleOperatorReplay be its name
//
//
//               1) in header              (CATFrFSampleOperator.h)
//                  CATFrFOperatorDefineReplayOperator(CATFrFSampleOperator,CATFrFSampleOperatorReplay) 
//
//               2) in implementation file (CATFrFSampleOperator.cpp)
//                  CATFrFOperatorImplementReplayOperator(CATFrFSampleOperator,CATFrFSampleOperatorReplay) 
//
//               3) in CATFrFSampleOperator define all CGMReplay methods just as if ther was a derivation from CATCGMOperator
//                 - RunOperator()
//                 - IsRecordable()
//                 - WriteInput()
//                 - WriteOutput()
//                 - ValidateOutput()
//                 - Dump()
//                 - DumpOutput() (1st signature)
//                 - DumpOutput() (2nd signature)
//                 - CheckOutput()
//                 - GetOperatorId()
//
//               4) migrate run code from CATFrFSampleOperator::Run() to CATFrFSampleOperator::RunOperator()
//
//                 in CATFrFSampleOperator::Run(), make a simple implementation routing execution
//                 to CATFrFSampleOperatorReplay if recording filter is active
//                 CATFrFOperatorComputeRunCode() may be used for simple filtering
//                 example
//                 int CATFrFSampleOperator::Run()
//                 {
//                    int ReturnCode = 0;
//                    CATFrFOperatorComputeRunCode(CATFrFSampleOperator,CATFrFSampleOperatorReplay,"CATFrFSampleOperator",
//                                                 _Factory,ReturnCode)
//                  return ReturnCode;
//                 }
//
//               5) at the end of CATLoad function, after construction of the CATFrFSampleOperator operator,
//                  construct a CATFrFSampleOperatorReplay operator and return it
//
//==========================================================================
// 17/01/17 NLD Creation
// 19/01/17 NLD L'argument iLoadedFromReplay du constructeur prend la valeur 1 et non plus 0 par defaut
//              pour simplifier l'ecriture des methodes CATLoad
//              La macro CATFrFOperatorComputeRunCode() est modifiee en consequence
// 22/03/18 NLD Adhesion à LesBonnesRecettesDuPereLochard
// 22/11/18 NLD Enrichissement des cas de detournement (forçage du passage par operateur de replay)
//              dans macro CATFrFOperatorComputeRunCode() aux cas où le filtre d'enregistrement
//              est vide mais le mode enregistrement actif (non nul)
// 24/07/19 NLD Ajout _SoftwareConfiguration
//              Ajout GetSoftwareConfiguration()
//              Ajout iSoftwareConfiguration au constructeur
//              (pour interrogation par plateforme, et ligne Summary du fichier .status)
//==========================================================================
// #include "FrFOpeUtil.h"

// On pourrait faire tout simplement un jeu de macros d'apres CATInterproxSurCx2/CATInterproxSurReplay
// pour faire le renvoi du suroperateur vers le pseudo-operateur

#include "CATCGMOperator.h"
#include "CATSoftwareConfiguration.h"

#define CATFrFOperatorDefineReplayOperator(OperatorName,OperatorReplayName)                                 \
class OperatorReplayName : public CATCGMOperator                                                            \
{                                                                                                           \
 public:                                                                                                    \
                            OperatorReplayName   (      CATGeoFactory           *  iFactory      ,          \
                                                        OperatorName            *  iOperator     ,          \
                                                        int                        iLoadedFromReplay = 1,   \
                                                        CATSoftwareConfiguration*  iSoftwareConfiguration = NULL\
                                                 );                                                         \
 virtual                   ~OperatorReplayName   ();                                                        \
                                                                                                            \
        int                 RunOperator          ();                                                        \
                                                                                                            \
        CATExtCGMReplay   * IsRecordable         (      short                   & LevelOfRuntime ,          \
                                                        short                   & VersionOfStream);         \
                                                                                                            \
virtual void                WriteInput           (      CATCGMStream            & os             );         \
                                                                                                            \
virtual void                WriteOutput          (      CATCGMStream            & os             );         \
                                                                                                            \
virtual CATBoolean          ValidateOutput       (      CATCGMStream            & ioStream       ,          \
                                                        CATCGMOutput            & os             ,          \
                                                        int                       VersionNumber  = 1);      \
                                                                                                            \
virtual void                Dump                 (      CATCGMOutput            & os             );         \
                                                                                                            \
virtual void                DumpOutput           (      CATCGMOutput            & os             );         \
                                                                                                            \
virtual void                DumpOutput           (      CATCGMStream            & ioStream       ,          \
                                                        CATCGMOutput            & os             ,          \
                                                        int                       VersionNumber  = 1);      \
                                                                                                            \
virtual CATCGMOperator::CATCheckDiagnostic                                                                  \
                                  CheckOutput   (       CATCGMOutput            & os             );         \
                                                                                                            \
virtual CATSoftwareConfiguration* GetSoftwareConfiguration()                                        const;  \
 private:                                                                                                   \
                                                                                                            \
  const CATString         * GetOperatorId        ();                                                        \
                                                                                                            \
        OperatorName             * _Operator;                                                               \
        int                        _LoadedFromReplay;                                                       \
        CATSoftwareConfiguration * _SoftwareConfiguration;                                                  \
};                                                                                                          //


//==========================================================================
//-----------------------------------------------------------------------
#define CATFrFOperatorDefConstructor(OperatorName,OperatorReplayName)                    \
OperatorReplayName::OperatorReplayName(CATGeoFactory           *  iFactory         ,     \
                                       OperatorName            *  iOperator        ,     \
                                       int                        iLoadedFromReplay,     \
                                       CATSoftwareConfiguration*  iSoftwareConfiguration)\
 : CATCGMOperator(iFactory)                                                              \
{                                                                                        \
 _Operator              = iOperator;                                                     \
 _LoadedFromReplay      = iLoadedFromReplay;                                             \
 _SoftwareConfiguration = iSoftwareConfiguration;                                        \
 if (_SoftwareConfiguration)                                                             \
    _SoftwareConfiguration->AddRef();                                                    \
}                                                                                        //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefDestructor(OperatorName,OperatorReplayName)          \
OperatorReplayName::~OperatorReplayName()                                     \
{                                                                             \
 if (_LoadedFromReplay)                                                       \
    if (_Operator)                                                            \
       delete _Operator;                                                      \
 _Operator = NULL;                                                            \
 if (_SoftwareConfiguration)                                                  \
    _SoftwareConfiguration->Release();                                        \
 _SoftwareConfiguration = NULL;                                               \
}                                                                             //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefRunOperator(OperatorName,OperatorReplayName)         \
int OperatorReplayName::RunOperator()                                         \
{                                                                             \
 if (!_Operator) CATThrowForNullPointerReturnValue(0);                        \
 int ReturnCode = _Operator->RunOperator();                                   \
 return ReturnCode;                                                           \
}                                                                             //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefGetSoftwareConfiguration(OperatorName,OperatorReplayName) \
CATSoftwareConfiguration* OperatorReplayName::GetSoftwareConfiguration() const     \
{                                                                                  \
 return _SoftwareConfiguration;                                                    \
}                                                                                  //

//-----------------------------------------------------------------------
//- Gestion Mode Record
//-----------------------------------------------------------------------  
#define CATFrFOperatorDefIsRecordable(OperatorName,OperatorReplayName)       \
CATExtCGMReplay * OperatorReplayName::IsRecordable(short& LevelOfRuntime ,   \
                                                   short& VersionOfStream)   \
{                                                                            \
 if (!_Operator) CATThrowForNullPointerReturnValue(NULL);                    \
 CATExtCGMReplay* Record = _Operator->IsRecordable(LevelOfRuntime,           \
                                                   VersionOfStream);         \
 return Record;                                                              \
}                                                                            //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefWriteInput(OperatorName,OperatorReplayName)         \
void OperatorReplayName::WriteInput(CATCGMStream& Str)                       \
{                                                                            \
 if (!_Operator) CATThrowForNullPointer();                                   \
 _Operator->WriteInput(Str);                                                 \
}                                                                            //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefWriteOutput(OperatorName,OperatorReplayName)        \
void OperatorReplayName::WriteOutput(CATCGMStream& Str)                      \
{                                                                            \
 if (!_Operator) CATThrowForNullPointer();                                   \
 _Operator->WriteOutput(Str);                                                \
}                                                                            //

//-----------------------------------------------------------------------
//
//-----------------------------------------------------------------------
#define CATFrFOperatorDefValidateInput(OperatorName,OperatorReplayName)      \
CATBoolean OperatorReplayName::ValidateOutput(CATCGMStream& Str            , \
                                              CATCGMOutput& os             , \
                                              int           VersionOfStream) \
{                                                                            \
 if (!_Operator) CATThrowForNullPointer();                                   \
 CATBoolean OkValidate = _Operator->ValidateOutput(Str, os, VersionOfStream);\
 return OkValidate;                                                          \
}                                                                            //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefDump(OperatorName,OperatorReplayName)                \
void OperatorReplayName::Dump(CATCGMOutput            & os             )      \
{                                                                             \
 if (!_Operator) CATThrowForNullPointer();                                    \
 _Operator->Dump(os);                                                         \
}                                                                             //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefDumpOutput(OperatorName,OperatorReplayName)         \
void OperatorReplayName::DumpOutput(CATCGMOutput& os)                        \
{                                                                            \
 if (!_Operator) CATThrowForNullPointer();                                   \
 _Operator->DumpOutput(os);                                                  \
}                                                                            //

//-----------------------------------------------------------------------
// Dump des sorties enregistrees
//-----------------------------------------------------------------------
#define CATFrFOperatorDefDumpOutput2(OperatorName,OperatorReplayName)       \
void OperatorReplayName::DumpOutput(CATCGMStream& Str            ,          \
                                    CATCGMOutput& os             ,          \
                                    int           VersionOfStream)          \
{                                                                           \
 if (!_Operator) CATThrowForNullPointer();                                  \
 _Operator->DumpOutput(Str, os, VersionOfStream);                           \
}                                                                           //

//-----------------------------------------------------------------------
// Check 
//-----------------------------------------------------------------------
#define CATFrFOperatorDefCheckOutput(OperatorName,OperatorReplayName)       \
CATCGMOperator::CATCheckDiagnostic                                          \
OperatorReplayName::CheckOutput(CATCGMOutput             & os         )     \
{                                                                           \
 CATCGMOperator::CATCheckDiagnostic Result = CATCGMOperator::CheckOK;       \
 if (!_Operator) CATThrowForNullPointerReturnValue(Result);                 \
 Result = _Operator->CheckOutput(os);                                       \
 return Result;                                                             \
}                                                                           //

//-----------------------------------------------------------------------
#define CATFrFOperatorDefGetOperatorId(OperatorName,OperatorReplayName)       \
const CATString * OperatorReplayName::GetOperatorId()                         \
{                                                                             \
 if (!_Operator) CATThrowForNullPointerReturnValue(NULL);                     \
 const CATString * OperatorId = _Operator->GetOperatorId();                   \
 return OperatorId;                                                           \
}                                                                             //


#define CATFrFOperatorImplementReplayOperator(OperatorName,OperatorReplayName) \
CATFrFOperatorDefConstructor(OperatorName,OperatorReplayName)                  \
CATFrFOperatorDefDestructor(OperatorName,OperatorReplayName)                   \
CATFrFOperatorDefRunOperator(OperatorName,OperatorReplayName)                  \
CATFrFOperatorDefGetSoftwareConfiguration(OperatorName,OperatorReplayName)     \
CATFrFOperatorDefIsRecordable(OperatorName,OperatorReplayName)                 \
CATFrFOperatorDefWriteInput(OperatorName,OperatorReplayName)                   \
CATFrFOperatorDefWriteOutput(OperatorName,OperatorReplayName)                  \
CATFrFOperatorDefValidateInput(OperatorName,OperatorReplayName)                \
CATFrFOperatorDefDump(OperatorName,OperatorReplayName)                         \
CATFrFOperatorDefDumpOutput(OperatorName,OperatorReplayName)                   \
CATFrFOperatorDefDumpOutput2(OperatorName,OperatorReplayName)                  \
CATFrFOperatorDefCheckOutput(OperatorName,OperatorReplayName)                  \
CATFrFOperatorDefGetOperatorId(OperatorName,OperatorReplayName)                \
                                                                               //

// N.B ci-dessous
//     - il pourrait etre pertinent d'elargir la condition de filtre:
//       lorsqu'on est en enregistrement mais sans filtre (ReplayFilter == NULL)
//       pour considerer alors que l'operateur DOIT etre enregistré
//       interroger donc CATCGMReplayRecord::GetMode()
//       et tester sa non nullité
//       sachant que c'est le gestionnaire de replays lui-meme qui ensuite
//       agira en fonction des conditions d'enregistrement
//     - cependant mon optique jusqu'ici etait de ne detourner que lorsqu'il y avait
//       demande explicite d'enregistrement dedié, afin de ne pas introduire de
//       perturbation dans les fonctionnements standards
//     - Je tente cela; voir ExtendedModeNoFilter NLD221118
#define CATFrFOperatorComputeRunCode(OperatorName,OperatorReplayName,OperatorId,FactoryName,RunReturnCode) \
{                                                                              \
 int         RunDone       = 0;                                                \
 int         ThroughReplay = 0;                                                \
 const char* ReplayFilter  = CATCGMReplayRecord::GetKeepName() ;               \
 int         ReplayMode    = CATCGMReplayRecord::GetMode() ;                   \
 int         ExtendedModeNoFilter = 1;                                         \
 if (   (    ReplayFilter                                                      \
         && (   (!strcmp(ReplayFilter, OperatorId))                            \
            )                                                                  \
        )                                                                      \
     || (  (!ReplayFilter)                                                     \
         && (ReplayMode != 0)                                                  \
         && ExtendedModeNoFilter                                               \
        )                                                                      \
    )                                                                          \
    ThroughReplay = 1;                                                         \
 if (ThroughReplay)                                                            \
   {                                                                           \
    int LoadedFromReplay = 0;                                                  \
    OperatorReplayName Replay(FactoryName, this, LoadedFromReplay);            \
    RunReturnCode = Replay.Run();                                              \
    RunDone        = 1;                                                        \
   }                                                                           \
 if (!RunDone)                                                                 \
    RunReturnCode = RunOperator();                                             \
}                                                                              //

#endif

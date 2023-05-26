/* -*-C++-*- */

#ifndef CATRemoveFaceDebug_H
#define CATRemoveFaceDebug_H
/*  
=============================================================================

RESPONSABLE  : ZUT

DESCRIPTION  : Various debug utilities for RemoveFace\RemoveFacePlus operators
               
=============================================================================
*/

#include "CATBoolean.h"

//-Constantes du preprocesseur----------------------------------------------

//#define DEBUG_RF_LOGGER  // Activation du report des traces vers les fichiers <ODTName>.RFTraces (en mode Replay d'ODTs)
//#define DEBUG_RF_CHRONO  // Activation du timer
//#define DEBUG_RF_LOCALOPE // Activation de l'affichage des traces du RemoveFace local
//#define DEBUG_RF_ADVRF   // Activation de l'affichage des traces du AdvancedRemoveFace
//#define DEBUG_RF_RFG1G2  // Activation de l'affichage des traces du RemoveFaceG1G2
//#define DEBUG_RF_PLUS    // Activation de l'affichage des traces du RemoveFacePlus
//#define DEBUG_RF_DFTR    // Activation de l'affichage des traces du DefeatureOpe
//#define DEBUG_RF_INNER    // Activation de l'affichage des traces du RemoveInnerLoopFaces
//--------------------------------------------------------------------------


//-Activation des developpements--------------------------------------------

int IsLocalRFEnabled();                 // Activation du RemoveFace local par variable d'environnement CATRemoveFace_LocalRFEnabled
int StopWhenRF2DFailed();               // Desactivation de l'appel de secours a RemoveFace classique par variable d'environnement CATRemoveFace_StopWhenRF2DFailed (CATDevelopmentStage=TRUE)
int CheckPartialRFIntermediateBodies(); // Activation du check des bodies intermediaires crees lors de l'execution de RemoveFacePlus (CATDevelopmentStage=TRUE)
//--------------------------------------------------------------------------


//-Logger :-----------------------------------------------------------------

// Si active,
//   En mode replay d'ODTS, ecriture des traces dans des fichiers \LOG\RFTraces\*.RFTraces propres a chaque ODT
//   Sinon, affichage des traces dans la console
// Si desactive, affichage des traces dans la console

// Variable d'environement CATRemoveFace_RFTracesOutputPath :
//   Pour definir le dossier de sortie : CATRemoveFace_RFTracesOutputPath=E:\tmp
//   Pour forcer l'affichage dans la console : CATRemoveFace_RFTracesOutputPath=console

#ifdef DEBUG_RF_LOGGER

#include "Thick.h"

class CATCGMOutput;
class CATUnicodeString;

class ExportedByThick CATRemoveFaceLogger
{
public:
  static CATCGMOutput & GetRemoveFaceLogStream();
  static void CloseRemoveFaceLogStream();  
  static CATUnicodeString GetODTLineHeader();

private:
  static void InitRemoveFaceLogStream();

  static CATCGMOutput * _RFLogStream;
};

#define CLOSE_RFLOGGER CATRemoveFaceLogger::CloseRemoveFaceLogStream()
#define rflog   (CATRemoveFaceLogger::GetRemoveFaceLogStream())
#define rflognl (CATRemoveFaceLogger::GetRemoveFaceLogStream() << CATRemoveFaceLogger::GetODTLineHeader())

#else

#define CLOSE_RFLOGGER
#define rflog   (cgmout)
#define rflognl (cgmout)

#endif /* DEBUG_RF_LOGGER */
//--------------------------------------------------------------------------


//-Affichage des traces du RemoveFace local---------------------------------

#ifdef DEBUG_RF_LOCALOPE

#include "CATUnicodeString.h"
#include "CATBodyName.h"

#define LOCALOPE_HEADER "=== LOCALOPE === "

#endif /* DEBUG_RF_LOCALOPE */
//--------------------------------------------------------------------------


//-Affichage des traces du AdvancedRemoveFace-------------------------------

#ifdef DEBUG_RF_ADVRF

#define ADVRF_HEADER "==== ADVRF ==== "

#endif /* DEBUG_RF_ADVRF */
//--------------------------------------------------------------------------


//-Affichage des traces du RemoveFaceG1G2-----------------------------------

#ifdef DEBUG_RF_RFG1G2

#define RFG1G2_HEADER "==== RFG1G2 ==== "

#endif /* DEBUG_RF_RFG1G2 */
//--------------------------------------------------------------------------

//-Affichage des traces du RemoveFacePlus-----------------------------------

#ifdef DEBUG_RF_PLUS

#define RFPLUS_HEADER "==== RFPLUS ==== "

#endif /* DEBUG_RF_PLUS */
//--------------------------------------------------------------------------

//-Affichage des traces du DefeatureOpe-------------------------------------

#ifdef DEBUG_RF_DFTR

#define DFTR_HEADER "==== DFTR ==== "

#endif /* DEBUG_RF_DFTR */
//--------------------------------------------------------------------------

//-Affichage des traces du RemoveInnerLoopFaces-------------------------------------

#ifdef DEBUG_RF_INNER

#define RFINNER_HEADER "==== RFINNER ==== "

#endif /* DEBUG_RF_INNER */
//--------------------------------------------------------------------------

//-Activation et affichage des traces des timers----------------------------

#ifdef DEBUG_RF_CHRONO

#define CHRONO_HEADER "==== TIMER ==== "

#include "Thick.h"
#include "CATechTimer.h"
#include "CATUnicodeString.h"
#include "CATCGMOutput.h"
#include "CATCGMHashDico.h"

struct ExportedByThick RFTimerBlock
{
  RFTimerBlock( const char * iBlockName ) : _BlockId(iBlockName), _Counter(1), _TotalCPU(0) {}
  ~RFTimerBlock() {}

  CATUnicodeString _BlockId;
  CATLONG32        _Counter;
  CATLONG32        _TotalCPU;
};

struct ExportedByThick RFGlobalTimer
{
  RFGlobalTimer() { _TimerBlocksDico = new CATCGMHashDico(32); }

  ~RFGlobalTimer()
  { 
    Dump();

    int nbElem = _TimerBlocksDico -> Size();
    int iPos;
    for ( iPos = 0; iPos < nbElem; ++iPos )
    {
      RFTimerBlock * timerBlock = (RFTimerBlock *) _TimerBlocksDico ->GetAssoc(iPos);
      if ( timerBlock )
        delete timerBlock;
    }
    delete _TimerBlocksDico;
    _TimerBlocksDico = NULL;
  }

  CATLONG32 GetCount( const char * blockID )
  {
    RFTimerBlock * block = (RFTimerBlock *) _TimerBlocksDico -> Locate(blockID);
    if ( block )
      return block -> _Counter;
    return 0;
  }

  void InsertBlock( RFTimerBlock & iTimerBlock )
  {
    const char * blockID = iTimerBlock._BlockId.CastToCharPtr();

    RFTimerBlock * block = (RFTimerBlock *) _TimerBlocksDico -> Locate(blockID);
    if ( block )
    {
      block -> _TotalCPU += iTimerBlock._TotalCPU;
      block -> _Counter++;
    }
    else
    {
      block = new RFTimerBlock(blockID);
      block -> _TotalCPU = iTimerBlock._TotalCPU;
      blockID = block -> _BlockId.CastToCharPtr();
      _TimerBlocksDico -> Insert(blockID, block);
    }
  }

  void Dump()
  {
    rflognl << "==== GLOBAL TIMER ============================ " << cgmendl;
    int nbElem = _TimerBlocksDico -> Size();
    int iPos;
    for ( iPos = 0; iPos < nbElem; ++iPos )
    {
      RFTimerBlock * timerBlock = (RFTimerBlock *) _TimerBlocksDico ->GetAssoc(iPos);
      if ( timerBlock )        
        rflognl << "==== GLOBAL TIMER ==== " << timerBlock -> _BlockId << " : COUNT = " << timerBlock -> _Counter << " ELAPSED = " << timerBlock -> _TotalCPU << " ms" << cgmendl;
    }
  }

  static RFGlobalTimer & GlobalTimer();

  CATCGMHashDico * _TimerBlocksDico;
};

struct ExportedByThick RFSmartTimer
{
  RFSmartTimer( const char * iBlockName )
  : _TimerBlock(iBlockName)
  { 
    _Timer._Reset();
  }

  ~RFSmartTimer()
  {
    if( !_Timer._IsStopped() )
    { _Timer._Stop(); Dump(); }

    CATLONG32 elapsed = _Timer._GetCPU();
    _TimerBlock._TotalCPU += elapsed;

    RFGlobalTimer::GlobalTimer().InsertBlock(_TimerBlock);
  }

  void Reset()
  {
    CATLONG32 elapsed = _Timer._GetCPU();
    _TimerBlock._TotalCPU += elapsed;
    _Timer._Reset();
  }

  void Dump()
  {
    CATBoolean isStopped = _Timer._IsStopped();
    _Timer._Stop();

    CATLONG32 elapsed = _Timer._GetCPU();
    CATLONG32 curCount = RFGlobalTimer::GlobalTimer().GetCount(_TimerBlock._BlockId.CastToCharPtr()) + 1;
    rflognl << CHRONO_HEADER << _TimerBlock._BlockId << " : COUNT = " << curCount << " ELAPSED = " << elapsed << " ms" << cgmendl;
    
    if ( !isStopped )
      _Timer._Start();
  }

  void Start() { _Timer._Start(); }
  void Stop()  { _Timer._Stop(); }

  RFTimerBlock _TimerBlock;
  CATechTimer  _Timer;
};

#define RF_CHRONO_INIT(timer, blockName)  RFSmartTimer RF_##timer(#blockName)
#define RF_CHRONO_BLOCK(timer, blockName)  RFSmartTimer RF_##timer(#blockName); RF_##timer.Start()
#define RF_CHRONO_FUNC(timer, blockName)  RFSmartTimer RF_##timer(#blockName"()"); RF_##timer.Start()
#define RF_CHRONO_START(timer) RF_##timer.Start()
#define RF_CHRONO_STOP(timer)  RF_##timer.Stop()
#define RF_CHRONO_RESET(timer) RF_##timer.Reset()
#define RF_CHRONO_DUMP_ELAPSED(timer) RF_##timer.Dump()

#else

#define RF_CHRONO_INIT(timer, blockName)
#define RF_CHRONO_BLOCK(timer, blockName)
#define RF_CHRONO_FUNC(timer, blockName)
#define RF_CHRONO_START(timer)
#define RF_CHRONO_STOP(timer)
#define RF_CHRONO_RESET(timer)
#define RF_CHRONO_DUMP_ELAPSED(timer)

#endif /* DEBUG_RF_CHRONO */
//--------------------------------------------------------------------------

#endif /* CATRemoveFaceDebug_H */

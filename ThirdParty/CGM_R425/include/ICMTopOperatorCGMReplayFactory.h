#ifndef ICMTopOperatorCGMReplayFactory_h
#define ICMTopOperatorCGMReplayFactory_h

// export includes
//#include "ExportedByICMOperatorTop_Replay.h"
#include "AdvTopoUtil.h"

// To NO REMOVE Define ICM_CGMReplay_R19CAA_ImplementStreamFactoryInAdvancedTopologicalOPE
#include "ICMTopOperatorCGMReplayFactoryCreate.h"

#ifdef ICM_CGMReplay_R19CAA_ImplementStreamFactoryInAdvancedTopologicalOPE
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////#include "CATExtCGMReplay.h"
////////////#include "CATCGMNewArray.h"
////////////
/////////////**
////////////* Interface to manage persistency with CATMathStream/CACGMStream infrastructure
////////////*/
////////////class ExportedByAdvTopoUtil /*ExportedByICMOperatorTop_Replay*/ ICMTopOperatorCGMReplayFactory : public CATExtCGMReplay
////////////{
////////////  CATDeclareClass;
////////////  
////////////public:
////////////  /** @nodoc */
////////////  CATCGMNewClassArrayDeclare;
////////////  
////////////  void GetSharedlibOfOperator(const char *operatorId, char* & sharedLib);
////////////
////////////  HRESULT GetAvailableOperators(CATListOfCATString &opIds);
////////////};

#endif
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
#endif

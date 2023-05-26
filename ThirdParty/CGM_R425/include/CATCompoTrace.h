/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
/**
 *  CATCompoTrace : - trace used to debug Compound File code
 *
 */
//================================================================
//  Usage notes :
//
//		06/98		slg
//================================================================
#ifndef CATCompoTrace_H
#define CATCompoTrace_H

/**
 * @level Private
 * @usage U1
 */

#include "CATTrace.h"
#include "AC0XXLNK.h"
class CATOMBAbendInfo;
class CATLifeCycleTraceManager;

extern ExportedByAC0XXLNK CATTrace* TraceCompo;
extern ExportedByAC0XXLNK CATTrace* TraceRoll;
extern ExportedByAC0XXLNK CATTrace* TraceLinkTrader;
extern ExportedByAC0XXLNK CATTrace* TraceLinkSynchro;
extern ExportedByAC0XXLNK CATTrace* TraceImporterExporterMngr;//are
extern ExportedByAC0XXLNK CATLifeCycleTraceManager* TraceLifeGraph;
extern ExportedByAC0XXLNK CATTrace* TraceCATNonCATIADocument;
extern ExportedByAC0XXLNK CATTrace* TraceOMSdm;
extern ExportedByAC0XXLNK CATTrace* TraceProperty;
extern ExportedByAC0XXLNK CATTrace* ActiveTrace;
//ajout BHG
extern ExportedByAC0XXLNK CATTrace* TraceUnloadDoc;
//fin BHG
extern ExportedByAC0XXLNK CATTrace * TracePerfo;
extern ExportedByAC0XXLNK CATTrace * TraceOmbVVS;
extern ExportedByAC0XXLNK CATTrace * TraceCATOmbSwitchEngineError;
extern ExportedByAC0XXLNK int ActiveLinkCount;
extern ExportedByAC0XXLNK int ActivePreview; // Preview format (metafile)
extern ExportedByAC0XXLNK int ActiveProperties; 
extern ExportedByAC0XXLNK int ActivePartialLoad; 
extern ExportedByAC0XXLNK int ActiveDocEnv;//1
extern ExportedByAC0XXLNK int StoreAppliTimer;
extern ExportedByAC0XXLNK int ActiveFlags;
extern ExportedByAC0XXLNK int UpgradeVersion;
extern ExportedByAC0XXLNK int PerfoGraph;
extern ExportedByAC0XXLNK int PDMLogAppliCont;
extern ExportedByAC0XXLNK int IsPDMXMLDebugMode;
extern ExportedByAC0XXLNK int CATGlobalUndo;

#define PERFO_GRAPH_BIS


ExportedByAC0XXLNK 
int GetCATOMBAbendInfo(CATOMBAbendInfo*& AbendInfo);
//Project SESSION UNDO
#define NEW_SESSIONUNDO_BUILDRJS //tempo RJS to avoid build error between OSM and OMB, do not use
extern ExportedByAC0XXLNK int CATSessionUndoRunning;



#endif

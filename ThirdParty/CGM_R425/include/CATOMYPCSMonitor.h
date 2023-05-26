#ifndef CATOMYPCSMonitor_H
#define CATOMYPCSMonitor_H

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined (__CATOMYPCSMonitor)
#define ExportedByCATOMYPCSMonitor DSYExport
#else
#define ExportedByCATOMYPCSMonitor DSYImport
#endif
#include "DSYExport.h"

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

//=======================================================================
extern "C" ExportedByCATOMYPCSMonitor int DSYSysIRMonitorInitialize(void** ioppMonitorContainer, const int iPid);
//=======================================================================

//=======================================================================
extern "C" ExportedByCATOMYPCSMonitor int DSYSysIRMonitorFinalize(void** ioppMonitorContainer);
//=======================================================================

//=======================================================================
extern "C" ExportedByCATOMYPCSMonitor int DSYSysIRMonitorSetGlobalMemoryStatus ( void* ipMonitorContainer, const int iTimingFlag
                                                                                          , const unsigned int ipMemoryLoad
                                                                                          , const unsigned long long ipTotalPhys
                                                                                          , const unsigned long long ipAvailPhys
                                                                                          , const unsigned long long ipTotalPageFile
                                                                                          , const unsigned long long ipAvailPageFile
                                                                                          , const unsigned long long ipTotalVirtual
                                                                                          , const unsigned long long ipAvailVirtual);
//=======================================================================

//=======================================================================
extern "C" ExportedByCATOMYPCSMonitor int DSYSysIRMonitorSetCpuUsage(void* ipMonitorContainer, const int iTimingFlag, const unsigned int iCpuUsage);
//=======================================================================

//=======================================================================
extern "C" ExportedByCATOMYPCSMonitor int DSYSysIRMonitorSetVMemUsage(void* ipMonitorContainer, const int iTimingFlag, const unsigned int iVMemUsage);
//=======================================================================

#endif  // CATOmyPCSMonitor_H

/*
// COPYRIGHT DASSAULT SYSTEMES 2010
#ifndef CATOmyPCSMonitor_H
#define CATOmyPCSMonitor_H

/**
* @level Private
* @usage U1
*/
/*
#if defined (__CATOmyPCSMonitor)
#define ExportedByCATOmyPCSMonitor DSYExport
#else
#define ExportedByCATOmyPCSMonitor DSYImport
#endif
#include "DSYExport.h"

//===========================================================================
//  Abstract of the class:
//  ----------------------
//
//  Class which represents an addin of the General Workshop.
//  It implements the CATIAfrGeneralWksAddin interface which is
//  specified by the General workshop as the interface to implement in its
//  addins. 
//
//===========================================================================

// System Framework
#include "CATCommand.h"


class ExportedByCATOmyPCSMonitor CATOmyPCSMonitor : public CATCommand
{

  public:
     CATOmyPCSMonitor();
     virtual ~CATOmyPCSMonitor();

  private :
  
     int NetworkAnalysis();
     int HardDriveSpace();
     int VirtualMemory();
     int ProcessAnalysis();
     int CPU_Usage();

     // Copy constructor, not implemented
     // Set as private to prevent from compiler automatic creation as public.
     CATOmyPCSMonitor(const CATOmyPCSMonitor &iObjectToCopy);

     // Assigment operator, not implemented
     // Set as private to prevent from compiler automatic creation as public.
     CATOmyPCSMonitor & operator = (const CATOmyPCSMonitor &iObjectToCopy);
};
#endif*/

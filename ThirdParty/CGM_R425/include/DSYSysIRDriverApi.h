#ifndef DSYSysIRDriverApi_H
#define DSYSysIRDriverApi_H

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
// COPYRIGHT DASSAULT SYSTEMES 2020

#if defined (__DSYSysWatchDogAgent)
# define ExportedByDSYSysIRDriverApi  DSYExport
#else
# define ExportedByDSYSysIRDriverApi  DSYImport
#endif
#include "DSYExport.h"

#ifdef _WINDOWS_SOURCE
# define  DSYSysIRDriverApiFileTime   SYSTEMTIME
#else   // _WINDOWS_SOURCE
# define DSYSysIRDriverApiFileTime    struct tm
#endif  // _WINDOWS_SOURCE

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYSysCommon.h"

/************************************************************************/
/* Types definition                                                     */
/************************************************************************/

//=======================================================================
typedef void(*DSYSysIRDriverApiModuleInfoW_t) ( const wchar_t*                                /* File path          */
                                              , const unsigned short                          /* Major version      */
                                              , const unsigned short                          /* Minor version      */
                                              , const unsigned short                          /* Build number       */
                                              , const unsigned short                          /* Revision           */
                                              , const DSYSysIRDriverApiFileTime* ipSystemTime /* File time (UTC)    */
                                              , void*                                         /* Custom parameter   */);
//=======================================================================

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

//=======================================================================
typedef void* HDEBUGMATERIAL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
/** 
 * Function to create an handle
 * @param ihDebugMaterial       : Handle on the object, initialized at nullptr.
 * @param ippDirectoryPathList  : Array of dictory path to watch.
 * @param iDirectoryPathCount   : Size of the array of directory path to watch.
 * @param ipFilter              : Path filter as a CSV (;) string.
 */
extern "C" ExportedByDSYSysIRDriverApi void DSYSysIRDriverApiDebugMaterialCreate  ( HDEBUGMATERIAL*              ophDebugMaterial
                                                                                  , const _DSYSysUTF8_(char)** ippDirectoryPathList
                                                                                  , const size_t               iDirectoryPathCount
                                                                                  , const _DSYSysUTF8_(char)*  ipFilter = nullptr);

//=======================================================================

//=======================================================================
/** 
 * Function to start monitoring directories given in DSYSysIRDriverApiDebugMaterialCreate
 * @param ihDebugMaterial    : Handle on the object
 */
extern "C" ExportedByDSYSysIRDriverApi int DSYSysIRDriverApiDebugMaterialStart(HDEBUGMATERIAL ihDebugMaterial);
//=======================================================================

//=======================================================================
/** 
 * Function to stop monitoring directories
 * @param ihDebugMaterial    : Handle on the object
 */
extern "C" ExportedByDSYSysIRDriverApi void DSYSysIRDriverApiDebugMaterialStop(HDEBUGMATERIAL ihDebugMaterial);
//=======================================================================

//=======================================================================
/** 
 * Function to generate an archive with the files monitored so far.
 * @param ihDebugMaterial    : Handle on the object
 * @param opPath             : Folder of the archive
 * @param iPathLen           : Length of the folder path
 * @param opUuid             : Archive name
 * @param iUuid              : Archive name length
 */
extern "C" ExportedByDSYSysIRDriverApi int DSYSysIRDriverApiDebugMaterialGenerate ( HDEBUGMATERIAL ihDebugMaterial
                                                                                  , _DSYSysUTF8_(char)* opPath
                                                                                  , const size_t iPathLen
                                                                                  , _DSYSysUTF8_(char)* opUuid
                                                                                  , const size_t iUuid);
//=======================================================================

//=======================================================================
/** 
 * Function to destroy the handle
 * @param ihDebugMaterial    : Handle on the object.
 */
extern "C" ExportedByDSYSysIRDriverApi void DSYSysIRDriverApiDebugMaterialDestroy(HDEBUGMATERIAL* iophDebugMaterial);
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
/**
 * Function to get the list of the modules of a given running process.
 * 
 * @param iProcessId    : Process identifier.
 * @param ifModuleInfo  : Callback function for each module.
 * @param ipModuleInfo  : Callback function opaque parameter.
 */
extern "C" ExportedByDSYSysIRDriverApi void DSYSysIRDriverApiDebugMaterialListModulesW  ( const int iProcessId
                                                                                        , DSYSysIRDriverApiModuleInfoW_t ifModuleInfo
                                                                                        , void* ipModuleInfo/* = nullptr */);
//=======================================================================

#endif  // DSYSysIRDriverApi_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1997
//============================================================================
//
// CATReadCgrFilesMT
//
//=============================================================================
//
// Usage notes: multi-threaded cgr files unstreaming
//
// Thread safe, manage without static variable, nor software monocode, nor environnement variables  
//
//=============================================================================
// Sept 2019                                        Creation: TPG
//=============================================================================

#ifndef CATReadCgrFilesMT_H
#define CATReadCgrFilesMT_H

#include "CATReadWriteCgr.h"

 /**
 * This function reads a Cgr files (CATILockBytes2) list and returns their graphic data as an array of pointers to CAT3DRep objects.
 * <b>Role:</b>This function reads a Cgr files list and returns their graphic data as an array of pointers to CAT3DRep objects.
 * @return
 *    This function returns an array of pointers to CAT3DRep. 
 *    This array size is equal to the number of Cgr files to read. 
 *    Each field contains, as a pointer to a CAT3DRep, the representation of the corresponding Cgr file.
 *    If the function encounters a problem during the reading of a Cgr file, the corresponding field of the returned array is NULL.
 * @param iLB2list
 *    The list of Cgr files from CATILockBytes2 to read.
 * <b>Warning:</b>
 *  <ul>          
 *    <li>
 *    This list should not contain identical CATILockBytes2 pointers (i.e. duplicates) if threadCount>1 (i.e. multithreaded read), otherwise data race issues.
 *    </li>
 *  </ul>
 * @param iSizeList
 *    The number of Cgr files to read.
 * @param iSettingCgr
 *    The CATSettingCgr flag to specify the kind of graphic data we want to read in the cgr file.
 * @param threadCount
 *    The number of threads to use.
 *    Set threadCount = 1 if a single-threaded read is required.
 * @param targetLevel
 *    Semantic Level applied on the scene graph and the render.
 *    The default value is set to <tt>HIGH</tt>.
 * @param ioMode
 *    Defines the method used for reading the CGR.
 *    The default value is set to <tt>CATVizCGRAccessModeMemory</tt>.
 */
extern ExportedBySGInfra cgrFileStatus* CATReadCgrFilesMT(CATILockBytes2 **iLB2list,
														   int iSizeList,
														   CATSettingCgr iSettingCgr,
														   int threadCount,
														   CATVizSemanticLevel targetLevel = HIGH,
														   CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

 /**
 * This function reads a Cgr files (file path) list and returns their graphic data as an array of pointers to CAT3DRep objects.
 * <b>Role:</b>This function reads a Cgr files list and returns their graphic data as an array of pointers to CAT3DRep objects.
 * @return
 *    This function returns an array of pointers to CAT3DRep. 
 *    This array size is equal to the number of Cgr files to read. 
 *    Each field contains, as a pointer to a CAT3DRep, the representation of the corresponding Cgr file.
 *    If the function encounters a problem during the reading of a Cgr file, the corresponding field of the returned array is NULL.
 * @param iFileNamelist
 *    The list of Cgr files to read.
 * <b>Warning:</b>
 *  <ul>          
 *    <li>
 *    This list should not contain identical Cgr files (i.e. duplicates) if threadCount>1 (i.e. multithreaded read), otherwise data race issues.
 *    </li>
 *  </ul>
 * @param iSizeList
 *    The number of Cgr files to read.
 * @param iSettingCgr
 *    The CATSettingCgr flag to specify the kind of graphic data we want to read in the cgr file.
 * @param threadCount
 *    The number of threads to use.
 *    Set threadCount = 1 if a single-threaded read is required.
 * @param targetLevel
 *    Semantic Level applied on the scene graph and the render.
 *    The default value is set to <tt>HIGH</tt>.
 * @param ioMode
 *    Defines the method used for reading the CGR.
 *    The default value is set to <tt>CATVizCGRAccessModeMemory</tt>.
 */
extern ExportedBySGInfra cgrFileStatus* CATReadCgrFilesMT(char **iFileNamelist,
														   int iSizeList,
														   CATSettingCgr iSettingCgr,
														   int threadCount,
														   CATVizSemanticLevel targetLevel = HIGH,
														   CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

 /**
 * This function reads a Cgr files (buffer) list and returns their graphic data as an array of pointers to CAT3DRep objects.
 * <b>Role:</b>This function reads a Cgr files list and returns their graphic data as an array of pointers to CAT3DRep objects.
 * @return
 *    This function returns an array of pointers to CAT3DRep. 
 *    This array size is equal to the number of Cgr files to read. 
 *    Each field contains, as a pointer to a CAT3DRep, the representation of the corresponding Cgr file.
 *    If the function encounters a problem during the reading of a Cgr file, the corresponding field of the returned array is NULL.
 * @param iBufferList
 *    The buffer (of Cgr file) list to read.
 * <b>Warning:</b>
 *  <ul>          
 *    <li>
 *    This list should not contain identical Buffers (i.e. duplicates) if threadCount>1 (i.e. multithreaded read), otherwise data race issues.
 *    </li>
 *  </ul>
 * @param iLBufferList
 *    The length, in bytes of each buffer.
 * @param iSizeList
 *    The number of the buffer list to read.
 * @param iSettingCgr
 *    The CATSettingCgr flag to specify the kind of graphic data we want to read in the cgr file.
 * @param threadCount
 *    The number of threads to use.
 *    Set threadCount = 1 if a single-threaded read is required.
 * @param targetLevel
 *    Semantic Level applied on the scene graph and the render.
 *    The default value is set to <tt>HIGH</tt>.
 * @param ioMode
 *    Defines the method used for reading the CGR.
 *    The default value is set to <tt>CATVizCGRAccessModeMemory</tt>.
 */
extern ExportedBySGInfra cgrFileStatus* CATReadCgrFilesMT(char **iBufferList, int *iLBufferList,
														   int iSizeList,
														   CATSettingCgr iSettingCgr,
														   int threadCount,
														   CATVizSemanticLevel targetLevel = HIGH,
														   CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

#endif

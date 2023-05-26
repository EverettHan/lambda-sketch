#ifndef CATReadWriteCgr_h
#define CATReadWriteCgr_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

class CATRep;
class CAT3DRep;
class CATColorMap;
class CATCGRSetting;
class CATDescribeCgr;
class CATCgrHeader;
class CATMutex;
class CATStorage;
class CATCGRContainer;
class CATILockBytes2;

/** @nodoc */
typedef struct _cgrfile cgrfile;

#include "SGInfra.h"
#include "CATBoolean.h"
#include "CATVizGlobals.h"


#ifndef NULL
#define NULL 0
#endif 

// JUT : A macro that defines a library on various OS based on it's root name
#if defined   (_AIX)
/** @nodoc */
#define LIBFILENAME(iName) "lib" #iName ".a"
#elif defined (_IRIX_SOURCE) 
/** @nodoc */
#define LIBFILENAME(iName) "lib" #iName ".so"
#elif defined (_WINDOWS_SOURCE) 
/** @nodoc */
#define LIBFILENAME(iName) "" #iName ".dll"
#elif defined(_SUNOS_SOURCE)
/** @nodoc */
#define LIBFILENAME(iName) "lib" #iName ".so"
#elif defined(_HPUX_SOURCE)
/** @nodoc */
#define LIBFILENAME(iName) "lib" #iName ".sl"
#elif defined(_DARWIN_SOURCE)
/** @nodoc */
#define LIBFILENAME(iName) "lib" #iName ".dylib"
#elif defined(_LINUX_SOURCE)
/** @nodoc */
#define LIBFILENAME(iName) "lib" #iName ".so"
#elif defined(_ANDROID_SOURCE)
/** @nodoc */
#define LIBFILENAME(iName) "lib" #iName ".so"
#else
/** @nodoc */
#define LIBFILENAME(iName) ""
#endif

/**
 * Flag to specify the kind of graphic data we want to store in a Cgr file.
 * <br>This flag is used in <tt>CATReadCgr</tt> and <tt>CATWriteCgr</tt> methods.
 * @param USE_NONE
 *    To save nothing
 * @param USE_LODS
 *    To save the Levels Of Details
 * @param USE_TEXTURE
 *    To save textures
 * @param USE_LODS_TEXTURE
 *    To save textures and Levels Of Details
 * @param USE_EDGE
 *    To save edges
 * @param USE_LODS_EDGE
 * @param USE_TEXTURE_EDGE
 *    To save textures and edges
 * @param USE_LODS_TEXTURE_EDGE
 *    To save Levels Of Details, texture and edges
 * @param USE_SHOW_NOSHOW
 *    To specify that the whole representation
 *    tree must be saved, whether it belongs to "show" or "no show" space.
 *    When the flag is set equal to <tt>USE_SHOW_NOSHOW</tt>,
 *    the Levels Of Details, texture and edges are saved.
 * @param USE_3DCUSTOMREP
 *    To save graphic representations of
 *    type CAT3DCustomRep, which are not ususally stored. For example, to save a CAT3DCustomRep
 *    with its Levels Of Details, texture and edges, the flag should
 *    be set to <tt>USE_LODS_TEXTURE_EDGE | USE_3DCUSTOMREP</tt>.
 * @param USE_LINEIC
 *    To save lineic informations (Wireedge - 3DLineRep).
 *    Using this setting force save of 3DCustomRep
 * @param USE_NOSHOWLAYER
 *    To save informations which are in no-shown layer.
 * @param USE_NOMATERIAL
 *    Materials are not saved
 * @param USE_NOSGCOMP
 *    SG Composites are not saved
 * @param USE_TEXT_MESH
 *    CAT2DGeometricTextGP tessellation is saved
 */
enum CATSettingCgr {USE_NONE=0x0,
                    USE_LODS=0x1,
                    USE_TEXTURE=0x2,
                    USE_LODS_TEXTURE=0x3,
                    USE_EDGE=0x4,
                    USE_LODS_EDGE=0x5,
                    USE_TEXTURE_EDGE=0x6,
                    USE_LODS_TEXTURE_EDGE=0x7,
					     USE_SHOW_NOSHOW=0x8,
                    USE_3DCUSTOMREP=0x10,
					     USE_LINEIC=0x20,
               USE_NOSHOWLAYER=0x40,
               USE_NOMATERIAL=0x80,
               USE_NOSGCOMP=0x100,
               USE_TEXT_MESH=0x200};

/** @nodoc
 * Error codes for IO on CGR files
 */
enum CATCGRReturnCode
{
   S_CGR_OK       =  0,
   E_CGR_FAIL,
   E_CGR_ACCESS_DENIED,
   E_CGR_OUT_OF_MEMORY,
   E_CGR_VERSION,
   E_CGR_STORAGE,
   E_CGR_CORRUPTED,
   E_CGR_BUFFER_V4,
   E_CGR_INVALID_ARGS,
   E_CGR_STREAM,
   E_CGR_UNSTREAM,
   E_CGR_CORRUPTED_VERSION,
   E_CGR_UNKNOWN,
   E_CGR_SCALEFACTOR_STANDARD,
   E_CGR_SCALEFACTOR_LARGE,
   E_CGR_SCALEFACTOR_SMALL,
   E_CGR_SCALEFACTOR_UNKNOWN
};

/** @nodoc*/
struct cgrFileStatus{
  int returnCode;
  CAT3DRep* rep;
};

/**
 * Function to save the representation of a graphic scene
 * in a cgr file.
 * <b>Role:</b>This function writes a Cgr file.
 * @return
 *   <dl>
 *      <dt>0</dt>
 *        <dd>OK</dd>
 *      <dt>1</dt>
 *        <dd>KO, because of a disk writting error</dd>
 *      <dt>2</dt>
 *        <dd>KO, because, one of the rep we tried to 
 *        save is not streamable</dd>
 *   </dl>   
 * @param iRep
 *    A pointer to the root node of the 3D scene to save.
 * @param iFileName
 *    The name of the file in which the scene will be saved.
 * @param iSettingCgr
 *    The CATSettingCgr flag to specify the kind of graphic data we want to store in the cgr file.
 * @param iColMap
 *    The color map to use to convert color attribute in RGB composants.
 * @param iFileMarked
 *    do not use.
 *    <br><b>Legal values</b>:
 *    <dl>
 *      <dt>TRUE</dt>
 *        <dd>The cgr file will be readable by only CATIA Demo version</dd>
 *      <dt>FALSE</dt>
 *        <dd>The cgr file will be readable by every CATIA versions</dd>
 *    </dl>
 *    The default value is set to <tt>FALSE</tt>.
 * @param ioMode
 *    Defines the method used for writing the CGR.
 *    The default value is set to <tt>CATVizCGRAccessModeMemory</tt>.
 */
extern ExportedBySGInfra int CATWriteCgr(CATRep *iRep,
                                        char *iFileName,
                                        CATSettingCgr iSetting,
                                        CATColorMap *iColMap,
                                        CATBoolean iFileMarked = FALSE,
                                        CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

/** @nodoc */
extern ExportedBySGInfra int CATWriteCgr(CATRep *iRep,
                                        char *iFileName,
                                        CATSettingCgr iSetting,
                                        CATColorMap *iColMap,
                                        CATCgrHeader &iHeader,
                                        CATBoolean iFileMarked = FALSE,
                                        CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

/** @nodoc */
extern ExportedBySGInfra int CATWriteTargetReleaseCgr(CATRep *iRep,
                                                     char *iFileName,
                                                     CATSettingCgr iSetting,
                                                     CATColorMap *iColMap,
                                                     CATVizTargetCGR target,
                                                     CATBoolean iFileMarked = FALSE,
                                                     CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);
/**
 * Function to save, in the Cgr format, the representation of a graphic scene
 * in a buffer.
 * <b>Role:</b>This function writes a Cgr buffer.
 * @return
 *   <dl>
 *      <dt>0</dt>
 *        <dd>OK</dd>
 *      <dt>-1</dt>
 *        <dd>KO</dd>
 *   </dl>   
 * @param iRep
 *    A pointer to the root node of the 3D scene to save.
 * @param oBuffer
 *    The buffer in which the Cgr data are stored. This buffer is allocated by <tt>CATWriteCgr</tt>,
 *    but its deletion is let to the caller and must be done by using the "free" function.
 * @param oLBuffer
 *    The length of oBuffer.
 * @param iSettingCgr
 *    The CATSettingCgr flag to specify the kind of graphic data you want to store in the cgr file.
 * @param iColMap
 *    The color to use to convert color attribute in RGB composants.
 * @param iFileMarked
 *    do not use.
 *    <br><b>Legal values</b>:
 *    <dl>
 *      <dt>TRUE</dt>
 *        <dd>The cgr file will be readable by only CATIA Demo version</dd>
 *      <dt>FALSE</dt>
 *        <dd>The cgr file will be readable by every CATIA versions</dd>
 *    </dl>
 *    The default value is set to <tt>FALSE</tt>.
 */
extern ExportedBySGInfra int CATWriteCgr(CATRep * iRep,
                                        char*& oBuffer, 
                                        int& oLBuffer,
                                        CATSettingCgr iSettingCgr,
                                        CATColorMap *iColMap,
                                        CATBoolean iFileMarked=FALSE);

/** @nodoc */
extern ExportedBySGInfra int CATWriteCgr(CATRep * iRep,
                                        char*& oBuffer, 
                                        int& oLBuffer,
                                        CATSettingCgr iSettingCgr,
                                        CATColorMap *iColMap,
                                        CATCgrHeader &iHeader,
                                        CATBoolean iFileMarked=FALSE);

/**
 * @nodoc 
 * This method writes a CGR in a storage (for PART)
 */
extern ExportedBySGInfra int CATWriteCgr(CATRep *iRep,
                                        CATStorage *iStorage,
                                        CATSettingCgr iSetting,
                                        CATColorMap *iColMap,
                                        CATBoolean iFileMarked = FALSE,
                                        CATVizCGRAccessMode ioMode = CATVizCGRAccessModeDirect);

/**
 * @nodoc 
 * This method reads a CGR from a CATILockBytes2 (for CATVizCGRDocument)
 */
extern ExportedBySGInfra CAT3DRep * CATReadCgr(CATILockBytes2 *iLB2);

 /**
 * This function reads a Cgr files list and returns their graphic
 * data as an array of pointers to CAT3DRep objects.
 * <b>Role:</b>This function reads a Cgr files list and returns their graphic
 * data as an array of pointers to CAT3DRep objects.
 * @return
 *    This function returns an array of pointers to CAT3DRep. This array
 *    size is equal to the number of Cgr files to read. Each field contains,
 *    as a pointer to a CAT3DRep, the representation of the corresponding Cgr file.
 *    If the CATReadCgr() function encounters a problem during the reading of a Cgr file,
 *    the corresponding field of the returned array is NULL.
 * @param iFileNameList
 *    The list of Cgr files to read.
 * @param iSizeList
 *    The number of Cgr files to read.
 * @param iSettingCgr
 *    do not use. Set this parameter to the <tt>USE_LODS_TEXTURE_EDGE</tt> value.
 */
extern ExportedBySGInfra CAT3DRep ** CATReadCgr(char **iFileNamelist, int iSizeList,CATSettingCgr iSettingCgr);

/** @nodoc */
extern ExportedBySGInfra cgrFileStatus* CATReadCgrWithStatus(char **iFileNamelist,
                                                            int iSizeList,
                                                            CATSettingCgr iSettingCgr,
                                                            CATVizSemanticLevel targetLevel = HIGH,
                                                            CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

/** @nodoc */
extern ExportedBySGInfra CAT3DRep ** CATReadCgr(char **iFileNamelist, int iSizeList,
                                               CATSettingCgr iSettingCgr,
                                               CATCgrHeader **&oFileHeader);

/**
 * This Function is the interface with the Cgr file.
 * <b>Role</b>: Reads a Cgr file and returns its graphic data as a pointer
 * to a CAT3DRep.
 * @return
 *    If everything is OK, the function returns a valid pointer to a CAT3DRep,
 *    else, it returns a NULL pointer.
 * @param iFileName
 *    The cgr file name to read.
 * @param iSettingCgr
 *    do not use. Set this parameter to the <tt>USE_LODS_TEXTURE_EDGE</tt> value.
 * @param ioMode
 *    Defines the method used for writing the CGR.
 *    The default value is set to <tt>CATVizCGRAccessModeMemory</tt>.
 */
extern ExportedBySGInfra CAT3DRep * CATReadCgr(char *iFileName,
                                              CATSettingCgr iSettingCgr,
                                              CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

/** @nodoc */
extern ExportedBySGInfra CAT3DRep * CATReadCgr(char *iFileName,
                                              CATSettingCgr iSettingCgr,
                                              CATVizSemanticLevel targetLevel,
                                              CATCgrHeader **oHeader = NULL,
                                              CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);
/** @nodoc */
extern ExportedBySGInfra cgrFileStatus CATReadCgrWithStatus(char *iFileName,
                                              CATSettingCgr iSettingCgr,
                                              CATVizSemanticLevel targetLevel = HIGH,
                                              CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);
/** @nodoc */
/*oHeader has to be RELEASED by the caller if != NULL*/
extern ExportedBySGInfra CAT3DRep * CATReadCgr(char *iFileName,
                                              CATSettingCgr iSettingCgr,
                                              CATCgrHeader *&oHeader,
                                              CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);
/** @nodoc */
extern ExportedBySGInfra CATCgrHeader * CATReadCgrHeader(char *iFileName,
                                                        CATSettingCgr iSettingCgr,
                                                        CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

 /**
 * This function reads a buffer containing Cgr data and returns this graphic data as a pointer
 * to a CAT3DRep.
 * <b>Role:</b>This function reads a Cgr buffer and returns its graphic
 * data as a pointer to a CAT3DRep object.
 * @return
 *    If everything is OK, the function returns a valid pointer to a CAT3DRep,
 *    else, it returns a NULL pointer.
 * @param iBuffer
 *    The buffer to read.
 * @param iLBuffer
 *    The length, in bytes of <tt>iBuffer</tt>.
 */
extern ExportedBySGInfra CAT3DRep * CATReadCgr(char *iBuffer, int iLBuffer);

/** @nodoc */
/* deprecated */
extern ExportedBySGInfra CAT3DRep * CATReadCgr(char *iBuffer, int iLBuffer, CATCgrHeader * oHeader);

/** @nodoc */
/*oHeader has to be RELEASED by the caller if != NULL*/
extern ExportedBySGInfra CAT3DRep * CATReadCgrWithHeader(char *iBuffer, int iLBuffer, CATCgrHeader * & oHeader);


/** @nodoc */
extern ExportedBySGInfra CATCgrHeader * CATReadCgrHeader(char *iBuffer, int iLBuffer);

/**
 * Function to save the representation of a graphic scene
 * in a cgr file.
 * <b>Role:</b>This function write a Cgr file.
 * @return
 *   <dl>
 *      <dt>0</dt>
 *        <dd>OK</dd>
 *      <dt>-1</dt>
 *        <dd>KO</dd>
 *   </dl>   
 * @param iRep
 *    A pointer to the root node of the 3D scene to save.
 * @param iFileName
 *    The name of the file in which the scene will be saved.
 * @param iCGRSettingCgr
 *    The CATCGRSetting to specify the kind of graphic data we want to store in the cgr file.
 * @param iColMap
 *    The color map to use to convert color attribute in RGB composants.
 * @param iFileMarked
 *    do not use.
 *    <br><b>Legal values</b>:
 *    <dl>
 *      <dt>TRUE</dt>
 *        <dd>The cgr file will be readable by only CATIA Demo version</dd>
 *      <dt>FALSE</dt>
 *        <dd>The cgr file will be readable by every CATIA versions</dd>
 *    </dl>
 *    The default value is set to <tt>FALSE</tt>.
 * @param ioMode
 *    Defines the method used for writing the CGR.
 *    The default value is set to <tt>CATVizCGRAccessModeMemory</tt>.
 */
extern ExportedBySGInfra int CATWriteCgr(CATRep * iRep,
                                        char * iFileName,
                                        CATCGRSetting * iCGRSetting = 0,
                                        CATColorMap * iColMap = 0,
                                        CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

/** @nodoc */
extern ExportedBySGInfra int CATWriteCgr(CATRep * iRep,
                                        char * iFileName,
                                        CATCgrHeader &iHeader,
                                        CATCGRSetting * iCGRSetting = 0,
                                        CATColorMap * iColMap = 0,
                                        CATVizCGRAccessMode ioMode = CATVizCGRAccessModeMemory);

/** @nodoc */
/* deprecated */
extern ExportedBySGInfra int CATReadCgrInfo(char *ifilename,
                                           CATDescribeCgr *& oDescription,
                                           int& oConversion);

/** @nodoc */
extern int CATWriteCgr(CATRep * iRep, 
                       unsigned char marker,
                       CATVizCGRAccessMode ioMode,
                       CATVizTargetCGR target,
                       CATStorage *iStorage = NULL,
                       char * iFilename = NULL, 
                       char** oBuffer = NULL, 
                       int * oLBuffer = NULL, 
                       CATCGRSetting * iCGRSetting = NULL, 
                       CATSettingCgr * iSetting = NULL, 
                       CATColorMap * iColMap = NULL, 
                       CATCgrHeader * iHeader = NULL, 
                       CATBoolean * iFileMarked = NULL);

/** @nodoc */
extern cgrFileStatus  CATReadCgr(CATVizCGRAccessMode ioMode,
                                 CATVizSemanticLevel iTargetLevel,
                                 char * iFileName = NULL, 
                                 char * iBuffer = NULL, 
                                 int iLBuffer = 0, 
                                 CATSettingCgr * iSettingCgr = NULL, 
                                 CATCgrHeader ** oHeader = NULL, 
                                 int headerOnly = 0, 
                                 cgrfile * = NULL, 
                                 CATMutex * lock = NULL,
                                 CATILockBytes2 * iLB2 = NULL);

/** @nodoc */
extern void MultiThreadUnStream(CATCGRContainer * iMainContainer, int iUnstreamSceneGraph = 1);

/** @nodoc
 *  This function check if the CGR file is a V4 or V5 one.
 *  @return
 *   <dl>
 *      <dt>0</dt>
 *        <dd>V4 CGR</dd>
 *      <dt>1</dt>
 *        <dd>V5 CGR</dd>
 *      <dt>-1</dt>
 *        <dd>bad file</dd>
 *   </dl>
 *  @param iFilename
 *     The name of the file to check.
 */
extern ExportedBySGInfra int CATCheckCgrType(const char * iFileName);

/** @nodoc
 *  This function check if the CGR buffer is a V4 or V5 one.
 *  @return
 *   <dl>
 *      <dt>0</dt>
 *        <dd>V4 CGR</dd>
 *      <dt>1</dt>
 *        <dd>V5 CGR</dd>
 *      <dt>-1</dt>
 *        <dd>bad file</dd>
 *   </dl>
 *  @param iBuffer
 *     The buffer to check.  
 *  @param iLBuffer
 *     The length of the buffer to check.
 */
extern ExportedBySGInfra int CATCheckCgrType(char * iBuffer, int iLBuffer);

/** @nodoc
 *  Forces library loading.
 *  @param   iLibraryLevel
 *    The library level.
 *    <br><b>legal values</b>
 *    <ul>
 *         <li>0 V4 library</li>
 *         <li>1 V5 library</li>
 *    </ul>
 */
extern ExportedBySGInfra void CATForceCgrLibraryLoading(int iLibrayLevel);
#endif

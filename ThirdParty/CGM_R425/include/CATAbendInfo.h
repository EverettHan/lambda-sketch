#ifndef CATAbendInfo_H
#define CATAbendInfo_H
// COPYRIGHT DASSAULT SYSTEMES 2000
// ==============================================================
// == CATAbendInfo class                                       ==
// ==============================================================
// == This class is used to set some information for the       ==
// == the catrace flag                                         ==
// ==============================================================
// == Derive the object and surcharge dump method              ==
// == Use static method SetAbendInfo to set the information    ==
// ==                                                          ==
// ==  This class permits to add information into the abend    ==
// ==  trace file                                              ==
// ==  The dump method must be totally safe (static pre-       ==
// ==  generated strings only )                                ==
// ==  This information is addressed to Dassault-Systemes      ==
// ==  maintenance but WILL BE READ BY CUSTOMERS : this is     ==
// ==  not a place where to place joke                         ==
// ==                                                          ==
// ==  USE ONLY ENGLISH SERIOUS MESSAGES                       ==
// ==                                                          ==
// ==  ------------------------------------------------------  ==
// ==                                                          ==
// ==                                                          ==
// ==                                                          ==
// ==                                                          ==
// ==============================================================
#include <stdio.h>
#include "JS0ERROR.h"

// ++vxg - 2010:05:25
# define JS0ERROR_FRAME_INFORMATION_SEP_CHAR                '?'
# define JS0ERROR_FRAME_INFORMATION_SEP_STRG                "?"
// --vxg - 2010:05:25

/*
 * Dialog Engine and application frame informations 
 */
#define CAT_ABEND_FRAME_INFO		0
#define CAT_ABEND_FRAME_EVENT		1
#define CAT_ABEND_FRAME_CMDS		2 
#define CAT_ABEND_FRAME_WKBCH		3 

/*
 * Servers informations
 */
#define CAT_ABEND_SERVER_INFO		5
/*
 * Dialog frameworks informations
 */
#define CAT_ABEND_DIALOG_INFO		6

/*
 * Model organisations informations 
 */
#define CAT_ABEND_MDL_LIFE_CYCLE	7
#define CAT_ABEND_MDL_PRODUCT		8
#define CAT_ABEND_MDL_OTHER		9
#define CAT_ABEND_MDL_CHECKER		10
#define CAT_ABEND_OMB_INFO		3



/*
 * Batch informations
 */
#define CAT_ABEND_BATCH_INFO		11

/*
 * Visual informations
 */
#define CAT_ABEND_VISU_WARNING		12
#define CAT_ABEND_VISU_DECODE		13
#define CAT_ABEND_VISU_HARDWARE		16

/*
 * File/Save/Open commands informations
 */
#define CAT_ABEND_FILE_CMDS		14 
#define CAT_ABEND_DIALOG_ENGINE		15


/* COMMANDS */
#define CAT_ABEND_COMMANDS_INFO		17

/* CATBaseUnknown */
#define CAT_ABEND_BASEUNKN_INFO		18
#define CAT_ABEND_BASEUNKNQI_INFO	30

/* MARSHALLING */
#define CAT_ABEND_MARSHALL_INFO		19

/* ERRORS   */
#define CAT_ABEND_ERRORS_INFO		20

/* COLLECTIONS */
#define CAT_ABEND_SETTNG_INFO		23

/* COLLECTIONS */
#define CAT_ABEND_COLLEC_INFO		24
/** LICENSING */
 
#define CAT_ABEND_LIC_INFO		26

/*  30-31 already given  */

/* PRINT / MULTIMEDIA  */
#define  CAT_ABEND_MMEDIA_INFO		40
#define  CAT_ABEND_PRINT_INFO		41

/** COLLAB **/
#define  CAT_ABEND_COLLAB_INFO		43
/** AUTOMATION  **/
#define  CAT_ABEND_SCRIPT_INFO		44
#define  CAT_ABEND_VSTA_INFO		31


#define  CAT_ABEND_CALLBACK_INFO	45
#define  CAT_ABEND_CMDBAD_INFO		46
/**
 * Part  informations
 */
#define CAT_ABEND_PART_INFO		128
/**
 * Drafting informations
 */
#define CAT_ABEND_DRAFTING_INFO		129

/**
 * Web Viewer
 */
#define CAT_ABEND_WEBVIEWER_INFO	133

/**
 * Interop VPM 
 */
#define CAT_ABEND_SIDLTUBE_INFO		139
#define CAT_ABEND_INTEROPVPM_INFO	140
/**
 * Single IDL
 */
#define CAT_ABEND_SINGLEIDL_INFO	141
#define CAT_ABEND_PLMEV5_INFO		142

/**
 * Windows VID
 */
#define CAT_ABEND_VID_INFO  150


//---------------------------------------------------
// Info Rules Flags
//---------------------------------------------------

// add the current context to the information
#define CATInfoRules_AddContext      0x0001


// add the current stacktrace
// should be used only exceptionnally and only for very i
// serious error detection
// VERY expansive in performance and memory and I/O 

#define CATInfoRules_AllwaysAddStack 0x0002


// infinite info buffer
//should be used only exceptionnally and only for errors
// must be used in conjonction with CATInfoNb_InfiniteBuffer
// Disk IO generated

#define CATInfoRules_InfiniteBuffer  0x0004

// should be used only exceptionnally 
// VERY Exceptionnally, you may try to put a content
// dangerous to dump. In this case YOU MUST SET the flag 
// CATInfoRules_DumpMayCore   
#define CATInfoNb_DumpMayCore        -1


//---------------------------------------------------
// info number flag
//---------------------------------------------------
// infinite info buffer
// should be used only exceptionnally and only for errors
// Disk IO generated
// must be used in conjonction with CATInfoRules_InfiniteBuffer

#define CATInfoNb_InfiniteInfo   -1


//---------------------------------------------------
class ExportedByJS0ERROR  CATAbendInfo
{
  public:
  CATAbendInfo(short int iTypeInfo=CAT_ABEND_FRAME_INFO);
  virtual ~CATAbendInfo();
  virtual char * Dump();
  static void SetAbendInfo(CATAbendInfo *);  
  static CATAbendInfo *GetAbendInfo(short int iTypeInfo=CAT_ABEND_FRAME_INFO);
  static void SetInformationSpecs(short int iTypeInfo, const char *iInfoTitle, int iNbInfosToKeep, int iInfoRules  ); 
  static FILE *GetAbendFileStream(); 
  private :
  short int od_Type;
};

#endif

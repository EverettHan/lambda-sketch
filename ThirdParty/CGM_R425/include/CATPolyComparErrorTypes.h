#ifndef __CATPolyComparERRORTYPES
#define __CATPolyComparERRORTYPES
//====================================================================
// Copyright Dassault Systemes Provence 2010, All Rights Reserved 
//====================================================================

// CATPolyComparERRORTYPES
// Header definition of class CATPolyComparERRORTYPES
//===================================================================
//
// Usage notes: Tous les erreurs sont typees et numerotees ici
//
//===================================================================
// 28.10.2019 : RAQ : Touch fichier pour forcer la recompilation
// 13.04.2018 : RAQ : Correction du build de Delmia en ajoutant temporairement les macros CHECK_*
// 04/11/2013 : RNO : La Macro CATPolyComparOCLErrorMacro imprime la last error
//  04/11/2010  RNO : Ajout POLYCOMPAR_INITBLOCK_EXCEEDMAXNBWORKITEM
//  XX/09/2010  NUA : Creation 
//===================================================================
#include "CATCGMOutput.h"
#include "CATCGMOutputColor.h"

// JE DESACTIVE CAR CA FAIT DES DOUBLES SYMBOLS [5/16/2018 RNO]
////------- TEMPORAIRE : Modif RAQ du 13.04.2018 pour corriger pb de build chez Delmia -----//
//#ifndef CHECK_TRUE_RET
//  #define CHECK_TRUE_RET(iBoolean) { if(!iBoolean) return ; }
//#endif  //!CHECK_TRUE_RET
//
//#ifndef CHECK_HANDLER_RET
//  #define CHECK_HANDLER_RET(iHandler) { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) return; }
//#endif  //!CHECK_HANDLER_RET    
////----------------------------------------------------------------------------------------//
//


#define CATPolyComparErrorMSGMacro(MYMSG)\
	{cgmout<<cgmout_red<<"[E] " <<MYMSG<<" ( Error happened in function "<<__FUNCTION__<<" / Source : "<<__FILE__<<" / Line : "<<__LINE__<<")\n"; cgmout<<cgmout_std;}

#define CATPolyComparWarningMSGMacro(MYMSG)\
	{cgmout<<cgmout_yellow<<"[w] "; cgmout<<cgmout_std<<MYMSG<<" ( Warning In function "<<__FUNCTION__<<" / Source : "<<__FILE__<<" / Line : "<<__LINE__<<")\n";}

#define CATPolyComparInfoMSGMacro(MYMSG)\
	{cgmout<<cgmout_pink<<"[i] "; cgmout<<cgmout_std<<MYMSG<<"\n";}


#define CATPolyComparCHECKNULLPOINTER(A){ if(!(A)) { CATPolyComparErrorMSGMacro("Error Null Pointer : ("<<#A<<")"); return(POLYCOMPAR_NULL_POINTER_ERROR);}}
#define CATPolyComparCHECKNULLVISHANDLE(A) { if((A==NullHandle)) { CATPolyComparErrorMSGMacro("Null Handle : ("<<#A<<") !"); return(POLYCOMPAR_NULL_POINTER_ERROR);}}
#define CATPolyComparCHECK_HRESULTANDRETURNCODE(HR,CODETORETURN){if(!SUCCEEDED(HR)){ CATPolyComparErrorMSGMacro("HResult!=SUCCEEDED"); return CODETORETURN;}}






#ifndef PutMessageEveryWhere
//MACRO FOR DUMPING IN ALL KNOWN CONSOLE (Use it Parsimoniously!!)
#define PutMessageEveryWhere(MSG) \
{ if(cgmstatus) cgmstatus<<MSG<<cgmendl;\
  if(cgmout) cgmout<<MSG<<cgmendl;\
}
#endif
#define MRSDUMPERR(MSG)\
{ if(cgmstatus) cgmstatus<<MSG<<cgmendl;\
  if(cgmout) cgmout<<MSG<<cgmendl;\
  if(cgmerr) cgmerr<<MSG<<cgmendl;}
enum CATPolyComparErrorTypes
{
  POLYCOMPAR_OK = 0,
  //VERY GENERIC ERROR
  POLYCOMPAR_NULL_POINTER_ERROR,
  POLYCOMPAR_NOT_IMPLEMENTED,
  POLYCOMPAR_NO_ENOUGH_MEM_ERROR,
  POLYCOMPAR_INTERNAL_ERROR,//GENERIC ERROR 
 
  POLYCOMPAR_NULL_DENOM_ERROR,
  
  //
  POLYCOMPAR_SWEEP_ERROR,
  POLYCOMPAR_UNSUPPORTED_TRAJECTORY_TYPE,
  POLYCOMPAR_INVALID_ARGUMENT_ERROR,
  POLYCOMPAR_STOCK_INVALID,
  POLYCOMPAR_INVALID_SCENARIO_ELEM,
  POLYCOMPAR_INVALID_INTERNALARG,
  POLYCOMPAR_INVALID_SCENARIO,

  POLYCOMPAR_EMPTY_LIST,
  POLYCOMPAR_CRITICAL_INIT_ERROR,
  POLYCOMPAR_INVALID_INDEX,
  POLYCOMPAR_INCOMPATIBLE_OPTIONS,


  POLYCOMPAR_POLYHEDRAL_TOOMUCHTRIANGLES,
  //STREAM/UNSTREAM SPECIFIC
  POLYCOMPAR_STREAM_ERROR,
  POLYCOMPAR_STREAM_ERROR_VERSION,
  POLYCOMPAR_STREAM_ERROR_INCOHERENCE,

  POLYCOMPAR_INVALID_SIZE,


  POLYCOMPAR_COMPUTEBOXES_ERROR,
  POLYCOMPAR_MEMORY_MANAGER_LOAD_ERROR,
  POLYCOMPAR_BAD_VBO_ID,
  //POLYCOMPAR_INVALID_OPENGL_VIEWER,
  POLYCOMPAR_ERROR_IN_TRIANGULATION,
  POLYCOMPAR_DEPRECATED_METHOD,
  //POLYCOMPAR_BLOCKSGIVENSIZE_ERROR,
  POLYCOMPAR_SUBMIT_JOB_ERROR,
  POLYCOMPAR_INVALID_TOOLPART,
  POLYCOMPAR_INVALID_INPUT_TOLERANCE,
  POLYCOMPAR_TRANSFERT_ERROR,
  POLYCOMPAR_MEMORY_MANAGER_NO_FREE_SLOTS,
  POLYCOMPAR_INVALID_PSO_ID,
  POLYCOMPAR_UNSUPPORTED_ANALYTICAL_TOOL,
  POLYCOMPAR_CREATE_EVENT,
  POLYCOMPAR_STOCKOPERATOR_FAILED,
  POLYCOMPAR_SWAP_FILE_ERROR,
  POLYCOMPAR_POLYHEDRALOPE_ERROR,
  POLYCOMPAR_INVALID_DEVICE,
  POLYCOMPAR_DSYSYSJOBSCHEDULER_ERROR,
  POLYCOMPAR_INVALID_TOOL,
  POLYCOMPAR_INVALID_TRAJECTORY,
  POLYCOMPAR_INVALID_TOOLTRAJCOMBINATION,
  POLYCOMPAR_INVALID_MOTION_MODE,
  POLYCOMPAR_COMPARE_ERROR,
  POLYCOMPAR_INVALID_BSP_POINT,
  POLYCOMPAR_INVALID_BSP_POLYGON,
  POLYCOMPAR_INVALID_MESH,
  POLYCOMPAR_ELEMENT_NOT_FOUND,

  //STOCK_INCOMPATIBLE_MONO_ERROR,

  POLYCOMPAR_UNKNOWN_ERROR,

  POLYCOMPAR_SPLITPOLYHEDRON_FLATPOLYHEDRON,
  POLYCOMPAR_SPLITPOLYHEDRON_UNCHAINABLEEDGE,

  //POUR LES SUPPORTS
  POLYCOMPAR_ERR_SUPPORT_BOTTOM_ANCHOR_TOO_LONG,
  POLYCOMPAR_ERR_SUPPORT_TOP_ANCHOR_TOO_LONG,
  POLYCOMPAR_ERR_SUPPORT_MARGINS_TOO_BIG,
  POLYCOMPAR_ERR_SUPPORT_HEIGHT_TOO_SMALL,
  POLYCOMPAR_ERR_SUPPORT_FACEWIDTH_TOO_SMALL,
  POLYCOMPAR_ERR_SUPPORT_TOPANDBOTTOM_NBPOINTS_DIFFERENT,
  POLYCOMPAR_ERR_SUPPORT_FACE_TWISTED,

  //Pour les diags d'ODT
  POLYCOMPAR_CHECK_OPERATOR_ERROR
};

//INLINE HRESULT MRSERR2HR(const CATPolyComparErrorTypes & ierr)
//{
//  if (ierr == POLYCOMPAR_OK)
//    return S_OK;
//  else
//    return E_FAIL;
//}



//OBSOLETE PRAGMA 
#define CATPolyComparErrorMacroAndReturn(MSG,CODE){  CATPolyComparErrorMSGMacro(MSG); return;}
//OBSOLETE PRAGMA 
#define CATPolyComparErrorMacroAndReturnCode(MSG,CODE){  CATPolyComparErrorMSGMacro(MSG); return CODE;}
//OBSOLETE PRAGMA
#define CATPolyComparErrorMacro(MSG,CODE) CATPolyComparErrorMSGMacro(MSG)
#endif

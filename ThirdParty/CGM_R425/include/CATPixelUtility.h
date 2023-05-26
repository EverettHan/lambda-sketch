/*
 * @quickreview TPG/HQ4 22:07:21 CATPixelImage unstream thread safety for LDH
 */
#ifndef CATPixelUtility_H
#define CATPixelUtility_H
//#include "CATViz.h"
#include "CATMMediaPixelImage.h"
#include "CATUnicodeString.h"

  // struct to activate protections for multimedia thread safety in multithreaded context
  struct ExportedByCATMMediaPixelImage MM_Mutex {static int activated;};
  enum MMMutexVersion{ MMMV_no, MMMV_PIUnstream, MMMV_LowSpreadV1, MMMV_LowSpreadV2};

/*
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// Abstract: Get the Complete PATH for a given Image File 
//           
//------------------------------------------------------------------------------
// Usage:    Use  CATGetImagePathName    to get a Path of an Image 
//           Use  CATGetPathNameFromEnv  to get a Path using a Path Concatenation 
// stored in a given environment variable 
//    
//------------------------------------------------------------------------------
*/        

//#ifdef __cplusplus
//extern "C" {
//#endif

  ExportedByCATMMediaPixelImage char * CATGetPathNameFromEnv( const char * env, const char * filename );
  ExportedByCATMMediaPixelImage char * CATGetImagePathName( const char * filename );
  ExportedByCATMMediaPixelImage CATUnicodeString CATGetPathNameFromEnvEx(const char* env, CATUnicodeString filename);
  ExportedByCATMMediaPixelImage CATUnicodeString CATGetImagePathNameEx(CATUnicodeString filename);

  ExportedByCATMMediaPixelImage CATUnicodeString  GetFileExtension(const  CATUnicodeString&  iFilename) ;

  // return :
  // -1 : not an image
  //  0 : unknown
  // >0 : DS Supported
  //      rgb     = 100 
  //      picture = 101
  //      sgi     = 100
  ExportedByCATMMediaPixelImage int FilterBitmapExtension(const CATString& iPathName);

  enum CATGDIPlus_RM {
      CATGDIPlus_RM_Unitialised,
      CATGDIPlusOn_RMOff,
      CATGDIPlusOff_RMOn // default
  };

  ExportedByCATMMediaPixelImage CATGDIPlus_RM CATGDIPlus_RM_Activation() ;

  ExportedByCATMMediaPixelImage void CATGDIPlus_RM_SetActivation(CATGDIPlus_RM) ;

  ExportedByCATMMediaPixelImage int UseNewImageAPI(); // to be removed

  // AZX, For private use only... used to debug in/out parameters of various image functions (used in MultimediaPixelImage and MultimediaRasterFormats_SB)
//#define TRACE_IMG_CALLS // <---- uncomment this and recompile to activate trace (don't forget to comment before promotion)

/**
 * @ingroup groupMMediaDebug
 * @defgroup groupPixelImageTraces CATPixelImage Traces compile condition.
 * @brief CATPixelImage traces activable by defining "TRACE_IMG_CALLS" in @ref CATPixelUtility.h and re-compiling MultimediaPixelImage.
 */
 /**
 * @ingroup groupPixelImageTraces 
 * @def TRACE_IMG_FUN
 * @brief Dump functions for MultimediaPixelImage.
 **/
/**
 * @ingroup groupPixelImageTraces 
 * @def TRACE_IMG_RC  
 * @brief Dump return codes for MultimediaPixelImage.
 **/
/**
 * @ingroup groupPixelImageTraces 
 * @def TRACE_IMG_IN
 * @brief Dump IN for MultimediaPixelImage.
 **/
/**
 * @ingroup groupPixelImageTraces 
 * @def TRACE_IMG_OUT
 * @brief Dump OUT for MultimediaPixelImage.
 **/
/**
 * @ingroup groupPixelImageTraces 
 * @def TRACE_IMG_IMG
 * @brief Dump image for MultimediaPixelImage.
 **/
#ifdef TRACE_IMG_CALLS
#include <iostream>
#define TRACE_IMG_FUN(fun)     std::cout << "[UseNewImageAPI]" << fun << endl;                                                                                        /*TracesMultimediaTeam*/
#define TRACE_IMG_RC(fun,rc)   std::cout << "[UseNewImageAPI]" << fun << rc<<endl;                                                                                    /*TracesMultimediaTeam*/
#define TRACE_IMG_IN(in)       std::cout << "[UseNewImageAPI]\tin: " << in << endl;                                                                                   /*TracesMultimediaTeam*/
#define TRACE_IMG_OUT(out)     std::cout << "[UseNewImageAPI]\tout: " << out << endl;                                                                                 /*TracesMultimediaTeam*/
#define TRACE_IMG_IMG(opImage) std::cout << "[UseNewImageAPI]\tImage(";                                                                                               /*TracesMultimediaTeam*/ \
    if(opImage) \
    { \
      int oXSize, oYSize;  opImage->GetSize(oXSize, oYSize); \
      std::cout << oXSize<< ", " << oYSize << opImage->GetFormat() << ", " << opImage->GetXPixelSize() << ", " << opImage->GetYPixelSize() << ")" << endl; \
    } \
    else std::cout << "NULL)" << endl;
#else
#define TRACE_IMG_FUN(fun)
#define TRACE_IMG_RC(fun,rc)  
#define TRACE_IMG_IN(in)  
#define TRACE_IMG_OUT(out)
#define TRACE_IMG_IMG(opImage)
#endif


//#ifdef __cplusplus
//}
//#endif

#endif


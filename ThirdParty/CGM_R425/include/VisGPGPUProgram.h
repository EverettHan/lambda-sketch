#ifndef VISGPGPUPROGRAM_H_
#define VISGPGPUPROGRAM_H_


#ifdef throw
#undef throw
#define RESTORE_THROW
#endif /* throw */

#pragma warning( disable : 4530 )

#include <string>
#include <fstream>

#ifdef RESTORE_THROW
#undef RESTORE_THROW
#define throw ERROR
#endif /* RESTORE_THROW */


#include "CATVisFoundation.h"

#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include <string>

#include "CATListOfCATUnicodeString.h"
#include "CATListPV.h"
#include "CATListOfCATString.h"
#include "CATListOfInt.h"

#include "CATSYPCheck.h"

class CATString;

/** You must NOT directly inherit from this class ! 
 Use VisOpenCL or VisCUDAProgram (in the futur) instead !
 */
class ExportedByCATVisFoundation VisGPGPUProgram : public CATBaseUnknown
{
  CATDeclareClass;

  //Test unit class
  friend class VisGenericProgramTstClass;
  friend class VisGPGPUProgramTstClass;
  friend class VisGPGPUFactory;

public :
  
  VisGPGPUProgram(HRESULT & oError);

  virtual ~VisGPGPUProgram();

   /** This method will be overloaded by the application.
   @param iGPGPUProgramArgument The argument are a structure defined by the application.
   */
  virtual HRESULT Compute(void * iGPGPUProgramArgument) = 0;

  //CATListOf--ModuleInputType * --
   /** This Method is used to add a program (.cu or .cl files)
   @param iKernelList This is a list of ModuleInputType * which represent the kernel. This can be a file
                      or a a string. (You can mix file and str)
                      In case of a file : We will open the file with the path given. If not found, we will see
                      in CATGraphicPath that corresponds to OS/resources/graphics
   @param iCompilingOption This is the compilation options that will be given.
   @param oCompilationErrorList This output will contain the compilation errors
   @return S_OK or E_FAIL
   */
  HRESULT AddProgram(const CATListPV & iKernelList, const CATString & iCompilingOption, 
                     CATListOfCATUnicodeString & oCompilationErrorList);

   /** User must not call these methods. This is for Visualization team only
       These methods set the informations that will be usefull for interoperability
   */
  inline void SetVBOList(CATListPV * iListVBO);
  inline void SetIBOList(CATListOfInt * iListIBO);
  inline void SetTextureList(CATListPV * iListTexture);

public :

  enum typeOfInput
  {
    isACHAR,
    isAFILE
  };

  struct moduleInputType
  {
    moduleInputType() : _kernelType(OpenCL) {}
    CATUnicodeString             _str;	      ///< The file name if _type is isAFILE, else the kernel string
    typeOfInput                  _type;	      ///< The type of the input
    enum {Cuda, OpenCL, Generic, Compute} _kernelType; ///< Specify if the kernel must be used for OpenCL, Cuda, or compute shader
  };

protected :

   /** For options see AddProgram */
  virtual HRESULT Compile(const CATListPV & iKernelList, const CATString & iCompilingOptions, 
                          CATListOfCATUnicodeString & oCompilationErrorList) = 0;

  /** This method create the .clbin file : flush the binary file into the disk.
   * This is based on the hash function of CATUnicodeString to store an unique ID and retreive the right kernel
   * @param iKernelList This is a list of ModuleInputType * which represent the kernel.
   * @param iCompilingOptions The list of Options.
   */
  virtual HRESULT CreateBinaries(const CATListPV & iKernelList, const CATString & iCompilingOptions) const
  { return S_OK; }

  /** This method load the binaries that are on the disk 
   *  This is based on the hash function of CATUnicodeString to store an unique ID and retreive the right kernel
   * @return E_FAIL in case of error, S_FALSE if the file was not present on disk but no error occured, S_OK, il all goes well 
   */
  virtual HRESULT LoadBinaries(const CATListPV & iKernelList, const CATString & iCompilingOptions,
                               CATListOfCATUnicodeString & oCompilationErrorList)
  { return S_OK; }

  /** This method is for ODT purpose. To test the kernel compilation we force the caching disabling. 
   *  The environment variable is VIS_GPGPU_DISABLE_CACHING.
   *  @return true if the caching is enabled else false.
   */
  bool IsCachingEnabled();

  static VisGPGPUProgram::moduleInputType* ConvFctModule(void * iElem);

  static std::string ConvFctUnicodeToString(const CATUnicodeString & iElem);

  static CATUnicodeString ConvFctStringToUnicode(const std::string & iElem);

  
protected :

  //Don't free ptr on list !
  //Life cycle of lists is handle by VisGPGPUPrimitive not The program !
  CATListPV *	   _vboIDs;     ///< List of VisGPGPUVboInformation *
  CATListOfInt * _iboIDs;
  CATListPV *    _textureIDs; ///< List of VisGPGPUTextureInformation * 

private :

#ifdef _WINDOWS_SOURCE
  static HANDLE s_interProcessMutex;
#endif //_WINDOWS_SOURCE
  static unsigned int s_enableCaching;
};

inline void VisGPGPUProgram::SetVBOList(CATListPV * iListVBO)
{
  _vboIDs = iListVBO;
}

inline void VisGPGPUProgram::SetIBOList(CATListOfInt * iListIBO)
{
  _iboIDs = iListIBO;
}

inline void VisGPGPUProgram::SetTextureList(CATListPV * iListTexture)
{
  _textureIDs = iListTexture;
}

#endif //VISGPGPUPROGRAM_H_

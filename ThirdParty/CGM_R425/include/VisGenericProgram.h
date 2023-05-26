#ifndef VISGENERICPROGRAM_H_
#define VISGENERICPROGRAM_H_

#include "CATVisFoundation.h"

#include "VisGPGPUProgram.h"
#include "VisGPGPUEncapsulation.h"

class VisGPGPUManager;
class VisGPGPUProgramInitializer;
class VisGPGPUProgramInternalInterfaces;

class ExportedByCATVisFoundation VisGenericProgram : public VisGPGPUProgram
{
  CATDeclareClass;

protected :

  VisGenericProgram(VisGPGPUProgramInitializer * iInitialier, HRESULT & oError);

  virtual ~VisGenericProgram();

private :

  /** For options see AddProgram */
  virtual HRESULT Compile(const CATListPV & iKernelList, const CATString & iCompilingOptions, 
                          CATListOfCATUnicodeString & oCompilationErrorList);

  /** This method create the .clbin file : flush the binary file into the disk.
   * This is based on the hash function of CATUnicodeString to store an unique ID and retreive the right kernel
   * @param iKernelList This is a list of ModuleInputType * which represent the kernel.
   * @param iCompilingOptions The list of Options.
   */
  virtual HRESULT CreateBinaries(const CATListPV & iKernelList, const CATString & iCompilingOptions) const;

  /** This method load the binaries that are on the disk 
   *  This is based on the hash function of CATUnicodeString to store an unique ID and retreive the right kernel
   * @return E_FAIL in case of error, S_FALSE if the file was not present on disk but no error occured, S_OK, il all goes well 
   */
  virtual HRESULT LoadBinaries(const CATListPV & iKernelList, const CATString & iCompilingOptions,
                               CATListOfCATUnicodeString & oCompilationErrorList);

protected :

  VisGPGPUProgramInitializer * _initializer;
  VisProgramHandle *           _listOfPrograms;
  unsigned int                 _nbPrograms;
};


#endif //VISGENERICPROGRAM_H_

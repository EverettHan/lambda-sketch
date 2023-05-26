#ifndef IVISSGGPGPUPRIMITIVE_H_
#define IVISSGGPGPUPRIMITIVE_H_

#include "IVisSGCustomPrimitive.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSGGPGPUPrimitive;

struct VisGPGPUProgramArgument;
class VisGPGPUProgram;

class ExportedByVisSceneGraph IVisSGGPGPUPrimitive : public IVisSGCustomPrimitive
{
public : 

  enum VisGPGPUProgramType
  {
    OpenCL,
    Cuda,
    Generic,
    Compute
  };

  /** This method attach a program to the Primitive
  *  You must attach the following couple : GenericProgram or OpenCL/Cuda or OpenCL/Generic or Cuda/Generic.
  *  If not, an error will be raised in the compute method.
  *  @param iGPGPUProgram The Program that you want to attach.
  *  @return S_OK or E_FAIL
  */
  virtual HRESULT SetVisGPGPUProgram(VisGPGPUProgram * iGPGPUProgram) = 0;

  /** This method detach a VisGPGPUProgram from the primitive.
  *  @deprecated Use DetachVisGPGPUProgram with the enum 
  *  @param i The program to detach : 0 = OpenCL, 1 = Cuda, 2 = Generic, 3 = Compute
  *  @return S_OK or E_FAIL
  */
  virtual HRESULT DetachVisGPGPUProgram(const unsigned int i) = 0;

    /** This method detach a VisGPGPUProgram from the primitive.
  *  @param i The program to detach.
  *  @return S_OK or E_FAIL
  */
  virtual HRESULT DetachVisGPGPUProgram(const VisGPGPUProgramType & iType) = 0;

  /** Enable the computation. By default, the computation is turned to 0. So the compute will not be done.
  Turn it to true to enable compute
  @param iComputableState true to enable compute, else false
  */
  virtual void EnableComputation(bool iComputableState) = 0;

  /** The the argument that will be passed to the program for the compute.
  The argument is a structure defined by the user. User must handle lifecycle of his argument !
  -----> Warning LEAK is possible ! The User must get the current attrib, free it before a set ! <----
  @param iProgramArgument the argument.
  */
  virtual void SetProgramArgument(void * iProgramArgument) = 0;

  /** Get the current argument. Usefull to avoid free as explain for SetProgramArgument
  @return the argument
  */
  virtual void * getProgramArgument() const = 0;
};

#endif /* IVISSGGPGPUPRIMITIVE_H_ */

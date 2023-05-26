#ifndef VISCOMPUTEPROGRAM_H_
#define VISCOMPUTEPROGRAM_H_

#include "CATVisFoundation.h"
#include <vector>
#include "VisGPGPUProgram.h"
#include "VisGPGPUEncapsulation.h"

class CATGraphicMaterial;
class VisGPGPUManager;
class VisGPGPUProgramInitializer;
class VisGPGPUProgramInternalInterfaces;
class IVisTexture;
class vDSFXEffect;




// mapping with renderEngine structs
struct ComputeMemoryBarrier
{
	enum Type
	{
		fVertexAttrib       = 1 << 0x0,
		fElementArray       = 1 << 0x1,
		fUniform            = 1 << 0x2,
		fTextureFetch       = 1 << 0x3,
		fShaderImageAccess  = 1 << 0x4,
		fCommand            = 1 << 0x5,
		fPixelBuffer        = 1 << 0x6,
		fTextureUpdate      = 1 << 0x7,
		fBufferUpdate       = 1 << 0x8,
		fFramebuffer        = 1 << 0x9,
		fTransformFeedback  = 1 << 0xa,
		fQuery              = 1 << 0xb,
		fAtomicCounter      = 1 << 0xc,
		fUnorderedBuffer    = 1 << 0xd
  };
};

struct ComputeBufferUsage
{
	enum Type
	{
		Static, // Immutable, set by CPU at creation and cannot change afterward
		Dynamic, // Frequently updated by the CPU
		Stream, // Infrequently changed by CPU, can be changed by GPU
		Copy // Used to transfer from GPU to CPU
	};
};

struct ComputeMapFlags
{
	enum Type
	{
		Read,
		Write,
		ReadWrite
	};
};


class ExportedByCATVisFoundation VisComputeProgram : public VisGPGPUProgram
{
	CATDeclareClass;

struct ComputeKernel
{
	VisProgramHandle _effect;
	bool		  _enabled;
	//vRstDraw::handle _dispatchAction;
	ComputeKernel()
	{
		_effect = -1;
		_enabled = true;
	};
};
protected :

	
	VisComputeProgram(HRESULT & oError);
	virtual ~VisComputeProgram();

public:
	
	
	inline void SetExecuteContext(VisComputeContext iComputeContext)
	{
		_computeContext = iComputeContext;
	}

  // = NULL car public !!!!
  void Prepare(void * iPrepareContext, void * iShaderOptions);

  virtual void PrepareParameters() {}

private :

	// creation du vDSFXEffect
	virtual HRESULT Compile(const CATListPV & iKernelList, const CATString & iCompilingOptions, 
		CATListOfCATUnicodeString & oCompilationErrorList);


	virtual HRESULT CreateBinaries(const CATListPV & iKernelList, const CATString & iCompilingOptions) const;

	virtual HRESULT LoadBinaries(const CATListPV & iKernelList, const CATString & iCompilingOptions,
		CATListOfCATUnicodeString & oCompilationErrorList);


	
protected:

	std::vector<ComputeKernel> _programs;
	VisComputeContext					 _computeContext;
  VisPrepareContext					 _prepareContext;
  
};


#endif //VISCOMPUTEPROGRAM_H_

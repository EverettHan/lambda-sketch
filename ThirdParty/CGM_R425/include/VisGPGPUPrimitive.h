#ifndef VISGPGPUPRIMITIVE_H_
#define VISGPGPUPRIMITIVE_H_

#include "SGInfra.h"

#include "VisPrimitive.h"
#include "VisVertexComponent.h"

#include "CATSGSYPCheck.h"
#include "CATSYPCheck.h"

#include "CATListPV.h"
#include "CATListOfInt.h"

#include "VisGPGPUVboInformation.h"
#include "VisGPGPUTextureInformation.h"
#include "IVisSGGPGPUPrimitive.h"

class VisGPGPUPrimitiveIVisSGGPGPUPrimitiveBOAImpl;

class VisGPGPUProgram;
class VisComputeProgram;

class CATRender;

class ExportedBySGInfra VisGPGPUPrimitive : public VisPrimitive
{
  friend class CATCacheOfDestroyedElements;
  friend class vVolRender;
  friend class SGInfraToVisuFConnectToolImpl;
public :

  CATVisDeclarePublicInterfaceAdhesion(VisGPGPUPrimitive, IVisSGGPGPUPrimitive, VisGPGPUPrimitiveIVisSGGPGPUPrimitiveBOAImpl);

  //++ Implementation of IVisSGGPGPUPrimitive

   /** This method attach a program to the Primitive
    *  You must attach the following couple : GenericProgram or OpenCL/Cuda or OpenCL/Generic or Cuda/Generic.
    *  If not, an error will be raised in the compute method.
    *  @param iGPGPUProgram The Program that you want to attach.
    *  @return S_OK or E_FAIL
   */
  HRESULT SetVisGPGPUProgram(VisGPGPUProgram * iGPGPUProgram);

  /** This method detach a VisGPGPUProgram from the primitive.
  *  @deprecated Use DetachVisGPGPUProgram with the enum 
  *  @param i The program to detach : 0 = OpenCL, 1 = Cuda, 2 = Generic, 3 = Compute
  *  @return S_OK or E_FAIL
  */
  HRESULT DetachVisGPGPUProgram(const unsigned int i);

    /** This method detach a VisGPGPUProgram from the primitive.
  *  @param i The program to detach
  *  @return S_OK or E_FAIL
  */
  HRESULT DetachVisGPGPUProgram(const IVisSGGPGPUPrimitive::VisGPGPUProgramType & iType);

   /** Enable the computation. By default, the computation is turned to 0. So the compute will not be done.
   Turn it to true to enable compute
   @param iComputableState true to enable compute, else false
   */
   void EnableComputation(bool iComputableState);


   /** The the argument that will be passed to the program for the compute.
   The argument is a structure defined by the user. User must handle lifecycle of his argument !
   -----> Warning LEAK is possible ! The User must get the current attrib, free it before a set ! <----
   @param iProgramArgument the argument.
   */
  inline void SetProgramArgument(void * iProgramArgument);

  inline void SetExecuteContext(void * iExeCtx);

   /** Get the current argument. Usefull to avoid free as explain for SetProgramArgument
   @return the argument
   */
  inline void * getProgramArgument() const;
  //-- Implementation of IVisSGGPGPUPrimitive


  VisGPGPUPrimitive();

   HRESULT Compute();

   void Prepare(void * iPrepareContext, void*iShaderOptions);

  virtual void Draw(CATRender &iRender);
  virtual void AddToGPGPU(CATRender &iRender);

  virtual VizGeomType GetGeomType() const override;

   /** Say if the Primitive must be computed at this frame
   @return true if the compute must be done, else false 
   */
  inline bool IsComputable() const;

   /** Set The OpenGL ID of the VBO. But we can have several component (@see VisVerticesDescription)
   @param iVboID The OpenGL ID
   @param The Component. This is usefull to identify which VBO corresponds to each component.
   @param For the application to identify the right data more easily. Correspond to the rawBuffer ID.
   */
  inline HRESULT SetVBOID(const unsigned int & iVboID, const VisVertexComponent & iComponentType, 
                  const unsigned int & iRawBufferID);

   /** Set The OpenGL ID of the IBO 
   @param iIboID The OpenGL ID
   */
  inline HRESULT SetIBOID(const unsigned int & iIboID);

  inline HRESULT SetTextureID(const unsigned int & iTextureID, const unsigned int & iTextureType); 
 
   /** Say if the Interoperability has been set. That concern if the VBO, IBO and Textures IDs has been set. In the DrawRender
   @return true if vbo has been set, else false
   */
  inline bool IsInteropInitialized() const;

   /* Set The interoperablity to done */
  inline void SetInteropInitalized();

protected :

  virtual ~VisGPGPUPrimitive();

protected :

  VisGPGPUProgram * _openclProgram;
  VisGPGPUProgram * _cudaProgram;
  VisGPGPUProgram * _genericProgram;
  VisGPGPUProgram * _computeProgram;

  void *            _programArgument;
  void *			_executeCtx;

  unsigned int _isComputable : 1;
  unsigned int _interopInitialized : 1;


  //We store that info because before each Compute(), we must set VBO/IBO/Texture
  //and  because 1 Program can be attached to several GPGPUPrimitive
  //Retrieve all that info at each frame cost a lot ! So we save it
  CATListPV	 _vboIDs; //VisGPGPUVboInformation *
  CATListOfInt _iboIDs;
  CATListPV    _textureIDs; //VisGPGPUTextureInformation *
};

inline bool VisGPGPUPrimitive::IsComputable() const
{
  return _isComputable;
}



inline void VisGPGPUPrimitive::SetProgramArgument(void * iProgramArgument)
{
  //Warning LEAK is possible with bad use ! 
  //User must delete the argument with GetProgramArgument !
  //If you see a leak at this line, the developer has, as usual, not read
  //the documentation of the function !
  _programArgument = iProgramArgument;
}

inline void VisGPGPUPrimitive::SetExecuteContext(void * iExeCtx)
{
	_executeCtx = iExeCtx;
}


inline void * VisGPGPUPrimitive::getProgramArgument() const
{
  return _programArgument;
}

inline HRESULT VisGPGPUPrimitive::SetVBOID(const unsigned int & iVboID, const VisVertexComponent & iComponentType, 
                             const unsigned int & iRawBufferID)
{
  CHECK_TRUE_RETV_MSG(iVboID != 0, E_FAIL, "ID cannot be 0");
  _vboIDs.Append(new VisGPGPUVboInformation(iVboID, iComponentType, iRawBufferID));

  return S_OK;
}

inline HRESULT VisGPGPUPrimitive::SetIBOID(const unsigned int & iIboID)
{
  CHECK_TRUE_RETV_MSG(iIboID != 0, E_FAIL, "ID cannot be 0");
  _iboIDs.Append(iIboID);

  return S_OK;
}

inline HRESULT VisGPGPUPrimitive::SetTextureID(const unsigned int & iTextureID, const unsigned int & iTextureType) 
{
  CHECK_TRUE_RETV_MSG(iTextureID != 0, E_FAIL, "ID cannot be 0");

  VisGPGPUTextureInformation * textureInfo = new VisGPGPUTextureInformation();
  textureInfo->_textureID = iTextureID;
  textureInfo->_textureType = iTextureType;

  _textureIDs.Append(textureInfo);

  return S_OK;
}


bool VisGPGPUPrimitive::IsInteropInitialized() const
{
  return _interopInitialized;
}

void VisGPGPUPrimitive::SetInteropInitalized()
{	
  _interopInitialized = 1;
}




#endif /* VISGPGPUPRIMITIVE_H_ */

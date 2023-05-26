#ifndef VISCOMPUTEBASEPROGRAM_H_
#define VISCOMPUTEBASEPROGRAM_H_

#include "CATVisFoundation.h"

#include "VisComputeProgram.h"
#include "IVisTexturePtr.h"

#include <vector>
#include <set>
#include <string>


class VisRawBuffer;
class VisComputeManager;

class ExportedByCATVisFoundation VisComputeBaseProgram : public VisComputeProgram
{


public :


  VisComputeBaseProgram(HRESULT & oError, const CATString & iFileName);


    /** Set a float(1-4) uniform to the Compute Shader
    * @param iParamName The uniform name.
    * @param iValue The float value to set.
    */
  void SetParameter(const char * iParamName, float iValue) const;
  void SetParameter(const char * iParamName, float iValue, float iValue2) const ;
  void SetParameter(const char * iParamName, float iValue, float iValue2, float iValue3) const;
  void SetParameter(const char * iParamName, float iValue, float iValue2, float iValue3, float iValue4) const;


  /** Specify the group count for the dispatch command. This is used to determine the number of threads.
   *  Default value is 1 for each component.
   */
  void SetGroupCount(unsigned int iX, unsigned int iY, unsigned int iZ);

  /** Set a buffer to the compute shader. It will be bound as an UnorderedBuffer (also called SSBO in OpenGL)
   *  @param iParamName the shader parameter name.
   *  @param iBuffer The buffer you want to bound to the shader.
   */
  void SetParameterBuffer(const char * iParamName, VisRawBuffer * iBuffer);

  /** Set a texture to the compute shader.
    * @param iParamName the shader parameter name.
    * @param iTexture The texture you want to bound to the shader.
    */
  void SetParameterTexture(const char * iParamName, IVisTexturePtr & iTexture);
  void SetParameterTexture(const char * iParamName, const IVisTexturePtr & iTexture);
  
  /** Set a an image to the compute shader. You must be very careful to the lifecycle. The method doesn't make copy.
    * @param iParamName the shader parameter name.
    * @param iImage The image you want to bound as to the shader.
    */
  void SetParameterImage(const char * iParamName, VisImageHandle iImage);

  /** Set a texture to the compute shader.
    * @param iParamName the shader parameter name.
    * @param iTexturePath The texture path you want to bound to the shader.
    */
  void SetParameterTexture(const char * iParamName, const char * iTexturePath);

protected :

  enum EOrderType
  {
    eUserBuffer,
    eUserTexture,
    eUserTextureFromPath,
    eUserImage,
    eParamFloat1,
    eParamFloat2,
    eParamFloat3,
    eParamFloat4
  };

  virtual ~VisComputeBaseProgram();

  virtual HRESULT Compute(void* iProgramArgument) override;

  /** this method is shared with the draw indirect vbecause it has a specific need to get the VisBufferHandle of the buffer */
  void _SetBuffer(VisRawBuffer * iBuffer, const char * iParamName, EOrderType iOrder, VisBufferHandle* iHandlePtr);

private :


  struct DataOrder
  {
    EOrderType      type;
    std::string    paramName;
    union
    {
      VisRawBuffer * rb;
      const char *   texPath;
      float          values[4];
    };
    IVisTexturePtr tex;
    VisBufferHandle* bufferHandle; ///< used in case of draw indirect. We will return the handle in the pointer after creation.
                                   ///< if not used with draw indrect, just put NULL
    VisImageHandle image;
  };

private :


  virtual void PrepareParameters();

  void _SetProgramBuffer(VisComputeManager * iComputeManager, const DataOrder & iOrder);


private :

  unsigned int m_groupx;
  unsigned int m_groupy;
  unsigned int m_groupz;

  mutable std::vector<DataOrder> m_dataOrders; ///< Command buffer for the compute

  std::set<VisRawBuffer*> m_userBuffers; ///< This tab is used to release VisRawBuffer

};



#endif //VISCOMPUTEBASEPROGRAM_H_

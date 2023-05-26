#ifndef CATVisuContextTypes_H
#define CATVisuContextTypes_H

#include "CATDataType.h"
#include "CATBoolean.h"

//
// Read Pixels
//

typedef enum VIS_PIXEL_FORMAT
{
  VIS_PIXEL_STENCIL,
  VIS_PIXEL_DEPTH,
  VIS_PIXEL_RGBA,
  VIS_PIXEL_RGB
} VIS_PIXEL_FORMAT;

typedef enum VIS_PIXEL_TYPE
{
  VIS_PIXEL_UBYTE,
  VIS_PIXEL_BYTE,
  VIS_PIXEL_USHORT,
  VIS_PIXEL_SHORT,
  VIS_PIXEL_UINT,
  VIS_PIXEL_INT,
  VIS_PIXEL_FLOAT
} VIS_PIXEL_PIXEL_TYPE;

//
// Clear Flag
//

typedef enum VIS_CLEAR_FLAG
{
  VIS_CLEAR_DEPTH_BUFFER = 0x00000100,
  VIS_CLEAR_STENCIL_BUFFER = 0x00000400,
	VIS_CLEAR_RENDER_TARGET = 0x00004000,
} VIS_CLEAR_FLAG;

//
// Primitive Topology
//

typedef enum VIS_PRIMITIVE_TOPOLOGY
{
	VIS_PRIMITIVE_TOPOLOGY_UNDEFINED = 0,//
	VIS_PRIMITIVE_TOPOLOGY_POINTLIST = 1,// GL_POINTS
	VIS_PRIMITIVE_TOPOLOGY_LINELIST = 2,// GL_LINES
	VIS_PRIMITIVE_TOPOLOGY_LINESTRIP = 3,// GL_LINE_STRIP
	VIS_PRIMITIVE_TOPOLOGY_TRIANGLELIST = 4,// GL_TRIANGLES
	VIS_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,// GL_TRIANGLE_STRIP
} VIS_PRIMITIVE_TOPOLOGY;

//
// Primitive Core Topology
//

typedef enum VIS_PRIMITIVE_CORE_TOPOLOGY
{
	VIS_PRIMITIVE_CORE_TOPOLOGY_UNDEFINED = 0,
	VIS_PRIMITIVE_CORE_TOPOLOGY_POINT = 1,
	VIS_PRIMITIVE_CORE_TOPOLOGY_LINE = 2,
	VIS_PRIMITIVE_CORE_TOPOLOGY_TRIANGLE = 3,
} VIS_PRIMITIVE_CORE_TOPOLOGY;

#define VIS_PRIMITIVE_CORE_TOPOLOGY_COUNT 4

typedef enum VIS_MATRIX_DIRTY
{
	VIS_MATRIX_WORLD = 1,
	VIS_MATRIX_VIEW = 2,
	VIS_MATRIX_PROJECTION = 4,
	VIS_MATRIX_TEXTURE = 8,
} VIS_MATRIX_DIRTY;

//
// Index Type
//
/*
typedef enum VIS_INDEX_TYPE
{
	VIS_INDEX_UNDEFINED = 0,
	VIS_INDEX_UINT16 = 1,
	VIS_INDEX_UINT32 = 2,
} VIS_INDEX_TYPE;
*/

//
// Id
//
typedef CATUINTPTR VIS_ID;

//
// Vertex Attribute
//

typedef enum VIS_VERTEX_ATTRIB
{
	VIS_VERTEX_POSITION = 0,
	VIS_VERTEX_NORMAL = 1,
	VIS_VERTEX_TEXCOORD0 = 2,
	VIS_VERTEX_TANGENT = 3,
	VIS_VERTEX_BINORMAL = 4,
	VIS_VERTEX_COLOR = 5,
	VIS_VERTEX_LINEPARAM = 6,
} VIS_VERTEX_ATTRIB;

#define VIS_VERTEX_ATTRIB_COUNT 7

//
// Vertex Assembler Desc
//

typedef struct VIS_VERTEX_ASSEMBLER_DESC
{
	VIS_PRIMITIVE_TOPOLOGY PrimitiveTopology;
	VIS_PRIMITIVE_CORE_TOPOLOGY PrimitiveCoreTopology;

	CATBoolean AttribArrayEnable[VIS_VERTEX_ATTRIB_COUNT];
	unsigned int AttribArrayStride[VIS_VERTEX_ATTRIB_COUNT];
  unsigned int AttribArrayOffset[VIS_VERTEX_ATTRIB_COUNT];
	void const*  AttribArrayPointer[VIS_VERTEX_ATTRIB_COUNT];
  unsigned int AttribArraySize[VIS_VERTEX_ATTRIB_COUNT];
#ifdef _IOS_SOURCE
  //++p6a Correction of a multiple buffer bug on iOS
  unsigned int AttribArrayBufferID[VIS_VERTEX_ATTRIB_COUNT];
  //--p6a
#endif

	CATVizIndexType IndexType;

	VIS_ID VertexBufferID;
	VIS_ID IndexBufferID;

#ifdef __cplusplus
public:
	VIS_VERTEX_ASSEMBLER_DESC()
	{
		PrimitiveTopology = VIS_PRIMITIVE_TOPOLOGY_UNDEFINED;
		PrimitiveCoreTopology = VIS_PRIMITIVE_CORE_TOPOLOGY_UNDEFINED;

		for(int i = 0; i < VIS_VERTEX_ATTRIB_COUNT; i++)
		{
			AttribArrayEnable[i] = FALSE;

			AttribArrayStride[i] = 0;
			AttribArrayPointer[i] = NULL;

      AttribArraySize[i] = 0;

#ifdef _IOS_SOURCE
      AttribArrayBufferID[i] = 0;
#endif
      
		}

		IndexType = CATVizUCharType;

		VertexBufferID = 0;
		IndexBufferID = 0;
	}
#endif //__cplusplus
} VIS_VERTEX_ASSEMBLER_DESC;

//
// Face Fill Mode
//

typedef enum VIS_FACE_FILL_MODE
{
	VIS_FACE_FILL_WIREFRAME = 0,// = GL_LINE,
	VIS_FACE_FILL_SOLID = 1,// = GL_FILL
} VIS_FACE_FILL_MODE;

//
// Face Cull Mode
//

typedef enum VIS_FACE_CULL_MODE
{
	VIS_FACE_CULL_FRONT = 0,// = GL_FRONT,
	VIS_FACE_CULL_BACK = 1,// = GL_BACK
} VIS_FACE_CULL_MODE;

//
// Scissor Rect Desc
//

typedef struct VIS_SCISSOR_RECT_DESC
{
	int LowerLeftCornerXCoord;
	int LowerLeftCornerYCoord;
	unsigned int Width;
	unsigned int Height;
} VIS_SCISSOR_RECT_DESC;

//
// Viewport Desc
//

typedef struct VIS_VIEWPORT_DESC
{
	int LowerLeftCornerXCoord;
	int LowerLeftCornerYCoord;
	unsigned int Width;
	unsigned int Height;
} VIS_VIEWPORT_DESC;

//
// Rasterizer Desc
//

typedef struct VIS_RASTERIZER_DESC
{
	VIS_FACE_FILL_MODE FaceFillMode;
	unsigned int FaceCullEnable;
	VIS_FACE_CULL_MODE FaceCullMode;
	unsigned int FrontFaceCCW;

  unsigned int DepthBiasEnable;
  int DepthBias;
  float DepthBiasClamp;
  float SlopeScaledDepthBias;

  unsigned int MultisampleEnable;
  unsigned int ScissorEnable;
  VIS_SCISSOR_RECT_DESC ScissorRect;
  VIS_VIEWPORT_DESC Viewport;

#ifdef __cplusplus
public:
	VIS_RASTERIZER_DESC()
	{
    FaceFillMode = VIS_FACE_FILL_SOLID;
		FaceCullEnable = FALSE;
		FaceCullMode = VIS_FACE_CULL_BACK;
		FrontFaceCCW = TRUE;
		DepthBiasEnable = FALSE;
		DepthBias = 0;
		DepthBiasClamp = 0.0f;
		SlopeScaledDepthBias = 0.0f;
		MultisampleEnable = FALSE;
		ScissorEnable = FALSE;
		ScissorRect.Width = 0;
		ScissorRect.Height = 0;
		ScissorRect.LowerLeftCornerXCoord = 0;
		ScissorRect.LowerLeftCornerYCoord = 0;
		Viewport.Width = 0;
		Viewport.Height = 0;
		Viewport.LowerLeftCornerXCoord = 0;
		Viewport.LowerLeftCornerYCoord = 0;
	}
#endif //__cplusplus
} VIS_RASTERIZER_DESC;

//
// Depth Write Mask
//

typedef enum VIS_DEPTH_WRITE_MASK
{
    VIS_DEPTH_WRITE_MASK_ZERO = 0,
    VIS_DEPTH_WRITE_MASK_ALL = 1,
} VIS_DEPTH_WRITE_MASK;

//
// Comparison Func
//

typedef enum VIS_COMPARISON_FUNC
{
    VIS_COMPARISON_NEVER = 0,// = GL_NEVER,
    VIS_COMPARISON_LESS = 1,// = GL_LESS,
    VIS_COMPARISON_EQUAL = 2,// = GL_EQUAL,
    VIS_COMPARISON_LESS_EQUAL = 3,// = GL_LEQUAL,
    VIS_COMPARISON_GREATER = 4,// = GL_GREATER,
    VIS_COMPARISON_NOT_EQUAL = 5,// = GL_NOTEQUAL,
    VIS_COMPARISON_GREATER_EQUAL = 6,// = GL_GEQUAL,
    VIS_COMPARISON_ALWAYS = 7,// = GL_ALWAYS,
} VIS_COMPARISON_FUNC;

inline VIS_COMPARISON_FUNC ToVisComparisonFunc(unsigned int val)
{
  switch(val)
  {
  case /*GL_NEVER*/0x0200:        return VIS_COMPARISON_NEVER;
  case /*GL_LESS*/0x0201:         return VIS_COMPARISON_LESS;
  case /*GL_EQUAL*/0x0202:        return VIS_COMPARISON_EQUAL;        
  case /*GL_LEQUAL*/0x0203:       return VIS_COMPARISON_LESS_EQUAL;
  case /*GL_GREATER*/0x0204:      return VIS_COMPARISON_GREATER;
  case /*GL_NOTEQUAL*/0x0205:     return VIS_COMPARISON_NOT_EQUAL;
  case /*GL_GEQUAL*/0x0206:       return VIS_COMPARISON_GREATER_EQUAL;
  case /*GL_ALWAYS*/0x0207:       return VIS_COMPARISON_ALWAYS;
  default:              return VIS_COMPARISON_LESS;
  }
};

inline unsigned int ToOglVisComparisonFunc(VIS_COMPARISON_FUNC func)
{
  unsigned int modes[] = {0x0200, 0x0201, 0x0202, 0x0203, 0x0204, 0x0205, 0x0206, 0x0207};
  return modes[(int)func];
}

//
// Depth Range Desc
//

typedef struct VIS_DEPTH_RANGE_DESC
{
	float MinValue;
	float MaxValue;
} VIS_DEPTH_RANGE_DESC;

//
// Stencil Op
//

typedef enum VIS_STENCIL_OP
{
    VIS_STENCIL_OP_KEEP = 0,// = GL_KEEP,
    VIS_STENCIL_OP_ZERO = 1,// = GL_ZERO,
    VIS_STENCIL_OP_REPLACE = 2,// = GL_REPLACE,
    VIS_STENCIL_OP_INCR_SAT = 3,// = GL_INCR_WRAP,
    VIS_STENCIL_OP_DECR_SAT = 4,// = GL_DECR_WRAP,
    VIS_STENCIL_OP_INVERT = 5,// = GL_INVERT,
    VIS_STENCIL_OP_INCR = 6,// = GL_INCR,
    VIS_STENCIL_OP_DECR = 7,// = GL_DECR,
} VIS_STENCIL_OP;

inline VIS_STENCIL_OP ToVisStencilOp(unsigned int val)
{
  switch(val)
  {
  case /*GL_KEEP*/0x1E00:       return VIS_STENCIL_OP_KEEP;
  case /*GL_ZERO*/0x0:       return VIS_STENCIL_OP_ZERO;
  case /*GL_REPLACE*/0x1E01:    return VIS_STENCIL_OP_REPLACE;        
  //case GL_INCR_WRAP:  return VIS_STENCIL_OP_INCR_SAT;
  //case GL_DECR_WRAP:  return VIS_STENCIL_OP_DECR_SAT;
  case /*GL_INVERT*/0x150A:     return VIS_STENCIL_OP_INVERT;
  case /*GL_INCR*/0x1E02:       return VIS_STENCIL_OP_INCR;
  case /*GL_DECR*/0x1E03:       return VIS_STENCIL_OP_DECR;
  default:            return VIS_STENCIL_OP_KEEP;
  }
};

//
// Depth Desc
//

typedef struct VIS_DEPTH_DESC
{
	unsigned int DepthEnable;
	VIS_DEPTH_WRITE_MASK DepthWriteMask;
	VIS_COMPARISON_FUNC DepthComparisonFunc;
	VIS_DEPTH_RANGE_DESC DepthRange;

#ifdef __cplusplus
public:
	VIS_DEPTH_DESC()
	{
		DepthEnable = FALSE;
		DepthWriteMask = VIS_DEPTH_WRITE_MASK_ALL;
		DepthComparisonFunc = VIS_COMPARISON_LESS;
		DepthRange.MinValue = 0.0f;
		DepthRange.MaxValue = 1.0f;
	}
#endif //__cplusplus
} VIS_DEPTH_DESC;

//
// Stencil Desc
//

typedef struct VIS_STENCIL_DESC
{
	unsigned int StencilEnable;
	unsigned char StencilWriteMask;
	unsigned char StencilReadMask;
	unsigned int StencilReferenceValue;
	VIS_COMPARISON_FUNC StencilComparisonFunc;
	VIS_STENCIL_OP StencilFailOp;
    VIS_STENCIL_OP StencilDepthFailOp;
    VIS_STENCIL_OP StencilPassOp;

#ifdef __cplusplus
public:
	VIS_STENCIL_DESC()
	{
		StencilEnable = FALSE;
		StencilWriteMask = 0xFF;
		StencilReadMask = 0xFF;
		StencilReferenceValue = 0;
		StencilComparisonFunc = VIS_COMPARISON_ALWAYS;
		StencilFailOp = VIS_STENCIL_OP_KEEP;
		StencilDepthFailOp = VIS_STENCIL_OP_KEEP;
		StencilPassOp = VIS_STENCIL_OP_KEEP;
	}
#endif //__cplusplus
} VIS_STENCIL_DESC;

//
// Blend Factor
//

typedef enum VIS_BLEND_FACTOR
{
    VIS_BLEND_FACTOR_ZERO = 0,// = GL_ZERO,
    VIS_BLEND_FACTOR_ONE = 1,// = GL_ONE,
	  VIS_BLEND_FACTOR_SRC_COLOR = 2,// = GL_SRC_COLOR,
    VIS_BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 3,// = GL_ONE_MINUS_SRC_COLOR,
	  VIS_BLEND_FACTOR_SRC_ALPHA = 4,// = GL_SRC_ALPHA,
    VIS_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 5,// = GL_ONE_MINUS_SRC_ALPHA,
    VIS_BLEND_FACTOR_DEST_ALPHA = 6,// = GL_DST_ALPHA,
    VIS_BLEND_FACTOR_ONE_MINUS_DEST_ALPHA = 7,// = GL_ONE_MINUS_DST_ALPHA,
    VIS_BLEND_FACTOR_DEST_COLOR = 8,// = GL_DST_COLOR,
    VIS_BLEND_FACTOR_ONE_MINUS_DEST_COLOR = 9,// = GL_ONE_MINUS_DST_COLOR,
    VIS_BLEND_FACTOR_SRC_ALPHA_SATURATE = 10,// = GL_SRC_ALPHA_SATURATE,
    VIS_BLEND_FACTOR_CONSTANT_COLOR = 11,// = GL_CONSTANT_COLOR_EXT,
    VIS_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 12,// = GL_ONE_MINUS_CONSTANT_COLOR_EXT,
} VIS_BLEND_FACTOR;

inline VIS_BLEND_FACTOR ToVisBlendFactor(unsigned int val)
{
  switch(val)
  {
  case /*GL_ZERO*/0x0:                           return VIS_BLEND_FACTOR_ZERO;
  case /*GL_ONE*/0x1:                            return VIS_BLEND_FACTOR_ONE;
  case /*GL_SRC_COLOR*/0x0300:                      return VIS_BLEND_FACTOR_SRC_COLOR;
  case /*GL_ONE_MINUS_SRC_COLOR*/0x0301:            return VIS_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
  case /*GL_SRC_ALPHA*/0x0302:                      return VIS_BLEND_FACTOR_SRC_ALPHA;
  case /*GL_ONE_MINUS_SRC_ALPHA*/0x0303:            return VIS_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
  case /*GL_DST_ALPHA*/0x0304:                      return VIS_BLEND_FACTOR_DEST_ALPHA;
  case /*GL_ONE_MINUS_DST_ALPHA*/0x0305:            return VIS_BLEND_FACTOR_ONE_MINUS_DEST_ALPHA;
  case /*GL_DST_COLOR*/0x0306:                      return VIS_BLEND_FACTOR_DEST_COLOR;
  case /*GL_ONE_MINUS_DST_COLOR*/0x0307:            return VIS_BLEND_FACTOR_ONE_MINUS_DEST_COLOR;
  case /*GL_SRC_ALPHA_SATURATE*/0x0308:             return VIS_BLEND_FACTOR_SRC_ALPHA_SATURATE;
  //case GL_CONSTANT_COLOR_EXT:             return VIS_BLEND_FACTOR_CONSTANT_COLOR;
  //case GL_ONE_MINUS_CONSTANT_COLOR_EXT:   return VIS_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR;
  default:                                return VIS_BLEND_FACTOR_ZERO;
  }
};

//
// Blend Op
//

typedef enum VIS_BLEND_OP
{
    VIS_BLEND_OP_ADD = 0,// = GL_FUNC_ADD_EXT,
    VIS_BLEND_OP_SUBTRACT = 1,// = GL_FUNC_SUBTRACT_EXT,
    VIS_BLEND_OP_REV_SUBTRACT = 2,// = GL_FUNC_REVERSE_SUBTRACT_EXT,
    VIS_BLEND_OP_MIN = 3,// = GL_MIN_EXT,
    VIS_BLEND_OP_MAX = 4,// = GL_MAX_EXT,
} VIS_BLEND_OP;

typedef enum VIS_COLOR_WRITE_ENABLE
{
    VIS_COLOR_WRITE_ENABLE_RED = 1,
    VIS_COLOR_WRITE_ENABLE_GREEN = 2,
    VIS_COLOR_WRITE_ENABLE_BLUE = 4,
    VIS_COLOR_WRITE_ENABLE_ALPHA = 8,
    VIS_COLOR_WRITE_ENABLE_ALL = 
      ( VIS_COLOR_WRITE_ENABLE_RED | VIS_COLOR_WRITE_ENABLE_GREEN |  
        VIS_COLOR_WRITE_ENABLE_BLUE | VIS_COLOR_WRITE_ENABLE_ALPHA ),
} VIS_COLOR_WRITE_ENABLE;

//
// Blend Desc
//

typedef struct VIS_BLEND_DESC {
	unsigned int BlendEnable;
    VIS_BLEND_FACTOR SrcColorBlendFactor;
    VIS_BLEND_FACTOR DestColorBlendFactor;
    VIS_BLEND_OP BlendOp;
    VIS_BLEND_FACTOR SrcAlphaBlendFactor;
    VIS_BLEND_FACTOR DestAlphaBlendFactor;
    VIS_BLEND_OP AlphaBlendOp;
	float BlendConstantColor[4];
	unsigned int RenderTargetWriteMask;

#ifdef __cplusplus
public:
	VIS_BLEND_DESC()
	{
		BlendEnable = FALSE;
		SrcColorBlendFactor = VIS_BLEND_FACTOR_ONE;
		DestColorBlendFactor = VIS_BLEND_FACTOR_ZERO;
		BlendOp = VIS_BLEND_OP_ADD;
		SrcAlphaBlendFactor = VIS_BLEND_FACTOR_ONE;
		DestAlphaBlendFactor = VIS_BLEND_FACTOR_ZERO;
		AlphaBlendOp = VIS_BLEND_OP_ADD;
		BlendConstantColor[0] = 0.0f;
		BlendConstantColor[0] = 0.0f;
		BlendConstantColor[0] = 0.0f;
		BlendConstantColor[0] = 0.0f;
		RenderTargetWriteMask = VIS_COLOR_WRITE_ENABLE_ALL;
	}
#endif //__cplusplus
} VIS_BLEND_DESC;

/*

frag.rgba = (fragSrc.rgba * SrcColorBlendFactor) BlendOp (fragDest.rgba * DestColorBlendFactor)

*/

//
// Programmable States (means via shaders) (from a d3d10 point of view)
//

#include "CATVisuContextFixedPipelineTypes.h"

//
// Resources Types
//

//
// Buffer Bind Flag
//

typedef enum VIS_BUFFER_BIND_FLAG
{
	VIS_BUFFER_BIND_VERTEX = 0,
	VIS_BUFFER_BIND_INDEX = 1,
} VIS_BUFFER_BIND_FLAG;

//
// Resource Usage
//

typedef enum VIS_RESOURCE_USAGE
{
	VIS_RESOURCE_DEFAULT = 0,
	VIS_RESOURCE_IMMUTABLE = 1,
	VIS_RESOURCE_DYNAMIC = 2,
	VIS_RESOURCE_STAGING = 3,
} VIS_RESOURCE_USAGE;

//
// CPU Access Flag
//

typedef enum VIS_CPU_ACCESS_FLAG
{
    VIS_CPU_ACCESS_WRITE = 0x10000L,
    VIS_CPU_ACCESS_READ = 0x20000L,
} VIS_CPU_ACCESS_FLAG;

//
// Buffer Desc
//

typedef struct VIS_BUFFER_DESC {
    unsigned int ByteWidth;
    VIS_RESOURCE_USAGE Usage;
    unsigned int BindFlags;
    unsigned int CPUAccessFlags;
} VIS_BUFFER_DESC;

//
// Texture Desc
//

typedef struct VIS_TEXTURE_DESC {
    unsigned int Width;
    unsigned int Height;
    unsigned int MipLevels;
    unsigned int BindFlags;
    VIS_TEXTURE_FORMAT Format;
} VIS_TEXTURE_DESC;

//
// Dirty Desc
//

//
// Group State
//

typedef enum VIS_GROUP_STATE
{
  VIS_GROUP_VERTEX_ASM        = 0x1 << 1, //often used
  VIS_GROUP_RASTERIZER        = 0x1 << 2,
  VIS_GROUP_DEPTH             = 0x1 << 3,
  VIS_GROUP_STENCIL           = 0x1 << 4,
  VIS_GROUP_BLEND             = 0x1 << 5,

  VIS_GROUP_CONTEXT           = 0x1 << 6,
  VIS_GROUP_MATRIX            = 0x1 << 7,
  VIS_GROUP_CLIP_PLANE        = 0x1 << 8,
  VIS_GROUP_LIGHTING          = 0x1 << 9,
  VIS_GROUP_MATERIAL          = 0x1 << 10,
  VIS_GROUP_FOG               = 0x1 << 11,
  VIS_GROUP_ALPHA_TEST        = 0x1 << 12,
  VIS_GROUP_NORMAL            = 0x1 << 13,
  VIS_GROUP_POLYGON_STIPPLE   = 0x1 << 14,
  VIS_GROUP_LINE              = 0x1 << 15,
  VIS_GROUP_RAST              = 0x1 << 16,
  VIS_GROUP_COLOR             = 0x1 << 17,
  VIS_GROUP_TEXTURING         = 0x1 << 18,

  VIS_GROUP_SHADERS           = 0x1 << 19,

  VIS_GROUP_ALL = (
    VIS_GROUP_VERTEX_ASM |
    VIS_GROUP_RASTERIZER |
    VIS_GROUP_DEPTH |
    VIS_GROUP_STENCIL |
    VIS_GROUP_BLEND |
    VIS_GROUP_CONTEXT |
    VIS_GROUP_MATRIX |
    VIS_GROUP_CLIP_PLANE |
    VIS_GROUP_LIGHTING |
    VIS_GROUP_MATERIAL |
    VIS_GROUP_FOG |
    VIS_GROUP_ALPHA_TEST |
    VIS_GROUP_NORMAL |
    VIS_GROUP_POLYGON_STIPPLE |
    VIS_GROUP_LINE |
    VIS_GROUP_RAST |
    VIS_GROUP_COLOR |
    VIS_GROUP_TEXTURING |
    VIS_GROUP_SHADERS
  ),

  VIS_GROUP_CB0 = (
    VIS_GROUP_CONTEXT |
    VIS_GROUP_MATRIX |
    VIS_GROUP_CLIP_PLANE |
    VIS_GROUP_LIGHTING |
    VIS_GROUP_MATERIAL |
    VIS_GROUP_FOG |
    VIS_GROUP_ALPHA_TEST |
    VIS_GROUP_NORMAL |
    VIS_GROUP_POLYGON_STIPPLE |
    VIS_GROUP_LINE |
    VIS_GROUP_RAST |
    VIS_GROUP_COLOR |
    VIS_GROUP_TEXTURING
  ),

} VIS_GROUP_STATE;

//
// Vertex Asm State
//

typedef enum VIS_VERTEX_ASM_STATE
{
  VIS_VERTEX_ASM_PRIMITIVE_TOPOLOGY  = 0x1 << 1,
  VIS_VERTEX_ASM_INPUT_LAYOUT        = 0x1 << 2,
  VIS_VERTEX_ASM_INDEX_TYPE          = 0x1 << 3,
  VIS_VERTEX_ASM_INDEX_BUFFER        = 0x1 << 4,
  VIS_VERTEX_ASM_VERTEX_BUFFER       = 0x1 << 5,
  
  VIS_VERTEX_ASM_ALL = (
    VIS_VERTEX_ASM_PRIMITIVE_TOPOLOGY |
    VIS_VERTEX_ASM_INPUT_LAYOUT |
    VIS_VERTEX_ASM_INDEX_TYPE |
    VIS_VERTEX_ASM_INDEX_BUFFER |
    VIS_VERTEX_ASM_VERTEX_BUFFER
  ),

} VIS_VERTEX_ASM_STATE;

typedef struct VIS_DIRTY_DESC {
  unsigned int DirtyGroup;
  unsigned int DirtyVertexAsm;
	unsigned int DirtyMatrix;

#ifdef __cplusplus
public:
  VIS_DIRTY_DESC()
	{
    MakeDirty();
	}
  void MakeDirty()
  {
    DirtyGroup = VIS_GROUP_ALL;
    DirtyVertexAsm = VIS_VERTEX_ASM_ALL;
		DirtyMatrix = VIS_MATRIX_WORLD | VIS_MATRIX_VIEW | VIS_MATRIX_PROJECTION | VIS_MATRIX_TEXTURE;
  }
  void MakeClean()
  {
    DirtyGroup = 0;
    DirtyVertexAsm = 0;
		DirtyMatrix = 0;
  }
#endif //__cplusplus
} VIS_DIRTY_DESC;

#endif // ! CATVisuContextTypes_H



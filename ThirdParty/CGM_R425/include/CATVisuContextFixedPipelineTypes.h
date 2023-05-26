#ifndef CATVisuContextFixedPipelineTypes_H
#define CATVisuContextFixedPipelineTypes_H

#ifndef __hlsl
#define TYPEDEF typedef
#define ENDTYPEDEF(x) x

struct matrix
{
	float Value[16];
};

struct float4
{
	float& operator[](int i ){ return Value[ i ]; };

	CATBoolean operator!=(float4 vec){ return (vec.x != x) || (vec.y != y) || (vec.z != z) || (vec.w != w); };

	CATBoolean operator==(float4 vec){ return (vec.x == x) && (vec.y == y) && (vec.z == z) && (vec.w == w); };

	union
	{
		struct
		{
			float x, y, z, w;
		};
		float Value[4];
	};
	
	float4()
	{
		Value[0] = 0.0f;
		Value[1] = 0.0f;
		Value[2] = 0.0f;
		Value[3] = 0.0f;
	}
	
	float4(float x, float y, float z, float w)
	{
		Value[0] = x;
		Value[1] = y;
		Value[2] = z;
		Value[3] = w;
	}
};

struct int4
{
	int& operator[](int i ){ return Value[ i ]; };

	CATBoolean operator!=(float4 vec){ return (vec.x != x) || (vec.y != y) || (vec.z != z) || (vec.w != w); };

	CATBoolean operator==(float4 vec){ return (vec.x == x) && (vec.y == y) && (vec.z == z) && (vec.w == w); };

	union
	{
		struct
		{
			int x, y, z, w;
		};
		int Value[4];
	};

	int4()
	{
		Value[0] = 0;
		Value[1] = 0;
		Value[2] = 0;
		Value[3] = 0;
	}
	
	int4(int x, int y, int z, int w)
	{
		Value[0] = x;
		Value[1] = y;
		Value[2] = z;
		Value[3] = w;
	}
};

struct uint4
{
	unsigned int& operator[](int i ){ return Value[ i ]; };

	CATBoolean operator!=(float4 vec){ return (vec.x != x) || (vec.y != y) || (vec.z != z) || (vec.w != w); };

	CATBoolean operator==(float4 vec){ return (vec.x == x) && (vec.y == y) && (vec.z == z) && (vec.w == w); };

	union
	{
		struct
		{
			unsigned int x, y, z, w;
		};
		unsigned int Value[4];
	};

	uint4()
	{
		Value[0] = 0;
		Value[1] = 0;
		Value[2] = 0;
		Value[3] = 0;
	}
	
	uint4(unsigned int x, unsigned int y, unsigned int z, unsigned int w)
	{
		Value[0] = x;
		Value[1] = y;
		Value[2] = z;
		Value[3] = w;
	}
};

#else
#define TYPEDEF  
#define ENDTYPEDEF(x)  
#endif //__hlsl

//
// Context Desc
//

TYPEDEF struct VIS_CONTEXT_DESC
{
	float4 RenderTargetClearValue;

	float DepthBufferClearValue;
	int StencilBufferClearValue;

	unsigned int Width;
	unsigned int Height;
	unsigned int ViewportWidth;
	unsigned int ViewportHeight;

	unsigned int P0;
	unsigned int P1;

#ifdef __cplusplus
public:
	VIS_CONTEXT_DESC()
	{
    RenderTargetClearValue = float4(0.0f, 0.0f, 1.0f, 0.0f);//normally it's black

    DepthBufferClearValue = 1.0f;
		StencilBufferClearValue = 0;
		
		Width = 0;
		Height = 0;
		ViewportWidth = 0;
		ViewportHeight = 0;

		P0 = 666;
		P1 = 666;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_CONTEXT_DESC);

//
// Matrix Desc
//

TYPEDEF struct VIS_MATRIX_DESC
{
	matrix World;
	matrix View;
	matrix Projection;
  matrix Texture;

  matrix WV;
  matrix WVI;
  matrix WVP;

	float4 ViewpointPosition;
  float4 NearPlaneEq;

#ifdef __cplusplus
public:
	VIS_MATRIX_DESC()
	{
		float identity[] =
		{
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
		memcpy(World.Value, identity, 16 * sizeof(float));
		memcpy(View.Value, identity, 16 * sizeof(float));
		memcpy(Projection.Value, identity, 16 * sizeof(float));
    memcpy(Texture.Value, identity, 16 * sizeof(float));

    memcpy(WV.Value, identity, 16 * sizeof(float));
    memcpy(WVI.Value, identity, 16 * sizeof(float));
		memcpy(WVP.Value, identity, 16 * sizeof(float));

		ViewpointPosition = float4(0.0f, 0.0f, 0.0f, 0.0f);
    NearPlaneEq = float4(0.0f, 0.0f, 0.0f, 0.0f);
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_MATRIX_DESC);

//
// Clip Plane Desc
//

#ifndef __hlsl
TYPEDEF enum VIS_CLIP_PLANE
{
	VIS_CLIP_PLANE0 = 0,
	VIS_CLIP_PLANE1 = 1,
	VIS_CLIP_PLANE2 = 2,
	VIS_CLIP_PLANE3 = 3,
	VIS_CLIP_PLANE4 = 4,
	VIS_CLIP_PLANE5 = 5,
	VIS_CLIP_PLANE6 = 6,
	VIS_CLIP_PLANE7 = 7,
} VIS_CLIP_PLANE;
#endif //__hlsl

TYPEDEF struct VIS_CLIP_PLANE_DESC
{
	float4 ClipPlaneEquation[8];

	unsigned int ClipPlaneEnable;
	unsigned int P0;
	unsigned int P1;
	unsigned int P2;

#ifdef __cplusplus
public:
	VIS_CLIP_PLANE_DESC()
	{
		for(int i = 0; i < 8; i++)
		{
			ClipPlaneEquation[i] = float4(0.0f, 0.0f, 0.0f, 0.0f);
		}

		ClipPlaneEnable = 0;
		P0 = 666;
		P1 = 666;
		P2 = 666;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_CLIP_PLANE_DESC);

//
// Lighting Desc
//

#ifndef __hlsl
TYPEDEF enum VIS_LIGHT_SOURCE
{
	VIS_LIGHT_SOURCE0 = 0,
	VIS_LIGHT_SOURCE1 = 1,
	VIS_LIGHT_SOURCE2 = 2,
	VIS_LIGHT_SOURCE3 = 3,
	VIS_LIGHT_SOURCE4 = 4,
	VIS_LIGHT_SOURCE5 = 5,
	VIS_LIGHT_SOURCE6 = 6,
	VIS_LIGHT_SOURCE7 = 7,
} VIS_LIGHT_SOURCE;
#endif //__hlsl

TYPEDEF struct VIS_LIGHTING_DESC
{
	float4 LightSourcePosition[8];//w=0 -> directionnal | w=1 ->point
	float4 LightSourceSpotDirection[8];
	float4 LightSourceAttenuationParam[8];//[constant, linear, quadratic, null]
	float4 LightSourceSpotParam[8];//[exponent, cutoff, null, null] (0<cutoff<90 -> spot | cutoff = 180 ->point)
	float4 LightSourceAmbientColor[8];
	float4 LightSourceDiffuseColor[8];
	float4 LightSourceSpecularColor[8];

	float4 GlobalAmbientColor;
	unsigned int ViewerLocal;
	unsigned int SpecularColorSeparate;

	unsigned int LightingEnable;
	unsigned int TwoSideLightingEnable;
	unsigned int LightSourceEnable;

	unsigned int P0;
	unsigned int P1;
	unsigned int P2;

#ifdef __cplusplus
public:
	VIS_LIGHTING_DESC()
	{
		for(int i = 0; i < 8; i++)
		{
			LightSourcePosition[i]			= float4(0.0f, 0.0f, 1.0f, 0.0f);
			LightSourceSpotDirection[i]		= float4(0.0f, 0.0f, -1.0f, 0.0f);
			LightSourceAttenuationParam[i]	= float4(1.0f, 0.0f, 0.0f, 0.0f);
			LightSourceSpotParam[i]			= float4(0.0f, 180.0f, 0.0f, 0.0f);
			LightSourceAmbientColor[i]		= float4(0.0f, 0.0f, 0.0f, 1.0f);
			LightSourceDiffuseColor[i]		= float4(0.0f, 0.0f, 0.0f, 1.0f);
			LightSourceSpecularColor[i]		= float4(0.0f, 0.0f, 0.0f, 1.0f);
		}
		GlobalAmbientColor = float4(0.2f, 0.2f, 0.2f, 1.0f);
		ViewerLocal = FALSE;
		SpecularColorSeparate = FALSE;
		
		LightingEnable = FALSE;
		TwoSideLightingEnable = FALSE;
		LightSourceEnable = 0;

		P0 = 0;
		P1 = 0;
		P2 = 0;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_LIGHTING_DESC);

//
// Material Desc
//

TYPEDEF struct VIS_MATERIAL_DESC
{
	float4 MaterialAmbientColor;
	float4 MaterialDiffuseColor;
	float4 MaterialSpecularColor;
	float4 MaterialEmissionColor;

	float MaterialShininess;

	unsigned int P0;
	unsigned int P1;
	unsigned int P2;

#ifdef __cplusplus
public:
	VIS_MATERIAL_DESC()
	{
		MaterialAmbientColor = float4(0.2f, 0.2f, 0.2f, 1.0f);
		MaterialDiffuseColor = float4(0.8f, 0.8f, 0.8f, 1.0f);
		MaterialSpecularColor = float4(0.0f, 0.0f, 0.0f, 1.0f);
		MaterialEmissionColor = float4(0.0f, 0.0f, 0.0f, 1.0f);

		MaterialShininess = 0.0f;

		P0 = 0;
		P1 = 1;
		P2 = 2;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_MATERIAL_DESC);

//
// Fog Desc
//

#ifndef __hlsl
TYPEDEF enum VIS_FOG_MODE
{
	VIS_FOG_MODE_EXP = 0,
	VIS_FOG_MODE_EXP2 = 1,
	VIS_FOG_MODE_LINEAR = 2,
} VIS_FOG_MODE;
#endif //__hlsl

TYPEDEF struct VIS_FOG_DESC
{
	float4 FogColor;
	unsigned int FogEnable;
	unsigned int FogMode;
	float FogDensity;
	float FogStart;
	float FogEnd;

	unsigned int P0;
	unsigned int P1;
	unsigned int P2;

#ifdef __cplusplus
public:
	VIS_FOG_DESC()
	{
		FogColor = float4(0.0f, 0.0f, 0.0f, 0.0f);
		FogEnable = FALSE;
		FogMode = VIS_FOG_MODE_EXP;
		FogDensity = 1.0f;
		FogStart = 0.0f;
		FogEnd = 1.0f;

		P0 = 0;
		P1 = 0;
		P2 = 0;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_FOG_DESC);

//
// Alpha Test Desc
//

TYPEDEF struct VIS_ALPHA_TEST_DESC
{
	unsigned int AlphaTestEnable;
	unsigned int AlphaTestComparisonFunc;
	float AlphaTestReferenceValue;

	unsigned int P0;

#ifdef __cplusplus
public:
	VIS_ALPHA_TEST_DESC()
	{
		AlphaTestEnable = FALSE;
		AlphaTestComparisonFunc = VIS_COMPARISON_ALWAYS;
		AlphaTestReferenceValue = 0.0f;

		P0 = 0;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_ALPHA_TEST_DESC);

//
// Normal Desc
//

TYPEDEF struct VIS_NORMAL_DESC
{
	float4 GlobalNormal;
	
	unsigned int GlobalNormalEnable;
	unsigned int NormalizeEnable;
	unsigned int RescaleNormalEnable;

	unsigned int P0;

#ifdef __cplusplus
public:
	VIS_NORMAL_DESC()
	{
		GlobalNormal = float4(0.0f, 0.0f, 0.0f, 0.0f);
		
		GlobalNormalEnable = FALSE;
		NormalizeEnable = FALSE;
		RescaleNormalEnable = FALSE;

		P0 = 0;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_NORMAL_DESC);

//
// Polygon Stipple Desc
//

TYPEDEF struct VIS_POLYGON_STIPPLE_DESC
{
	uint4 PolygonStippleMask[8];
	uint4 PolygonStippleEnable;

#ifdef __cplusplus
public:
	VIS_POLYGON_STIPPLE_DESC()
	{
		PolygonStippleEnable[0] = FALSE;
		memset(PolygonStippleMask, 0, sizeof(unsigned int) * 32);
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_POLYGON_STIPPLE_DESC);

//
// Line Desc
//

TYPEDEF struct VIS_LINE_DESC
{
	unsigned int LineWidthEnable;
	unsigned int LineStippleEnable;
	float LineWidth;
	unsigned int LineStippleFactor;
	unsigned int LineStipplePattern;

	unsigned int P0;
	unsigned int P1;
	unsigned int P2;

#ifdef __cplusplus
public:
	VIS_LINE_DESC()
	{
		LineWidthEnable = TRUE;
		LineStippleEnable = FALSE;
		LineWidth = 1.0f;
		LineStippleFactor = 1;
		LineStipplePattern = 0xFFFF;

		P0 = 0;
		P1 = 0;
		P2 = 0;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_LINE_DESC);

#ifndef __hlsl
TYPEDEF enum VIS_TYPE
{
  VIS_TYPE_UNDEFINED = 0,
  VIS_TYPE_BYTE = 1,
	VIS_TYPE_UBYTE = 2,
  VIS_TYPE_SHORT = 3,
  VIS_TYPE_USHORT = 4,
  VIS_TYPE_INT = 5,
  VIS_TYPE_UINT = 6,
	VIS_TYPE_FLOAT = 7,
} VIS_TYPE;
#endif //__hlsl

//
// Color Desc
//

TYPEDEF struct VIS_COLOR_DESC
{
	float4 rgba;
	unsigned int ColorArrayEnabled;
	unsigned int P0;
	unsigned int P1;
	unsigned int P2;

#ifdef __cplusplus
public:
	VIS_COLOR_DESC()
	{
		rgba = float4(0.0f, 0.0f, 0.0f, 0.0f);

		ColorArrayEnabled = FALSE;
		P0 = 0;
		P1 = 0;
		P2 = 0; 
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_COLOR_DESC);

//
// Texturing Desc
//

#ifndef __hlsl
TYPEDEF enum VIS_TEXTURE_BIND_FLAG
{
	VIS_TEXTURE_BIND_UNDEFINED = 0,
	VIS_TEXTURE_BIND_1D = 1,
	VIS_TEXTURE_BIND_2D = 2,
} VIS_TEXTURE_BIND_FLAG;
#endif //__hlsl

#ifndef __hlsl
TYPEDEF enum VIS_TEXTURE_FORMAT // à renommer en PIXEL_FORMAT
{
	VIS_TEXTURE_FORMAT_UNDEFINED = 0,
	VIS_TEXTURE_FORMAT_L = 1,
	VIS_TEXTURE_FORMAT_LA = 2,
	VIS_TEXTURE_FORMAT_RGBA = 3,
	VIS_TEXTURE_FORMAT_RGB = 4,
} VIS_TEXTURE_FORMAT;
#endif //__hlsl

#ifndef __hlsl
TYPEDEF enum VIS_FILTER
{
	VIS_FILTER_NEAREST = 0,
	VIS_FILTER_LINEAR = 1,
	VIS_FILTER_NEAREST_MIPMAP_NEAREST = 2,
	VIS_FILTER_NEAREST_MIPMAP_LINEAR = 3,
	VIS_FILTER_LINEAR_MIPMAP_NEAREST = 4,
	VIS_FILTER_LINEAR_MIPMAP_LINEAR = 5,
} VIS_FILTER;
#endif //__hlsl

#ifndef __hlsl
TYPEDEF enum VIS_WRAP_MODE
{
	VIS_WRAP_REPEAT = 0,
	VIS_WRAP_CLAMP = 1,
	VIS_WRAP_CLAMP_TO_EDGE = 2,
} VIS_WRAP_MODE;
#endif //__hlsl

#ifndef __hlsl
TYPEDEF enum VIS_TEXTURE_COORD
{
	VIS_TEXTURE_COORD_S = 0,
	VIS_TEXTURE_COORD_T = 1,
	VIS_TEXTURE_COORD_R = 2,
	VIS_TEXTURE_COORD_Q = 3,
} VIS_TEXTURE_COORD;
#endif //__hlsl

#ifndef __hlsl
TYPEDEF enum VIS_TEXTURE_COORD_GEN_MODE
{
	VIS_TEXTURE_COORD_OBJECT_LINEAR = 0,
	VIS_TEXTURE_COORD_EYE_LINEAR = 1,
	VIS_TEXTURE_COORD_SPHERE_MAP = 2,
} VIS_TEXTURE_COORD_GEN_MODE;
#endif //__hlsl

#ifndef __hlsl
TYPEDEF enum VIS_TEXTURE_FUNCTION
{
	VIS_TEXTURE_DECAL = 0,
	VIS_TEXTURE_REPLACE = 1,
	VIS_TEXTURE_MODULATE = 2,
	VIS_TEXTURE_BLEND = 3,
} VIS_TEXTURE_FUNCTION;
#endif //__hlsl

TYPEDEF struct VIS_TEXTURING_DESC
{
	unsigned int Texturing1DEnable;
	unsigned int Texturing2DEnable;
	unsigned int TextureBindFlag;
	unsigned int TextureFormat;
	
	unsigned int TextureID;
	
	unsigned int TextureFunction;
	
	unsigned int TextureMagFilter;
	unsigned int TextureMinFilter;

	float4 TextureEnvColor;
	
	uint4 TextureCoordGenEnable; //for s, t, r or q coord
	uint4 TextureCoordGenMode; //for s, t, r or q coord
	float4 TextureCoordGenPlaneEquation[4]; //[4] is again for each coord

	
	unsigned int TextureCoordSWrapMode;
	unsigned int TextureCoordTWrapMode;
	unsigned int TextureComparisonFunc;

  unsigned int ShadowMappingEnable;
  
	unsigned int P0;

#ifdef __cplusplus
public:
	VIS_TEXTURING_DESC()
	{
		Texturing1DEnable = FALSE;
		Texturing2DEnable = FALSE;
		TextureBindFlag = VIS_TEXTURE_BIND_UNDEFINED;
		TextureFormat = VIS_TEXTURE_FORMAT_UNDEFINED;
		
		TextureID = 0;
		
		TextureFunction = VIS_TEXTURE_MODULATE;
		TextureEnvColor = float4(0.0f, 0.0f, 0.0f, 0.0f);

		for(int i = 0; i < 4; i++)
		{
			TextureCoordGenEnable[i] = FALSE;

			TextureCoordGenPlaneEquation[i][0] = 0.0f;
			TextureCoordGenPlaneEquation[i][1] = 0.0f;
			TextureCoordGenPlaneEquation[i][2] = 0.0f;
			TextureCoordGenPlaneEquation[i][3] = 0.0f;
			
			TextureCoordGenMode[i] = VIS_TEXTURE_COORD_EYE_LINEAR;
		}
		
		TextureMagFilter = VIS_FILTER_LINEAR;
		TextureMinFilter = VIS_FILTER_NEAREST_MIPMAP_LINEAR;
		TextureCoordSWrapMode = VIS_WRAP_REPEAT;
		TextureCoordTWrapMode = VIS_WRAP_REPEAT;
		TextureComparisonFunc = VIS_COMPARISON_LESS_EQUAL;

    ShadowMappingEnable = FALSE;
    
		P0 = 0;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_TEXTURING_DESC);

//
// Raster Desc
//

TYPEDEF struct VIS_RASTER_DESC
{
  float4 RasterParams; //width, height, xOffset, yOffset
  
  unsigned int RasterSymbolEnable;
  unsigned int RasterSymbolBank;
  unsigned int RasterSymbolIndex;

  unsigned int RasterImageEnable;
  unsigned int RasterImageFormat;
  unsigned int RasterImageType;

  unsigned int P0;
  unsigned int P1;

#ifdef __cplusplus
public:
	VIS_RASTER_DESC()
	{
      RasterParams.x = 1.0f;
      RasterParams.y = 1.0f;
      RasterParams.z = 0.0f;
      RasterParams.w = 0.0f;

      RasterSymbolEnable = 0;
      RasterSymbolBank = 0;
      RasterSymbolIndex = 0;

      RasterImageEnable = 0;
      RasterImageFormat = VIS_TEXTURE_FORMAT_UNDEFINED;
      RasterImageType = VIS_TYPE_UNDEFINED;

      P0 = 0;
      P1 = 0;
	}
#endif //__cplusplus
} ENDTYPEDEF(VIS_RASTER_DESC);

#endif // ! CATVisuContextFixedPipelineTypes_H


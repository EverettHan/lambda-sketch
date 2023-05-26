#ifndef CATDisplayListElement_H
#define CATDisplaylistElement_H


// COPYRIGHT DASSAULT SYSTEMES 2007

#define CAT_DLE_TOTAL_GEOMETRIES 56
#define CAT_DLE_TOTAL_MATRICES 3

#if defined (_AIX)
#define CAT_DLE_TOTAL_STATES 63 // XK7 GPU_SKINNING ++
#else
#define CAT_DLE_TOTAL_STATES 62
#endif

#define CAT_DLE_TOTAL_ENDSTATES 9
#define CAT_DLE_TOTAL_BEGINSTATES 9
#define CAT_DLE_TOTAL_INHERITANCESTATES 2
#define CAT_DLE_TOTAL_GPGPUELEM 1 //UO4+ 15:04:30 IR-330136 GPPGU DL 

#define CAT_DLE_TOTAL_ALL_STATES (CAT_DLE_TOTAL_STATES+CAT_DLE_TOTAL_ENDSTATES+CAT_DLE_TOTAL_BEGINSTATES)

#define CAT_DLE_TOTAL_BEFORE_STATES (CAT_DLE_TOTAL_GEOMETRIES+CAT_DLE_TOTAL_MATRICES)
#define CAT_DLE_TOTAL_BEFORE_ENDSTATES (CAT_DLE_TOTAL_BEFORE_STATES+CAT_DLE_TOTAL_STATES)
#define CAT_DLE_TOTAL_BEFORE_BEGINSTATES (CAT_DLE_TOTAL_BEFORE_ENDSTATES+CAT_DLE_TOTAL_ENDSTATES)
#define CAT_DLE_TOTAL_BEFORE_INHERITANCESTATES (CAT_DLE_TOTAL_BEFORE_BEGINSTATES+CAT_DLE_TOTAL_BEGINSTATES)
#define CAT_DLE_TOTAL_BEFORE_GPGPUELEM (CAT_DLE_TOTAL_BEFORE_INHERITANCESTATES +CAT_DLE_TOTAL_INHERITANCESTATES) //UO4+ 15:04:30 IR-330136 GPPGU DL 

#define CAT_DLE_TOTAL_ELEMENTS (CAT_DLE_TOTAL_BEFORE_GPGPUELEM + CAT_DLE_TOTAL_GPGPUELEM) //UO4+ 15:04:30 IR-330136 GPPGU DL 

enum CATDisplayListGeometries
{
  //3D Geometric Elements
  CAT_DLE_LIGHT_SOURCE,
  CAT_DLE_3D_MARKER,
  CAT_DLE_3D_VIZ_MARKER,
  CAT_DLE_3D_VIZ_INDEXED_MARKER,
  CAT_DLE_3D_LINE,
  CAT_DLE_3D_VIZ_LINE,
  CAT_DLE_3D_VIZ_UV_LINE,
  CAT_DLE_3D_INDEXED_LINE,
  CAT_DLE_3D_BUFFERED_INDEXED_LINE,
  CAT_DLE_3D_EDGE,
  CAT_DLE_3D_VIZ_EDGE,
  CAT_DLE_3D_VIZ_UV_EDGE,
  CAT_DLE_3D_BUFFERED_EDGE,
  CAT_DLE_3D_FACE,
  CAT_DLE_3D_FACE_1D_TEXTURE,
  CAT_DLE_3D_FACE_2D_TEXTURE,
  CAT_DLE_3D_VIZ_FACE,
  CAT_DLE_3D_VIZ_FACE_1D_TEXTURE,
  CAT_DLE_3D_VIZ_FACE_2D_TEXTURE,
  CAT_DLE_3D_VIZ_UV_FACE,
  CAT_DLE_3D_BUFFERED_FACE,
  CAT_DLE_3D_BUFFERED_FACE_1D_TEXTURE,
  CAT_DLE_3D_BUFFERED_FACE_2D_TEXTURE,
  CAT_DLE_3D_PLANAR_FACE,
  CAT_DLE_3D_PLANAR_FACE_1D_TEXTURE,
  CAT_DLE_3D_PLANAR_FACE_2D_TEXTURE,
  CAT_DLE_3D_CYLINDER,
  CAT_DLE_3D_CYLINDER_1D_TEXTURE,
  CAT_DLE_3D_CYLINDER_2D_TEXTURE,
  CAT_DLE_3D_CURVED_PIPE,
  CAT_DLE_3D_CURVED_PIPE_1D_TEXTURE,
  CAT_DLE_3D_CURVED_PIPE_2D_TEXTURE,
  CAT_DLE_3D_MIRROR,
  CAT_DLE_3D_MIRROR_1D_TEXTURE,
  CAT_DLE_3D_MIRROR_2D_TEXTURE,
  CAT_DLE_3D_DYNAMIC_PRIMITIVE,
  CAT_DLE_3D_VIZ_DYNAMIC_PRIMITIVE,
  CAT_DLE_3D_PRIMITIVE_SET,
  CAT_DLE_3D_VOXEL_TREE,
  CAT_DLE_VIS_PRIMITIVE,
  CAT_DLE_VERTEX_ASSEMBLY,
  CAT_DLE_SHADER_OPTION,
  CAT_DLE_SIMPLE_DRAW,
  CAT_DLE_SIMPLE_DRAW_COMPACTED,
  CAT_DLE_BEGIN_MULTIPLE_DRAW,
  CAT_DLE_MULTIPLE_DRAW,
  CAT_DLE_END_MULTIPLE_DRAW,
  CAT_DLE_OOC_POINT_CLOUD,
  //2D Geometric Elements
  CAT_DLE_2D_MARKER,
  CAT_DLE_2D_LINE,
  CAT_DLE_2D_RECTANGLE,
  CAT_DLE_2D_POLYGON,
  CAT_DLE_2D_GEOMETRIC_TEXT,
  CAT_DLE_2D_QUAD_STRIP,
  CAT_DLE_2D_ARC_ELLIPSE,
  CAT_DLE_2D_ARC_CIRCLE
};

enum CATDisplayListMatrices
{
  CAT_DLE_PUSH_4X4_MATRIX = CAT_DLE_TOTAL_GEOMETRIES,
  CAT_DLE_PUSH_3X3_MATRIX,
  CAT_DLE_POP_MATRIX
};

enum CATDisplayListStates
{
  //Non Geometric Elements 
  //Attention CAT_DLE_PRIORITY doit toujours etre le premier enum
  //car il n'est pas ajoute dans le DisplayList 3D
  CAT_DLE_PRIORITY =  CAT_DLE_TOTAL_BEFORE_STATES,
  CAT_DLE_GRAPHIC_ATTRIBUTE_RGBA,
  CAT_DLE_GRAPHIC_ATTRIBUTE_SET,
  CAT_DLE_VALUE,
  CAT_DLE_ACTIVATE_REFINEMENT,
  CAT_DLE_QUALITY,
  CAT_DLE_TO_BUFFERIZE,
  CAT_DLE_VERTEX_BUFFER,
  CAT_DLE_TOLERANCE_SCALE,
  CAT_DLE_POLYGON_MODE,
  CAT_DLE_POLYGON_OFFSET,
  CAT_DLE_CLIPPING_MODE,
  CAT_DLE_ALL_IN_Z_MODE,
  CAT_DLE_EYE_POINT,
  CAT_DLE_FURTIF,
  CAT_DLE_GRAPHIC_MATERIAL,
  CAT_DLE_VIS_MATERIAL,
  CAT_DLE_VIS_MATERIAL_APPLICATION,
  CAT_DLE_VIEWPOINT,
  CAT_DLE_VIEWPORT,
  CAT_DLE_GEOMETRIC_TEXT_NUMBER,
  CAT_DLE_COLOR_MASK,
  CAT_DLE_DIALOG,
  CAT_DLE_ALPHA_FILTER_VALUE,
  CAT_DLE_BACK_FACE_CULLING_MODE,
  CAT_DLE_TWO_SIDED_LIGHTING_MODE,
#ifdef _IRIX_SOURCE
  CAT_DLE_ADD_SURFACIC_REP,
  CAT_DLE_REP_VIEW_MODE, //UO4+ IR-360692 New Rep View Modes with outlines
#else
 #ifdef _AIX
  CAT_DLE_INSIDE,
  CAT_DLE_IS_STRIP,
  CAT_DLE_REP_VIEW_MODE, //UO4+ IR-360692 New Rep View Modes with outlines
 #else
  CAT_DLE_INSIDE,
  CAT_DLE_REP_VIEW_MODE, //UO4+ IR-360692 New Rep View Modes with outlines
 #endif
#endif
  CAT_DLE_OUTLINE_STATE,
  CAT_DLE_PUSH_TEXTURE_MATRIX,
  CAT_DLE_POP_TEXTURE_MATRIX,
  CAT_DLE_SET_UV_TRANSFORM,
  CAT_DLE_SET_IBL_PARAMETERS,
  CAT_DLE_SET_LIGHTING_PROPERTIES,
  CAT_DLE_SET_CHANNEL_TEXTURE,
  CAT_DLE_PUSH_DECAL,
  CAT_DLE_POP_DECAL,
  CAT_DLE_SET_UVASSOC,
  CAT_DLE_SET_WORLDSCALE,
  CAT_DLE_RENDERING_MODE,
  CAT_DLE_VIS_ATTRIBUTE_POINT_TYPE,
  CAT_DLE_VIS_ATTRIBUTE_POINT_SIZE,
  CAT_DLE_SLAVE_GW_OUTSIDE,
  CAT_DLE_SLAVE_GW_NOT_OUTSIDE,
  CAT_DLE_DEPTH,

  CAT_DLE_VIS_ATTRIBUTE_NUMINSTANCE,
  CAT_DLE_VIS_ATTRIBUTE_INSTANCEBUFFER,

  // XK7 GPU_SKINNING ++
  CAT_DLE_VIS_ATTRIBUTE_BONE_TX_BUFFER, 
  CAT_DLE_VIS_ATTRIBUTE_NUMBONE,
  CAT_DLE_VIS_ATTRIBUTE_BONE_POS_BUFFER,
  CAT_DLE_VIS_ATTRIBUTE_BONE_NUMINSTANCE,
  // XK7 GPU_SKINNING --

  CAT_DLE_DRAW_SURFACIC_REP,
  CAT_DLE_END_DRAW_SURFACIC_REP,
  CAT_DLE_INDIRECT_DRAW_COUNT,
  CAT_DLE_INDIRECT_BUFFER,
  CAT_DLE_FILTER_RAYTRACING,
  CAT_DLE_VISU_DRAW_LAYER,
  CAT_DLE_VISU_DRAW_PRIORITY,
  CAT_DLE_VISU_DRAW_GEOMINDEX,
  CAT_DLE_VISU_REP_LAYER_NUMBER
};

enum CATDisplayListEndStates
{
  //Non Geometric Elements 
  CAT_DLE_END_DRAW_SCISSOR = CAT_DLE_TOTAL_BEFORE_ENDSTATES,
  CAT_DLE_END_DRAW_SIMPLE_SCISSOR,
  CAT_DLE_END_DRAW_CLIPPING_PLANE,
  CAT_DLE_END_DRAW_CLIPPING_SECTIONS,
  CAT_DLE_END_DRAW_SUB_CLIPPING_SECTIONS,
  CAT_DLE_END_DRAW_CLIPPING_VOLUMES, //++ OXQ: New RenderEngine
  CAT_DLE_END_DRAW_HIGHLIGHT, //++ OU4: New RenderEngine
  CAT_DLE_END_DRAW_CURVE_CLIPPING,
  CAT_DLE_END_DRAW_CLIPPING_SPHERES,
};

enum CATDisplayListBeginStates
{
  //Non Geometric Elements 
  CAT_DLE_DRAW_SCISSOR = CAT_DLE_TOTAL_BEFORE_BEGINSTATES,
  CAT_DLE_DRAW_SIMPLE_SCISSOR,
  CAT_DLE_DRAW_CLIPPING_PLANE,
  CAT_DLE_DRAW_CLIPPING_SECTIONS,
  CAT_DLE_DRAW_SUB_CLIPPING_SECTIONS,
  CAT_DLE_DRAW_CLIPPING_VOLUMES, //++ OXQ: New RenderEngine
  CAT_DLE_DRAW_HIGHLIGHT, //++ OU4: New RenderEngine
  CAT_DLE_DRAW_CURVE_CLIPPING,
  CAT_DLE_DRAW_CLIPPING_SPHERES,
};

enum CATDisplayListInheritanceStates
{
  CAT_DLE_INHERIT_GRAPHIC_ATTRIBUTE_SET = CAT_DLE_TOTAL_BEFORE_INHERITANCESTATES,
  CAT_DLE_INHERIT_GRAPHIC_ATTRIBUTE_FLAG
};

//UO4+ 15:04:30 IR-330136 GPPGU DL 
enum CATDisplayListGPGPUElement
{
  CAT_DLE_VIS_GPGPUPRIMITIVE = CAT_DLE_TOTAL_BEFORE_GPGPUELEM 
};
//UO4- 15:04:30 IR-330136 GPPGU DL 

#endif
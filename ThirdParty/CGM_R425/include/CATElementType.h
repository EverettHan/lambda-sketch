#ifndef CATElementType_H
#define CATElementType_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * Enumerate the different type of display's behavior of an element.
 * <b>Role</b>: It must be used with @href CATRender to specify the behavior of
 * an element.
 * @param OCCLUSION_VOLUME
 * use this enum to have a volume element which participate
 * to occlusion culling render.
 * @param OCCLUSION_SKIN
 * to occlusion culling render.
 * use this enum to have a skin element which participate
 * @param LIGHT_SOURCE
 * use this enum to have a light source element which participate
 * to culling render.
 * @param VOLUME
 * use this enum to have a volume element which participate
 * to culling render.
 * @param SKIN
 * use this enum to have a skin element which participate
 * to culling render.
 * @param TRANSPAR
 * use this enum to have a transparent element which participate
 * to culling render.
 * @param OUTLINE.
 * use this enum to have an face which could generate outline
 * to culling render.	
 * @param EDGE.
 * use this enum to have an edge element which participate
 * to culling render.	
 * @param HIDDEN_EDGE.
 * use this enum to have an 2D element which participate
 * to culling render in a 3D View with ZBuffer..
 * @param TRANSPAR_EDGE.
 * use this enum to have a transparent edge element which participate
 * to culling render.	
 * @param OTHER3D
 * use this enum to have a 3D element which participate
 * to culling render.
 * @param PRIORITY0 up to PRIORITY15p
 * do not use this enum (reserved).
 * @param HOTHER
 * use this enum to have a selected element (highlight) other than an edge 
 * which participate to culling render.
 * @param HEDGE
 * use this enum to have a selected edge (highlight) element which participate
 * to culling render.
 * @param FURTIVE_EDGE
 * use this enum to have a pre-selected edge (pre-highlight) element which
 * participate to culling render.
 * @param FURTIVE
 * use this enum to have a pre-selected (pre-highlight) element which
 * participate to culling render.
 * @param OTHER2D
 * use this enum to have a 2D element which participate
 * to culling render.
 * @param TRANSPAR2DP0 up to TRANSPAR2DP15
 * Usefull to define a priority for the 2D transparency.
 * @param DEFAULT
 * use this enum to have a default (2D or 3D) element which participate
 * to culling render.
 * @param GPGPU //UO4+ 15:04:30 IR-330136 GPPGU DL 
 * use this enum to make GPGPU computing. 
 */

enum CATVizElementType
{
 OCCLUSION_VOLUME = 0,
 OCCLUSION_SKIN,
 LIGHT_SOURCE,
 VOLUME,
 SKIN,
 ALPHA_TEST,
 TRANSPAR,
 OUTLINE,
 SPARSE_TEXTURE,
 EDGE,
 HIDDEN_EDGE,
 TRANSPAR_EDGE,
 OTHER3D_2DMODE,
 PRIORITY0,
 PRIORITY0p,
 PRIORITY1,
 PRIORITY1p,
 PRIORITY2,
 PRIORITY2p,
 PRIORITY3,
 PRIORITY3p,
 PRIORITY4,
 PRIORITY4p,
 PRIORITY5,
 PRIORITY5p,
 PRIORITY6,
 PRIORITY6p,
 PRIORITY7,
 PRIORITY7p,
 PRIORITY8,
 OTHER3D,
 PRIORITY8p,
 PRIORITY9,
 PRIORITY9p,
 PRIORITY10,
 PRIORITY10p,
 PRIORITY11,
 PRIORITY11p,
 PRIORITY12,
 PRIORITY12p,
 PRIORITY13,
 PRIORITY13p,
 PRIORITY14,
 PRIORITY14p,
 PRIORITY15,
 PRIORITY15p,
 HEDGE,
 HOTHER,
 FURTIVE_EDGE,
 FURTIVE,
 OTHER2D,
 TRANSPAR2DP0,
 TRANSPAR2DP1,
 TRANSPAR2DP2,
 TRANSPAR2DP3,
 TRANSPAR2DP4,
 TRANSPAR2DP5,
 TRANSPAR2DP6,
 TRANSPAR2DP7,
 TRANSPAR2DP8,
 TRANSPAR2DP9,
 TRANSPAR2DP10,
 TRANSPAR2DP11,
 TRANSPAR2DP12,
 TRANSPAR2DP13,
 TRANSPAR2DP14,
 TRANSPAR2DP15,
 GPGPU, //UO4+ 15:04:30 IR-330136 GPPGU DL
 DEFAULT
};


#define ELEMENT_TYPE CATVizElementType

#endif

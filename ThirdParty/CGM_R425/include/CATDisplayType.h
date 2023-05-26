#ifndef CATDisplayType_H
#define CATDisplayType_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


/**
 * Display modes. 
 * @param CATNormal
 *  This is the default mode and means that the graphical representation
 *  of the CATISO is added into viewpoints as any other graphical
 *  representation.
 * 
 * @param CATFurtive
 *  This mode means that the graphical representation of the CATISO 
 *  will be considered as furtive and then will be drawn using XOR mode
 *  and will overdraw the scene.
 *
 * @param CATBackground
 *  This mode means that the graphical representation of the CATISO
 *  will be drawn before any other graphical representations hold in a given
 *  viewpoint.
 *
 * @see CATISO
 */
enum CATDisplayType {CATNormal,CATFurtive,CATBackground};

#endif

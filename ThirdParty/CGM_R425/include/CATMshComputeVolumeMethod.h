#ifndef CATMshComputeVolumeMethod_H
#define CATMshComputeVolumeMethod_H

/**
 * @brief The method used to compute the volumes.
 * 
 * - TET_DECOMPOSITION: We split the elements into tets, whose 
 * volumes are eventually computed using the pyramid volume formula
 * - GAUSS_THEOREM: We split the faces into triangles and sum the constant one
 * over the closed faces to compute the volume (Gauss theorem)
 */
enum CATMshComputeVolumeMethod { TET_DECOMPOSITION, GAUSS_THEOREM };

#endif // CATMshComputeVolumeMethod

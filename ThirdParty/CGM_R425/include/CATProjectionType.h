#ifndef CATProjectionType_H
#define CATProjectionType_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/** 
 * Enumerates the different type of projection.
 * <b>Role</b>: It must be used in @href CAT3DViewer and @href CAT3DViewpoint
 * to specify the projection type.
 * @param CYLINDRIC
 * Use this enum to have a cylindric projection.
 * @param CONIC
 * Use this enum to have a conic projection.
 */

enum CATProjectionType
{
 CYLINDRIC,
 CONIC
};

/** @nodoc */
typedef CATProjectionType ProjectionType;

#endif

#ifndef CreateConvertSurToNurbsSur_H
#define CreateConvertSurToNurbsSur_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

class CATSurface;
class CATGeoFactory;
class CATConvertSurToNurbsSur;

#include "FrFOpeSur.h"
#include "CATSkillValue.h"


/**
 * @deprecated V5R10 CreateSurFittingToNurbsSur 
 * Creates the geometric operator that computes the Nurbs representation of a CATSurface.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iSurface
 * The pointer to the surfacee to convert.
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATConvertSurToNurbsSur
 */
ExportedByFrFOpeSur
 CATConvertSurToNurbsSur*  CreateConvertSurToNurbsSur( CATGeoFactory  *iFactory,
                                                     const CATSurface &iSurface, 
                                                     CATSkillValue iMode = BASIC);

#endif

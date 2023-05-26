#ifndef CATCreateTopShellOrientation_H 
#define CATCreateTopShellOrientation_H 

//COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Protected
 * @usage U1
 */ 

#include "AdvTopoUtil.h"
#include "CATTopShellOrientation.h"

/*
 * Constructs the CATTopShellOrientation operator. 
 * The CATTopShellOrientation operator
 * inverts the orientation of the faces of a shell as well as the underlying surfaces 
 * so that all the faces and surfaces have the same orientation as the shell. 
 * @param iFactory
 * A pointer to the factory of the resulting body.
 * @param iData
 * A pointer to the topological data.
 * @param inputBody
 * A pointer to the body which contains the shell to be processed.
 */
ExportedByAdvTopoUtil CATTopShellOrientation* CATCreateTopShellOrientation(CATGeoFactory*         iFactory,
                                                                           CATTopData*            iData,
                                                                           CATBody*               inputBody);
#endif






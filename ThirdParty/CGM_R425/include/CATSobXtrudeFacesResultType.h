//============================================================================
// Copyright Dassault Systemes Provence 2014, all rights reserved 
//============================================================================
//
// CATSobXtrudeFacesResultType.h pour l'op�rateur CATStoExtrudeFacesOperator
//
//============================================================================
//
// Usage notes:
//
//============================================================================
// April,     2014 : RBD : Creation CATSobXtrudeFacesResultType.h
//============================================================================
#ifndef CATSobXtrudeFacesResultType_H
#define CATSobXtrudeFacesResultType_H

//Pour l'export
#include "CATSobObjects.h"


/**
 * Les modes de cr�ation du r�sultat de CATStoExtrudeFacesOperator:
 **/
typedef enum 
{
CATSobXtrudeFacesResUndef,                      // R�sultat non d�fini (Before the run)
CATSobXtrudeFacesResFill,                       // R�sultat : Extrusion mode Fill
CATSobXtrudeFacesResJoin,                       // R�sultat : Extrusion mode join avec cr�ation de faces traces
CATSobXtrudeFacesResMerge,                      // R�sultat : Merge de couple de faces quasi-confondue
CATSobXtrudeFacesResXtrusionPure,               // R�sultat : Extrusion pure des faces, avec cr�ation de faces traces par ensemble connexes
CATSobXtrudeFacesResXtrusionPureUnitaire,       // R�sultat : Extrusion pure unitaire avec cr�ation de faces traces pour chaque face trait�es
CATSobXtrudeFacesResMultiple                    // R�sultat multiples : Traitement de plusieurs composantes connexes avec plusieurs types de r�sultats
} CATSobXtrudeFacesResultType;


/**
 * Gets the string corresponding to a diag
 *
 * @param iTResultType
 * The type of the result 
 *
 * @return
 * The string corresponding to the given diag
 **/

ExportedByCATSobObjects
const char* ToString(const CATSobXtrudeFacesResultType iTResultType);


#endif



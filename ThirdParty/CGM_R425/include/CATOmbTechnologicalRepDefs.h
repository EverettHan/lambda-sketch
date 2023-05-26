#ifndef CATOmbTechnologicalRepDefs_H
#define CATOmbTechnologicalRepDefs_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Protected 
 * @usage U1
 */

// System
#include "CATCollec.h"
#include "CATUnicodeString.h" // needed by HP-UX compiler for use of CATOmiNullString as prototype default value
// ObjectModelerInterfaces
#include "CATOmbTechnologicalRep.h"

class CATUnicodeString;
class CATLISTP(CATIOmbTechnologicalSet);

typedef class CATLISTP(CATIOmbTechnologicalSet) CATListOfCATIOmbTechnologicalSet;
typedef  CATLISTV(CATUnicodeString) CATListOfCATOmbTechnologicalCategory;

/**
* Define the CATTechnologicalSetId type.
* This type is used for define the name of the CATIOmbTechnologicalSet object.
*/
typedef CATUnicodeString CATTechnologicalSetId;

/**
* Define the CATListOfCATTechnologicalSetId type.
* This type is used for retrieve the list of CATIOmbTechnologicalSet objects under a Technological Representation.
*/
typedef CATLISTV(CATUnicodeString) CATListOfCATTechnologicalSetId;

/**
* Define the CATOmbTechnologicalCategory type.
* This type is used for define the category of the CATIOmbTechnologicalSet object.
*/
typedef CATUnicodeString CATOmbTechnologicalCategory;


extern ExportedByCATOmbTechnologicalRep CATUnicodeString CATOmbNullString;
extern ExportedByCATOmbTechnologicalRep CATTechnologicalSetId CATOmbNullSetId;
extern ExportedByCATOmbTechnologicalRep CATString TechnologicalRepNLSFileName;

#endif

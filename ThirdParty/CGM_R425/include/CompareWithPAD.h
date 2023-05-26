#ifndef CompareWithPAD_h
#define CompareWithPAD_h

/******************************************************************************************************
 CompareWithPAD
-----------------------------------------------------------------------------------------------------
Utility to compare 2 bodies using CATPAD

Input parameters:
 iConfig                               : software configuration
 iBodyToHL and iBodyRef                : bodies to compare
 iColor                                : TRUE to change color of cells of iBodyToHL
 iDimension                            : 2 to stop at faces level
                                         1 to go until edges
                                         0 to go until vertices
 iFaceOri                              : if TRUE, 2 faces having different orientation in shell
                                         are considered as different

Output parameters:
 oDifferencesFound                     : TRUE if all cells of BodyToHL are present in BodyRef
 iDump and iLongDump                   : if not NULL, it is filled by comparison information
-----------------------------------------------------------------------------------------------------
 2014 WEEK 44      Split from CompareBodyGeometries.h                                      LD2
******************************************************************************************************/

#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByCATCXTopology.h"

class CATBody;
class CATSoftwareConfiguration;

ExportedByCATCXTopology HRESULT CompareWithPAD(CATBody * iBodyToHL,
                                               CATBody * iBodyRef,
                                               int iDimension,
                                               CATBoolean iFaceOri,
                                               CATBoolean & oDifferencesFound,
                                               CATBoolean iColor,
                                               CATListOfCATUnicodeString * iDump,
                                               CATListOfCATUnicodeString * iLongDump);

#endif

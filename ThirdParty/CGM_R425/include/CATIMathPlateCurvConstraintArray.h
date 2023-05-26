/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............BeamFE                             
 *   FRAMEWORK:.........SurfacicMathematics                  
 *   DATE:..............Dec 2001
 *   Purpose : Interface of to build curve Constraint's for BeamFE
 *=========================================================
 * HISTORY:
 * Dec 2001 : ktu definition
 */

#ifndef CATIMathPlateCurvConstraintArray_H
#define CATIMathPlateCurvConstraintArray_H
#include "CATIMathPlateConstraintArray.h"
#include <string.h>
#include "CATBoolean.h"
class CATIMathPlateCurvConstraintArray : public CATIMathPlateConstraintArray
{
public:
   CATIMathPlateCurvConstraintArray(){}
   /*
    * return constraintType
    */
   virtual CATBoolean IsAKindOf(const char * iType);

protected:
   virtual ~CATIMathPlateCurvConstraintArray(){};
};

inline CATBoolean CATIMathPlateCurvConstraintArray::IsAKindOf(const char * iType)
{
   if(NULL==iType) return FALSE;
   if(strcmp(iType, "CATIMathPlateCurvConstraintArray"))
      return CATIMathPlateConstraintArray::IsAKindOf(iType);
   else return TRUE;  
}

#endif

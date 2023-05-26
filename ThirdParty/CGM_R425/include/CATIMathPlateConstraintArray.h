/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............BeamFE                             
 *   FRAMEWORK:.........SurfacicMathematics                  
 *   DATE:..............Dec 2001
 *   Purpose : Interface of All Plate( Plate, PlateFE, BeamFE) Constraints
 *=========================================================
 * HISTORY:
 * Dec 2001 : ktu definition
 */

#ifndef CATIMathPlateConstraintArray_H
#define CATIMathPlateConstraintArray_H
#include <string.h>
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
class CATIMathPlateConstraintArray: public CATBaseUnknown
{
public:
   CATIMathPlateConstraintArray(){}
   /*
    * dimension of working space
    */
   virtual int GetDimension() const = 0;

   /*
    * return sizeOfArray.
    */
   virtual void GetLength(int& oLength) const = 0;

   /*
    * return Curerent update date constraints version
    */
   virtual int GetConstraintVersion(int& oConstraintVersion) const = 0;

   /*
    * return constraintType
    */
   virtual CATBoolean IsAKindOf(const char * iType);

protected:
   virtual ~CATIMathPlateConstraintArray(){};
   
};

inline CATBoolean CATIMathPlateConstraintArray::IsAKindOf(const char * iType)
{
   if(NULL==iType) return FALSE;
   else return !(strcmp(iType, "CATIMathPlateConstraintArray"));
}

#endif

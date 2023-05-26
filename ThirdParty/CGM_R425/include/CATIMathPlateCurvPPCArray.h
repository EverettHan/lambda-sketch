/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............BeamFE                             
 *   FRAMEWORK:.........SurfacicMathematics                  
 *   DATE:..............Dec 2001
 *   Purpose : Interface of to build curve  PCC array  for BeamFE
 *=========================================================
 * HISTORY:
 * Dec 2001 : ktu definition
 */

#ifndef CATIMathPlateCurvPPCArray_H
#define CATIMathPlateCurvPPCArray_H

#include "CATIMathPlateCurvConstraintArray.h"
#include "CATMathPoint.h"
#include "CATMathPlateCurvPinpointConstraint.h"


class CATIMathPlateCurvPPCArray :public CATIMathPlateCurvConstraintArray
{
public:
   
   CATIMathPlateCurvPPCArray(){}
   /*
    * Change the Indexth pcc value,
    * Index in [0,.., Length-1]
    * 1. general method
    * 2. if dimension i<= 3, only dimension coordonnates of pt are valid if not code error returned
    * return : 0 successfull
    *        : 1 error
    */
   virtual int SetPPCValue(const int iIndex, const double iValue[]) = 0;

   virtual int SetPPCValue(const int iIndex, 
                           const CATMathPoint& iValue) = 0;

   /*
    * set and get  the Indexth pcc
    * Index in [0,.., Length-1]
    * eturn : 0 successfull
    *        : 1 error
    */
   virtual int SetPPC(const int iIndex, const CATMathPlateCurvPinpointConstraint& iPPC) = 0;
   virtual int GetPPC(const int iIndex, CATMathPlateCurvPinpointConstraint*& oPPC) = 0;
   
   /*
    *  Curerent update date constraints Values version
    */
   virtual int GetValueVersion(int& oValueVersion) const = 0;

   /*
    * return constraintType
    */
   CATBoolean IsAKindOf(const char * iType);
  
protected:
   virtual ~CATIMathPlateCurvPPCArray(){};

};


inline CATBoolean CATIMathPlateCurvPPCArray::IsAKindOf(const char * iType)
{
   if(NULL==iType) return FALSE;
   if(strcmp(iType, "CATIMathPlateCurvPPCArray"))
      return CATIMathPlateCurvConstraintArray::IsAKindOf(iType);
   else return TRUE;  
}

#endif

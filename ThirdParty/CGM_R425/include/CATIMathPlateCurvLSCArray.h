/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............BeamFE                             
 *   FRAMEWORK:.........SurfacicMathematics                  
 *   DATE:..............Jan 2002
 *   Purpose : Interface of to build curve  LSC array  for BeamFE
 *=========================================================
 * HISTORY:
 * Jan 2002 : ktu definition
 */

#ifndef CATIMathPlateCurvLSCArray_H
#define CATIMathPlateCurvLSCArray_H

#include "CATIMathPlateCurvConstraintArray.h"
#include "CATIMathPlateCurvPPCArray.h"

class CATMathPlateCurvLinearScalarConstraint;
class CATMathGridOfPoints;


class CATIMathPlateCurvLSCArray :public CATIMathPlateCurvConstraintArray
{
public:
   
   CATIMathPlateCurvLSCArray(){}
   
   /**
    * Initialise le iIndex-ieme  lsc du Tableau
    * return 1 si erreur 0 sinon
    */
   virtual int SetLSCValue(const int iIndex, 
                           const CATMathPlateCurvLinearScalarConstraint & iLSC)=0;

   /**
    * Initialise le iIndex-ieme  lsc du Tableau a partir du PPCA et des Coeffs
    * return 1 si erreur 0 sinon
    */
   virtual int SetLSCValue(const int iIndex, const double iTol,
                           CATIMathPlateCurvPPCArray * iPPCA,
                           const CATMathGridOfPoints & iCoeffs)=0;

   /**
    * Retourne l'ADRESSE du iIndex-ieme lsc du tableau
    * Retourn 1 si erreur 0 sinon
    */
   virtual int GetLSC(const int iIndex, CATMathPlateCurvLinearScalarConstraint*& oLSC) = 0;

   /**
    * Retourne l'ADRESSE du PPCA,  du iIndex-ieme lsc du tableau
    * Retourn 1 si erreur 0 sinon
    */
   virtual int GetPPCs(const int iIndex, CATIMathPlateCurvPPCArray *& oPPC) = 0;
   
   /**
    * Retourne l'ADRESSE des coeffs,  du iIndex-ieme lsc du tableau
    */

   virtual int GetCoeffs(const int iIndex, CATMathGridOfPoints *& oCoeffs) = 0;
   
   /**
    * Retourne la la version courantes des contraintes du tableau
    * Retourn 1 si erreur 0 sinon
    */
   virtual int GetConstraintVersion(int& oValueVersion) const = 0;

   /*
    * return constraintType
    */
   CATBoolean IsAKindOf(const char * iType);
  
protected:
   virtual ~CATIMathPlateCurvLSCArray(){};

};


inline CATBoolean CATIMathPlateCurvLSCArray::IsAKindOf(const char * iType)
{
   if(NULL==iType) return FALSE;
   if(strcmp(iType, "CATIMathPlateCurvLSCArray"))
      return CATIMathPlateCurvConstraintArray::IsAKindOf(iType);
   else return TRUE;  
}

#endif

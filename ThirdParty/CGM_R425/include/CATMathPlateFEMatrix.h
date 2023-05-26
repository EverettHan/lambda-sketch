/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............FE                             
 *   FRAMEWORK:.........SurfacicGeoOperator                  
 *   DATE:..............Feb 2002
 *   Purpose : Base Interface of Fe Matrix's
  *=========================================================
 * HISTORY:
 * Oct 2020 : ktu, definition de la methode clone
 * Feb 2002 :  definition
 **/

#ifndef _CATMathPlateFEMatrix_H
#define _CATMathPlateFEMatrix_H

#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATFEMatrixType.h"

class CATMathPlateFEMatrix
{
public:

   /**
    * virtual Clone
    * 
    */
	virtual  CATMathPlateFEMatrix * Clone()const =0;

   /**
    * virtual constructor
    * 
    */
	virtual  ~CATMathPlateFEMatrix(){}

   /**
    * Identify matrix
    * 
    */
   virtual FEMatrixType GetMatrixType() const =0;

   /**
    * this*iX=ioY
    * return :
    *         0  Successful completion
    *         1  Failure 
    */
   virtual int Multiply(const double * iX, double * ioY) const =0;

   /**
    * this *=t
    * return :
    *         0  Successful completion
    *         1  Failure 
    */
   virtual int Multiply(const double t) =0; 

   /**
    * ioM = *this * t
    * return :
    *         0  Successful completion
    *         1  Failure 
    */
   virtual int Multiply(CATMathPlateFEMatrix * ioM, const double t) const =0; 

   /**
    * this  += t* iM
    * return :
    *         0  Successful completion
    *         1  Failure 
    */
   virtual int MultiplyAndAdd(const CATMathPlateFEMatrix * iM, const double t) =0;
   
   /**
    * this += iM
    * return :
    *         0  Successful completion
    *         1  Failure 
    */
   virtual int Add(const CATMathPlateFEMatrix * iM) =0;

   /**
    * retun ptr of Coeffs table's
    */
   virtual const double * GetAllCoeffs() const =0;

   /**
    * reset all coeffs to 0.0;
    * return :
    *         0  Successful completion
    *         1  Failure 
    */
   virtual int Reset() =0;

   /**
    */
   virtual CATLONG32 GetBandOfMatrix() const =0;

   /**
    */
   virtual CATLONG32 GetSizeOfMatrix() const =0;

   /**
    *
    */
   virtual CATBoolean Is3D()const=0;


};

#endif

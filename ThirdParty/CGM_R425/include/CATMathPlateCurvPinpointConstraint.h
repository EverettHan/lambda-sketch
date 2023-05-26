/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............BeamFE                             
 *   FRAMEWORK:.........SurfacicMathematics                  
 *   DATE:..............Dec 2001
 *   Purpose : Build some constraint to use in BeamFE algorithms
 *=========================================================
 * HISTORY:
 * Dec 2001 : ktu definition
 */


#ifndef _CATMathPlateCurvPinpointConstraint_H
#define _CATMathPlateCurvPinpointConstraint_H

#include "MathPlate.h"
#include "CATMathVector.h"


class ExportedByMathPlate CATMathPlateCurvPinpointConstraint{

public:

   /*
    * Constructors
    * 1. initialize _Dimension , By Default _Dimension == 0 for test;
    * 2 Ful initialization
    * 3 copy
    */
   CATMathPlateCurvPinpointConstraint();
   
   CATMathPlateCurvPinpointConstraint(const int       iDimension,
                                      const double    iParameter,
                                      const double    iImposedValue [] ,
                                      const int       iOrder=0,
                                      const double    iTolerance=0.001);
   CATMathPlateCurvPinpointConstraint(const CATMathPlateCurvPinpointConstraint & ppc);

    CATMathPlateCurvPinpointConstraint& operator= (const CATMathPlateCurvPinpointConstraint& equals) ;
   /*
    * Destructor
    */
   ~CATMathPlateCurvPinpointConstraint();
   
   /*
    *  Order method's  
    */
   int GetDerivativeOrder() const { return _DerivativeOrder;}
   void SetDerivativeOrder(const int iOrder) { _DerivativeOrder = iOrder; }
  
   /*
    *  Parameter method's  
    */
   double GetParameter() const { return _T;}
   void SetParameter(const double  iParam) { _T = iParam; }


   /*
    *  Dimension  
    */
   int GetDimension() const { return _Dimension;}
   void SetDimension(const int iDim)  { _Dimension = iDim;}


   /*
    * Value Method's
    * The two first are general
    * if _dimension is <=3, we must use the adaptive methose
    * return 1 if error 0 if not 
    */
   int GetValue(double ioValues[] ) const ;
   int SetValue(const double iValues[], const double iTolerance = 0.001 );
   // dimension == 3;
   int GetValue(CATMathVector & ioValues) const;
   int SetValue(const CATMathVector & iValues, const double iTolerance = 0.001);
   int GetValue(CATMathPoint & ioValues) const;
   int SetValue(const CATMathPoint & iValues, const double iTolerance = 0.001);
   // dimension == 2;
   /*void GetValue(CATMathPoint2D & ioValues) const;
   void SetValues(const CATMathPoint2D & iValues);
   // dimension ==1;
   void GetValue(double &ioValues) const;
   void SetValues(const double & iValues);*/
   
 
   /*
    * Tolerance Method's 
    */
   double GetTolerance() const { return _Tolerance; }
   int    SetTolerance(const double & Tol)  ;

   void Dump(/*const int iNoPPC=-1*/)const;
 
private: 

   void Copy(const CATMathPlateCurvPinpointConstraint& ippc);

   /*
    * Define dimension of working space
    */
   int _Dimension;

   /*
    * Parameter value
    */
   double _T;

   /*
    * Derivative Order
    */
   int _DerivativeOrder;

   /*
    * Constraint's values
    * For optimization of new calls, we define:
    * _Value1D if _Dimesion equal to 1
    * _Value2D if _Dimesion equal to 2
    * _Value3D if _Dimesion equal to 3
    * _ValueND if _Dimesion > 3
    * WARNING!!!! Only One  will be used; 
    */
   double *  _ValueND;
   double    _Value3D[3];

   /*
    * Constraint tolerance's
    */
   double _Tolerance;


};

   // dimension == 3;
inline int CATMathPlateCurvPinpointConstraint::GetValue(CATMathVector & ioValues) const
{
   if(_Dimension<1) return 1;
   ioValues.SetCoord(_Value3D);
   return 0;
}

inline int CATMathPlateCurvPinpointConstraint::SetValue(const CATMathVector & iValues,
                                                        const double iTolerance)
{
   if(_Dimension<1) return 1;
   iValues.GetCoord(_Value3D);
   _Tolerance = iTolerance;
   return 0;
}
   
   // dimension == 3;
inline int CATMathPlateCurvPinpointConstraint::GetValue(CATMathPoint & ioValues) const
{
   if(_Dimension<1) return 1;
   ioValues.SetCoord(_Value3D);
   return 0;
}

inline int CATMathPlateCurvPinpointConstraint::SetValue(const CATMathPoint & iValues,
                                                        const double iTolerance)
{
   if(_Dimension<1) return 1;
   iValues.GetCoord(_Value3D);
   _Tolerance = iTolerance;
   return 0;
}

inline int CATMathPlateCurvPinpointConstraint::SetTolerance(const double & Tol)
{
   if(Tol<1e-15) return 1;
   _Tolerance = Tol;
   return 0;

}

   

#endif


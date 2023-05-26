
//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 1998
//===================================================================
//
// CATGSDModParam :
//
//===================================================================
// Usage notes:
//
//===================================================================
// January 99   Creation                         D. Johansson
//===================================================================

#ifndef CATGSDModParam_H  
#define CATGSDModParam_H 
#include "FrFOpeSur.h"
#include <stdlib.h>
#include "CATDataType.h"
#include "CATCGMVirtual.h"


class ExportedByFrFOpeSur CATGSDModParam : public CATCGMVirtual

{    
 public:

//==================================================================
// Constructor
//==================================================================

  CATGSDModParam () ;
  
//==================================================================
// Destructor
//==================================================================
        
  virtual ~CATGSDModParam () ;
  
//==================================================================
// Change magnitudes 
//==================================================================

void SetMagnitudes (const CATLONG32  MagnI   , 
                    const CATLONG32  MagnII ) ; 
//==================================================================
// Read magnitudes
//==================================================================

void GetMagnitudes (CATLONG32  &MagnI   , 
                    CATLONG32  &MagnII ) ; 

//==================================================================
// Change  scales
//==================================================================

void SetScales (const double  ScaleI  , 
                const double  ScaleII  ) ; 
 
//==================================================================
// Read  scales
//==================================================================

void GetScales (double  &ScaleI  , 
                double  &ScaleII  ) ;  

//==================================================================
// Sets the modification polynomials _ModPolA and _ModPolS. 
// In "CATGSDCrvSur" lengths are not intended to be given when 
// using "evalModParam". Then, "SetModPolynomials" is only to  
// be run ONCE after the object creation (or after any change  
// of magnitudes, of scaling or of parameter interval). 
// When using double guide surfaces the modification poly-
// nomials are to be created individually for each point. Thus
// "SetModPolynomials" is run BEFORE EACH use of "evalModParam".    
//==================================================================

void SetModPolynomials (const double LengthA, 
                        const double LengthS, 
                        const double *dLAdu = NULL  ,
                        const double *dLSdu = NULL  ,
                        const double *dLAdv = NULL  ,
                        const double *dLSdv = NULL  ) ; 

//==================================================================
// Sets the modification polynomials by scaling factors at the ends,
// i.e. without considering any lengths.  
//==================================================================

void SetModPolByScales (double iScaleI, 
                        double iScaleII, 
                        double iDI_du  = 0.0, 
                        double iDII_du = 0.0 ) ;

//==================================================================
//  Evaluate the modification, ou, and its derivative, odu, at iu.
//==================================================================

  void evalModParam(const double iw,
                          double &ow     ,
                          double &odw    , 
                          double *owu = NULL ,
                          double *owv = NULL ) ; 
 

//=========================== PRIVATE ==============================
 private:

 CATLONG32    _MagnI,
              _MagnII,
              _Order,
              _isLinear ;
 double       _ScaleI,
              _ScaleII                  ; 
 double       _dScaleQuotIdu,
              _dScaleQuotIIdu    ;
 double       _dScaleQuotIdv,
              _dScaleQuotIIdv    ;
 double       _dCoeffIdu,
              _dCoeffIIdu            ; 
 double       _dCoeffIdv,
              _dCoeffIIdv            ; 
 double     * _FixPart,
            * _ModPartI,
            * _ModPartII,
            * _ModPolA,
            * _ModPolS ; 

//==================================================================
// Set primary ModPart & FixPart coefficients.
//==================================================================

  void SetPimaryCoeff () ;
  
//==================================================================
// Inverse evaluation of an increasing 
// polynomial: [0, 1] --> [0, 1]:
// The evaluation work for ix < 0 (or ix > 1) if also
// poly(ix) < ix (or poly(ix) > ix).
//==================================================================

double solvePoly (const double *poly, 
                  const CATLONG32   order, 
                  const double ix ) ;

//==================================================================
// Evaluates the modification differentiated with respect to 
// variable coefficients
//==================================================================

double DifferentiatedCoeff (const double  iw,
                            const double  idw,
                            const double  DCI,
                            const double  DCII ) ; 

};

//==================================================================
// Returns the evaluation of a 
// polynomial "poly" of order "order" in "ix": 
//================================================================== 

inline double evalPoly (const double *poly, 
                        const CATLONG32 order, 
                        const double ix ) 
{ 
   CATLONG32 i = order -1 ;
   double ox = poly[i] ;
   for ( i-- ; i > -1 ; i--) { ox *= ix ; ox += poly[i] ; }
   return ox ;
}

//==================================================================
// Returns the derivative of a 
// polynomial "poly" of order "order" in "ix": 
//==================================================================

inline double evalDiff (const double *poly, 
                        const CATLONG32 order, 
                        const double ix ) 
{ 
   CATLONG32 i = order -1 ;
   double dx = i * poly[i] ;
   for ( i-- ; i > 0 ; i-- ) { dx *= ix ; dx += i * poly[i] ; }
   return dx ;
}

#endif  

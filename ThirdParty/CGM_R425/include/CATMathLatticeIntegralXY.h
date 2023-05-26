// COPYRIGHT   : DASSAULT SYSTEMES 2009
//
//  15/07/18 JSX add CATMathCreateLatticeIntegralXY 
//  07/10/22 jsx add DBG_LatticeDATA
//  27/10/22 JSX add MinRank, for case that error estimation is too small
//  05/12/22 JSX add GetInfoAfterEval
#ifndef CATMathLatticeIntegralXY_H
#define CATMathLatticeIntegralXY_H

#include "YN000FUN.h"
#include "CATCGMVirtual.h"
#include "CATBoolean.h"
#include "CATMathVectorMass.h"
#include "CATListOfDouble.h"

class CATSoftwareConfiguration;
class CATMathFunctionX;
class CATMathVectorialFunctionXY;

//#define DBG_LatticeDATA  // require to save points of evaluation (should not be active in official code)

class ExportedByYN000FUN CATMathLatticeIntegralXY : public CATCGMVirtual
{
public:
#ifdef DBG_LatticeDATA
   CATMathLatticeIntegralXY() { _DBG_NbData = 0; };
#endif
   virtual ~CATMathLatticeIntegralXY(){};

   /// Set the maximum rank.
   /// Integrands will be evaluated 4^max rank times.
   ///
   /// @param[in] iRank
   /// @return Negative number upon error, 0 otherwise.
   virtual int SetMaxRank( int iRank ) = 0;

   /// Set the minima rank.
   /// Integrands will be evaluated 4^max rank times.
   ///
   /// @param[in] iRank
   /// @return Negative number upon error, 0 otherwise.
   virtual int SetMinRank(int iRank) = 0;

   /// Set the integration error tolerance
   ///
   /// @param[in] iTolerance Error tolerance value for each of the integrands
   /// @param[in] iRelativeError True if tolerance is specified as relative, false if it's absolute
   /// @return Negative number upon error, 0 otherwise.
   virtual int SetTolerance( const double *iTolerance,
                             CATBoolean iRelativeError ) = 0;

   /// Set the integration domain
   /// The integrals are currently computed as 
   /// \int_{x=iXStart}^{iXEnd} \int_{y=iYStart(x)}^{iYEnd(x)} f(x,y) dy dx
   ///
   /// @param[in] iXStart Lower integration bound for x
   /// @param[in] iXEnd Upper integration bound for x
   /// @param[in] iYStart Lower integration bound for y(x)
   /// @param[in] iYEnd Upper integration bound for y(x)
   /// @return Negative number upon error, 0 otherwise.
   virtual int SetIntegrationDomain( double iXStart,
                                     double iXEnd,
                                     double iYStart,
                                     double iYEnd ) = 0;
   virtual int SetIntegrationDomain( double iXStart,
                                     double iXEnd,
                                     double iYStart,
                                     const CATMathFunctionX *iYEnd ) = 0;
   virtual int SetIntegrationDomain( double iXStart,
                                     double iXEnd,
                                     const CATMathFunctionX *iYStart,
                                     double iYEnd ) = 0;
   virtual int SetIntegrationDomain( double iXStart,
                                     double iXEnd,
                                     const CATMathFunctionX *iYStart,
                                     const CATMathFunctionX *iYEnd ) = 0;

   /// Set a bound to the integration domain
   /// _YEnd will be bounded to the [YStart,YBound] or
   /// [YBound,YStart] interval.
   ///
   /// @param[in] iYBound the bound
   /// @return Negative number upon error, 0 otherwise.
   virtual int SetIntegrationDomainBound( double iYBound ) = 0;

   /// Evaluate the integrals
   ///
   /// @param[out] oResults The results
   /// @param[out] oErrors The errors (relative or absolute depending on the iRelativeError argument given to SetTolerance). Can be NULL.
   /// @return Negative number upon error, 0 otherwise.
   virtual int Eval( double *oResults, double *oErrors ) = 0;

   // Information after evaluation 
   // Only for Debug and Performance analysis

   virtual void GetInfoAfterEval(CATLONG32& oNbGridUsed, CATLONG32 &oRank, CATLONG32 &oSubRank) = 0;

public:
#ifdef DBG_LatticeDATA

   // Pour debug, mutable pour ecriture dans les methodes const
   mutable int _DBG_StoreData;
   mutable  CATListOfDouble _DBG_EvalData;
   mutable int _DBG_NbData;   // nombre d'enregistrement
   mutable int _DBG_Datasize; // taile d'un enregistrement
#endif
};

//
//
// Mode=0 : oldlatice
// mode=1 : newlatice
// mode 2 : latice computed by GPU
ExportedByYN000FUN CATMathLatticeIntegralXY * CATMathCreateLatticeIntegralXY( CATSoftwareConfiguration *iSoftwareConfiguration,
                                const CATMathVectorMass &iF ,
                                CATLONG32 Mode = 0 );
#endif

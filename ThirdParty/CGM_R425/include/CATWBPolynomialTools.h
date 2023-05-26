//===================================================================
//
// CATWBPolynomialTools.h
// Header definition of CATWBPolynomialTools
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//  Apr 2015  Creation                                 KJD
//===================================================================


#ifndef CATWBPolynomialTools_h
#define CATWBPolynomialTools_h


#include "CATWBExpression.h"
#include "CATWBFactory.h"
#include "WhiteBoxData.h"
class CATWBVariable;
class CATWBPolynomialUtilities;

/**
  * @brief The CATWBPolynomialTools class groups all the services for polynomials
  */

class  ExportedByWhiteBoxData CATWBPolynomialTools
{
public:
  CATWBPolynomialTools(CATWBFactory & iFactory);
  ~CATWBPolynomialTools();



  /**
  * @brief This method finds the coefficients  of a polynomial
  * @param[in] iExpr is the polynomial whose the coefficients mus be found.
  * @param[in] ipVariable  the variable of our polynomial 
  * @param[out] Coef  An empty list where the coefficients will be stored.
  * @return 
  */
  CATCDSBoolean FindCoeff(CATWBExpression * iExpr,CATWBVariable * ipVariable,CATCDSLISTP(CATWBExpression) &Coef);

 /**
  *@brief This method performs the euclidean division between two polynomial
  *@param[in] ipVariable is the variable of our polynomials. 
  *@param[in] iNumExpr is apolynomial, which is the dividend.
  *@param[in] iDenExpr is apolynomial, which is the divisor.
  *@param[out] Quot is an expression, which will be the quotient of our division
  *@param[out] Rest is an expression, which will be the rest of our division
  */
  CATCDSBoolean PolynomialDivision(CATWBVariable * ipVariable,CATWBExpression * iNumExpr ,CATWBExpression * iDenExpr,CATWBExpression *& Quot,CATWBExpression *& Rest);

  /**
  *@brief This method computes the greatest common divisor between two polynomials
  *@param[in] ipVariable is the variable of our polynomials.
  *@param[in] iExpr is a polynomial.
  *@param[in] iExpr1 is a polynomial.
  *@return an expression which is the greatest common divisor.
  */
  CATWBExpression * FindPgcd(CATWBVariable * ipVariable,CATWBExpression * iExpr, CATWBExpression * iExpr1);

  /**
  *@brief This method performs euclid's algorithm to find the expressions S and T such that S*A + T*B = C
  *@param[in] ipVariable is the variable of our polynomials.
  *@param[in] A is a polynomial.
  *@param[in] B is a polynomial.
  *@param[in] C is a polynomial
  *@param[out] S,T two polynomials which are the solutions.
  *@return 1 if the computation is well done , and 0 otherwise.
  */
  int SolveBezout(CATWBVariable * ipVariable,CATWBExpression * A ,CATWBExpression * B,CATWBExpression * C , CATWBExpression *& S, CATWBExpression *& T);

  /**
  *@brief This method performs the partial fraction decomposition
  if iListExpr = [E1, E2, E3,....., En] , this method finds the expressions [A0, A1, A2,......, An] such that iExpr/(E1*E2*....*En) =  A0 + A1/E1 +....+ An/En
  *@param[in] ipVariable is the variable of our polynomials.
  *@param[in] iExpr is a polynomial.
  *@param[in] iListExpr is a list of expressions.
  *@param[out] oListResult is the results list.
  *@return 1 if the computation is well done , and 0 otherwise.
  */
  int PartialFraction(CATWBVariable * ipVariable,CATWBExpression * iExpr ,CATCDSLISTP(CATWBExpression) iListExpr, CATCDSLISTP(CATWBExpression) & oListResult);

  /**
  *@brief This method performs a squarefree factorization of the expression iExpr. It finds the expressions [A0, A1, A2,......, An] such that iExpr =  A^1 * A2^2 *....* An^n
  *@param[in] ipVariable is the variable of our polynomials.
  *@param[in] iExpr is a polynomial.
  *@param[out] oListExpr is a empty list where the expressions will be stored.
  *@return 1 if the computation is well done , and 0 otherwise.
  */
  int SquareFree(CATWBVariable * ipVariable,CATWBExpression * iExpr ,CATCDSLISTP(CATWBExpression) & oListExpr);

  /**
  *@brief This method performs a Hermite Reduction. it takes two polynomials A and B (B coprime with A), returns G and H such that A/B = G' + H
  *@param[in] ipVariable is the variable of our polynomials.
  *@param[in] A is a polynomial.
  *@param[in] B is a polynomial.
  *@param[out] G,H two polynomials which are the solutions.
  *@return 1 if the computation is well done , and 0 otherwise.
  */
  int HermiteReduction(CATWBVariable * ipVariable,CATWBExpression * A ,CATWBExpression * B, CATWBExpression *& G, CATWBExpression *& H);

  int SubResultant(CATWBVariable * ipVariable,CATWBExpression * A ,CATWBExpression * B, CATCDSLISTP(CATWBExpression) & ioListExpr);

 
   /**
  *@brief This method finds the roots of polynomial iExpr. If the degre of our polynomial is bigger than 2, then oListExpr = [ DegreTropGrand ]
  *@param[in] ipVariable is the variable of our polynomial.
  *@param[in] iExpr is a polynomial.
  *@param[out] oListExpr is a empty list where the roots will be stored.
  *@return S_OK if the computation is well done
  */
 HRESULT FindRoots(CATWBVariable * ipVariable, CATWBExpression * iExpr, CATCDSLISTP(CATWBExpression) & oListExpr);

   /**
  *@brief This method simplifies the polynomial "iExpr" relative to the variable "ipVariable"
  *@param[in] ipVariable is the variable of our polynomial.
  *@param[in] iExpr is a polynomial.
  *@return an expression which is the result of the simplification of "Expr".
  */
  CATWBExpression * SimplifyPolynomial(CATWBVariable* ipVariable, CATWBExpression* iExpr);

private :
  CATWBFactory  & _factory;
  CATWBPolynomialUtilities * _PolTools;
};
#endif


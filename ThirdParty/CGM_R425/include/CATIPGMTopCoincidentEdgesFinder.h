// COPYRIGHT DASSAULT SYSTEMES 2017
//=============================================================================
//
// CATTopCoincidentEdgesFinder:
//		Operator used to find almost-coincident edges. 
//    
//
//=============================================================================
//
// Usage notes: 
//  Do not use GetResult(..) on this operator and please use 
//  the provided getters  ( GetXXX(..)).
//  This operator provide an empty journal.
//
//
//=============================================================================
//  June 2017  Creation													                          U29
//=============================================================================

#ifndef CATIPGMTopCoincidentEdgesFinder_h_
#define CATIPGMTopCoincidentEdgesFinder_h_

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopMultiResult.h"

class CATBody;
class CATExtTopCoincidentEdgesFinder;
class CATGeoFactory;
class CATListPtrCATBody;
class CATListPtrCATTopCoincidentEdges;
class CATTopCoincidentEdges;
class CATTopData;
class CATCGMProgressBar;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMTopCoincidentEdgesFinder;

class ExportedByCATGMOperatorsInterfaces CATIPGMTopCoincidentEdgesFinder : public CATIPGMTopMultiResult
{
public:
  /**
   * Constructor
   */
  CATIPGMTopCoincidentEdgesFinder();

  //-------------------------------------------------------
  //              Operator methods
  //-------------------------------------------------------
  /**
  * @See CATTopCoincidentEdges.h for more information
  *  @param oCoincidentEdges
  *    It's up to the caller to free the elements created inside this list.
  *  @return
  *    couples of coincident edges
  */
  virtual void GetCoincidenceData(CATListPtrCATTopCoincidentEdges &ioCoincidentEdges) = 0;

  /**
  * @See CATTopCoincidentEdges.h for more information
  *  @param iTol
  *    iTol To apply to find all the edges which can be merged.
  */
  virtual void SetTolerance(double iTol) = 0;

  /**
  * Set the parent progress bar
  *  @param ipParentProgressBar
  *  @param iStartPercentage
  *    The start percentage on the parent progress bar. By default it is set to 0.
  *  @param iEndPercentage
  *    The end percentage on the parent progress bar. By default it is set to 100.
  *
  */
  virtual void SetParentProgressBar(
    CATCGMProgressBar *ipParentProgressBar,
    const double iStartPercentage = 0.0,
    const double iEndPercentage = 100.0) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMTopCoincidentEdgesFinder(); // -> delete can't be called
};

/**
* External method that creates an instance of CATIPGMTopCoincidentEdgesFinder.
* This CoincidentEdgesFinder creation is correlated to operator CATTopBoundaryHomogenize
*   @param ipFactory
*     the pointer to the factory of the geometry.
*   @param ipTopdata
*     the pointer to the data defining the software configuration and the journal.
*     If the journal inside the configuration is <tt>NULL</tt>, it is not filled.
*   @param ipGlobalBody
*     input body (global shell).
*   @param iBodies
*     N shells generated by the splitting of the original body.
*   @param iEOPBodies
*     N shells containing the confusions with the boundaries of iBodies to be ignored. (EOP = Edge Of Part)
*   @param iTol
*     tolerance to consider two curves as "almost-coincident".
*/

ExportedByCATGMOperatorsInterfaces CATIPGMTopCoincidentEdgesFinder *CATPGMCreateTopCoincidentEdgesFinder(
  CATGeoFactory *ipFactory,
  CATTopData *ipTopdata,
  CATBody *ipGlobalBody,
  const CATLISTP(CATBody) &iBodies,
  const CATLISTP(CATBody) &iEOPBodies,
  double iTol);

/**
* External method that creates an instance of CATIPGMTopCoincidentEdgesFinder.
* this call is done to prepare a future HybAssemble operator
*   @param ipFactory
*     the pointer to the factory of the geometry.
*   @param ipTopdata
*     the pointer to the data defining the software configuration and the journal.
*     If the journal inside the configuration is <tt>NULL</tt>, it is not filled.
*   @param iBodies
*     N shells generated by the splitting of the original body.
*/
ExportedByCATGMOperatorsInterfaces CATIPGMTopCoincidentEdgesFinder* CATPGMCreateTopCoincidentEdgesFinder(
  CATGeoFactory* ipFactory,
  CATTopData* ipTopdata,
  const CATLISTP(CATBody)& iBodies);

#endif /* CATIPGMTopCoincidentEdgesFinder_h_ */
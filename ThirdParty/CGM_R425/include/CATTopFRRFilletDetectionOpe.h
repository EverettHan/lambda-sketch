#ifndef CATTopFRRFilletDetectionOpe_h
#define CATTopFRRFilletDetectionOpe_h

//=============================================================================
// Copyright Dassault Systemes Provence 2008, all rights reserved
//=============================================================================



#include "FrFTopologicalOpe.h"
#include "CATTopOperator.h"
#include "ListPOfCATBody.h"
class CATMathInterval;
 /**
 * Class defining the operator that detects Fillet in a Body for Fillet Radius Reduction.
 * <br>
 * This operator follows the general scheme of the topological operators. User should:
 * <ul>
 *<li> Create the operator with the <tt>CATCreateTopFRRFilletDetectionOpe</tt>
 * global function, which defines the shell to treat.
 *<li> Run the operator with the <tt>Run</tt> method. In case of any failing treatment, the <tt>Run</tt>
 * method returns an integer error status different from 0:
 *

 *</ul>
 */ 
class ExportedByFrFTopologicalOpe CATTopFRRFilletDetectionOpe : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopFRRFilletDetectionOpe);
public:
  //-------------------------------------------------------------------

  /**
  * Do not use. 
  * Constructor.
  * Use <tt>CATCreateTopFRRRailsExtractorOpe</tt> to create a
  * <tt>CATTopFRRFilletDetectionOpe</tt> operator.
  */
  CATTopFRRFilletDetectionOpe(CATGeoFactory *iFactory,
                                            CATTopData    *iTopData,
                                            CATBody       *iShellBody);
  
  virtual ~CATTopFRRFilletDetectionOpe();

 /** 
  * Set Intervals of available radius
  *
  * <br><b>/If a Face is Recongnized as a Fillet an have a Fillet Radius R that is in the interval i
  * Than the Face will be Append in the returned Array of List of Face [i];
  * If no interval are specified than the array contains all Face Fillet and have only one element [0]</b>
  *
  * @param iNbInterval [in]
  *   The Number Of Intervals...
  * @param iArrayOfInterval [in]
  *   The Array of intervals...
  *
  */
  virtual void SetIntervals(int iNbInterval, const CATMathInterval * iArrayOfInterval) = 0;

  
  /** 
  * Get The found fillet as a list of face
  *
  * @param oNbInterval [out]
  *   The Dimension of the returned array...
  *
  * @return
  *   array (same dimension of the Input Intervals) of List of cell (CATFace s)that are considered as Fillets
  *
  */
  virtual CATLISTP(CATCell) * GetFilletFaces(int & oNbInterval) = 0;


  /** 
  * Get The found fillet as MULTI-DOMAIN bodies
  *
  *
  * @param iSeparation [in] [!!!Experimental!!!!]
  * If TRUE divide the resulting search fillet into two parts (fillets in curvature opposition)
  * IF FALSE (Normal Behavior) 
  * @param oNbInterval [out]
  *   The parameter role...
  *
  * @return
  *   an array  of Size oNbInterval of a List of Bodies (1 Body in List if iSeparation=FALSE)
  * !!!! Each Body can have several Domains
  * (contiguous Fillets are automatically federated in one Domain)
  *
  */
  virtual ListPOfCATBody * GetBodies(CATBoolean iSeparation,int & oNbInterval) = 0;

   /**
  * Force the operator to compute a Radius (and Detection) even if the surface (Fillet,Cylinder) can give the exact radius
  */
  virtual void SetNoUseOfNativeSurfaceType() = 0;

};


ExportedByFrFTopologicalOpe CATTopFRRFilletDetectionOpe * 
CATCreateTopFilletDetectionOpe(CATGeoFactory *iFactory,
                                            CATTopData    *iTopData,
                                            CATBody       *iShellBody);


#endif

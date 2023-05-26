#ifndef CATDynIntersectionCrvBody_H_
#define CATDynIntersectionCrvBody_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATDynOperator.h"
#include "CATMathDef.h"

class CATTopData;
class CATBody;
class CATCurve;
class CATCrvParam;

/**
 * Do not use.
 * Interface representing a topological operation of intersection of a CATCurve
 * with a CATBody.
 * As all the topological operators, the input body and geometry are not modified.
 * Notice that this operator does not create a new resulting CATBody.
 * It only creates geometrial points, that can be scans with an iterator.
 */
class ExportedByBODYNOPE CATDynIntersectionCrvBody : public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynIntersectionCrvBody);
 public:
/**
 * Virtual constructor of a CATDynIntersectionCrvBody operator.<br>
 * Can never be called. Use the <tt>CATDynIntersectionCrvBody</tt> global function
 * to create a CATDynIntersectionCrvBody operator.
 */
  CATDynIntersectionCrvBody(CATGeoFactory     * iFactory,  
                            CATCGMJournalList * iJournal = NULL);

  CATDynIntersectionCrvBody(CATGeoFactory     * iFactory,  
                            CATTopData        * iData);

  virtual ~CATDynIntersectionCrvBody();

/**
 * Initializes the iterator of the geometrical points,
 * resulting from a CATDynIntersectionCrvBody operator.
 *<br>By default, the initialization is performed once the operator has been
 * calculated, and is therefore only used to read the solutions again.
 */
  virtual void Beginning() = 0;
/**
 * Points to the next point, resulting from a CATDynIntersectionCrvBody operator.
 *<br>Called just after the <tt>Beginning</tt> method, it points to the first point.
 * @return
 *<dl><dt><tt>1</tt> <dd>if there is still a point that is solution.
 *    <dt><tt>0</tt> <dd>otherwise.</dl>
 */
  virtual CATBoolean NextSolution() = 0;
  
/**
 * Retrieves, as a CATCrvParam, the next geometrical point
 * solution of a CATIntersectionCrvBody operator.
 *<br>Creates the object if necessary.
 */
   virtual void GetSolution(CATCrvParam& oSolution) = 0;
};


// Creation EntryPoints
/**
 * Creates a CATDynIntersectionCrvBody operator.
 * @param iForResultingBody
 * Where to create the resulting CATBody. For the moment, this body
 * is not created. Only geometrical points are created.
 * @param iPart
 * The CATBody to intersect.
 * @param iCurve
 * The CATCurve intersecting <tt>iBody</tt>.  
 * @param journal
 * A pointer to the topological journal. If NULL, no line will be writen.
 */
//cbk-ri0296310A-debut
ExportedByBODYNOPE CATDynIntersectionCrvBody* CATCreateDynIntersectionCrvBody(CATGeoFactory     * iFactory,
                                                                              CATTopData        * iData,
									      CATCurve          * iCurve,
     	                                                                      CATBody           * iPart);
////////////////cbk-ri0296310A-fin
ExportedByBODYNOPE CATDynIntersectionCrvBody* CATDynCreateIntersectionCrvBody(CATGeoFactory     * iFactory,
										                                                CATCurve          * iCurve,
										                                                CATBody           * iPart,
										                                                CATCGMJournalList * iJournal = NULL);

ExportedByBODYNOPE CATDynIntersectionCrvBody* CATDynCreateIntersectionCrvBody(CATGeoFactory     * iFactory,
                                                                              CATTopData        * iData,
										                                                CATCurve          * iCurve,
										                                                CATBody           * iPart);

#endif

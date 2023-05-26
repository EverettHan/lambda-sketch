#ifndef CATDynIntersectionSurBody_H_
#define CATDynIntersectionSurBody_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATDynOperator.h"
#include "CATMathDef.h"

class CATBody;
class CATSurface;
class CATPCurve;

/**
 * Do not use.
 * Interface representing a topological operation of intersection of a CATSurface
 * with a CATBody.
 * As all the topological operators, the input body and geometry are not modified. 
 * The resulting body is
 * a new one, that you can get by using the <tt>CATDynOperator::GetResult</tt> method.<br>
 * The resulting body contains edges, and methods are given to directly scan
 * the geometry attached to these edges.
 */
class ExportedByBODYNOPE CATDynIntersectionSurBody : public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynIntersectionSurBody);
 public:
	 /**
 * Virtual constructor of a CATDynIntersectionSurBody operator.<br>
 * Can never be called. Use the <tt>CATDynIntersectionSurBody</tt> global function
 * to create a CATDynIntersectionSurBody operator.
 */
  CATDynIntersectionSurBody(CATGeoFactory     * iFactory,
                            CATCGMJournalList * iJournal = NULL);

  CATDynIntersectionSurBody(CATGeoFactory     * iFactory,
                            CATTopData        * iData);

  virtual ~CATDynIntersectionSurBody();


/**
 * Initializes the iterator of the geometrical curves,
 * corresponding to edges of the resulting 
 * body from a CATDynIntersectionSurBody operator.
 *<br>By default, the initialization is performed once the operator has been
 * calculated, and is therefore only used to read the solutions again.
 */
   virtual void BeginningPCurve() = 0;

/**
 * Points to the next CATPCurve, corresponding to an edge of the resulting 
 * body from a CATDynIntersectionSurBody operator.
 *<br>Called just after the <tt>Beginning</tt> method, it points to the first curve.
 * @return
 *<dl><dt><tt>1</tt> <dd>if there is still a curve that is solution.
 *    <dt><tt>0</tt> <dd>otherwise.</dl>
 */ 
   virtual CATBoolean NextPCurve() = 0;
/**
 * Retrieves the next geometrical CATPCurve corresponding to an
 * edge, solution of a CATIntersectionSurBody operator.
  *<br>Creates the object if necessary.
 */
   virtual CATPCurve * GetPCurve() = 0;
};


// Creation EntryPoints
/**
 * Creates a CATDynIntersectionSurBody operator.
 * @param iForResultingBody
 * Where to create the resulting CATBody. 
 * @param iPart
 * The CATBody to intersect.
 * @param iSurface
 * The CATSurface intersecting <tt>iBody</tt>.  
 * @param journal
 * A pointer to the topological journal. If NULL, no line will be writen.
 */
//cbk-ri0296310A-debut
ExportedByBODYNOPE CATDynIntersectionSurBody* CATCreateDynIntersectionSurBody(CATGeoFactory     * iFactory,
                                                                              CATTopData        * iData,
									      CATSurface        * iSurface,
                                                                              CATBody           * iPart);
////////////////cbk-ri0296310A-fin
ExportedByBODYNOPE CATDynIntersectionSurBody* CATDynCreateIntersectionSurBody(CATGeoFactory     * iFactory,
									                                                   CATSurface        * iSurface,
									                                                   CATBody           * iPart,
									                                                   CATCGMJournalList * iJournal = NULL);


ExportedByBODYNOPE CATDynIntersectionSurBody* CATDynCreateIntersectionSurBody(CATGeoFactory     * iFactory,
                                                                              CATTopData        * iData,
									                                                   CATSurface        * iSurface,
									                                                   CATBody           * iPart);

#endif



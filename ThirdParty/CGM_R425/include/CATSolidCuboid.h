#ifndef CATSolidCuboid_h
#define CATSolidCuboid_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATSolidPrimitive.h"
#include "Primitives.h"

class CATMathPoint;
class CATTopData;

/**
 * Class defining the operator to create a topological cube.
 * <br><tt>CATSolidCuboid</tt> follows the global frame of the topological operators.
 *<ul>
 * <li>Create it with the <tt>CATCreateSolidCuboid</tt> global function
 * <li>Run it 
 * <li>Get the result
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.
 *</ul>
 */
class ExportedByPrimitives CATSolidCuboid : public CATSolidPrimitive
{
  CATCGMVirtualDeclareClass(CATSolidCuboid);
 public:
/**
 * @nodoc
 * Constructs an operator that creates a topological cube.
 *<pre>              ________
 *        iPt4 /        /| 
 *            /        / |
 *           /  |     /  |
 *          /________/   |
 *          |   |    |   |
 *          |        |   |
 *          |   |    |   | iPt3
 *          |iPt1-  -! - /
 *          |  /     |  /
 *          |        | /
 *     iPt2 |/       |/
 *          |________|  </pre>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled. 
 * @param iPt1
 * The origin of the cube.
 * @param iPt2
 * The limitation in the first direction.
 * @param iPt3
 * The limitation in the second direction.
 * @param iPt4
 * The limitation in the third direction.
 */
   CATSolidCuboid(CATGeoFactory* iFactory, CATTopData *iData,
                  const CATMathPoint& iPt1, const CATMathPoint& iPt2, 
                  const CATMathPoint& iPt3, const CATMathPoint& iPt4);

/**
 * @nodoc
 * Deprecated. Use now the signature with CATTopData.
 * Constructs an operator that creates a topological cube.
 *<pre>              ________
 *        iPt4 /        /| 
 *            /        / |
 *           /  |     /  |
 *          /________/   |
 *          |   |    |   |
 *          |        |   |
 *          |   |    |   | iPt3
 *          |iPt1-  -! - /
 *          |  /     |  /
 *          |        | /
 *     iPt2 |/       |/
 *          |________|  </pre>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iPt1
 * The origin of the cube.
 * @param iPt2
 * The limitation in the first direction.
 * @param iPt3
 * The limitation in the second direction.
 * @param iPt4
 * The limitation in the third direction.
 * @param iReport
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 */
   CATSolidCuboid(CATGeoFactory* iFactory, 
                  const CATMathPoint& iPt1, const CATMathPoint& iPt2, 
                  const CATMathPoint& iPt3, const CATMathPoint& iPt4,
									 CATCGMJournalList *iReport=NULL );
};

//--------------------------------------------------------------------------
/**
 * Constructs an operator that creates a topological cube.
 * The Run method must be used.
 *<pre>              ________
 *        iPt4 /        /| 
 *            /        / |
 *           /  |     /  |
 *          /________/   |
 *          |   |    |   |
 *          |        |   |
 *          |   |    |   | iPt3
 *          |iPt1-  -! - /
 *          |  /     |  /
 *          |        | /
 *     iPt2 |/       |/
 *          |________|  </pre>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled. 
 * @param iPt1
 * The origin of the cube.
 * @param iPt2
 * The limitation in the first direction.
 * @param iPt3
 * The limitation in the second direction.
 * @param iPt4
 * The limitation in the third direction.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByPrimitives CATSolidCuboid * CATTopCreateSolidCuboid (CATGeoFactory      *iFactory,
                                                            CATTopData         *iData,
                                                            const CATMathPoint &iPt1,
                                                            const CATMathPoint &iPt2,
                                                            const CATMathPoint &iPt3,
                                                            const CATMathPoint &iPt4);

//--------------------------------------------------------------------------
/**
 * @deprecated R211 CATTopCreateSolidCuboid
 * Constructs an operator that creates a topological cube.
 *<pre>              ________
 *        iPt4 /        /| 
 *            /        / |
 *           /  |     /  |
 *          /________/   |
 *          |   |    |   |
 *          |        |   |
 *          |   |    |   | iPt3
 *          |iPt1-  -! - /
 *          |  /     |  /
 *          |        | /
 *     iPt2 |/       |/
 *          |________|  </pre>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled. 
 * @param iPt1
 * The origin of the cube.
 * @param iPt2
 * The limitation in the first direction.
 * @param iPt3
 * The limitation in the second direction.
 * @param iPt4
 * The limitation in the third direction.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByPrimitives CATSolidCuboid * CATCreateSolidCuboid (CATGeoFactory      *iFactory,
                                                            CATTopData         *iData,
                                                            const CATMathPoint &iPt1,
                                                            const CATMathPoint &iPt2,
                                                            const CATMathPoint &iPt3,
                                                            const CATMathPoint &iPt4);

#endif

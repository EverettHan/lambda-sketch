#ifndef CATSolidTorus_h
#define CATSolidTorus_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "Primitives.h"
#include "CATSolidPrimitive.h"

class CATMathPoint;
class CATMathAxis;
class CATMathDirection;
class CATTopData;

/**
 * Class defining the operator to create a topological torus.
 * <br><tt>CATSolidTorus</tt> follows the global frame of the topological operators.
 *<ul>
 * <li>Create it with the <tt>CATCreateSolidTorus</tt> global function 
 * <li>Run it 
 * <li>Get the result
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.
 *</ul>
 */
class ExportedByPrimitives CATSolidTorus : public CATSolidPrimitive
{
  CATCGMVirtualDeclareClass(CATSolidTorus);
 public:
/**
 * @nodoc
 * Constructs an operator that creates a topological torus.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data containing the software configuration and the journal.
 * @param iAxis
 * The axes system of the torus.
 * @param iMajor
 * The point defining the major ring, such that its distance to the third direction of <tt>iAxis</tt> is the radius
 * of the major ring.
 * @param iMinor
 * The point defining the minor ring, such that its distance to <tt>iMajor</tt> is the radius
 * of the minor ring.
 */ 
   CATSolidTorus(CATGeoFactory* iFactory, CATTopData *iData,
		 const CATMathAxis&, const CATMathPoint&, const CATMathPoint&);

/**
 * @nodoc
 * Constructs an operator that creates a topological torus.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iAxis
 * The axes system of the torus.
 * @param iMajor
 * The point defining the major ring, such that its distance to the third direction of <tt>iAxis</tt> is the radius
 * of the major ring.
 * @param iMinor
 * The point defining the minor ring, such that its distance to <tt>iMajor</tt> is the radius
 * of the minor ring.
 * @param iReport
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 */ 
   CATSolidTorus(CATGeoFactory* iFactory, 
		 const CATMathAxis&, const CATMathPoint&, const CATMathPoint&,
		 CATCGMJournalList *iReport=NULL );
};

//------------------------------------------------------------------------
/**
 * Constructs an operator that creates a topological torus.
 * The Run method must be used to generate a result.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iAxis
 * The axes system of the torus.
 * @param iMajor
 * The point defining the major ring, such that its distance to the third direction of <tt>iAxis</tt> is the radius
 * of the major ring.
 * @param iMinor
 * The point defining the minor ring, such that its distance to <tt>iMajor</tt> is the radius
 * of the minor ring.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitives CATSolidTorus * CATTopCreateSolidTorus(CATGeoFactory* iFactory, CATTopData *iData,
                                                         const CATMathAxis& iAxis,
                                                         const CATMathPoint& iMajor,
                                                         const CATMathPoint& iMinor);
//------------------------------------------------------------------------
/**
 * @deprecated R211 CATTopCreateSolidTorus
 * Constructs an operator that creates a topological torus.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iAxis
 * The axes system of the torus.
 * @param iMajor
 * The point defining the major ring, such that its distance to the third direction of <tt>iAxis</tt> is the radius
 * of the major ring.
 * @param iMinor
 * The point defining the minor ring, such that its distance to <tt>iMajor</tt> is the radius
 * of the minor ring.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitives CATSolidTorus * CATCreateSolidTorus(CATGeoFactory* iFactory, CATTopData *iData,
                                                         const CATMathAxis& iAxis,
                                                         const CATMathPoint& iMajor,
                                                         const CATMathPoint& iMinor);


#endif

#ifndef CATSolidCylinder_h
#define CATSolidCylinder_h

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
 * Class defining the operator to create a topological cylinder.
 * <br><tt>CATSolidCylinder</tt> follows the global frame of the topological operators.
 *<ul>
 * <li>Create it with the <tt>CATCreateSolidCylinder</tt> global function 
 * <li>Run it 
 * <li>Get the result
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.
 *</ul>
 */
class ExportedByPrimitives CATSolidCylinder : public CATSolidPrimitive
{
  CATCGMVirtualDeclareClass(CATSolidCylinder);
 public:
/**
 *@nodoc
 *  Constructs an operator that creates a topological cube.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iPointOnSurface
 * A point belonging to the boundary of the cylinder (to define the radius).
 */
  CATSolidCylinder(CATGeoFactory* iFactory, CATTopData * iData,
		   const CATMathPoint & iFirstPointOnAxis, 
                   const CATMathPoint & iSecondPointOnAxis, 
                   const CATMathPoint & iPointOnSurface);

/**
 *@nodoc
 *  Constructs an operator that creates a topological cube.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iRadius
 * The radius value.
 */
  CATSolidCylinder(CATGeoFactory* iFactory, CATTopData *iData,
		   const CATMathPoint & iFirstPointOnAxis, 
                   const CATMathPoint & iSecondPointOnAxis, 
                   double iRadius);

/**
 *@nodoc
 *  Constructs an operator that creates a topological cube.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iPointOnSurface
 * A point belonging to the boundary of the cylinder (to define the radius).
 * @param iReport
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 */
  CATSolidCylinder(CATGeoFactory* iFactory, 
		   const CATMathPoint & iFirstPointOnAxis, 
                   const CATMathPoint & iSecondPointOnAxis, 
                   const CATMathPoint & iPointOnSurface,
		   CATCGMJournalList *iReport=NULL );

/**
 *@nodoc
 *  Constructs an operator that creates a topological cube.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iRadius
 * The radius value.
 * @param iReport
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 */
  CATSolidCylinder(CATGeoFactory*, 
		   const CATMathPoint & iFirstPointOnAxis, 
                   const CATMathPoint & iSecondPointOnAxis, 
                   double iRadius,
		   CATCGMJournalList *iReport=NULL );
  
 protected:
	 /** @nodoc */
   void SetUp(const CATMathPoint&, const CATMathPoint&, double);
};

//---------------------------------------------------------------
/**
 *  Constructs an operator that creates a topological cylinder.
 * The Run method must be used to generate a result.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iPointOnSurface
 * A point belonging to the boundary of the cylinder (to define the radius).
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByPrimitives CATSolidCylinder * CATTopCreateSolidCylinder(CATGeoFactory* iFactory, CATTopData *iData,
                                                               const CATMathPoint & iFirstPointOnAxis, 
                                                               const CATMathPoint & iSecondPointOnAxis, 
                                                               const CATMathPoint & iPointOnSurface);

/**
 *  Constructs an operator that creates a topological cylinder.
 * The Run method must be used to generate a result.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iRadius
 * The radius value.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByPrimitives CATSolidCylinder * CATTopCreateSolidCylinder(CATGeoFactory* iFactory, CATTopData *iData,
                                                               const CATMathPoint & iFirstPointOnAxis, 
                                                               const CATMathPoint & iSecondPointOnAxis, 
                                                               double iRadius);
//---------------------------------------------------------------
/**
 * @deprecated R211 CATTopCreateSolidCylinder
 *  Constructs an operator that creates a topological cylinder.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iPointOnSurface
 * A point belonging to the boundary of the cylinder (to define the radius).
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByPrimitives CATSolidCylinder * CATCreateSolidCylinder(CATGeoFactory* iFactory, CATTopData *iData,
                                                               const CATMathPoint & iFirstPointOnAxis, 
                                                               const CATMathPoint & iSecondPointOnAxis, 
                                                               const CATMathPoint & iPointOnSurface);

/**
 * @deprecated R211 CATTopCreateSolidCylinder
 *  Constructs an operator that creates a topological cylinder.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iFirstPointOnAxis
 * The first limit of the axis.
 * @param iSecondPointOnAxis
 * The second limit of the axis.
 * @param iRadius
 * The radius value.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByPrimitives CATSolidCylinder * CATCreateSolidCylinder(CATGeoFactory* iFactory, CATTopData *iData,
                                                               const CATMathPoint & iFirstPointOnAxis, 
                                                               const CATMathPoint & iSecondPointOnAxis, 
                                                               double iRadius);

#endif

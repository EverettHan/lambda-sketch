#ifndef CATSolidSphere_h
#define CATSolidSphere_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "PrimitivesLight.h"
#include "CATSolidPrimitive.h"

class CATTopData;
class CATMathPoint;

/**
 * Class defining the operator to create a topological sphere.
 * <br><tt>CATSolidSphere</tt> follows the global frame of the topological operators.
 *<ul>
 * <li>Create it with the <tt>CATCreateSolidSphere</tt> global function 
 * <li>Run it 
 * <li>Get the result
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.
 *</ul>
 */
class ExportedByPrimitivesLight CATSolidSphere : public CATSolidPrimitive
{
  CATCGMVirtualDeclareClass(CATSolidSphere);
 public:
/**
 * @nodoc
 * Constructs an operator that creates a topological sphere.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data containing the software configuration and the journal.
 * @param iCenter
 * The center of the sphere.
 * @param iRadius
 * The radius of the sphere.
 */ 
   CATSolidSphere(CATGeoFactory * iFactory, CATTopData * iData, const CATMathPoint& iCenter, double iRadius);

/**
 * @nodoc
 * Constructs an operator that creates a topological sphere.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iCenter
 * The center of the sphere.
 * @param iRadius
 * The radius of the sphere.
 * @param iReport
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 */ 
   CATSolidSphere(CATGeoFactory* iFactory, const CATMathPoint& iCenter, double iRadius,CATCGMJournalList *iReport=NULL );
};

//--------------------------------------------------------------------------
/**
 * Constructs an operator that creates a topological sphere.
 * The run method must be used.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iCenter
 * The center of the sphere.
 * @param iRadius
 * The radius of the sphere.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitivesLight CATSolidSphere * CATTopCreateSolidSphere(CATGeoFactory      *iFactory,
                                                           CATTopData         *iData,
                                                           const CATMathPoint &iCenter,
                                                           double              iRadius);
//--------------------------------------------------------------------------
/**
 * @deprecated R211 CATTopCreateSolidSphere
 * Constructs an operator that creates a topological sphere.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iCenter
 * The center of the sphere.
 * @param iRadius
 * The radius of the sphere.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitivesLight CATSolidSphere * CATCreateSolidSphere(CATGeoFactory      *iFactory,
                                                           CATTopData         *iData,
                                                           const CATMathPoint &iCenter,
                                                           double              iRadius);

#endif

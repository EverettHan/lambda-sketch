#ifndef CATSolidPyramid_h
#define CATSolidPyramid_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATSolidPrimitive.h"
#include "Primitives.h"

class CATMathPoint;
class CATFace;
class CATLoop;
class CATSurParam;
class CATTopData;

/**
 * Class defining the operator to create a topological pyramid.
 * <br><tt>CATSolidPyramid</tt> follows the global frame of the topological operators.
 *<ul>
 * <li>Create it with the <tt>CATCreateSolidPyramid</tt> global function 
 * <li>Run it 
 * <li>Get the result
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.
 *</ul>
 */
class ExportedByPrimitives CATSolidPyramid : public CATSolidPrimitive
{
  CATCGMVirtualDeclareClass(CATSolidPyramid);
public:
/**
 * @nodoc
 * Constructs an operator that creates a topological pyramid.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data containing the software configuration and the journal.
 * @param iPt1
 * The first point of the base.
 * @param iPt2
 * The second point of the base.
 * @param iPt3
 * The third point of the base.
 * @param iTop
 * The point defining the top of the pyramid.
 */ 
  CATSolidPyramid(CATGeoFactory* iFactory, CATTopData *iData,
		  const CATMathPoint& iPt1, const CATMathPoint& iPt2, 
		  const CATMathPoint& iPt3, const CATMathPoint& iTop);

/**
 * @nodoc
 * Constructs an operator that creates a topological pyramid.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data containing the software configuration and the journal.
 * @param iBase
 * The pointer to the face defining the base of the pyramid.
 * @param iTop
 * The point defining the top of the pyramid.
 */ 
  CATSolidPyramid(CATGeoFactory* iFactory, CATTopData *iData,
		  CATFace* iBase, const CATMathPoint& iTop);

/**
 * @nodoc
 * Constructs an operator that creates a topological pyramid.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iPt1
 * The first point of the base.
 * @param iPt2
 * The second point of the base.
 * @param iPt3
 * The third point of the base.
 * @param iTop
 * The point defining the top of the pyramid.
 * @param iReport
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 */ 
  CATSolidPyramid(CATGeoFactory* iFactory, 
		  const CATMathPoint& iPt1, const CATMathPoint& iPt2, 
		  const CATMathPoint& iPt3, const CATMathPoint& iTop,
		  CATCGMJournalList *iReport=NULL );

 /**
  * @nodoc
 * Constructs an operator that creates a topological pyramid.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iBase
 * The pointer to the face defining the base of the pyramid.
 * @param iTop
 * The point defining the top of the pyramid.
 * @param iReport
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 */ 
  CATSolidPyramid(CATGeoFactory* iFactory, 
		  CATFace* iBase, const CATMathPoint& iTop,
		  CATCGMJournalList *iReport=NULL );
  
private:
  void InternalBuild(CATFace*, const CATMathPoint&);
  CATLoop* CreateLoop(CATFace* aFace, CATSurParam* localParams , int nbParams);
  
};

//---------------------------------------------------------------
/**
 * Constructs an operator that creates a topological pyramid.
 * The Run method must be used to generate a result.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iPt1
 * The first point of the base.
 * @param iPt2
 * The second point of the base.
 * @param iPt3
 * The third point of the base.
 * @param iTop
 * The point defining the top of the pyramid.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitives CATSolidPyramid * CATTopCreateSolidPyramid(CATGeoFactory* iFactory, CATTopData *iData,
                                                             const CATMathPoint& iPt1, const CATMathPoint& iPt2, 
                                                             const CATMathPoint& iPt3, const CATMathPoint& iTop);

/**
 * Constructs an operator that creates a topological pyramid.
 * The Run method must be used to generate a result.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iBase
 * The pointer to the face defining the base of the pyramid.
 * @param iTop
 * The point defining the top of the pyramid.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitives CATSolidPyramid * CATTopCreateSolidPyramid(CATGeoFactory* iFactory, CATTopData *iData,
                                                             CATFace* iBase, const CATMathPoint& iTop);

//---------------------------------------------------------------
/**
 * @deprecated R211 CATTopCreateSolidPyramid
 * Constructs an operator that creates a topological pyramid.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iPt1
 * The first point of the base.
 * @param iPt2
 * The second point of the base.
 * @param iPt3
 * The third point of the base.
 * @param iTop
 * The point defining the top of the pyramid.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitives CATSolidPyramid * CATCreateSolidPyramid(CATGeoFactory* iFactory, CATTopData *iData,
                                                             const CATMathPoint& iPt1, const CATMathPoint& iPt2, 
                                                             const CATMathPoint& iPt3, const CATMathPoint& iTop);

/**
 * @deprecated R211 CATTopCreateSolidPyramid
 * Constructs an operator that creates a topological pyramid.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iBase
 * The pointer to the face defining the base of the pyramid.
 * @param iTop
 * The point defining the top of the pyramid.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */ 
ExportedByPrimitives CATSolidPyramid * CATCreateSolidPyramid(CATGeoFactory* iFactory, CATTopData *iData,
                                                             CATFace* iBase, const CATMathPoint& iTop);

#endif

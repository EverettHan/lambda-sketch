#ifndef CATTopVertex_h
#define CATTopVertex_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATGeoToTopOperator.h"

class CATDomain;
class CATVertex;
class CATLoop;
class CATVertex;
class CATPoint;
class CATSurface;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;

/** 
* Class representing the operator that creates a point body from one point. 
* <br>To use the CATTopVertex:
* <ul><li>Create it with the <tt>CATCreateTopVertex</tt> global function. 
* <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods.
* <li> <tt>Run</tt> the operator
* <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
* <li>Delete with the usual C++ <tt>delete</tt> operator after use.
* </ul>
*/

class ExportedByPrimitivesLight CATTopVertex :public CATGeoToTopOperator
{
  CATCGMVirtualDeclareClass(CATTopVertex);
public:
/**
 * @nodoc
 */
	CATTopVertex(CATGeoFactory      *iFactory,
		CATTopData         * iData
#ifdef CATIACGMR214CAA
    , CATExtTopOperator *iExtensible = NULL
#endif      
    );

/**
 * @nodoc
 */	
	CATTopVertex(CATGeoFactory      *iFactory, 
		CATBody            *iBodyForCellCreation,
		CATBodyFreezeMode   iBodyFreezeMode=CATBodyFreezeOn,
		CATCGMJournalList  *iReport=NULL
#ifdef CATIACGMR214CAA
    , CATExtTopOperator *iExtensible = NULL
#endif      
    );
  
  ~CATTopVertex();

/**
 * Runs <tt>this</tt> operator.
 */
  virtual int Run()=0;

 /**
 * Returns the pointer to the vertex of the resulting point body.
 * @return
 * The pointer to the vertex of the resulting point body. Remember that the whole body is retrieved with
 * the <tt>GetResult</tt> method, and you must manage its deletion if you do not want to keep it.
 */
  virtual CATVertex*     GetVertex() const=0;
 
  
};

/**
 * Creates an operator to build a point body from one point.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iPoint
 * The pointer to the point used to define the vertex.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */
ExportedByPrimitivesLight CATTopVertex * CATCreateTopVertex(CATGeoFactory*	iFactory,
                                                       CATTopData * iData,
                                                       CATPoint*	    	iPoint);
/** @nodoc */
ExportedByPrimitivesLight CATBody * CATCreateVertex(CATGeoFactory*	iFactory,
                                               CATTopData * iData,
                                               CATPoint*	    	iPoint);


#endif

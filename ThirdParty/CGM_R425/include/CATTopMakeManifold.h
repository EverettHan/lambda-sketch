#ifndef CATTopMakeManifold_H
#define CATTopMakeManifold_H

// COPYRIGHT DASSAULT SYSTEMES  2001

#include "BOTOPOPE.h"
#include "CATTopOperator.h"

/**
 * Class representing the topological operator that transform a non manifold body 
 * into a manifold a body.
 * Definition :
 * - In a non manifold body , a edge can be bound by more than two faces.
 * - In a manifold body , a edge can not bound by more than two two faces.
 * To use it :
 * - Create it with the CATCreateTopMakeManifold global function.
 * - Run it
 * - Get the resulting body with the GetResult method.
 * If the input body was already manifold , it return the input body.
 * - Delete with the usual C++ delete operator afer use. 
 * -----------------------------------------------------------------------------------
 * Oct. 01     Creation FDS 
 * -----------------------------------------------------------------------------------
 */  
class ExportedByBOTOPOPE CATTopMakeManifold : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopMakeManifold);
  public:
/**
 * @nodoc
 * Constructor. Do not use. Use the <tt>CATCreateTopSweep</tt> global function to create a
 * CATTopSweep operator.
 */
    CATTopMakeManifold (CATGeoFactory * iGeoFactory, CATTopData * iData);
/**
 * Destructor.
 */
    virtual ~CATTopMakeManifold ();

};


/**
 * Creates a CATTopMakeManifold operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodyToMakeManifold
 * The pointer to the body to make manifold
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator afer use.
 * @see CATTopMakeManifold
 */
ExportedByBOTOPOPE  CATTopMakeManifold * CATCreateTopMakeManifold ( CATGeoFactory * iGeoFactory,
                                                                    CATTopData    * iData,
                                                                    CATBody       * iBodyToMakeManifold );

#endif

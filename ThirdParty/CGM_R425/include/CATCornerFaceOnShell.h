#ifndef CATCornerFaceOnShell_h
#define CATCornerFaceOnShell_h

//#include "Primitives.h"
#include "AdvancedFillet.h"
#include "CATTopOperator.h"
//#include "ListPOfCATEdge.h"
//#include "CATMathDef.h"

class CATLISTP(CATEdge);


/** 
 * Class representing the operator that creates a face on a planar body 
 * on a concavity of the shell boundary represented by two sets of edges.
 * <br>To use the CATCornerFaceOnShell :
 * <ul><li>Create the <tt>CATCreateCornerFaceOnShell</tt> global function. 
 * <li> <tt>Run</tt> the operator
 * <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.</ul>
 */

class ExportedByAdvancedFillet CATCornerFaceOnShell : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATCornerFaceOnShell);
  public:
	
/**
 * @nodoc
 */
    CATCornerFaceOnShell( CATGeoFactory *iFactory,
                           CATTopData * iData);

/**
 * @nodoc
 */	
    ~CATCornerFaceOnShell();
};

/** 
 * Creates an operator to build a 2D corner face.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside the
 * configuration is <tt>NULL</tt>, it is not filled. 
 * @param iBody
 * The pointer to the planar body containing a shell
 * @param iRadius
 * The value of the corner face to create
 * @param iListOfLeftEdges
 * The list of edges forming one set of edges
 * @param iListOfRightEdges
 * The list of edges forming another set of edges
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */

ExportedByAdvancedFillet CATCornerFaceOnShell * CATCreateCornerFaceOnShell (CATGeoFactory * iFactory,
                                                                            CATTopData    * iTopData,
                                                                            CATBody * iBody,
                                                                            double iRadius,
                                                                            CATLISTP(CATEdge) *iListOfLeftEdges,
                                                                            CATLISTP(CATEdge) *iListOfRightEdges);

/** 
 * Creates an operator to build a 2D corner face.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside the
 * configuration is <tt>NULL</tt>, it is not filled. 
 * @param iBody
 * The pointer to the planar body containing a shell
 * @param iListOfLeftEdges
 * The list of edges forming one set of edges
 * @param iListOfRightEdges
 * The list of edges forming another set of edges
  * @param iListOfEdgesToRemove (after creating corner)
 * The list of edges forming another set of edges which will disappear after corner is created.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */

ExportedByAdvancedFillet CATCornerFaceOnShell * CATCreateCornerFaceOnShell (CATGeoFactory * iFactory,
                                                                            CATTopData    * iTopData,
                                                                            CATBody * iBody,                                                                            
                                                                            CATLISTP(CATEdge) *iListOfLeftEdges,
                                                                            CATLISTP(CATEdge) *iListOfRightEdges,
                                                                            CATLISTP(CATEdge) *iListOfEdgesToRemove);

#endif

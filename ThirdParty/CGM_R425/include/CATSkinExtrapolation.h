#ifndef CATSkinExtrapolation_h
#define CATSkinExtrapolation_h

// COPYRIGHT DASSAULT SYSTEMES 2002

/**
* @level Protected
* @usage U1
*/

#include "PowerTopologicalOpe.h"
#include "CATTopOperator.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"


class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATSoftwareConfiguration;

/**  
* Class defining the topological operator that extrapolates a 
* surface in tangency. 
* The parameters to be specified are:
* <ul>
* <li>an extrapolation length. 
* <li>the type of extrapolation: the faces that are created to extend the surface body
*   are added smoothly. See diagram below:
* </ul>
* <pre>
*
*                             |--------|              /--\
*                             |        |             /    \
*                             |        |            /      \
*       /--------\            /--------\           /--------\
*      /          \          /          \         /          \
*     /            \        /            \       /            \
*        . . . .               . . . .               . . . .
*
*        body to               normal mode         tangent mode
*       extrapolate
*
*</pre> 
* <ul>
* <li>A CATSkinExtrapolation operator is created with the
* <tt>CATCreateSkinExtrapolation</tt> global method.
* It must be directly <tt>delete</tt>d after use. It is is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. 
* <li>The resulting body is retrieved with the <tt>GetResult</tt> method.
*</ul> 
*/

class ExportedByPowerTopologicalOpe CATSkinExtrapolation : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATSkinExtrapolation);
public:

/**
* @nodoc
* Constructor - Not to be used
* Create the operator with CATCreateSkinExtrapolation.
*/
                                  CATSkinExtrapolation     (     CATGeoFactory           *  iFactory                  ,
                                                                 CATTopData              *  iTopData                  ,
                                                                 CATBody                 *  iSkin                     ,
                                                                 CATBody                 *  iWireOnSkin               );
    
/**
* Destructor.
*/
                                 ~CATSkinExtrapolation     ();
    
/**
* @nodoc
* Defines the continuity criteria: 1 for G1, 2 for G2.
* Not to be used.
*/
         void                      SetContinuity            (     int                        mode                     = 1); 
    
    
/**
* Specifies the type of extrapolation.
* @param mode
*<dl>  
*<dt><tt>1</tt></dt><dd>  The extrapolation is Tangent to extremities.   
*<dt><tt>2</tt></dt><dd>  The extrapolation is Normal to extremities.
*   This mode is the default mode.
*</dl>  
*/
         void                      SetBorderMode            (     int                        mode                     = 1); 
    
// #ifndef CATIACGMV5R19 // need migration
/**
* @nodoc
* Specifies the extrapolation length.
* Use SetLength method.
*/
         void                      SetOffset                (     double);
// #endif    
/**
* Specifies the extrapolation length.
*/
         void                      SetLength                (     double);
    
/**
* @nodoc
* Specifies a body to extrapolate up to.
* @param iUntilBody
*    The body to extrapolate up to.   
* @param iSplitMode
*<dl>  
*<dt><tt>0</tt></dt><dd>  No split.   
*<dt><tt>1</tt></dt><dd>  Result will be splitted by iUntilBody.
*   This mode is the default mode.
*</dl>  
*/
         void                      SetUntilBody             (      CATBody* iUntilBody ,
                                                                   int      iSplitMode = 1);
    
    
/**
* @nodoc
* 0 = NO, otherwise = YES.
* In active mode, checks that the wire is on the boundary of the skin.
* Not to be used : check is automatically done.
*/
         void                      SetCheckIfWireIsOnShellBoundary(int mode); 
    
/**
* @nodoc
*/
         void                      SetSoftwareConfiguration(CATSoftwareConfiguration* iConfig);
    
/**
* @nodoc
*/
         CATSoftwareConfiguration* GetSoftwareConfiguration() const;
    
/**
* @nodoc
* Specifies one or several internal edges in order to determine a direction for the extrapolation.
* The edges will be extrapolated in tangency. It is possible to associate a vertex to each edge
* to give an orientation to extrapolation.
* @param iEdgesForDirection
*   The Edges to determine direction for extrapolation.
* @param iVertexOfEdges
*   The Vertex associated to each Edge for orientation. 
*/
         void                      SetDirectionnalEdge     (const CATLISTP(CATEdge)  & iEdgesForDirection,
                                                            const CATLISTP(CATVertex)& iVertexOfEdges    );
    
/**
* @nodoc
*/
         void                      SetJournalMode          (      CATLONG32            iJournalMode      );

/**
 * @nodoc
 * Enables or disables twist detection. 
 * @param  iTwistDetection  
 *<dl>  
 *<dt><tt>0</tt></dt><dd>  No  twist detection : twist is authorized.  
 *<dt><tt>1</tt></dt><dd>  twist detection : twist is not authorized.  
 *   This is default mode : extrapolation is not possible if a twist is detected.
 *</dl>  
 */
 virtual void                      SetTwistDetection       (      int                  iTwistDetection   );

/**
* Retrieves the resulting body.
*/
 virtual CATBody                 * GetResult               ();
    
protected:
    void * _implementation;
    
};

/**
 * Creates a CATSkinExtrapolation operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data of the operation.
 * @param iSkin
 * The pointer to surface to be extrapolated.
 * @param iWireOnSkin
 * The pointer to the wire from which the skin is to be extrapolated.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 */

ExportedByPowerTopologicalOpe CATSkinExtrapolation * CATCreateSkinExtrapolation( CATGeoFactory     * iFactory, 
                                                                                 CATTopData        * iTopData, 
                                                                                 CATBody           * iSkin, 
                                                                                 CATBody           * iWireOnSkin ); 


#endif

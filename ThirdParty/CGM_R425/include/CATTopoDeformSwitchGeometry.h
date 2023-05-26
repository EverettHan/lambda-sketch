#ifndef CATTopoDeformSwitchGeometry_H
#define CATTopoDeformSwitchGeometry_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "TopoDeformation.h"
#include "CATTopOperator.h"

#include "ListPOfCATFace.h"
#include "CATListOfCATSurfaces.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATEdge.h"

class CATGeoFactory;
class CATTopoData;

class CATBody;
class CATFace;
class CATSurface; 
class CATEdge;


/**
 * Class defining the operator that deforms a input body by replacing initial surfaces of this body 
 * by given deformed surfaces.
 * Each deformed surface must have the same parameterization for a given tolerance than the corresponding initial surface. 
 * This operator follows the global frame of the topological operators and satisfies the smart mechanism: 
 * the input body is not modified. A new resulting body is created possibly sharing data with the input body.
 *<ul>
 * <li>A CATTopoDeformSwitchGeometry operator is created with the <tt>CATCreateTopoDeformSwitchGeometry</tt> global method:
 * It must be directly <tt>delete</tt>d after use. It is not streamable. 
 *<li>Options can be precised, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.
 *</ul>
 */
class ExportedByTopoDeformation CATTopoDeformSwitchGeometry	: public	CATTopOperator

{

  CATCGMVirtualDeclareClass(CATTopoDeformSwitchGeometry);

public:

  virtual ~CATTopoDeformSwitchGeometry();

	/**
	 * @param FaceImpacted 
	 * the initial face  impacted by the deformation
	 * @param DeformedSurface 
	 * the corresponding deformed surface 
	 * This method must be called each time that an initial face is impacted. 
	 */
	virtual int AddDeformedSurface(CATFace* FaceImpacted, CATSurface * DeformedSurface)=0;

  
	/**
	 * @param FaceImpacted 
	 * the initial  list of faces  impacted by the deformation
	 * @param DeformedSurface 
	 * the corresponding list of deformed surface 
	 */
	virtual	int AddDeformedSurface(ListPOfCATFace & FaceImpacted,CATLISTP(CATSurface) & DeformedSurface )=0; 
												
   
	 
	/**
	* @param iG0Tolerance 
	* The tolerance used to verify which edges on the deformed body have a G0 gap greater than iG0Tolerance. 
	* The default Tolerance  is the Resolution Tolerance.  
	*/
  virtual  void SetG0Tolerance (double iG0Tolerance)=0; 

	
	/**
	* Run method
	* returns 0 if there is no problem in the update of deformed body 
	* returns 1 if the deformed body can not be updated 
	* returns 2 if the maximum G0 error along an edge is greater than 100*iG0Tolerance
  */
	virtual int Run ()=0;


	/**
	* This method returns the deformed body.   
	* This method gives no result if the method Run does not return 0. 
	*  
  */
	virtual CATBody * GetResult ()=0;


   /**
   * Retrieves the G0 continuity diagnosis for a given edge.
   * @param iE
   * The pointer to the edge on the result 
	 * @param isAfterDeformation
	 * if isAfterDeformation=TRUE, the max deviation corresponds to the result body 
	 * otherwise it corresponds  the input body 
   * @param oG0Error
   * The value of the maximum G0 deviation along the edge
   * @returns
   * -1 if the edge has not been impacted by the deformation
   */
   virtual int G0MaxError(CATEdge * iE , double &oG0Error, const CATBoolean isAfterDeformation=TRUE) = 0;

  
	 /**
   * This method returns the list of edges on result with a G0 gap greater than input tolerance iG0Tolerance.
   **/
	  virtual int GetOpenEdges(ListPOfCATEdge & ioListOfEdges)=0;

protected :

  CATTopoDeformSwitchGeometry( CATGeoFactory  *iFactory,
                        CATTopData *iData );			
};

/**
 * Creates the operator that deforms a body by replacing surfaces of this body with new given surfaces 
 * @param iFactory
 * The pointer to the geometry factory.
 * @param iTopData
 * The pointer to the data defining the configuration.
 * @param iBodyToBeDeformed
 * The pointer to the body to deform. As the operator follows the smart mechanism, 
 * this input body is not modified. A new one is created, it can be retrieved with 
 * the <tt>GetResult</tt> method.
 */
ExportedByTopoDeformation
CATTopoDeformSwitchGeometry * CATCreateTopoDeformSwitchGeometry(CATGeoFactory  *iFactory, CATTopData *iData,CATBody * iBodyToBeDeformed);
#endif

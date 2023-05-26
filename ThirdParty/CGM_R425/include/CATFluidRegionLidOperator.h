#ifndef CATFluidRegionLidOperator_h
#define CATFluidRegionLidOperator_h
//==========================================================================
// 09/09/2021 G5S Created
// 07/11/2022 G5S Added interface for a list of faces.
//==========================================================================

//#include "ExportedByCATTopologicalObjects.h"
#include "CATTopOperator.h"
#include "ExportedByBONEWOPE.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"

/**
 * Interface representing an operator that uses a solid bodies and geometries on
 * those bodies to create one or more surfacic lids that will be used for the fluid region
 * extract operator. 
 * The solid container bodies and resulting lids should enclose one or more volumes
 * 
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateFluidRegionLidOperator</tt> global function.
 * <li>Run it
 * <li>Get the resulting body with the <tt>GetResult</tt> method. If you do not want
 * to keep these resulting body, use the @href CATICGMContainer#Remove method to remove them from the
 * geometric factory, after the operator deletion.
 *<li>delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul>
 */
class CATFluidRegionLidOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATFluidRegionLidOperator);
public:
  virtual ~CATFluidRegionLidOperator();

protected:
  CATFluidRegionLidOperator(CATGeoFactory * iGeoFactory, CATTopData * iData, CATExtTopOperator* iExtensible);
  
};

/**
 * Creates a CATFluidRegionLid operator that will create a single lid only.
 * @param iFactory
 * The pointer to the factory of the geometry for the creation of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iSolidContainerBodyList
 * List of solid container bodies.
 * @param iEdgeList
 * List of edges lying on the container bodies.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBONEWOPE CATFluidRegionLidOperator * CATCreateFluidRegionLidOperator(CATGeoFactory * iFactory,
  CATTopData * iTopData,
  ListPOfCATBody & iSolidContainerBodyList,
  ListPOfCATEdge & iEdgeList);

/**
 * Creates a CATFluidRegionLid operator that will create one lid for each closed boundary of a list of
 * faces, provided that all boundaries are in the same plane.
 * If the list contains one face, the operator will create one lid for each internal loop of the face
 * that does not surround material in the solid container body.
 * Otherwise, the operator will create one lid for each closed boundary except for the outer boundary and boundaries
 * that are internal loops of a single face and boundaries that surround material in the solid container body.
 * @param iFactory
 * The pointer to the factory of the geometry for the creation of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iSolidContainerBodyList
 * List of solid container bodies.
 * @param iFaceList
 * List of faces lying on the container bodies.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBONEWOPE CATFluidRegionLidOperator* CATCreateFluidRegionLidOperator(CATGeoFactory* iFactory,
  CATTopData* iTopData,
  ListPOfCATBody& iSolidContainerBodyList,
  ListPOfCATFace& iFaceList);

/**
 * Creates a CATFluidRegionLid operator that will create one lid for each intenal loop of the face that does not
 * surround material in the solid conainer body.
 * @param iFactory
 * The pointer to the factory of the geometry for the creation of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iSolidContainerBodyList
 * List of solid container bodies.
 * @param iFace
 * A face lying on one of the container bodies.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBONEWOPE CATFluidRegionLidOperator* CATCreateFluidRegionLidOperator(CATGeoFactory* iFactory,
  CATTopData* iTopData,
  ListPOfCATBody& iSolidContainerBodyList,
  CATFace* iFace);

/**
 * Creates a CATFluidRegionLid operator that will automatically create all the lids required for a
 * list of solid container bodies.
 * @param iFactory
 * The pointer to the factory of the geometry for the creation of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iSolidContainerBodyList
 * List of solid container bodies.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBONEWOPE CATFluidRegionLidOperator* CATCreateFluidRegionLidOperator(CATGeoFactory* iFactory,
  CATTopData* iTopData,
  ListPOfCATBody& iSolidContainerBodyList);
#endif

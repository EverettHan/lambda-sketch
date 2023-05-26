#ifndef CATVisClippingSectionsFilter_H
#define CATVisClippingSectionsFilter_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
// Class  :  	CATVisClippingSectionsFilter
// Date   :  	15/11/08
//-----------------------------------------------------------------------------
//  Inheritance : CATVisClippingSectionsFilter
//					CATVisFilter
//-----------------------------------------------------------------------------
// Abstract : This class defines a filter build with many clipping geom sections
//            and 3D clipping section
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	manage the filters
//		AddClippingGeom
//		RemoveClippingGeom
//-----------------------------------------------------------------------------

// Local Framework
#include "CATVisFilter.h"
#include "list.h"
class CATVisClippingGeom;
class CATVisTetrahedron;
class IVisSGClippingFilter;

class ExportedBySGInfra CATVisClippingSectionsFilter : public CATVisFilter 
{
	CATDeclareVisFilter(CATVisClippingSectionsFilter);
  CATVisDeclarePublicInterfaceAdhesion(CATVisClippingSectionsFilter, IVisSGClippingFilter, CATVisClippingSectionsFilterIVisSGClippingFilterBOAImpl);
	friend class VisInsertBehaviour;

public:

	/** Contructs an empty global filter.
	 */
	static CATVisClippingSectionsFilter* Create();

	/** Add a clipping geometry to use as a filter.
	 * @param ipClippingGeom
	 * Clipping geometrical section.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>S_OK</dt>
	 *  <dd>Success.</dd>
	 *  <dt>E_FAIL</dt>
	 *  <dd>failure.</dd>
	 * </dl>
	 */
	HRESULT AddClippingGeom(CATVisClippingGeom* ipClippingGeom);

	/** Remove a clipping geometrical section.
	 * @param ipClippingGeom
	 * Clipping geometrical section.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>S_OK</dt>
	 *  <dd>Success.</dd>
	 *  <dt>E_FAIL</dt>
	 *  <dd>failure.</dd>
	 * </dl>
	 */
	HRESULT RemoveClippingGeom(CATVisClippingGeom* ipClippingGeom);

	/** Remove the whole clipping geometries.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>S_OK</dt>
	 *  <dd>Success.</dd>
	 *  <dt>E_FAIL</dt>
	 *  <dd>failure.</dd>
	 * </dl>
	 */
	HRESULT RemoveAllClippingGeom();

	/** Get clipping geometries count.
	 * @param oClippingGeomCount
	 * Clipping geometries count.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>S_OK</dt>
	 *  <dd>Success.</dd>
	 *  <dt>E_FAIL</dt>
	 *  <dd>failure.</dd>
	 * </dl>
	 */
	HRESULT GetClippingGeomCount(int& oClippingGeomCount) const;

	/** Get a clipping geometry according to its index.
	 * @param iClippingGeomNum
	 * Clipping geometry index.
	 * @param opClippingGeom
	 * Clipping geometry.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>S_OK</dt>
	 *  <dd>Success.</dd>
	 *  <dt>E_FAIL</dt>
	 *  <dd>failure.</dd>
	 * </dl>
	 */
	HRESULT GetClippingGeom(int iClippingGeomNum, CATVisClippingGeom*& opClippingGeom) const;
	
	/** Get tetraedrons list defining the space divided by clipping geometries.
	 * @param oTetraedronList
	 * tetraedrons list.
	 * @return
	 * <br><b>Legal values</b>
	 * <dl>
	 *  <dt>S_OK</dt>
	 *  <dd>Success.</dd>
	 *  <dt>E_FAIL</dt>
	 *  <dd>failure.</dd>
	 * </dl>
	 */
    HRESULT GetTetraedronList(list<CATVisTetrahedron>& oTetraedronList);

    virtual void Visit(VisSGFilterVisitor& iVisitor) const;

    virtual HRESULT SetUncutting(int iUncut);
    virtual HRESULT GetUncutting(int& oiUncut) const;

private:

	CATVisClippingSectionsFilter();
	virtual ~CATVisClippingSectionsFilter();
};
#endif 
  
  

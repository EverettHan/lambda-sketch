// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATAdMfgVolSupportGenerator.h
//
//===================================================================

#include "CATIACGMLevel.h"
#ifdef CATIAR420

#ifndef CAT_ADMFG_VOL_SUPPORT_GENERATOR_H
#define CAT_ADMFG_VOL_SUPPORT_GENERATOR_H

#include "AdvTopoOpeItf.h"
#include "CATPolyBaseOper.h"

class CATIPolyMesh;
class CATPolyBody;
class CATMathPlane;
class CATMathBox2D;
class CATAdMfgVolSupportGeneratorObserver;
class CATechExt;
#include "CATListOfVolSupportDomain.h"

/**
* Class defining the operator that computes volumic supports to support a part during additive manufacturing. 
* <br>This operator identifies regions of a given input part that require support and computes volumes to support
* those regions. These volumes may end on other regions of the part itself or on the base plate.
* Before using the operator, mandatory operands and parameters must be set, specifically:
*<ul>
* <li>The input mesh or polybody (recommended to use polybody input).
* <li>The reference plane which represents the base plate.
*</ul>
* The operator is created using the <tt>CATCreateSupportGenerator</tt> global function. The operator requires two other 
* inputs, namely the two critical angles to determine which regions of the input part require support. There are some other
* optional paramters too. The output of the operator is obtained as a list of <tt>CATAdMfgVolSupportDomain</tt> 
* objects. 
*/

class ExportedByAdvTopoOpeItf CATAdMfgVolSupportGenerator : public CATPolyBaseOper
{
public:
	/**
	* Destructor.
	*/
	virtual ~CATAdMfgVolSupportGenerator();
		
	/**
	* Sets the input polybody of the operator. This is the polybody of the part for which support structures are computed
	* to aid during additive manufacturing.
	*/
	virtual void SetInputPolyBody(const CATPolyBody& iPolyBody) = 0;

	/**
	* -DoNotUse-
	* It is recommended to use <tt>SetInputPolyBody<tt>.
	*/
	virtual void SetInputMesh(const CATIPolyMesh& iMesh) = 0;
	
	/**
	* Sets the plane which is to be considered as the base plate/tray. The normal vector to this plane must be along 
	* the build axis of the part and opposite to the direction of gravity.
	* This plane must not intersect the input part.
	*/
	virtual void SetReferencePlane(const CATMathPlane& iRefPlane) = 0;
	
	/**
	* Sets the option to divide the support volumes and compute top and bottom surface meshes for each volume.
	* Off by default. If option is set, output <tt>CATAdMfgVolSupportDomain</tt> objects will contain support 
	* volume as well as top and bottom surface meshes.
	*/
	virtual void SetComputeTopBottomSurfaces(const CATBoolean& iComputeTopBottomSurfaces) = 0;
	
	/**
	* Optional method to filter the output support volumes.
	* Sets the minimum area for cross section of support volumes. 
	* If area of cross section is smaller than this minimum, that support volume will be discarded.
	* @param iMinimumArea
	* The minimum area in mm*mm to set. 
	*/
	virtual void SetMinimumArea(double iMinimumArea) = 0;

	/**
	* Optional method to filter the output support volumes.
	* Sets the minimum bounding box for cross section of support volumes.
	* If oriented bounding box of cross section is smaller than this minimum, that support volume will be discarded.
	* @param iMinimumBox
	* The minimum CATMathBox2D to set.
	*/
	virtual void SetMinimumBox(const CATMathBox2D& iMinimumBox) = 0;

	/**
	* Computes the volumic supports.
	* @param iBottomLimitAngle
	* The lower angle limit. Regions that lie between iBottomLimitAngle and iTopLimitAngle will be considered 
	* for computing support. Angles are measured between triangle normals and vertical axis. 
	* Should be between 0 and 89.5 degrees. Note: To be specified in radians.
	* @param iTopLimitAngle
	* The higher angle limit. Should be between 0 and 89.5 degrees. Note: To be specified in radians.
	* @param oSupportsList
	* The output list of <tt>CATAdMfgVolSupportDomain</tt> objects. Objects of list to be deleted by the user.
	*/
	virtual HRESULT ComputeSupport(double iBottomLimitAngle, double iTopLimitAngle, CATLISTP(CATAdMfgVolSupportDomain) & oSupportsList) = 0;
	
	/**
	* Sets the observer for Phoenix Implementation.
	*/
	virtual void SetObserver (CATAdMfgVolSupportGeneratorObserver* iObserver) = 0;
	
	/**
	* Retrieves the observer for Phoenix Implementation.
	*/
	virtual CATAdMfgVolSupportGeneratorObserver* GetObserver () = 0;
};


/**
* Creates an instance of <tt>CATAdMfgVolSupportGenerator</tt>.
*/
ExportedByAdvTopoOpeItf  CATAdMfgVolSupportGenerator * CATCreateSupportGenerator();


#endif

#endif

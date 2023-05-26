// -*- C++ -*-
//=================================================================
// COPYRIGHT DASSAULT SYSTEMES 2007
//=================================================================
// VPM (c) Copyright Dassault Systemes 2007
//=================================================================
#ifndef _CATIPLMIndex_TypeQuery_h_
#define _CATIPLMIndex_TypeQuery_h_

/**
 * @level Private
 * @usage U3
 */

/**
 * This class supplies CATIPLMIndex_TypeQuery.
 * <b>Role</b>: CATIPLMIndex_TypeQuery proposes a list of predefined queries to use.
 * Each query has some parameters to be set using the 'SetParam' method.
 * Allowed types in 'SetParam' method are: CATUnicodeString, float, double, int,
 * CATMathVector, CATMathPoint,	CATMathTransformation, CATIPLMAsmGeo_var,
 * CATIPLMViewpoint_var, CATIPLMValueList_var, CATPLMID
 * @example
 *	CATIPLMIndexQuery_var	hQuery;
 *	CATIPLMAsmGeo_var hAsmGeo;
 *	CATMathPoint bMin;
 *	CATMathPoint bMax;
 *	CATMathTransformation bPosition;
 *		...............
 *	RC = hQuery->SetQuery(CATIPLMIndex_TypeQuery::QueryBox);
 *	RC = hQuery->SetParam(hAsmGeo);
 *	RC = hQuery->SetParam(bMin);
 *	RC = hQuery->SetParam(bMax);
 *	RC = hQuery->SetParam(bPosition);
 *		...............
 */

// =================================================================
// Includes
// =================================================================

#include "GUIDCATPLMIndexInterfaces.h"

// -- System
#include "CATUnicodeString.h"

//------------------------------------------------------------------

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMIndex_TypeQuery
{
	CATIPLMIndex_TypeQuery(const CATIPLMIndex_TypeQuery&);
	CATIPLMIndex_TypeQuery& operator=(const CATIPLMIndex_TypeQuery&);
	CATIPLMIndex_TypeQuery();
	virtual ~CATIPLMIndex_TypeQuery() = 0;

public:
    /**
     * "Intersect mode" for geometric queries that support it (QueryBoxComplex[RI], QuerySphereComplex[RI])
     */
    static const CATUnicodeString QueryMode_Intersect;
    
    /**
     * "Inside mode" for geometric queries that support it (QueryBoxComplex[RI], QuerySphereComplex[RI])
     */
    static const CATUnicodeString QueryMode_Inside;
    
    /**
     * "Not Intersect mode" for geometric queries that support it (QueryBoxComplex[RI], QuerySphereComplex[RI])
     */
    static const CATUnicodeString QueryMode_NotIntersect;

    /**
     * "Not Inside mode" for geometric queries that support it (QueryBoxComplex[RI], QuerySphereComplex[RI])
     */
    static const CATUnicodeString QueryMode_NotInside;

public:
	/**
	 * Predefined QueryMultiVolume statement: Select the objects that are in the described combination of volume (in at least one of the volumes).
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Volume: Multi volume object. Contains one are more basic volumes (CATIPLMMultiVolume)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryMultiVolume;
	/**
	 * Predefined QueryMultiVolume statement: Select the objects that are in the described combination of volume (in at least one of the volumes).
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Volume: Multi volume object. Contains one are more basic volumes (CATIPLMMultiVolume)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryMultiVolumeRI;

	/**
	 * Predefined QueryBox statement: Select the objects that are at least partially in the box.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   MinPoint: Box min point (CATMathPoint)
	 *   MaxPoint: Box max point (CATMathPoint)
	 *   BoxPosition: Box position (CATMathTransformation)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryBox;

	/**
	 * Predefined QueryBoxComplex statement: QueryBox with the choice on the mode of intersection.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Mode: Intersection mode PartlyIn / FullyIn / PartlyOut / FullyOut (CATIPLMIndex_TypeQuery) See definition above.
	 *   MinPoint: Box min point (CATMathPoint)
	 *   MaxPoint: Box max point (CATMathPoint)
	 *   BoxPosition: Box position (CATMathTransformation)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryBoxComplex;

	/**
	 * Predefined QueryBoxRI statement: Select the objects that are at least partially in the box.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   MinPoint: Box min point (CATMathPoint)
	 *   MaxPoint: Box max point (CATMathPoint)
	 *   BoxPosition: Box position (CATMathTransformation)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryBoxRI;

    /**
	 * Predefined QueryBoxComplexRI statement: QueryBox with the choice on the mode of intersection.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Mode: Intersection mode PartlyIn / FullyIn / PartlyOut / FullyOut (CATIPLMIndex_TypeQuery) See definition above.
	 *   MinPoint: Box min point (CATMathPoint)
	 *   MaxPoint: Box max point (CATMathPoint)
	 *   BoxPosition: Box position (CATMathTransformation)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryBoxComplexRI;

	/**
	 * Predefined QuerySphere statement: Select the objects that are at least partially in the sphere.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Center: Sphere center (CATMathPoint)
	 *   Radius: Sphere radius (float)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QuerySphere;
    
    /**
	 * Predefined QuerySphereComplex statement: QuerySphere with the choice on the mode of intersection.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Mode: Intersection mode PartlyIn / FullyIn / PartlyOut / FullyOut (CATIPLMIndex_TypeQuery) See definition above.
	 *   Center: Sphere center (CATMathPoint)
	 *   Radius: Sphere radius (float)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QuerySphereComplex;

	/**
	 * Predefined QuerySphereRI statement: Select the objects that are at least partially in the sphere.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Center: Sphere center (CATMathPoint)
	 *   Radius: Sphere radius (float)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QuerySphereRI;

    /**
	 * Predefined QuerySphereComplexRI statement: QuerySphereRI with the choice on the mode of intersection.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   Mode: Intersection mode PartlyIn / FullyIn / PartlyOut / FullyOut (CATIPLMIndex_TypeQuery) See definition above.
	 *   Center: Sphere center (CATMathPoint)
	 *   Radius: Sphere radius (float)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QuerySphereComplexRI;

    /**
	 * Predefined QueryFull Statement: All the leaf references (Expand)
	 * Input parameters (in this order): 
	 *   Asmgeo: Geometric Assembly. IT CANNOT BE COUMPOUND (CATIPLMAsmGeo)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int) 
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryFull;

    /**
	 * Predefined QueryFullRI Statement: All the leaf references (Expand).
	 * Input parameters (in this order): 
	 *   Asmgeo: Geometric Assembly. IT CANNOT BE COUMPOUND (CATIPLMAsmGeo)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)   
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryFullRI;

	/**
	 * Predefined QueryExpandDepthN Statement: All the references at an input depth (Expand with depth)
	 * Input parameters (in this order):
	 *   Depth: Depth at which expand must be done (int)
	 *   Asmgeo: Geometric Assembly. IT CANNOT BE COUMPOUND (CATIPLMAsmGeo)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)   
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryExpandDepthN;

	/**
	 * Predefined QueryExpandDepthNRI Statement: All the references at an input depth (Expand with depth)
	 * Input parameters (in this order):
	 *   Depth: Depth at which expand must be done (int)
	 *   Asmgeo: Geometric Assembly. IT CANNOT BE COUMPOUND (CATIPLMAsmGeo)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)   
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryExpandDepthNRI;

    /**
	 * Predefined QueryLine Statement: First object intersecting the line (if any).
	 * Input parameters (in this order):
	 *   Asmgeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   Origin: Line origin (CATMathPoint)
	 *   Direction: Line direction (CATMathVector)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)   
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryLine;

    /**
	 * Predefined QueryLineRI Statement: First object intersecting the line (if any).
	 * Input parameters (in this order):
	 *   Asmgeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   Origin: Line origin (CATMathPoint)
	 *   Direction: Line direction (CATMathVector)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)   
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryLineRI;

	/**
	 * Predefined QueryLineBoxSectionRI Statement: QueryLineRI (see above) with box sectioning.
	 * Input parameters (in this order):
	 *   Asmgeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   Origin: Line origin (CATMathPoint)
	 *   Direction: Line direction (CATMathVector)
	 *   MinPoint: Box min point (CATMathPoint)
	 *   MaxPoint: Box max point (CATMathPoint)
	 *   BoxPosition: Box position (CATMathTransformation)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryLineBoxSectionRI;

    /**
	 * Predefined QueryLineHalfSpaceSectionRI Statement: QueryLineRI (see above) with half space sectioning.
	 * Input parameters (in this order):
	 *   Asmgeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   Origin: Line origin (CATMathPoint)
	 *   Direction: Line direction (CATMathVector)
	 *   PlanePoint: Point in plane (CATMathPoint)
	 *   PlaneNormal: Plane normal pointing out (CATMathVector)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryLineHalfSpaceSectionRI;

	/**
	 * Predefined QueryLineHalfSpaceSectionRI Statement: QueryLineRI (see above) with sphere sectioning.
	 * Input parameters (in this order):
	 *   Asmgeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   Origin: Line origin (CATMathPoint)
	 *   Direction: Line direction (CATMathVector)
	 *   Center: Sphere center (CATMathPoint)
	 *   Radius: Sphere radius (float)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryLineSphereSectionRI;

	/**
	 * Predefined QueryVisu statement: Select all the objects visible from a given viewpoint.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   ViewPoint: Viewpoint (CATIPLMViewpoint)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryVisu;

    /**
	 * Predefined QueryVisuRI statement: Select all the objects visible from a given viewpoint.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   ViewPoint: Viewpoint (CATIPLMViewpoint)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryVisuRI;

	/**
	 * Predefined QueryVisuBoxSectionRI statement: QueryVisuRI with box sectioning.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   ViewPoint: Viewpoint (CATIPLMViewpoint)
	 *   MinPoint: Box min point (CATMathPoint)
	 *   MaxPoint: Box max point (CATMathPoint)
	 *   BoxPosition: Box position (CATMathTransformation)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryVisuBoxSectionRI;

	/**
	 * Predefined QueryVisuHalfSpaceSectionRI statement: QueryVisuRI with half space sectioning.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   ViewPoint: Viewpoint (CATIPLMViewpoint)
	 *   PlanePoint: Point in plane (CATMathPoint)
	 *   PlaneNormal: Plane normal pointing out (CATMathVector)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryVisuHalfSpaceSectionRI;

    /**
	 * Predefined QueryVisuSphereSectionRI statement: QueryVisuRI with sphere sectioning.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   ViewPoint: Viewpoint (CATIPLMViewpoint)
	 *   Center: Sphere center (CATMathPoint)
	 *   Radius: Sphere radius (float)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */ 
	static const CATUnicodeString QueryVisuSphereSectionRI;

	/**
	 * Predefined QueryAllVisible statement: Select all the visible objects whatever the viewpoint is (WrapQuery)
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   TimeOut: Max time for rays casting (int)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */ 
    static const CATUnicodeString QueryAllVisible;
	/**
	 * Predefined QueryAllVisibleRI statement: Select all the visible objects whatever the viewpoint is (WrapQuery)
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   TimeOut: Max time for rays casting (int)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */ 
    static const CATUnicodeString QueryAllVisibleRI;
	
	/**
	 * Predefined QueryAllVisibleByDensity statement: Select all the visible external objects whatever the viewpoint is (WrapQuery)
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   TimeOut: Max time for rays casting (int)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */ 
    static const CATUnicodeString QueryAllVisibleByDensity;

	/**
	 * Predefined QueryAllVisibleRIByDensity statement: Select all the visible external objects whatever the viewpoint is (WrapQuery)
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   TimeOut: Max time for rays casting (int)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
    static const CATUnicodeString QueryAllVisibleRIByDensity;

	/**
	 * Predefined QueryClash statement: Select all the pairs of occurrences in collision
	 * Input parameters (in this order):
	 *   AsmGeo1: First geometric assembly - list of occurrences! - IT MUST BE COMPOUND OF REP PATHS ONLY (CATIPLMAsmGeo)
	 *   AsmGeo2: Second geometric assembly - list of occurrences! - IT MUST BE COMPOUND OF REP PATHS ONLY (CATIPLMAsmGeo)
	 *   Distance: Clash distance (float)
	 * Output parameters (in this order):
	 *   OccIndice1: Indice of occurrence in AsmGeo1 (int)
	 *   OccIndice2: Indice of occurrence in AsmGeo2 (int)
	 */
	static const CATUnicodeString QueryClash;
	
	/**
	 * Predefined QueryRoot statement: Select all roots in index files
	 * Input parameters (in this order):
	 *   (NONE)
	 * Output parameters (in this order):
	 *   path: Root reference path - only one reference! - (CATPLMID)
	 */
    static const CATUnicodeString QueryRootIDs;

	/**
	 * Predefined QueryNames statement: Returns PLM_ExternalID for all objects in list
     * Input parameters (in this order):
	 *   objList: List of objects whose PLM_ExternalID must be retrieved. THEY MUST BE REFERENCES. (CATIPLMValueList of CATPLMID)
	 * Output parameters (in this order):
	 *   objName: PLM_ExternalID (CATUnicodeString)
	 */
    static const CATUnicodeString QueryNames;

	/**
	 * Predefined QueryInstanceNames statement: Returns PLM_ExternalID for all objects in list
     * Input parameters (in this order):
	 *   objList: List of objects whose PLM_ExternalID must be retrieved. THEY MUST BE INSTANCES. (CATIPLMValueList of CATPLMID)
	 * Output parameters (in this order):
	 *   objName: PLM_ExternalID (CATUnicodeString)
	 */

	static const CATUnicodeString QueryInstanceNames;

	/**
	 * Predefined QueryMaxCountAndBB statement: Get max number of leaf occurrences and an axis aligned bounding box of AsmGeo.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 * Output parameters (in this order):
	 *   nbLeafs: Max number of leaf occurrences (int) (Invalid with CloudView)
	 *   AsmGeoBB: Axis aligned bounding box of AsmGeo ([CATMathPoint, CATMathPoint])
	 */
    static const CATUnicodeString QueryMaxCountAndBB;

	/**
	 * Predefined QueryMaxCountAndBB statement: Get max number of leaf occurrences and an axis aligned bounding box of AsmGeo.
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric Assembly (CATIPLMAsmGeo)
	 * Output parameters (in this order):
	 *   path: Root reference path - (CATPLMID)
	 *   AsmGeoBB: Axis aligned bounding box of AsmGeo ([CATMathPoint, CATMathPoint])
	 */
	static const CATUnicodeString QueryRootBBs;

	/**
	 * Predefined UpdateIndex statement: Update index files for all objects after a given date.
	 * Input parameters (in this order):
	 *   date: Number of seconds since 1970, Jan 1st. (int)
	 * Output parameters (in this order):
	 *   (NONE (?))
	 */
	static const CATUnicodeString UpdateIndex;

	/**
	 * Predefined GetIndexLastUpdateDate statement: Returns the date of the last index update.
	 * Input parameters (in this order):
	 *   (NONE)
	 * Output parameters (in this order):
	 *   date: Number of seconds since 1970, Jan 1st. (int)
	 */
	static const CATUnicodeString GetIndexLastUpdateDate;

	/**
	 * WARNING!!! DO NOT USE => Not yet implemented
	 *
	 * Predefined QueryLineMultiple statement: Select all the objects intersecting a given line (if any).
	 * Input parameters (in this order):
	 *   Asmgeo: Geometric Assembly (CATIPLMAsmGeo)
	 *   Origin: Line origin (CATMathPoint)
	 *   Direction: Line direction (CATMathVector)
	 * Output parameters (in this order):
	 *   (UNKNOWN)
	 */
	static const CATUnicodeString QueryLineMultiple;

	///**
	// *  Predefined QueryRoot Statement: Returns CATPLMID and PLMExternalID for all roots in index
	//*/
    //static const CATUnicodeString QueryRootIDsNames;

	/**
	 * Predefined QueryRootNames statement: Returns PLM_ExternalID for all roots in index.
	 * Input parameters (in this order):
	 *   (NONE)
	 * Output parameters (in this order):
	 *   rootName: Root PLM_ExternalID (CATUnicodeString)
	 */
	static const  CATUnicodeString QueryRootNames;

	/**
	 * Predefined QueryUserName statement: Returns V_user for all roots in index.
	 * Input parameters (in this order):
	 *   (NONE)
	 * Output parameters (in this order):
	 *   rootName: Root V_user (CATUnicodeString)
	 */
	static const  CATUnicodeString QueryUsername;

	/**
	 * Predefined LastIndexTraces statement: Get last indexation traces.
	 * Input parameters (in this order):
	 *   (NONE)
	 * Output parameters (in this order):
	 *   trace: Index trace (CATUnicodeString)
	 */
	static const  CATUnicodeString  LastIndexTraces;

	/**
	 * Predefined QueryProximity statement: Select the objects that are at least partially in a given shape (object).
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   refID: Shape - object! - ID. IT'S NOT A PATH, but the RepReference ID. (CATPLMID)
	 *   position: Shape - object! - matrix position (CATMathTransformation)
	 *   clearance: Shape - object! - expansion (float)
	 * Output parameters (in this order):
	 *   path: R-I-I-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryProximity;

	/**
	 * Predefined QueryProximityRI statement: Select the objects that are at least partially in a given shape (object).
	 * Input parameters (in this order):
	 *   AsmGeo: Geometric assembly (CATIPLMAsmGeo)
	 *   refID: Shape - object! - ID. IT'S NOT A PATH, but the RepReference ID. (CATPLMID)
	 *   position: Shape - object! - matrix position (CATMathTransformation)
	 *   clearance: Shape - object! - expansion (float)
	 * Output parameters (in this order):
	 *   path: R-I-R-I... path (CATPLMID)
	 *   resultMatrix: Last reference absolute positon (CATMathTransformation)
	 *   matrixPath: List of position matrices of all the references in the path (CATMathTransformationList)
	 *   url: URL where the geometry can be loaded (SEQUENCE_octet)
	 *   waterMarkStamp: Object "version" number (int)
	 *	 is3D: 1 if output path is a 3DRep, 0 otherwise (int)
	 *	 latetype: gives the latetype of the returned object, that can be either cgr or uvr (CATUnicodeString)
	 */
	static const CATUnicodeString QueryProximityRI;
	
	/**
	 * Predefined Query for retreiving Derived Objects.
	 * This query returns [ <url of object> ]
	 */
	//static CATUnicodeString QueryDerivedObject(CATUnicodeString iTag);

	/**
	 * Predefined Query for retreiving Derived Objects.
	 * This query returns [ <id of objects> ]
	 */
	//static CATUnicodeString QueryNamesFromSubstring(CATUnicodeString iTag);

	/**
	 * WARNING!!! To use this query SUFFIXES must be indexed
     *
	 * Predefined QueryNamesFromSubstring statement: Select all objects whose PLM_ExternalID contains a given substring
	 * Input parameters (in this order):
	 *   tag: Substring that must be matched (CATUnicodeString)
	 *   maxResults: Max number of displayed results (int) 
	 * Output parameters (in this order):
	 *   nbResults: Number of found results (int) => NUMBER OF RESULTS IS ONLY RETURNED ONCE (NOT FOR EACH RESULT)
	 *   objPath: R-I-R-I... path (CATPLMID)
	 */
	static const CATUnicodeString QueryNamesFromSubstring;

	/**
	 * Predefined Query for similar search.
	 * This query returns [ list of URLs ]
	 */
	static const CATUnicodeString SimilarSearch;

	/**
	 * Predefined Query for knowledge search.
	 * Take 1 list as parameter.
	 */
	static const CATUnicodeString KnowledgeSearch;

	/**
	 * Predefined Query to retrieve id and bounding boxes for a set of Ids
	 * Take 1 list as parameter.
	 */
	static const CATUnicodeString QueryBBbySet;

	/**
	 * Predefined Query to retrieve recursive total number of children for a set of Ids
	 * Take 1 list as parameter.
	 */
	static const CATUnicodeString QueryCountBySet;
	/** @nodoc */
	static const CATUnicodeString QueryDWH;

	/**
	 * Predefined Get dictionary statement: Retrieves the latest version of the attribute dictionary.
	 * Input parameters (in this order):
	 *   (NONE)
	 * Output parameters (in this order):
	 *   dict XML : CATUnicodeString (XML of the dictionary)
	 *   WMS : unsigned int (WaterMarkStamp of the retrieved dictionary)
	 */
	static const CATUnicodeString QueryAttributeDictionary;

	/**
	 * Perform a check on the index, ensuring path is actually properly indexed.
	 * Input parameters (in this order):
	 *   CATIPLMValueList_var : Path R-I-I-I to verify
	 * Output parameters (in this order):
	 *   int              : Boolean
     *   CATUnicodeString : ErrorMsg
	 */
	static const CATUnicodeString QueryCheckPathIsIndexed;

	/**
	 * Predefined QueryMultiWrap statement : For each input reference, select all the visible external objects whatever the viewpoint is.
	 *
	 * INPUT PARAMETERS (in this order):
	 *		[CATIPLMAsmGeo] : Geometric Assembly.
	 *						  A simple wrap query will be run on each context added to the geometric assembly.
	 *						  Only one config filter is allowed if mono root(=> the same for all the contexts).
	 *						  NO config filter is allowed if multi root(=> at least 2 different roots for 2 contexts)./
	 *		[int]			: Rays density. The same for all the contexts.
	 *
	 * OUTPUT PARAMETERS :
	 *		Before receiving the list of objects associated to a given context, you will receive a pre-result
	 *		notifying to which input context they are associated. 
     *      You can detect the kind of record (pre-result or real result) by checking if the first field if of type
     *      int or CATPLMID.
     *      After reading a pre-result record, all the results records till the the next pre-result record are 
     *      associated to the previously read context.
     *      Once all these results read, you will receive another pre-result, and so on.
	 *		PRE-RESULT (in this order):
	 *			[Field 0] [int]		 : Arbitrary int value (used to detect if it is a pre-result record)
	 *			[Field 1] [CATPLMID] Path R-I-I-I... One of the input contexts at which the
	 *								 following results are associated.
	 *
	 *		RESULTS (in this order) :
	 *			[Field 0] [CATPLMID					] Path : R-I-I-I-... path
	 *			[Field 1] [CATMathTransformation	] ResultMatrix : Last reference absolute position
	 *			[Field 2] [CATMathTransformationList] MatrixPath : List of position matrices of all the references in the path
	 *			[Field 3] [SEQUENCE_octet			] Url : URL where the geometry can be loaded
	 *			[Field 4] [int						] WaterMarkStamp : Object version number
	 *			[Field 5] [CATUnicodeString			] LateType : Gives the late type of the returned object. Can be either "cgr" or "uvr".
	 */
	static const CATUnicodeString QueryMultiWrap;

	/**
	 * Predefined QueryMultiWrap statement : For each input reference, select all the visible external objects whatever the viewpoint is.
	 *
	 * INPUT PARAMETERS (in this order):
	 *		[CATIPLMAsmGeo] : Geometric Assembly.
	 *						  A simple wrap query will be run on each context added to the geometric assembly.
	 *						  Only one config filter is allowed if mono root(=> the same for all the contexts).
	 *						  NO config filter is allowed if multi root(=> at least 2 different roots for 2 contexts)./
	 *		[int]			: Rays density. The same for all the contexts.
	 *
	 * OUTPUT PARAMETERS :
	 *		Before receiving the list of objects associated to a given context, you will receive a pre-result
	 *		notifying to which input context they are associated. 
     *      You can detect the kind of record (pre-result or real result) by checking if the first field if of type
     *      int or CATPLMID.
     *      After reading a pre-result record, all the results records till the the next pre-result record are 
     *      associated to the previously read context.
     *      Once all these results read, you will receive another pre-result, and so on.
	 *		PRE-RESULT (in this order):
	 *			[Field 0] [int]		 : Arbitrary int value (used to detect if it is a pre-result record)
	 *			[Field 1] [CATPLMID] Path R-I-I-I... One of the input contexts at which the
	 *								 following results are associated.
	 *
	 *		RESULTS (in this order) :
	 *			[Field 0] [CATPLMID					] Path : R-I-R-I-... path
	 *			[Field 1] [CATMathTransformation	] ResultMatrix : Last reference absolute position
	 *			[Field 2] [CATMathTransformationList] MatrixPath : List of position matrices of all the references in the path
	 *			[Field 3] [SEQUENCE_octet			] Url : URL where the geometry can be loaded
	 *			[Field 4] [int						] WaterMarkStamp : Object version number
	 *			[Field 5] [CATUnicodeString			] LateType : Gives the late type of the returned object. Can be either "cgr" or "uvr".
	 */
	static const CATUnicodeString QueryMultiWrapRI;

	/**
	 * Check the existence of a query in the server
	 * Input parameters (in this order):
	 *   Query: Tested query (CATUnicodeString)
	 * Output parameters (in this order):
	 *   existence: 1 if the query exists, 0 else (int)
	 */
	static const CATUnicodeString QueryTestExistence;

	/**
	 * Predefined FindInContext statement : Select all the occurrences of a given list of references, in a given context.
	 *
	 * INPUT PARAMETERS (in this order):
	 *		[CATIPLMAsmGeo]		: Geometric assembly. That is the context on which the find will be applied.
	 *		[CATIPLMValueList]	: List of CATPLMID (simple) of the REFERENCES whose occurrences have to be found.
	 *
	 * OUTPUT PARAMETERS (in this order, for each result):
	 *		[Field 0][CATPLMID]						: Result path (R-I-I-I...)
	 *		[Field 1][CATMathTransformation]		: Result matrix
	 *		[Field 2][CATMathTransformationList]	: Matrix path (list of position matrices)
	 */
	static const CATUnicodeString FindInContext;
	
	/**
	 * Predefined FindInContext statement : Select all the occurrences of a given list of references, in a given context.
	 *
	 * INPUT PARAMETERS (in this order):
	 *		[CATIPLMAsmGeo]		: Geometric assembly. That is the context on which the find will be applied.
	 *		[CATIPLMValueList]	: List of CATPLMID (simple) of the REFERENCES whose occurrences have to be found.
	 *
	 * OUTPUT PARAMETERS (in this order, for each result):
	 *		[Field 0][CATPLMID]						: Result path (R-I-R-I...)
	 *		[Field 1][CATMathTransformation]		: Result matrix
	 *		[Field 2][CATMathTransformationList]	: Matrix path (list of position matrices)
	 */
	static const CATUnicodeString FindInContextRI;


    /**
	 * Predefined QueryInstall statement: To check if index server is installed with ENOVIA
	 * Input parameters (in this order):
	 *   (NONE)
	 * Output parameters (in this order):
	 *   bool. True for installed. False for not installed
	 */
	static const CATUnicodeString QueryInstall;

	/**
	 * Predefined QueryCrawlAccessList : Crawl the Access List for the indexed security
	 * 
	 * INPUT (attached to the query, separated by a space) :
	 *		(optionnal) Timestamp of the last indexation for incremental indexation (unix time format)
	 *
	 * OUTPUT :
	 *  A Int is used to indexed the result of the crawl and associates the id of the OV with the accessList
	 *  ':' is used to parse.
	 *		[int]:[int for the id]
	 *		[int]:[CATUnicodeString per accessList. (access.pass[-|Grant.MyCompany.VPLMODTDesignerPrj1_PRJ|-] = yes) ]
	 */
	static const CATUnicodeString QueryCrawlAccessList;

	/**
	 * Predefined QueryCrawlIovDov : Crawl the IOV and DOV of given CATBOID
	 *
	 * INPUT (attached to the query, separated by a space) :
	 *		[ REF | INST ] : REF for representations and references, INST for instances and rep-instances
	 *      [ CATBOID1 CATBOID 2 ... CATBOIDn ] : physicalID dumped as 32 hexa.
	 *		Warning : Not sure of the behaviour if the list exceeds 512 000 elements ..
	 *
	 * OUTPUT :
	 * A Int is used to indexed the result, ':' is used to parse.
	 *		[int]:physicalid:[32 hexa]
	 *      [int]:iov.oid:[8 hexa]
	 *      [int]:dov.oid:[8 hexa]
	 *      Warning : only the line [int]:physicalid:[32 hexa] is mandatory in the output for a given [int]
	 */
	static const CATUnicodeString QueryCrawlIovDov;
};                       

#endif // _CATIPLMIndex_TypeQuery_h_

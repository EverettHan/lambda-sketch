// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
//
//===================================================================
//
//  Jul 2003  Creation: lvl
// Oct. 2004 TPD integration de la nouvelle sortie "Polyedre" du maillage
// Jan. 2006 TPD On rend les w : "GetW" pour l'edge
// Jan. 2006 TPD On rend le CATVertex pour les points 
//===================================================================

#ifndef CATTessCloudOpe_H
#define CATTessCloudOpe_H

#include "TessPolygon.h"

#include "CATTessDiagnostic.h"

#include "CATBooleanDef.h"
#include "CATDataType.h"

class CATTessSettings;

class CATBody;
class CATCldGenEntity;
class CATCldPolygon;
class CATIPolyMesh;
class CATSoftwareConfiguration;
 
#ifndef CATTessFrameworkCaller
#define CATTessFrameworkCallerExpansed(x) #x
#define CATTessFrameworkCaller(x)  CATTessFrameworkCallerExpansed(x)
#endif

//===================================================================
/**
   * Computes the tessellation of a given body with the tessellation settings.
   * @param iBody
   *    The <tt>CATBody</tt> to tessellate.
   * @param iSettings
   *    The <tt>Settings</tt> of the tessellation.
   * @param ioPolygon
   *    The polygon in which the triangles will be added.
   * @param iTriangleInfo
   *    If <tt>>0</tt>, triangles informations will coded within the <tt>CATCldPolygon</tt>.<br>
   *    The informations could be retreived by calling the method <tt>CATCldPolygon::GetTriangleAttribute</tt>,
   *    and will be <tt>CATTessCldTessTriangleInfo</tt>.<br>
   *    <b>CAUTION:<b> These informations must be deleted by the caller.
   *    @see CATTessCldTessInformations, CATCldPolygon
   *                        = 1 : CATFace
   * @param iVertexInfo
   *    If <tt>>0</tt>, vertices informations will coded within the <tt>CATCldPolygon</tt>.
   *    The informations could be retreived by calling the method <tt>CATCldUniCell::GetPointAttribute</tt>,
   *    and will be <tt>CATTessCldTessVertexInfo</tt>.<br>
   *    <b>CAUTION:<b> These informations must be deleted by the caller.
   *    @see CATTessCldTessInformations, CATCldPolygon
   *                               Face informations
   *                        = +  1 : CATFace, UVParameters
   *                       Or    2 : CATFace, UVParameters, Normal
   *                                 ( Only 1 or  2 )
   *                               Edge informations
   *                          +  4 : CATEdge, NuPtDisc
   *                       Or +  8 : CATEdge, NuPtDisc, CrvParameter, QualPts ( Only CXR17 and more )
   * @param QualPts
   * The variable which allows you to determine the CrvParameter  quality:
   * <ul>
   * <li> 0 : CrvParameter impossible computation
   * <li> 1 : CrvParameter exact computation
   * <li> 2 : CrvParameter does not neccessarily correspond to Xyz or Uv (merged points)
   * </ul>
   *                               Vertex informations
   *                          + 16 : CATVertex
   *    if you want all informations iVertexInfo = 26
   * @param iCalInfo
   *                 =  0 : Nothing
   *                 +  1 : Flip edge in strip
   * @param iConfig
   *  If <tt>=NULL</tt>, running without configuration ( the lastest coding configuration is active )
   *  else running with the configuration.
   */
ExportedByTessPolygon CATTessDiagnostic TesselateInCl(CATBody                  * iBody,
						      CATTessSettings          * iSettings,
						      CATCldPolygon            * ioCldPolygon,
						      CATLONG32                  iTriangleInfo,
						      CATLONG32                  iVertexInfo,
						      CATLONG32                  iCalInfo,
						      CATSoftwareConfiguration * iConfig = 0,
                  const char               * iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) ;

ExportedByTessPolygon CATTessDiagnostic TesselateInCl(CATBody                  * iBody,
						      CATTessSettings          * iSettings,
						      CATCldPolygon            * ioCldPolygon,
						      CATLONG32                  iTriangleInfo,
						      CATLONG32                  iVertexInfo,
						      CATLONG32                  iCalInfo,
                  CATBoolean         & iSameResultAsVisu,
						      CATSoftwareConfiguration * iConfig = 0,
                  const char               * iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) ;

ExportedByTessPolygon CATTessDiagnostic NewTesselateInCl(CATBody                  * iBody,
	CATTessSettings          * iSettings,
	CATCldPolygon            * ioCldPolygon,
	CATLONG32                  iTriangleInfo,
	CATLONG32                  iVertexInfo,
	CATLONG32                  iCalInfo,
	CATSoftwareConfiguration * iConfig = 0,
	const char               * iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_));

/*
* This new API provide a way to build a CldPolygon using the new LocalTessellation.
* this new behaviour consists in building a CATIPolyBody whithout any watertighness issue. On top of that, every improvements are enabled in it.
* For this API, we convert the CATIPOlyBody into a CldPolygon
* Check the env variable named in the cpp file is declared, otherwise you could not benefit from the new behaviour
*/
ExportedByTessPolygon CATTessDiagnostic TesselateInCl( CATSoftwareConfiguration* iConfig,
  CATBody* iBody,
  CATTessSettings* iSettings,
  CATCldPolygon* ioCldPolygon,
  CATLONG32                  iTriangleInfo,
  CATLONG32                  iVertexInfo,
  CATLONG32                  iCalInfo,
  CATBoolean iSameResultAsVisu = FALSE,
  const char* iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_));

//#define NEWNEW
#ifdef NEWNEW
#include "CATTessPolyAttrContainers.h"
ExportedByTessPolygon CATTessDiagnostic TesselateInCl(CATBody                  * iBody,
						      CATTessSettings          * iSettings,
						      CATIPolyMesh            * ioCldPolygon,
                  CATTessPolyTriangleAttrContainer * TriangleAttr,
                  CATTessPolyVertexAttrContainer * VertexAttr,
						      CATLONG32                  iTriangleInfo,
						      CATLONG32                  iVertexInfo,
						      CATLONG32                  iCalInfo,
						      CATSoftwareConfiguration * iConfig = 0,
                  const char               * iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) ;

#endif
#endif

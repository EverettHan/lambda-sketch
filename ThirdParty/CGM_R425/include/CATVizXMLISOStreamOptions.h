#ifndef CATVizXMLISOStreamOptions_H
#define CATVizXMLISOStreamOptions_H

#include "CATVisInteropXMLMeshV6.h"
#include "CATUnicodeString.h"
#include "CATSymbolType.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATVizPtrList.h"
#include "CATLib.h"
#include "CATMathPointf.h"


class CATGraphicAttributeSet;
class CATGraphicMaterial;
class CATVizXMLISOStreamer;
class CATRep;
class CATIXMLPPWriter_var;

/*
 * Defines the different elements that can be streamed in XML V6
 * @param CATVizXMLISOFace
 *    The representation of a topological face.
 * @param CATVizXMLISOLOD : not supported yet
 *    The representation of the level of detail of a topological body.
 * @param CATVizXMLISOV4Edge,
 *    The representation of a topological V4 edge that bonds a face.
 * @param CATVizXMLISOBoundaryEdge
 *    The representation of a topological edge that bounds a face.
 * @param CATVizXMLISOInternalSharpEdge
 *    The representation of a G0 continuous topological edge that bounds two faces.
 * @param CATVizXMLISOInternalSmoothEdge
 *    The representation of an at least G1 continuous topological edge.
 * @param CATVizXMLISOWireEdge
 *    The representation of a topological wire (polyline)
 * @param CATVizXMLISOBoundaryPoint
 *    The representation of a topological point that bounds a face.
 * @param CATVizXMLISOInternalSharpePoint
 *    The representation of a G0 continuous topological point.
 * @param CATVizXMLISOInternalSmoothPoint
 *    The representation of an at least G1 continuous topological point.
 * @param CATVizXMLISOSurfacicPoint
 *    The representation of a topological point that lies on a face.
 * @param CATVizXMLISOFreePoint
 *    The representation of a topological point.
 */
typedef enum _CATVizXMLISOType
{
   CATVizXMLISOFace,
   CATVizXMLISOLOD,
   CATVizXMLISOV4Edge,
   CATVizXMLISOBoundaryEdge,
   CATVizXMLISOInternalSharpEdge,
   CATVizXMLISOInternalSmoothEdge,
   CATVizXMLISOWireEdge,
   CATVizXMLISOBoundaryPoint,
   CATVizXMLISOInternalSharpPoint,
   CATVizXMLISOInternalSmoothPoint,
   CATVizXMLISOSurfacicPoint,
   CATVizXMLISOFreePoint
} CATVizXMLISOType;

typedef struct _CATVizXMLISOSetOfOptions
{
   CATBoolean              saveShowSpace;
   CATBoolean              saveNoShowSpace;
   CATBoolean              saveShowFreeSpace;
   CATBoolean              saveMaterials;
   CATBoolean              typesFilter[CATVizXMLISOFreePoint+1];
} CATVizXMLISOSetOfOptions;

#define MASK_FACES_GROUP_MODE 0x00000001
#define MASK_EDGES_CONVERSION 0x00000002
#define MASK_SHOW_SPACE       0x00000004
#define MASK_NOSHOW_SPACE 		0x00000008
#define MASK_SHOWFREE_SPACE   0x00000010
#define MASK_LOD_GENERATION   0x00000020
#define MASK_MATERIALS        0x00000040
#define MASK_TYPES_FILTERS    0x00000080
#define MASK_ALL              (MASK_FACES_GROUP_MODE | MASK_EDGES_CONVERSION | MASK_SHOW_SPACE | MASK_NOSHOW_SPACE | MASK_SHOWFREE_SPACE | MASK_LOD_GENERATION | MASK_MATERIALS | MASK_TYPES_FILTERS)

class ExportedByCATVisInteropXMLMeshV6 CATVizXMLISOStreamOptions
{
public:

   CATVizXMLISOStreamOptions();
   CATVizXMLISOStreamOptions(const CATVizXMLISOStreamOptions & options);
   virtual ~CATVizXMLISOStreamOptions();

   // Creates the associated streamer for the input format
   //virtual CATVizXMLISOStreamer * CreateStreamer() = 0;

   // In order to change the set of options
   void SetStreamingOptions(const CATVizXMLISOSetOfOptions & iSetOfOptions, unsigned int iDataMask = MASK_ALL);

   // In order to retrieve the set of options
   void GetStreamingOptions(CATVizXMLISOSetOfOptions & oSetOfOptions) const;

   // Tells if elements in the ShowSpace are saved
   const CATBoolean SaveShowSpace() const;
   // Tells if elements in the NoShowSpace are saved
   const CATBoolean SaveNoShowSpace() const;
   // Tells if elements in the ShowFreeSpace are saved
   const CATBoolean SaveShowFreeSpace() const;
   // Tells if Materials are saved
   const CATBoolean SaveMaterials() const;
   // Tells whether a specific type must be streamed or not
   const CATBoolean SaveType(const CATVizXMLISOType iType) const;

   CATBoolean FilteringEnabled();
   void       EnableFiltering(CATBoolean iOnOff);
   void       Filter(CATRep & iRep);
   CATBoolean IsFiltered(CATRep & iRep);
   void       ClearFilters();
   
   virtual HRESULT StreamMaterial(CATGraphicMaterial * iMat, CATUnicodeString & iRepId, CATUnicodeString & oLinkIdRef);
   virtual HRESULT UnstreamMaterial(CATUnicodeString & iAppliedAppearanceId, CATGraphicMaterial * oGraphicMaterial);
   virtual HRESULT AddFTALink(int iRep_CGMID, int iGP_CGMID, CATUnicodeString & iXMLID);
   virtual unsigned int GetUniqueID();

   // bounding box
   void SetBoundingBox(CATMathPointf iMin, CATMathPointf iMax);
   void MergeBoundingBox(CATMathPointf iMin, CATMathPointf iMax);
   HRESULT GetBoundingBox(CATMathPointf & oMin, CATMathPointf & oMax);

   virtual HRESULT ComputeTargetFromLinkIdRef(CATUnicodeString & iTagName, CATUnicodeString & iLinkIdRef, CATUnicodeString & oTarget);

protected:
   CATBoolean              _saveShowSpace;
   CATBoolean              _saveNoShowSpace;
   CATBoolean              _saveShowFreeSpace;
   CATBoolean              _saveMaterials;
   CATBoolean              _typesFilter[CATVizXMLISOFreePoint+1];

   CATBoolean              _filteringEnabled;
   CATVizPtrList<CATRep>   _filtered;

   unsigned int _uniqueID;

   CATMathPointf _minAABB;
   CATMathPointf _maxAABB;
};

#endif

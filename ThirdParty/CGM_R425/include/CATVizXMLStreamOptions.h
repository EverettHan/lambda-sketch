#ifndef CATVizXMLStreamOptions_H
#define CATVizXMLStreamOptions_H

#include "CATVisInteropXMLMesh.h"

#include "CATUnicodeString.h"
#include "CATSymbolType.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATVizPtrList.h"
#include "CATLib.h"


class CATGraphicAttributeSet;
class CATGraphicMaterial;
class CATVizXMLStreamer;
class CATRep;
class CATIXMLPPWriter_var;
class CATIMaterialUnstreamRequestHandler;
/*
 * Defines the different faces grouping method available
 * @param CATVizXMLGroupNone
 *    Save each faces individually. Preserves topology.
 * @param CATVizXMLGroupAllInOne
 *    Group all faces into one big face (Only the dominant color of all the faces will be preserved).
 * @param CATVizXMLGroupByColor
 *    Group all faces by color.
 */
typedef enum _CATVizXMLFacesGroupMode
{
   CATVizXMLGroupNone,
   CATVizXMLGroupAllInOne,
   CATVizXMLGroupByColor,
} CATVizXMLFacesGroupMode;

/*
 * Defines the different elements that can be streamed in XML
 * @param CATVizXMLFace
 *    The representation of a topological face.
 * @param CATVizXMLLOD
 *    The representation of the level of detail of a topological body.
 * @param CATVizXMLV4Edge,
 *    The representation of a topological V4 edge that bonds a face.
 * @param CATVizXMLBoundaryEdge
 *    The representation of a topological edge that bounds a face.
 * @param CATVizXMLInternalSharpEdge
 *    The representation of a G0 continuous topological edge that bounds two faces.
 * @param CATVizXMLInternalSmoothEdge
 *    The representation of an at least G1 continuous topological edge.
 * @param CATVizXMLWireEdge
 *    The representation of a topological wire (polyline)
 * @param CATVizXMLBoundaryPoint
 *    The representation of a topological point that bounds a face.
 * @param CATVizXMLInternalSharpePoint
 *    The representation of a G0 continuous topological point.
 * @param CATVizXMLInternalSmoothPoint
 *    The representation of an at least G1 continuous topological point.
 * @param CATVizXMLSurfacicPoint
 *    The representation of a topological point that lies on a face.
 * @param CATVizXMLFreePoint
 *    The representation of a topological point.
 */
typedef enum _CATVizXMLType
{
   CATVizXMLFace,
   CATVizXMLLOD,
   CATVizXMLV4Edge,
   CATVizXMLBoundaryEdge,
   CATVizXMLInternalSharpEdge,
   CATVizXMLInternalSmoothEdge,
   CATVizXMLWireEdge,
   CATVizXMLBoundaryPoint,
   CATVizXMLInternalSharpPoint,
   CATVizXMLInternalSmoothPoint,
   CATVizXMLSurfacicPoint,
   CATVizXMLFreePoint,
} CATVizXMLType;

/*
 * Defines the different streaming format available
 * @param CATVizXML3DXML
 *    Standard 3DXML
 * @param CATVizXMLXAML
 *    Microsoft (r) XAML description language
 */
typedef enum _CATVizXMLFormat
{
   CATVizXML3DXML,
   CATVizXMLXAML,
} CATVizXMLFormat;

/*
 * Defines the different unstreaming mode available
 * @param CATVizXMLV5Mode
 *    Creates a standard V5 SceneGraph (default)
 * @param CATVizXMLXAML
 *    Creates a LiveShape SceneGraph
 */
typedef enum _CATVizXMLUnStreamMode
{
   CATVizXMLV5Mode,
   CATVizXMLLiveShapeMode,
} CATVizXMLUnStreamMode;

typedef struct _CATVizXMLSetOfOptions
{
   CATVizXMLFacesGroupMode facesGroupMode;
   CATBoolean              convertEdgesToLines;
   CATBoolean              saveShowSpace;
   CATBoolean              saveNoShowSpace;
   CATBoolean              saveShowFreeSpace;
   CATBoolean              allowLODGeneration;
   CATBoolean              saveMaterials;
   CATBoolean              typesFilter[CATVizXMLFreePoint+1];
} CATVizXMLSetOfOptions;

#define MASK_FACES_GROUP_MODE 0x00000001
#define MASK_EDGES_CONVERSION 0x00000002
#define MASK_SHOW_SPACE       0x00000004
#define MASK_NOSHOW_SPACE 		0x00000008
#define MASK_SHOWFREE_SPACE   0x00000010
#define MASK_LOD_GENERATION   0x00000020
#define MASK_MATERIALS        0x00000040
#define MASK_TYPES_FILTERS    0x00000080
#define MASK_ALL              (MASK_FACES_GROUP_MODE | MASK_EDGES_CONVERSION | MASK_SHOW_SPACE | MASK_NOSHOW_SPACE | MASK_SHOWFREE_SPACE | MASK_LOD_GENERATION | MASK_MATERIALS | MASK_TYPES_FILTERS)

class ExportedByCATVisInteropXMLMesh CATVizXMLStreamOptions
{
public:

   CATVizXMLStreamOptions(const CATVizXMLFormat iFormat = CATVizXML3DXML);
   CATVizXMLStreamOptions(const CATVizXMLStreamOptions & options);
   virtual ~CATVizXMLStreamOptions();

   // Creates the associated streamer for the input format
   CATVizXMLStreamer * CreateStreamer();

   // In order to change the set of options
   void SetStreamingOptions(const CATVizXMLSetOfOptions & iSetOfOptions, unsigned int iDataMask = MASK_ALL);

   // In order to retrieve the set of options
   void GetStreamingOptions(CATVizXMLSetOfOptions & oSetOfOptions) const;

   // Can be overloaded in order to define a custom default attribute for faces
   virtual const CATGraphicAttributeSet & GetDefaultFaceAttribute() const;
   // Can be overloaded in order to define a custom default attribute for lines
   virtual const CATGraphicAttributeSet & GetDefaultLineAttribute() const;
   // Can be overloaded in order to define a custom default attribute for edges
   virtual const CATGraphicAttributeSet & GetDefaultEdgeAttribute() const;
   // Can be overloaded in order to define a custom default attribute for points
   virtual const CATGraphicAttributeSet & GetDefaultPointAttribute() const;
   // Can be overloaded in order to define a custom default symbol for points
   virtual const CATSymbolType GetDefaultPointSymbol() const;

   // Tell which grouping method must be applied on the faces
   const CATVizXMLFacesGroupMode FacesGroupMode() const;

   // Returns the target streaming format
   const CATVizXMLFormat GetStreamingFormat() const;

   // Tell if edges are converted into lines
   // WARNING : Edges WILL be saved as lines if faces are grouped (ie FacesGroupMode() != CATVizXMLGroupNone)
   // and this option will be overriden if it is the case.
   const CATBoolean ConvertEdgesToLines() const;

   // Tells whether a specific type must be streamed or not
   const CATBoolean SaveType(const CATVizXMLType iType) const;

   // Tells if elements in the ShowSpace are saved
   const CATBoolean SaveShowSpace() const;
   // Tells if elements in the NoShowSpace are saved
   const CATBoolean SaveNoShowSpace() const;
   // Tells if elements in the ShowFreeSpace are saved
   const CATBoolean SaveShowFreeSpace() const;

   // Tells if LODs can be dynamically generated when none are already available
   // and they are requested (ie : SaveType(CATVizXMLLOD) returns TRUE)
   const CATBoolean AllowLODGeneration() const;

   // Tells if Materials are saved
   const CATBoolean SaveMaterials() const;

   // Set material streaming late type used to call interface CATIXMLMeshMaterialStreaming
   void SetMaterialStreamLateType(const CATUnicodeString & iStreamLateType);

   // Set/Get material unstreaming late type used to call interface CATIXMLMeshMaterialStreaming
   void SetMaterialUnStreamLateType(const CATUnicodeString & iUnStreamLateType);
   const CATUnicodeString & GetMaterialUnStreamLateType();

   void SetAsyncMaterialUnStreaming(CATBoolean iOnOff);
   void SetMaterialUnstreamRequestHandler(CATIMaterialUnstreamRequestHandler *handler);
   CATIMaterialUnstreamRequestHandler *GetMaterialUnstreamRequestHandler();
   CATBoolean GetAsyncMaterialUnStreaming();

   // Must be overriden in order to handle material streaming / unstreaming
   virtual HRESULT StreamMaterial   (CATGraphicMaterial & iMaterial, CATIXMLPPWriter_var & oWriter);

   void SetUnStreamMode(const CATVizXMLUnStreamMode & iUnStreamMode);
   CATVizXMLUnStreamMode GetUnStreamMode();

   inline CATBoolean FilteringEnabled();
   inline void       EnableFiltering(CATBoolean iOnOff);
   inline void       Filter(CATRep & iRep);
   inline CATBoolean IsFiltered(CATRep & iRep);
   inline void       ClearFilters();

private :

   CATVizXMLFormat         _format;
   CATVizXMLFacesGroupMode _facesGroupMode;
   CATBoolean              _edgesConversion;
   CATBoolean              _saveShowSpace;
   CATBoolean              _saveNoShowSpace;
   CATBoolean              _saveShowFreeSpace;
   CATBoolean              _allowLODGeneration;
   CATBoolean              _saveMaterials;
   CATBoolean              _typesFilter[CATVizXMLFreePoint+1];
   CATBoolean              _asyncMaterialUnstreaming;
   CATUnicodeString        _materialsStreamLateType;
   CATUnicodeString        _materialsUnStreamLateType;
   CATVizXMLUnStreamMode   _unstreamMode;

   CATBoolean              _filteringEnabled;
   CATVizPtrList<CATRep>   _filtered;
   CATIMaterialUnstreamRequestHandler *_materialUnstreamRequestHandler;
};

inline CATBoolean CATVizXMLStreamOptions::FilteringEnabled()
{
   static int override = (CATGetEnv("CATVisXMLStreamFilters")) ? atoi(CATGetEnv("CATVisXMLStreamFilters")) : -1;
   if(override != -1)
      return override;
   
   return _filteringEnabled;
}

inline void CATVizXMLStreamOptions::EnableFiltering(CATBoolean iOnOff)
{
   _filteringEnabled = iOnOff;
}

inline void CATVizXMLStreamOptions::Filter(CATRep & iRep)
{
   _filtered.AddTail(&iRep);
}

inline CATBoolean CATVizXMLStreamOptions::IsFiltered(CATRep & iRep)
{
   return (_filtered.Find(&iRep) >= 0) ;
}

inline void CATVizXMLStreamOptions::ClearFilters()
{
   _filtered.Empty();
}


#endif

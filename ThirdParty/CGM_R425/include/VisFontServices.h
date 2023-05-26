#ifndef VisFontServices_H
#define VisFontServices_H

#include "CATUnicodeString.h"
#include "SGInfra.h"
#include "CATFont.h"

/*
* Criteria to use while returning requested font(requested font may or may not available on system).
*		Exact     : Font Mapping will not be used, requested font will be returned else NULL.
*		BestMatch : Mapping used, Exact font OR mapping with best font match else NULL.
*		Acceptable: Mapping used, Exact font OR mapping with best font match OR acceptable font match else NULL.
*		DefaultMap : Mapping used, Exact font OR mapping with best font match OR acceptable font match else default mapped font is returned.
*/
enum CATFontMapping { Exact, BestMatch, Acceptable, DefaultMap };

class ExportedBySGInfra VisFontServices
{
  friend class CATFontStaticEnvironment;
public:

  VisFontServices(const VisFontServices&) = delete;
  VisFontServices& operator =(const VisFontServices&) = delete;
  /*
    Singleton implementation of VisFontServices, Use GetVisFontServices to get the instance of this class
  */
  static VisFontServices* GetVisFontServices();
  /*
  @param iFontName : Input font file name / Font Name 
  @param fontstyle : Input font style (Regular, Bold, Italic, BoldItalic)
  @param mappingMode : Input enum CATFontMapping(refer above declaration)
  @param iVersion : Input text version, use CATFont:: sGetVisuFontCurrentVersion
  */
  CATFont* GetFont(const CATUnicodeString& iFontName, CATFontStyle fontStyle = Regular, CATFontMapping mappingMode = DefaultMap, const unsigned int iVersion = 0xFFFFFFFF);

  /*
*  iText             : Input Text string
*  iAttributeSet     : Input parameters for Text
*  iFont             : Input Font with which Text to be stroked
*  oPolylineList     : Output stroked Polyline
*  oTriPrimitiveList : Output stroked triangle list.
*/
  HRESULT GetStrokedText(const CATUnicodeString& iText, const CATFont* iFont, const CAT2DGeomTextAttributeSet iAttributeSet, CAT2DGeomTextPolylineList*& oPolylineList, CAT2DGeomTextTriPrimitiveList*& oTriPrimitiveList);

private:
  VisFontServices();
  ~VisFontServices();
  static void sCleanup();
  void InitFontInfoCache();
  static VisFontServices* servicesObj;

  struct FontInformationCache
  {
    CATUnicodeString _FileName;
    CATUnicodeString _FontName;
    CATUnicodeString _FamilyType;
    CATFontStyle _FontStyle;
    int _index;
  };

  FontInformationCache* m_FontInformation;

};

#endif


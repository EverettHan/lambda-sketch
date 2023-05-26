#if !defined(__CATOmbKey_h__)
#define __CATOmbKey_h__
/**
* @level Private
* @usage U1
*/

#include "CATObjectModelerBase.h"
#include "CATUnicodeString.h"
#include "sequence_octet.h"

//
// this class publish usefull CATUnicodeString defined in Omb
// and which can be used by other guys
//

// use this tag in order to declare new key
#define DECLARE_OMBKEY(a) const CATUnicodeString k##a;
#define DECLARE_OMBOCTETKEY(a) const SEQUENCE(octet) ko##a;

#define OMBKEY(a) theCATOmbKey.k##a
#define OMBOCTETKEY(a) theCATOmbKey.ko##a
#define OMBOCTETINTEGERKEY(a) theCATOmbKey.koInteger##a


class ExportedByCATObjectModelerBase CATOmbKey
{
public:
  CATOmbKey();
  ~CATOmbKey();
public :
  DECLARE_OMBKEY(File)
  DECLARE_OMBKEY(TeamPDM)
  DECLARE_OMBKEY(Author)
  DECLARE_OMBKEY(CatBackPath)
  DECLARE_OMBKEY(CatBackVersion)
  DECLARE_OMBKEY(CatBackLevel) //CATBack R205
  DECLARE_OMBKEY(CATBuildLevel)
  DECLARE_OMBKEY(CATIA)
  DECLARE_OMBKEY(CATInformations)
  DECLARE_OMBKEY(CATPDMPersistence)
  DECLARE_OMBKEY(CATPreview)
  DECLARE_OMBKEY(CATProjectFlags)
  DECLARE_OMBKEY(CATPropertySet)
  DECLARE_OMBKEY(CATSummaryInformation)
  DECLARE_OMBKEY(CATUserProperties)
  DECLARE_OMBKEY(Day)
  DECLARE_OMBKEY(DocProperty)
  DECLARE_OMBKEY(Hour)
  DECLARE_OMBKEY(LastSaveVersion)
  DECLARE_OMBKEY(MinimalVersionToRead)
  DECLARE_OMBKEY(Minute)
  DECLARE_OMBKEY(Month)
  DECLARE_OMBKEY(ProjectFlags)
  DECLARE_OMBKEY(Second)
  DECLARE_OMBKEY(Thumbnail)
  DECLARE_OMBKEY(ThumbnailFormat)
  DECLARE_OMBKEY(Year)
  DECLARE_OMBKEY(OMBDocument_0001)
  DECLARE_OMBKEY(SelectiveLoadingCache)
  DECLARE_OMBKEY(TemporaryCache)
  DECLARE_OMBKEY(OMBFileCache)
  DECLARE_OMBKEY(GenericLocate)
  DECLARE_OMBKEY(CATUnloadable)
  DECLARE_OMBKEY(CATLinkNotChecked)
  DECLARE_OMBKEY(CDMAmodel)
  DECLARE_OMBKEY(model)
  DECLARE_OMBKEY(cgr)
  DECLARE_OMBKEY(CATSpecClip)
  DECLARE_OMBKEY(Null)
  DECLARE_OMBKEY(VOLocator)
  DECLARE_OMBKEY(CATPLMIDLocator)
  DECLARE_OMBKEY(Unknown)
  DECLARE_OMBKEY(Reference)
  DECLARE_OMBKEY(Default)
  DECLARE_OMBKEY(ENOVIA5)
  DECLARE_OMBKEY(TestDocEnv)


  DECLARE_OMBOCTETKEY(Null)
  DECLARE_OMBOCTETKEY(o)
  DECLARE_OMBOCTETKEY(r)
  DECLARE_OMBOCTETKEY(d)
  DECLARE_OMBOCTETKEY(GenericLocate)
  DECLARE_OMBOCTETKEY(DocId)
  DECLARE_OMBOCTETKEY(File)
  DECLARE_OMBOCTETKEY(CATWin)
  DECLARE_OMBOCTETKEY(Undef)
  DECLARE_OMBOCTETKEY(CATUnloadable)
  DECLARE_OMBOCTETKEY(CATIA)
  DECLARE_OMBOCTETKEY(CATLinkNotChecked)
  DECLARE_OMBOCTETKEY(CATSpecClip)
  DECLARE_OMBOCTETKEY(CDMAmodel)
  DECLARE_OMBOCTETKEY(model)
  DECLARE_OMBOCTETKEY(CATData)
  DECLARE_OMBOCTETKEY(VOLocator)
  DECLARE_OMBOCTETKEY(CATPLMIDLocator)
  DECLARE_OMBOCTETKEY(TestBedRelLocator)
  DECLARE_OMBOCTETKEY(CATPrdXMLGeometryLocator)
  DECLARE_OMBOCTETKEY(CATSDM)
  DECLARE_OMBOCTETKEY(CATSDMN)
  SEQUENCE(octet) koInteger1;

  DECLARE_OMBKEY(CATIA1);
};
extern ExportedByCATObjectModelerBase CATOmbKey theCATOmbKey;

#endif


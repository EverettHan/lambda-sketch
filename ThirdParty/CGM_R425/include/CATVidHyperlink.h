#ifndef CATVidHyperlink_H
#define CATVidHyperlink_H

#include <VisuDialog.h>
#include <CATUnicodeString.h>
#include <CATVidURL.h>

class ExportedByVisuDialog CATVidHyperlink
{
public:
  CATVidHyperlink()
  {
    _visitedFlag=0;
  }
  CATVidHyperlink(const CATVidURL& i_url, const CATUnicodeString& i_tooltip, int i_visitedFlag)
  {
    _url = i_url;
    _tooltip = i_tooltip;
    _visitedFlag = i_visitedFlag;
  }
  CATVidHyperlink(const CATVidHyperlink& i_toCopy)
  {
    *this = i_toCopy;
  }
  ~CATVidHyperlink(){}
  CATVidHyperlink& operator= (const CATVidHyperlink& i_toCopy)
  {
    _url = i_toCopy._url;
    _tooltip = i_toCopy._tooltip;
    _visitedFlag = i_toCopy._visitedFlag;
    return *this;
  }
  int operator== (const CATVidHyperlink& i_toCompare) const
  {
    if (_url != i_toCompare._url || _tooltip != i_toCompare._tooltip || _visitedFlag != i_toCompare._visitedFlag)
      return 0;
    else
      return 1;
  }
  void SetURL(const CATVidURL& i_url){_url=i_url;}
  const CATVidURL& GetURL() const{return _url;}
  void SetTooltip(const CATUnicodeString& i_tooltip){_tooltip = i_tooltip;}
  const CATUnicodeString& GetTooltip() const{return _tooltip;}
  void SetVisitedFlag(int i_visitedFlag){ _visitedFlag =i_visitedFlag;}
  int GetVisitedFlag() const {return _visitedFlag;}
private:
  CATVidURL _url;
  CATUnicodeString _tooltip;
  int _visitedFlag;
};


//-----------------------------------------------------------------------
#include <CATSYPFactoryResult.h>

extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidHyperlinkFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidHyperlinkSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif

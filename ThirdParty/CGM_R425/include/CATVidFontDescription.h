//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidFontDescription_H
#define CATVidFontDescription_H

#include <VisuDialog.h>
#include <CATSYPMacros.h>
#include <CATVidFontDescription.h>
#include <CATUnicodeString.h>

class ExportedByVisuDialog CATVidFontDescription
{
  FORCE_STACK_ALLOCATION();
public:
  /** Constructor */
  CATVidFontDescription();
  /** Constructor */
  CATVidFontDescription(int i_size, int i_boldFlag=0, int i_italicFlag=0, const char* i_pFamily=0);
  /** Destructor */
  ~CATVidFontDescription(){};
  /** Copy Constructor */
  CATVidFontDescription(const CATVidFontDescription& i_Init);
  /** Operator != */
  int operator == (const CATVidFontDescription & i_Right) const;
  /** Operator == */
  int operator != (const CATVidFontDescription & i_Right) const;
  /** Operator = */
  CATVidFontDescription& operator =(const CATVidFontDescription& i_Right);
  void SetFamily(const CATUnicodeString& i_family){_family=i_family;}
  const CATUnicodeString& GetFamily() const {return _family;}
  void SetBoldFlag(int i_boldFlag){_boldFlag=i_boldFlag;}
  int GetBoldFlag() const{return _boldFlag;}
  void SetItalicFlag(int i_italicFlag){_italicFlag=i_italicFlag;}
  int GetItalicFlag() const{return _italicFlag;}
  /** @param i_size the size in px (pixels) */
  void SetSize(int i_size){_size=i_size;}
  /** @return the size in (pixels) */
  int GetSize() const{return _size;}
private:
  CATUnicodeString _family;
  unsigned int _boldFlag   :1;
  unsigned int _italicFlag :1;
  unsigned int _size       :30;
};

//-----------------------------------------------------------------------
#include <CATSYPFactoryResult.h>
extern "C" ExportedByVisuDialog
    CATSYPFactoryResult
    CATSYPCATVidFontDescriptionFactory(const CATUnicodeString &i_string);
extern "C" ExportedByVisuDialog
    HRESULT
    CATSYPCATVidFontDescriptionSerializer(const CATBaseUnknown_var &i_spCBU, CATUnicodeString &o_string);

#endif

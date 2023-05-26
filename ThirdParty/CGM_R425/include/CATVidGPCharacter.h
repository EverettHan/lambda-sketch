// COPYRIGHT Dassault Systemes 2005
//===================================================================
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidGPCharacter_H
#define CATVidGPCharacter_H

#include <VisuDialog.h>
#include <CATVidGP.h>
#include <CATVidEnum.h>
#include <CATUnicodeChar.h>
#include <CATVidColor.h>
#include <CATVid.h>
#include <CATVidFontDescription.h>
#include <CATBoolean.h>
#include <CATUnicodeChar.h>
#include <CATVidBorder.h>
#include <CATFreeType.h>

/**
 * @ingroup VIDGP
 * 
 * The Label is used to display a single line of text.
 * It has very basic font management, if you need more control on the text displayed, you can use #CATVidCtlLineEditor in Read-Only
 */
class ExportedByVisuDialog CATVidGPCharacter: public CATVidGP
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  CATVidGPCharacter();

  void SetText(const CATUnicodeChar& i_text);
  const CATUnicodeChar&GetText() const;

  void SetFontDescription(const CATVidFontDescription& i_fontDescription);
  const CATVidFontDescription& GetFontDescription() const;

  void SetFontSize(int i_fontSize);
  int GetFontSize() const {return _fontDescription.GetSize();}

  // Set/Get text color
  void SetTextColor(const CATVidColor& i_color);
  const CATVidColor& GetTextColor() const;
  /** 
   * Sets the margins used around the layout.
   * By default, these margins are null.
   */
  void SetContentsMargins(const CATVidBorder& i_contentsMargins);
  /**
   * @return the margins used around the layout.
   */
  INLINE const CATVidBorder& GetContentsMargins() const 
  {
    return _contentsMargins;
  }

protected:
	virtual ~CATVidGPCharacter();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidGPCharacter(CATVidGPCharacter &);
  CATVidGPCharacter& operator=(CATVidGPCharacter&);

  virtual HRESULT BuildRep();

  // protected virtual fron CATVidWidget
  virtual void UpdateComputedMinimumDimension();
private:
  void Empty();
private:
  CATVidBorder _contentsMargins;
  CATVidColor _color;
  CATUnicodeChar _character;
  CATVidFontDescription _fontDescription;
  CATFreeType::ImageMetrics _glyphMetrics;
  CATFreeType::GlobalMetrics _fontMetrics;
  friend class l_CATVidGPCharacter;
};

#endif

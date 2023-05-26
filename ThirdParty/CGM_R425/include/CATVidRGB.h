//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidRGB_H
#define CATVidRGB_H

#include <VisuDialog.h>
/**
 * @ingroup VIDCore
 * Class CATVidRGB
 */
class ExportedByVisuDialog CATVidRGB
{
public:
  /** Constructor, creates black color*/
  CATVidRGB ();
  /** Constructor */
  CATVidRGB (const unsigned char i_r, const unsigned char i_g, const unsigned char i_b);
  /** Copy constructor */
  CATVidRGB (const CATVidRGB &i_original);
  /** Non virtual destructor! Warning with inheritance*/
  ~CATVidRGB ();
  /** operator= */
  CATVidRGB& operator=(const CATVidRGB& i_original);
  /** Sets the red component */
  void SetR(const unsigned char i_r);
  /** @return the red component */
  unsigned char GetR() const;
  /** Sets the green component */
  void SetG(const unsigned char i_g);
  /** @return the green component */
  unsigned char GetG() const;
  /** Sets the blue component */
  void SetB(const unsigned char i_b);
  /** @return the blue component */
  unsigned char GetB() const;
  /** Sets the RGB component */
  void Set(const unsigned char i_r, const unsigned char i_g, const unsigned char i_b);
  /** Gets the RGB component */
  void Get(unsigned char& o_r, unsigned char& o_g, unsigned char& o_b) const;
private:
  unsigned char _r;
  unsigned char _g;
  unsigned char _b;
};

ExportedByVisuDialog int operator==(const CATVidRGB& i_left, const CATVidRGB& i_right);
ExportedByVisuDialog int operator!=(const CATVidRGB& i_left, const CATVidRGB& i_right);

//-----------------------------------------------------------------------
#include <CATSYPFactoryResult.h>
#include <CATUnicodeString.h>
class CATBaseUnknown_var;
extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidRGBFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidRGBSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif

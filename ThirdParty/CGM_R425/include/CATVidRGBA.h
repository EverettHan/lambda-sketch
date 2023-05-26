//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidRGBA_H
#define CATVidRGBA_H

#include <VisuDialog.h>
#include <CATVidRGB.h>
/**
 * @ingroup VIDCore
 * Class CATVidRGBA
 */
class ExportedByVisuDialog CATVidRGBA
{
public:
  static double ConvertLinearToSRGB(double iValue);
  static double ConvertSRGBToLinear(double iValue);

  static CATVidRGBA ConvertSRGBToLinear(const CATVidRGBA i_rgba);
  static CATVidRGBA ConvertLinearToSRGB(const CATVidRGBA i_rgba);
  static void ConvertToFloatHSL (const CATVidRGBA i_rgba, float& oH, float& oS, float& oL);
  static CATVidRGBA ConvertFromFloatHSL (float iH, float iS, float iL);

  /** Constructor, creates black color*/
  CATVidRGBA ();
  /** Constructor */
  CATVidRGBA (const unsigned char i_r, const unsigned char i_g, const unsigned char i_b, const unsigned char i_a);
  /** Copy constructor */
  CATVidRGBA (const CATVidRGBA &i_original);
  /** Non virtual destructor! Warning with inheritance*/
  ~CATVidRGBA ();
  /** operator= */
  CATVidRGBA& operator=(const CATVidRGBA& i_original);
  /** Sets the red component */
  void SetR(const unsigned char i_r);
  /** @return the red component */
  const unsigned char& GetR() const;
  /** Sets the green component */
  void SetG(const unsigned char i_g);
  /** @return the green component */
  const unsigned char& GetG() const;
  /** Sets the blue component */
  void SetB(const unsigned char i_b);
  /** @return the blue component */
  const unsigned char& GetB() const;
  /** Sets the alpha component */
  void SetA(const unsigned char i_a);
  /** @return the alpha component */
  const unsigned char& GetA() const;
  /** Sets the RGBA component */
  void Set(const unsigned char i_r, const unsigned char i_g, const unsigned char i_b, const unsigned char i_a);
  /** Gets the RGBA component */
  void Get(unsigned char& o_r, unsigned char& o_g, unsigned char& o_b, unsigned char& o_a) const;
  /** Gets a RGB component */
  CATVidRGB GetRGB() const;

  inline float GetRFloat()const { return _r; }  
  inline float GetGFloat()const { return _g; }
  inline float GetBFloat()const { return _b; }
  inline float GetAFloat()const { return _a; }

  void SetFloat(float i_r, float i_g, float i_b, float i_a);

private:
  float _r;
  float _g;
  float _b;
  float _a;
  unsigned char _rChar;  
  unsigned char _gChar;  
  unsigned char _bChar;  
  unsigned char _aChar;
};

ExportedByVisuDialog int operator==(const CATVidRGBA& i_left, const CATVidRGBA& i_right);
ExportedByVisuDialog int operator==(const CATVidRGB& i_left, const CATVidRGBA& i_right);
ExportedByVisuDialog int operator==(const CATVidRGBA& i_left, const CATVidRGB& i_right);

ExportedByVisuDialog int operator!=(const CATVidRGBA& i_left, const CATVidRGBA& i_right);
ExportedByVisuDialog int operator!=(const CATVidRGB& i_left, const CATVidRGBA& i_right);
ExportedByVisuDialog int operator!=(const CATVidRGBA& i_left, const CATVidRGB& i_right);

//-----------------------------------------------------------------------
#include <CATSYPFactoryResult.h>
#include <CATUnicodeString.h>
class CATBaseUnknown_var;
extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidRGBAFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidRGBASerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif

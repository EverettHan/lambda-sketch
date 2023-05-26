//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidRGBAGradient_H
#define CATVidRGBAGradient_H

#include <VisuDialog.h>
#include <CATVidRGBA.h>

/**
 * @ingroup VIDCore
 * Class CATVidRGBAGradient
 */
class ExportedByVisuDialog CATVidRGBAGradient
{
public:
  /** Constructor, creates color gradient*/
  CATVidRGBAGradient ();
  /** Constructor */
  CATVidRGBAGradient (const CATVidRGBA i_StartColor, const CATVidRGBA i_EndColor);
  /** Copy constructor */
  CATVidRGBAGradient (const CATVidRGBAGradient &i_original);
  /** Non virtual destructor! Warning with inheritance*/
  ~CATVidRGBAGradient ();
  /** operator= */
  CATVidRGBAGradient& operator=(const CATVidRGBAGradient& i_original);
  /** Sets the red component */
  void SetStartColor(const CATVidRGBA i_StartColor);
  /** @return the red component */
  const CATVidRGBA & GetStartColor() const;
  /** Sets the green component */
  void SetEndColor(const CATVidRGBA i_EndColor);
  /** @return the green component */
  const CATVidRGBA & GetEndColor() const;
  /** @return the green component */
  void SetCurrentColor(const CATVidRGBA i_CurrentColor);
  /** @return the green component */
  const CATVidRGBA & GetCurrentColor() const;
 
private:
  CATVidRGBA _startColor;
  CATVidRGBA _endColor;
  CATVidRGBA _currentColor;
};

ExportedByVisuDialog int operator==(const CATVidRGBAGradient& i_left, const CATVidRGBAGradient& i_right);
ExportedByVisuDialog int operator!=(const CATVidRGBAGradient& i_left, const CATVidRGBAGradient& i_right);

#include <CATSYPFactoryResult.h>
#include <CATUnicodeString.h>
class CATBaseUnknown_var;
extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidRGBAGradientFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidRGBAGradientSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif

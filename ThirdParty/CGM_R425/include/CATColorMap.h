#ifndef CATColorMap_H
#define CATColorMap_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"

/**
 * Class to create a table of 256 indexed colors.
 * <b>Role</b>: This class permits to have a relationship between an indexed
 * color and its red, green and blue components. <br>
 * The table index ranges from 0 to 255. <br>
 */
class ExportedBySGInfra CATColorMap
{
  friend class CATColorMapHelper;
 public :

  /** Constructs a default color map. */
  CATColorMap ();

  /** Constructs a color map by copy.
   * @param iColorMap
   * The color map to be copied.
   */
  CATColorMap (const CATColorMap & iColorMap);

  /** Deletes the color map. */
  virtual ~CATColorMap ();

  /** Sets the red, green and blue components of an indexed color.
   * @param iIndex
   * The index of the color.
   * <b>Legal values</b>: <tt>iIndex</tt> ranges from 0 to 255. 
   * @param iRed
   * The red component of the color.
   * <b>Legal values</b>: <tt>iRed</tt> ranges from 0.0 to 1.0. 
   * @param iGreen
   * The green component of the color.
   * <b>Legal values</b>: <tt>iGreen</tt> ranges from 0.0 to 1.0. 
   * @param iBlue
   * The blue component of the color.
   * <b>Legal values</b>: <tt>iBlue</tt> ranges from 0.0 to 1.0. 
   */
  void SetColor (const int iIndex, const float iRed, const float iGreen, const float iBlue);

  /** Retrieves the red, green and blue components of an indexed color.
   * @param iIndex
   * The index of the color to be read.
   * <b>Legal values</b>: <tt>iIndex</tt> ranges from 0 to 255. 
   * @param oRed
   * The red component of the color.
   * <b>Legal values</b>: <tt>oRed</tt> ranges from 0.0 to 1.0. 
   * @param oGreen
   * The green component of the color.
   * <b>Legal values</b>: <tt>oGreen</tt> ranges from 0.0 to 1.0. 
   * @param oBlue
   * The blue component of the color.
   * <b>Legal values</b>: <tt>oBlue</tt> ranges from 0.0 to 1.0. 
   */
  void GetColor (const int iIndex, float *oRed, float *oGreen, float *oBlue);


  /** Sets the red, green and blue components of an indexed color.
   * @param iIndex
   * The index of the color.
   * <b>Legal values</b>: <tt>iIndex</tt> ranges from 0 to 255. 
   * @param iRed
   * The red component of the color.
   * <b>Legal values</b>: <tt>iRed</tt> ranges from 0 to 255.
   * @param iGreen
   * The green component of the color.
   * <b>Legal values</b>: <tt>iGreen</tt> ranges from 0 to 255.
   * @param iBlue
   * The blue component of the color.
   * <b>Legal values</b>: <tt>iBlue</tt> ranges from 0 to 255.
   */
  void SetColor (const int iIndex, const int iRed, const int iGreen, const int iBlue);

  /** Retrieves the red, green and blue components of an indexed color.
   * @param iIndex
   * The index of the color to be read.
   * <b>Legal values</b>: <tt>iIndex</tt> ranges from 0 to 255. 
   * @param oRed
   * The red component of the color.
   * <b>Legal values</b>: <tt>oRed</tt> ranges from 0 to 255.
   * @param oGreen
   * The green component of the color.
   * <b>Legal values</b>: <tt>oGreen</tt> ranges from 0 to 255.
   * @param oBlue
   * The blue component of the color.
   * <b>Legal values</b>: <tt>oBlue</tt> ranges from 0 to 255.
   */
  void GetColor (const int Index, int *oRed, int *oGreen, int *oBlue);

  /** Returns the index of the indexed foreground color for the red, green and 
   * blue components specified.
   * @param iRed
   * The red component of the color.
   * <b>Legal values</b>: <tt>iRed</tt> ranges from 0.0 to 1.0.
   * @param iGreen
   * The green component of the color.
   * <b>Legal values</b>: <tt>iGreen</tt> ranges from 0.0 to 1.0.
   * @param iBlue
   * The blue component of the color.
   * <b>Legal values</b>: <tt>iBlue</tt> ranges from 0.0 to 1.0.
   */
  int GetForegroundColor (const float iRed, const float iGreen, const float iBlue);

 private :
  
  float _index[256][3];
};



#endif

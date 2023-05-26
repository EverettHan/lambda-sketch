/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATAdvancedLayer for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATAdvancedLayer_H
#define CATAdvancedLayer_H

#include "SGInfra.h"

class ExportedBySGInfra CATAdvancedLayer
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATAdvancedLayer();
	virtual ~CATAdvancedLayer();

	// Copy constructor and equal operator
	// -----------------------------------
	CATAdvancedLayer(const CATAdvancedLayer&);
	CATAdvancedLayer& operator=(const CATAdvancedLayer&);

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATAdvancedLayer&);

   /** Sets the red, green, blue components color.
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
   inline void SetColorRGB(const unsigned int iRed, const unsigned int iGreen, const unsigned int iBlue);

	/** Retrieves the red, green, blue and alpha color components.
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
	inline void GetColorRGB(unsigned int* oRed, unsigned int* oGreen, unsigned int* oBlue) const;

	/** Sets the Transparency.
	* @param iTransparency
	* The Transparency index.
	* <b>Legal values</b>: <tt>iTransparency</tt> range from 1 to 100.
	*/
	inline void SetTransparency(const unsigned int iTransparency);

	/** Retrieves the transparency.<br>
	*/
	inline unsigned int GetTransparency() const;

	/** Sets the LineWeight.
	* @param iLineWeight
	* The LineWeight index.
	* <b>Legal values</b>: <tt>iLineWeight</tt> range from 1 to 25.
	*/
	inline void SetLineWeight(const unsigned short iLineWeight);

	/** Retrieves the LineWeight.<br>
	*/
	inline unsigned short GetLineWeight() const;

	/** Sets the Frozen.
	* @param iFrozen
	*/
	inline void SetFrozen(const bool iFrozen = true);

	/** Retrieves the Frozen.<br>
	*/
	inline bool IsFrozen() const;

	/** Sets the LineTypeIndex.
	* @param iLineTypeIndex
	* The LineTypeIndex index.
	* <b>Legal values</b>: <tt>iLineTypeIndex</tt>
	*/
	inline void SetLineTypeIndex(const unsigned short iLineTypeIndex);

	/** Retrieves the LineTypeIndex.<br>
	*/
	inline unsigned short GetLineTypeIndex() const;

	/** Sets the LineScale.
	* @param iLineScale
	* The LineScale index.
	* <b>Legal values</b>: <tt>iLineScale</tt>
	*/
	inline void SetLineScale(const float iLineScale);

	/** Retrieves the LineScale.<br>
	*/
	inline float GetLineScale() const;

private:
	unsigned int _red:8;
	unsigned int _green:8;
	unsigned int _blue:8;
	unsigned int _frozen:1;       // bool (true or false)
	unsigned int _transparency:7; // unsigned int (Range 0-100)
	unsigned short _lineWeight:8;   // unsigned short (Range 0-25 indices)
	unsigned short _lineTypeIndex;   
	float _lineScale;  
};

inline void CATAdvancedLayer::SetColorRGB(const unsigned int red, const unsigned int green, const unsigned int blue)
{
	_red = 0;
	if (red   < 256) _red   = red;
	_green = 0;
	if (green < 256) _green = green;
	_blue = 0;
	if (blue  < 256) _blue  = blue;
}

inline void CATAdvancedLayer::GetColorRGB(unsigned int* oRed, unsigned int* oGreen, unsigned int* oBlue) const
{
	if (oRed)
		*oRed   = _red;
	if (oGreen)
		*oGreen = _green;
	if (oBlue)
		*oBlue  = _blue;
}

inline void CATAdvancedLayer::SetTransparency (const unsigned int transparency)
{

 if ( transparency > 100 ) _transparency = 1;
 else _transparency = transparency;
}

inline unsigned int CATAdvancedLayer::GetTransparency() const { return (_transparency); }

inline void CATAdvancedLayer::SetLineWeight (const unsigned short LineWeight)
{

 if ( LineWeight > 25 ) _lineWeight = 1;
 else _lineWeight = LineWeight;
}

inline unsigned short CATAdvancedLayer::GetLineWeight() const { return (_lineWeight); }

inline void CATAdvancedLayer::SetFrozen (const bool Frozen)
{

 if ( Frozen ) _frozen = 1;
 else _frozen = 0;
}

inline bool CATAdvancedLayer::IsFrozen() const { return (_frozen); }

inline void CATAdvancedLayer::SetLineTypeIndex(const unsigned short iLineTypeIndex) {_lineTypeIndex = iLineTypeIndex;}

inline unsigned short CATAdvancedLayer::GetLineTypeIndex() const { return (_lineTypeIndex); }

inline void CATAdvancedLayer::SetLineScale(const float iLineScale) {_lineScale = iLineScale;}

inline float CATAdvancedLayer::GetLineScale() const { return (_lineScale); }

#endif

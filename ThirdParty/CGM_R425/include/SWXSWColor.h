#ifndef SWXSWColor_H
#define SWXSWColor_H

#include "SWXUtGeneral.h"
#include "CATDataType.h"

class ExportedBySWXUtGeneral SWXSWColor
{
public:
	SWXSWColor();
	SWXSWColor(double iRGB[3], CATLONG32 iID);
	~SWXSWColor();

	void SetColor( double iColor[3] );
	void SetColor( int iWholeValue );
	void GetColor( double oColor[3] );
	// Get RGB values in integer 0-255
	void GetColor( int oColor[3] );
	CATLONG32 GetInputID() const;
	void SetInputID( CATLONG32 iID );

	bool IsAnyColorSet();
	bool operator <  (const SWXSWColor& iThat) const;
	bool operator == (const SWXSWColor& iThat) const;
	bool operator != (const SWXSWColor& iThat) const;

private:
	double mColor[3];
	CATLONG32 mInputID;
};

#endif

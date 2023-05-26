//----------------------------------------------------------------------------
//	CATStatCleaner.h
//----------------------------------------------------------------------------
//	Creation by NMU
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 1997
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
//----------------------------------------------------------------------------
#ifndef CATStatCleaner_H
#define CATStatCleaner_H

//#include "CATViz.h"
#include "CATMMediaPixelImage.h"
#include <atomic>
class CATPixelFormat;
class CATUnicodeString;

//class ExportedByCATViz CATStatCleaner
class ExportedByCATMMediaPixelImage CATStatCleaner
{
public:
	~CATStatCleaner();
	void SetError(const char * iprError);
	const CATUnicodeString * GetLastError();
	int GetFormatCount();

private:
	CATStatCleaner();
	void InitStatClean(const char * iprDirectory);

	friend class CATPixelImage;
	static std::atomic<CATPixelFormat*> _paStatPixelFormat;
	
private:
	// useless default methods intentionally not accessible (and not generated)
	CATStatCleaner(const CATStatCleaner&);
	CATStatCleaner& operator=(const CATStatCleaner&);
	CATStatCleaner * operator&();
	const CATStatCleaner * operator&() const;
};

#endif // CATStatCleaner_H

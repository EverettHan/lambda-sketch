#ifndef SWXUtDirectoryFileProvider_H
#define SWXUtDirectoryFileProvider_H

#include "SWXUtGeneral.h"
#include "SWXUtFileProvider.h"

#include "CATUnicodeString.h"
#include "SWXUtMacForOverride.h" //for GCC4.4.7 to be removed on GCC4.9.2#include "SWXUtMacForOverride.h" //for GCC4.4.7 to be removed on GCC4.9.2

class ExportedBySWXUtGeneral SWXUtDirectoryFileProvider : public SWXUtFileProvider
{
	CATDeclareClass;
	typedef SWXUtFileProvider base_class;
public:
	SWXUtDirectoryFileProvider();
	virtual ~SWXUtDirectoryFileProvider();

	virtual HRESULT SetDirectoryPath(const CATUnicodeString & iDirectoryPath) override;
	virtual HRESULT ResolvePath(const CATUnicodeString & iName, CATUnicodeString & oPath) const override;
protected:
	CATUnicodeString mDirectoryPath;
};

#endif

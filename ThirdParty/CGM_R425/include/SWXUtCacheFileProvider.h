#ifndef SWXUtCacheFileProvider_H
#define SWXUtCacheFileProvider_H

#include "SWXUtGeneral.h"
#include "SWXUtDirectoryFileProvider.h"

class ExportedBySWXUtGeneral SWXUtCacheFileProvider : public SWXUtDirectoryFileProvider
{
	CATDeclareClass;
	typedef SWXUtDirectoryFileProvider base_class;
public:
	SWXUtCacheFileProvider();
	virtual ~SWXUtCacheFileProvider();
	
	virtual HRESULT SetDirectoryPath(const CATUnicodeString & iDirectoryPath) override;
	virtual HRESULT ResolvePath(const CATUnicodeString & iName, CATUnicodeString & oPath) const override;
	virtual HRESULT GetFile(const CATUnicodeString & iName, const CATUnicodeString & iPath) const = 0;
};

#endif

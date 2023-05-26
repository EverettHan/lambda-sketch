#ifndef SWXUtServerFileProvider_H
#define SWXUtServerFileProvider_H

#include "SWXUtGeneral.h"
#include "SWXUtCacheFileProvider.h"

class CATUnicodeString;

class ExportedBySWXUtGeneral SWXUtServerFileProvider : public SWXUtCacheFileProvider
{
	CATDeclareClass;
	typedef SWXUtCacheFileProvider base_class;
public:
	SWXUtServerFileProvider();
	virtual ~SWXUtServerFileProvider();
	
	virtual HRESULT SetDirectoryPath(const CATUnicodeString & iCacheDirectoryName) override;
};

#endif

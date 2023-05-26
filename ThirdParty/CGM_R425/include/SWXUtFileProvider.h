
#ifndef SWXUtFileProvider_H
#define SWXUtFileProvider_H

#include "SWXUtGeneral.h"
#include "SWXIUtFileProvider.h"

class SWXIUtFileProvider;

// Abstract class of a file provider.
class ExportedBySWXUtGeneral SWXUtFileProvider : public SWXIUtFileProvider
{
	typedef SWXIUtFileProvider base_class;
public:
	virtual ~SWXUtFileProvider() {}
protected:
	SWXUtFileProvider() {}
private:
	void operator =(const SWXUtFileProvider &);
	SWXUtFileProvider(const SWXUtFileProvider &);
};

#endif

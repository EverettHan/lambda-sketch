#ifndef SWXUtTextFile_H
#define SWXUtTextFile_H

#include "SWXUtGeneral.h"
#include "CATUnicodeString.h"

class ExportedBySWXUtGeneral SWXUtTextFile
{
public:
	SWXUtTextFile();
	~SWXUtTextFile();
	bool Open(CATUnicodeString &iFilename, const char *iFileOpenMode = "r");
	void Close();
	bool ReadLine(CATUnicodeString &oLineText);
	bool WriteLine(const CATUnicodeString &iLineText);
protected:
	unsigned int mFileHandle;
};

#endif

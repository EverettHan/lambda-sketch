#ifndef _FileReader_H
#define _FileReader_H


#include "CATUnicodeString.h"
#include <stdio.h>

class FileReader
{
	private:
	FileReader();
	
	FILE * _fileToParse;
	
	public:
	
	~FileReader();
	
	static void CreateFileReader(FileReader * & opFileReader);
	
	HRESULT Open(CATUnicodeString & iPath,const char * iMode);
	
	HRESULT Close();
	
	int  ReadLine(CATUnicodeString & oLine);
		
	HRESULT  WriteLine(CATUnicodeString & iLine);
	
};


#endif

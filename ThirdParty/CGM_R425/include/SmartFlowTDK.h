//TDK Library Version - Windows: 2.5.1.1
//TDK Library Version - Linux: 2.5.1.1
#pragma once

#ifdef _WIN32
#include <wchar.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct _TDKResult
	{
		char *fullPath;
		char *actualChecksum;
		char *expectedChecksum;
		int resultType;
	} TDKResult;

#ifdef _WIN32
	typedef struct _TDKResultW
	{
		wchar_t *fullPath;
		char *actualChecksum;
		char *expectedChecksum;
		int resultType;
	} TDKResultW;
#endif

	//ValidateFile
	int Tdk_VF(const char *fileDirectory, const char *fileName, TDKResult *result, const char *salt);
#ifdef _WIN32
	int Tdk_VFW(const wchar_t *fileDirectory, const wchar_t *fileName, TDKResultW *result, const char *salt);
#endif
	/* ValidateFile return codes:
	0 - The operation completed successfully and the file was not tampered.
	1 - The operation completed successfully and the file was tampered.
	2 - fileDirectory or fileName argument is NULL
	3 - result argument is NULL
	4 - File could not be opened or does not exist
	5 - File is not signed / signature not found
	6 - .text segment not found - Windows specific
	7 - Heap error
	8 - Could not read the hash value from file
	9 - Could not compute hash value
	10 - Not a valid executable file type (Windows only)
	11 - Invalid format of executable file detected (Windows only)
	12 - Unknown file architecture (Windows only)
	13 - I/O error
	14 - Processing initialization failure
	15 - Processing internal error
	16 - Processing access error 
	17 - fileDirectory or fileName argument is empty string
	*/
	
	//ValidateFileAsync
	int Tdk_VFA(const char *fileDirectory, const char *fileName, void(*callback)(void *, TDKResult *), void *callbackParam, size_t sizeofCallbackParam, const char *salt);
#ifdef _WIN32
	int Tdk_VFAW(const wchar_t *fileDirectory, const wchar_t *fileName, void(*callback)(void *, TDKResultW *), void *callbackParam, size_t sizeofCallbackParam, const char *salt);
#endif
	/* ValidateFileAsync return codes:
	0 - Thread was created successfully
	1 - Thread creation failed
	2 - fileDirectory or fileName argument is NULL
	3 - callback argument is NULL
	7 - Heap error
	17 - fileDirectory or fileName argument is empty string
	*/

	//ValidateSelf - this function calls the VF function on the current executable
	int Tdk_VS(TDKResult *result, const char *salt);
#ifdef _WIN32
	int Tdk_VSW(TDKResultW *result, const char *salt);
#endif
	// ValidateSelf return codes are the same as the VF ones, with the mention that the return code 2 could also mean that memory allocation failed

	//ValidateFilesInFolder
	int Tdk_VFF(const char *rootFilePath, int isRecursive, TDKResult **results, unsigned int *resultCount, const char *salt);
#ifdef _WIN32
	int Tdk_VFFW(const wchar_t *rootFilePath, int isRecursive, TDKResultW **results, unsigned int *resultCount, const char *salt);
#endif

	//ValidateFilesInFolder
	int Tdk_VFFA(const char *rootFilePath, int isRecursive, void(*callback)(void *, TDKResult *, unsigned int), void *callbackParam, size_t sizeofCallbackParam, const char *salt);
#ifdef _WIN32
	int Tdk_VFFAW(const wchar_t *rootFilePath, int isRecursive, void(*callback)(void *, TDKResultW *, unsigned int), void *callbackParam, size_t sizeofCallbackParam, const char *salt);
#endif

	//CheckComputerDateTime
#ifdef _WIN32
	int Tdk_CCDT();
#else
	int Tdk_CCDT(char const *storagePath);
#endif

	//FreeTDKResult
	void Tdk_FreeTDKResult(TDKResult *result);
	void Tdk_FreeTDKResultArray(TDKResult *results, unsigned int resultCount);
#ifdef _WIN32
	void Tdk_FreeTDKResultW(TDKResultW *result);
	void Tdk_FreeTDKResultArrayW(TDKResultW *results, unsigned int resultCount);
#endif

#ifdef __cplusplus
};
#endif

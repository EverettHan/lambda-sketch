#ifndef JS0MKKdyn_h
#define JS0MKKdyn_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define STRINGIFY(s) TO_STR(s)
#define TO_STR(s) #s

#include "JS0MKK.h"
#include "CATGetEntryPoint.h"

typedef int(*farEncodeLibrary)(const char* library, const char* release, int debug);
static int dynEncodeLibrary(const char* library, const char* release, int debug) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(EncodeLibrary));
	if (handler.EntryPoint) {
		farEncodeLibrary fct = (farEncodeLibrary)handler.EntryPoint;
		return fct(library, release, debug);
	}
	return -1;
}

typedef int(*farICSign)(const char* inputIC, const char* outputIC, const char* release, int debug);
static int dynICSign(const char* inputIC, const char* outputIC, const char* release, int debug) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(ICSign));
	if (handler.EntryPoint) {
		farICSign fct = (farICSign)handler.EntryPoint;
		return fct(inputIC, outputIC, release, debug);
	}
	return -1;
}

typedef int(*farCheckExtendedAuthorization)(const char* encodingKey, const char* release, int debug);
static int dynCheckExtendedAuthorization(const char* encodingKey, const char* release, int debug) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(CheckExtendedAuthorization));
	if (handler.EntryPoint) {
		farCheckExtendedAuthorization fct = (farCheckExtendedAuthorization)handler.EntryPoint;
		return fct(encodingKey, release,debug);
	}
	return -1;
}

typedef int(*farDecodeCryptedObject)(const char* encodingKey, const char* release, const unsigned char* inBuffer, size_t inLength, unsigned char*& outBuffer, size_t& outLength, int debug);
static int dynDecodeCryptedObject(const char* encodingKey, const char* release, const unsigned char* inBuffer, size_t inLength, unsigned char*& outBuffer, size_t& outLength, int debug) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(DecodeCryptedObject));
	if (handler.EntryPoint) {
		farDecodeCryptedObject fct = (farDecodeCryptedObject)handler.EntryPoint;
		return fct(encodingKey, release, inBuffer, inLength, outBuffer, outLength, debug);
	}
	return -1;
}

typedef int(*farCheckEnv)(const char* component, const char* release, int debug);
static int dynCheckEnv(const char* component, const char* release, int debug) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(CheckEnv));
	if (handler.EntryPoint) {
		farCheckEnv fct = (farCheckEnv)handler.EntryPoint;
		return fct(component, release, debug);
	}
	return -1;
}
#ifdef _ExtraEntriesForODT
typedef int(*farEncodeAlphabet)(const char* alphabet, const unsigned char* input, size_t inputLength, char* output, size_t outputLength);
static int dynEncodeAlphabet(const char* alphabet, const unsigned char* input, size_t inputLength, char* output, size_t outputLength) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(EncodeAlphabet));
	if (handler.EntryPoint) {
		farEncodeAlphabet fct = (farEncodeAlphabet)handler.EntryPoint;
		return fct(alphabet, input, inputLength, output, outputLength);
	}
	return -1;
}

typedef int(*farDecodeAlphabet)(const char* alphabet, const char* input, size_t inputLength, unsigned char* output, size_t outputLength, size_t& decodedLength);
static int dynDecodeAlphabet(const char* alphabet, const char* input, size_t inputLength, unsigned char* output, size_t outputLength, size_t& decodedLength) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(DecodeAlphabet));
	if (handler.EntryPoint) {
		farDecodeAlphabet fct = (farDecodeAlphabet)handler.EntryPoint;
		return fct(alphabet, input, inputLength, output, outputLength, decodedLength);
	}
	return -1;
}

typedef int(*farEncodeCPK)(const char* encodingKey, const char* release, const unsigned char* inBuffer, size_t inLength, unsigned char*& outBuffer, size_t& outLength, int debug);
static int dynEncodeCPK(const char* encodingKey, const char* release, const unsigned char* inBuffer, size_t inLength, unsigned char*& outBuffer, size_t& outLength, int debug) {
	LibraryHandler handler = CATGetFunctionAddress("JS0MKK", STRINGIFY(EncodeCPK));
	if (handler.EntryPoint) {
		farEncodeCPK fct = (farEncodeCPK)handler.EntryPoint;
		return fct(encodingKey, release, inBuffer, inLength, outBuffer, outLength, debug);
	}
	return -1;
}
#endif
#endif

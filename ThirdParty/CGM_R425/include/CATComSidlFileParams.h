#ifndef CATComSidlFileParams_h
#define CATComSidlFileParams_h

#include "CATComSidlFile.h"
#include "CATUnicodeString.h"

/**
 * Use this instead of raw const char * to avoid string duplication
 * This is "SidlProcessorClass"
 * */
const CATUnicodeString ExportedByCATComSidlFile GetProcessorNameParam();

/**
 * Use this instead of raw const char * to avoid string duplication
 * This is "FileName"
 * */
const CATUnicodeString ExportedByCATComSidlFile  GetFileNameParam();

/**
 * Use this instead of raw const char * to avoid string duplication
 * This is "InputPacketSize"
 * */
const CATUnicodeString ExportedByCATComSidlFile GetInputPacketSizeParam();

/**
 * Use this instead of raw const char * to avoid string duplication
 * This is "OutputPacketSize"
 * */
const CATUnicodeString ExportedByCATComSidlFile GetOutputPacketSizeParam();

#endif

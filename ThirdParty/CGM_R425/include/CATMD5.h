/* -*-c++-*- */
/**
 * @Level Protected
 * @Usage U2
 **/
//=================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017
//=================================================================================

#ifndef CATMD5_H
#define CATMD5_H

#include "VVSStreamConsumer.h"
#include "CATSysErrorDef.h"
#include "CATOmxCollecManager.h"
#include "CATAssert.h"

/*
 * Class that represents a MD5 result
 */

#define MD5_SIZE        16
#define MD5_STRING_SIZE 33

struct ExportedByVVSStreamConsumer CATMD5
{  

public:   

  // A static CATMD5 to compare with in order to know if a CATMD5 has not been initialized
  // if (MyCATMD5.IsEqual(CATMD5::DEFAULT_CATMD5)==TRUE) then not initialized
  static CATMD5 DEFAULT_CATMD5;
  
  // CTORs & DTOR
  CATMD5()                                           {memset(Md5Value,'F',MD5_SIZE);}
  CATMD5(const unsigned char iMd5[], int iDataSize)  {CATAssert(MD5_SIZE==iDataSize); memcpy(Md5Value,iMd5,MD5_SIZE);}
  virtual ~CATMD5()                                  {}
  CATMD5 (const CATMD5& iMd5)                        {memcpy(Md5Value,iMd5.Md5Value,MD5_SIZE);}
  CATMD5& operator=(const CATMD5&);
  
  // Comparison of two CATMD5s
  CATBoolean IsEqual(const CATMD5& iOther) const {return (strncmp((const char*)Md5Value,(const char*)iOther.Md5Value,MD5_SIZE)==0)?TRUE:FALSE;}
  
  // Convert into a printable string. The end of string (i.e. the value '\0') is added at the end of the string
  // oMd5AsString must be an array of size MD5_STRING_SIZE
  // iTabSize must be valuated to MD5_STRING_SIZE
  HRESULT ConvertToHexaString(char oMd5AsString[], int iTabSize) const; 

  // Build the CATMD5 value from a printable string.
  // iMd5AsString must be an array of size MD5_STRING_SIZE
  // iTabSize must be valuated to MD5_STRING_SIZE
  HRESULT BuildFromHexaString(char iMd5AsString[], int iTabSize);  
  
  // The data 
  unsigned char Md5Value[MD5_SIZE];   
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATMD5>::manager();

#endif

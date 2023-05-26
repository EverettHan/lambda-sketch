#ifndef CATBBDataMessage_H
#define CATBBDataMessage_H
// COPYRIGHT DASSAULT SYSTEMES 2000
#include "CATBaseUnknown.h"
#include "CATBBMessage.h"
#include "CATSysCommunication.h"

class ExportedByCATSysCommunication  CATBBDataMessage : public CATBBMessage
{
  CATDeclareClass;
  CATBBDataMessage();
  /**
   * mandatory call at the beginning of a stream operation
   * reset the streamed data
   */
  HRESULT BeginStream();
  /**
   * streams a char
   */
  HRESULT StreamByte(char  iVal);
  /**
   * streams a short
   */
  HRESULT StreamShort(short iVal);
  /**
   * streams an unsigned short
   */
  HRESULT StreamUnsignedShort( unsigned short iVal);
  /**
   * streams an  int
   */
  HRESULT StreamInt(int iVal);
  /**
   * streams an unsigned int
   */
  HRESULT StreamUnsigned(unsigned int iVal);
  /**
   * streams a float
   */
  HRESULT StreamFloat(float iVal);
  /**
   * streams a double
   */
  HRESULT StreamDouble(double iVal);
  /**
   * streams a string
   */
  HRESULT StreamString(const char *iString);
  /**
   * streams  tables
   */
  HRESULT StreamFixedByteArray(const void *iTab, int iLen);
  HRESULT StreamVariableByteArray(const void *iTab, int iLen);

  HRESULT StreamFixedIntArray(const int iTab[], int iLen);
  HRESULT StreamVariableIntArray(const int iTab[], int iLen);

  HRESULT StreamFixedUnsignedArray(const unsigned int iTab[], int iLen);
  HRESULT StreamVariableUnsignedArray(const  unsigned int iTab[], int iLen);

  HRESULT StreamFixedShortArray(const short iTab[], int iLen);
  HRESULT StreamVariableShortArray(const short iTab[], int iLen);

  HRESULT StreamFixedUnsignedShortArray(const unsigned short iTab[], int iLen);
  HRESULT StreamVariableUnsignedShortArray(const unsigned short iTab[], int iLen);

  HRESULT StreamFixedFloatArray(const float iTab[], int iLen);
  HRESULT StreamVariableFloatArray(const float iTab[], int iLen);

  HRESULT StreamFixedDoubleArray(const double iTab[], int iLen);
  HRESULT StreamVariableDoubleArray(const double iTab[], int iLen);

  /**
   * streams an UUID 
   */
  //HRESULT StreamUUID();

  /**
   * mandatory call at the end of a stream operation
   */
   void * EndStream(int *oLen);
  /**
   * reset a streaming operation 
   * frees the allocated memory 
   */
   HRESULT ResetStreamData();

  /**
   * Mandatory at the beginning operation
   */
  HRESULT BeginUnstream(void *iData, int Len);
  /**
   * Unstream a char
   */
  HRESULT UnstreamByte(char  *oChar );
  /**
   * Unstream a short
   */
  HRESULT UnstreamShort(short *oShort);
  /**
   * Unstream an unsigned short
   */
  HRESULT UnstreamUnsignedShort( unsigned short *oUnsignedS);
  /**
   * Unstream an int
   */
  HRESULT UnstreamInt(int *oInt);
  /**
   * Unstream an unsigned int 
   */
  HRESULT UnstreamUnsigned(unsigned int *oUnsigned);
  /**
   * Unstream a float
   */
  HRESULT UnstreamFloat(float *oFloat);
  /**
   * Unstream a double
   */
  HRESULT UnstreamDouble(double *oDouble);
  /**
   * Unstream a string
   */
  HRESULT UnstreamNeededStringLength(int *oLen);
  HRESULT UnstreamString(char *oString);


  /**
   * Unstream a fixed size byte array
   */
  HRESULT UnstreamFixedByteArray(void *oByteArray, int iLen);
  HRESULT UnstreamFixedFloatArray(float*, int);
  HRESULT UnstreamFixedDoubleArray(double*, int);
  HRESULT UnstreamFixedShortArray(short*, int);
  HRESULT UnstreamFixedUnsignedShortArray(unsigned short*, int);
  HRESULT UnstreamFixedIntArray(int*, int) ;
  HRESULT UnstreamFixedUnsignedArray(unsigned*, int);

  /**
   * Unstream the size of a variable  byte array
   */
  HRESULT UnstreamVariableArrayLength(int *oLen);

  HRESULT EndUnstream();
  private :
  int  _Status;
  char *_Data;
  unsigned int _DataLen;
  unsigned int _RealLen;
};
#endif

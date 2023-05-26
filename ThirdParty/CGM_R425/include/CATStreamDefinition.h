/**
* @level Private
* @usage U1
*/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
//
// CATStreamDefinition 
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
// Jan. 99
//=============================================================================

#ifndef CATStreamDefinition_h
#define CATStreamDefinition_h

#include "AC0XXLNK.h"
#include "CATWOmxBinaryStream.h"
#include "CORBAAnyDef.h"


class ExportedByAC0XXLNK CATStreamDefinition: public CATWOmxBinaryStream
{
public:
  CATStreamDefinition(CATULONG32  maxlen=50000);
  CATStreamDefinition(void*, CATULONG32 );
  ~CATStreamDefinition();

private:
  CATStreamDefinition( const CATStreamDefinition& );	// not implemented
  CATStreamDefinition& operator=( const CATStreamDefinition& );	// not implemented


public:

  //FIXME, used only once in MlcInfra
  void WriteString(const char*);
  void ReadString(char*&);

  //FIXME, used only once in DNB
  void WriteStream (const CATStreamDefinition&);
  void ReadStream  (CATStreamDefinition&,CATULONG32  length_to_read);

  const void *   GetBuffer() const;
  CATULONG32   GetLength() const;
  void *   GiveBuffer();

  void Reset();
  void Advance( CATULONG32  siz );

  // Used to convert data according to the endian-ness of the machine.
  void WriteHeader (unsigned short iVersion);
  void ReadHeader ();

  inline unsigned short GetStreamVersion() {return _versionStream;}

  void          SetConversion(unsigned char);

private:
  unsigned short _versionStream;
  CATLONG64 _bufferSize;
};

#endif


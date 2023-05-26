/*
 * CATOmyBinaryFileReader.h
 *
 *  Created on: Oct 4, 2013
 *      Author: pjq
 */

#ifndef CATOMYBINARYFILEREADER_H_
#define CATOMYBINARYFILEREADER_H_

#include "CATBinary.h"
#include "CATSysErrorDef.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATOMYBaseSession.h"

/**
 * Reads the content of a file in one chunk and put it in CATBinary buffer.
 */
class ExportedByCATOMYBaseSession CATOmyBinaryFileReader
{
  unsigned int fileDesc;
  CATBoolean opened;
public:
  CATOmyBinaryFileReader(const CATUnicodeString & iFilePath);
  ~CATOmyBinaryFileReader();
  HRESULT ReadFileContent(CATBinary& oContent);
};
#endif /* CATOMYBINARYFILEREADER_H_ */

// COPYRIGHT Dassault Systemes 2000
//
// GDE - 06/2000
//

#ifndef CATFileMapping_H
#define CATFileMapping_H

#include <CATView.h>
#include <CATFilePath.h>

/**
 * Object for direct file read/write (file mapping)
 */
class ExportedByCATView CATFileMapping
{
public:

  /**
   * Create
   * iMode: 0 for read only, 1 for read/write
   * iSize: size, 0 to get current file size
   */
  CATFileMapping(const CATFilePath& iFileName, int iMode, int iSize=0);

  /**
   * Create empty mapping
   */
  CATFileMapping();

  /**
   * Destructor
   */
  ~CATFileMapping();

  /**
   * Open mapping for read
   */
  HRESULT OpenRead(const CATFilePath &iPath);

  /**
   * Open mapping for read write
   */
  HRESULT OpenWrite(const CATFilePath &iPath, int iSize);

  /**
   * Resize (for write mapping only)
   */
  HRESULT Resize(int iNewSize);

  /**
   * Close mapping
   */
  HRESULT Close();

  /**
   * Get buffer
   */
  void *GetBuffer();

  /**
   * Get buffer size
   */
  int   GetSize();

  /**
   * Compress the buffer
   */
  int Compress();

  /**
   * Uncompress the buffer
   */
  int Uncompress();

private:
  HRESULT Open(const CATFilePath& iFileName, int iMode, int iSize);
  CATFilePath _path;
  void* _buffer;
  int   _size;
};

#endif

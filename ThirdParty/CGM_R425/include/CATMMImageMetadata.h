/*
*  CATMMImageMetadata.h
*
*  Created by azx on 21/07/2011.
*  Copyright 2011 Dassault Systemes. All rights reserved.
*
*/

#ifndef CATMMImageMetadata_H
#define CATMMImageMetadata_H

#include "CATMMediaPixelImage.h"
#include "CATMMRasterEngineDef.h"
// System
#include "CATBaseUnknown.h"
#include "CATListPV.h"

#include "CATMMMetadataExif.h"


typedef unsigned short ExifFieldID;
typedef unsigned short ExifFieldType;

/*
* Class to use for image metadata.
*/
class ExportedByCATMMediaPixelImage CATMMImageMetadata : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /**
  * Constructs an instance of metadata class containing empty data.
  */
  CATMMImageMetadata();

  virtual ~CATMMImageMetadata();

  /** @new APIs */
  /**@{*/
  int GetMetadataCount();
    /**
     * Returned metadata has to be released after use.
     * @param opMetadata [out, IUnknown#Release]
     */
  HRESULT GetMetadata(int iIndex, CATMMMetadata* &opMetadata) const;
    /**
     * Returned metadata has to be released after use.
     */
  HRESULT GetMetadata(const char* iMetadataType, CATMMMetadata* &opMetadata) const;
  HRESULT RemoveMetadata(int iIndex);
  HRESULT RemoveMetadata(const char* iMetadataType);
    /**
     * Given metadata will be AddRef.
     */
  HRESULT AddMetadata(CATMMMetadata* ipMetadata);


  /**@}*/


  /** @ @deprecated API, moved to CATMMMetadataExif */
  /**@{*/

  /**
  * Set the desired metadata. There are various functions for each type 
  * of field type. The function which accepts 'float' is used for both 
  * RATIONAL and SRATIONAL types. User is required to adhere strictly 
  * with ID-Type-Count relations. 
  * @param iID
  *   IFD field ID.
  * @param ipData
  *   Pointer to data corresponding to iID.
  * @param iCount
  *   Number of items of data (NOT the number of bytes). Default value is 1.
  * @return
  * <br><b>Legal values</b>
  * <dl>
  *  <dt>MMIE_TYPE_MISMATCH</dt>
  *  <dd>Type provided is not allowed for given ID.</dd>
  *  <dt>MMIE_COUNT_MISMATCH</dt>
  *  <dd>Count provided is not allowed for given ID.</dd>
  *  <dt>E_FAIL</dt>
  *  <dd>Unknown error.</dd>
  *  <dt>S_OK</dt>
  *  <dd>Data is added successfully.</dd>
  * </dl>
  * @see ExifFieldID, ExifFieldType
  */
  HRESULT SetData(const ExifFieldID iID, const char           *ipData,  int iCount=1);  // for ASCII (may contain multiple strings terminated by single NUL character)
  HRESULT SetData(const ExifFieldID iID, const unsigned short *ipData, const int iCount=1);  // for SHORT
  HRESULT SetData(const ExifFieldID iID, const unsigned int   *ipData, const int iCount=1);  // for LONG
  HRESULT SetData(const ExifFieldID iID, const ExifRational   *ipData, const int iCount=1);  // for RATIONAL
  HRESULT SetData(const ExifFieldID iID, const ExifSRational  *ipData, const int iCount=1);  // for SRATIONAL
  HRESULT SetData(const ExifFieldID iID, const void           *ipData, const int iCount=1);  // for UNDEFINED (1 byte data)
  HRESULT SetDataByte(const ExifFieldID iID, const void           *ipData, const int iCount = 1);  // for Byte 

  /**
  * Get data size in bytes for requested tag.
  * @param iID
  *   IFD field ID.
  * @param oByteSz
  *   Size of data in bytes.
  * @return
  * <br><b>Legal values</b>
  * <dl>
  *  <dt>E_INVALIDARG</dt>
  *  <dd>Requested ID is not present.</dd>
  *  <dt>E_FAIL</dt>
  *  <dd>Unknown error.</dd>
  *  <dt>S_OK</dt>
  *  <dd>Success.</dd>
  * </dl>
  * @see ExifFieldID, ExifFieldType
  */
  HRESULT GetDataSizeInBytes(ExifFieldID iID, int &oByteSz) const;

  /**
  * Get data for requested tag.
  * @param iID
  *   IFD field ID.
  * @param oType
  *   IFD field type.
  * @param opData
  *   Pointer to receive data corresponding to iID. User should allocate necessary memory.
  *   Size of required memory can be found using GetDataSizeInBytes.
  * @param iSzDataInBytes
  *   Size of user allocated opData.
  * @return
  * <br><b>Legal values</b>
  * <dl>
  *  <dt>E_INVALIDARG</dt>
  *  <dd>Requested ID is not present.</dd>
  *  <dt>E_OUTOFMEMORY</dt>
  *  <dd>The memory is not sufficient. Please use GetDataSizeInBytes to know size of memory needed.</dd>
  *  <dt>E_FAIL</dt>
  *  <dd>Unknown error.</dd>
  *  <dt>S_OK</dt>
  *  <dd>Success.</dd>
  * </dl>
  * @see ExifFieldID, ExifFieldType
  */
  HRESULT GetData(ExifFieldID iID, ExifFieldType &oType, int &oCount, void *opData, int iSzDataInBytes) const;

  int GetNumberOfEntries() const;

  ExifFieldID GetID(int index) const; // 0 <= index < GetNumberOfEntries()
  /**@}*/

  CATMMImageMetadata& operator=(const CATMMImageMetadata&);

private:
  // useless default methods intentionally not accessible (and not generated)
  CATMMImageMetadata(const CATMMImageMetadata&);

  friend class CATMMRasterEngineSB;
  friend class CATMMRasterEngineOpenAPI;
  friend class CATMMRasterEngineGDIplus;

  // if opIFD is NULL, oSzIFD returns size needed
  HRESULT Generate(unsigned char *&opIFD, int &ioSzIFD, CATBoolean iForTIFF=TRUE) const;
  HRESULT Interpret(const unsigned char *ipIFD, const int iSzIFD, const unsigned char* ipTIFFHeader=NULL);

  HRESULT SetData(const ExifFieldID iID, const ExifFieldType iType, const void *ipData, const int iSzBytes, const int iCount);

  CATMMMetadataExif* GetExif() const;
  CATMMMetadataExif* GetOrCreateExif();

private:
  CATListPV _listMetadata;
};


#endif  // CATMMImageMetadata_H

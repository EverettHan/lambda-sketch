#ifndef CATMMPIBUFFER_H
#define CATMMPIBUFFER_H

#include "CATMMediaPixelImage.h"

#include "CATSysBoolean.h"
#include "CATDataType.h"
#include "CATMMPITypeDesc.h"

//enum CATMMPIValueType          {
//    MMPI_VT_char,
//    MMPI_VT_uchar,
//    MMPI_VT_float,
//    MMPI_VT_double,
//    MMPI_VT_Unknown
//};

enum CATMMPIBufferDeletionMode {
    MMPIB_DelMode_No,         /*!< Nothing to do at destruction. */
    MMPIB_DelMode_Free,       /*!< Free required at destruction. */
    MMPIB_DelMode_DeleteTab,  /*!< Table deletion at destruction. */
    MMPIB_DelMode_Specific,   /*!< A supplied method has to be called at destruction. */
    MMPIB_DelMode_Unknown     /*!< Unknown. */
};

/**
 * @ingroup groupPixelImageData
 * Responsabilities:
 *  o Handle data lifecycle
 *  o Handle read/write access.
 *  o Optimize buffer size facing type CATMMPITypeDesc.
 **/
class ExportedByCATMMediaPixelImage CATMMPIBuffer {
public:
  
  CATMMPIBuffer();
  CATMMPIBuffer(const CATMMPIBuffer& iPIBuffer, bool iMakeACopy);
  CATMMPIBuffer(const CATMMPITypeDesc iTypeDesc,CATUINT32 iNbElem,void* ipBuffer,CATMMPIBufferDeletionMode iDelMode);
  CATMMPIBuffer(size_t iSize, void* ipBuffer,void (*ipDestructor)(void*), CATUINT32 iNbElem=1);
  virtual ~CATMMPIBuffer();

 /** @name static services */
 /**@{*/
  static unsigned int       ProductIntToUInt(const int a, const int b, const int c = 1);
  static unsigned int       ProductUIntToUInt(const unsigned int a, const unsigned int b, const unsigned int c = 1);
  static unsigned int       GetValidSize(const int iWidth, const int iHeight, const int iBytePerPixel);
 /**@}*/

 /** @name Getter */
 /**@{*/
  CATBoolean                IsReadOnly()          const;
  CATMMPITypeDesc           GetTypeDesc()         const;
   /**
   * Returns the number of CATMMPITypeDesc stored in budder.
   */
  CATUINT32                 GetNbElem()           const;
   /**
   * Returns the size of buffer in bytes.
   */
  size_t                    GetBufferSize()       const;
  CATMMPIBufferDeletionMode GetDeletionMode()     const;
  const void*               GetBufferForRead()    const;
  void*                     GetBufferForModify();
 /**@}*/

 /** @name Setter/Modifier */
 /**@{*/
  void                      SetReadOnly()             { _readOnly = 1;      };
  bool                      MakeACopyFrom(const CATMMPIBuffer& iPIBuffer);
  void                      Switch(CATMMPIBuffer& iPIBuffer);
  void                      ChangeBuffer(const CATMMPITypeDesc iTypeDesc, CATUINT32 iNbElem, void* ipBuffer, CATMMPIBufferDeletionMode iDelMode);
  void                      ChangeBuffer(size_t iSize, void* ipBuffer, void(*ipDestructor)(void*), CATUINT32 iNbElem = 1);
  void*                     ExtractBufferAndClear(bool iOnlyNotReadOnly=true);// Only for MMPIB_DelMode_Free and MMPIB_DelMode_DeleteTab.
 /**@}*/

private:
  CATMMPIBuffer(const CATMMPIBuffer&);
  CATMMPIBuffer& operator=(const CATMMPIBuffer&);
  void Clear();
  void Empty();
  static void* CreateTab(const CATMMPITypeDesc iTypeDesc, CATUINT32 iNbElem);

  void*                      _buffer;
  void                     (*_pDestructor)(void*);
  size_t                     _size;
  CATMMPIBufferDeletionMode  _deleteMode;//no,free,delete[],Specific,unknown
  unsigned int               _readOnly;
  CATMMPITypeDesc            _typeDesc;
  CATUINT32                  _nbElem;
};

#endif

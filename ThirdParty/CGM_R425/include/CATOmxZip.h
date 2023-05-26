#ifndef __CATOmxZip_H
#define __CATOmxZip_H

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
#include "CATOmxArray.h"

/**
 * Tranforms in place ioBLOB into a BLOB containing:
 * <iHeader:iHeaderSize bytes><ioBLOB size:4 bytes><CATSysCompress zipped version of ioBLOB>
 * It can only be read by CATOmxUnzipWithHeader.
 */
ExportedByCATOmxKernel void CATOmxZipWithHeader(CATOmxArray<unsigned char>& ioBLOB, const unsigned char* iHeader, size_t iHeaderSize, int iZipLevel = 1);

/**
 * unzipper for CATOmxUnzipWithHeader.
 * @return
 *  STG_E_INVALIDHEADER, ioBLOB does not begin with correct header
 *  Else see CATSysUncompress documentation
 */
ExportedByCATOmxKernel HRESULT CATOmxUnzipWithHeader(CATOmxArray<unsigned char>& ioBLOB, const unsigned char* iHeader, size_t iHeaderSize);

#endif

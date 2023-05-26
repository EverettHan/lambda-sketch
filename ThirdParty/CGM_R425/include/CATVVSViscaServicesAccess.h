#ifndef CATVVSViscaServicesAccess_H
#define CATVVSViscaServicesAccess_H

#include "CATOmxArray.h"
#include "VVSUtils.h"

class CATUnicodeString;
class CATVVSUrl;
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATVVSUrl>::manager();

class ExportedByVVSUtils CATVVSViscaServicesAccess
{
public:
  // new iTransaction for each call. It cannot be the whole download transaction as it might be splitted in several packets
  static HRESULT ParseViscaURLAndCorrelationIdForTicket(const CATUuid& iTransaction, const CATOmxArray<CATVVSUrl>& iUrls, CATUnicodeString &oUrl, CATUnicodeString& oJson);
  static HRESULT ParseTicketAnswer(const CATUuid& iTransaction, const CATUnicodeString& iAnswer, CATOmxArray<CATUnicodeString>& oTickets, CATOmxArray<CATUnicodeString>& oUrls, CATOmxArray<CATVVSUrl>& oMissingFilesWithFallbackNeeded, CATOmxArray<CATVVSUrl>& oMissingFilesWithoutFallbackNeeded);
  // without variable element for a same stream element
  static HRESULT GetViscaCanonicalUrl(const CATUnicodeString& iUrl, CATUnicodeString& oCanonicalUrl);
};


#endif

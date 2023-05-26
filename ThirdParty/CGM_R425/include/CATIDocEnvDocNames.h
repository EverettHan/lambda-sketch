/* -*-c++-*- */
#ifndef CATIDocEnvDocNames_h
#define CATIDocEnvDocNames_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Protected 
 * @usage U3
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATDocDisplayNames.h"

extern ExportedByAD0XXBAS IID IID_CATIDocEnvDocNames;

/**
 * Interface to query document names from an environment.
 */
class ExportedByAD0XXBAS CATIDocEnvDocNames: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
   * Retrieves one or many display names of one or many documents.<br>
   * Sample: retrieve the display name and the display short name from one CATIDocId<pre>
   *    CATDocDisplayNames DocNames(MyDocId);
   *    CATListPtrCATDocDisplayNames ListOfDocNames;
   *    ListOfDocNames.Append(&DocNames);
   *    HRESULT hr = DocEnvDocNames.GetDocDisplayNames(ListOfDocNames, CATDocDisplayNames::QueryDocName | CATDocDisplayNames::QueryDocShortName);
   *    if (SUCCEEDED(hr))
   *       < DocNames.GetDocName() and DocNames.GetDocShortName() are set ></pre>
   * Sample: retrieve the display short name from many CATIDocId<pre>
   *    CATListPtrCATDocDisplayNames ListOfDocNames;
   *    for (Cnt1 = 1; Cnt1 <= NbDocId; Cnt1++)
   *       ListOfDocNames.Append(new CATDocDisplayNames(*ListOfDocId[Cnt1]));
   *    HRESULT hr = DocEnvDocNames.GetDocDisplayNames(ListOfDocNames, CATDocDisplayNames::QueryShortDocName);
   *    if (SUCCEEDED(hr))
   *       < DocNames.GetDocName() and DocNames.GetDocShortName() are set >
   *    CATLISTP_APPLY_DELETE(ListOfDocNames);</pre>
   * @param ioListOfDocDisplayNames
   *   The object which identifies the document in this environment.
   * @param iQueriedNames
   *   The queried names (bit mask). See @href CATDocDisplayNames#QueryDocName , etc. Use the operator <tt>OR |</tt>.
   */
  virtual HRESULT GetDocDisplayNames(CATListPtrCATDocDisplayNames &ioListOfDocDisplayNames, unsigned int iQueriedNames) = 0;
};

#endif

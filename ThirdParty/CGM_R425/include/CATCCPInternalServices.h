// COPYRIGHT DASSAULT SYSTEMES 2015

#ifndef _CATCCPInternalServices_H_
#define _CATCCPInternalServices_H_

/**
 * @level Protected 
 * @usage U1
 */

// SpecialAPI
#include "CATSysBoolean.h"
// ObjectModelerCollection
#include "CATOmxIter.h"
// ObjectModelerBase
#include "CP0CLIP.h"

class CATDocument;
class CATFormat;

// Nouveaux services pour gerer correctement le SourceDocument qui correspond au document clipboard (ccp_dummy*)
// CATOmbSetSourceDocument doit etre utilisee que par ImplementationCCP_SPEC::NewTempoSpecContainer lors de la creation du document
ExportedByCP0CLIP
void CATOmbSetSourceDocument( CATDocument & iClipExtDoc, CATDocument & iDoc );
// CATOmbRemoveSourceDocument doit etre utilisee que par CATDocument::remove lors de la destruction du document
// CATOmbRemoveSourceDocument doit etre utilisee que par CATSpecClipExt::_OnClipboardFlushCB lors de la destruction du document
CATBoolean CATOmbRemoveSourceDocument( CATDocument & iClipExtDoc );
ExportedByCP0CLIP
CATBoolean CATOmbIsSourceDocument( const CATDocument & iDoc );
ExportedByCP0CLIP
CATDocument* CATOmbGetSourceDocument( CATDocument & iClipExtDoc );
ExportedByCP0CLIP
CATDocument * CATOmbGetClipboard( const CATFormat & iFormat );
ExportedByCP0CLIP
CATOmxIter<CATDocument> CATOmbGetAllClipboards();

//  ne pas utiliser Usage interne
void AddNumCopyFormats(); 
void CopyNumCopyFormats(); 

#endif


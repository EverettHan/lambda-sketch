/* -*-c++-*- */

#ifndef CATOmyEditorMarshallingServices_h
#define CATOmyEditorMarshallingServices_h

#include "CATOMYBaseSession.h"
#include "CATOmyEditor.h"

/**
 * @level Private
 * @usage U1
 */

/**
 * Service class exposed for the Session management
 */
class CATOmyEditorRegistry;
class CATUnicodeString;
class CATOmyLocalSaveImage;
class CATOmySessionImageDescriptor;

class ExportedByCATOMYBaseSession CATOmyEditorMarshallingServices
{
public:
  /** 
  * Streams registered editors into a file in LocalSave context. InfraEditors are also streamed.
  * @return
  *   <code>S_OK</code> if everything ran ok, <code>E_FAIL</code> otherwise.
  */
  static HRESULT StreamAllEditors();

  /** 
  * Unstreams registered editors from a file in LocalSave context. InfraEditors are not unstreamed.
  * @return
  *   <code>S_OK</code> if everything ran ok, <code>E_FAIL</code> otherwise.
  */
  static HRESULT UnstreamEditors();

  /**
  * Returns the count of editors to be opened (NOT accouting the infra editors)
  * @return
  *   <code>S_OK</code> if everything ran ok, <code>E_FAIL</code> otherwise.
  * @param [out] oNumberOfEditors Count of editors
  * @param [in] ipTransaction The transaction where to find the editors, optional. To be specified if image not activated yet.
  *
  */
  static HRESULT GetNumberOfEditors(CATLONG32 &oNumberOfEditors, CATOmySessionImageDescriptor* ipTransaction = 0);
  
  /** 
  * Unstreams registered infra editors from a file in LocalSave context. Normal editors are not unstreamed.
  * @return
  *   <code>S_OK</code> if everything ran ok, <code>E_FAIL</code> otherwise.
  */
  static HRESULT UnstreamInfraEditors();
  
private:
  static HRESULT StreamEditorRegistry   (CATOmyEditorRegistry * iRegistry, const CATUnicodeString & iFilePath);
  static HRESULT UnstreamEditorRegistry (const CATUnicodeString & iFilePath, CATOmyEditorRegistry * ioRegistry);
  static CATOmyLocalSaveImage * GetPrivateSID();
};

#endif

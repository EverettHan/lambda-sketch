#ifndef __CATIOmbPlug_H
#define __CATIOmbPlug_H

/**
 * @level Protected 
 * @usage U1
 */

/*******************************************
 * THIS CODE MUST BE THE SAME IN V5 AND V6 *
 *     PLEASE REPORT MODIFICATIONS         *
 *******************************************/


#include "AC0XXLNK.h"
#include "CATObject.h"
class CATDocument;
class CATIOmbPlug_var;
template<class T> class CATOmxIter;

extern ExportedByAC0XXLNK IID IID_CATIOmbPlug;

/**
 * Base class for CATIAPlug allowing interactions between Omb and Omc worlds.
 */
class ExportedByAC0XXLNK CATIOmbPlug: public CATObject
{
  CATDeclareInterface;
public:
  /**
   * tricky, due to CATObject inheritance.
   */
  CATIOmbPlug(const char* iType,const char* iSuperType);

  /**
   * Retrieves document of container.
   * DO NOT USE.
   */
  virtual CATDocument* GetDocument() const = 0;

  /**
   * Assigns document of container.
   * DO NOT USE.
   */
  virtual HRESULT SetDocument(CATDocument* iDocument) = 0;

  /**
   * Get parent container.
   * DO NOT USE.
   */
  virtual CATIOmbPlug_var GetParentContainer() = 0;


  enum LoadState 
  {
    NotLoaded,
    Loaded,
    Loading,
    LoadFailed
  };
  /**
   * Get load state.
   * DO NOT USE.
   */
  virtual LoadState GetLoadState() const = 0;


  /**
   * List sub containers.
   * DO NOT USE.
   */
  virtual CATOmxIter<CATIOmbPlug> GetSubContainers() const = 0;

  /**
   * DO NOT USE.
   */
  virtual CATBoolean IsUnderRemove() const = 0;

  /*
  Inform the plug that Stream of CATDocument will start soon. ExecuteBeforeSave cannot be used as it require that applicative container/doc implements interface to work
  */
  virtual HRESULT OnDocumentStreamStart() = 0;

  /* 
  Indicate to the plug that the stream of CATDocument has ended and inform if an error occurred to launch a session rollback if so.
  This method's aim is only to get global errors of document stream.
  */
  virtual HRESULT OnDocumentStreamEnd(CATBoolean iErrorOccurred) = 0;
};
//------------------------------------------------------------------

CATDeclareHandler(CATIOmbPlug,CATBaseUnknown);

#endif


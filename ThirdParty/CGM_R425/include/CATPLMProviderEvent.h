/**
* @level Private
* @usage U1
*/


#ifndef __CATPLMProviderEvent_h__
#define __CATPLMProviderEvent_h__

#include "CATPLMServicesItf.h"

#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"

#include "CATPLMRepositoryName.h"


/**
* Classe representing a command executed by the provider.
*/
class ExportedByCATPLMServicesItf CATPLMProviderEvent: public CATBaseUnknown
{
public:
  /**
   * Construct an event raised by the provider.
   */
  CATPLMProviderEvent(CATPLMRepositoryName& iRepositoryName, CATUnicodeString& iInstanceId, CATUnicodeString& iPvCommand, unsigned int iElapsedTime);
  CATPLMProviderEvent (CATPLMProviderEvent &);
  CATPLMProviderEvent& operator=(CATPLMProviderEvent&);
  virtual ~CATPLMProviderEvent();
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();


  /** 
  * Returns the name of the command launched by the provider.
  */
  CATUnicodeString& GetProviderCommand();

  /** 
  * Gets the information about the provider which has raised this event..
  * @param oRepository [out]
  *   The repository name of the provider
  * @param oInstanceId [out]
  *   The instanceid of the provider.
  *
  */
  void GetProviderInfos(CATPLMRepositoryName& oRepository, CATUnicodeString& oInstanceId) const;

  /** 
  * Returns the time spent during this event.
  * @return
  *   the tim in ms
  */
  unsigned int GetElapsedTime() const;

  /** 
  * Return the time when this event was created.
  * @return
  *   The time is formated as HH:MM:SS:ms
  */
  const CATUnicodeString& GetCreationTime() const;

  /** 
  * Sets the status of this event.
  */
  void SetEventStatus(HRESULT iHr);

  /** 
  * Returns the status of this event.
  */
  HRESULT GetEventStatus();

private:
  /** Command lanched by the provider */
  CATUnicodeString _PvCommand;

  /** RepositoryName of the provider. */
  CATPLMRepositoryName _Repository;
  /** Instance Id of the Provider.*/
  CATUnicodeString _InstanceId;
  
  /** Time used by provider to execute its command (in ms) */
  unsigned int _ElapsedTime;  
  /** Creation time of this object: (ie HH:MM:SS:ms) */
  CATUnicodeString _CreationTime;
  /** Internal status of the event. */
  HRESULT _HR;
};
#endif //__CATPLMProviderEvent_h__

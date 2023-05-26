#ifndef CATIBBHTTP_H
#define CATIBBHTTP_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBaseUnknown.h"
#include <IUnknown.h>
#include "CATSysCommunication.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATSysCommunication IID IID_CATIBBHTTP;
#else
extern "C" const IID IID_CATIBBHTTP;
#endif
class CATIBBHTTP_var;

/**
 * Interface to access the backbone HTTP services.
 * <b>Role</b>: This interface provides methods to handle backbone HTTP messages.
 * It is implemented by the @href CATBBMessage component.
 * Since your message component derives from this component, it inherits
 * the implementation of CATIBBHTTP, and you don't need to implement it.
 */
class ExportedByCATSysCommunication CATIBBHTTP : public IUnknown

{
  CATDeclareInterface;
  public:


  /** 
   * Set DestinatorURL                                               
   * This method permits to specify the destinator URL
   */
  virtual HRESULT SetDestinatorURL(const char *iHost, const char* iResource, int iPort)=0;

  virtual HRESULT GetDestinatorURL(char ** oHost, char ** oResource, int* oPort)=0;

  virtual HRESULT GetDestinatorURLString(char ** oURL, int* oSize)=0;

    /** 
   * Set MultipleDestinatorURL                                               
   * This method permits to specify the destinator URL
   * behaviour determines what is to be done with the URLs
   * 0 means that the message will be broadcasted to all the URLs
   * 1 means that the message will be sent to the first available URL in the list.
   */
  virtual HRESULT SetMultipleDestinatorURL(char *iURLs[], int behaviour)=0;

     /** 
   * SetFilter                                               
   * This method permits to specify the destinator bus
   */
  virtual HRESULT SetFilter(const char *iFilter)=0;

  /** 
   * GetFilter                                               
   * This method permits to get the destinator user
   */
  virtual HRESULT  GetFilter(char **oFilter)=0;







};

/**
 * Declaration of the handler class  for CATIBBHTTP : CATIBBHTTP_var
 */
CATDeclareHandler( CATIBBHTTP, CATBaseUnknown );

#endif

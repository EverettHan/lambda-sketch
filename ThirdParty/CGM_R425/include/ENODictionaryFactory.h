//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/01/04
//===================================================================
// ENODictionaryFactory.cpp
// Header definition of class ENODictionaryFactory
//===================================================================
//
//===================================================================
//  2011/01/04 Creation: Code generated by the 3DS wizard
//===================================================================
/**
 * @level Private
 * @usage U3
 */

#ifndef ENODictionaryFactory_H
#define ENODictionaryFactory_H

#include "VPMIDicInterfaces.h"
#include "CATBaseUnknown.h"

class VPMIDicMgr_var;
class VPMIDicGet;
class VPMIDicStream;

class ExportedByVPMIDicInterfaces ENODictionaryFactory : public CATBaseUnknown
{
public:
           ENODictionaryFactory();
  virtual ~ENODictionaryFactory();

private:
  ENODictionaryFactory( ENODictionaryFactory& );
  ENODictionaryFactory& operator=( ENODictionaryFactory& );

public:
  /**
   * Retrieves an interface to the Dictionary Manager and loads the dictionary.
   * The VPMIDicMgr interface returned by this method is ready to use, i.e. no LoadPackage call should be needed.
   * You should call this method only once (you just have to keep the reference).
   * @param oDictionary: Dictionary manager
   * @return S_OK, E_FAIL
   */
  HRESULT GetDictionary( VPMIDicMgr_var& oDictionary );

  /**
   * Retrieves an interface to the Dictionary Manager and loads the dictionary through the streams provided by VPMIDicStream.
   * The VPMIDicMgr interface returned by this method is ready to use, i.e. no LoadPackage call should be needed.
   * You should call this method only once (you just have to keep the reference).
   * @param oDictionary: Dictionary manager
   * @param iFromServer: The object which sends the metadata stream and the environment stream
   * @return S_OK, E_FAIL
   */
  HRESULT GetDictionary( VPMIDicMgr_var& oDictionary, VPMIDicStream& iFromServer );

private:
  VPMIDicGet& get_;
};

#endif /*ENODictionaryFactory_H*/

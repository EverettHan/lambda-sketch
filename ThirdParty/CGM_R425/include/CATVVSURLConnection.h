/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================

/**
 * @level Protected
 * @usage U2
 */

#ifndef CATVVSURLConnection_H
#define CATVVSURLConnection_H

#include "CATVVSNetBase.h"
#include "CATILockBytes2.h"
#include "CATUnicodeString.h"
#include "CATVVSUrl.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"

class CATOmyPowerIOURLCachedConnection;

/**
 * 
 */
class ExportedByVVSNetBase CATVVSURLConnection
{
  public:
  
  /**
   * Construct a new CATVVSURLConnection
   */
  CATVVSURLConnection();

  /**
   * Destructor
   */
  virtual ~CATVVSURLConnection();

  /**
   * Use this if you want to copy the object.
   * The copy constructor cannot be used here, as
   * at least the Close() function is vurtual.
   */
  virtual CATVVSURLConnection* Clone() const { return new CATVVSURLConnection(*this); }

  /**
   * Initialises the object
   * It can be called once on the Lifetime of the object
   * @param iURL
   * The url the connection represents
   * @param iStream
   * The stream represented by the url
   * @return
   * S_OK if the connection was succesfully initialised, or E_FAIL otherwise
  */
  HRESULT InitWith(const CATVVSUrl& iURL,CATILockBytes2* iStream) ; 

  /**
   * Returns the stream in order to read from it or write in it
   * @param oStream
   * The Stream (this pointer is AddRef-ed)
   * @return
   * S_OK if the connection was succesfully initialised, or E_FAIL otherwise
   */
  HRESULT GetILockBytes2(CATILockBytes2*& oStream) const ;
  
  /**
   * Returns the associated Url
   * @param oUrl
   * The url
   * @return
   * S_OK if the connection was succesfully initialised, or E_FAIL otherwise
   */
  HRESULT GetUrl(CATVVSUrl & oUrl) const ;

  // @deprecated  
  HRESULT GetProperty(const CATUnicodeString& iKey,CATUnicodeString*& oValue) ;

  // @deprecated
  virtual HRESULT Close();

  // ConverToCacheConnection
  inline virtual CATOmyPowerIOURLCachedConnection* asCacheConnection() {return NULL;}
 
  protected:
  
  /** Url of the pointed stream. */
   CATVVSUrl _urlOftheStream;

   /** Handle on the pointed stream. */
   CATOmxSR<CATILockBytes2>  _spStream ;

  /** Copy Constructor */  
  CATVVSURLConnection (const CATVVSURLConnection& iURLConnection);

  /** Assignment operator */  
  CATVVSURLConnection& operator=(const CATVVSURLConnection&);     
};

class ExportedByVVSNetBase CATVVSURLConnectionSharable : public CATOmxSharable
{
  public:
  
  /**
   * Construct a new CATVVSURLConnectionSharable
   */
  CATVVSURLConnectionSharable();
  CATVVSURLConnectionSharable(const CATVVSURLConnection& iConnection);

  /**
   * Destructor
   */
  virtual ~CATVVSURLConnectionSharable();
  
  /**
   * Initialises the object
   * It can be called once on the Lifetime of the object
   * @param iURL
   * The url the connection represents
   * @param iStream
   * The stream represented by the url
   * @return
   * S_OK if the connection was succesfully initialised, or E_FAIL otherwise
  */
  HRESULT InitWith(const CATVVSUrl& iURL,CATILockBytes2* iStream) ; 

  /**
   * Returns the stream in order to read from it or write in it
   * @param oStream
   * The Stream (this pointer is AddRef-ed)
   * @return
   * S_OK if the connection was succesfully initialised, or E_FAIL otherwise
   */
  HRESULT GetILockBytes2(CATILockBytes2*& oStream) const ;
  
  /**
   * Returns the associated Url
   * @param oUrl
   * The url
   * @return
   * S_OK if the connection was succesfully initialised, or E_FAIL otherwise
   */
  HRESULT GetUrl(CATVVSUrl & oUrl) const ;
     
  /** ConverToCacheConnection*/  
  CATOmyPowerIOURLCachedConnection* asCacheConnection();

  protected:
  CATVVSURLConnection* _pConnection;

  /** Copy Constructor */  
  CATVVSURLConnectionSharable (const CATVVSURLConnectionSharable& iURLConnection);

  /** Assignment operator */  
  CATVVSURLConnectionSharable& operator=(const CATVVSURLConnectionSharable&);
};

#endif




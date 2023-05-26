// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATPLMReplicationStreamInfo.h
// Header definition of CATPLMReplicationStreamInfo
//
//===================================================================
//
// Usage notes:
//
//===================================================================
/**
* @level Private
* @usage U1
*/
#ifndef CATPLMReplicationStreamInfo_H
#define CATPLMReplicationStreamInfo_H

#include "CATPLMServicesItf.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATVVSUrl.h"
#include "CATLISTV_CATPLMReplicationStreamInfo.h"

//-----------------------------------------------------------------------

/**
* Structure describing a vault stream to be exported or imported by the replicationEngine.
* <b>Role:</b>
* <li>FileId (CATString) is the identifier given at extraction to this stream
* <li>Url is the vault url of the stream to be exported/imported
* <li>TypeLate (CATUnicodeString) is the latetype of the document included in the stream
* <li>MarkStamp (int) is the stamp given to the stream when it was last modified.
*/
class ExportedByCATPLMServicesItf CATPLMReplicationStreamInfo
{
public:


  CATPLMReplicationStreamInfo(const CATString &iFileId, const CATVVSUrl &iUrl, const CATUnicodeString &iTypeLate, const int iMarkStamp);
  virtual ~CATPLMReplicationStreamInfo ();

	/**
	*	Returns the replication stream identifier (given at extraction)
	*/
  HRESULT GetFileId( CATString &oFileId ) const;

	/**
	*	Returns the replication stream vault url
	*/
  HRESULT GetUrl( CATVVSUrl &oUrl) const  ;

	/**
	*	Returns the replication stream latetype
	*/
  HRESULT GetTypeLate( CATUnicodeString &oTypeLate ) const;

	/**
	*	Returns the replication stream watermarkstamp 
	*/
  HRESULT GetMarkStamp( int &oMarkStamp ) const;

	/**
	*	Dump content as unicodestring
	*/
  CATUnicodeString ToUnicodeString() const;

	/**
	*	== operator
	*/
  int operator == ( const CATPLMReplicationStreamInfo& other ) const ; 

  /**
	*	!= operator
	*/
  int operator != ( const CATPLMReplicationStreamInfo& other ) const ; 

  CATPLMReplicationStreamInfo(const CATPLMReplicationStreamInfo& ICOPY);   	

private:
  int _markStamp;
  CATString _fileId;
  CATVVSUrl _url;
  CATUnicodeString _typeLate;
  	
 	CATPLMReplicationStreamInfo operator=(CATPLMReplicationStreamInfo& ICOPY); // = operator should not be implemented
};

//-----------------------------------------------------------------------

#endif

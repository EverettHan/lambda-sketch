#ifndef CATVVSWatcher_H
#define CATVVSWatcher_H
/**
* @level Private
* @usage U1
*/

#include "CATVVSNetBase.h"
#include "CATUnicodeString.h"
#include "IUnknown.h"

class ExportedByVVSNetBase CATVVSWatcher
{

public:

	CATVVSWatcher(){};
	virtual ~CATVVSWatcher(){};


	/**
	* VVS Impl informs the Cache Layer the upload is beginning.
	*
	* @param iCountBytes [in]
	*   The bytes number to upload.
	* @param iCountFiles [in]
	*   The file number to upload.
	*
	* @return S_OK if everything ran ok, otherwise E_FAIL
	*
	*/
	virtual HRESULT Start(unsigned long long iCountBytes, int iCountFiles) {return E_NOTIMPL;} ;


	/**
	* VVS Impl informs the Cache Layer the file upload is beginning.
	*
	* @param iFileName [in]
	*   The filename.
	* @param iSize [in]
	*   The file size.
	*
	* @return S_OK if everything ran ok, otherwise E_FAIL
	*
	*/
	virtual HRESULT StartFile(CATUnicodeString iFileName, CATULONG64 iSize) {return E_NOTIMPL;} ;

	/**
	* VVS Impl informs the Cache Layer the file upload is ended.
	*
	* @return S_OK if everything ran ok, otherwise E_FAIL
	*
	*/
	virtual HRESULT EndFile() {return E_NOTIMPL;} ;

	/**
	* VVS Impl updates the byte count.
	*
	* @param iByteCount [in]
	*   The byte Count.
	*
	* @return S_OK if everything ran ok, otherwise E_FAIL
	*
	*/
	virtual HRESULT UpdateStatus(int iByteCount) {return E_NOTIMPL;} ;

	/**
	* VVS Impl informs the Cache Layer the upload is ended.
	*
	* @return S_OK if everything ran ok, otherwise E_FAIL
	*
	*/
	virtual HRESULT End() {return E_NOTIMPL;} ;

	/**
	* VVS Impl pushes an error to the Cache Laye.
	*
	* @param iFileError [in]
	*   The filename.
	* @param iErrorDescription [in]
	*   The error descrition.
	*
	* @return S_OK if everything ran ok, otherwise E_FAIL
	*
	*/
	virtual HRESULT PushError(CATUnicodeString &iFileError, CATUnicodeString &iErrorDescription) {return E_NOTIMPL;} ;


private:
	CATVVSWatcher (CATVVSWatcher &);
	CATVVSWatcher& operator=(CATVVSWatcher&);

};


#endif

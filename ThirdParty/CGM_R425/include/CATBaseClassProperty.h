/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
/**
 *  CATBaseClassProperty :
 *      Base Class For Persistence Of Properties In Storages
 */
//================================================================
//  Usage notes :
//
//  
//	June.98	lbf/slg
//================================================================
#ifndef CATBaseClassProperty_H
#define CATBaseClassProperty_H

/**
 * @level Private
 * @usage U2
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"
#include "CATIAV5Level.h"
//
class CATStorage ;
class CATStream;

/**
 * This class is an adapter C++ for the component CATDocumentProperty, CATStorageProperty and CATSymbolProperty.
 * It declared CATIPersitStorage methods, surcharged by its descendants and have 2 methods specific to stream property.
 */
class ExportedByAC0XXLNK CATBaseClassProperty: public CATBaseUnknown
{  
public :

  //	'TORS
  //	-----
  CATBaseClassProperty ( );
  virtual ~CATBaseClassProperty ();

  /**
   * Dump Service
   */
  virtual void Dump ();
  /**
   * Method GetLastVersion<BR>
   * <B>Role:</B>
   *  Get the version of this component
   * @return The version number
   */
  int GetLastVersion();
  /**
   * METHOD LoadFromStream<BR>
   * <B>Role:</B>
   * This method tries to read the given Stream, extract property data and Unmarshall it to set the ClassProperty 
   * of the Document.
   * @param Stream 
   *    The stream analysed to load Property infomration of the document
   * @return 
   *     S_OK if this command succeeds
   */
  HRESULT LoadFromStream (CATStream* Stream);
  /**
   * Method SaveInStream<BR>
   * <B>Role:</B>
   * Save the Property information of the document in the Stream
   * @param Stream
   *   The stream where property information are written
   * @return
   *    S_OK if it succeeds
   */
  HRESULT SaveInStream(CATStream* Stream);   

  /**
   *  CATIPersistStorage interface
   */     
  // NOT IMPLEMENTED
  virtual HRESULT GetClassID (CLSID* pclsid) ;
  virtual HRESULT IsDirty () ;
  virtual HRESULT InitNew (CATStorage* pStg) ;
  virtual HRESULT SaveCompleted (CATStorage* pStgNew) ;
  virtual HRESULT HandsOffStorage () ;
  virtual HRESULT IsLoaded (); 
  // NOT IMPLEMENTED: implemented on children classes
  virtual HRESULT Load (CATStorage* pStg);
  virtual HRESULT Save (CATStorage* pStgSave, CATULONG32  fSameAsLoad);
  

  private:    
  CATBaseClassProperty ( const CATBaseClassProperty& StorageProperty);
  CATBaseClassProperty& operator =	( const CATBaseClassProperty& );

#ifndef CATIAR213
protected:
  //
  //	PROTECTED DATA: Version
  //	--------------
  int 		  _Version;	// Current version
  int			  _LastVersion; // Last version (>=_Version) depending on modelisation evolution
#endif
};

#endif

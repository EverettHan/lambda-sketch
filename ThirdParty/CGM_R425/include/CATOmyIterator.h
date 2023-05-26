// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATOmyIterator.h
//
//===================================================================
//
// Usage notes:
//  Used as argument by itf CATIOmyEditorNotification
//  to pass the notified editor list of elements
//
//===================================================================
//
//  Jan 2009  Creation JRZ
//===================================================================
/**
 * @level Protected
 * @usage U4
 */
#ifndef CATOmyIterator_H
#define CATOmyIterator_H

#include "CATBaseUnknown.h"
#include "CATOMYBaseSession.h"

class ExportedByCATOMYBaseSession CATOmyIterator
{
public: 
 /**
  * Next element
  * @param	ipElement [out, CATBaseUnknown#Release]
  *   Addref ptr to that element
  * @return
	*    S_OK   : Element returned
	*    E_FAIL : End of list
  */ 
  virtual HRESULT  Next(CATBaseUnknown  *&  ipElement) = 0;
	
  // Reset the editor at its begining
  virtual void   Reset() = 0;
  
  CATOmyIterator() ;
  virtual ~CATOmyIterator() ;
};


#endif

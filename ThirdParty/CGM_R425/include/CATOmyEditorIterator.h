/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2007
//=============================================================================
//
// Class CATOmyEditorIterator:
//
// Usage Notes: Iterator used to retrieve the list of registered CATOmyEditors
//
//=============================================================================

/**
 * @level Protected
 * @usage U1
 */


#ifndef CATOmyEditorIterator_H
#define CATOmyEditorIterator_H

#include "CATOMYBaseSession.h"

#include  "IUnknown.h"

class CATOmyEditor;

/**
 * Class used to iterate through the list of registered CATOmyEditors
 * <b>Role</b>: CATOmyEditorIterator provides access to the
 *				registered CATOmyEditors.
 */
class ExportedByCATOMYBaseSession CATOmyEditorIterator
{
public:

	 /** 
	 * Selects the next CATOmyEditor element.
	 *
	 * <br><b>Role</b>: Selects the next CATOmyEditor element.
	 *
	 * @param ioPosition [inout]
	 *    On  input,  it is  the  index  of  the  editor  (specify  0  for  the  first  editor).  
	 *    On  output,  it  will  represent  the  index  of  the  next  editor.
	 * @param oEditor [out]
	 *   The returned CATOmyEditor.
	 *
	 * @return
	 *  <ul>
	 *      <li><code>S_OK</code>  if  everything  ran  ok.</li>
	 *      <li><code>S_FALSE</code>  if  no  more  editors  are  available.  All  the  editors  were  parsed.</li>
	 *      <li><code>E_INVALIDARG</code>  if  invalid  position  is  provided.</li>
	 *      <li><code>E_FAIL</code>  if  a  fatal  error  occured  during  the  operation.  Nothing  was  done  during  the  operation.</li>
	 *      </ul> 
	 *
	 */
	 virtual HRESULT  Next(  int&  ioPosition,  CATOmyEditor  *&  oEditor) = 0;

   // MLK protection
   virtual ~CATOmyEditorIterator(){};
private:
	
};

#endif

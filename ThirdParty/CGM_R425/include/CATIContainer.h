/* -*-c++-*- */
#ifndef CATIContainer_h
#define CATIContainer_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Required               
 */

#include "sequence_CATBaseUnknown.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIContainer ;

/**
* Interface to structure a document.
*/

class ExportedByAD0XXBAS CATIContainer : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	/**
	* @nodoc
	*/
    virtual SEQUENCE(CATBaseUnknown_ptr) ListMembers (const CATIdent interfaceID)=0 ;
	/**
  * Searches all objects implementing a specific interface into  the container.<BR><BR>
	* <B>role:</B><BR>This method searches all objects implementing a specified interface given in argument and fill the sequence with them. Each object contained in the returned sequence must be released after user.<BR><BR>
  * <B>example</B>: <BR>
  * <TABLE>
  *   <TR><TD>&nbsp;&nbsp; CATIContainer* pCATIContainer = ... // we suppose that pointer is well initialized.</TD></TR>
  *   <TR><TD>&nbsp;&nbsp; SEQUENCE(CATBaseUnknown_ptr) ListObj;</TD></TR>
  *   <TR><TD>&nbsp;&nbsp; CATLONG32 NbObj = pCATIContainer-><B>ListMembersHere("CATIexample", ListObj)</B>;</TD></TR>
  *   <TR><TD>&nbsp;&nbsp; for (int i=0; i < NbObj; i++)</TD></TR>
  *   <TR><TD>&nbsp;&nbsp; {</TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp; CATIexample* pCATIexample = NULL;</TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp; if (ListObj[i] && SUCCEEDED(ListObj[i]->QueryInterface(IID_CATIexample, (void**)&pCATIexample))</TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp; { </TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; pCATIexample->Release();</TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; pCATIexample = NULL;</TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ListObj[i]-><B>Release()</B>;</TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ListObj[i] = NULL;</B>;</TD></TR>
  *   <TR><TD>&nbsp;&nbsp;&nbsp;&nbsp; }</TD></TR>
  *   <TR><TD>&nbsp;&nbsp; }</TD></TR>
  * </TABLE>
	* @param interfaceID The name of the interface searched.
	* @param ioListObj The list of all objects found that implement this interface. Each object  of the list must be release.
	* @return The number of objects found.
	*/
    virtual CATLONG32 ListMembersHere (const CATIdent interfaceID, SEQUENCE(CATBaseUnknown_ptr)& ioListObj)=0 ;
};

CATDeclareHandler( CATIContainer, CATBaseUnknown ) ;


#endif

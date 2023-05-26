#ifndef CATIAfrCommandHeader_H
#define CATIAfrCommandHeader_H

// COPYRIGHT DASSAULT SYSTEMES 2008

///////////////////////////////////////////////////////////////////////////////
//    CATIAfrCommandHeader.h                                                 //
///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........AfrFoundation                                       //
//    AUTEUR:............Cécilia Miltgen                                     //
//    DATE:..............08/09/2008                                          //
///////////////////////////////////////////////////////////////////////////////

//=============================================================================
//
// Interface for CATCommandHeader
//
//=============================================================================

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"
#include "CATAfrAvailabilityType.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrCommandHeader;
#else
extern "C" const IID IID_CATIAfrCommandHeader;
#endif

class CATDialog;
class CATStateCommand;
class CATString;
class CATUnicodeString;

class ExportedByCATAfrItf CATIAfrCommandHeader : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:

 /**
  * Sets the header visibility in the Tools/Customize command.
  * <br><b>Role</b>: This method enables you to hide or show the 
  * command header instance in the Tools/Customize command. It can be interesting
  * to hide some command header instances, when you do not want that the end user 
  * drag and drop your command in a toolbar. 
  * @param iIsVisible
  *		The header visibility in the Tools/Customize command.
  *		<br><b>Legal values</b>:
  *			<tt>1</tt> : visible
  *			<tt>0</tt> : invisible
  */
  virtual void SetVisibility(int iIsVisible)=0;
 
  
  /**
  * Retrieves the argument of the header.
  */
  virtual CATString & GetCurrentArgument()=0;


  /**
  * Manages the availability of the command.
  * <br><b>Role</b>: This method enables you to make the command of the header available or unavailable.
  * @param iType
  *		Command Header availability type.
  *		@see CATAfrCommandHeader
  * @param iState
  *    	Command Header state.
  *    	<br><b>Legal values</b>: 
  *       <li> CATFrmAvailable </li>
  *       <li> CATFrmUnavailable </li>
  */

  virtual void SetAvailability (CATAfrAvailabilityType iType, CATFrmState iState)=0;

};


//-----------------------------------------------------------------------------
//                             Handler
//-----------------------------------------------------------------------------

CATDeclareHandler(CATIAfrCommandHeader, CATBaseUnknown);

#endif

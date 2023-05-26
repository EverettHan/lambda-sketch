#ifndef CATAfrDialogCommandHeaderFactory_H
#define CATAfrDialogCommandHeaderFactory_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"
#include "CATAfrCommandHeader.h"
#include "CATString.h"

class CATBaseUnknown;

ExportedByCATAfrFoundation CATBaseUnknown * CreateDialogCmdHdrArgs(CATString iHeaderID, 
																   CATString iResourceFileName, 
																   CATString iLateType,
																   CATString iFw,
																   CATFrmState iState = CATFrmAvailable);

/**
* Base class to create a command header with a customized representation.
* <b>Role:</b> This class enables you to create a command header with a  
* customized representation. It means a representation which will be not the 
* default one: a push button in a toolbar, and a push item in the
* menu bar or a contextual menu. 
* <p> To do that, you should implement the @href CATIAfrCommandHeaderRep interface
* on a class deriving from <tt>CATBaseUnknown</tt> and specify a string (late type)
* which corresponds to the component that implements the interface.
* This interface enables you to provide your specific representation in the toolbar, 
* or/and the menubar, or/and the contextual menu. 
* This representation is an instance of a class deriving of
* the @href CATAfrCommandHeaderRep class.</p>
* <br>The @href CATCommand class describes how to create a customized command header. 
*/


class ExportedByCATAfrFoundation CATAfrDialogCommandHeaderFactory
{
public:
 /**
  * Constructs a command header with a customized representation.
  * @param iHeaderIdentificator
  *		The identificator of the command header class instance. It is the <tt>command</tt> 
  *		argument of the <tt>SetAccessCommand</tt> macro. 
  * @param iResourceFileName
  *    The name of the resource file.
  * @param iLateType
  *    The name of the late type (name of the component implementing the interface).
  * @param iState
  *    The command header state.
  *    <br><b>Legal values</b>: 
  *       <li> <tt>CATFrmAvailable</tt> (The default value) </li>
  *       <li> <tt>CATFrmUnavailable</tt> </li>
  */
	static CATBaseUnknown * CATCreateDialogCommandHeader(const CATString & iHeaderIdentificator, 
														 const CATString & iResourceFileName,
														 const CATString & iLateType,
														 int iState = CATFrmAvailable);
};

/** @nodoc */
#define CATAfrDialogCommandHeaderFactory
/** @nodoc */
#define CATCreateDialogCommandHeader(iHeaderIdentificator, iResourceFileName, iLateType, ...) \
	CreateDialogCmdHdrArgs(iHeaderIdentificator, iResourceFileName, iLateType, XMkHeaderStr(_MK_FWNAME_), ##__VA_ARGS__)

#endif

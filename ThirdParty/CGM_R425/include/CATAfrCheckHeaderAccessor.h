#ifndef CATAfrCheckHeaderAccessor_H
#define CATAfrCheckHeaderAccessor_H

// Copyright Dassault Systemes 2003

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATBaseUnknown.h"

#include "CATAfrFoundation.h"
#include "CATBoolean.h"

class CATCheckHeader;
class CATString;

/**
* Class to handle a check header.
* <b>Role</b>: A check header is a @href CATCommandHeader which is represented 
* in a toolbar or in the menu bar as a check button. The <tt>CATAfrCheckHeaderAccessor</tt> class encapsulates
*  the creation and the access to a check header instance. The class identifier (the argument of 
* the constructor) is also the check header identifier.
* <br><br><b>How to use this class ? </b>
* <p>A <tt>CATAfrCheckHeaderAccessor</tt> class instantiation creates a check header instance 
* only if the instance does not already exist in the command header list of the current 
* @href CATFrmEditor.
* <br>Each time you need an access on a check header instance, create an instance of the 
* <tt>CATAfrCheckHeaderAccessor</tt> class, 
* use its methods to modify or retrieve information on the check header instance, and then release
* the class instance.</p>
* <b>How to specify the check/uncheck behaviors ? </b> 
* <p>A check header has two states: check and uncheck. Specific behaviors are associated to its 
* two states by the means of two other @href CATCommandHeader instances. One will be started 
* whether the check button turns to the "checked" state ( @href #SetCheckCommand ) and the other will 
* be started whether the check button turns to the "unchecked" state ( @href #SetUncheckCommand ). 
* The behaviors are implemented in the commands called by these two command headers.</p>
* <p>However, the check/uncheck behaviors are not mandatory. You can create a check header only to have
* a header keeping a two position state. In this case, except the mandatory methods such 
* as the constructor and @href #SetResourceFile, only 
* the @href #IsChecked and the @href #SetCheck methods are really important.
* </p>
*/
class ExportedByCATAfrFoundation CATAfrCheckHeaderAccessor : public CATBaseUnknown
{ 
  CATDeclareClass;
  
  public:

    /** 
     * Constructs a CATAfrCheckHeaderAccessor.
     * <br><b>Role</b>:This method creates, if it does not already exist, a check header instance 
     * whose the name is iChechHeaderIdentifier. The check header instance pointer
     * can be retrieved, as a @CATCommandHeader class instance, thanks to the 
     * @href CATAfrGetCommandHeader global function. 
     * @param iCheckHeaderIdentifier
     *  Identifier for the check header instance.
     */
    CATAfrCheckHeaderAccessor (const CATString & iCheckHeaderIdentifier);

    virtual ~CATAfrCheckHeaderAccessor();
    
    /** 
     * Associates a command header to the "check" state. 
     * <br><b>Role</b>:The given command header will be started 
     * each time the check button is checked.
     * @param iChkCmdName
     *  Identifier of the header.
     */
    void        SetCheckCommand  (const CATString& iChkCmdName);
    
    /** 
     * Associates a command header to the "uncheck" state. 
     * <br><b>Role</b>: The given command header will be started 
     * each time the check button is unchecked.
     * @param iUchkCmdName
     *  Identifier of the header.
     */
    void        SetUncheckCommand(const CATString& iUchkCmdName);
    
    /** 
     * Returns the command header identifier associated to the "check" state.
     * @return 
     *  Identifier of the header.
     */
    CATString & GetCheckCommand  ();
    
    /** 
     * Returns the command header identifier associated to the "uncheck" state.
     * @return 
     *  Identifier of the header.
     */
    CATString & GetUncheckCommand();
    
    /** 
     * Associates a resource file name to the check header.
     * <br><b>Role</b>: This method enables you to associate NLS resources to the check header
     * instance. 
     * <ul>
     * <li>in <tt>iFileName</tt>.CATNls</li>
     * <pre>
     * iFileName.iCheckHeaderIdentifier.Help="Help text";
     * iFileName.iCheckHeaderIdentifier.ShortHelp="Short help text";
     * iFileName.iCheckHeaderIdentifier.LongHelp="Long help text";
     * iFileName.iCheckHeaderIdentifier.Category="Categoty";
     * </pre>
     * <li>in <tt>iFileName</tt>.CATRsc</li>
     * <pre>
     * iFileName.iCheckHeaderIdentifier.Icon.Normal="Icon Name";
     * iFileName.iCheckHeaderIdentifier.LongHelpId ="...";
     * </pre>
     * </ul>
     * @param iFileName
     *  Name of the resource file.
     */
    void        SetResourceFile  (const CATString& iFileName);
    
    /** 
     * Returns the resource file name associated to the check header.
     * @return
     *  Name of the resource file.
     */
    CATString   GetResourceFile  ();

    /** 
     * Returns the check button state.
     * @return
     *  FALSE for the unchecked state and TRUE for the checked state.
     */
    CATBoolean  IsChecked        ();
    
    /** 
     * Sets the state of the check button.
     * @param iChecked
     *  TRUE checks the buttons, FALSE unchecks it.
     * @param iStartCmd
     *  TRUE starts the command corresponding to the new state, FALSE does not start the command.
     */
    void SetCheck                (CATBoolean iChecked=TRUE, CATBoolean iStartCmd=TRUE);
    
  private:
    CATCheckHeader * _letter;
};
#endif

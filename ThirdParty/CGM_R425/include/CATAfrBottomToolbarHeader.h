#ifndef CATAfrBottomToolbarHeader_h
#define CATAfrBottomToolbarHeader_h

// COPYRIGHT DASSAULT SYSTEMES 2004

#include "CATAfrDialogCommandHeader.h"
#include "CATAfrFoundation.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
//---------------------------------------------------------------------- System
#include "CATBaseUnknown_WR.h"

class CATAfrBottomToolbarRep;
class CATAfrPLMBarStarterView;
class CATAfrComboWrapper;

/**
 * Base class for command headers to display their representation in the PLM toolbar. 
 * <b>Role</b>: This header allows you to add its representation in the PLM toolbar. 
 * <br>
 * This class of command header represents itself as a button displaying
 * a menu when clicked, a combo and an arrow button.
 * <ul>
 * <li>The menu can be filled with command headers.
 * The behavior of hte menu is automatic and not customizable.
 * Selecting in this menu starts the corresponding command.
 * <li>The combo is completely managed by the application.
 * The GetCombo method gets a pointer to this combo.
 * Each CATAfrBottomToolbarHeader automatically implements the
 * @href CATIAfrBottomToolbarHeaderArgument interface. A pointer to the combo is given
 * to the started command using this interface. The commands to be started must have an argument
 * of CATIAfrBottomToolbarHeaderArgument type (or derived).
 * <li>The arrow button is automatic. It starts the last started command.
 * </ul>
 * This class is an abstract class.
 *
 */
class ExportedByCATAfrFoundation CATAfrBottomToolbarHeader : public CATAfrDialogCommandHeader
{
	/** @nodoc */
  // Used in conjunction with CATImplementHeaderResources in the .cpp file
  CATDeclareHeaderResources;

	/** @nodoc */
  // Used in conjunction with CATImplementClass in the .cpp file 
  CATDeclareClass ;

  public:
   
/**
 * Constructs a CATAfrBottomToolbarHeader.
 * <br><b>Role</b>This method adds the argument header in the menu.
 * @param iHeaderName
 *   Identifier of the header to add. 
 */
    CATAfrBottomToolbarHeader(const CATString & iHeaderName);

/**
 * Sets the command header to be started.
 * <br><b>Role</b>This method sets the command header which is started by the user.
 * @param iHeaderName
 *   Identifier of the header. 
 */
    void SetHeader (const CATString& cmdName);

    CATString & GetHeader();

    // Manage the parameters combo
    // Use SetComboEditable or SetComboIcon method in the CATAfrBottomToolbarHeader constructor
    void SetComboEditable (CATBoolean ibool); // default is FALSE
    void SetComboIcon (CATBoolean ibool); // default is FALSE
    CATAfrComboWrapper *GetCombo(); // Gets a pointer to the combo.
    // Overload InitUserInterface method to fill the combo and add callbacks on it.
    // Should be a pure virtual method, if a command header derived class could be an abstract class...
    virtual void InitUserInterface ();
    // Overload these methods to set the behavior when the user interacts in the combo:
    virtual void ComboEdited   (CATUnicodeString & textEntered);
    virtual void ComboSelected (int selectedLineNumber);



    // NOT API methods (do not use):
    // =============================

    virtual ~CATAfrBottomToolbarHeader();
    CATCommandHeader * Clone() ;
    // Overloaded method
    CATCmdRep * CreateToolbarRep (CATCmdStarter *item, CATDialog *parent);
    CATBoolean GetComboEditable();
    CATBoolean GetComboIcon();
    CATAfrPLMBarStarterView *GetUniqueView();
    CATAfrBottomToolbarRep *GetUniqueRep();

    
  protected:

    // Used by the Clone method 
    CATAfrBottomToolbarHeader(CATCommandHeader *iHeaderToCopy);

  private:

    // Copy constructor, not implemented
    // Set as private to prevent from compiler automatic creation as public.
    CATAfrBottomToolbarHeader(const CATAfrBottomToolbarHeader &iObjectToCopy);

    // Assignment operator, not implemented
    // Set as private to prevent from compiler automatic creation as public.
    CATAfrBottomToolbarHeader & operator = (const CATAfrBottomToolbarHeader &iObjectToCopy);

    void GetSpecificResources ();
    
    CATString                 _header;
    CATAfrBottomToolbarRep   *_uniqueRep;
    CATUnicodeString          _comboCurrent;
    CATBoolean                _comboStyle;
    CATBoolean                _comboIcon;

    friend class CATAfrBottomToolbarRep;
    CATBaseUnknown_WR _uniqueViewWR;
    friend class CATAfrPLMBarStarterView;
};

#endif



#ifndef CATDlgVirtualEditor_H
#define CATDlgVirtualEditor_H

#include "DI0PANV2.h"

#include "CATCommand.h"

#include "CATDlgUtility.h"

#include "CATUnicodeString.h"

// Virtual Editor Style

// Use CATDlgVirtualEditorMultiline to create a multiline editor
#define CATDlgVirtualEditorMultiline     (1 << 1)

// Use CATDlgVirtualEditorWrap in combination of CATDlgVirtualEditorMultiline to create a multiline editor whose lines are wrapped
#define CATDlgVirtualEditorWrap          (1 << 2)

// Use CATDlgVirtualEditorSecured to create a secured editor (not supported in multiline editor)
#define CATDlgVirtualEditorSecured       (1 << 3)

// Use CATDlgVirtualEditorNoDecoration to create an editor without border nor background
#define CATDlgVirtualEditorNoDecoration  (1 << 4)

/**
 * This class is the base class of editors used in CATDlgVirtualKeyboard
 */
class ExportedByDI0PANV2 CATDlgVirtualEditor : public CATCommand
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iParent the command's parent
	 * @param iIdentifier the command's identifier
	 * @param iStyle a combination of CATDlgVirtualEditorXXX styles (see above)
	 */
	CATDlgVirtualEditor(CATCommand * iParent, const CATString& iIdentifier, int iStyle = 0);

	/**
	 * Destructor
	 */
	virtual ~CATDlgVirtualEditor();

	/**
	 * Set the current value
	 * @param iValue the current value
	 */
	void SetValue(const CATUnicodeString& iValue);

	/**
	 * Get the current value
	 * @return the current value
	 */
	const CATUnicodeString& GetValue();

	/**
	 * Display the editor
	 * @param iFrame the editor's frame
	 */
	virtual void Display(const DRECT& iFrame);

	/**
	 * Hide the editor
	 */
	virtual void Hide();

	/**
	 * Give focus to the editor
	 */
	virtual void SetFocus();

	/**
	 * Get the notification sent when text has modified
	 */
	CATNotification * GetEditModifyNotification() const;

	/**
	 * Get the notification sent when text is validated with RETURN key
	 */
	CATNotification * GetEditModifyExtNotification() const;

	/**
	 * Get the notification sent when the editor gains focus
	 */
	CATNotification * GetEditFocusInNotification() const;

	/**
	 * Get the notification sent when the editor loses focus
	 */
	CATNotification * GetEditFocusOutNotification() const;

protected:
	DRECT _frame;
	int _style;
	CATUnicodeString _value;
};

#endif

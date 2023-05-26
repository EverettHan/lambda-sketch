#ifndef CATDlgVirtualEditorIOS_H
#define CATDlgVirtualEditorIOS_H

#ifdef _IOS_SOURCE

#include "DI0PANV2.h"

#include "CATDlgVirtualEditor.h"

#include "CATBoolean.h"

// Auto-capitalization behavior
typedef enum {
	CATDlgVirtualEditorAutocapitalizationTypeNone,
	CATDlgVirtualEditorAutocapitalizationTypeWords,
	CATDlgVirtualEditorAutocapitalizationTypeSentences,
	CATDlgVirtualEditorAutocapitalizationTypeAllCharacters,
} CATDlgVirtualEditorAutocapitalizationType;

// Auto-correction behavior
typedef enum {
	CATDlgVirtualEditorAutocorrectionTypeDefault,
	CATDlgVirtualEditorAutocorrectionTypeNo,
	CATDlgVirtualEditorAutocorrectionTypeYes,
} CATDlgVirtualEditorAutocorrectionType;

// Spell-checking behavior
/* IOS 5 */
/*
typedef enum {
	CATDlgVirtualEditorSpellCheckingTypeDefault,
	CATDlgVirtualEditorSpellCheckingTypeNo,
	CATDlgVirtualEditorSpellCheckingTypeYes,
} CATDlgVirtualEditorSpellCheckingType;
*/

// Keyboard appearance
typedef enum {
	CATDlgVirtualKeyboardAppearanceDefault,
	CATDlgVirtualKeyboardAppearanceAlert,
} CATDlgVirtualKeyboardAppearance;

// Keyboard type
typedef enum {
	CATDlgVirtualKeyboardTypeDefault,
	CATDlgVirtualKeyboardTypeASCIICapable,
	CATDlgVirtualKeyboardTypeNumbersAndPunctuation,
	CATDlgVirtualKeyboardTypeURL,
	CATDlgVirtualKeyboardTypeNumberPad,
	CATDlgVirtualKeyboardTypePhonePad,
	CATDlgVirtualKeyboardTypeNamePhonePad,
	CATDlgVirtualKeyboardTypeEmailAddress,
	CATDlgVirtualKeyboardTypeDecimalPad,
	/* IOS 5 */
	//CATDlgVirtualKeyboardTypeTwitter,
} CATDlgVirtualKeyboardType;

typedef enum {
	CATDlgVirtualReturnKeyDefault,
	CATDlgVirtualReturnKeyGo,
	CATDlgVirtualReturnKeyGoogle,
	CATDlgVirtualReturnKeyJoin,
	CATDlgVirtualReturnKeyNext,
	CATDlgVirtualReturnKeyRoute,
	CATDlgVirtualReturnKeySearch,
	CATDlgVirtualReturnKeySend,
	CATDlgVirtualReturnKeyYahoo,
	CATDlgVirtualReturnKeyDone,
	CATDlgVirtualReturnKeyEmergencyCall,
} CATDlgVirtualReturnKeyType;

/**
 * This class is the IOS specification for CATDlgVirtualEditor
 */
class ExportedByDI0PANV2 CATDlgVirtualEditorIOS : public CATDlgVirtualEditor
{
public:
	/**
	 * Constructor
	 * @param iParent the command's parent
	 * @param iIdentifier the command's identifier
	 * @param iStyle a combination of CATDlgVirtualEditorXXX styles (see CATDlgVirtualEditor.h)
	 */
	CATDlgVirtualEditorIOS(CATCommand * iParent, const CATString& iIdentifier, int iStyle = 0);

	/**
	 * Destructor
	 */
	virtual ~CATDlgVirtualEditorIOS();

	/**
	 * Set the current value
	 * @param iValue the current value
	 */
	void SetValue(const CATUnicodeString& iValue);

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
	 * Set focus to the editor
	 */
	virtual void SetFocus();

	/**
	 * Set the auto-capitalization behavior
	 * @param iType the auto-capitalization type
	 */
	void SetAutocapitalizationType(CATDlgVirtualEditorAutocapitalizationType iType);

	/**
	 * Set the auto-correction behavior
	 * @param iType the auto-correction type
	 */
	void SetAutocorrectionType(CATDlgVirtualEditorAutocorrectionType iType);

	/**
	 * Set the spell-checking behavior
	 * @param iType the spell-checking type
	 */
	/* IOS 5 */
	//void SetSpellCheckingType(CATDlgVirtualEditorSpellCheckingType iType);

	/**
	 * Set if the return key is automatically enabled when text is entered by the user
	 * @param iReturnKeyAutoSensitivity
	 */
	void SetReturnKeyAutoSensitivity(CATBoolean iReturnKeyAutoSensitivity);

	/**
	 * Set the keyboard appearance
	 * @param iAppearance the keyboard appearance
	 */
	void SetKeyboardAppearance(CATDlgVirtualKeyboardAppearance iAppearance);

	/**
	 * Set the keyboard type
	 * @param iType the keyboard type
	 */
	void SetKeyboardType(CATDlgVirtualKeyboardType iType);

	/**
	 * Set the return key type
	 * @param iType the return key type
	 */
	void SetReturnKeyType(CATDlgVirtualReturnKeyType iType);

private:
	CATDlgVirtualEditorAutocapitalizationType _autocapitalizationType;
	CATDlgVirtualEditorAutocorrectionType _autocorrectionType;
	/* IOS 5 */
	//CATDlgVirtualEditorSpellCheckingType _spellCheckingType;
	CATBoolean _isReturnKeyAutoSensitivity;
	CATDlgVirtualKeyboardAppearance _keyboardAppearance;
	CATDlgVirtualKeyboardType _keyboardType;
	CATDlgVirtualReturnKeyType _returnKeyType;

	void * _pEditor;
};

#endif

#endif

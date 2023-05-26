#ifndef CATVisCIDComboSymbolType_H
#define CATVisCIDComboSymbolType_H

#include "CATVisCIDPanel.h"

#include "CATVidCtl.h"
#include "CATVisCIDComboTools.h"

class CATVidCtlSimpleCombo;

/**
* Role: VID widget to represent standard symbol type
* The symbols are, CROSS, PLUS, CONCENTRIC, COINCIDENT, FULLCIRCLE, FULLSQUARE, STAR, DOT, SMALLDOT
*/

class ExportedByCATVisCIDPanel CATVisCIDComboSymbolType: public CATVidCtl
{
	CATDeclareClass;
public:
	/**
	* iSymbolType, valid range: 1 ... 9
	*/
	CATVisCIDComboSymbolType(CATCommand *i_pParent, const CATString & i_pIdentifier, 
		const unsigned int iSymbolType = 1, CATBoolean iAutoAvailable = FALSE);

	virtual ~CATVisCIDComboSymbolType();

	// iSymbolType, valid range: 1 ... 9
	void SetSymbolType(const unsigned int iSymbolType);

	// Valid inputs: Auto or None
	// Set only if corresponding entries are already created in combo
	void SetSpecialValue(const CATVisCIDComboValueType iType); 

	// returns type of value set
	// valid return values for oSymbolType: 1...9
	CATVisCIDComboValueType GetSelect(unsigned int &oSymbolType);

	void CreateNoneLine();
	void DestroyNoneLine();
	void SetSelect(unsigned int sel);
	void SetSelectedAuto();

	/**
	* Get the @c Selected event.
	* 
	* The @c Selected event is emitted when user selected opacity value from combo
	*  
	* @par EventProperties
	*   - Name: @c "Selected"
	*   - Type of propagation: @c NoPropagation
	*   - Type of argument: @ref CATSYPEventArgs
	* 
	* @return the event instance. @c AddRef has NOT been called on
	* the returned pointer.
	*/
	static CATSYPEvent * Selected();

	//set maximum visible items in combo
	void SetMaxVisibleItems(int iMaxVisibleItem);
	//------------------------------------------------------------------------------
private:
	void UpdateHelpMessage(const CATVisCIDComboValueType iValueType, unsigned int iLineThickness=-1);
	void ComboSelect(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

private:
	CATUnicodeString _noneStr, _autoStr, _undefStr;
	CATBoolean _isAutoAvailable, _isNoneAvailable, _isUndefAvailable,_bTriggerEvents;
	unsigned int _noneIndex, _undefIndex, _autoIndex;
	CATVidCtlSimpleCombo *_pCombo;
};

#endif

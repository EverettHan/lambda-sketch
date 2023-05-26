#ifndef CATVisCIDComboOpacity_H
#define CATVisCIDComboOpacity_H

#include "CATVidCtl.h"
#include "CATVisCIDPanel.h"
#include "CATVisCIDComboTools.h"
class CATVidCtlSimpleCombo;

class ExportedByCATVisCIDPanel CATVisCIDComboOpacity: public CATVidCtl
{
	CATDeclareClass;
public:
	/**
	* iOpacity: valid range 0 to 255
	*/
	CATVisCIDComboOpacity(CATCommand *i_pParent, const CATString & i_pIdentifier, const unsigned char iOpacity = 0, CATBoolean iAutoAvailable = FALSE);
	virtual ~CATVisCIDComboOpacity();

	// valid range 0 to 255, this will be mapped to,
	//    222-225 :   0%
	//    159-221 :  25%
	//     95-158 :  50%
	//     32- 94 :  75%
	//      0- 31 : 100%
	// iOpacity will be ignored in case iType is Auto or None
	void SetOpacityValue(const unsigned char iOpacity);
	// Valid inputs: Auto or None
	// Set only if corresponding entries are already created in combo
	void SetSpecialValue(const CATVisCIDComboValueType iType); 

	// returns type of value set
	// valid return values for type Value: 255 (for 0%), 190 (for 25%), 127 (for 50%), 63 (for 75%), 0 for (100%)
	CATVisCIDComboValueType GetSelect(unsigned int &oOpacity);

	void CreateNoneLine();
	void DestroyNoneLine();
	
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


	//------------------------------------------------------------------------------
private:
	void SetComboSelect(int iIndex);
	void UpdateHelpMessage();
	void ComboSelect(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

private:
	CATUnicodeString      _NoneOpacityText;
	CATVidCtlSimpleCombo *_pCombo;
	unsigned int			_isAutoAvailable;
	unsigned int			_isNoneAvailable;
	CATBoolean  _bTriggerEvents;
	int	_noneIndex;

};

#endif

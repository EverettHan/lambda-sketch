#ifndef CATVisCIDComboLineThickness_H
#define CATVisCIDComboLineThickness_H

#include "CATVisCIDPanel.h"

#include "CATVidCtl.h"
#include "CATVisCIDComboTools.h"

class CATVizDisplayContext;
class CATVidCtlSimpleCombo;
class CATSettingRepository;

const int _nbMaxThinknessInPixel=16;

class ExportedByCATVisCIDPanel CATVisCIDComboLineThickness: public CATVidCtl
{
	CATDeclareClass;
public:
	/**
	* iOpacity: valid range 0 to 255
	*/
	CATVisCIDComboLineThickness(CATCommand *i_pParent, const CATString & i_pIdentifier, const int iLineThickness = 1, CATBoolean iAutoAvailable = FALSE);

	virtual ~CATVisCIDComboLineThickness();

	void SetLineThicknessValue(const unsigned int iLineThickness);

	// Valid inputs: Auto or None
	// Set only if corresponding entries are already created in combo
	void SetSpecialValue(const CATVisCIDComboValueType iType); 

	// returns type of value set
	// valid return values for type Value: 255 (for 0%), 190 (for 25%), 127 (for 50%), 63 (for 75%), 0 for (100%)
	CATVisCIDComboValueType GetSelect(unsigned int &oLineThickness);

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

	//set maximum visible items in combo
	void SetMaxVisibleItems(int iMaxVisibleItem);

	//------------------------------------------------------------------------------
private:
	void UpdateHelpMessage(const CATVisCIDComboValueType iValueType, unsigned int iLineThickness=-1);
	int SetComboLine(const unsigned int iLineThickness, const int iIndex = -1, CATVizDisplayContext* pDC=NULL);
	void ClearContents();
	void ConvertToRightUnit(float &ioValue, CATUnicodeString &unitStr);
	CATPixelImage* GetLineThicknessIcon(const unsigned int iLineThickness, CATVizDisplayContext* pDC=NULL);
	CATUnicodeString GetLineThicknessString(const unsigned int iLineThickness, CATVizDisplayContext* pDC=NULL);

	void CkeModified (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);

	void ComboSelect(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
	void ComboDrop(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

private:
	CATUnicodeString      _noneStr, _autoStr, _undefStr;
	CATBoolean _isAutoAvailable, _isNoneAvailable, _isUndefAvailable,_bTriggerEvents;
	unsigned int	_noneIndex, _undefIndex, _autoIndex;
	CATVidCtlSimpleCombo *_pCombo;

	int _currentUnit;
	CATSettingRepository *_pRepository;
	CATCallback         _ckeCB;
	CATPixelImage* _comboIcons[_nbMaxThinknessInPixel];
};

#endif

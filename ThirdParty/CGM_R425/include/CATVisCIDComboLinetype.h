#ifndef CATVisCIDComboLinetype_H
#define CATVisCIDComboLinetype_H

#include "CATVidCtl.h"
#include "CATVisCIDPanel.h"
#include "CATVisCIDComboTools.h"

class CATVizDisplayContext;
class CATVidCtlSimpleCombo;

class ExportedByCATVisCIDPanel CATVisCIDComboLinetype: public CATVidCtl
{
	CATDeclareClass;
public:
	/**
	* iLinetype : valid range 1 to 7
	*/
	CATVisCIDComboLinetype(CATCommand *i_pParent, const CATString & i_pIdentifier, const int iLinetype = 1, CATBoolean iAutoAvailable = FALSE);

	virtual ~CATVisCIDComboLinetype();

	void SetLinetypeValue(const unsigned int iLinetype);

	// Valid inputs: Auto or None
	// Set only if corresponding entries are already created in combo
	void SetSpecialValue(const CATVisCIDComboValueType iType); 

	// returns type of value set
	CATVisCIDComboValueType GetSelect(unsigned int &oLinetype);

	void CreateNoneLine();
	void DestroyNoneLine();
	void SetSelectedNot();
	void SetSelectedAuto();

	void SetExtended(const CATBoolean iExtend);

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

	/** 
	 CATString - lable of image
	 isExtended = 0 then line type till 7 will be added 
	 isExtended = 1 then line type till 63 will be added
	*/
		void ExtendLineTypes(const CATString &, const CATBoolean isExtended = 0);


	//------------------------------------------------------------------------------
private:
	void UpdateHelpMessage(const CATVisCIDComboValueType iValueType, unsigned int iLinetype=-1);
	int SetComboLine(const unsigned int iLineType, const int iIndex = -1, CATVizDisplayContext* pDC=NULL);
	void ClearContents();

	void ComboSelect(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
	void ComboDrop(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

private:
	CATUnicodeString      _noneStr, _autoStr, _undefStr;
	CATVidCtlSimpleCombo *_pCombo;
	CATString _icon;
	CATBoolean _isAutoAvailable, _isNoneAvailable, _isExtended,_bTriggerEvents, _isUndefAvailable;
	unsigned int	_noneIndex, _undefIndex, _autoIndex;

};

#endif

#ifndef CATVisCIDComboRenderingStyle_H
#define CATVisCIDComboRenderingStyle_H

#include "CATVisCIDPanel.h"

#include "CATVidCtl.h"
#include "CATVisCIDComboTools.h"
#include "CATRenderingAttribut.h"

class CATVidCtlSimpleCombo;


class ExportedByCATVisCIDPanel CATVisCIDComboRenderingStyle: public CATVidCtl
{
	CATDeclareClass;
public:
	/**
	* irenderingStyle: valid range  
	*/
	CATVisCIDComboRenderingStyle(CATCommand *i_pParent, const CATString & i_pIdentifier, 
		const CATRenderingAttribut iRenderingStyle = CATRSNone, CATBoolean iAutoAvailable = FALSE);

	virtual ~CATVisCIDComboRenderingStyle();

	// 1...9
	void SetRenderingStyle(const CATRenderingAttribut iRenderingStyle);

	// Valid inputs: Auto or None
	// Set only if corresponding entries are already created in combo
	void SetSpecialValue(const CATVisCIDComboValueType iType); 

	// returns type of value set
	// valid return values for type Value: Transparent , Edge, Mesh, Edge | CATRSMesh, None
	CATVisCIDComboValueType GetSelect(CATRenderingAttribut &oRenderingStyle);

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
	void UpdateHelpMessage(const CATVisCIDComboValueType iValueType, const CATRenderingAttribut iRenderingStyle=0);
	void ComboSelect(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

private:
	CATUnicodeString  _autoStr, _transpStr, _edgeStr, _meshStr, _meshAndEdgeStr, _noneStr, _undefStr;
	CATBoolean _isAutoAvailable, _isUndefAvailable,_bTriggerEvents;
	unsigned int	_autoIndex, _undefIndex;

	CATVidCtlSimpleCombo *_pCombo;
};

#endif

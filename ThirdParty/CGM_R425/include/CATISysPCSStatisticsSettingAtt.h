//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//===========================================================================
//
//	CATStatisticsSetting
//
//	Usage Notes: Class Definition
//===========================================================================
//	Creation decembre 2004									siu
//===========================================================================
# ifndef _CATISYSPCSSTATISTISSETTINGSATT
# define _CATISYSPCSSTATISTISSETTINGSATT

// COPYRIGHT DASSAULT SYSTEMES 2003
# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATISysSettingController.h"
# include "CATBoolean.h"
# include "CATSysStatisticsDef.h"
#include "CATISysGeneralStatisticsSettingAtt.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS03TRA IID IID_CATISysPCSStatisticsSettingAtt;
#else
extern "C" const IID IID_CATISysPCSStatisticsSettingAtt;
#endif


/**
* Interface to handle the parameters of the PCS statistic.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the PCS statistic. 
* <br>This interface defines:
* <ul>
* <li>Methods to set each parameter</li>
* <li>Methods to get the value of each parameter</li>
* <li>A method to lock/unlock all parameters (there is only one lock per thematic)</li>
* <li>A method to retrieve the informations concerning all parameters</li>
* </ul>
* <br>For the definitions of methods and variables common to every thematic, see the @href CATISysGeneralStatisticsSettingAtt
*/
class ExportedByJS03TRA CATISysPCSStatisticsSettingAtt : public CATISysGeneralStatisticsSettingAtt
{
  CATDeclareInterface;

public :
/**
 * Retrieves the activation state of the memory field.
 * <br><b>Role</b>: Retrieves the activation state of the memory field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/

	virtual	HRESULT GetMemUse(CATBoolean &oStatus)=0;

/**
 * Sets the activation state of the memory field.
 * <br><b>Role</b>: Retrieves the activation state of the memory field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/

	virtual HRESULT SetMemUse(const CATBoolean &iStatus)=0;

};


# endif /* _CATISYSPCSSTATISTISSETTINGSATT */



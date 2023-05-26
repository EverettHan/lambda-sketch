//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  CATStatisticsSetting                                                 
//                                                                           
//  Usage Notes: Class Definition                                             
//===========================================================================
//  Creation novembre  2003                                 siu         	
//===========================================================================
# ifndef _CATISYSACCESSLOGSTATISTISSETTINGSATT
# define _CATISYSACCESSLOGSTATISTISSETTINGSATT

// COPYRIGHT DASSAULT SYSTEMES 2003

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATISysSettingController.h"
# include "CATBoolean.h"
# include "CATSysStatisticsDef.h"
# include "CATISysGeneralStatisticsSettingAtt.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS03TRA IID IID_CATISysAccesslogStatisticsSettingAtt;
#else
extern "C" const IID IID_CATISysAccesslogStatisticsSettingAtt;
#endif

/**
* Interface to handle the parameters of the accesslog statistic.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the accesslog statistic. 
* <br>This interface defines:
* <ul>
* <li>Methods to set each parameter</li>
* <li>Methods to get the value of each parameter</li>
* <li>A method to lock/unlock all parameters (there is only one lock per thematic)</li>
* <li>A method to retrieve the informations concerning all parameters</li>
* </ul>
* <br>For the definitions of methods and variables common to every thematic, see the @href CATISysGeneralStatisticsSettingAtt
*/
class ExportedByJS03TRA CATISysAccesslogStatisticsSettingAtt : public CATISysGeneralStatisticsSettingAtt
{
  CATDeclareInterface;

public :

};


# endif /* _CATISYSACCESSLOGSTATISTISSETTINGSATT */

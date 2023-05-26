#ifndef CATStatsSettings_H
#define CATStatsSettings_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS03TRA.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATSettingInfo.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS03TRA IID IID_CATIStatsSettings;
#else
extern "C" const IID IID_CATIStatsSettings;
#endif

class CATIStatsSettings  : public CATBaseUnknown
{
  public:
  CATDeclareInterface;

  /** 
   *  To read  the settings
  **/
  virtual HRESULT ReadSettings(int iFlags=0 , int *oFlags=NULL)=0;
 


public :

/*
 * Method allowing the initialization of the setting parameters
 * by default, 5 parameters are selected
 * THEM - TIME - ELPS - RTIM - UCPU
 */
//	virtual HRESULT Initialize() = 0;



/*
 * Setting Infos
 */
	virtual HRESULT GetOutputSettingInfo (CATSettingInfo &iOutputFormat)=0;

};
#endif

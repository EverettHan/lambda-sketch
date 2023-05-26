#ifndef CATIStatsManager_H
#define CATIStatsManager_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS03TRA.h"

#include "CATMacForIUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class CATIStatsThematics;
class CATIStatsManager;

/** 
 * obtains the statistic manager 
 *   iReservedForNow : reserved for future use
 */
ExportedByJS03TRA CATIStatsManager   *CATGetStatisticsManager(int iReservedForNow=0 );

/**
 * CATIStatsManager is the interface which allows the global management of the statistics
 * This class permits to  :
 *    obtain a thematics
 *    update the statistic configuration ( which stats are active , their output .. )
 *    close all the opened thematics
 */
class ExportedByJS03TRA  CATIStatsManager : public IUnknown
{
   public:
   CATDeclareInterface;

  /** 
   * obtain a statistics thematic interface
   *   iThematicsName : name of the wanted statistics thematics
   *   iReservedForNow : reserved for future use
   */
   virtual CATIStatsThematics *GetThematics( const char *iThematicsThem, int iReservedForNow =0 )=0;
 
  /** 
   *   Force the update of statistics to take into account tools/option changes
   *   iReservedForNow : reserved for future use
   */
   virtual HRESULT UpdateConfiguration(int iReservedForNow=0)=0;

  /** 
   *   Closes all statistics thematics and  dump the results 
   *   iReservedForNow : reserved for future use
   */
   virtual HRESULT CloseAll(int iReservedForNow=0)=0;

  /**
   * Methods that allow the enumeration of actives Statistics for the ToolsOption
   */
   virtual HRESULT GetFirstActiveStatisticName( CATUnicodeString &oName)=0;
   virtual HRESULT GetNextActiveStatisticName(CATUnicodeString &oName)=0;

  /**
   * Methods to retrieve all the pathes of active Statictics log file
   */
   virtual HRESULT CollectStatisticsLogFilePath(CATListOfCATUnicodeString& oListOfPath, bool iActiveOnly = true) = 0;
};
#endif 






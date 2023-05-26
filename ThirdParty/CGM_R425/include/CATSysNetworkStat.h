// COPYRIGHT DASSAULT SYSTEMES 2008
#ifndef CATSysNetworkStat_H
#define CATSysNetworkStat_H
/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#define CATSysNetworkStatisticsDefaultLevel           0

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "CATIStatsThematics.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/
/**
 * Initialize a new NETWORK statistics object
 *   @param oppStatisticRef
 *          Pointer address of the numerical operator object
 *   @param iActivationLevel
 *         Statistics activation level
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsInit ( void** oppStatisticsRef
                                                      , unsigned int iActivationLevel = CATSysNetworkStatisticsDefaultLevel);

 /**
  * Begin a NETWORK statistics event
  *   @param iFirstFieldName
  *         First applicative field name of the new event
  *   @param iFirstFieldValue
  *         Value for first applicative field
  *   @param iActivationLevel
  *         Statistics level
  */
ExportedByJS03TRA CATStatsEventId CATSysNetworkStatisticsBeginEvent ( const char* ipFirstFieldName
                                                                    , const char* ipFirstFieldValue
                                                                    , unsigned int iActivationLevel = CATSysNetworkStatisticsDefaultLevel);

/**
 * Add a field to a NETWORK statistics event
 *    @param iEventId
 *          Event identifier
 *    @param iFieldName
 *          Field name for a given event
 *    @param iFieldValue
 *          Value for the corresponding field name
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsAddField ( const CATStatsEventId iEventId
                                                          , const char* ipFieldName
                                                          , const char* ipFieldValue);

/**
 * Add a statistics field to a NETWORK statistics event
 *    @param iEventId
 *          Event identifier
 *    @param ipStatisticRef
 *          Pointer address of the numerical operator object
 *    @param iStatisticFlags
 *          Statistic operations flag. Possible flags are:
 *                        - CATStatsIncOp:  Variable calls count
 *                        - CATStatsSumOp:  Variable accumulation
 *                        - CATStatsAvgOp:  Variable mean
 *                        - CATStatsVarOp:  Variable variance
 *                        - CATStatsStdOp:  Variable standard deviation
 *                        - CATStatsStrOp:  Variable relative standard deviation
 *                        - CATStatsMinOp:  Variable minimum
 *                        - CATStatsMaxOp:  Variable maximum
 *        Note that when the statistics field name and/or format are set only one flag can be added at a time.
 *    @param ipStatisticsFieldName
 *        Statistics indicator name
 *    @param ipStatisticsValueFormat
 *        Statistics indicator value format
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsAddField ( const CATStatsEventId iEventId
                                                          , void* ipStatisticsRef
                                                          , const int iStatisticsFlags = CATStatsAllOp
                                                          , const char* ipStatisticsFieldName = NULL
                                                          , const char* ipStatisticsValueFormat = NULL);

/**
 * End a NETWORK statistics event
 *    @param iEventId
 *          Event identifier
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsEndEvent(const CATStatsEventId iEventId);

/**
 * Make statistics process
 *    @param ipStatisticRef
 *          Pointer address of the numerical operator object
 *    @param iUserVar
 *          User variable to evaluate
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsProcess(void* ipStatisticsRef, const double iUserVar = 0.0);

/**
 * Get statistic value
 *    @param ipStatisticRef
 *          Pointer address of the numerical operator object
 *    @param oStatisticVal
 *          Statistic value
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetOcc(void* ipStatisticsRef, double& oStatisticVal);
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetSum(void* ipStatisticsRef, double& oStatisticVal);
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetAvg(void* ipStatisticsRef, double& oStatisticVal);
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetVar(void* ipStatisticsRef, double& oStatisticVal);
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetStd(void* ipStatisticsRef, double& oStatisticVal);
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetStr(void* ipStatisticsRef, double& oStatisticVal);
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetMin(void* ipStatisticsRef, double& oStatisticVal);
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsGetMax(void* ipStatisticsRef, double& oStatisticVal);

/**
 * Reset the statistics values
 *    @param ipStatisticsRef
 *          Pointer address of the numerical operator object
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsReset(void* ipStatisticsRef);

/**
 * Destroy a NETWORK statistics object
 *    @param oppStatisticRef
 *          Pointer address of the numerical operator object
 */
ExportedByJS03TRA HRESULT CATSysNetworkStatisticsRelease(void** oppStatisticsRef);

/**
 * Ask if NETWORK statistics are activated
 */
ExportedByJS03TRA bool CATSysNetworkStatisticsIsActive(void);

/**
 * Get/Set NETWORK statistics administration level
 */
ExportedByJS03TRA unsigned int& CATSysNetworkStatisticsActivationLevel(void);

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

#endif // CATSysNetworkStat_H

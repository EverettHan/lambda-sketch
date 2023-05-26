#ifndef CATIStatsThematics_H
#define CATIStatsThematics_H


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS03TRA.h"
#include "CATMacForIUnknown.h"

/**
 * CATIStatsThematics interface is the key interface to add statistics into CATIA V5 Architecture
 *
 * statistics in V5 architecture are divided into thematics 
 * each thematics may be activated/redirected/controled separately from the others
 * This interface permits to :
 *	log statistical events
 *      dump these events
 *      control the obtention of statistics 
 *      create group of events permitting the dump of all events or only a summary of the results
 */

#define CATStatsAllGroups           -2 

/**
 *  invalid event id
 */
#define CATStatsInvalidEventId      -1 

/**
 *  invalid group id
 */
#define CATStatsInvalidGroupId      -1

/**
 * identifies an event in a given thematics 
 */
typedef int CATStatsEventId ;

/**
 * identifies a group of event in a given thematics 
 */
typedef int CATStatsGroupId ;

/**
 * Default options flags
 */
#define CATStatsDftOptionIdentify      0x00010000
#define CATStatsDftOptionActive        0x00020000
#define CATStatsDftOptionNoFieldNames  0x00040000
#define CATStatsDftOptionSetSeparator  0x00080000
#define CATStatsDftOptionCumulative    0x00100000
#define CATStatsDftOptionSuspendable   0x00200000

/**
 * Suspension flags
 */
#define CATStatsApplicativeSuspension 0x00000002
#define CATStatsStealSuspension       0x00000004
#define CATStatsSystemSuspension      0x00000008

/**
 * Statistical operations flags
 */
#define CATStatsOccOp   0x00000001
#define CATStatsSumOp   0x00000002
#define CATStatsAvgOp   0x00000004
#define CATStatsVarOp   0x00000008
#define CATStatsMinOp   0x00000010
#define CATStatsMaxOp   0x00000020
#define CATStatsStdOp   0x00000040
#define CATStatsStrOp   0x00000080
#define CATStatsAllOp   0x000000FF    // ( CATStatsOccOp
                                      // | CATStatsSumOp
                                      // | CATStatsAvgOp
                                      // | CATStatsVarOp
                                      // | CATStatsMinOp
                                      // | CATStatsMaxOp
                                      // | CATStatsStdOp
                                      // | CATStatsStrOp);
/**
 * Improvment to statistical measures
 */
#define _VXG_ADD_REAL_3DEXP_APPNAME 1
                                      
class ExportedByJS03TRA CATIStatsThematics : public IUnknown
{
  public:
   CATDeclareInterface; 

  public:
  /**
   * SetDefaultOptions  
   *  Set the default options for the thematics
   *  iDefaultFlags : Default flags to set, possible values are
   *        CATStatsDftOptionIdentify     : Before the first event , a single line is emited
   *                                       allowing to identify                  
   *                                       the session : application, username, hostname , ...
   *
   *        CATStatsDftOptionNoFieldNames : the field names won't be printed
   *
   *        CATStatsDftOptionSetSeparator : specifies the separator string
   *                                     with parameter iOptionalString
   *        CATStatsDftOptionActive   : the stats is active by default
   *                                    (should be used only exceptionaly)
   *       
   *        CATStatsDftOptionCumulative: if the statistics outputs into an    
   *                                     existing file it adds the lines at the
   *                                     end instead of erasing it.
   *       
   *       
   *        CATStatsDftOptionSuspendable:the statistics supports suspension   
   *                                     and specific response time
   *       
   *       
   */
	virtual HRESULT SetDefaultOptions(int iDefaultFlags, char *iOptionalString=NULL)=0;

  /**
   * IsActive
   *  Tells if the statistics thematics in active or not 
   *
   *   return -1 if the statistics is active and 0 otherwise
   */
	virtual int IsActive()=0;

  /**
   * Dump the summary of a group statistics
   *    @param iGroupId
   *        Group to summarize or  CATIStatsAllGroups
   *    @param iReservedForNow
   *        Reserved for future use
   */
	virtual HRESULT DumpGroupSummary( CATStatsGroupId iGroupId, int iReservedForNow=0)=0;

  /**
   * Dump the summary of a group statistics
   *    @param iGroupId
   *        Group to summarize or  CATIStatsAllGroups
   *    @param iFlags
   *        Stopping flags
   *    @param iReservedForNow
   *        Reserved for future use
   */
	virtual HRESULT StopGroup( CATStatsGroupId iGroupId, int iFlags, int iReservedForNow=0)=0;

  /**
   * Begins a new event  thematic interface
   *    @param iFirstField
   *        First applicative field name of the new event
   *        may only be NULL if the Event is part of an event group
   *    @param iFirstFieldValue
   *        Value for first applicative field
   *    @param iGroupId
   *        Group id
   *    @param iReservedForNow
   *        Reserved for future use
   */
	virtual CATStatsEventId BeginEvent( const char *iFirstField, const char *iFirstFieldValue,
                               CATStatsGroupId iGroupId = CATStatsInvalidGroupId , int iReservedForNow=0)=0;

  /**
   * Add a field to a begun event
   *    @param iEventId
   *        The event identifier
   *    @param iFieldName
   *        First applicative field name of the new event
   *        may only be NULL if the Event is part of an event group
   *    @param iFieldValue
   *        Value for first applicative field
   *    @param iReservedForNow
   *        Reserved for future use
   */
	virtual HRESULT AddField( CATStatsEventId iEventId, const char *iFieldName, const char *iFieldValue,
                     int iReservedForNow=0 )=0;
	virtual HRESULT AddFieldConditional ( CATStatsEventId iEventId, const char *iFieldName, const char *iFieldValue,
                     int iConditionFlag , int iReservedForNow=0 )=0;

  /**
   * End an event
   *    @param iEventId
   *        The event identifier
   *    @param iReservedForNow
   *        Rreserved for future use
   */
	virtual HRESULT EndEvent( CATStatsEventId iEventId, int iReservedForNow=0)=0;


  /**
   * Suspend an event
   *    @param iEventId
   *        The event identifier
   *    @parama iSuspensionFlag
   *        Suspension flag, values can be:
   *          CATStatsApplicativeSuspension
   *          CATStatsStealSuspension
   *          CATStatsSystemSuspension
   *  statistical accounts will be suspended until next ResumeEvent
   *
   *  SuspendEvent have not effect (and fails)  on an already suspended 
   *  event
   *  
   *  EndEvent will terminate the event 
   *
   */
	virtual HRESULT SuspendEvent( CATStatsEventId iEventId, int iSuspensionFlag=
	CATStatsApplicativeSuspension)=0;

  /**
   * Resume  a suspended event
   *
   *   ResumeEvent have no effect at all on a running event 
   *
   *    @param iReservedForNow : reserved for future use
   */
	virtual HRESULT ResumeEvent( CATStatsEventId iEventId, int iSuspensionFlag=CATStatsApplicativeSuspension)=0;

	virtual int IsSuspended(CATStatsEventId iEventId, int iSuspensionFlag=CATStatsApplicativeSuspension)=0;

	virtual int  IsSuspendable()=0;
   
   /**
   * CPU reservation
   * By calling this method, this event will suspend all other events
   * of the same statistics ( avoiding cpu double accounting)
   * The event iEventId will be resumed 
   *
   *    @param iEventId
   *        The event identifier
   *    @param iReservedForNow
   *        Reserved for future use
   */
	virtual HRESULT StartCPUReservation( CATStatsEventId iEventId, int iReservedForNow=0)=0;

  /**
   * End CPU reservation
   * By calling this method, this event will restore all other events
   * to their current state
   * The event iEventId will be ended
   *
   *    @param iEventId
   *        The event identifier
   *    @param iReservedForNow
   *        Rreserved for future use
   */
	virtual HRESULT StopCPUReservation( CATStatsEventId iEventId, int iReservedForNow=0)=0;

  /**
   * Closes the thematics and dump the unflushed results
   *    @param iReservedForNow : reserved for future use
   */
	virtual HRESULT Close( int iReservedForNow )=0;

  /**
   * Method to skip fields
   */
	virtual HRESULT SkipField (int NbField) =0;

	virtual CATStatsGroupId GetGroupId(const char *iGroupKey, int iFlags , 
                                   const char *iDefaultFirstFieldName,
                                   const char *iDefaultFirstValue ,
                                   int iReservedForNow=0) =0;

  // ===============================================================
  // Statistics operation management section
  // ===============================================================
  /**
   * Permit to obtain an identifier for a set of basic statistical operations
   *    @param oppStatisticRef
   *        Pointer address of the numerical operator object
   */
  virtual HRESULT GetStatisticsEventRef(void** oppStatisticsRef) = 0;

  /**
   * Add a field to a begun event with basic numerical statistics.
   *    @param iEventId
   *        The current event identifier on which we want to log the statistics
   *    @param ipStatisticRef
   *        Pointer address of the numerical operator object
   *    @param iStatisticsFlags
   *        Numerical operation flag
   *        The value of iStatisticsFlags can be one or a combination of the following flags:
   *            CATStatsOccOp : Variable call count (occurence value)
   *            CATStatsSumOp : Variable sum
   *            CATStatsAvgOp : Variable mean
   *            CATStatsVarOp : Variable variance
   *            CATStatsStdOp : Variable standard deviation
   *            CATStatsStrOp : Variable relative standard deviation
   *            CATStatsMinOp : Variable minimum value
   *            CATStatsMaxOp : Variable maximum value
   *            CATStatsAllOp : All of the previous statistics operations.
   *        Note that when the statistics field name and/or format are set only one flag can be added at a time.
   *    @param ipStatisticsFieldName
   *        Statistics indicator name
   *    @param ipStatisticsValueFormat
   *        Statistics indicator value format
   */
  virtual HRESULT AddStatisticsField  ( const CATStatsEventId iEventId
                                      , void* ipStatisticsRef
                                      , const int iStatisticsFlags = CATStatsAllOp
                                      , const char* ipStatisticsFieldName = NULL
                                      , const char* ipStatisticsValueFormat = NULL) = 0;

  /**
   * Process the numerical statistics operation
   *    @param ipStatisticRef
   *        Pointer address of the numerical operator object
   *    @param iUserVar
   *        User variable
   */
  virtual HRESULT UpdateStatistics(void* ipStatisticsRef, const double iUserVar = 0.0) = 0;

  /**
   * Get statistics value
   *    @param ipStatisticRef
   *        Pointer address of the numerical operator object
   *    @param oStatisticVal
   *        Statistic value
   *    @param iStatisticsFlags
   *        Numerical operation flag
   */
  virtual HRESULT GetStatistics(void* ipStatisticsRef, const int iStatisticsFlags, double& oStatisticVal) = 0;

  /**
   * Clear the numerical statistics on a given set
   *    @param ipStatisticRef
   *        Pointer address of the numerical operator object
   */
  virtual HRESULT ResetStatistics(void* ipStatisticsRef) = 0;

  /**
   * Clear the numerical statistics on a given set and release the set
   *    @param oppStatisticsRef
   *        Pointer address of the numerical operator object
   */
  virtual HRESULT StopStatistics(void** oppStatisticsRef) = 0;
};
#endif  // CATIStatsThematics_H

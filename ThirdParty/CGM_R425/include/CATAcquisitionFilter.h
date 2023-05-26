#ifndef CATAcquisitionFilter_h
#define CATAcquisitionFilter_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1996
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATBaseUnknown.h"

#include "CATBoolean.h"
#include "CATDialogAgent.h"
#include <stdlib.h>

class CATAcquisitionAgent;

/**
 * Method called to test an acquisition before an agent is prevaluated or valuated.
 * @param iAgent
 *   The agent to be prevaluated or valuated.
 * @param iData
 *   Data relative to the filter using this method.
 * @return 
 *   The result of the test.
 * @see CATAcquisitionFilter
 */
typedef CATBoolean (CATDialogAgent::*FilterMethod)(CATDialogAgent * iAgent, void * iData);

/**
 * The basic class for a filter.
 * <b>Role</b>: Filters are used to validate prevaluation or valuation of a @href CATAcquisitionAgent.
 * <br>To create a standard filter use the @href CATStateCommand#Filter method,
 * <br>then the command will delete the filter when it will be deleted.
 * <br>You can combine standard filters by using the @href CATDialogAgent#AndFilter,
 * @href CATDialogAgent#OrFilter and @href CATDialogAgent#NotFilter methods.
 */
class ExportedByCATDialogEngine CATAcquisitionFilter : public CATBaseUnknown
{

  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /** @nodoc */
  enum FilterType { UNKNOWN, METHOD, AND, OR, NOT };
  
  /**
   * This method is not useful, to create a filter you should use
   * @href CATStateCommand#Filter.
   */
  CATAcquisitionFilter ();
  
  /** @nodoc */
  CATAcquisitionFilter (const CATAcquisitionFilter &);
  
  /** @nodoc */
  CATAcquisitionFilter (FilterType, CATAcquisitionFilter *, CATAcquisitionFilter *);
  
  /** @nodoc */
  CATAcquisitionFilter (FilterType, CATAcquisitionFilter *);
  
  /** @nodoc
   * used by CATStateCommand::Filter to create a standard acquisition filter
   */
  CATAcquisitionFilter (CATDialogAgent * iMethodCmd, FilterMethod iMethod, void * iData=NULL);
  
  /** @nodoc */
  CATAcquisitionFilter & operator= (const CATAcquisitionFilter &);

  /**
   * This method is not useful IF you create the filter by using
   * @href CATStateCommand#Filter because the filter is deleted
   * by the command itself.
   */
  virtual ~CATAcquisitionFilter ();
  
  //--------------------------------------
  // virtual method to be defined by the application
  //--------------------------------------
  
  /** 
   *  @nodoc 
   *   this method is called in the DecodeNotification step
   *   of any acquisition agent before Accept.
   * @return 
   *   The result of the test.
   */
  virtual CATBoolean GetStatus ();
  
  //--------------------------------------
  // For internal use
  //--------------------------------------
  
  /** @nodoc */
  CATDialogAgent * GetCommand ();
  /** @nodoc */
  void SetCommand (CATDialogAgent * iAgent);
  /** @nodoc */
  void Dump (int iDecale=0);

private:  

  /*---------------------------------------------*/
  // Dump to De² methods
  /*---------------------------------------------*/
  /**
  * @nodoc 
  *  Internal use only 
  */
  FilterType                        GetFilterType()const;
  const CATAcquisitionFilter* const GetFilter1()const;
  const CATAcquisitionFilter* const GetFilter2()const;
  const FilterMethod                GeFilterMethodAddr()const;
  
  CATDialogAgent * _command; // the CATAcquisitionAgent which calls the filter.
  CATDialogAgent * _methodCmd;
  FilterType       _type;
  CATAcquisitionFilter * _firstFilter, * _secondFilter;
  FilterMethod _method;
  int _withData;
  void * _data;
  
  friend class CATDE2DumpCppStateCommand;
};

#endif

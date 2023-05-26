/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//								   
// CATTransactionTime:						   
//          Class for Time Management
//
//=============================================================================
// Considerations of usage:
//  CATTransactionTime has to be used whenever a time representation is
//  needed during a transaction (an end user interaction).
//  
//=============================================================================
//								   
// October 98   No base for Creation P. WALTER (PWR) 
//								   
//=============================================================================

#ifndef CATTRANSACTIONTIME_H
#define CATTRANSACTIONTIME_H

#include "CATLib.h"
#include "CATTime.h"

//-------------------------------------------------------------------
/**
 * CATTransactionTime is the class to use whenever a time representation
 * is to be manipulated during a transaction.
 * <p>
 */
class ExportedByNS0S7TIM CATTransactionTime
{
  public :

/**
 * Constructs an empty CATTransactionTime instance.
 */
  CATTransactionTime ();

/**
 * Copy constructor.
 */
  CATTransactionTime(const CATTransactionTime& iTime);
/*
 * Destructor
 */
  ~CATTransactionTime ();
  
/**
 * Retrieves the time corresponding to the current transaction.
 * @param UTCtime
 *   time in the current TIME ZONE.
 * @param UTCbias
 *   bias corresponding to the current TIME ZONE
 */
  void GetTransactionTime (CATTimeValue *UTCtime, CATLONG32 *UTCbias = NULL);

/**
 * Indicates the CATTransactionTime is to be updated because of a 
 * new transaction.
 */ 
  static void SetNewTransactionTime ();

/**
 * Compares two CATTransactionTime according to their their corresponding
 * transactions.
 * @return
 *    0  if both CATTransactionTime(s) correspond to the same transaction
 *    -1 if iTimeToCompare corresponds to a following transaction.
 *    1  if iTimeToCompare corresponds to a previous transaction.
*/
  int TransactionCompare ( const CATTransactionTime &iTimeToCompare ) const;

  // the following comparisons take into account the differences between 
  // two CATTransactionTime corresponding to the same transaction.
/**
 * Equality operator.
 */
  int operator == ( const CATTransactionTime &iTimeToCompare ) const;
/**
 * Less-than operator.
 */
  int operator <  ( const CATTransactionTime &iTimeToCompare ) const;
/**
 * Less-than or equal operator.
 */
  int operator <= ( const CATTransactionTime &iTimeToCompare ) const;


  private :

  static CATTimeValue _TransactionTime;
  static CATLONG32 _TransactionBias;
  static int _UpdateNeeded;
  static CATLONG32 _TransactionCount;
  CATTimeValue _UTCtime;
  CATLONG32 _UTCbias;
  CATLONG32 _Count;
};

#endif




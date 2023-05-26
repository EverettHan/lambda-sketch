/*
 * @Fullreview JXO 11:12:19
 */

// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceOperObserver.h
//
//===================================================================
//
// Usage notes:
// Parent class for observer on interference operators
//
//===================================================================
//
// Dec 2011 Creation: JXO
//===================================================================

#ifndef CATPolyInterferenceOperObserver_h
#define CATPolyInterferenceOperObserver_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATPolyRefCounted.h"
#include "CATErrorDef.h"

// Interference
class CATPolyInterferenceOper;
class CATBVHTreeSet;
class CATIPolyInterfInputCoupleFilter;
class CATPolyInterferenceList;
class CATPolyInterfWarningList;

// CATPolyInterferenceOperObserver should be removed.
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceOperObserver : public CATPolyRefCounted
{
public:
  CATPolyInterferenceOperObserver(){}
  virtual ~CATPolyInterferenceOperObserver(){}

  /**
   * See CATPolyInterferenceOper.
   */
  virtual void SetFirstOperand(const char * operatorname, CATBVHTreeSet * data1) = 0;
  
  /**
   * See CATPolyInterferenceOper.
   */
  virtual void SetSecondOperand(const char * operatorname, CATBVHTreeSet * data2) = 0;

  /**
   * See CATPolyInterferenceOper.
   */
  virtual HRESULT Run(int CheckPointFirstOperand, int CheckPointSecondOperand) = 0;

  /**
   * See CATPolyInterferenceOper.
   */
  virtual void EndRun() = 0;

  /**
   * See CATPolyInterferenceOper.
   */
  virtual void GetResult( CATPolyInterferenceList* ipList ) = 0;

  /**
   * See CATPolyInterferenceOper.
   */
  virtual void GetWarnings( CATPolyInterfWarningList* ipList ) = 0;

  /**
   * See CATPolyInterferenceOper.
   */
  virtual void AddInputCoupleFilter(CATIPolyInterfInputCoupleFilter * filter) = 0;
  /**
   * See CATPolyInterferenceOper.
   */
  virtual void RemoveInputCoupleFilter(CATIPolyInterfInputCoupleFilter * filter) = 0;

  /**
   * See CATPolyInterferenceOper.
   */
  virtual void AddRepCoupleFilter(CATIPolyInterfInputCoupleFilter * filter) = 0;

  /**
   * See CATPolyInterferenceOper.
   */
  virtual void RemoveRepCoupleFilter(CATIPolyInterfInputCoupleFilter * filter) = 0;

  /**
   * 
   */
  virtual void SetOperator(CATPolyInterferenceOper * o) = 0;

};

#endif /* CATPolyInterferenceOperObserver_h */

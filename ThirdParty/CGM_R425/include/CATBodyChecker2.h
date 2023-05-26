//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
// Creation AJM  12.Nov.2003
//
// Interface for body check operator class
//=============================================================================

#ifndef __CATBodyChecker2_h__
#define __CATBodyChecker2_h__

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATBodyChecker.h"
#include "CATBodyCheckerRules.h"
#include "CATThrowForNullPointer.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATCXBodyChecker;
class CATCheckDiagnosis;
class CATCheckDiagnosisList;

//=============================================================================

class ExportedByCATTopologicalOperators CATBodyChecker2 : public CATBodyChecker
{
  public:

    // Creator(Ctor) and Remover(Dtor)

    static CATBodyChecker2* Create(CATGeoFactory * ipFactory,
                                   CATTopData    * ipData,
                                   CATBody       * ipBodyToCheck);
    static CATBoolean Remove(CATBodyChecker2 *& ipBodyChecker);

    static CATBoolean Check(CATGeoFactory * ipFactory,
                            CATBody       * ipBodyToCheck,
                            CATLONG32     & ioNumberOfSevereAnomalies,
                            ostream       & ioDetailsOfAnomalies,
                            const CATBoolean & ibFullCheck = FALSE);

    static CATBodyChecker2* ConvertToCATBodyChecker2(CATBodyChecker *ipBodyChecker); //safe

    // Operator services/specific methods
    virtual int Run();
    virtual int Type() const;

    // Methods for querying/altering operator settings:
    //    - mode  [light (default, full, user, lightplus] 
    //    - rules [number and/or sequence of rules to check]
    //    - parameter [check rule parameters]
    //    - cells [cells i.e. subset of complete body to check]
    CATBoolean GetCheckerParameters(CATBodyCheckerRuleParam &oCheckRuleParams) const;
    CATBoolean SetCheckerParameters(CATBodyCheckerRuleParam &iCheckRuleParams);
    CATBoolean SetCheckRules(CATLISTP(CATBodyCheckerRuleDef) &ilsCheckRuleDefs);

    virtual CATBoolean GetCheckMode(CATBodyChecker::CheckMode &oCheckMode);
    virtual CATBoolean SetCheckMode(const CATBodyChecker::CheckMode &iCheckMode);
    virtual CATBoolean SetCheckRules(CATListOfInt *&iplsCheckRuleIDs);
    virtual CATBoolean SetCheckCells(CATLISTP(CATCell) &ilsCheckCells);

    // Methods for diagnosis/results analysis/iterators
    virtual CATLONG32 GetNbDiagnoses() const;
    virtual void BeginningDiagnosis();
    virtual CATBoolean NextDiagnosis();
    virtual CATBoolean GetDiagnosis(CATUnicodeString &oDiagnosisString) const;
    virtual void Dump(ostream &ioOutput) const;

    const CATCheckDiagnosis* GetDiagnosis() const;
    const CATCheckDiagnosis* GetDiagnosis(CATLONG32 &iDiagnosisIndex) const;
		CATCheckDiagnosisList* GetCheckDiagnosisList() const;

		//KY1 : 10-12-2010

		/**	@nodoc @nocgmitf */ 
		static const  CATString  *GetDefaultOperatorId();

protected:
		/**	@nodoc @nocgmitf */
		int RunOperator();
		/**	@nodoc @nocgmitf */
		//static  CATString  _OperatorId; //voir CATCXBodyChecker
		/**	@nodoc @nocgmitf */
		const  CATString  *GetOperatorId();
		/** @nodoc @nocgmitf */
		void   RequireDefinitionOfInputAndOutputObjects();

private:
   inline CATCXBodyChecker * GetCheckExtensible() const;

  protected:

    // Ctor and Dtor
    CATBodyChecker2(CATGeoFactory   * ipFactory,
                   CATTopData       * ipData,
                   CATCXBodyChecker * ipImplementation);
    virtual ~CATBodyChecker2();

    // Operator internal methods
    void CheckDiagnosisIndex(char * iCallingMethod) const;

    // Data members
    CATLONG32         _lDiagnosisIndex;
#ifndef CATIACGMV5R21
    CATCXBodyChecker *_pImplementation;
#endif
};

//=============================================================================

/** @nodoc  */
inline CATCXBodyChecker * CATBodyChecker2::GetCheckExtensible() const
{
#ifdef CATIACGMV5R21
   if (!GetExtensible()) CATThrowForNullPointerReturnValue(NULL);
   return (CATCXBodyChecker*) GetExtensible();   
#else
   if (!_pImplementation) CATThrowForNullPointerReturnValue(NULL);
   return _pImplementation;
#endif
}

#endif // __CATBodyChecker2_h__


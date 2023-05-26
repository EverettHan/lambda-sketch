#ifndef CATFastRunDebugTool_h
#define CATFastRunDebugTool_h

#include "CATBaseUnknown.h"
#include "ExportedByCATCXTopology.h"

class CATContextForFastRun;
class CATUnicodeString;
class CATCGMJournalList;
class CATIPGMTopOperator;
class CATTopData;
class CATBody;

/********************************************************************************************************************
CATFastRunDebugTool enums
********************************************************************************************************************/
enum CATFastRunDebugTool_ReportType {CATFastRunDebugTool_Copy, CATFastRunDebugTool_NoCopy};


/********************************************************************************************************************
CATFastRunDebugTool declaration
********************************************************************************************************************/

class ExportedByCATCXTopology CATFastRunDebugTool : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual ~CATFastRunDebugTool();

  /** @nodoc @nocgmitf
  * Sets the topological operator.
  */
  virtual void SetTopOperator(CATIPGMTopOperator * iIpgmTopOperator) = 0;



  /** @nodoc @nocgmitf
  * Sets the mode..
  */
  virtual void SetMode(const CATUnicodeString & iMode) = 0;

  /** @nodoc @nocgmitf
  * Sets the output directory path.
  */
  virtual void SetDirectoryPath(const CATUnicodeString & iDirectoryPath) = 0;

  /** @nodoc @nocgmitf
  * Sets the feature name.
  */
  virtual void SetFeatureName(const CATUnicodeString & iFeatureName) = 0;

  /** @nodoc @nocgmitf
  * Sets the topological journal reconstructed after StoreProcReport.
  */
  virtual void SetReconstructedJournalFromGN(CATCGMJournalList * iJournal) = 0;

  /** @nodoc @nocgmitf
  * To be called when feature build starts.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT StartBuild(const CATUnicodeString & iIdentifier) = 0;

  /** @nodoc @nocgmitf
  * To be called when feature build ends.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT EndBuild(const CATUnicodeString & iIdentifier) = 0;

  /** @nodoc @nocgmitf
  * To be called when feature build ends with an error.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT EndBuildWithError(const CATUnicodeString & iIdentifier) = 0;

  /** @nodoc @nocgmitf
  * To be called when topological operator Run starts.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT StartOperator(const CATUnicodeString & iIdentifier) = 0;

  /** @nodoc @nocgmitf
  * To be called when topological operator Run ends.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT EndOperator(const CATUnicodeString & iIdentifier) = 0;

  /** @nodoc @nocgmitf
  * To be called when topological operator Run ends with an error.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT EndOperatorWithError(const CATUnicodeString & iIdentifier) = 0;

  /** @nodoc @nocgmitf
  * To be called when GenericNaming CreateProcReport Run starts.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT StartCreateProcReport(const CATUnicodeString & iIdentifier)= 0;

  /** @nodoc @nocgmitf
  * To be called when GenericNaming CreateProcReport Run end.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT EndCreateProcReport(const CATUnicodeString & iIdentifier)= 0;

  /** @nodoc @nocgmitf
  * To be called when GenericNaming StoreProcReport Run starts.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT StartStoreProcReport(const CATUnicodeString & iIdentifier)= 0;

  /** @nodoc @nocgmitf
  * To be called when GenericNaming StoreProcReport Run end.
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual HRESULT EndStoreProcReport(const CATUnicodeString & iIdentifier)= 0;
  
  /** @nodoc @nocgmitf
  * To be called when GenericNaming ProcReport Run .
  * @param iIdentifier
  *   The unique identifier for the feature instance.
  */
  virtual void AddInputBody(CATBody * iBody,const CATUnicodeString & iFeatureName, CATFastRunDebugTool_ReportType iReportType, CATUnicodeString * iKey = NULL)= 0;

  /** @nodoc @nocgmitf
  * Executes one or several debug actions.
  */
  virtual HRESULT Execute() = 0;


  /** @nodoc @nocgmitf
  * only for Old Debug Macro.
  */
  virtual void SetOperatorName(const CATUnicodeString &iOperatorName) = 0; 
  
  /** @nodoc @nocgmitf
  * only for Old Debug Macro.
  */
  virtual void AddOperatorInputBody (CATBody * iBody) = 0; 
  
  /** @nodoc @nocgmitf
  * only for Old Debug Macro.
  */
  virtual void AddOperatorResultBody(CATBody * iBody) = 0; 

  /** @nodoc @nocgmitf
  * only for Old Debug Macro.
  */
  virtual void SetTopData(CATTopData* iTopData) = 0; 

  /**
   * @nodoc @nocgmitf
   * @return [out, CATBaseUnknown#Release]
   * Creates a CATFastRunDebugTool.
  */
  static CATFastRunDebugTool * Create();

protected:
  CATFastRunDebugTool();

private:
  CATFastRunDebugTool(const CATFastRunDebugTool & iOther);
};

/********************************************************************************************************************
CATFastRunDebugTool_var declaration
********************************************************************************************************************/

CATDeclareHandler(CATFastRunDebugTool, CATBaseUnknown);

#endif

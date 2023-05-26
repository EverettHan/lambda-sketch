/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATCheckReport_h
#define CATCheckReport_h

/** 
 *  @level Protected 
 *  @usage U1
 */
#include "ExportedByCATClnBase.h"

#include "CATBaseUnknown.h"
#include "CATListPtrCATCheckRule.h"
#include "CATCheckRule.h"
#include "CATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATListOfCATUnicodeString.h"
#include "CATHashDicOfCATUnicodeString.h"

#include "fstream.h"

class CATListPtrCATBaseUnknown;
class CATDocument;
/**
 * CATCheckReport manages the Check and Clean operations and generation of report.
 * <br><b>Role:</b>The check operation generates an object( documents, containers, features,<br>
 * topological entities etc.) called CATCheckReport filled with the violated rules and then,<br>
 * after the Check operation,this CATCheckReport object drives the Clean operation.<br>
 * At the end of the Check operation,the Report object contains the list of violated rules and<br>
 * a list of CATBaseUnknown on which CATICleanObject interface will be asked to launch the <br>
 * Clean operation with the Clean method (E_FAIL is returned if the Clean fails or does not exist,<br>
 * this method has also to be called on the super-class) having the Report object as an argument. <br>
 */
class ExportedByCATClnBase CATCheckReport 
{
  public:


/**
 * Constructs the CATCheckReport object.<br>
 * @param iFilename
 *			The name of CheckReport<br>
 *			If Filename is NULL, output is the standard one<br>
 * @param iCtxt
 *			This variable allows a communication with batch environment and resources.<br>
 * @param idummy
 *			Dummy argue for internal purpose.<br>
 * @param iForExternalUse
 *			This variable indicates the internal (DS) or external (Customer) usage.<br>
 *			It differentiates the Internal view and customer view of the product.<br>
 * <b>Legal values:</b><br>
 * <tt>0</tt> interne DS CheckRep<br>
 * <tt>1</tt> externe DS CheckRep<br>
 * <tt>2</tt> interne DS PLMBATCH<br>
 * <tt>3</tt> externe DS PLMBATCH<br>
 * <tt>4</tt> interne DS CheckRep Fildesk <br>
 * <tt>5</tt> externe DS CheckRep Fildesk <br>
 */
     CATCheckReport(const char * iFilename , int idummy = 0 , short iForExternalUse = 0);


/**
 * Destructs the object and its resources
 */    ~CATCheckReport();

/**
 * Adds Rule and Object.
 * <br><b>Role:</b>
 * Adds Rule and Object to Rule and Object list.<br>
 * Rule and Object must be added at the same time to avoid misunderstanding during print or clean process.
 * @param iRule
 *			The rule to add<br>
 * @param iObject
 *			The Object to add<br>
 */
     void AddRuleAndObject(CATCheckRule* iRule,CATBaseUnknown* iObject);

/**
 * Returns Object list.
 * @return 
 *		List of Object List.
 */
     CATListPtrCATBaseUnknown* GetObjectList();
     
/**
 * Returns Rule list.
 * @return 
 *		List of Rule.
 */
	 CATListPtrCATCheckRule* GetRuleList();
/**
 * Returns Rule list on specified Object.
 * @param iObject
 *			The specified Object.
 * @param iIsCurrent
 *			The current object is taken by default.
 * @return 
 *		List of Rule.
 */
     CATListPtrCATCheckRule* GetRuleListOnObject(CATBaseUnknown* iObject, boolean iIsCurrent=1);
/**
 * Returns Rule Codes on specified Object.
 * @param iObject
 *			The specified Object.
 * @param iIsCurrent
 *			The current object is taken by default.
 * @return 
 *		List of Rule Codes.
 */
	 CATListOfCATUnicodeString* GetRuleCodeOnObject(CATBaseUnknown* iObject, boolean iIsCurrent=1);
/**
 * Returns Rule Code.
 * @param iPos
 *			The specified position.
 * @return 
 *		The Rule Code.
 */
     CATUnicodeString GetRuleCode(int iPos);
/**
 * Returns total number of Rules.
 * @return 
 *		The total number of Rules.
 */
	 int GetNbRules();
 /**
 * Returns whether specified Rule is active.
 * @param iRuleCode
 *		The rule code.
 * @return 
 *		The status.
 * <br><b>Legal values:</b><br>
 * <tt>1</tt> the rule is active<br>
 * <tt>0</tt> the rule must not be executed<br>
 */
	 int IsActive(CATUnicodeString iRuleCode);

/**
 * Prints Report after check operation.
 * @param iCleanFollows
 *			Flag indication whether Clean Action follows after check.
 */
     void WriteAfterCheck(short iCleanFollows=0);
/**
 * Prints Report after check operation in non verbose mode.
 * @param iCleanFollows
 *			Flag indication whether Clean Action follows after check.
 */
	void NonVerboseWriteAfterCheck(short iCleanFollows);

/**
 * Adds message for clean.
 * @param iMsg
 *			Cleaner Message to add.
 */
     void AddCleanMessage(CATUnicodeString iMsg);

/**
 * Prints Report after clean operation.
 */
     void WriteAfterClean();	

/**
 * Prints Report after clean operation in non verbose mode.
 */ 
 	 void NonVerboseWriteAfterClean();

/**
 * Launches clean operation.
 */
     void LaunchClean();

/**
 * Return Current Rule code under action.
 * @return
 *			Current Rule code under action.
 */
	 CATUnicodeString GetCurrentCode();

/**
 * Returns Current Rule under action.
 * @return
 *			Current Rule under action.
 */
	 CATCheckRule* GetCurrentRule();

/**
 * Returns List of Counter for number of Links on embedded features.
 * @return
 *			List of counters for number of Links on embedded features.
 */
	 CATListOfInt* GetCounter() { return _IndexCounter;}

/**
 * Returns current Link Manager.
 * @return
 *			Link Manager.
 */
	 CATBaseUnknown_var GetLinkManager() { return _LinkMan;}
/**
 * Sets Link Manager.
 * @param iLm
 *		Link Manager.
 */
	 void SetLinkManager(CATBaseUnknown_var iLm) { _LinkMan = iLm;}

/**
 * Sets document to check/clean.
 * @param iDoc
 *		Document pointer.
 */
	 void SetDocument(CATBaseUnknown* iDoc) {_Document = iDoc;}
/**
 * Returns the number of corrected Rules.
 * @return 
 *			The number of corrected Rules.
 */
     int GetCorrectedErrors() { return _CorrectedErrors;}

/**
 * Returns flag for ForcedRepair of Rules.
 * @return
 *			The flag for ForcedRepair of Rules.
 */
	 boolean IsRepairForced() {return _ForceRepair;}

/**
 * Sets flag for ForcedRepair of Rules.
 */
	 void SetForceRepair() { _ForceRepair = TRUE;}

/**
 * Builds list of available list of Rules for particular repository.
 * @param ifromRepository
 *			The repository to use for building Rules List.
 * <br><b>Legal values:</b><br>
 * <tt>""</tt> default configuration (file)<br>
 * <tt>"LCA"</tt> LCA  configuration <br>
 * @param iCustoList
 *			The cusotmized list of Rules.
 *
 */
	 void BuildListOfErrors(CATUnicodeString ifromRepository=NULL,
                                CATListOfCATUnicodeString* iCustoList=NULL);
/**
 * Returns the Customized List of Rules.
 * @return 
 *			The Customized List of Rules.
 */
	 CATListOfCATUnicodeString BuildListFromCustomization();

/**
 * Sets the Severities for Rules to check/clean.
 * @param iListSev
 *			The list of severities.
 */
	 void SetAuthorizedSeverities(CATListOfInt iListSev);

/**
 * Sets the Creation Date and Version for reports.
 * @param iCreationDate
 *			The creation date.
 */
	 void SetCreationDateAndVersion(CATUnicodeString iCreationDate) {_CreationDate = iCreationDate;}

/**
 * Returns the count of available rules. 
 * <br><b>Role:</b> Returns the count of available rules.
 * @param  iAmongFixableOnly
 *		Flag indicating the type of rules.
 * <br><b>Legal values:</b><br>
 * <tt>0</tt> Fixable rules only.<br>
 * <tt>1</tt> All rules.<br>
 */
	 int GetErrors(boolean iAmongFixableOnly=0);
   
/**
 * Sets Active Rule list.
 * <br><b>Role:</b> Sets the actual errors list computed considering the<br>
 * user's choice of Error Selection mode and the selected items in the multilist.
 * @param iList
 *			List of Rules.
 */
   void SetActiveErrorsList(CATListOfCATUnicodeString iList); //for setting the actual errors list computed considering the user's choice of Error Selection mode and the selected items in the multilist


/**
 * Returns the severites for Rules.
 * @return 
 *			List of severities.
 */
   int * GetSeveritiesTab() { return _Sever;}

/**
 * Returns the error repository (File, ENOVIA5)
 * @return
 *		The error reporitory is<UL>
 * <LI> ENOVIA5: CheckRepresentation environment (for every VPLM environment, .i.e MatrixOne, TST, TST provider, ...)
 * <LI> File:FBDI environment
 * </UL>
 */
	 CATUnicodeString GetErrorRepository () 
	                                     { return _plmRepository ; }  

/**
 * Initializes the ErrorDetected flag when no errors are initialized by the Init().
 */
	 void SetInitError() 
                          { _InitErrorDetected = TRUE;}
/**
 * Returns the absolute error link URL.
 * @param 
 *			The absolute error link URL
 * @return 
 *			The absolute error link URL
 */
	 CATUnicodeString GetAbsoluteErrorLink(CATUnicodeString iLink);

/**
 * Writes global statistics.
 * @param iWhere
 *			Location to write to File ( at end/start).
 */
	 HRESULT WriteGlobalStatistics( int iWhere);

/**
 * Sets the documentation path.
 * @param iDocPath00
 *			The document path for CATDUA_DOC0.
 * @param  iDocPath05
  *			The document path for CATDUA_DOC5.
 */
	 void SetDocPath(CATUnicodeString iDocPath00,CATUnicodeString iDocPath05);
/**
 * Returns the Global Status.
 * @return 
 *			The global status.
 */
	 CATUnicodeString GetGlobalStat();

/**
 * Puts the current iteration during Check/Clean operation.
 * @param iIterationForCheckClean
 *			Current iteration.
 */
	 void PutCheckCleanIteration(const int& iIterationForCheckClean);

/**
 * Sets the Document to process.
 * @param iDoc
 *			The pointer to document.
 */
	void SetCATDoc(CATDocument* iDoc);
/**
 * Sets the DUA Mode.
 * @param iMode
 *			The Clean/Check mode.
 */
	void SetDUAMode(short iMode);

/**
 * Returns the report (text/htm).
 * @param iformat<ul>
 * <li>=1: htm format (default)
 * <li>=0: txt format </ul>
 * @param iflush<ul>
 * <li>=1: remove the report from main object after the call (default)
 * <li>=0: keep the report attached to the main object </ul>
 * @return 
 *			The report.
 */

  CATListOfCATUnicodeString GetReportandFlush(int iformat , int iflush);

/**
 * Defines the report format (text/htm).
 * @param iformat<ul>
 * <li>=0        : htm + txt both format 
 * <li>=2<sup>0</sup> (1): txt format (default) 
 * <li>=2<sup>1</sup> (2): htm format 
 * <li>then you can combine values:
 * <li>=2<sup>1</sup>+2<sup>0</sup> (3): txt and htm formats</ul>

 * @return 
 *  none
 */
      void SetChkRepReportFormat(int iformat);
 /**
 * Method is used to check if the processed object is modified in check mode.
 * @param oErrorCodes <ul>
 * The list of error codes that modified the object in check mode.
 * <li> Empty List : Object not modified in check mode or check oper carried out on already modified object. 
 * <li> Non empty List : list of error codes that modified the object. 
 * @return 
 * <li> = 0        : Object not modified in check mode. 
 * <li> = 1        : Object modified in check mode.
 * <li> = 2        : check operation carried out on already modifed object.
 */    
int IsObjModifiedInCheckMode(CATListOfCATUnicodeString & oErrorCodes);


/**
 * Sets the stream quality.
 * @param iStreamQuality
 *			Stream quality value.
 */
	void SetSreamQuality(CATUnicodeString&);

	/**
 * Returns the Clean ErrorMessage list.
 * @param iflush<ul>
 * <li>=1: remove the report from main object after the call (default)
 * <li>=0: keep the report attached to the main object </ul>
 * @return 
 *			The report.
 */

  CATListOfCATUnicodeString GetAllCleanMessage(int iflush);

protected:
/**
 * Format setting the Global statistics box.
 * @param iPStr
 *			Rule Priority related data.
 * @param iFStr
 *			Fixable Rule Priority related data.
 * @return 
 *			Formatted statistics.
 */
	CATUnicodeString FormatGlobalStatBox(CATUnicodeString& iPStr, CATUnicodeString& iFStr);
/**
 * Writes the base (fixed) format for the Global statistics box.
 * @param NLSText_list
 *		Keeps all the resource strings.
 * @param iMode
 *			The Clean/Check mode.
 */
	void WriteBaseFormat(CATListOfCATUnicodeString& NLSText_list, int ifromClean,CATUnicodeString& BackGrndColor);
/**
 * Writes the error statistics in the Global statistics box.
 * @param iMode
 *			The Clean/Check mode.
 */
	void WriteErrorStat(CATUnicodeString& , CATUnicodeString& , CATListOfCATUnicodeString& , int );
/**
 * Sets the DUA Mode.
 * @param iMode
 *			The Clean/Check mode.
 */
	void DrawBox(CATListOfCATUnicodeString& , CATUnicodeString&, CATUnicodeString& ,  CATUnicodeString& );

  protected:
/**
 * The list of Pointer to Objects to process.
 */
   CATListPtrCATBaseUnknown* _ObjectList;
/**
 * The list of Pointer to available Rule Objects.
 */
   CATListPtrCATCheckRule* _RuleList;
/**
 * The list of plain checker messages.
 */
   CATListOfCATUnicodeString* _CleanMessageList;
/**
 * The name of Report.
 */
   char * _ReportName;
/**
 * The index of current Rule under processing. 
 */
   int _ProcessRule;
/**
 * The index to start with while launching Clean operation.
 */
   int _IdxToStart;
/**
 * List of counters for number of Links on embedded features.
 */
   CATListOfInt* _IndexCounter;
/**
 * The pointer to Link Manager of document under process.
 */
   CATBaseUnknown_var _LinkMan;
/**
 * The list of supported severites.
 */
   int * _Sever;
/**
 * The count of corrected Rules.
 */
   int _CorrectedErrors; /** @win64 fbq : 64-bit structure padding **/
/**
 * The flag to indicate whether to display Short/Long message.
 */
   int _DisplayMess;
/**
 * The list of Rule codes.
 */
   CATHDICO(CATUnicodeString)* _ListOfCodes;
/**
 * The pointer to current document under process.
 */
   CATBaseUnknown* _Document;
/**
 * The list of Authorized severites.
 */
   CATListOfInt* _AuthorizedSeverities;
/**
 * The report creation date.
 */
   CATUnicodeString _CreationDate;
/**
 * The Cleaner mode when CATDUA_DOMAIN is exported for Geom/Spec. E_DEPRECATED
 */
   short e_deprecated_01; // E_DEPRECATED - DLC_TOREMOVE
/**
 * The variable indicates the internal (DS) or external (Customer) usage.
 */
   short _ExternalUse;

/**
 * Flag to indicate ForceRepair of document.
 */
   boolean _ForceRepair;
/**
 * Flag to html mode.
 */
   boolean e_deprecated_02; // E_DEPRECATED - DLC_TOREMOVE

/**
 * Flag to put a right message in client environment when Init is impossible.
 */
   boolean _InitErrorDetected;

  public:

/**
 * Flag to indicate Base Objects' Clean() method are called.
 */
   boolean _BaseCleanCall;
/**
 * Flag to indicate CATCheckDocument() methods are called.
 */
   boolean _BaseDocumentCall; 
/**
 * Flag to indicate CATCheckContainer() methods are called.
 */
   boolean _BaseContainerCall;
/**
 * Flag to indicate CATCheckFeature() methods are called.
 */
   boolean _BaseFeatureCall;
/**
 * Flag to indicate problem of method call.
 */
   boolean _BaseProblemCall;
/**
 * Flag to re-count links before correction.
 */
   boolean _LinksShouldBeCounted;
   // Add due to move from SpecsModeler to ObjectModeler. Operation moved in CATCheckDocument::Clean
   // FALSE : nothing to do
   // TRUE : re-compute counters before correction
/**
 * Flag to re-compute counters before correction.
 */
   boolean _CheckLinks;

   /**
 * Iteration Count for Check/Clean.
 * <br><b>Role:</b> Its keeps the iteration count to identify whether Check or Clean is running.
 */
   int _IterationForCheckClean;

 /**
 *	Htm Report.
 * <br><b>Role:</b> Its keeps the htm report.
 */
     CATListOfCATUnicodeString _HtmReport ;     
	 CATListOfCATUnicodeString _CleanErrorList ;
 /**
 *	Htm Report requested.
 * <br><b>Role:</b> =1 if an htm report is requested.
 */
     int _iHtmReport ;     
 /**
 *	Txt Report requested.
 * <br><b>Role:</b> =1 if an txt report is requested.
 */
     int _iTxtReport ;     
 /**
 *	Txt Report.
 * <br><b>Role:</b> Its keeps the htm report.
 */

     CATListOfCATUnicodeString _TxtReport ;     
/**
 * Flag to indicate when the txt report is requested (non PLMBatch application versus htm report).
 */

     int _iCreateTxtReport ;

/**
* Variable to indicate stream quality.
*/
		 CATUnicodeString _StreamQuality;

	 private:
     CATListOfCATUnicodeString _DocModifRuleCodes;
     CATUnicodeString _plmRepository ;
     
     
};
   

#endif

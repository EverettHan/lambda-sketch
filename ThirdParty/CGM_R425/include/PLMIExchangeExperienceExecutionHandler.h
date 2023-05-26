//===================================================================
// COPYRIGHT Dassault Systemes 2013/11/22
//===================================================================
// PLMIExchangeExperienceExecutionHandler.cpp
// Header definition of class PLMIExchangeExperienceExecutionHandler
//===================================================================
//
// Usage notes: Interface use to create progress listener to 
// display a visual progression (progress bar).
//
//===================================================================
//  2013/11/22 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef PLMIExchangeExperienceExecutionHandler_H
#define PLMIExchangeExperienceExecutionHandler_H

#include "PLMExchangeInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"

class CATPLMManagementListener;
class CATUnicodeString;
class CATString;
class CATOmbLifeCycleRootsBag;
extern ExportedByPLMExchangeInterfaces  IID IID_PLMIExchangeExperienceExecutionHandler ;


class ExportedByPLMExchangeInterfaces PLMIExchangeExperienceExecutionHandler: public CATBaseUnknown
{
CATDeclareInterface;

public:

   /**
   * <b> CreateProgressListener </b> : Create a progress listener to allow the tracking of the execution progress.
   * Multiple listener can be created. Visually, this will result in the creation of multiple progress bar.
   * In other word, one listener = one progress bar.
   * With the created listener, the caller will be able to specify different execution steps, their progress and any encoutered errors.
   * Please release the pointer after use.
   *
   * @param opProgressListener [out, CATBaseUnknown#Release] 
   * output CATPLMManagementListener corresponding the progress listener.
   *
   * @param ipStrIcon [in] 
   * input pointer on a string corresponding to the icon to affect to each created progress listener.
   * By default, it will use the icon set through the customization #DefineExperience. (PLMIExchangeExperienceDesignInfo of added execution).
   *
   * @param ipStrCatalogName [in] 
   * input pointer on a string corresponding to the catalog to affect to each created progress listener.
   * This will be used by the progress listener to display info such as the title.
   * The catalog should have the following information tag :
   * - ProgressTaskUI.Title 
   * - ProgressTaskUI.ObjectName
   * By default, it will use the catalog name set through the customization #DefineExperience. (PLMIExchangeExperienceDesignInfo of added execution).
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT CreateProgressListener(CATPLMManagementListener * & opProgressListener, CATString * ipStrIcon = NULL, CATString * ipStrCatalogName = NULL) = 0;

   /**
   * <b> SetPostProcess </b> : Set the execution post process id. The post process id depends on the type of triggered execution.
   * Please refer to the executed operation for further information and supported post process.
   *
   * @param iExecutionPostProcessId [in] 
   * input mask of int corresponding to the ids of the post process to launch after the end of the on going execution.
   * i.e : if iExecutionPostProcessId = (ExecutionPostProcessId_ReportViewer | ExecutionPostProcessId_CloseExperience) then 
   *      the report viewer will be launched followed by the experience closing.
   * (id must be built from enum type PLMExchangeExperienceExecutionPostProcessId defined in PLMExchangeExperienceDictionary.h)
   */ 
   virtual void SetPostProcess(int iExecutionPostProcessId) =0;

   /**
   * <b> GetPostProcess </b> : Get the execution post process id. The post process id depends on the type of triggered execution.
   * Please refer to the executed operation for further information and supported post process.
   *
   * @return int corresponding to the id of the post process to launch after the end of the on going execution.
   *         -1; if no post process Id has been set.
   *          (id returned is of enum type PLMExchangeExperienceExecutionPostProcessId defined in PLMExchangeExperienceDictionary.h)
   */ 
   virtual int GetPostProcess()=0;

   /**
   * <b> SetExecutionReportPath </b> : (only for post process ReportViewer) The report execution which will be used by the post process ExecutionPostProcessId_ReportViewer.
   * The report viewer will provide an access to the given file path.
   *
   * @param iStrReportFullPath [in] 
   * input string corresponding to the execution report file path.
   */ 
   virtual void SetExecutionReportPath(CATUnicodeString & iStrReportFullPath) =0;

  /**
   * <b> GetExecutionReportPath </b> : Get the execution report path set.
   * If none was set then an empty string is returned.
   *
   * @return the execution report path.
   */ 
   virtual CATUnicodeString GetExecutionReportPath()=0;


   /**
   * <b> SetExecutionStatus </b> : Set the execution result.
   * Please refer to PLMExchangeExperienceDictionary.h for available execution result id.
   *
   * @param iExecutionResultId [in] 
   * input int corresponding to the id of the execution result.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT SetExecutionStatus(int iExecutionResultId)=0;

   /**
   * <b> GetExecutionParameter :</b> (Integrated customization) Get the execution parameters from the "common" exchange operation custo.
   * Depending on the operation, different parameters can be accessed. Defined in the different operaton design info header.
   * (i.e PLMExportExperienceDesign.h # Integration # Parameter)
   *
   * @param iParameterId (in)
   * input int corresponding to the parameter to retrieve.
   *
   * @param oStrParameterValue (out)
   * output CATUnicodeString corresponding to the value of the given parameter id.
   *
   * @return
   *    Legal values:  S_OK ,
   *                   E_FAIL  
   */
   virtual HRESULT GetExecutionParameter(int iParameterId, CATUnicodeString & oStrParameterValue) = 0;


   /**
   * <b> SetExecutionParameter :</b> (Integrated customization) Set the execution parameters to share with integrated customization.
   * Depending on the operation, different parameters need to be set. Defined in the different operaton design info header.
   * (i.e PLMExportExperienceDesign.h # Integration # Parameter)
   *
   * @param iParameterId (in)
   * input int corresponding to the parameter to retrieve.
   *
   * @param iStrParameterValue (in)
   * input CATUnicodeString corresponding to the value of the given parameter id.
   *
   * @return
   *    Legal values:  S_OK ,
   *                   E_FAIL  
   */
   virtual HRESULT SetExecutionParameter(int iParameterId, CATUnicodeString & iStrParameterValue) = 0;

   /**
   * <b> GetExecutionParameter :</b> (Integrated customization) Get the execution parameters from the "common" exchange operation custo.
   * Depending on the operation, different parameters can be accessed. Defined in the different operaton design info header.
   * (i.e PLMExportExperienceDesign.h # Integration # Parameter)
   *
   * @param iParameterId (in)
   * input int corresponding to the parameter to retrieve.
   *
   * @param oParameterValue (out)
   * output int corresponding to the value of the given parameter id.
   *
   * @return
   *    Legal values:  S_OK ,
   *                   E_FAIL  
   */
   virtual HRESULT GetExecutionParameter(int iParameterId, int & oParameterValue) = 0;


   /**
   * <b> SetExecutionParameter :</b> (Integrated customization) Set the execution parameters to share with integrated customization.
   * Depending on the operation, different parameters need to be set. Defined in the different operaton design info header.
   * (i.e PLMExportExperienceDesign.h # Integration # Parameter)
   *
   * @param iParameterId (in)
   * input int corresponding to the parameter to retrieve.
   *
   * @param iParameterValue (in)
   * input int corresponding to the value of the given parameter id.
   *
   * @return
   *    Legal values:  S_OK ,
   *                   E_FAIL  
   */
   virtual HRESULT SetExecutionParameter(int iParameterId, int & iParameterValue) = 0;

   /**
   * <dl>
   * <dt><b> SetPreviewInfo</b>
   * <pre>
   * Set the List of Objects, attribute list and attribute alias list to display in the preview panel.
   *
   * @param iAttrIdList [in]
   * List of attributes to be set in the header of the preview panel
   *
   * @param iAttrAliasList [in]
   * List of attributes alias
   *
   * @param iAttrValueList [in]
   * List of attributes values
   *
   * @param iListOfIconName [in]
   * List of attributes icons
   *
   * @param iNumberOfObjects [in]
   * Number of objects
   *
   *           
   * </pre>
   * </dl>
   */

   virtual void SetPreviewInfo( CATListValCATString & iAttrIdList, CATListValCATUnicodeString & iAttrAliasList 
                                 , CATListValCATUnicodeString & iAttrValueList, CATListValCATUnicodeString & iListOfIconName
                                 , int & iNumberOfObjects) = 0;

   /**
   * <dl>
   * <dt><b> GetPreviewInfo</b>
   * <pre>
   * Get the List of Objects, attribute list and attribute alias list to display in the preview panel.
   *
   * @param oAttrIdList [out]
   * List of attributes to be set in the header of the preview panel
   *
   * @param oAttrAliasList [out]
   * List of attributes alias
   *
   * @param oAttrValueList [out]
   * List of attributes values
   *
   * @param oListOfIconName [out]
   * List of attributes icons
   *
   * @param oNumberOfObjects [out]
   * Number of objects
   *
   *           
   * </pre>
   * </dl>
   */

   virtual void GetPreviewInfo( CATListValCATString & oAttrIdList, CATListValCATUnicodeString & oAttrAliasList 
                         , CATListValCATUnicodeString & oAttrValueList, CATListValCATUnicodeString & oListOfIconName
                         , int & oNumberOfObjects) = 0;

   /**
   * <b> SetPreviewPLMIDs :</b> Use for export to set the plmdIds of the object to display in the preview panel.
   *
   * @param iListOfPLMIDs (in)
   * input list of PLMIDs to exchange.
   *
   */
   virtual void SetPreviewPLMIDs(CATPLMIDs & iListOfPLMIDs) = 0;

   /**
   * <b> AddPreviewPLMIDsInfo :</b> Add additional information to the preview.
   * Specify for the given list of PLMId, the associated custom nls status.
   * This method is used to organize into smaller set, the list given to the method SetPreviewPLMIDs.
   * i.e . In the list given to SetPreviewPLMIDs, there's a subset of object having the nls status  A.
   *       Then we can use this method AddPreviewPLMIDsInfo, to specify this additional information by 
   *       giving the list of subset PLMID, and the nls status of A.
   *
   * @param iListOfPLMIDs (in)
   * input list of PLMIDs to exchange having another status (i.e to be delagated).
   *
   * @param iStrStatusNls (in)
   * input status nls string corresponding to the status of the given input list of PLMIDs.
   *
   * @param ipStrCompletionNls (in)
   * input pointer on the completion string to add right next to the given status.
   * Be default, it's null therefore, no additional completion string will be added to the object's status.
   */
   virtual void AddPreviewPLMIDsInfo(CATPLMIDs & iListOfPLMIDs, const CATUnicodeString & iStrStatusNls , CATUnicodeString * ipStrCompletionNls = NULL) = 0;
      

   /**
   * <b> GetPreviewPLMIDs :</b> Use for export to get the plmdIds of the object to display in the preview panel.
   *
   * @param oListOfPLMIDs (out)
   * output list of PLMIDs.
   */
   virtual void GetPreviewPLMIDs(CATPLMIDs & oListOfPLMIDs) = 0 ;

   /**
   * <b> GetPreviewPLMIDsInfo :</b> Get the list of PLMIDs and associated status nls defined for the given position.
   *
   * @param iPos (in)
   * input position to retrieve the info from.
   *
   * @param oListOfPLMIDs (out)
   * output list of PLMIDs.
   *
   * @param oStrStatusNls (out)
   * output status nls.
   *
   * @param oStrCompletionNls (out)
   * output completion nls.
   *
   * @return
   *    Legal values:  S_OK ,
   *                   E_FAIL  
   */
   virtual HRESULT GetPreviewPLMIDsInfo(int iPos, CATPLMIDs & oListOfPLMIDs ,  CATUnicodeString & oStrStatusNls ,CATUnicodeString & oStrCompletionNls) = 0 ;

   /**
   * <b> GetNbOfPreviewPLMIDsInfo :</b> Return nb of set preview information.
   */
   virtual int GetNbOfPreviewPLMIDsInfo() = 0 ;

   /**
   * <b> GetBagForOpenFromSession :</b> Return a bag where to keep roots to be considered for the post process ExecutionPostProcessId_OpenExploreData==DisplayData_OpenFromSession.
   */
   virtual CATOmbLifeCycleRootsBag &GetBagForOpenFromSession() = 0 ;
};

//-----------------------------------------------------------------------

#endif

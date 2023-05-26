/**
 * @level Private
 * @usage U1
 */
#ifndef CATOmbPLMImportContextType_h
#define CATOmbPLMImportContextType_h

 /**
 * Defines the PLM import action currently in progress.
 * <b> Role:</b>
 * It Indicates whether a PLM  import process is currently running
 * in the current session.
 *@param
 * 	CATPLMNoImportAction  : No PLM import process currently running
 *@param
 * 	CATPLM_FBDI_Load : PLM FBDI LOAD running
 *@param
 * 	CATPLM_FBDI_Migrate : PLM FBDI MIGRATE running
 *@param
 * 	CATPLM_DBDI_Load : PLM DBDI LOAD running
 *@param
 * 	CATPLM_DBDI_Migrate : PLM DBDI MIGRATE running
  *@param
 * 	CATPLM_POWERBY_ConvertLoad : PLM PowerBy V5->V6 PostConversion load running
 */

enum CATPLMImportContext
{
  CATPLMNoImportAction = 0,
  CATPLM_FBDI_Load = 1,
  CATPLM_FBDI_Migrate = 2,
  CATPLM_DBDI_Load = 4,
  CATPLM_DBDI_Migrate = 5,
  CATPLM_IMPORTER = 6,
  CATPLM_POWERBY_ConvertLoad = 7
};

#endif

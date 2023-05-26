/**
 * @level Protected
 * @usage U1
 */

// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CATLieSettingsDeclarations
//
//=============================================================================
// Usage Notes: definition des variables necessaires au settings de TPSBrowser
//
//=============================================================================
// Nov. 2003  Creation                                                  SOB
//=============================================================================

// *************************
// **** KNOWLEDGE SHEET ****
// *************************
//=============================================================================
// nom du repository
#define CATLieKnowledgeRepository                          "Knowledge"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define PARAMETERS_VIEW_WITH_VALUE_DEFAULT_VALUE           0
// nom du setting correspondant
#define PARAMETERS_VIEW_WITH_VALUE                         "ParametersViewWithValue"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Value
#define PARAMETERS_VIEW_WITH_FORMULA_DEFAULT_VALUE         0
// nom du setting correspondant
#define PARAMETERS_VIEW_WITH_FORMULA                       "ParametersViewWithFormula"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View Surrounded
#define PARAMETERS_SURROUNDED_BY_SYMBOL_DEFAULT_VALUE      0
// nom du setting correspondant
#define PARAMETERS_SURROUNDED_BY_SYMBOL                    "EncadrementPathnames"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en Synchronous at creation
#define RELATIONS_SYNCHRONOUS_AT_CREATION_DEFAULT_VALUE    1
// nom du setting correspondant
#define RELATIONS_SYNCHRONOUS_AT_CREATION                  "RelationSynchronousAtCreation"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en Synchronous at creation
#define RELATIONS_INTEGRATED_TO_UPDATE_DEFAULT_VALUE       0
// nom du setting correspondant
#define RELATIONS_INTEGRATED_TO_UPDATE                     "RelationIntegratedToUpdate"
//-----------------------------------------------------------------------------
// valeur par defaut de la Synchronisation des Design Tables
#define DESIGN_TABLES_SYNCHRONIZATION_MODE_DEFAULT_VALUE   0
// nom du setting correspondant
#define DESIGN_TABLES_SYNCHRONIZATION_MODE				   "DesignTableSynchroMode"
//-----------------------------------------------------------------------------
// valeur par defaut du Copy mode des Design tables
#define DESIGN_TABLES_COPY_MODE_DEFAULT_VALUE			   0
// nom du setting correspondant
#define DESIGN_TABLES_COPY_MODE							   "DesignTableDefaultCopyMode"
//-----------------------------------------------------------------------------
// valeur par defaut du Copy mode des Design tables
#define PREVIOUS_INCREMENTAL_DEFAULT_VALUE				   0
// nom du setting correspondant
#define PREVIOUS_INCREMENTAL							   "PreviousIncremental"



// *************************
// **** LANGUAGE SHEET  ****
// *************************
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define LOAD_EXTENDED_LANGUAGE_LIB_DEFAULT_VALUE           0
// nom du setting correspondant
#define LOAD_EXTENDED_LANGUAGE_LIB                         "ExtendedLanguage"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Value
#define LOAD_ALL_PACKAGES_DEFAULT_VALUE					   1
// nom du setting correspondant
#define LOAD_ALL_PACKAGES								   "AllPackages"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View Surrounded
#define LIST_OF_PACKAGES_TO_LOAD_DEFAULT_VALUE			   ""
// nom du setting correspondant
#define LIST_OF_PACKAGES_TO_LOAD	                       "LoadPackage"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en Synchronous at creation
#define REFERENCE_DIRECTORY_FOR_TYPES_DEFAULT_VALUE        ""
// nom du setting correspondant
#define REFERENCE_DIRECTORY_FOR_TYPES                      "OutputDirectoryForTypes"
//-----------------------------------------------------------------------------


// **********************************
// **** REPORT GENERATION SHEET  ****
// **********************************
//=============================================================================
// nom du repository
#define CATLieReportGenerationRepository                     "Report"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define CHECK_REPORT_HTML_DEFAULT_VALUE						1
// nom du setting correspondant
#define CHECK_REPORT_HTML			                         "ReportHtml"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define ALL_CHECK_REPORT_DEFAULT_VALUE						1
// nom du setting correspondant
#define ALL_CHECK_REPORT			                         "AllCheck"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define REPORT_CHECK_ADVISOR_DEFAULT_VALUE					1
// nom du setting correspondant
#define REPORT_CHECK_ADVISOR			                    "CheckAdvSelect"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define REPORT_PARAMETERS_INFORMATION_DEFAULT_VALUE			1
// nom du setting correspondant
#define REPORT_PARAMETERS_INFORMATION                       "ParametersValue"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define REPORT_CHECK_EXPERT_DEFAULT_VALUE					1
// nom du setting correspondant
#define REPORT_CHECK_EXPERT			                        "CheckExpSelect"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define REPORT_PASSED_OBJECTS_DEFAULT_VALUE					1
// nom du setting correspondant
#define REPORT_PASSED_OBJECTS			                    "PassedExp"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define REPORT_OBJECTS_INFORMATION_DEFAULT_VALUE			1
// nom du setting correspondant
#define REPORT_OBJECTS_INFORMATION				            "ObjAttr"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define REPORT_HTML_IN_CATIA_SESSION_DEFAULT_VALUE			1
// nom du setting correspondant
#define REPORT_HTML_IN_CATIA_SESSION                        "HTMLIntoCATIA"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define DIRECTORY_FOR_INPUT_XSL_DEFAULT_VALUE				""
// nom du setting correspondant
#define DIRECTORY_FOR_INPUT_XSL								"InputXSL"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define REPORT_OUTPUT_DIRECTORY_DEFAULT_VALUE				""
// nom du setting correspondant
#define REPORT_OUTPUT_DIRECTORY								"OutputDirectory"
//-----------------------------------------------------------------------------


// *************************
// **** UNIT SHEET ****
// *************************
//=============================================================================
// nom du repository DISPLAY
#define CATLieUnitDisplayRepository                        "NumberDisplay"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define MAGNITUDE_DISPLAY_DEFAULT_VALUE						3
// nom du setting correspondant
#define MAGNITUDE_DISPLAY			                       "Display"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define MAGNITUDE_CALC_DISPLAY_DEFAULT_VALUE				3
// nom du setting correspondant
#define MAGNITUDE_CALC_DISPLAY			                   "CalcDisplay"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define UNITS_SAME_DISPLAY_DEFAULT_VALUE					1
// nom du setting correspondant
#define UNITS_SAME_DISPLAY									"SameDisplay"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define UNITS_TRAILING_ZEROS_DEFAULT_VALUE					0
// nom du setting correspondant
#define UNITS_TRAILING_ZEROS								"TrailingZeros"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define UNITS_EXPONENTIAL_HIGH_DEFAULT_VALUE				6
// nom du setting correspondant
#define UNITS_EXPONENTIAL_HIGH								"ExponentialHigh"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define UNITS_EXPONENTIAL_LOW_DEFAULT_VALUE					6
// nom du setting correspondant
#define UNITS_EXPONENTIAL_LOW								"ExponentialLow"
//-----------------------------------------------------------------------------


//=============================================================================
// nom du repository CKE
#define CATLieUnitCkeRepository                            "cke"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define UNITS_MAGNITUDE_UNITS_DEFAULT_VALUE					1
//-----------------------------------------------------------------------------



// *************************
// **** TOLERANCE SHEET ****
// *************************
//=============================================================================
// nom du repository DISPLAY
#define CATLieToleranceRepository                        "CkeTolerance"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Formula
#define DEFAULT_TOLERANCE_DEFAULT_VALUE            0
// nom du setting correspondant
#define DEFAULT_TOLERANCE		                          "defaultTolerance"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Value
#define LENGTH_MAX_TOLERANCE_DEFAULT_VALUE         0.0
// nom du setting correspondant
#define LENGTH_MAX_TOLERANCE		                       "maxLengthTolerance"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Value
#define LENGTH_MIN_TOLERANCE_DEFAULT_VALUE         0.0
// nom du setting correspondant
#define LENGTH_MIN_TOLERANCE		                       "minLengthTolerance"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Value
#define ANGLE_MAX_TOLERANCE_DEFAULT_VALUE         0.0
// nom du setting correspondant
#define ANGLE_MAX_TOLERANCE				                    "maxAngleTolerance"
//-----------------------------------------------------------------------------
// valeur par defaut du passage en View With Value
#define ANGLE_MIN_TOLERANCE_DEFAULT_VALUE         0.0
// nom du setting correspondant
#define ANGLE_MIN_TOLERANCE			                       "minAngleTolerance"

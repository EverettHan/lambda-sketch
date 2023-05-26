#ifndef _CATCkeDisplayParameter_H
#define _CATCkeDisplayParameter_H

#include "CATLifDictionary.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATICkeUnit.h"

/**
 * This structure allows to control the behavior of CATCkeDisplayParameter API.
 */
struct ExportedByCATLifDictionary CATCkeDisplayParameterConfiguration
{
  /**Configuration of "Date" parameter display*/
  struct DateConfiguration
  {
    enum RepresentationType
    {
      Number,     //dates will be shown  as time_t
      ShortDate,  //use setting value, default being %x (date without hour/min/sec fields, see strftime)
      LongDate    //use setting value, default being %c (full date, see strftime)
    } Representation;
    CATUnicodeString Format; //if set dates will be displayed using this specific format overriding Representation member (see CATTime::ConvertToString, strftime)
  } Date;

  /**Configuration of "Enumere" parameter display (Boolean included)*/
  struct EnumConfiguration
  {
    unsigned int UseNls:1;//if true NLS value will be displayed
  } Enum;

  /**Configuration of "Real" parameter display (no influence on magnitude/integers)*/
  struct RealConfiguration
  {
    unsigned int Iso:1;   //if true "Iso" mode will be used (no clue of what it means, see implementation)
    int NumberOfDecimals; // number of decimals to display, -1 means default value which is REALS_DECIMALS_NB
  } Real;

  /**Configuration of "magnitude" parameter display*/
  struct DimensionConfiguration
  {
    unsigned int Iso:1;            //if true "Iso" mode will be used (no clue of what it means, see implementation)
    unsigned int ShowUnitSymbol:1; //if true, unit symbol will be displayed
    int NumberOfDecimals;          //number of decimals to display [0,REALS_DECIMALS_NB] , -1 means use seting defined value, warning 0 gives weird results
    CATICkeUnit_var DisplayUnit;   //Display unit to use, if NULL setting defined value will be used. Use with care, a display unit is valid for only one dimension
  } Dimension;

  /**Configuration of "Feature" parameter display*/
  struct ReferenceConfiguration
  {
    enum FormatType {Legacy}; //Legacy = crazy incoherent and stupid legacy implementation
    FormatType Format;
  } Reference;

  /**Configuration of "List"|"ListType" parameter display*/
  struct ListConfiguration
  {
    enum FormatType {Legacy}; //Legacy = crazy incoherent and stupid legacy implementation
    FormatType Format;
  } List;

  struct GlobalConfiguration
  {
    unsigned int UseCATIParmFormat:1; //if FALSE, CATIParmFormat will not be used
    unsigned int DisplayUnset:1; //If TRUE, unset parameters will have a specific display
    unsigned int ShowRealMode:1; //internal use
  } Global;


#define CKE_SHOW       0x0100
#define CKE_CONTENT    0x0200
#define CKE_ISO        0x0400
#define CKE_SHOW_REAL (0x0800|CKE_SHOW)
#define CKE_UI         0x1000
  /**
   * Initialize a CATCkeDisplayParameterConfiguration.
   * @param iMode.
   * Legal values:
   *  A combination (binary OR) of CKE_XXX flags defined herabove
   *    CKE_SHOW/CKE_CONTENT/CKE_SHOW_REAL are mandatory and exclusive
   *    CKE_ISO/CKE_UI are optional
   * Legacy values:
   *  CKE_SHOW:             will generate the exact same format as CATICkeParm::Show
   *  CKE_SHOW|CKE_ISO:     will generate the exact same format as CATICkeParm::ShowIso
   *  CKE_CONTENT:          will generate the exact same format as CATICkeParm::Content    ("almost" the same as Show without unit symbols)
   *  CKE_CONTENT|CKE_ISO:  will generate the exact same format as CATICkeParm::ContentIso
   */
  CATCkeDisplayParameterConfiguration(int iMode);

  ~CATCkeDisplayParameterConfiguration();
};

/**
 * Displays parameter value according to configuration.
 * Notice that depending on parameter's type all fields of iConfiguration may not be checked.
 * usage:
 * Let's say we want to display parameters with CATICkeParm::Show legacy behavior except for dates and enums:
 * <pre>
 * CATICkeParm_var hParm = ...;
 * CATCkeDisplayParameterConfiguration config(CKE_SHOW);
 * config.Date.Representation = CATCkeDisplayParameterConfiguration::DateConfiguration::LongDate; //Show long date
 * config.Enum.UseNls = TRUE; //show NLS values for enum's
 * CATUnicodeString result;
 * HRESULT hr = CATCkeDisplayParameter(hParm,config,result); //notice that it should not fail except in case of dummy arguments.
 * </pre>
 * @param iParameter
 *   The parameter to dump (Notice that passing a parameter value (CATICkeInst returned by CATICkeParm::Value) is also accepted).
 *   Any type of parameter can be passed (Real/Integer/String/Enum/Boolean/Dimension/*), notice that there is currently no "reasonable" implementation for Lists and references parameters.
 * @param iConfiguration
 *   Display configuration, @see CATCkeDisplayParameterConfiguration
 * @param oResult
 *   String representing parameter's value.
 *   This string must not be interpreted, stored, passed to CATICkeParm::Valuate nor used for odt dumps.
 *   It may depend on locale, user language, user settings, time zone.
 */
ExportedByCATLifDictionary HRESULT CATCkeDisplayParameter(const CATBaseUnknown* iParameter,const CATCkeDisplayParameterConfiguration& iConfiguration,CATUnicodeString& oResult);

#endif

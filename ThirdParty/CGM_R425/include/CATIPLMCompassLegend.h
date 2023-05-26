// COPYRIGHT Dassault Systemes 2004
#ifndef CATIPLMCompassLegend_H
#define CATIPLMCompassLegend_H

#include <UIModelInterfaces.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include "CATLISTP_CATBaseUnknown.h"
#include "CATTime.h"
#include "CATISYPIntrospectableProvider.h"

class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIPLMCompassLegend;
#else
extern "C" const IID IID_CATIPLMCompassLegend ;
#endif

  /**
   * Style type.
   * <br><b>Role:</b> It's the style of your legend. The style can be a composition 
   * of several style. Example : CATLegendCommand|CATLegendShading. Each class lists its allowed type.  
   */
typedef unsigned long CATLegendStyle;

#define CATLegendLabel           (1 << 2)
#define CATLegendShading         (1 << 3)
#define CATLegendCheck           (1 << 4)   // display this legend with a check button
#define CATLegendRadio           (1 << 5)   // display this legend with a radio button
#define CATLegendCount           (1 << 6)   // display this legend with its count
#define CATLegendBarChart        (1 << 7)   // allow bar chart for this legend
#define CATLegendEditor          (1 << 8)   // simple editor legend
#define CATLegendRange           (1 << 9)   // range editor legend
#define CATLegendCommand         (1 << 10)  // command legend
#define CATLegendRangeEdit       (1 << 11)  // ranges can be edited
#define CATLegendDelete          (1 << 12)  // 
#define CATLegendAddToCSO        (1 << 13)  // allow Add To CSO command for this legend
#define CATLegendAlwaysFirst     (1 << 14)  // legend will always be displayed in the first row whatever the sort is
#define CATLegendAlwaysLast      (1 << 15)  // legend will always be displayed in the last row whatever the sort is
#define CATLegendValidForTag     (1 << 16)  // legend can be used for cloud of tag (need that GetCount returns a valid int value)
#define CATLegendRangeNoOperator (1 << 17)  // Operators on range are not visible in the UI
#define CATLegendSliderDisplay   (1 << 18)  // display slider for editor (only if type int)
#define CATLegendHideButton      (1 << 19)  // hide the radio/check button

enum CATLegendType { LegendString=0, LegendInt=1, LegendDouble=3, LegendDate=4, LegendBoolean=5 };
enum CATLegendOperator { LegendEqualOp=0, LegendLessOp=1, LegendLessEqOp=2, LegendGreaterOp=3, LegendGreaterEqOp=4 };

/**
 * PLM compass legend entry. Please derive from CATAdapterPLMCompassLegend adapter
 */
class ExportedByUIModelInterfaces CATIPLMCompassLegend: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get item label
	 **/
	virtual HRESULT GetLabel( CATUnicodeString &oLabel ) = 0;
	/**
	 * Get item tooltip
   * the real tool tip displayed will contain the label and the tool tip given by this method
	 **/
	virtual HRESULT GetTooltip( CATUnicodeString &oTooltip ) = 0;

  /**
   * @return The introspectable provider in charge of returning the tooltip 
   * content's data block. 
   */
  virtual CATISYPIntrospectableProvider_var GetTooltipProvider() =0;

  /**
   * Get the facet containint the current property
   * 
   * @param opBUFacet [out, CATBaseUnknown#Release]
   *         the facet containing this property
   *
   * @Return
   *         S_OK: the facet is defined
   *         E_FAIL: otherwise
   */
  virtual HRESULT GetFacet(CATBaseUnknown *&opBUFacet)=0;

  /**
   * Get default item color
   */
  virtual HRESULT GetDefaultColor( unsigned char &oRed, unsigned char &oGreen, unsigned char &oBlue ) = 0;

  /**
   * Get item color
   */
  virtual HRESULT GetColor( unsigned char &oRed, unsigned char &oGreen, unsigned char &oBlue ) = 0;

  /**
   * Change item color
   */
  virtual HRESULT SetColor( unsigned char iRed, unsigned char iGreen, unsigned char iBlue ) = 0;

  /**
   * Get default item color
   */
  virtual HRESULT GetDefaultColor( unsigned char &oRed, unsigned char &oGreen, unsigned char &oBlue, unsigned char &oT ) = 0;

  /**
   * Get item color
   */
  virtual HRESULT GetColor( unsigned char &oRed, unsigned char &oGreen, unsigned char &oBlue, unsigned char &oT ) = 0;

  /**
   * Change item color
   */
  virtual HRESULT SetColor( unsigned char iRed, unsigned char iGreen, unsigned char iBlue, unsigned char iT ) = 0;

  /**
   * Item selected
   */
  virtual void OnSelect( void ) = 0;

  /**
*
* <br><b>Role</b>: Get check state of this legend
* @param oCheckState: the check state of the legend to return
* <br><code>TRUE</code> the legend requires to be checked, otherwise, the legend needs to be unchecked.
* @return
* <dl> 
* <dt><code>S_OK</code> <dd> All is OK.
* <dt><code>S_FALSE</code> <dd> to have a mixed state (only for check box style).
* <dt><code>E_FAIL</code> <dd> Something wrong
* </dl>
*/
virtual HRESULT GetCheckState(CATBoolean & oCheckState) = 0 ;

/**
*
* <br><b>Role</b>: Get complementary information of the legend.
* @param oStringValue : the string value, can be an information on the quantity with a unit. Indeed, no conversion will be done.
* 
* @param oFloatValue : the float value related. Between 0 and 1.
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd> All is OK.
* <dt><code>E_FAIL</code> <dd> Something wrong
* </dl>
*/
virtual HRESULT GetValue(CATUnicodeString & oStringValue, float & oFloatValue) = 0;
/**
 * <br><b>Role</b>: Get count information of the legend if available.
 * @param oCountValue : the int value, will be used to compute cloud of tag
 */
virtual HRESULT GetCount(int &oCountValue) = 0;

/**
*
* <br><b>Role</b>: When the user interacts with the checkbox
* @param iNewCheckState: the new check state obtained
* * <br><code>TRUE</code> the user has checked, otherwise, the user has unckecked.
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
virtual HRESULT OnUserCheck(const CATBoolean & iNewCheckState) = 0;

/**
 *
 * <br><b>Role</b>: When the user interacts with the tag
 * only for properties with style : CATLegendValidForTag
 * default implementation from adapter will call OnUserCheck(FALSE)
 * but can be overloaded by application (case of radio buttons for example)
 * @return
 * <dl>
 * <dt><code>S_OK</code> <dd>
 * <dt><code>E_FAIL</code> <dd>
 * </dl>
 */
virtual HRESULT OnTagUnset() = 0;

/**
*
* <br><b>Role</b>: When the user clicks on label
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
virtual HRESULT OnLabelPropertyClick()=0;

/**
*
* <br><b>Role</b>: When the user double clicks on label
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
virtual HRESULT OnLabelPropertyDoubleClick()=0;

/**
*
* <br><b>Role</b>: When the user clicks on shading icon
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
virtual HRESULT OnShadingPropertyClick()=0;

    /**
     * Retrieve list of sub-properties for this property
     * @param oListProperty the list of properties (objects implementing CATIPLMCompassLegend
     */
    virtual HRESULT GetRefinementSubProperties(CATListPtrCATBaseUnknown &oListProperty)=0;

    virtual HRESULT GetExpandStatus(CATBoolean &oExpandStatus)=0;
    virtual HRESULT SetExpandStatus(CATBoolean iExpandStatus)=0;

    /**
     *
     * <br><b>Role</b>: When the user interacts with the expander
     * @param iNewExpandStatus: the new expand status obtained
     * <br><code>TRUE</code> the user has expanded, otherwise, the user has collapsed.
     * @return
     * <dl>
     * <dt><code>S_OK</code> <dd>
     * <dt><code>E_FAIL</code> <dd>
     * </dl>
     */
    virtual HRESULT OnUserExpand(const CATBoolean & iNewExpandStatus) = 0;

    /**
     *
     * <br><b>Role</b>: When the user interacts with the editor
     * @param iusNewEdtValue: the new editor value
     * @return
     * <dl>
     * <dt><code>S_OK</code> <dd>
     * <dt><code>E_FAIL</code> <dd>
     * </dl>
     */
    virtual HRESULT OnEditorValidation(const CATUnicodeString &iusNewEdtValue)=0;
    virtual HRESULT GetEditorValue(CATUnicodeString &ousEdtValue)=0;

    // used for slider mode
    virtual HRESULT GetMinMaxAuthorizedEditorValue(int &oMinEdtValue, int &oMaxEdtValue)=0;
    virtual HRESULT OnEditorValidation(int iNewIntValue)=0;
    virtual HRESULT GetEditorValue(int &oIntEdtValue)=0;

  /**
   *
   * <br><b>Role</b>: Returns the style of the legend to display (Combination of styles)
   * @return
   * Style of the legend
   */
    virtual CATLegendStyle GetLegendStyle()=0;

    /**
     * Used for editor and range editor
     * enum CATLegendType { LegendString=0, LegendInt=1, LegendDouble=3, LegendDate=4, LegendBoolean=5 };
     * 
     */
    virtual CATLegendType GetLegendType()=0;

    /**
     * DEPRECATED
     */
    //virtual HRESULT GetRangeValues(CATUnicodeString &oMinRange, CATUnicodeString &oMaxRange)=0;
    /**
     * DEPRECATED
     */
    //virtual HRESULT OnRangeEditorValidation(const CATUnicodeString &iusNewMinEdtValue, const CATUnicodeString &iusNewMaxEdtValue)=0;

    /**
     * Get string range values
     * args could be NULL if not yet valuated
     * MinOperator can be equal to : LegendEqualOp, LegendGreaterOp, LegendGreaterEqOp
     * MaxOperator can be equal to : LegendLessOp, LegendLessEqOp
     */
    virtual HRESULT GetRangeStringValues(CATLegendOperator &oMinOperator, CATUnicodeString *&opMinVal, CATLegendOperator &oMaxOperator, CATUnicodeString *&opMaxVal) = 0;
    virtual HRESULT OnRangeStringValidation(CATLegendOperator iMinOperator, CATUnicodeString *ipusNewMinValue, CATLegendOperator iMaxOperator, CATUnicodeString *ipusNewMaxValue)=0;

    /**
     * Get range values with CATTime, only for legend with LegendType=LegendDate
     * method should return NULL pointer if not yet valuated
     * MinOperator can be equal to : LegendEqualOp, LegendGreaterOp, LegendGreaterEqOp
     * MaxOperator can be equal to : LegendLessOp, LegendLessEqOp
     */
    virtual HRESULT GetRangeTimeValues(CATLegendOperator &oMinOperator, CATTime *&opMinDate, CATLegendOperator &oMaxOperator, CATTime *&opMaxDate) = 0;
    virtual HRESULT OnRangeTimeValidation(CATLegendOperator iMinOperator, CATTime *ipNewMinDate, CATLegendOperator iMaxOperator, CATTime *ipNewMaxDate)=0;

    /**
     * Get double range values
     * args could be NULL if not yet valuated
     * MinOperator can be equal to : LegendEqualOp, LegendGreaterOp, LegendGreaterEqOp
     * MaxOperator can be equal to : LegendLessOp, LegendLessEqOp
     */
    virtual HRESULT GetRangeDoubleValues(CATLegendOperator &oMinOperator, double *&opMinVal, CATLegendOperator &oMaxOperator, double *&opMaxVal) = 0;
    virtual HRESULT OnRangeDoubleValidation(CATLegendOperator iMinOperator, double *ipusNewMinValue, CATLegendOperator iMaxOperator, double *ipusNewMaxValue)=0;

    /**
     * Get int range values
     * args could be NULL if not yet valuated
     * MinOperator can be equal to : LegendEqualOp, LegendGreaterOp, LegendGreaterEqOp
     * MaxOperator can be equal to : LegendLessOp, LegendLessEqOp
     */
    virtual HRESULT GetRangeIntValues(CATLegendOperator &oMinOperator, int *&opMinVal, CATLegendOperator &oMaxOperator, int *&opMaxVal) = 0;
    virtual HRESULT OnRangeIntValidation(CATLegendOperator iMinOperator, int *ipusNewMinValue, CATLegendOperator iMaxOperator, int *ipusNewMaxValue)=0;

    virtual HRESULT GetIcon(CATUnicodeString &oIconNamePath)=0;

    virtual HRESULT SendRefinementUpdateNotification(int iRefreshType)=0;
};

CATDeclareHandler( CATIPLMCompassLegend, CATBaseUnknown );

#endif


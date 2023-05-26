//===================================================================
// COPYRIGHT Microsoft 2011/11/16
//===================================================================
// CATIAfrSpiderChart.cpp
// Header definition of class CATIAfrChart
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/11/16 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIAfrChart_H
#define CATIAfrChart_H

#include "CATAfrItf.h"
#include "CATICAfrComponent.h"
//---------------------------------------------------------------------- System
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfDouble.h"
#define AFRCHART_MIGRATION_SETCATEGORY

extern ExportedByCATAfrItf  IID IID_CATIAfrChart ;

/**
* The interface that define a dataset for a chart with one or more series, and values associated with categories
*/
class ExportedByCATAfrItf CATIAfrChart: public CATICAfrComponent
{
CATDeclareInterface;

public:
/**
* the policy when value of a series is out of objective value
*/
  enum ExcessPolicy
  {
    Ignore       = 0, /*The exceeded value is ignored and set to the objective. This is the default policy.*/
    Mirror       = 1, /*The exceeded value is equal to the objective value less than the difference between exceeded and objective value.*/
    NotToExceed  = 2, /*The exceeded value must not be over the objective value else it is set to the worth value. */
  };



#ifdef AFRCHART_MIGRATION_SETCATEGORY
  /**
*
* <br><b>Role</b>: Adds or updates a category in the dataset. 
* If this is a new category, missing value will be created for each series group with as value the objective value of this category.
* @param iCategoryKey: the category key (empty key not permitted)
* @param iWorthValue: the value further away from the objective (Default is zero).
* @param iObjectiveValue: the value to reach the objective (Default is 100).
* @param iExcessPolicy: the policy when value of a series is out of objective value (Default is Ignore). 
* @param iUnit: the unit of the category (Default is %).
* @param iToooltip: the tooltip for this category
* @param iColor : the color of this category. It must respect the following syntax �r g b� or �r g b a�.
* @param iEnableFlag: if we can do some interaction on the categoy. You must register a controller on this chart to listen those events.
* @param iLabel: the label NLS of the category, if it is not defined it will takes the category key
* 
*/
virtual void SetCategory(const CATString & iCategoryKey, const double & iWorthValue=0, 
                 const double & iObjectiveValue= 100, const ExcessPolicy & iExcessPolicy= CATIAfrChart::Ignore, 
                 const CATUnicodeString & iUnit= "%", const CATUnicodeString & iToooltip="",
                 const CATBoolean & iEnableFlag = FALSE, const CATUnicodeString & iLabel= "")=0;
#else

/**
* @Deprecated
* <br><b>Role</b>: Adds or updates a category in the dataset. 
* If this is a new category, missing value will be created for each series group with as value the objective value of this category.
* @param iCategoryKey: the category key (empty key not permitted)
* @param iWorthValue: the value further away from the objective (Default is zero).
* @param iObjectiveValue: the value to reach the objective (Default is 100).
* @param iExcessPolicy: the policy when value of a series is out of objective value (Default is Ignore). 
* @param iUnit: the unit of the category (Default is %).
* @param iToooltip: the tooltip for this category
* @param iColor : the color of this category. It must respect the following syntax �r g b� or �r g b a�.
* @param iNavigateToChartPath: the path to navigate to another chart when activate a category. This path should respect 
*        the following syntax [XmlFile]/[TemplateNameOfChart]:[InstanceNameOfChart]. 
*        The Xml file is the declarative file where is defined the template of your component model. 
*        If you put ".", so the xml file is the current Xml File. 
*        The TemplateNameOfChart is the identifier of the template related to the target "CATAfrComponent".
* @param iLabel: the label NLS of the category, if it is not defined it will takes the category key
* 
*/
virtual void SetCategory(const CATString & iCategoryKey, const double & iWorthValue=0, 
                 const double & iObjectiveValue= 100, const ExcessPolicy & iExcessPolicy= CATIAfrChart::Ignore, 
                 const CATUnicodeString & iUnit= "%", const CATUnicodeString & iToooltip="",
                 const CATString & iNavigateToChartPath = "", const CATUnicodeString & iLabel = "")=0;

#endif
/**
*
* <br><b>Role</b>: Adds or updates a series group in the dataset.
* If this is a new series, all values given in parameter for each category will be created.
* @param iSeriesKey : the series key (empty key not permitted)
* @param iSeriesValuesPerCategorie : the array of values of this series for each category. 
* @param iColor : the color of this series group. It must respect the following syntax �r g b� or �r g b a�.
*  Make sure that the size of the list fits with the count of category otherwise an assertion will be araise
* 
* 
*/
virtual void SetSeriesGroup(const CATString & iSeriesKey, const CATListOfDouble & iSeriesValuesPerCategorie, const CATString & iColor ="255 255 255 255")=0;



/**
*
* <br><b>Role</b>: Adds or updates a series value in the dataset.
* @param iCategoryKey: the category key (empty key not permitted)
* @param iSeriesKey: the series key (empty key not permitted)
* @param iValue: the value
* @param iToooltip: the tooltip for this value. 
* If the tooltip is not defined, the tooltip will respect this form [SeriesName] � [CategoryName] :[Value] [CategoryUnit].
*/
virtual void SetSeriesValue(const CATString & iCategoryKey, const CATString & iSeriesKey, const double & iValue, 
                    const CATUnicodeString & iToooltip="")=0;


/**
*
* <br><b>Role</b>: Removes a category in the dataset.
* Note that all related values will be also removed.
* @param iCategoryKey: the category key (empty key not permitted)
*/
virtual void RemoveCategory(const CATString & iCategoryKey)=0;


/**
*
* <br><b>Role</b>: Removes a series group in the dataset. The series values will be also removed.
* @param iSeriesKey: the series key (empty key not permitted)
*/
virtual void RemoveSeriesGroup(const CATString & iSeriesKey)=0;





/**
* <br><b>Role</b>: Returns the value from a series related to a category
* @param iCategoryKey: the category key (empty key not permitted)
* @param iSeriesKey: the series key (empty key not permitted)
* @return the value
*/
virtual  double  GetValue(const CATString & iCategoryKey, const CATString & iSeriesKey) =0;

/**
* <br><b>Role</b>: Gets the worth and objective value from a category related to a category
* @param iCategoryKey: the category key (empty key not permitted)
* @param oWorthValue: the category key (empty key not permitted)
* @param oObjectiveValue: the series key (empty key not permitted)
* @return S_OK if the values have been correctly found, E_FAIL else
*/
virtual HRESULT GetRange(const CATString & iCategoryKey,  double & oWorthValue, double & oObjectiveValue) =0;
/**
* <br><b>Role</b>: Gets the count of category
* @return the count of category
* 
*/
virtual  int GetCategoryCount() =0;


/**
*
* <br><b>Role</b>: Gets the count of series
* @return the count of series
* 
*/
virtual  int  GetSeriesCount() = 0;


/**
*
* <br><b>Role</b>: Gets the category key from an index
* @param iCategoryIndex the index between 0 and category Count-1
* @return the category key
* 
*/
virtual CATString GetCategoryKey(const int & iCategoryIndex) = 0;


/**
*
* <br><b>Role</b>: Gets the index of a category
* @param iCategoryKey : the category key (empty key not permitted)
* @return the index of a category (between 0 and category Count-1)
* 
*/
virtual  int  GetCategoryIndex(const CATString & iCategoryKey) = 0;
/**
*
* <br><b>Role</b>: Gets the series key from an index
* @param iSeriesIndex the index between 0 and series Count-1
* @return the series key
* 
*/
virtual CATString GetSeriesKey(const int & iSeriesIndex) = 0;
/**
*
* <br><b>Role</b>: Gets the index of a series
* @param iSeriesKey : the series key (empty key not permitted)
* @return the index of a series (between 0 and series Count-1)
* 
*/
virtual  int  GetSeriesIndex(const CATString & iSeriesKey) = 0;



};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIAfrChart, CATBaseUnknown );

#endif

// COPYRIGHT Dassault Systemes 2004
#ifndef CATColumnModel_H
#define CATColumnModel_H

#include <CATView.h>
#include <CATBaseUnknown.h>
#include <CATString.h>
#include <CATUnicodeString.h>
#include <CATListOfCATString.h>
#include <CATIColumnModel.h>

/**
 * Columns definitions
 **/
class CATColumnModelItem
{
public:
    CATString _id;
    CATUnicodeString _title;
    int _width;
	int _show;
	int operator != ( const CATColumnModelItem &iItem ) const
	{
		return iItem._id!=_id;
	}
};

#include <CATLISTV_Clean.h>
#define CATLISTV_RemovePosition
#include <CATLISTV_Declare.h>
CATLISTV_DECLARE( CATColumnModelItem );
typedef CATLISTV( CATColumnModelItem ) CATListOfCATColumnModelItem;

/**
 * CATColumnModel. Model for set of columns: names, width...
 **/
class ExportedByCATView CATColumnModel: public CATIColumnModel
{
    CATDeclareClass;
public:
    /**
     * Constructor
     **/
    CATColumnModel( void );
    /**
     * Destructor
     **/
    virtual ~CATColumnModel( void );
    /**
     * Add a column
     **/
    void AddColumn( const CATString &iID, const CATUnicodeString &iTitle, int iWidth );
    /**
     * Remove a column
     **/
    void RemoveColumn( const CATString &iID );
    /**
     * Set columns order
     **/
    void SetColumnOrder( const CATListOfCATString &iIDs );
    /**
     * Get columns order
     **/
    void GetColumnOrder( CATListOfCATString &oIDs );
    /**
     * Get column width
     **/
    int GetColumnWidth( const CATString &iID );
    /**
     * Set column width
     **/
    void SetColumnWidth( const CATString &iID, int iWidth );
    /**
     * Get column title
     **/
    CATUnicodeString GetColumnTitle( const CATString &iID );
    /**
     * Set column title
     **/
    void SetColumnTitle( const CATString &iID, const CATUnicodeString &iTitle );
    /**
     * Set sort definition
     **/
    void SetSortDefinition( const CATString &iColumnID, int iReverse= 0 );
    /**
     * Get sort definition
     **/
    void GetSortDefinition( CATString &oColumnID, int &oReverse );
	/**
	 * Service for serialization of column definition
	 **/
	static HRESULT Serialize( CATIColumnModel *iModel, CATUnicodeString &oDefinition );
	/**
	 * Service for un-serialization of column definition
	 **/
	static HRESULT UnSerialize( CATIColumnModel *iModel, const CATUnicodeString &iDefinition );
	/*
	 * CATIColumnModel2
	 */
    void HideColumn( const CATString &iID );
	void ShowColumn( const CATString &iID );
	void GetHiddenColumns( CATListOfCATString &oIDs );
  void GetColumns( CATListOfCATString &oIDs );

private:
    /**
     * Sort definition
     **/
    CATString _sortColumnID;
    int _sortReverse;
    CATColumnModelItem &GetColumn( const CATString &iID );
    CATListOfCATColumnModelItem _columns;
};

#endif

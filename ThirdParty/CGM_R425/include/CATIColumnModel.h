// COPYRIGHT Dassault Systemes 2005
#ifndef CATIColumnModel_H
#define CATIColumnModel_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>
#include <CATString.h>
#include <CATUnicodeString.h>
#include <CATListOfCATString.h>

extern ExportedByCATViewItf IID IID_CATIColumnModel;


/**
 * CATIColumnModel. Interface to display a model in a tree view.
 * For column hide/show management, @see CATIColumnModel2. 
 **/
class ExportedByCATViewItf CATIColumnModel: public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Set columns order
     **/
    virtual void SetColumnOrder( const CATListOfCATString &iIDs ) = 0;
    /**
     * Get columns order
     **/
    virtual void GetColumnOrder( CATListOfCATString &oIDs ) = 0;
    /**
     * Get column width
     **/
    virtual int GetColumnWidth( const CATString &iID ) = 0;
    /**
     * Set column width
     **/
    virtual void SetColumnWidth( const CATString &iID, int iWidth ) = 0;
    /**
     * Get column title
     **/
    virtual CATUnicodeString GetColumnTitle( const CATString &iID ) = 0;
    /**
     * Set sort definition
     **/
    virtual void SetSortDefinition( const CATString &iColumnID, int iReverse= 0 ) = 0;
    /**
     * Get sort definition
     **/
    virtual void GetSortDefinition( CATString &oColumnID, int &oReverse ) = 0;
	/*
	 * DEPRECATED !
	 */
	virtual void AddColumn( const CATString &iID, const CATUnicodeString &iTitle, int iWidth ) = 0;
	virtual void RemoveColumn( const CATString &iID ) = 0;
};

CATDeclareHandler(CATIColumnModel, CATBaseUnknown);

#endif

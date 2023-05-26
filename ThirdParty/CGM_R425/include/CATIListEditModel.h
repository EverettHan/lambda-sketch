// COPYRIGHT Dassault Systemes 2005
#ifndef CATIListEditModel_H
#define CATIListEditModel_H

#include <CATViewItf.h>
#include <CATIListViewModel.h>
#include <CATUnicodeString.h>
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var;

extern ExportedByCATViewItf IID IID_CATIListEditModel;

/**
 * CATIListEditModel. Interface to modify the model in a list view.
 **/
class ExportedByCATViewItf CATIListEditModel: public CATIListViewModel
{
    CATDeclareInterface;
public:
   virtual void SetLabel( CATBaseUnknown_var iItem,
                          const CATString &iColumnID,
                          const CATUnicodeString& iLabel )=0;

      /** Checks if an object is dirty (some of its values have been changed and not saved).
       * @param iObj Object to check for modified values
       * @return 0 if the object is clean
       *         1 if the object is dirty
       */
      virtual int IsDirty( const CATBaseUnknown_var & iObj ) = 0;


      /** Cancels the modifications done on the object. The modified values will not be saved, will
       * be put back to the values currently in database, and the object will not be dirty anymore.
       * @param iObj Object to clean
       * @param S_OK The object has been cleaned
       *        S_FALSE The object was not dirty
       *        E_FAIL A problem occured
       */
       virtual HRESULT Revert( const CATBaseUnknown_var & iObj ) = 0;


      /** Cancels the modifications for all the objects of the sheet editor. The modified values will
       * not be saved, will be put back to the values currently in database, and the objects will not
       * be dirty anymore.
       * @return S_OK All the objects have been cleaned
       *         E_FAIL A problem occured
       */

      virtual HRESULT Reset() = 0;


      /** Saves all modifications for all objects in database, and marks them as not dirty.
       * @return S_OK The whole list has been saved in database, then cleaned
       *         E_FAIL A problem occured
       */

      virtual HRESULT SaveAll() = 0;
    
      /**
       * Determine whether this attribute on this item may be edited.
       * @return TRUE The specified attribute on the specified object may be edited<br>
       *         FALSE It may not.
       */
      virtual CATBoolean IsEditable(const CATBaseUnknown_var& iObj, const CATString& iColID)=0;

};

CATDeclareHandler( CATIListEditModel, CATIListViewModel );

#endif

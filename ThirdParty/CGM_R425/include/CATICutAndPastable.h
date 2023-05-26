#ifndef CATICutAndPastable_H
#define CATICutAndPastable_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Required                                
*/


#include <CATBaseUnknown.h>

#include <CATBaseUnknowns.h>

#include <CATBaseUnknown_Associations.h>

#include <CATFormat.h>
#include <CATFormats.h>

#include <CP0CLIP.h>

extern ExportedByCP0CLIP IID IID_CATICutAndPastable ;

/**
* Interface to manage Cut Copy Paste.
* <b> Role:</b> this interface is used by interactive commands such as Drag&Drop
* or Cut Copy Paste.
* 
* <br> CATICutAndPastable exposes the methods required to: 
* <br>
* <br>    extract the selected objects for either a cut or a copy 
* <br>    paste these objects 
* <br>    remove the selected objects from their initial location for a cut 
* <br>    paste an object as a link rather than copying its actual data.
* <br>
* <p><b>BOA information</b>: this interface CANNOT be implemented
* using the BOA (Basic Object Adapter).
* To know more about the BOA, refer to the CAA Encyclopedia home page.
* Click Middleware at the bottom left, then click the Object Modeler tab page.
* Several articles deal with the BOA.</p>
*/

class ExportedByCP0CLIP CATICutAndPastable: public CATBaseUnknown
{
  CATDeclareInterface;
 public:

	/**
	* Lists formats which can be extracted from the selection.
	* <br><b> Role: </b> used on copy.
	*/
  virtual CATLISTP(CATFormat) ListExtractFormats() const=0;

    /**
	* Lists objects to extract.
	* <br><b> Role: </b> used on copy.
	* @param ioObjectsAlreadyInBoundary
	*        list of objects to extract.
	* @param iObjectsToAdd
	*		 list objects to add to list of objects to extract.
	* @param iAnImposedFormat
	*        if this format is not valid, it will be reinitialized.
	* @return 
	*        1 if there is at least one object extracted.
	*   <br> 0 otherwise
	*/
  virtual int BoundaryExtract(ListOfVarBaseUnknown& ioObjectsAlreadyInBoundary,
			      const ListOfVarBaseUnknown* iObjectsToAdd=NULL,
			      const CATFormat* iAnImposedFormat=NULL) const=0;

	/**
 	* Creates a structure to receive the boundary object in the requested format.
	* <br><b> Role: </b> used on copy.
	* @param iObjectToCopy
	*        list of objects to copy.
	* @param iAnImposedFormat
	*        if this format is not valid, it will be reinitialized.
	* @return 
	*        structure created by extract.
    */
  virtual VarBaseUnknown Extract(ListOfVarBaseUnknown& iObjectToCopy,
				     const CATFormat* iAnImposedFormat=NULL) const=0;

	/**
	* Lists formats which can be pasted.
	* <br><b> Role: </b> used on paste.
	*/
  virtual CATLISTP(CATFormat) ListPasteFormats() const=0;

	/**
 	* Returns the path of the object to copy.
	* <br><b> Role: </b> used on copy and paste.
	* @param iObjectToCopy
	*        list of objects to copy.
	* @param iToCurObjects   
	*        target objects for paste corresponding to selected objects.
	* @param iAnImposedFormat
	*        if this format is not valid, it will be reinitialized.
    */
  virtual ListOfVarBaseUnknown Paste(ListOfVarBaseUnknown& iObjectToCopy,
				  ListOfVarBaseUnknown* iToCurObjects=NULL,
				  const CATFormat* iAnImposedFormat=NULL)=0;

	/**
	* Creates in the client side, all objects required, and provides associations.
	* @param ioAssociationOfObjects
	*        couples of objects source/target.
	* @param iAnImposedFormat
	*        if this format is not valid, it will be reinitialized.
	* @return
	*        0 if failed
	*/
  virtual int Create(CATBaseUnknown_Associations& ioAssociationOfObjects,
		     const CATFormat* iAnImposedFormat=NULL)=0;
	/**
    * Makes in the client, the update of data and relations.
	* @param ioAssociationOfObjects
	*        couples of objects source/target.
	* @param iAnImposedFormat
	*        if this format is not valid, it will be reinitialized.
	* @param iToCurObjects   
	*        target objects for paste corresponding to selected objects.
	* @return
	*        0 if failed
	*/
  virtual int Update      (CATBaseUnknown_Associations& ioAssociationOfObjects,
					const CATFormat* iAnImposedFormat=NULL,
					ListOfVarBaseUnknown* iToCurObjects=NULL)=0;



  /**
   * @nodoc
   * makes structure link integration
   */
  virtual CATLISTP(CATFormat) ListLinkFormats() const=0;
	/** @nodoc */
  virtual ListOfVarBaseUnknown Link(ListOfVarBaseUnknown& object_to_link,
				 ListOfVarBaseUnknown* to_cur_objects=NULL,
				 const CATFormat* an_imposed_format=NULL)=0;

	/**
	* Lists formats which can be removed from the selection.
	* <br><b> Role: </b> used on cut and delete.
	*/
  virtual CATLISTP(CATFormat) ListRemoveFormats() const=0;

  /**
	* Lists objects to remove.
	* <br><b> Role: </b> used on cut and delete.
	* @param ioObjectsAlreadyInBoundary
	*        list of objects to remove.
	* @param iObjectsToRemove
	*		 list objects to remove to list of objects to extract.
	* @param iAnImposedFormat
	*        if this format is not valid, it will be reinitialized.
	* @return 
	*        1 if there is at least one object removed.
	*   <br> 0 otherwise
	*/
  virtual int BoundaryRemove(ListOfVarBaseUnknown& ioObjectsAlreadyInBoundary,
			     const ListOfVarBaseUnknown* iObjectsToRemove=NULL,
			     const CATFormat* iAnImposedFormat=NULL) const=0;

	/**
 	* Removes objects from the client.
	* <br><b> Role: </b> used on cut and delete.
	* @param iObjectToRemove
	*        list of objects to remove.
	* @param iAnImposedFormat
	*        if this format is not valid, it will be reinitialized.
	* @return 
	*        structure created by remove.
    */
  virtual int Remove      (ListOfVarBaseUnknown& iObjectToRemove,
			   const CATFormat* iAnImposedFormat=NULL)=0;

};


CATDeclareHandler( CATICutAndPastable, CATBaseUnknown ) ;

#endif 


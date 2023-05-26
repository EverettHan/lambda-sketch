#ifndef CATVidCtlDataBlockFactoryEditor_h
#define CATVidCtlDataBlockFactoryEditor_h

// COPYRIGHT Dassault Systemes 2014

#include <VisuDialog.h>
#include <CATVidCtlListView.h>
#include <CATVidCtl.h>
#include <CATSYPDataBlockFactory.h>
#include <CATSYPArray.h>
#include <CATVidCtlAbstractDataBlockFactoryEditor.h>

class CATBaseUnknown;
class CATSYPEventArgs;
class CATError;
class CATVidMdlDynamicItemViewPrebuildEventArgs;
class CATVidMdlItemViewBuiltEventArgs;
class CATListValCATBaseUnknown_var;
class CATIVidMdl_var;
class CATVidMdlStandardList;

/**
* Class used to create a data block factory editor widget from a type name.
* @see CATVidCtlTweaker
*/
class ExportedByVisuDialog CATVidCtlDataBlockFactoryEditor : public CATVidCtlAbstractDataBlockFactoryEditor
{
	CATDeclareClass;
public:

   /**
   * Constructs a data block factory(DBF) editor with default style.
   */
	static CATVidCtlDataBlockFactoryEditor * CreateDatablockFactoryEditor();
	
	/**
	* Default constructor
	*/
	CATVidCtlDataBlockFactoryEditor();

	/**
	* Default destructor
	*/
	~CATVidCtlDataBlockFactoryEditor();

	/**
	* Intialize the data block factory editor view.
	*/
	void TemplateDataUpdated();


	/**
	* Callback on adding introspectable property to the data block factory.
	* The editor add an item related to the new property, and the data block factory
	* is updated.
	*/
	void OnAddProperty(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

	/**
	* Callback on adding introspectable property to the data block factory.
	* The editor add an item related to the new property, and the data block factory
	* is updated.
	*/
	void OnRemoveProperty(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

	/**
	* Display DataBlock properties' data on a graphical presentation for ex : listview. 
	* It is for edition purposes.
	* @input i_pDataBlock : data to graphically display.
	* @see CreateListModelFromDatablock
	*/
	void DisplayDataBlock(CATSYPDataBlock* i_pDataBlock);
	
	/**
	* Generate data block 
	* @output oGeneratedDataBlock : generated data block
	*/
	HRESULT GenerateDataBlock(CATSYPDataBlock*& oGeneratedDataBlock);

	HRESULT GenerateDBFactoryFromData(CATSYPDataBlockFactory & oGeneratedFactory, CATSYPDynArray<CATError*> & oErrorArray);
	void DisplayModelproperties(CATIVidMdl_var & ispModel);
	void OnPropertyTypeChanged(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
	
private :

	/**
	* Create model from datablock
	* @input i_pDataBlock : used to extract data for the model to create
	*/
	CATVidMdlStandardList* CreateListModelFromDatablock(CATSYPDataBlock* i_pDataBlock);
	void AddError(CATUnicodeString PropStr, CATUnicodeString ErrorKind, int LineError, CATSYPDynArray<CATError*> & oErrorArray);

	void DynamicItemViewPrebuild(CATBaseUnknown * i_pSender, CATVidMdlDynamicItemViewPrebuildEventArgs * i_pArgs);
	void ItemViewBuilt(CATBaseUnknown * i_pSender, CATVidMdlItemViewBuiltEventArgs * i_pArgs);
	void SetTypePossibleValues(CATListValCATBaseUnknown_var & TypespossibleValues);


	CATVidCtlListView * _pListView;
	CATSYPDataBlockFactory _dbFactory;
	CATSYPEventHandler * _pPropAccessModeItemViewPrebuildHandler;
	CATBoolean _isElementBuildingInProgress;

};

#endif 

#ifndef CATVidCtlModelEditor_h
#define CATVidCtlModelEditor_h

// COPYRIGHT Dassault Systemes 2014

#include <VisuDialog.h>
#include <CATVidCtlListView.h>
#include <CATVidMdlStandardList.h>
#include <CATSYPMetaClass.h>
#include <CATVidMdlStandardTree.h>
#include <CATVidCtlTreeView.h>
#include <CATIVidMdl.h>
#include <CATVidCtl.h>
#include <CATSYPDataBlockFactory.h>
#include <CATSYPArray.h>

class CATBaseUnknown;
class CATSYPEventArgs;
class CATError;
class CATVidMdlIndex;
class CATUnicodeString;

/**
 * Class used to create a data block factory editor widget from a type name.
 * @see CATVidCtlTweaker
 */
class ExportedByVisuDialog CATVidCtlModelEditor : public CATVidCtl
{
  CATDeclareClass;
  public:

    /**
    * Creates a new CATVidCtlModelEditor.
    * CATIVidMdl * ipiVidMdl : Model represented in the model editor.
    * CATSYPMetaClass * ipMetaclass = NULL : optional argument. Metaclass which will be used to instantiate new data items.
    * CATUnicodeString DisplayMode  : optional argument. Allows choosing model editor representation mode;
    *                  Set it to "List" to represent your model ina list view.(default mode)
    *                  Set it to "Tree" to represent your model ina tree view.
    */    
    static CATVidCtlModelEditor * CreateModelEditor(CATIVidMdl * ipiVidMdl, CATSYPMetaClass * ipMetaclass = NULL, CATUnicodeString DisplayMode = "List");    

    CATVidCtlModelEditor(CATIVidMdl * ipiVidMdl, CATSYPMetaClass * ipMetaclass = NULL, CATUnicodeString DisplayMode = "List");

    CATVidCtlModelEditor();
    
    ~CATVidCtlModelEditor();

    virtual void TemplateDataUpdated();

    void OnAddModelChildItem(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

    void OnAddModelItem(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

    void OnRemoveModelItem(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

    CATIVidMdl_var GetSourceModel() const;

    /*
    * Set the model which will be represented in the model editor.
    */
    void SetSourceModel(const CATIVidMdl_var & i_spSourceModel);
     

private :    

    void SelectedItemsChanged(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

    void BuildModelEditor();

    /*
    * Specify the view mode in which model will be edited.
    *         iDisplayMode = "List" : the model is represented inside a list view.
    *         iDisplayMode = "Tree" : the model is represented inside a tree view.
    */
    void SetDisplayMode(CATUnicodeString iDisplayMode); 

    void CleanDataBlockMembers();
    
    CATVidCtlTreeView * _pTreeView;
    CATVidCtlListView * _pListView;
    CATIVidMdl_var _spVidMdl;
    CATSYPEventHandler * _pTreeItemSelectedHandler;        
    CATSYPDynArray<CATSYPDataBlockFactory*> _DataBlockFactoryArray;
    CATSYPMetaClass * _pMetaclass;
    CATBoolean _isTreeView;
    CATBoolean _isListView;
    CATBoolean _DatablockCase;
    
};

#endif 

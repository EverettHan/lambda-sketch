#ifndef _CATSYPStyleProcessor_H
#define _CATSYPStyleProcessor_H

#include <CATCollec.h>
#include <CATLISTP_CATBaseUnknown.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATListOfCATUnicodeString.h>
#include <CATMathPointf.h>
#include <CATSYPArray.h>
#include <CATSYPHashMap.h>
#include <CATSYPIntrospectableAdapter.h>
#include <CATSYPResourcesFinder.h>
#include <CATSetOfCATUnicodeString.h>
#include <CATStyleProcessor.h>
class CATUnicodeString;
class CATISYPCollection_var;
class CATISYPPresenter_var;
class CATSYPTagInstance;
class CATSYPModelTag;
class CATSYPModelTemplate;
class CATSYPModelStoryboard;
class CATSYPErrorReport;
class CATSYPErrorReportFactory;
class CATSYPModelTagFactory;
class CATSYPTemplateData;
class CATSYPModelBuilder;
class CATSYPModelDataBlockFactory;
class CATSYPDataBlock;
class CATSYPDataBlockFactory;

struct CATSYPTemplateAttributes
{
  CATUnicodeString className;
  CATUnicodeString templateName;
  CATUnicodeString variationName;
};

struct CATSYPDataTemplateAttributes
{
  CATUnicodeString templateName;
  CATUnicodeString variationName;
};

/**
 * This object process XML files to generate and connect introspectable objects.
 * @see introspection article : http://codewiki/codewiki/index.php/CID_:_Introspection  
 */
class ExportedByCATStyleProcessor CATSYPStyleProcessor : public CATBaseUnknown
{
  CATDeclareClass;

  public:
  /** The modes of binding that are available */
  enum BindingMode
  {
    /** Default mode*/
    Default = 0,
    /** Binding in two ways, that is from source to target and from target to source*/
    TwoWays,
    /** Binding in one way, from source to target*/
    OneWay,
    /** Binding in one way, from target to source*/
    OneWayToSource
  };

  /** The modes of parsing resources, represents level tolerance on parsing error*/
  enum ParsingMode
  {
    /** No tolerance of parsing errors*/
    Restricted,
    /** Tolerate unknown templates*/
    Permissif
  };

  /** Constructor */
  CATSYPStyleProcessor(CATSYPStyleProcessor::ParsingMode = CATSYPStyleProcessor::Restricted);

  /**
   * Constructor with exclusion list
   * @param i_exclusionList a list of class that can't be associated to a template 
   * in this style processor. 
   * In VID, this list contains all the basic class defined in a standard theme. It 
   * allows to control the appearence of the whole application. In this case, 
   * all the objects excluded are templated in the parent style processors of this one.
   */
  CATSYPStyleProcessor(const CATSetOfCATUnicodeString &i_exclusionList, const CATSetOfCATUnicodeString &i_exceptionList, CATSYPStyleProcessor::ParsingMode = CATSYPStyleProcessor::Restricted);

  /** Destructor */
  virtual ~CATSYPStyleProcessor();

  /**
  * Sets & Gets the resources parsing mode that defined tolerance to parsing errors 
  */
  CATSYPStyleProcessor::ParsingMode GetParsingMode();
  /** 
   * Sets the parent style processor, used to find templates unfound in this one.
   * This mecanism allows to create a hierarchical tree of theme.
   * For example in VID, at the end of the CATSYPStyleProcessor tree will be found 
   * a style processor with an exclusion list (excluding the widgets defined in a theme), 
   * Its father could be a standard theme overload, and the last father the standard theme.
   */
  void SetParentStyleProcessor(CATSYPStyleProcessor *i_pStyleProcessor);

  /**Return the parent style processor*/
  CATSYPStyleProcessor *GetParentStyleProcessor();

  /**
   * Recovers a template representing the i_spLeftObject (see #GetTemplate), 
   * and build a view of it by parsing the recovered hierarchical model tree.
   * @param i_spLeftObject the object to build a view.
   * @return the generated view.
   */
  CATBaseUnknown_var Generate(const CATISYPIntrospectable_var &i_spLeftObject);

  /**
   * Applies styles to a templated data.
   * This allows to apply a list of setters on any syp:named object of a templated object.
   * @return 1 if a style is found.
   */
  int ApplyStyles(const CATISYPIntrospectable_var &i_spLeftObject, const CATUnicodeString &i_styles, CATSYPTemplateData *i_pTemplateData);
  /**
   * Adds template to the style processor. The file path must point an exisinting sypstyle file.
   * It will call recursively AddResourecs if some ResourceDictionary is found in the sypstyle.
   * If the path is absolute, we build it immediately. 
   * Note that a ressource builder assigned to a zip file will fail to load a sypstyle with an absolute path.
   * A sypstyle with a relative path will be looked up : 
   * - directly in the resource finder
   * - prefixed by CATSTYPStyle/
   * If the sypstyle lookup failed, it AddResources will be called on the parent style processor.
   * @param i_filePath the name of the resource file
   * @param i_fullPathFlag a flag indicating if the the file path is a full, or relative
   */
  CATSYPMap<CATUnicodeString, CATUnicodeString> *AddResources(const CATUnicodeString &i_filePath, CATBoolean i_fullPathFlag = TRUE, const CATSYPConstMap<CATUnicodeString, CATUnicodeString> *const i_pDescription = NULL);
  /**
   * Reset the ressources stored in the style processor. All templates will be deleted.
   * Note that it is not recursive, and will not call ResetResources on the parent style processor.
   */
  void ResetResources();
  /** 
   * Calls #ResetResources and re-parse all already parsed sypstyle files.
   */
  void ReloadResources();
  /** @return the last generated error report, in a CATUnicodeString*/
  CATUnicodeString GetErrorReport() const;
  /** 
   * Recovers a template for a given object, by recovering on it its class name, 
   * and from the interface CATISYPTemplate a template name and a variation name.
   * If the template is not found in the template list, we call GetTemplate on the parent
   * style processor.
   * @see CATISYPTemplate
   * @param i_spLeftObject the object to recover the template.
   * @return the template. NULL if not found.
   */
  CATSYPModelTemplate *GetTemplate(const CATBaseUnknown_var &i_spLeftObject);
  CATSYPModelTemplate *IsTemplate(const CATBaseUnknown_var &i_spLeftObject);
  CATSYPModelTemplate *GetDataTemplate(const CATUnicodeString &i_dataTemplateName, const CATUnicodeString &i_variationName = "");
  CATSYPModelTemplate *IsDataTemplate(const CATUnicodeString &i_dataTemplateName, const CATUnicodeString &i_variationName = "");
  /** 
   * Recovers a data block factory template from its name. 
   * If the factory is not found in the factory list, we call GetDataBlockFactoryTemplate on the parent
   * style processor. 
   * @param i_factoryName the name of the factory. 
   * @return the factory. NULL if not found. 
   */
  CATSYPModelDataBlockFactory *GetDataBlockFactoryTemplate(const CATUnicodeString &i_factoryName);
  /** 
   * Recovers a data block factory instance from its name. 
   * If the factory instance is not found in the factory instance list, we call GetDataBlockFactoryInstance on the parent
   * style processor. 
   * @param i_factoryName the name of the factory. 
   * @return the factory instance, NULL if not found. 
   */
  CATSYPDataBlockFactory *GetDataBlockFactoryInstance(const CATUnicodeString &i_factoryName);

  /**
   * @copydoc CATSYPResourcesFinder#SetPathFolderList
   */
  void SetPathFolderList(const CATUnicodeString &i_pathFolderList);
  /**
   * @copydoc CATSYPResourcesFinder#GetPathFolderList
   */
  const CATUnicodeString &GetPathFolderList() const;
  /**
   * @copydoc CATSYPResourcesFinder#SetZipFilePath
   */
  void SetZipFilePath(const CATUnicodeString &i_pathFolderList);
  /**
   * @copydoc CATSYPResourcesFinder#GetZipFilePath
   */
  const CATUnicodeString &GetZipFilePath() const;
  /**
   * @copydoc CATSYPResourcesFinder#SetSubDirectoryPath
   */
  void SetSubDirectoriesPathList(const CATUnicodeString &i_pathFolderList);
  /**
   * @copydoc CATSYPResourcesFinder#GetSubDirectoriesPathList
   */
  CATUnicodeString GetSubDirectoriesPathList() const;
  /**
   * Sets the error report factory, that will create error reports.
   * It is AddRef-ed by the style processor.
   * @param i_pErrorReportFactory the factory to set. Can't be NULL.
   */
  void SetErrorReportFactory(CATSYPErrorReportFactory *i_pErrorReportFactory);
  /**
   * @return if a resource file has already be parsed by the processor. 
   * Note that 2 style sheet with same name could be found in a style processor and its parent, 
   * with different content. (for e.g, themeDescriptor.sypstyle...)
   */
  int LocateResourceFile(const CATUnicodeString &i_fileName) const;
  /**
   * @return if a template found in a resource file has already be parsed by style processor. 
   * Note that 2 style sheet with same name could be found in a style processor and its parent, 
   * with different content. (for e.g, themeDescriptor.sypstyle...)
   */
  int LocateTemplate(const CATSYPModelTemplate *i_template, const CATUnicodeString &i_fileName);
  /**
   * Recovers a data template representing the i_spLeftObject (see #GetDataTemplate), 
   * and builds a view of it by parsing the recovered hierarchical model tree.
   * @param i_spLeftObject the object to build a view.
   * @param i_dataTemplate name of the data template to use
   * @param o_pTemplateData template data built by the StyleProcessor. Giving NULL (the default value)
   * doesn't trigger the generation of template data.
   * @return the generated view.
   */
  CATBaseUnknown_var GenerateUsingDataTemplate(const CATISYPIntrospectable_var &i_spLeftObject, const CATUnicodeString &i_dataTemplate, CATSYPTemplateData *o_pTemplateData = NULL);
  /**
   * Recovers a data template representing the i_spLeftObject (see #GetDataTemplate), 
   * and builds a view of it by parsing the recovered hierarchical model tree.
   * @param i_spLeftObject the object to build a view.
   * @param i_dataTemplate name of the data template to use
   * @param i_dataTemplateVariation name of the data template variation to use
   * @param o_pTemplateData template data built by the StyleProcessor. Giving NULL (the default value)
   * doesn't trigger the generation of template data.
   * @return the generated view.
   */
  CATBaseUnknown_var GenerateUsingDataTemplate(const CATISYPIntrospectable_var &i_spLeftObject, const CATUnicodeString &i_dataTemplate, const CATUnicodeString &i_dataTemplateVariation, CATSYPTemplateData *o_pTemplateData = NULL);
  /**
   * Recovers a data block factory described in a declarative file.
   * @param i_factory name of the factory.
   * @return the generated data block factory. 
   */
  CATSYPDataBlockFactory *GenerateDataBlockFactory(const CATUnicodeString &i_factory);

  /**
   * Create a data block factory model from a datablock
   * @param i_pDataBlock datablock to parse.
   * @param i_factoryName : factory name
   * @param i_version : data block factory version
   * @return the generated data block factory model. 
   */
  CATSYPModelDataBlockFactory *GenerateDataBlockFactory(CATSYPDataBlock *i_pDataBlock, const CATUnicodeString &i_factoryName, int i_version = 1);

  /** 
   * Generate a data block based on a data block factory described in a declarative file 
   * @param i_factory name of the factory. 
   * @return the generated data block. 
   */
  CATSYPDataBlock *GenerateDataBlock(const CATUnicodeString &i_factory);

  /** 
   * Generate a data block based on a CATSYPModelDataBlockFactory 
   * @param i_pModelDataBlockFactory data block factory. 
   * @return the generated data block. 
   */
  CATSYPDataBlock *GenerateDataBlock(CATSYPModelDataBlockFactory *i_factory);

  /**
   * Defines a namespace URI as basic.
   * Objects from this namespace won't be translated, they will be returned as is.
   */
  void AddBasicNamespace(const CATUnicodeString &i_URI);
  /**
   * Adds a namespace, i.e. a ModelTagFactory, associated to an URI, see CATSYPModelTagFactory::GetURI().
   * There will be a translation from the namespace to objects in the C++ domain.
   * The lifecycle of i_pModelTagFactory is managed by the StyleProcessor instance.
   * Don't call Release() on it.
   */
  void AddNamespace(CATSYPModelTagFactory *i_pModelTagFactory);
  /**
   * Sets a flag indicating if a the view of templated sub-objects must be built recursively.
   * Default value is TRUE.
   */
  void SetBuildEmbeddedTemplatesFlag(CATBoolean i_buildEmbeddedTemplatesFlag);
  /**
   * @return a flag indicating if a the view of templated sub-objects must be built recursively.
   */
  CATBoolean GetBuildEmbeddedTemplatesFlag() const;
  /**
   * Indicates whether or not a template exists with the given variation name.
   * This member function will look for the given variation of the template
   * in all the StyleProcessor instances of the hierarchy.
   *
   * @param i_objectType the class name of the target of the requested template
   *
   * @param i_templateName the template name to look for
   *
   * @param i_variationName the variation to look for
   *
   * @return TRUE when a template with the given variation name exists, FALSE
   * otherwise.
   */
  CATBoolean IsTemplateSupported(const CATUnicodeString &i_objectType, const CATUnicodeString &i_templateName, const CATUnicodeString &i_variationName); // const;

  /**
   * Indicates whether or not a data template exists with the given variation name.
   * This member function will look for the given variation of the template
   * in all the StyleProcessor instances of the hierarchy.
   *
   * @param i_templateName the template name to look for
   *
   * @param i_variationName the variation to look for
   *
   * @return TRUE when a template with the given variation name exists, FALSE
   * otherwise.
   */
  CATBoolean IsDataTemplateSupported(const CATUnicodeString &i_templateName, const CATUnicodeString &i_variationName);

  void SetLoadTemplateWhenParsingFlag(int i_loadTemplateWhenParsingFlag);
  int GetLoadTemplateWhenParsingFlag() const { return _loadTemplateWhenParsingFlag; }

  /**
  * Generate a template from a string and builds a view of it. This string defines one template where the target matches the i_spLeftObject's type, 
  * @param i_spLeftObject the object to build a view.
  * @param i_templateAsString the string that represents one template where the target matches the i_spLeftObject's type
  * @return the generated view.
  */
  CATBaseUnknown_var GenerateFromString(const CATISYPIntrospectable_var &i_spLeftObject, const CATUnicodeString &i_templateAsString);

  private:
  CATSYPModelTemplate *BuildModel(CATSYPModelTemplate *i_pTemplate);
  /** Assert on errors */
  void AssertOnErrors(const CATUnicodeString &i_filePath);
  void BreakODT(const CATUnicodeString &i_filePath, const CATUnicodeString &i_message);
  /**
   * Used to propose a list of available templates/variztions for an object, when the one wanted is not available
   */
  CATSYPDynArray<CATSYPModelTemplate *> GetTemplateListForClass(const CATUnicodeString &i_objectType, int i_hideLocalsFlag) const;

  /**
  * Proposes a list of available templates/variations related(contained) to a resource file if not available we check in _pParentStyleProcessor templatelist
  * return NULL if the resource file is not available or do not contain templates
  */
  CATSYPDynArray<CATSYPModelTemplate *> GetTemplateListFromResourceFile(const CATUnicodeString &i_filePath, CATBoolean i_fullPathFlag);

  /**
  * Get Template list contained in resoure file i_filePath
  * @param i_filePath the name of the replace resource file 
  * @param i_fullPathFlag a flag indicating if the replace file path is a full, or relative
  * @return o_templateList: list of template either NULL is resource file is not available 
  */
  void GetTemplateListOfResource(const CATUnicodeString &i_filePath, CATBoolean i_fullPathFlag, CATSYPHashMap<CATSYPTemplateAttributes, CATSYPModelTemplate *> &o_templateList);
  /**
  * Get Data template list contained in resoure file i_filePath
  * @param i_filePath the name of the replace resource file 
  * @param i_fullPathFlag a flag indicating if the replace file path is a full, or relative
  * @return o_templateList: list of data template either NULL is resource file is not available 
  */
  void GetDataTemplateListOfResource(const CATUnicodeString &i_filePath, CATBoolean i_fullPathFlag, CATSYPHashMap<CATSYPDataTemplateAttributes, CATSYPModelTemplate *> &o_templateList);

  /** 
  * Replace model template
  * call to #ReplaceResource(const CATUnicodeString& i_filePath, CATBoolean i_fullPathFlag = TRUE)
  * @param i_filePathReplace the name of the replace resource file 
  * @param i_fullPathReplaceFlag a flag indicating if the replace file path is a full, or relative
  */
  void ReplaceResource(const CATSYPModelTemplate *i_pTemplate, const CATUnicodeString &i_filePathReplace, CATBoolean i_fullPathReplaceFlag = TRUE);

  /**
  * Replace resource file if existe either call directly #AddResources
  * clean the previous resource file and AddResources of the new one
  * @param i_filePathToReplace the name of the resource file to replace
  * @param i_fullPathToReplaceFlag a flag indicating if the file path to replace is a full, or relative
  * @param i_filePathReplace the name of the replace resource file 
  * @param i_fullPathReplaceFlag a flag indicating if the replace file path is a full, or relative
  */
  void ReplaceResource(const CATUnicodeString &i_filePathToReplace, const CATUnicodeString &i_filePathReplace, CATBoolean i_fullPathToReplaceFlag = TRUE, CATBoolean i_fullPathReplaceFlag = TRUE);

  /**
   * Add @c pTemplate
   */
  enum TemplateType
  {
    Template,
    DataTemplate
  };
  void AddToTemplateList(CATSYPModelTemplate *i_pTemplate, TemplateType iTemplateType);
  void AddToDataBlockFactoryList(CATSYPModelDataBlockFactory *pFactory);
  CATSYPModelTemplate *InternalGetTemplate(CATMetaClass *i_objectClass, const CATUnicodeString &i_templateName, const CATUnicodeString &i_variationName, CATBoolean i_hideLocalsFlag, CATBoolean i_returnDefaultFlag = TRUE);

  /**
   * Recovers a template from the triplet of string class name + template name + variation name.
   * @param i_className the class name
   * @param i_templateName the template name, that will determines highly the view of the model object of type i_className
   * @param i_variationName the variation name, that will be a variation of the requested template. (for ex, the vertical view or horizontal view of a standard slider)
   * @param i_returnDefaultFlag a flag indicating if the exact tripplet combinaison must match. If TRUE, if the variation does not match, recover the triplet i_className+i_templateName+"".
   * If it is still not found, recover the tripplet i_className+""+"".
   * @return the template corresponding to the requested triplet. Null if not found.
   */
  CATSYPModelTemplate *GetTemplateElement(const CATUnicodeString &i_objectType, const CATUnicodeString &i_templateName, const CATUnicodeString &i_variationName, CATBoolean i_hideLocalsFlag, CATBoolean i_returnDefaultFlag = TRUE);
  CATSYPModelTemplate *GetDataTemplateElement(const CATUnicodeString &i_dataTemplateName, const CATUnicodeString &i_variationName, int i_buildIfNeededFlag);
  CATSYPModelDataBlockFactory *GetDataBlockFactoryElement(const CATUnicodeString &i_factoryName);
  CATSYPDataBlockFactory *GetDataBlockFactoryInstanceElement(const CATUnicodeString &i_factoryName);
  /**
   * Generate a model template from a string. 
   * @param i_templateAsString the string that represents the model template
   * @param i_assertOnErrors : determin if we assert on errors or not
   * @return the generated model template. 
   */
  CATSYPModelTemplate *GenerateTemplateFromString(const CATUnicodeString &i_templateAsString, int i_assertOnErrors = 1);

  CATSetOfCATUnicodeString GetStyleProcessorRelativeResourceFileStringList();
  CATSetOfCATUnicodeString GetStyleProcessorAbsoluteResourceFileStringList();
  /**
   * Generate a data block factory model from a string. 
   * @param i_datablockfactoryAsString the string that represents the model data block factory 
   * @return the generated model data block factory. 
   */
  CATSYPModelDataBlockFactory *GenerateDataBlockFactoryFromString(const CATUnicodeString &i_datablockfactoryAsString);

  /**
   * Method containing common code called in the constructor.
   * This method can be removed when MKCS supports C++11's constructor delegation (error LCDMNI1).
   */
  void init(CATSYPStyleProcessor::ParsingMode i_mode);

  private:
  /** The files that have been already parsed to extract templates*/
  CATSetOfCATUnicodeString _resourceFilesAbsolute;
  CATSetOfCATUnicodeString _resourceFilesRelative;
  /** The templates list*/
  CATSYPHashMap<CATSYPTemplateAttributes, CATSYPModelTemplate *> _templateList;
  /** The data templates list */
  CATSYPHashMap<CATSYPDataTemplateAttributes, CATSYPModelTemplate *> _dataTemplateList;
  /** An error report, created only during buidling time */
  CATSYPErrorReport *_pErrorReport;
  CATSYPResourcesFinder _finder;
  CATSYPStyleProcessor *_pParentStyleProcessor;
  CATSetOfCATUnicodeString _exclusionList;
  CATSetOfCATUnicodeString _exceptionList;
  CATSYPErrorReportFactory *_pErrorReportFactory;
  int _buildEmbeddedTemplatesFlag;
  CATSYPStyleProcessor::ParsingMode _mode;
  CATSYPModelBuilder *_pBuilder;
  int _loadTemplateWhenParsingFlag;
  CATSYPHashMap<CATUnicodeString, CATSYPModelDataBlockFactory *> _dataBlockFactoryList;
  CATSYPHashMap<CATSYPTemplateAttributes, CATUnicodeString> _aliasesMap;
  CATSYPHashMap<CATUnicodeString, CATSYPDataBlockFactory *> _dataBlockFactoryInstanceList;

  /** Model template overring flag, should a SYPStyleProcessor be allowed to override the model template of its parents ? */
  CATBoolean _bDataTemplateOverrideFlag;

  /**
   * @name Deprecated members
   */
  /*@{*/
  public:
  /** @deprecated */
  CATBaseUnknown_var Generate(CATBaseUnknown *i_pLeftObject, const CATUnicodeString &i_templateName);
  /*@}*/

  // for debug purpose, it allows to reload the D-Afr Style Processor from a debug panel.
  friend class CIDDebugReloadResourcesWidget;
  friend class VIDSaveCommand;
  friend class VIDOpenCommand;
  friend class VIDParseFile;
  friend class VIDDeclarativeFormatController;
  friend class VIDEditMenuManager;
  friend class UIScriptCtlSampleGallery;
  friend class CATSYPModelTagVisitorBuilder;
  friend class VIDScalabilityBehaviour;
  friend class CATVidStyleProcessor;
  friend class CATVidThemeManager;
};

#endif

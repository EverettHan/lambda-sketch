#ifndef CATSYPResourcesFinder_H
#define CATSYPResourcesFinder_H

#include <CATUnicodeString.h>
#include <CATStyleProcessor.h>
#include <CATSYPHashMap.h>
#include <CATSYPArray.h>
#include <CATBaseUnknown_var.h>
#include <CATSYPResourcesBuilder.h>
#include <CATSYPFactoryResult.h>
class CATSYPInputStream;
class CATSysZipFile;

/**
 * This class allows to find a resource in a path folder, or a zip file, and to create it,
 * by using resource builders.
 * Resource builders can be added by calling #AddResourceBuilder.
 * @see CATSYPResourcesBuilder
 */
class ExportedByCATStyleProcessor CATSYPResourcesFinder
{
public:
  /**
   * The path of the resource.
   *
   * It can be either the path of a regular file or the path of an
   * entry in a ZIP file.
   *
   * If it is the path of a regular file, then @ref #zipPath is empty
   * string and @ref #path is the path of the regular file.
   *
   * It it is the path of an entry of a zip file, then @ref #zipPath
   * is the path of the ZIP file and @ref #path is the path of the
   * entry inside the ZIP file.
   */
  struct ResourcePath {
    /**
     * The path of the zip file; an empty string if the resource is
     * not in a ZIP.
     */
    CATUnicodeString zipPath;
    /**
     * The path of the resource. The path in the ZIP if @ref #zipPath
     * is not empty, otherwise the path on the file system.
     */
    CATUnicodeString path;
  };

public:
  /** 
   * Density modes available for resource finding. 
   *
   * To add a resource of higher density mode, place it in the same folder than
   * the original resource and append the right suffix to the original resource
   * name before the extension. For instance:
   *
   * .../icons/image.png
   * .../icons/image@2x.png
   */
  enum DensityMode {
    /** Default density mode. Corresponds to a density of 1. Suffix for resource is empty string. */
    DM_Medium = 0,
    /** High-density mode (Retina). Corresponds to a density of 2. Suffix for resource is "@2x". */
    DM_XHigh
  };
  /**
   * @param i_density a desired density.
   * 
   * @return the available density mode that fits the density at best. 
   */
  static DensityMode DensityToDensityMode(float i_density);
  /**
   * @param i_densityMode any density mode.
   *
   * @return the corresponding density.
   */
  static float GetDensity(DensityMode i_densityMode);
  /**
   * @param i_densityMode any density mode.
   *
   * @return the corresponding suffix identifier.
   *
   * @see DensityMode
   */
  static const CATUnicodeString & GetSuffix(DensityMode i_densityMode);
  /** Number of density modes available. */
  static const int DM_Count = 2;
  /** 
   * Offers a mapping from density modes to indexes for tables.
   *
   * @return the index that corresponds to a given density mode in all 
   * density-related tables. 
   */
  static int GetDensityIndex(DensityMode i_densityMode);

	/**
	* Get flag that indicate if zip resource file is forced to be closed
	*/
	int GetForceCloseZipFlag() const;
private:
  /** Suffixes used to determine the density of a resource. */
  static const CATUnicodeString s_DensitySuffixes[DM_Count];
  /** Densities corresponding to density modes. */
  static const float s_Densities[DM_Count];
  /** Density modes available. */
  static const DensityMode s_DensityModes[DM_Count];

public:
  /** Constructor */
  CATSYPResourcesFinder();
  /** Destructor*/
  ~CATSYPResourcesFinder();
  /**
   * Sets the path folder list. Calling it will reset the current path list, and 
   * a current zip file if needed.
   * @param i_pathFolderList the list of absolute path to use to find resources, 
   * separarated by character ';'
   */
  void SetPathFolderList(const CATUnicodeString& i_pathFolderList);
  /**
   * @return the the list of absolute path to use to find resources, 
   * separarated by character ';'. Return an empty string if a zip file is used.
   */
  const CATUnicodeString& GetPathFolderList() const;
  /**
   * Sets the path of a zip file that will be used as resource folder.
   * Calling it will reset the current path list, and a current zip file if needed.
   * Asserts if the zip file is not found, or if opening the zip fails.
   * @param i_zipPath the path of the zip file to use.
   */
  void SetZipFilePath(const CATUnicodeString& i_zipPath);
  /**
   * @return the zip file path. empty string if no zip file is used.
   */
  const CATUnicodeString& GetZipFilePath() const;
  /**
   * Adds a resource builder, associated to a given CATBaseUnknown type.
   * The resource finder AddRef the builder, as a same builder can be used in several
   * finders.
   * Asserts if i_pBuilder is NULL, or i_type is an empty string.
   */
  void AddResourceBuilder(const CATUnicodeString& i_type, CATSYPResourcesBuilder* i_pBuilder);
  /**
   * @return the resource builder associated to the given type. Asserts if no builder is associated to type.
   */
  CATSYPResourcesBuilder* GetResourceBuilder(const CATUnicodeString& i_type) const;
  /**
   * Tries to build a resource if found and if an associated builder has been found.
   * @param i_type the CATBaseUnknown type to build
   * @param i_relativePath the relative path of the resource.
   * @param i_densityMode the density mode to use when building the resource (for eg. DM_XHigh).
   * @param o_pDensityModeFound a pointer to the density mode for which the resource has been found 
   * (for eg. @c DM_Medium if asked for @c DM_XHigh but no <tt>image@2x.png</tt> has been found, only <tt>image.png</tt>). 
   * @c NULL if the build fails.
   * @return the built object, or NULL_var if failed.
   */
  CATSYPFactoryResult Build(const CATUnicodeString& i_type, const CATUnicodeString& i_relativePath, DensityMode i_densityMode = DM_Medium, DensityMode * o_pDensityModeFound = NULL) const;
  /**
   * Get the path of the resource with the given name.
   *
   * This path is the one that @ref #Build function will use to build
   * the resource.
   *
   * @param i_relativePath the relative path of the resource. Can't be empty.
   *
   * @return the path. Empty path if resource is not found or if an
   * error occured (in that case a @ref FAILURE may have been raised).
   */
  ResourcePath GetResourcePath(const CATUnicodeString& i_relativePath) const;
  /**
   * Retrieve the absolute path for a given relative path.
   * @param i_relativePath the relative path.
   * @return the absolute path. Empty if not found.
   *
   * @deprecated
   * This function only works when using regular files, not ZIP
   * files. Use @ref #GetResourcePath instead.
   *
   * @see #GetResourcePath
   */
  CATUnicodeString FindPath(const CATUnicodeString& i_relativePath) const;
  /**
   * Tries to build a resource if found and if an associated builder has been found.
   * Asserts if the corresponding type is not  supported.
   * @param i_type the CATBaseUnknown type to build
   * @param i_absolutePath the absolute path of the resource.
   * @return the built object, or NULL_var if failed.
   */
  CATSYPFactoryResult BuildFromAbsolutePath(const CATUnicodeString& i_type, const CATUnicodeString& i_absolutePath) const;
  /**
   * Sets a list of sub pathes, separated by semicolon ";", defining a list of directories to find a resource.
   * If a resource is found in none of the sub directories, it is looked up in the root path.
   * @param i_subDirectoriesPathList the list of subdirectories used to find resources.
   */
  void SetSubDirectoriesPathList(const CATUnicodeString& i_subDirectoriesPathList);
  /**
   * @return the sub directories path list, separated by semicolon ";"
   */
  CATUnicodeString GetSubDirectoriesPathList() const;
private:
  /**
   * Tries to build a resource if found and if an associated builder has been found.
   * Asserts if the corresponding type is not  supported.
   * @param i_type the CATBaseUnknown type to build
   * @param i_pInputStream the stream containing the data.
   * @param i_size the size of the stream.
   * @return the built object, or NULL_var if failed.
   */
  CATSYPFactoryResult _BuildFromStream(const CATUnicodeString& i_type, CATSYPInputStream& i_pInputStream, int i_size) const;
  CATSYPFactoryResult _BuildFromAbsolutePath(const CATUnicodeString& i_type, const CATUnicodeString& i_absolutePath) const;
  void _BuildDensityMap();
	/**
	* Open zip file 
	*/
	void _OpenZip();

	/**
	* close zip file
	*/
	void _CloseZip();

	/**
	* @return the resources finder list
	*/
	static CATSYPDynArray<CATSYPResourcesFinder*> GetResourcesFinderList();

	/**
	* if (i_forceCloseFlag==true) Force close zip, else set force close zip flag 
	*/
	void SetForceCloseZipFlag(const int i_forceCloseFlag);

private:
  CATSYPDynArray<CATUnicodeString> _subDirectoriesPathList;
  CATUnicodeString _pathFolderList;
  CATUnicodeString _zipFilePath;
  CATSysZipFile* _pZipFile;
  CATSYPHashMap<CATUnicodeString, CATSYPResourcesBuilder*> _resourceBuilderMap;
	static CATSYPDynArray<CATSYPResourcesFinder*> _s_resourcesFinderList;
	int _forceCloseZipFlag;

	friend class CATVidFraWindowManager;
};
#endif

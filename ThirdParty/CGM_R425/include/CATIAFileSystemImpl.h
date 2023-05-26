#ifndef CATIAFileSystemImpl_h
#define CATIAFileSystemImpl_h

// COPYRIGHT DASSAULT SYSTEMES 2002

// System framework
#include "CATBaseUnknown.h"
#include "CATBaseObject.h"
#include "CATBaseDispatch.h"

// + qay 2008:07:17 InfInterfaces split 
#include "InfOSIDLImpl.h"

// + jbx 2010:06:22 Convergence CAT_VARIANT_BOOL
#include "CAT_VARIANT_BOOL.h"

// InfInterfaces framework
class CATIAFolder;
class CATIAFile;
class CATIAApplication;
class CATIAFileSystem;

// CATIAApplicationFrame framework
class CATIAFolderImpl;

/**
 * Class to implement the CATIAFileSystem interface
 * @author Michel Chollet (MCF)
 */
class ExportedByInfOSIDLImpl /* + qay 2008:07:17 InfInterfaces split */ CATIAFileSystemImpl : public CATBaseObject {
		CATDeclareClass;
	public:
		/**
		 * Destructor
		 */
		virtual ~CATIAFileSystemImpl();

		// Overriding CATBaseObject default implementation of CATIABase
		virtual HRESULT __stdcall  get_Parent(CATBaseDispatch *& oParent);

		// Implementation of the CATIAFileSystem interface
		virtual HRESULT GetFolder(
			const CATBSTR & iPath,
			CATIAFolder *& oFolder);

		virtual HRESULT CopyFolder(
			const CATBSTR & iPathSource,
			const CATBSTR & iPathDestination);

		virtual HRESULT CreateFolder(
			const CATBSTR & iPath,
			CATIAFolder *&	oFolder);

		virtual HRESULT DeleteFolder(
			const CATBSTR & iPath);

		virtual HRESULT FolderExists(
			const CATBSTR & iPath,
			CAT_VARIANT_BOOL & oExists);

		virtual HRESULT GetFile(
			const CATBSTR & iPath,
			CATIAFile *& oFile);

		virtual HRESULT CopyFile(
			const CATBSTR & iPathSource,
			const CATBSTR & iPathDestination,
			CAT_VARIANT_BOOL iOverwrite);

		virtual HRESULT CreateFile(
			const CATBSTR & iPath, 
			CAT_VARIANT_BOOL iOverwrite, 
			CATIAFile *& oFile);

		virtual HRESULT DeleteFile( 
			const CATBSTR & iPath );

		virtual HRESULT FileExists(
			const CATBSTR & iPath,
			CAT_VARIANT_BOOL & oExists); 

		virtual HRESULT __stdcall get_TemporaryDirectory(
			CATIAFolder *& oTmpDirectory);

		virtual HRESULT __stdcall get_PathSeparator(
			CATBSTR & oPathSeparator);

		virtual HRESULT __stdcall get_FileSeparator(
			CATBSTR & oFileSeparator);

		virtual HRESULT __stdcall ConcatenatePaths(
			const CATBSTR & iPathChunk1, 
			const CATBSTR & iPathChunk2, 
			CATBSTR & oPath);
		
		/**
		 * Factory method
		 */
		static HRESULT CreateFileSystem( CATIAFileSystem *& oFileSystem );

	private:
		/**
		 * Constructor
		 */
		CATIAFileSystemImpl();

		/**
		 * Invoked by CATCallOnExit to remove the last reference to the root folder.
		 */
		static int _Cleanup (int iRc );

	private:
		static CATIAFileSystemImpl* _fileSystemImpl;
		static CATIAFolderImpl * _globalRootFolderImpl;
		CATIAFolderImpl * _rootFolderImpl;
};

#endif // CATIAFileSystemImpl_h

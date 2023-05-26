/**
@file

@COPYRIGHT

This file defines the vkAsset class.

@author Gerald Guyomard
*/

#if !defined(__vkAsset_h)
#define __vkAsset_h

#include "vkArray.h"
#include "vkHash.h"
#include "vkEventsListener.h"
#include "vkSmartPtr.h"
#include "vkResource.h"
#include "vkEvent.h"

namespace VKernel
{
	class vkContext;
	class vkAssetSerializationContext;
	class vkAssetCopyParams;
	
	class vkManifest;
	typedef vkSmartPtr<vkManifest> vkManifestPtr;

	class vkAsset;
	typedef vkRefPtr<vkAsset> vkAssetPtr;

	/**
	vkAsset is an abstract base class defining a collection of resources
	stored on disk (an asset = a file).

	@ingroup grp_resource
	*/
	class VKKERNEL_API vkAsset : public vkEventsListener
	{
	
	public:
		VK_DECLARE_RTTI_OBJECT(vkAsset, vkEventsListener);

		/**
		Destructor
		*/
		virtual ~vkAsset();

		// Overridden from vkEventsListener
		virtual bool	HandleEvent(vkEvent& ioEvent);
		virtual bool	DispatchEvent(vkEvent& ioEvent);

		/**
		Some flags used to customize asset registration.
		This flags are used in vkResourceManager::LoadAsset
		*/
		enum FLoadingFlags
		{
			/** Process the asset after load */
			fProcessAsset			= 1 << 0,

			/** During dependency computing, consider the dependency as explicit */
			fExplicitDependency		= 1 << 1,

			/** Make sure the asset is reloaded from scratch */
			fForceReload			= 1 << 2,

			/** Disable manifest checking when loading the asset */
			fIgnoreManifest			= 1 << 3,

			/** Disable configuration checking when loading the asset */
			fIgnoreConfiguration	= 1 << 4,

			/** Do not add the created asset as a dependency of the parent asset */
			fCreateNoDependency		= 1 << 5,

			/** Force the loaded resources to be ready */
			fForceReady				= 1 << 6,			

			/** Do not create instances from prototypes */
			fNoDuplicatingPrototype	= 1 << 7,		

			/** */
			fDefaultLoadingFlags	= fProcessAsset,

			/**  */
			fAllLoadingFlags		= fProcessAsset | fExplicitDependency
		};

		/**
		Initializes the asset.
		Override _Construct to implement custom inits
		@return Error code.
		
		*/
		error	Create();

		/**
		Tells if the asset is being loaded.
		@return 
		True if load in progress.
		*/
		bool	IsBeingLoaded() const;

		/**
		Tells if the asset is being destroyed.
		@return 
		True if destroy in progress.
		*/
		bool	IsBeingDestroyed() const;

		/**
		Tells if the asset is being reloaded.
		Note that IsBeingLoaded also returns true
		when IsBeingReloaded is true
		@return true if reload in progress.
		*/
		bool	IsBeingReloaded() const;

		/**
		Tells if the asset is loaded.
		@return 
		True if loaded.
		*/
		bool	IsLoaded() const;

		/**
		Tells if the asset is processed.

		Processing an asset is always done after having loaded it.
		Default implementation strictly does nothing but derived classes may
		perform particular actions like sort of compilation.
		@return 
		True if processed.
		@see Process
		*/
		bool	IsProcessed() const;

		/**
		Tells if the asset backups itself before a save.
		@return true if this asset is backuping
		@see SetReadOnly
		*/
		bool	IsBackuping() const;

		/**
		Makes the asset backuping itself before a save.
		@param iBackuping if true then backup is enabled, otherwise it backup is disabled.
		*/
		void	SetBackuping(bool iBackuping = true);

		/**
		Tells if the asset is dirty.

		A dirty asset occurs when its content (list of resources) is not synchronized
		with its file on disk anymore.
		@return 
		True if dirty.
		@see SetDirty
		*/
		bool	IsDirty() const;

		/**
		Changes the dirty flag.

		This method is only used to force dirtyness state (for example, when a resource
		becomes dirty).
		Adding/Removing resources dirtify the asset automatically.
		@param iDirty if true, then the asset is flagged dirty, clean otherwise.
		*/
		void	SetDirty(bool iDirty = true);

		/**
		Resets the last modification time of the asset.
		After this call, IsUpToDate() returns false.
		*/
		void ResetLastModificationTime();
				
		/**
		Tells if the asset is a system asset (read only and no configuration can be created).
		@return true if asset is system
		*/
		bool IsSystem() const;

		/**
		Flags this asset as being system. 
		By flagging this asset as system, it becomes read only and not configurable
		and thus is no more editable.
		@param iEnable true to set the asset as system
		@return true if the flag value has changed
		*/
		bool SetAsSystem(bool iEnable);

		/**
		Tells if the asset can be edited (create a configuration or modified).
		@return true
		*/
		bool IsEditable() const;
			
		/**
		Tells if the asset will always be loaded and therefore it is not necessary to save resources refs with its URI.
		Default returns false, overridden in a few modules (vkKernel, vkObjectModel, ...)
		*/
		virtual bool IsImplicit();

		/**
		Tells if saving this kind of asset has been implemented.
		Default implementation return false.
		When implementing save, you must both override IsSaveImplemented and _Save.
		@return true if save is implemented.
		*/
		virtual bool	IsSaveImplemented() const;

		/**
		Processes a loaded asset.

		An asset can only be processed once and works only on loaded assets.

		@param iProgress a progress indicator for processing progress (optional).

		@return Error code.

		@see _Process
		*/
		error			Process();

		/**
		Gets the number of resources.
		@return 
		The number of resources.
		*/
		uint32								GetResourceCount() const;

		/**
		Gets the resource at position iIndex in the internal cache
		@return 
		The resource  #iIndex or 0 if iIndex out of range.
		*/
		vkResource*							GetResource(uint32 iIndex) const;

		/**
		Gets all the resources.
		@return 
		The array of resources.
		*/
		const vkArray<vkResourcePtr>&			GetResources() const;

		/**
		Tells if this asset contains at least one resource of the specified type.
		If the specified is not kind of a resource, then the non-resource objects
		will be inspected by analyzing possible resource adapters.
		@param iType the type of the objects to test
		@return true if this asset has one resource of the chosen type
		*/
		bool HasResourceOfType(const vkType* iType) const;

		/**
		Gets all the resources of the specified type.
		@param iObjectType the type of the resources to extract.
		If this type does not describe a resource, then the adapters will
		will be inspected to extract the objects of this type.
		@param oResources in output, the resources of the particular type.
		@param iGetOnlyRelevantResources if true then only the resources with ID and
		non local to this asset are got.
		Note the array is not emptied before adding the resources.
		*/
		void GetResourcesByType(const vkType* iObjectType, vkArray<vkResourcePtr>& oResources, bool iGetOnlyRelevantResources = false) const;
		template <class TResourceType>
		void GetResourcesByType(vkArray<vkSmartPtr<TResourceType> >& oResources, bool iGetOnlyRelevantResources = false) const;

		/**
		Gets the resource with ID iResourceID
		@param iResourceID the ID of the resource to find.
		@param iCategory the category. If invalid, then this parameter is not discriminant
		@param iType if not null, then the resource must match this type
		@return The resource to find.
		*/
		//@{
		vkResource*							GetResource(const vkString& iResourceID, vkResourceCategory iCategory = kInvalidResourceCategory, const vkType* iResourceType = 0) const;
		template <class T> T*				GetResource(const vkString& iResourceID, vkResourceCategory iCategory = kInvalidResourceCategory) const;

		template <class T> T*				GetResource() const; 

		//@}

		/**
		Removes all the resources but do not destroy them.
		*/
		void								RemoveAllResources();

		/**
		Unregisters only the local resources from the resource manager.
		*/
		void								UnregisterLocalResources();

		/**
		Destroys all the resources.
		*/
		void								DestroyAllResources();

		/**
		Sets all the resources as obsoletes.
			- removed from the resource manager
			- removed from the asset
		*/
		void								SetObsoleteAllResources(vkAssetSerializationContext* iContext);
		
		/**
		Tells if the resource iResource can be added to the asset.

		Default implementation is accepting any kind of resources.
		@param iResource the resource to test. Cannot be null.
		@return True if accepted.
		*/
		virtual bool						IsAcceptingResource(vkResource* iResource) const;

		/**
		Search in the asset.

		@param iStr the string to search
		@param iMatchCase search with case sensivity
		@param iWholeWord search the whole word (i.e. " " + iStr + " " )
		@param iRegExp search using a regular expression
		
		virtual vkArray<vkSearchResult>		Search(vkString iStr, bool iMatchCase, bool iWholeWord, bool iRegExp);
		*/

		/**
		Returns the channel where listeners can be hooked to be notified on particular events
		related to this asset.
		@return the events channel
		*/
		vkEventsChannel&					GetEventsChannel();
		

		/**
		Some flags to be passed to Notify method.
		@see Notify
		*/
		enum FNotificationFlags
		{
			/* This asset is notified*/
			fNotifyThisAsset			= 1 << 0,

			/* The listeners connected the type of the event ton sent are notified*/
			fBroadcast					= 1 << 1,

			/* Direct dependencies are notified */
			fNotifyDirectDependencies	= 1 << 2,

			/* All dependencies are notified */
			fNotifyAllDependencies	= fNotifyDirectDependencies | 1 << 3,

			/* Direct users are notified */
			fNotifyDirectUsers		= 1 << 4,

			/* All users are notified */
			fNotifyAllUsers			= fNotifyDirectUsers | 1 << 5,

			/* Default flags notifies everyone */
			fDefaultNotificationFlags = fNotifyThisAsset | fBroadcast | fNotifyAllDependencies | fNotifyAllUsers,
		};

		/**
		Sends an event to objects indicated by FNotificationFlags
		@param ioEvent the event to send
		@param iNotificationFlags a combo of FNotificationFlags
		@param iStopIfHandled if true then the notification stops when an object handled this event
		@return true if someone handled the event
		*/
		bool Notify(vkEvent& ioEvent, uint32 iNotificationFlags = fDefaultNotificationFlags, bool iStopIfHandled = false);


		/**
		Tells if this asset is unresolved.
		*/
		bool		IsUnresolved() const;

		/**
		Marks this asset as unresolved.
		This method should only be called by the resource manager when detecting unresolved reference
		@param IsUnresolved if specified then the resource will be marked as unresolved
		*/
		void		SetUnresolved(bool iUnresolved);

		/**
		Tells if this asset is protected, i.e it cannot 
		be saved or copied.
		*/
		bool		IsProtected() const;

		/**
		Tells if the asset can register types in its life cycle.

		Assets registering types are the only ones allowed
		to call vkType::BeginRegisteringAsset()

		@return true if the asset can register types
		*/
		bool		CanRegisterTypes() const;

		virtual void Destroy();

	protected :
		friend class vkResource;
		friend class vkAssetFactory;

		// Override from vkRefPtrObject
		virtual error	_Construct();
		virtual void	_Destroy();

		/**
		Adds a new resource in the internal array cache.
		@param iResource the resource to add.
		*/
		virtual void	_RegisterResource(vkResource* iResource);

		/**
		Removes a resource from the internal array cache.
		@param iResource the resource to remove.
		*/
		virtual void	_UnregisterResource(vkResource* iResource);

		void			_UnregisterTypes();

		/**
		Default Constructor
		*/
		vkAsset(vkCtx iCtx);
		
		/**
		Loads the asset from disk
		An asset can only be loaded once. Successive calls to Load() returns errOk.
		If an asset is touched on disk, the nex call to Load will reload this asset.
		@param iContext a serialization context
		@return Error code.
		@see _Load
		*/
		error			Load(vkAssetSerializationContext& iContext);

		void			_SetLoaded(bool iLoaded);

		virtual void	_ReadyResources();

		void _SetCanHaveCyclicDeps(bool iValue);
		bool _CanHaveCyclicDeps();

	private :		
		friend class vkModule;

		bool	_Notify(vkEvent& ioEvent, uint32 iNotificationFlags, bool iStopIfHandled,vkArray<vkAsset*>& ioNotifiedAssets);
		bool	_NotifyNoTargetSet(vkEvent& ioEvent, uint32 iNotificationFlags, bool iStopIfHandled,vkArray<vkAsset*>& ioNotifiedAssets);
		

		void _RecurseGetListOfAssetDependantOn(vkAsset* iAsset, vkArray<vkAsset*>& ioAssets, vkArray<vkAsset*>& ioAlreadyTestedAssets);


		enum FAssetFlags
		{
			/**  */
			fIsBeingLoaded			= 1 << 0,

			/**  */
			fIsBeingReloaded		= fIsBeingLoaded | 1 << 1,

			/**  */
			fIsLoaded				= 1 << 2,
			
			/**  */
			fIsProcessed			= 1 << 3,

			/** The version in memory is different from what we have on disk. */
			fIsDirty				= 1 << 4,

			/* The asset cannot be modified on disk */
			fIsReadOnly				= 1 << 5,

			/* The asset tries to reload itself when its file is touched on disk */
			fIsReloadedOnUpdate		= 1 << 6,

			/* The asset backup itself before save */
			fEnableBackup			= 1 << 7,

			/* The asset needs the category of the resource to know what it should create */
			fMustSaveCategory		= 1 << 8,

			/** A configuration can have been created on this asset created */
			fCanBeConfigured		= 1 << 9,

			/** A configuration must be created when editing this asset */
			fMustBeConfigured		= 1 << 10 | fCanBeConfigured,

			/** The implementation of this asset is not "reload" compliant */
			fIsNotReloadable		= 1 << 11,

			/** The asset is unresolved (it failed loading) */
			fIsUnresolved			= 1 << 12,

			fCanHaveCyclicDeps		= 1 << 13,
						
			/** Asset is being destroyed */
			fIsBeingDestroyed		= 1 << 14,

			/** Asset is protected */
			fIsProtected			= 1 << 15,

			/** Asset can register some types */
			fCanRegisterTypes		= 1 << 16,

			/** The asset is system, it cannot be edited nor configured */
			fIsSystem				= 1 << 17,

			fLastFlag				= 1 << 18,
			fDefaultFlags			= fIsReloadedOnUpdate,			
		};
		uint32						m_Flags;


		// Asset containing the manifest
		vkAssetPtr					m_ManifestAsset;

		// List of the resource contained in this asset
		vkArray<vkResourcePtr>		m_Resources;

		// channel of listeners to be notified when broadcasting an event
		vkEventsChannel				m_EventsChannel;

	};

	// Inlined Implementations
	#include "vkAsset.hpp"
}

#endif // __vkAsset_h



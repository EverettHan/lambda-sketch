/**
@file

This file defines the vkResource class.

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkResource_h)
#define __vkResource_h

#if !defined(__vkKernelLib_h)
#include "vkKernelLib.h"
#endif
#if !defined(__vkKernelEnums_h)
#include "vkKernelEnums.h"
#endif
#if !defined(__vkString_h)
#include "vkString.h"
#endif
#if !defined(__vkRefPtr_h)
#include "vkRefPtr.h"
#endif
#if !defined(__vkSmartPtr_h)
#include "vkSmartPtr.h"
#endif
#if !defined(__vkMutex_h)
#include "vkMutex.h"
#endif
#if !defined(__vkRTTI_h)
#include "vkRTTI.h"
#endif
#if !defined(__vkError_h)
#include "vkError.h"
#endif

namespace VKernel
{

	class vkAsset;
	typedef vkRefPtr<vkAsset> vkAssetPtr;
	class vkXMLLoadArgs;
	class vkAssetSerializationContext;
	class vkProgress;
	
	class vkResource;
	typedef vkSmartPtr<vkResource> vkResourcePtr;
	
	/**
	Scope of the resource.

	@ingroup grp_resource
	*/
	enum EResourceScope
	{
		/** the resource is registered in the resource manager forever (or until explicit call to Destroy). */
		eResourceIsGlobal,	
		
		/** The resource is unregistered from the resource manager when its asset finished loading. */
		eResourceIsLocalToAsset,

		/** Same behavior as eResourceIsLocalToAsset, and more, the resource ID is temporary and cleared
		after having read or written the asset*/
		eResourceIsVolatile
	};

	/**
	The resource category is a way to classify the resources in global
	families (UI, Behavioral, texture, image, audio...).

	This is part of the unique identification of a resource.

	@ingroup grp_resource
	*/
	typedef uint8 vkResourceCategory;
	
	enum {
		kInvalidResourceCategory = 0xff
	};

	enum {
		kResourceAlwaysUsed = 0xffffffff
	};

	/**
	Initializer of vkCtxObject<vkResourceCategory>
	@see vkCtxObject
	*/
	template <>
	struct vkCtxObjectInitFunction<vkResourceCategory>
	{
		VK_INLINE static void Construct(vkResourceCategory* iDst)
		{
			*iDst = kInvalidResourceCategory;
		}

		VK_INLINE static void PostConstruct(vkResourceCategory& iDst)
		{
			iDst = kInvalidResourceCategory;
		}

		VK_INLINE static void Destruct(vkResourceCategory* iDst)
		{
			*iDst = kInvalidResourceCategory;
		}
	};

	
	/**
	vkResource is the base class for all resources.

	A resource is an object that can be globally referenced in
	the resource manager.

	A resource is identified by two keys : its category (vkResourceCategory), and its
	resource ID (a string). This pair is unique.
	On most cases, a resource comes from an asset.

	@see vkAsset, vkResourceManager

	@ingroup grp_resource
	*/
	class VKKERNEL_API vkResource : public vkSmartPtrObject
	{
	
	friend class vkKernelModule;
	friend class vkResourceType;
	friend class vkAsset;
	public :
		VK_DECLARE_RTTI_OBJECT(vkResource, vkSmartPtrObject);


		/** Default Constructor where you can specify the vkResourceCategory
		of the created resource */
		vkResource(vkCtx iCtxHandle, vkResourceCategory iCategory = kInvalidResourceCategory, uint32 iFlags = fIsInCache);

		/** Copy Constructor */
		vkResource(const vkResource& iSrc);

		/** Destructor */
		~vkResource();

		// Overridden from vkObject
		virtual const vkString& GetObjectID() const;
		/**
		Sets the ID of the resource.
		@param iID the new resource ID
		@return error code
		@see SetResourceID
		*/
		virtual error SetObjectID(const vkString& iObjectID);

		/**
		Tells if this resource is editable.
		Resource which results of a configuration or
		with an asset having a configuration.
		@return true if it's editable.
		*/
		virtual bool IsEditable() const;
		
		
		/**
		Creates an editable object. The modifications are made in place
		@param oEditableObject contains the newly created object.
		*/
		virtual error GetEditableObject(vkVariant& oEditableObject);

		/**
		Overridden from vkSmartObject
		*/		
		virtual error	Replace(const vkSmartPtrObject* iNewObject);

		/**
		TODO
		*/
		EResourceScope	GetResourceScope() const;

		/**
		TODO
		*/
		void			SetResourceScope(EResourceScope iScope);


		/**
		Gets the category of the resource.
		 the resource category is used with the resource id to have
		a unique identifier.
		@return 
		The resource category.
		@see GetResourceID
		*/
		vkResourceCategory GetResourceCategory() const;

		/**
		Gets the ID of the resource.
		 the resource ID is used with the resource category to have
		a unique identifier.
		@return 
		The resource ID.
		@see GetResourceCategory, SetResourceID
		*/
		const vkString&				GetResourceID() const;

		/**
		Sets the ID of the resource.
		@param iID the new resource ID
		@return error code
		@see GetResourceID
		*/
		virtual error				SetResourceID(const vkString& iID);

		/**
		Gets a plain text description of the resource.
		This is generally used for UI purpose.
		Default implementation returns the built-in Description.
		@return true if it's registered.
		@see GetBuiltInDescription
		*/
		virtual vkString GetDescription() const;


		/**
		Tells if this resource is registered in the resource manager.
		@return true if it's registered.
		*/
		bool IsRegistered() const;

		/**
		Tells if this resource was registered in the resource manager
		just before becoming obsolete.
		WasRegistered implies IsObsolete
		@return true if it's registered.
		*/
		bool WasRegistered() const;

		/**
		Gets the asset storing this resource.
		@return the asset.
		*/
		vkAsset*				GetAsset() const;

		/**
		Sets the asset storing this resource.

		@param iAsset the new asset.
		@param iRegisterInAsset if true, then the asset stores a resource reference in its internal cache.
		iRegisterInAsset = false is mainly used for internal reasons. Do not use it unless really needed.
		
		@return error code
		*/
		virtual error SetAsset(vkAsset* iAsset, bool iRegisterInAsset = true);

		/**
		Gets the memory used by the resource.
		@param iSelfSize if true, then memory only used by the resource is taken into account.
		@param iDependencies if true, then memory used by dependencies is also taken into account.
		@return the size in bytes of the occupation.
		*/
		virtual uint32					GetMemoryOccupation(bool iSelfSize = true, bool iDependencies = false) const;

		/**
		Gets the prefix of all ID generated by default implementation
		of GenerateResourceID. It's a random string to ensure unique ID generation.
		*/
		static const vkString&			GetPrefixID();

		/**
		Returns whether the resource is ready to be used.
		A resource needs to be ready to be used. For example a texture
		needs to be present in video memory, a VSL script to be compiled, etc..
		*/
		bool							IsReady() const;
		
		/**
		Sets whether resource should be ready or not.
		A resource needs to be ready to be used. For example a texture
		needs to be present in video memory, a VSL script to be compiled, etc..
		When a resource is not ready it can free any memory it used. For example 
		a texture which becomes not ready, removed its data from video memory.

		If a cache behavior has been specified, calling SetReady ensures the resource
		is placed in the desired cache.
		*/
		error							SetReady(bool iReady);

		/**
		Returns whether the resource is in the expected caches.
		@see SetInCache
		*/
		bool							IsInCache() const;

		/**
		Ensures the resource is loaded or unloaded from its caches.
		@see IsInCache
		*/
		error							SetInCache(bool iInCache);

		/**
		Tells if this resource is obsolete.
		An obsolete resource is a resource that was replaced by a new one
		when its asset has been reloaded.
		@return true if the resource is obsolete
		*/
		bool							IsObsolete() const;

		/**
		Marks this resource as obsolete.
		This method should only be called by asset implementations
		when being reloaded.
		@param iContext if specified then the resource will be removed from in this context,
		otherwise it's removed from the standard resource manager
		*/
		void							SetObsolete(vkAssetSerializationContext* iContext = 0);

		/**
		Tells if this resource is unresolved.
		An unresolved resource is a resource that was created after failing to resolve
		a reference on a resource. This kind of resource has the type desired by the uri
		but is created empty.
		*/
		bool							IsUnresolved() const;

		/**
		Marks this resource as unresolved.
		This method should only be called by the resource manager when detecting unresolved reference
		@param IsUnresolved if specified then the resource will be marked as unresolved
		*/
		void							SetUnresolved(bool iUnresolved);

		bool							IsConfigured() const;
		bool							CanBeConfigured() const;


		/**
		Clones this resource.
		The implementation relies on CopyContext's clone system.
		@param oClone in output, the cloned object
		@return error code
		*/
		error Clone(vkResourcePtr& oClone, uint32 iCopyOptions = eCopyNewInstance);


		/**
		Defines the reference string on a null resource.
		Litteral value is "#null"
		*/
		static const vkString kNullRef;

		/**
		Returns if this resource was duplicated and configured from another resource.
		
		This method only returns true if the resource was duplicated from an other existing
		resource before if was configured.
		If an existing resource was simply modified by a configuration, this method returns false.
		@see vkResourceConfiguration
		*/
		bool		IsResultOfAConfiguration() const;

	protected:

		////////////////////////////////////////////////////////////////////////////////
		// types

		enum FFlags {
			fIsRegistered		= 1 << 0,
			fIsLocal			= 1 << 1,
			fIsVolatile			= fIsLocal | 1 << 2,
			fIsReady			= 1 << 3,	// Resource is currently ready to be used
			fIsInCache			= 1 << 4,	// Resource is stored in a cache (system memory 	
			fIsDynamic			= 1 << 5,	// Resource is likely to be modified once readied
			fIsBeingPrefetched	= 1 << 6,	// Resource is being ready by a asynchronous operation 
			fIsOptional			= 1 << 7,	// Do not generate an error if this resource is not found when loaded	
			fIsTracked			= 1 << 8,	// Created resource will be tracked in its corresponding ResourceIndex
			fIsConfigured		= 1 << 9,	// This resource is configured.
			fIsResultOfConfig	= fIsConfigured | 1 << 10,
			fIsObsolete			= 1 << 11,	// This resource no longer belongs to an asset and was replaced by a new resource in the asset
			fWasRegistered		= fIsRegistered | fIsObsolete, // This resource was registered just before becoming obsolete

			fLoadPolicyShift	= 12,		// reserved bits for load policy behavior ( 2 bits) 
			fLoadPolicyMask		= 3 << 12,  // reserved bits for load policy behavior
			fIsUnresolved		= 1 << 14,
			fIsBeingReadied		= 1 << 15
		};


		/**
		Overridden from vkSmartObject
		*/		
		virtual void					_Destroy();

		/**
		Updates the resource ID.
		@param iID the new resource ID.
		*/		
		virtual error					_SetResourceID(const vkString& iID);

		/**
		Updates the internal pointer of the asset.
		@param iAsset the asset.
		*/		
		virtual error					_SetAsset(vkAsset* iAsset);

		/**
		Remove a reference on this in the internal cache of iAsset.
		@param iAsset the asset where to unregister the resource.
		*/		
		void							_UnregisterFromAsset(vkAsset* iAsset);

		void							_SetIsRegistered(bool iIsRegistered);

		virtual error					_SetReady(bool iReady);
		virtual error					_SetInCache(bool iInCache);



	protected:
		// members

		/** Resource ID */
		vkString			m_ResourceID;
		/** Asset owning the resource */
		vkAsset*			m_Asset;
		/** Flags */
		uint16				m_RscFlags;
		/** Priority */
		uint8				m_PriorityMask;
		/** Resource Category */
		vkResourceCategory	m_ResourceCategory;

		vkReentrantFastMutex m_Mutex;

	private:

		static vkString					s_PrefixIDString;

	}; // vkResource

	
}

#endif // __vkResource_h

#if !defined(__vkResource_hpp)
#include "vkResource.hpp"
#endif


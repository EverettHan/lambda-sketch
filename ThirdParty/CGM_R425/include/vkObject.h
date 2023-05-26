/**
@file

This file defines the vkObject class.
This class is the common ancestor between RefPtrObjects and SmartPtrObjects 
(Components and resources)

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkObject_h)
#define __vkObject_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkRTTI_h)
	#include "vkRTTI.h"
#endif
#if !defined(__vkContext_h)
	#include "vkContext.h"
#endif
#if !defined(__vkHeapObject_h)
	#include "vkHeapObject.h"
#endif


namespace VKernel
{
	// Forward declaration
	class vkVariant;

	// A UI singleton that will provide
	// display information about objects
	class vkObject;

	//-------------------------------------------------------------------------------
	/**
	vkObject is the base class for both resources and components.
	
	It defines the base virtual member functions that should be overridden to:
		- Perform initialization of an object after it is allocated (_Create)
		- Perform cleaning before an object is deleted (or because it has been explicitly asked though 
		the Destroy() method)
		- Perform copy of the object content (ConfigureFrom)
		- Perform creation of the object given an existing object (CreateFrom)
		- Compute the memory occupied by the object (GetMemoryOccupation)
	*/
	//-------------------------------------------------------------------------------
	class VKKERNEL_API vkObject : public vkRTTIObject
	{
	
	friend class vkKernelModule;
	public :
		//-------------------------------------------------------------------------------
		/**
		vkObject Copy options.
		When copying a list of objects, the way references to other objects are handled
		is specified with these options. 
		It can be used to specify whether a copied object should keep pointing on the same 
		references or if it should copy the referenced objects along.
		@see vkObject::GetCopyOptions
		*/
		//-------------------------------------------------------------------------------
		enum ECopyOptions {			
			eCopyUseGlobalSettings = 0,	/*!< Only valid with the vkObject:SetCopyOptions method. 
										The copy context contains the global settings for each type of object */
			eCopyNewInstance,			/*!< Create a new instance of the object with the
										copied data (This is the default global option for components ) */
			eCopyReference,				/*!< If possible, keep a reference to this same object
										(This is the default global option for resources ) */
			eCopyGhost,					/*!< If possible, create a single object that
										has the same representation without duplicating its dependencies */
			eCopyOptionMask		= 0x3,	/*!< */
			eCopyOptionBitCount	= 2,	/*!< Number of bit to represent this option. */
		};
		// \cond
		VK_DECLARE_RTTI_ABSTRACTTYPE(vkObject, vkRTTIObject);
		// \endcond

		//-------------------------------------------------------------------------------

		/**
		Returns the number of references on this object.
		@return the number of references.
		*/
		virtual int32	GetReferenceCount() const = 0;

		/**
		Tells if this object is referenced.
		This is equivalent to GetReferenceCount() > 0.
		@return true if this object is referenced
		*/
		bool32 IsReferenced() const;

		/**
		Gets the ID of this object.
		Default implementation returns the null string (VK_NS)
		@return the ID
		*/
		virtual const vkString& GetObjectID() const;

		/**
		Sets the ID of this object.
		Default implementation returns errNotImplemented
		@param iObjectID the new ID of the object
		@return error code
		*/
		virtual error SetObjectID(const vkString& iObjectID);

		/**
		Gets the display name of this object
		Default implementation returns the object id
		*/
		virtual vkString GetObjectDisplayName() const;

		/**
		Destroys explicitly this instance.
		This method must prepare the destruction and then call _Destroy.
		*/		
		virtual void Destroy() = 0;

		//-------------------------------------------------------------------------------
		/**
		Gets the memory used by the object.
		@param iSelfSize if true, then memory used by the vkObject class itself is taken into account.
		@param iDependencies if true, then memory used by dependencies is also taken into account.
		@return the size in bytes of the occupation.
		*/
		//-------------------------------------------------------------------------------
		virtual uint32	GetMemoryOccupation(bool32 iSelfSize = true, bool32 iDependencies = false) const;

		/**
		Returns the copy options of this specific object.
		@See ECopyOptions
		*/
		virtual uint32	GetCopyOptions() const;

		/**
		Sets the copy options of this specific object.
		@See ECopyOptions
		*/
		virtual void	SetCopyOptions(uint32 iCopyOptions);

		/**
		Tests if the instance's class equals or derives from the class
		whose type is iType
		@param iType the type of the class to compare with this instance
		@return true if class(instance) == OR derives from class(iType)
		*/
		bool32			IsKindOfByType(const vkType* iType) const;

		/**
		Sets/unsets an object as a prototype.
		@param iPrototype if true this method sets the prototype flag to this object. 
		If false the prototype flag is cleared from this object.
		*/
		void SetAsPrototype(bool32 iPrototype);

		/**
		Returns whether an object is a prototype.
		@return If true this object is a prototype that is not to be used, displayed in any global context or manager
		*/
		bool32 IsPrototype() const;

		/**
		Marks the object as visible or hidden in authoring mode.
		*/
		void							SetHiddenInAuthoring(bool32 iHidden);
		
		/**
		Returns whether the object should be hidden in authoring mode.
		*/
		bool32							IsHiddenInAuthoring() const;

		/**
		Marks the object as to be saved or ignored during serialisation.
		false : saved
		true : not saved
		*/
		void							SetTransient(bool32 iTransient);

		/**
		Returns whether the object should be saved.
		@see 
		*/
		bool32							IsTransient() const;

		/**
		Tells if this object can be edited as is.
		@return true if the object is editable
		*/
		virtual bool IsEditable() const;

		/**
		Gets an editable version of this.
		The returned object can be different from this
		and created on the fly.
		To get the editable object if the final pointed form, use vkVariant::GetPointedObject<TType>()
		@param oEditableObject in output, this object or a proxy that can be edited
		@return error code
		*/
		virtual error GetEditableObject(vkVariant& oEditableObject);
		
// \cond

		/**
		Defines the ID for referencing null object.
		Litteral value is "null"
		*/
		static const vkString kNullID;

		vkArray<uint32>			m_Tags;


		//@{
		/**
		Constructors
		*/
		vkObject(vkCtx iHandle);
		vkObject(const vkObject& iSrc);
		//@}


		/**
		Returns a generic handle to the context of this object
		*/
		vkCtx		GetCtx() const;

		/**
		Returns the context of this object
		*/
		vkContext*	GetContext() const;

		/**
		Ensures the input identifier is valid

		ID with characters such as #, ? , / \ are not valid. 
		This function replace these characters by underscores "_"
		*/
		static void 	ValidateGenericID(vkString& ioID);


	protected:

		// Do not allow a direct destruction via delete
		virtual ~vkObject();

		enum FObjectFlags {
			fIsPrototype		= 1	<< 0,		/*!< This object is a prototype that is not to be used, displayed in any global context or manager.. */
			fHideInAuthoring	= 1 << 1,		/*!< Do not display this object in authoring context */
			fTransient			= 1 << 2,		/*!< Do not save this object */
			fCopyOptionBitShift	= 3,			
			fCopyOptionMask		= eCopyOptionMask << fCopyOptionBitShift, /*!< Copy option storage */
			fLastObjectFlags	= 1	<< (3+eCopyOptionBitCount),	/*!< For following classes */
		};

#if defined(VK_MULTIPLE_CONTEXTS)
		uint16	m_Ctx;
		uint16	m_ObjectFlags;
#else
		uint32	m_ObjectFlags;
#endif

		//-------------------------------------------------------------------------------
		/**
		Cleans up any references 
		
		A default implementation should at least mark the object as invalid by calling
		its parent class _Destroy member function.
		
		Most of the time this function is called before a vkRefPtrObject or a vkSmartPtrObject 
		is destroyed. This can also be called though an explicit call to 
		vkRefPtrObject::Destroy() when an object is invalidated. 

		@see _Create
		*/
		//-------------------------------------------------------------------------------
		virtual void _Destroy();

	};

	VK_INLINE bool32
	vkObject::IsReferenced() const
	{
		return GetReferenceCount() > 0;
	}


	VK_INLINE vkCtx
	vkObject::GetCtx() const
	{
#if defined(VK_MULTIPLE_CONTEXTS)
		return m_Ctx;
#else
		return kMainCtx;
#endif
	}



	VK_INLINE void
	vkObject::SetAsPrototype(bool32 iPrototype)
	{
		if (iPrototype)
			m_ObjectFlags |= fIsPrototype;
		else
			m_ObjectFlags &= ~fIsPrototype;
	}

	VK_INLINE bool32
	vkObject::IsPrototype() const
	{
		return (m_ObjectFlags & fIsPrototype) != 0;
	}


	VK_INLINE void
	vkObject::SetTransient(bool32 iTransient)
	{
		if (iTransient)
			m_ObjectFlags |= fTransient;
		else
			m_ObjectFlags &= ~fTransient;
	}

	VK_INLINE bool32
	vkObject::IsTransient() const
	{
		return (m_ObjectFlags & fTransient);
	}

	VK_INLINE void
	vkObject::SetHiddenInAuthoring(bool32 iHidden)
	{
		if (iHidden)
			m_ObjectFlags |= fHideInAuthoring;
		else
			m_ObjectFlags &= ~fHideInAuthoring;
	}

	VK_INLINE bool32
	vkObject::IsHiddenInAuthoring() const
	{
		return (m_ObjectFlags & fHideInAuthoring) != 0;
	}
}

#endif // __vkObject_h



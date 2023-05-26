/**
@file

Base class for arguments passed in serialization methods of types

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkLoadArgs_h)
#define __vkLoadArgs_h

#include "vkRTTI.h"

namespace VKernel
{
	class vkAssetSerializationContext;
	class vkString;
	class vkType;
	class vkAsset;

	/**
	Summary: Argument structure given to load functions
	*/
	class VKKERNEL_API vkLoadArgs : public vkRTTIObject
	{
	public:
		VK_DECLARE_RTTI(vkLoadArgs, vkRTTIObject);

		vkLoadArgs(vkAssetSerializationContext* iLoadContext, const vkType* iType, void* oBuffer);
		vkLoadArgs(const vkLoadArgs& iArgs);

		virtual bool IsValid() const;

		// Masking Base class implementation !
		vkCtx GetCtx() const;

		// Returns loadContext->GetLastAsset
		vkAsset* GetLastAsset() const;

		vkAssetSerializationContext*	loadContext;
		const vkType*					type;
		void*							buffer;
		const vkString*					resourceID;
	};

	/**
	Summary: Argument structure given to XML saving function
	*/
	class VKKERNEL_API vkSaveArgs : public vkRTTIObject
	{
	public:
	VK_DECLARE_RTTI(vkSaveArgs, vkRTTIObject);

		vkSaveArgs(vkAssetSerializationContext* iSaveContext, const vkType* iType, const void* iBuffer,  const void* iReferenceBuffer = 0, const vkType* iReferenceType = 0);
		vkSaveArgs(const vkSaveArgs& iArgs);
		~vkSaveArgs();

		virtual bool IsValid() const;

		// Masking Base class implementation !
		vkCtx GetCtx() const;

		vkAssetSerializationContext*	saveContext;
		const vkType*					type;			// Type of data being written
		const void*						buffer;			// The buffer holding the data
		const void*						referenceBuffer; // If not null, referenceBuffer is compared to buffer to make differential
		const vkType*					referenceType; // If null, use the type
	
	private:
		// $$$ MEGA HACK TO REMOVE
		bool							m_SaveContextMustBeDestroyed;
	};

} // NameSpace VKernel


#endif //vkLoadArgs




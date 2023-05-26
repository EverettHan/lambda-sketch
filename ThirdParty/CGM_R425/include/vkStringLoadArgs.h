/**
@file

Arguments for loading & Saving data based on a String Serialization

@COPYRIGHT

@author Gerald Guomard
*/

#if !defined(__vkStringLoadArgs_h)
#define __vkStringLoadArgs_h

#include "vkLoadArgs.h"

namespace VKernel
{
	/**
	Summary: Argument structure given to String loading function
	*/
	class VKKERNEL_API vkStringLoadArgs : public vkLoadArgs
	{
	public:
		VK_DECLARE_RTTI(vkStringLoadArgs, vkLoadArgs);

		enum FFlags
		{
			fInternal			= 1<<0,
			fStaticMembers		= 1<<1,
			fSelfMembersOnly	= 1<<2,
			fCreateDummyResources = 1<<5, // For debugging purposes : do not resolve resource refs but create resources with the good id

			fSilent = 1 << 3, // Do not log errors or warnings

			fLastFlag			= 1<<6
		};

		vkStringLoadArgs(vkAssetSerializationContext* iLoadContext, const vkType* iType, const vkString& iInputString, void* oBuffer, bool iInternal = false);
		vkStringLoadArgs(vkAssetSerializationContext* iLoadContext, const vkType* iType, vkString::Iterator& iInputStringStart, vkString::Iterator& iInputStringEnd, void* oBuffer, bool iInternal = false);
		vkStringLoadArgs(const vkStringLoadArgs& iArgs);
		vkStringLoadArgs(const vkLoadArgs& iArgs);

		virtual bool	IsValid() const;
		error			Load(); 

		bool			HasFlags(uint32 iFlags) const;
		void			ModifyFlags(uint32 iAdd, uint32 iRemove = 0);

		vkString::ConstIterator	stringStart;
		vkString::ConstIterator	stringEnd;
		uint32					flags;

		//bool32				internal;		
	};

	/**
	Summary: Argument structure given to String saving function
	*/
	class VKKERNEL_API vkStringSaveArgs : public vkSaveArgs
	{
	public:
		VK_DECLARE_RTTI(vkStringSaveArgs, vkSaveArgs);

		enum FFlags
		{
			fInternal					= 1<<0,

			fStaticMembers				= 1<<1,
			fSelfMembersOnly			= 1<<2,
			fSavePointersAsID			= 1<<3,
			fForDisplayPurpose	= 1<<4,
			fSilent = 1 << 5, // Do not log errors or warnings
			fTakeUnresolvedUCIasValue	= 1<<6,		//MORTAL IR-067768V6R2013, used in vkuiCondensedTypeCtrl.cpp to ask for a name even for unresolved comp, and not have a "#null"
			fReturnValueIsUnresolvedComponent		= 1<<7,		//MORTAL IR-067768V6R2013, set within vkComponentType.cpp to tell the vkuiCondensedTypeCtrl that indeed, buffer points on an unresolved component
			fLastFlag					= 1<<8
		};

		vkStringSaveArgs(vkAssetSerializationContext* iSaveContext, const vkType* iType, vkString& oOutputString, const void* iBuffer, bool iInternal = false);
		vkStringSaveArgs(const vkStringSaveArgs& iOther);
		vkStringSaveArgs(const vkSaveArgs& iOther);

		virtual bool	IsValid() const;
		void			Save() const;

		bool			HasFlags(uint32 iFlags) const;
		void			ModifyFlags(uint32 iAdd, uint32 iRemove = 0);

		vkString*			output;
		uint32				flags;
	};

} // NameSpace VKernel


#endif //vkStringLoadArgs




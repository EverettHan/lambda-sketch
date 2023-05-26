/**
@file

@COPYRIGHT

@author Frederic Guignard
@author Julien Bouix
@author Francois Dujardin
*/


#ifndef __ESBackingStore_h
#define __ESBackingStore_h

#include "ESKernelLib.h"

#include <memory>

namespace v8 {
	class BackingStore;
}

namespace ES {

	/**
	Class describing a ES Backing Store
	*/
	class ESKERNEL_API BackingStore {

		public:
			/**
			* This callback is used only if the memory block for this backing store cannot
			* be allocated with an ArrayBuffer::Allocator. In such cases the destructor
			* of this backing store object invokes the callback to free the memory block.
			*/
			using DeleterCallback = void (*)(void* iData, size_t iLength, void* iDeleterData);

			BackingStore(std::shared_ptr<v8::BackingStore> iBackingStore);
			~BackingStore();

			/**
			* Return a pointer to the beginning of the memory block for this backing
			* store. The pointer is only valid as long as this backing store object
			* lives.
			*/
			void* Data() const;

			/**
			* The length (in bytes) of this backing store.
			*/
			size_t ByteLength() const;

		private:

			std::shared_ptr<v8::BackingStore> m_BackingStore;

			friend class ArrayBuffer;
	};

}

#endif //__ESBackingStore_h

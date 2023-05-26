/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESArrayBuffer_h
#define __ESArrayBuffer_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"
#include "ESString.h"
#include "ESType.h"
#include "ESBackingStore.h"


namespace ES {
	class Universe;
	class World;
	class Class;

	/**
	Abstract class describing a ES native object
	*/
	class ESKERNEL_API ArrayBuffer : public ES::Object {

		public:

			/**
			 * Copy constructor
			 */
			ArrayBuffer(const ES::ArrayBuffer& iObject);
			
			/**
			 * Destructor
			 */
			virtual ~ArrayBuffer();

			/**
			 * Data length in bytes.
			 */
			size_t ByteLength() const;
			
			/**
			 * Create a new ArrayBuffer. Allocate |byte_length| bytes.
			 * Allocated memory will be owned by a created ArrayBuffer and
			 * will be deallocated when it is garbage-collected,
			 * unless the object is externalized.
			 */
			static ES::ArrayBuffer New(ES::World* iWorld, unsigned int iLength);
			/**
			 * Create a new ArrayBuffer. Allocate |byte_length| bytes.
			 * Allocated memory will be owned by a created ArrayBuffer and
			 * will be deallocated when it is garbage-collected,
			 * unless the object is externalized.
			 * WARNING: Caller is responsible to call operator delete on the allocated returned value
			 */
			static ES::ArrayBuffer* NewPtr(ES::World* iWorld, unsigned int iLength);

			/**
			 * Create a new ArrayBuffer with an existing backing store.
			 * The created array keeps a reference to the backing store until the array
			 * is garbage collected.
			 */
			static ES::ArrayBuffer New(ES::World* iWorld, const ES::BackingStore& iBackingStore);
			/**
			 * Create a new ArrayBuffer with an existing backing store.
			 * The created array keeps a reference to the backing store until the array
			 * is garbage collected.
			 * WARNING: Caller is responsible to call operator delete on the allocated returned value
			 */
			static ES::ArrayBuffer* NewPtr(ES::World* iWorld, const ES::BackingStore& iBackingStore);

			/**
			 * Returns a new BackingStore that is allocated using the internal array
			 * buffer allocator of the universe. The result can be later passed to
			 * ArrayBuffer::New.
			 */
			static ES::BackingStore NewBackingStore(ES::Universe* iUniverse, size_t iByteLength);
			/**
			 * Returns a new BackingStore that is allocated using the internal array
			 * buffer allocator of the universe. The result can be later passed to
			 * ArrayBuffer::New.
			 * WARNING: Caller is responsible to call operator delete on the allocated returned value
			 */
			static ES::BackingStore* NewBackingStorePtr(ES::Universe* iUniverse, size_t iByteLength);

			/**
			 * Returns a new BackingStore that takes over the ownership of
			 * the given buffer. The destructor of the BackingStore invokes the given
			 * deleter callback.
			 *
			 * The result can be later passed to ArrayBuffer::New. The raw pointer
			 * to the buffer must not be passed again to any ES API function.
			 */
			static ES::BackingStore NewBackingStore(void* iData, size_t iByteLength, ES::BackingStore::DeleterCallback iDeleterCallback, void* iDeleterData);
			/**
			 * Returns a new BackingStore that takes over the ownership of
			 * the given buffer. The destructor of the BackingStore invokes the given
			 * deleter callback.
			 *
			 * The result can be later passed to ArrayBuffer::New. The raw pointer
			 * to the buffer must not be passed again to any ES API function.
			 * WARNING: Caller is responsible to call operator delete on the allocated returned value
			 */
			static ES::BackingStore* NewBackingStorePtr(void* iData, size_t iByteLength, ES::BackingStore::DeleterCallback iDeleterCallback, void* iDeleterData);

			/**
			 * Returns true if this ArrayBuffer may be detached.
			 */
			bool IsDetachable() const;

			/**
			 * Detaches this ArrayBuffer and all its views (typed arrays).
			 * Detaching sets the byte length of the buffer and all typed arrays to zero,
			 * preventing JavaScript from ever accessing underlying backing store.
			 * ArrayBuffer must be detachable.
			 */
			void Detach();

			/**
			 * Get the backing store of this array buffer. This
			 * object coordinates the lifetime management of the internal storage
			 * with any live ArrayBuffers on the heap, even across universes. The embedder
			 * should not attempt to manage lifetime of the storage through other means.
			 */
			ES::BackingStore GetBackingStore();

			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::ArrayBuffer Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::ArrayBuffer& operator=(const ES::ArrayBuffer& iValue);

		public:
			ES_DEPRECATED("2020/06/24", "Please use ES::ArrayBuffer::New() with ES::BackingStore using ES::ArrayBuffer::NewBackingStore", static ES::ArrayBuffer New(ES::World* iWorld, void* iData, unsigned int iLength);)
			ES_DEPRECATED("2020/06/24", "Please use ES::ArrayBuffer::NewPtr() with ES::BackingStore using ES::ArrayBuffer::NewBackingStore", static ES::ArrayBuffer* NewPtr(ES::World* iWorld, void* iData, unsigned int iLength);)
			ES_DEPRECATED("2020/06/24", "Obsolete API, with ES::BackingStore externalized ArrayBuffers are the same as ordinary ArrayBuffers", bool IsExternal() const;)
			ES_DEPRECATED("2020/06/24", "Please use ES::ArrayBuffer::GetBackingStore()", void Externalize();)
			ES_DEPRECATED("2020/06/24", "Please use ES::ArrayBuffer::Detach()", void Neuter();)
			ES_DEPRECATED("2020/06/24", "Please use ES::ArrayBuffer::ByteLength()", size_t GetByteLength();)
			ES_DEPRECATED("2020/06/24", "Please use ES::ArrayBuffer::GetBackingStore() using ES::BackingStore::Data()", void* GetData();)

		private:
			ArrayBuffer(ES::World* iWorld, size_t iByteLength);
			ArrayBuffer(ES::World* iWorld, const ES::BackingStore& iBackingStore);

			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(ArrayBuffer)
	};

}

#endif //__ESArrayBuffer_h

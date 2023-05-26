#ifndef  CATHashTableFlags_h
#define  CATHashTableFlags_h

/**
 * CATHashTableOptions.
 * Optional structure to pass as the fourth parameter of the CATHashTable constructor (void * iOptions):
 * CATHashTabOfMyObject(PFHash iPFH, PFCompare iPFC, int iDimension, void * iOptions);
 * 
 * Example:
 * CATHashTableOptions opt = { };
 * opt.flags = CATHTAB_AUTO_REHASH;
 * CATHashTabOfMyObject hashTab(iPFH, iPFC, iDimension, &options);
 */
struct CATHashTableOptions
{
	int flags;
	float max_load_factor;	// Requires flag CATHTAB_AUTO_REHASH_MAX_LOAD_FACTOR
};

/**
 * CATHashTableOptions flag CATHTAB_AUTO_REHASH.
 * Activates an implementation that rebuilds/rehash itself automatically in an attempt to limit the number of collisions
 * when the size of the container is growing, the final goal being to maintain good lookup performance.
 * In this mode, usually the initial dimension is kept low to save memory, because it will be increased as needed when the hash table grows.
 * Besides, calling the member functions "Unused", "Collisions" & "Rebuild" to trigger rehash manually is discouraged.
 * Currently, the underlying implementation is based on the C++ container std::unordered_set (STL). Note that this might change in the future.
 * Appendix:
 *  - Please don't write code relying on iteration order since hash tables are unordered containers!
 */
#define CATHTAB_AUTO_REHASH						0x01

/**
 * CATHashTableOptions flag CATHTAB_AUTO_REHASH_MAX_LOAD_FACTOR.
 * Use to customize the maximum load factor for the CATHashTable. This flag is ignored if CATHTAB_AUTO_REHASH is not set.
 * The load factor is the ratio between the number of elements in the container (its size) and the number of buckets (bucket_count).
 * By default, the maximum load factor is set to 1.0.
 * The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket). 
 * The container uses the value of max_load_factor as the threshold that forces an increase in the number of buckets (and thus causing a rehash).
 */
#define CATHTAB_AUTO_REHASH_MAX_LOAD_FACTOR		0x02

/**
 * CATHashTableOptions flag CATHTAB_AUTO_REHASH_DISABLE.
 * To explicitly opt for the behavior of R421 and previous levels.
 * Incompatible with flag CATHTAB_AUTO_REHASH.
 */
#define CATHTAB_AUTO_REHASH_DISABLE				0x04

/** 
 * CATHashTableOptions flag CATHTAB_AUTO_REHASH_DIMENSION_WARNING_SUPPRESS.
 * Generally, reserving/preallocating a large dimension at construction is a waste of memory, 
 * especially for an auto-rehashable container, unless one intents to fill the hash table right away. 
 * In SPECIFIC cases where preallocation is needed, one can safely suppress the CATHashTable warning by setting CATHTAB_AUTO_REHASH_DIMENSION_WARNING_SUPPRESS (+ optionally CATHTAB_AUTO_REHASH).
 * In other cases, one should consider:
 *  1) To enable the new auto-rehash behavior by setting the flag CATHTAB_AUTO_REHASH, leaving the default value for dimension.
 *     CATHTAB_AUTO_REHASH_DIMENSION_WARNING_SUPPRESS is useless in this case.
 *  2) To migrate the code to use another auto-rehashable container
 */
#define CATHTAB_AUTO_REHASH_DIMENSION_WARNING_SUPPRESS 0x08


#endif	// CATHashTableFlags_h

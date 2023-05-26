
#ifndef OOCPointCloudInterfaces_H
#define OOCPointCloudInterfaces_H

#define OOCPC_POSITION "DEF_POSITION" ///< Reserved meta data for point position
#define OOCPC_COLOR    "DEF_COLOR"    ///< Reserved meta data for point color

#define OOCPC_INDEX    "index"        ///< Reserved name for the point cloud index file

//#define OOCPC_UPDATE_ORIGIN // switch to enable dev metadata to highlight point origin during incremental update
#ifdef OOCPC_UPDATE_ORIGIN
// metadata to highlight points origin
#define OOCPC_PCREATION "DEV_PCREATION_VID"
#define OOCPC_NCREATION "DEV_NCREATION_VID"
#endif
#define DISABLE_VIEWPOINT_BASED_UPDATE ///< Deactivated code. Obsolete points are no longer detected using sensor parameters.
#define DISABLE_UPDATE_POINT_ERODING ///< Deactivated code. Excessive edits are no longer pruned by eroding patches of similarly edited points.
#define DISABLE_UPDATE_SUBSAMPLING ///< Deactivated code. Points of new acquisitions are no longer subsampled to the provided resolution.

#include <cstdint>
#include <string>
#include <type_traits>

#define new_OOCPCFrustumUtils_h

namespace oocpc
{

    /**
    * @brief Define PointCloud usage, default is ON_PREMISE
    *
    */
    enum class Usage
    {
        ON_PREMISE = 0, ///< Maximize caching system
        STREAMING_CLOUD = 1, ///< Lazy caching system
        COMPUTE_CLOUD = 2, ///<
    };

    /**
    * @brief Selection of coordinate system
    *
    * @details By default, point position are store in single precision ( float ), one can request double precision storage
    * Positions access will be made in double precision except if single precision is requested, for instance, visualization ( see TraversalConfig )
    */
    enum class CoordinateSystem
    {
        SINGLE_PRECISION, ///< single precision floating points
        DOUBLE_PRECISION  ///< double precision floating points ( for visualization, points coordinate will be casted to single precision )
    };

    /**
    * @brief Select point cloud traversal algorithm
    * @ingroup TraversalAlgorithm
    */
    enum class Algorithm
    {
        DEPTH_FIRST,        ///< traverse down each children path
        BREADTH_FIRST,      ///< traverse by level
        FRONT_TO_BACK,      ///< traverse from a viewpoint
        Z_SAMPLING,
        CUSTOM              ///< traverse algorithm must be defined by user
    };

    /**
    * @brief Select point cloud data loading mode
    * @ingroup DataLoading
    */
    enum class DataLoading
    {
        /*
         * Personal notes about choosing a DataLoading mode
         *
         * Modes difference overview:
         * VISIT_ONLY and LOD_ONLY are mostly for visu, and don't actually load/unload cache pages
         * REJECT_VISITED is good to traverse all nodes exactly once, and a node can be fully processed in one "cycle" -> not suited for non-forward iterators or neighbours
         * MOST_PRIORITY is good if *ALL* nodes priority are computed at once, and they will remain stable for a while (at least until the intended traversal ends)
         *  one issue of MOST_PRIORITY is that currently, no priority reset is actually performed (unless explicitly requested), so pages that are unused may keep
         *  a high priority and stay in cache, potentially preventing pages that we now need but whose computed priority is small, to be loaded
         *  ~> snapshot mode
         *  Edit: apparently the mode is now mostly dedicated to asynchronous traversals and is not suited anymore to regular data traversals.
         * [canceled] CUMULATIVE_PRIO(RITY) bypasses that issue by cumulating priority: if a page is repeatedly requested, its priority will eventually reach the maximum value
         * [canceled]  this method can suffer from priority overflow
         * LRU is similar to *PRIORITY modes when it comes to choosing what pages to load, but different as it automatically soft resets a page's priority when it is used.
         *  probably best suited for bi-directional iterators, can also work with CacheScheduler, but CacheScheduler would probably work better with an MRU mode?
         *  Currently Dispatch with neighbours and DoubleDispatch perform a full traversal of the hierarchy to assign priorities. When a page is already in L1 cache, it is
         *  likely that other not-yet-dispatched clusters using this page will explicitly request the page. So non-requested pages are likely to not be requested for a while,
         *  and should be unloaded in priority ~> MRU mode with a hard priority reset? If async, probably fine, but lazy load/unload probably better in sync.
         */
        REJECT_VISITED,     ///< traverse while all intersected node had been loaded once and compute had been dispatched on each one.
        MOST_PRIORITY,      ///< process node with the best priority only ( depending on ComputeNodePriority, priority is reset at each traversal )
        VISIT_ONLY,         ///< traverse loaded node only, no priority update or cache update will be done. If requested data is different, traversal will fail.
        LOD_ONLY,           ///< traverse only point cloud coarse representation ( degraded view of point cloud positions and colors )
        //CUMULATIVE_PRIO,    ///< load/unload according to a cumulative, persistent priority
        LRU                 ///< unload least recently used pages
    };


    /**
     * @brief Specifies stream access and sharing rights
     */
    enum class StreamFlags //: unsigned char
    {
        // if changes to values are required, edit OOCPCLockStreamHandle.cpp accordingly
        NONE = 0x0,

        REQ_READ    = 0x1,                  ///< Request READ permission
        REQ_WRITE   = 0x2,                  ///< Request WRITE permission
        REQ_MASK    = REQ_READ | REQ_WRITE, ///< Mask for "request" bits
        _REQ_MSIZE  = 2,                    ///< Size of the "request" mask in bits, for internal use

        AUT_READ    = REQ_READ  << _REQ_MSIZE,  ///< Authorize other threads/processes/machines to concurrently access the stream for READ
        AUT_WRITE   = REQ_WRITE << _REQ_MSIZE,  ///< Authorize other threads/processes/machines to concurrently access the stream for WRITE
        AUT_MASK    = REQ_MASK  << _REQ_MSIZE,  ///< Mask for the "authorize" bits

        //PROTECTED_READ  = REQ_READ | AUT_READ,              ///< Prevent others from writing while accessing for read
        DEFAULT_READ    = REQ_READ | AUT_READ | AUT_WRITE,  ///< Default flags for read access
        DEFAULT_WRITE   = REQ_READ | REQ_WRITE | AUT_READ,  ///< Default flags for write access
        DEFAULT_REQ_AUT = DEFAULT_READ                      ///< Flags used by default if unspecified when calling OOCPCTraverser::RequestData
    };

    inline StreamFlags operator|( const StreamFlags &lhs, const StreamFlags &rhs )
    {
        return static_cast<StreamFlags>( static_cast<std::underlying_type<StreamFlags>::type>( lhs ) | static_cast<std::underlying_type<StreamFlags>::type>( rhs ) );
    }

    inline StreamFlags operator&( const StreamFlags &lhs, const StreamFlags &rhs )
    {
        return static_cast<StreamFlags>( static_cast<std::underlying_type<StreamFlags>::type>( lhs ) & static_cast<std::underlying_type<StreamFlags>::type>( rhs ) );
    }


    enum class eNeighbours : unsigned short // unsigned: the warning C4369 was annoying
    {
        NONE = 0x0,

        // Adjacency logic, uses the 3 LSB
        FACES = 0x1,
        CORNERS = 0x2,
        EDGES = 0x4,
        ALL = 0x7,  // (FACES | CORNERS | EDGES)

        SAMPLE = 0x8, // For z-sampling only

        // Distance logic, should avoid the 3 LSB, actual values don't matter, but must:
        //      - avoid adjacency bits (currently the 3 LSB)
        //      - DISTANCE, XY, and SPACEVOXEL must be single bit masks
        //      - compound values are computed based on those bit masks values
        DISTANCE   = 0x10,  // compute neighbours based on nodes bounding box distance
        XY         = 0x20,  // distance option: indicates to use 2D XY euclidean distance instead of 3D
        SPACEVOXEL = 0x40,  // distance option: indicates to use distance to the space bounding box of the main node, rather than the data tight-fitting bounding box
        // compound distance modes, must be defined after bit masks
        XYDISTANCE     = (DISTANCE | XY),
        SVOXDISTANCE   = (DISTANCE | SPACEVOXEL),       // never used, remove? (remove support for it from OOCPCDispatcher::NodePairDistanceThreshold)
        XYSVOXDISTANCE = (DISTANCE | XY | SPACEVOXEL),  // can also be used as mask for distance logic bits

        OTHER = (0xFFFF & ~(ALL | XYSVOXDISTANCE))  // mask for values that neither fit the adjacency or distance logics
    };

    inline eNeighbours operator | ( eNeighbours lhs, eNeighbours rhs )

    {
        return static_cast<eNeighbours>( static_cast<std::underlying_type<eNeighbours>::type>( lhs ) | static_cast<std::underlying_type<eNeighbours>::type>( rhs ) );
    }

    inline eNeighbours operator & ( eNeighbours lhs, eNeighbours rhs )

    {
        return static_cast<eNeighbours>( static_cast<std::underlying_type<eNeighbours>::type>( lhs ) & static_cast<std::underlying_type<eNeighbours>::type>( rhs ) );
    }

    /**
    * @brief Options for traversal algorithm
    */
    struct TraversalConfig
    {
        TraversalConfig() :
            m_MaxInCoreLoad( 20 ),
            m_MaxOutOfCoreLoad( 50 ),
            m_DataLoading( DataLoading::MOST_PRIORITY ),
            m_StrictRequest( false ),
            m_RequestSPPositions( false ),
            m_InterleavedData( true ),
            m_Asynchronous( false ),
            m_CacheLevel( 3 ),
            m_TranslateOrigin( false ),
            m_Force4BytesAlignment( false ),
            m_ReloadDirty( false ),
            m_AddRequestData(false),
            m_UseSlicingQuery(false)
        {
            m_Viewpoint[ 0 ] = 0.0;
            m_Viewpoint[ 1 ] = 0.0;
            m_Viewpoint[ 2 ] = 0.0;
        }


        double               m_Viewpoint[ 3 ];       ///< Viewpoint for front to back traversal
        unsigned             m_MaxInCoreLoad;        ///< Control call number to OnInCoreNode during traversal see OOCPCTraverser
        unsigned             m_MaxOutOfCoreLoad;     ///< Control number of out of core data loading during traversal see OOCPCTraverser
        DataLoading          m_DataLoading;          ///< see DataLoading
        bool                 m_StrictRequest;        ///< force traversal with strictly requested data ( needed for visu performances )
        bool                 m_RequestSPPositions;   ///< Request positions to be casted to single precision ( will be effective with double precision coordinates system )
        bool                 m_InterleavedData;      ///< Advanced usage, Data will be interleaved by points
        bool                 m_Asynchronous;         ///< Advanced usage, Data loading will be performed asynchronously
        int                  m_CacheLevel;           ///< Advanced usage, Data loading through different cache level ( must be 2, or 3 )
        [[deprecated]] bool  m_TranslateOrigin;      ///< Advanced usage, point position will be translated to the origin
        [[deprecated]] bool  m_Force4BytesAlignment; ///< Advanced usage, for NRE purpose, ensure to have 4 bytes aligned data size to meet visu engine constraints
        bool                 m_ReloadDirty;          ///< Force node data to be reloaded when it is flagged as dirty (edited)
        bool                 m_AddRequestData;       ///< Force cache to add metadata in its current list instead of overwriting it
        bool                 m_UseSlicingQuery;      ///< Force traverser to take slicing plane query into account when filtering
        //...
    };

    /**
    *   @brief Options for dispatch algorithm
    */
    struct DispatcherConfig
    {
        DispatcherConfig() :
            m_BlockingLaunch( true ),
            m_Threads( 1 ),
            m_Neighbours( eNeighbours::NONE ),
            m_StrictRequest( false ),
            m_RequestSPPositions( false ),
            m_DistanceThreshold(-1.0f),
            m_AddRequestData(false)
        {
        }

        bool        m_BlockingLaunch;       ///< Dispatch one node at a time on a dedicated core, if false all nodes will be dispatched leading to a high memory consumption
        unsigned    m_Threads;              ///< max number of threads to dispatch nodes onto, 1 by default means no multithread activated
        eNeighbours m_Neighbours;           ///< Dispatch each node with its N neighbours e.g. 6, 8, 12 or an union of those, by default no neighbour will be dispatched
        bool        m_StrictRequest;        ///< force traversal with strictly requested data ( needed for visu performances )
        bool        m_RequestSPPositions;   ///< Request positions to be casted to single precision ( will be effective with double precision coordinates system )
        float       m_DistanceThreshold;    ///< Parameter for neighbour computation. Only relevant when the neighbour option is oocpc::eNeighbours::DISTANCE. A negative value is equivalent to oocpc::eNeighbours::NONE.
        bool        m_AddRequestData;       ///< Force cache to add metadata in its current list instead of overwriting it
    };

    /**
     * @brief Options for double dispatch
     */
    struct DoubleDispatcherConfig : public DispatcherConfig
    {
        DoubleDispatcherConfig() :
            m_OtherNeighbours(eNeighbours::NONE),
            m_OtherDistanceThreshold(-1.0f),
            //m_OtherStrictRequest( false ),
            //m_OtherRequestSPPositions( false )
            m_DispatchCacheReserve(0),
            m_OtherCacheReserve(0),
            m_PhantomDspPolicy(eNeighbours::NONE),
            m_PhantomDspDistanceThreshold(-1.0f),
            m_PhantomOthPolicy(eNeighbours::NONE),
            m_PhantomOthDistanceThreshold(-1.0f)
        {
        }

        eNeighbours m_OtherNeighbours;
        //bool        m_OtherStrictRequest;        ///< could define similar settings as for dispatcher to control other cache, but currently no need to have different settings
        //bool        m_OtherRequestSPPositions;   ///< could define similar settings as for dispatcher to control other cache, but currently no need to have different settings
        float       m_OtherDistanceThreshold;
        unsigned    m_DispatchCacheReserve;
        unsigned    m_OtherCacheReserve;
        // TODO: explanation of "phantom" parameters
        eNeighbours m_PhantomDspPolicy;            ///< authorized values := distance logic only
        float       m_PhantomDspDistanceThreshold;
        eNeighbours m_PhantomOthPolicy;            ///< authorized values := distance logic only
        float       m_PhantomOthDistanceThreshold;
    };


    /**
    * @brief Chunk type for point cloud containers
    *
    * @details dedicate bits to specialize chunk types ( allow fast search on container type )
    * first 8 bits assigned to static meta data types
    * next 8 bits for dynamic
    * next 8 bits for accelerator
    * next 4 bits for whatever we need in the future
    * last 4 bits for information
    */
    enum class ContainerChunkType : std::uint32_t
    {
        OOCPC_UNKNOWN_CONTAINER = 0x0,          ///< undefined container

        OOCPC_STATIC_CONTAINER = 0x1,          ///< The chunk contains a static container (data is per point)
        OOCPC_STATIC_POSITIONS_CONTAINER = 0x2,          ///< Special container for positions ( allow different coordinate system and type casting for double precision visualization )
        OOCPC_ALL_STATIC_CONTAINERS = 0xFF,         ///< Mask for all static containers

        OOCPC_LEGACY_VOLATILE_CONTAINER [[deprecated]] = 0x100, ///< @deprecated The chunk contains a volatile container (each data is linked to a range of points)
        OOCPC_DYNAMIC_CONTAINER = 0x200,         ///< The chunk contains a formula wich references several static or dynamic containers that is to be applied to InCore data
        OOCPC_VOLATILE_CONTAINER = 0x400,
        OOCPC_ALL_VOLATILE_CONTAINERS = 0xFF00,       ///< Mask for all dynamic containers

        OOCPC_ALL_CONTAINERS = 0xFFFF,       ///< Mask all meta data containers

        OOCPC_OCTREE_ACCELERATOR_CONTAINER [[deprecated]] = 0x10000,                            ///< @deprecated Octree accelerator ( first version of the octree accelerator )
        OOCPC_OCTREE_ACCELERATOR_WITH_VERSIONNING_CONTAINER [[deprecated]] = 0x20000,           ///< @deprecated Octree accelerator with versionning support
        OOCPC_OCTREE_ACCELERATOR_CONTAINER_DOUBLE [[deprecated]] = 0x30000,                     ///< @deprecated Octree accelerator with double bounding boxes support
        OOCPC_OCTREE_ACCELERATOR_WITH_VERSIONNING_CONTAINER_DOUBLE [[deprecated]] = 0x40000,    ///< @deprecated Octree accelerator with versionning and double bounding boxes support
        OOCPC_OCTREE_ACCELERATOR_WSTRICTMORTON_CONTAINER = 0x50000,                             ///< @deprecated Octree accelerator with an attempt at strict morton constraint for node creation: supports versionning v2, not backward compatible
        OOCPC_OCTREE_ACCELERATOR_WSTRICTERMORTON_CONTAINER = 0x60000,                           ///< Octree accelerator with a more correct strict morton constraint for node creation: supports versionning v2, not backward compatible
#ifdef OOCPC_OCTREE_AGGREGATION_DEV
        OOCPC_N_ACCELERATORS,   ///< do not use, just there to automatically update the value of OOCPC_OCTREE_AGGRETATION_ACCELERATOR_CONTAINER if a new accelerator makes it in before aggregation impl is ready
        OOCPC_OCTREE_AGGREGATION_ACCELERATOR_CONTAINER = OOCPC_N_ACCELERATORS + ( 0x10000 - 1 ),///< tentative name for the new "full-lod" implementation
#endif
        OOCPC_ALL_ACCELERATOR_CONTAINERS = 0xFF0000,                                            ///< Mask all accelerator

        OOCPC_UUID_CONTAINER = 0x10000000,              ///< Contains an unique id for the point cloud ( optional )
        OOCPC_STRING_REPOSITORY_CONTAINER = 0x20000000, ///< Special container for the StringRepository
        OOCPC_UPDATE_ITERATION_CONTAINER = 0x30000000,  ///< Special container for update iterations
        OOCPC_MORTON_SEED_CONTAINER = 0x40000000,       ///< Stores the original bounding box used at build time
        OOCPC_OCTREE_LOD_CONTAINER = 0x50000000,        ///< Octree LOD container
        OOCPC_REPOSITORY_INFO_CONTAINER = 0x60000000,   ///< To stream extra repository information
        OOCPC_INFOS_CONTAINER = 0xF0000000,             ///< Mask additional informations

        // More to come
    };

    inline ContainerChunkType operator | ( ContainerChunkType lhs, ContainerChunkType rhs )
    {
        return static_cast<ContainerChunkType>( static_cast<std::underlying_type<ContainerChunkType>::type>( lhs ) | static_cast<std::underlying_type<ContainerChunkType>::type>( rhs ) );
    }

    inline constexpr ContainerChunkType operator & ( ContainerChunkType lhs, ContainerChunkType rhs ) noexcept
    {
        return static_cast<ContainerChunkType>( static_cast<std::underlying_type<ContainerChunkType>::type>( lhs ) & static_cast<std::underlying_type<ContainerChunkType>::type>( rhs ) );
    }

    inline constexpr bool operator < ( ContainerChunkType lhs, ContainerChunkType rhs ) noexcept
    {
        return static_cast<std::underlying_type<ContainerChunkType>::type>( lhs ) < static_cast<std::underlying_type<ContainerChunkType>::type>( rhs );
    }

    inline bool IsMetaDataContainerChunkType( oocpc::ContainerChunkType i_ChunkType )
    {
        return ( oocpc::ContainerChunkType::OOCPC_ALL_CONTAINERS & i_ChunkType ) != oocpc::ContainerChunkType::OOCPC_UNKNOWN_CONTAINER;
    }

    enum class KnownStrictMortonBugs : std::uint32_t
    {
        eINITIAL_FAULTY_IMPL = 0,
        eINVALID_INIT_OF_INV_SEED_EXTENT,       //!< Constraints were computed in the stored floating point type, but the member computations was done in double. Discovered/observed ~ June 2022

        // add newly discovered bugs above...
        eNUMBER_OF_BUGS                         //!< usual "trick" to get the number of enumerators/enum values
    };

    namespace visu
    {
        enum class Layout
        {
            POSITION,
            RGB_COLOR,
            SCALAR,
            VEC2
            // could be useful for future use
            // today no rendering effect needs multiple metadata
            //VEC3,
            //VEC4
        };

        enum class Type
        {
            eUndefined = 0,
            eInt8,
            eInt16,
            eInt32,
            eInt64,
            eStringIndex,
            eFloat,
            eDouble
        };


        struct MetaData
        {
            unsigned cache_offset;
            unsigned visu_offset;
            /**
             * @details As of currently, there are three cases:
             *  - if layout == POSITION, (which implies cache_type == eUndefined), then size is the size in the cache buffer, and NOT the size visu buffer
             *  - (else) if cache_type == eUndefined, (and layout != POSITION), then size in chace buffer and visu buffer are equal, and the member evals to that common size
             *  - (else) cache_type != eUndefined, (and layout != POSITION), then size is NOT the size in the cache buffer, but is the size in visu buffer and is equal to 4 (forces cast to float when we know how to cast)
             *
             * This info is relevant if you want to understand what happens between OOCPCVisuTraverserProxyImpl::InitializeCache and CAT3DPointCloudRender::_CreateInCoreRep
             */
            unsigned size;
            std::string name;
            Layout layout;
            Type cache_type;
        };
    }
}


#endif

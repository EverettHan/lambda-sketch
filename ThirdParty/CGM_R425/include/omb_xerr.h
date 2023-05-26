#ifndef omb_xerr_H
#define omb_xerr_H

// Client traces refinement for debug
//-----------------------------------

// Define all OMB-centric static error flags operated by CATOmxLogError for unexpected internal errors tracing 

// Save stream error flags
#define OMBxSAVE01  OMBxSAVE01 // V6 streaming
#define OMBxSAVE02  OMBxSAVE02 // exporter
#define OMBxSAVE03  OMBxSAVE03 // converter
#define OMBxSAVE04  OMBxSAVE04 // V5 stream copy 
#define OMBxSAVE05  OMBxSAVE05 // new cache entry
#define OMBxSAVE06  OMBxSAVE06 // Duplicate stream
#define OMBxSAVE07  OMBxSAVE07 // start save notif
#define OMBxSAVE08  OMBxSAVE08 // End save notif
#define OMBxSAVE09  OMBxSAVE09 // invalid V6inV6 tag
#define OMBxSAVE10  OMBxSAVE10 // general save failure
#define OMBxSAVE11  OMBxSAVE11 // Document without name
#define OMBxSAVE12  OMBxSAVE12 // Invalid Document Info
#define OMBxSAVE13  OMBxSAVE13 // Attempting to save two docs to same path
#define OMBxSAVE14  OMBxSAVE14 // invalid V6inV6 tag
#define OMBxSAVE15  OMBxSAVE15 // general save failure
#define OMBxSAVE16  OMBxSAVE16 // Container not loaded
#define OMBxSAVE17  OMBxSAVE17 // Doc properties

// Secondary stream synchro error flags
#define OMBxSYNC01  OMBxSYNC01 // Applicative synchro declaration
#define OMBxSYNC02  OMBxSYNC02 // Applicative synchro preparation
#define OMBxSYNC03  OMBxSYNC03 // Applicative synchro preparation
#define OMBxSYNC04  OMBxSYNC04 // Applicative synchro operation

// PLM stream descriptor Save error flags
#define PSDxSAVE01  PSDxSAVE01 // Get SD

// code management coherency flags  
// (to replace assertions in general code management)
#define OMBxCOHR01  OMBxCOHR01 // Switch error severity inconsistency
#define OMBxCOHR02  OMBxCOHR02 // component information inconsistency
#define OMBxCOHR03  OMBxCOHR03 // PersistencyType inconsistency repaired on CATIA types

// Component mediator
#define OMBxMEDI01  OMBxMEDI01 // Streams access wrapper init
#define OMBxMEDI02  OMBxMEDI02 // LocalSave components restore
#define OMBxMEDI03  OMBxMEDI03 // After import

// Extended stream local storage
#define OMBxLSTO01  OMBxLSTO01 // local storage meta-data length incoherency
#define OMBxLSTO02  OMBxLSTO02 // local storage meta-data read

// Linkable Streams
#define OMBxLS01  OMBxLS01 // Linkable Streams caller did not allocate CATOmbObjectStreams
#define OMBxLS02  OMBxLS02 // Linkable Streams caller is trying to use empty component

// Open stream error flags
//#define OMBxOPEN01  OMBxOPEN01

// UndoRedo
//the commented OMBxUNDO0* has been defined in ObjectmodelerEngines because of a non completed migration
//we keep it to remind one must start after OMBxUNDO05
//#define OMBxUNDO01  OMBxUNDO01 // undo/redo invariant
//#define OMBxUNDO02  OMBxUNDO02 // undo/redo invariant 
//#define OMBxUNDO03  OMBxUNDO03 // undo/redo invariant
//#define OMBxUNDO04  OMBxUNDO04 // undo/redo invariant
//#define OMBxUNDO05  OMBxUNDO05 // undo/redo exception trap
#define OMBxUNDO06  OMBxUNDO06 // undo/redo observer lifecycle

// Omb dictionary (Selective loading dico / converter/importer/exporter declaration)
#define OMBxDICO01  OMBxDICO01 // Converter key re-declaration
#define OMBxDICO02  OMBxDICO02 // Bad RepRef definition

// SwitchEngine
#define OMBxSWI01  OMBxSWI01 // switch operation coherency (longjump at Unload/Load/parallel Load)
#define OMBxSWI02  OMBxSWI02 // switch operation coherency (longjump at steams download in cache before load)

// LocalSave de/serialization
#define OMBxSRZ01  OMBxSRZ01 // RepRef serializing
#define OMBxSRZ02  OMBxSRZ02 // SD serializing
#define OMBxDSZ01  OMBxDSZ01 // RepRef deserializing
#define OMBxDSZ02  OMBxDSZ02 // SD serializing

// Non CATIA doc Projection/Export/Import/Large file Download
#define OMBxNSDC01  OMBxNSDC01 // Non CATIA SD/doc
#define OMBxPROJ01  OMBxPROJ01 // Projection
#define OMBxEXPT01  OMBxEXPT01 // Export
#define OMBxDWLF01  OMBxDWLF01 // Large file Download

#endif

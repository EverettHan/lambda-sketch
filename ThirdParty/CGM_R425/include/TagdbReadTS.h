// // COPYRIGHT Dassault Systemes 2015
// //===================================================================
// //
// // TagdbTS.h
// //
// //===================================================================
// //
// // Usage notes:
// //   tagdbEngineR is a thread safe tagdb Engine dedicated to read.
// //   tagdbEngineR and its base class tagdbEngineBaseR are not intended
// //   to be used externally. These classes should be used only by 
// //   tagdbEngineTS.
// //
// //===================================================================
// //
// //  Apr 2015  Creation
// //===================================================================

// #ifndef TAGDBREADTS_H
// #define TAGDBREADTS_H

// #include "TagdbBase.h"

// namespace Tagdb
// {  
  // class tagdbStoreR;
  
  // ///////////////////////////////////////////////////////////////////////
  // class ExportedBytagdb tagdbEngineBaseR
  // {
    // public:
      // tagdbEngineBaseR(tagdbFileFactory iFileFactory, int iMaxNodeNumberInMemory=Large);
      // virtual ~tagdbEngineBaseR();
      // Status   open(const char *root, tagdbKeyFactory iKeyFactory, tagdbRecordFactory iRecordFactory, Boolean iStartCleaningThread=True);      
      // Status   get(tagdbKey &key, tagdbRecord *&rec);           
      // Status   exportFiles(const char * iDestDir);      

    // protected:      
      // void     setCleaningDelay(int imsDelay) {_cleaningDelay = imsDelay;}      
      
      // tagdbStoreR      *_store;
      // tagdbFileFactory  _fileFactory;      
      // int               _maxLoadedNode;
      // int               _cleaningDelay; // default is 5s
      
      // friend class tagdbStoreR;
      // friend class tagdbNodeR;
      // friend class tagdbUnloaderR;
  // };

  // ///////////////////////////////////////////////////////////////////////
  // template <class TypeKey, class TypeRecord>  
  // class tagdbEngineR : public tagdbEngineBaseR
  // {
    // public:
      // tagdbEngineR(tagdbFileFactory iFF=tagdbLocalFile::newInstance, int iMaxNodeNumberInMemory=Large) 
        // : tagdbEngineBaseR(iFF,iMaxNodeNumberInMemory)
        // {}
        
      // virtual ~tagdbEngineR() 
        // {}
            
      // // Not TS
      // using tagdbEngineBaseR::open;
      // Status open(const char *root) 
        // {return tagdbEngineBaseR::open(root,TypeKey::newInstanceFromFile,TypeRecord::newInstanceFromFile); }
      
      // // TS 
      // using tagdbEngineBaseR::get;
      // Status get(TypeKey &iKey, TypeRecord *&oRec)     
        // {
          // tagdbRecord * localRec = 0;
          // Status rc = tagdbEngineBaseR::get(iKey,localRec);
          // oRec = static_cast<TypeRecord*>(localRec);
          // return rc;
        // }
  // };   
// }

// #endif

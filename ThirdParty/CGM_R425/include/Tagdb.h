// Tagdb.h -- 
//
// Copyright (c) 2004-2007 Dassault Systemes.
// All Rights Reserved.
// This program contains proprietary and trade secret information of
// MatrixOne, Inc.  Copyright notice is precautionary only
// and does not evidence any actual or intended publication of such program.

////////////////////////////////////////////////////////////////////////////////
// $Id: Tagdb.h.rca 1.9.1.2 Mon Aug  6 12:24:23 2007 przemek Experimental $
////////////////////////////////////////////////////////////////////////////////
/**
* @level Protected
* @usage U1
*/

#ifndef TAGDB_H
#define TAGDB_H

#include "TagdbBase.h"
#include "LinkedList.h"
#include <stdio.h>
#include "CATAssert.h"

#define TagdbIsUnicode

namespace Tagdb
{    
  class tagdbEngineBase;
  class tagdbNode;
  class tagdbCachedNode;
  class tagdbNodeRef;
  class tagdbItrBase;
  class TagdbScenarioPlayer;
  class ScenarioPlayer;
  
  ///////////////////////////////////////////////////////////////////////
  class ExportedBytagdb tagdbStore {
    public:
      tagdbStore(tagdbEngineBase *, const CATUnicodeString & , tagdbKeyFactory, tagdbRecordFactory);
      virtual ~tagdbStore();
      Status start();
      Status prepare();
      Status commit();
      Status cleanup();
      Status abort();
      Status recover();
      Status update(tagdbId id);
      Status reclaim(tagdbId id);
      Status newNode(tagdbNode *&);
      int currentVersion(tagdbId);
      CATUnicodeString controlFilePath(int version);
      CATUnicodeString currentNodePath(tagdbId id);
      CATUnicodeString versionNodePath(tagdbId id, int version);
      Status tryload();
      tagdbFile *openNode(tagdbId, FileMode);

      // node cache  
      // Search the node of index id in the store's cache.
      Boolean lookup(tagdbId, tagdbCachedNode *&);
      Status lookup(tagdbId, tagdbNode *&);
      Status insert(tagdbNode *);
      Status checkCache(tagdbNode *);
      void remove(tagdbNode *);
      Status dropCache(Boolean, int * = NULL);

      // tree management
      tagdbId lookup(tagdbNode *node, tagdbKey &, int skipMatch, int &index, int &match);
      Status locate(tagdbKey &, int, int &, tagdbNodeRef &, tagdbNodeRef &);
      Status getRef(tagdbKey &, tagdbNodeRef &ref);
      Status addRef(tagdbNode *node, tagdbKey *,tagdbNodeRef &ref, tagdbNode *&, tagdbKey *&, int &match);

    protected:
      static int nextVersion(int version);    
      friend class tagdbEngineBase;
      friend class tagdbItrBase;
      friend class tagdbNode;
      friend class ScenarioPlayer;
      friend class tagdbCachedNode;
      friend class TagdbScenarioPlayer;
      friend class tagdbInfo;

      tagdbEngineBase *_db;
      CATUnicodeString _root;
      tagdbKeyFactory _keyFactory;
      tagdbRecordFactory _recordFactory;      
      int _version;
      int _newVersion;
      tagdbId _max;
      tagdbId _usedNode; // Last Index of existing node in the store.
      tagdbId _empty;
      int *_current;     // Number of object in Nodes* on file
      int *_updated;
      Boolean *_flushed;
      Boolean _dirty;
      LinkedList *_buckets;
      LinkedList _mru;
      int _nodeCount;
      tagdbFile *_file;
      tagdbKey *_nullKey;
      tagdbRecord *_nullRecord;      

      // list of iterators
      void registerItr(tagdbItrBase *);
      void unregisterItr(tagdbItrBase *);
      void restartIterator(tagdbId);
      tagdbItrBase **_itrList;
      int _itrCount;
      int _itrSize;
  };

///////////////////////////////////////////////////////////////////////
  class tagdbNode {
    public:
      tagdbNode(tagdbStore *, tagdbId id);
      virtual ~tagdbNode();
      Status load();
      Status flush();
      Status update();
      Status remove(int index);
      void clear();
      Status tryload();
    protected:
      friend class tagdbEngineBase;
      friend class tagdbItrBase;
      friend class tagdbStore;
      friend class tagdbNodeRef;
      friend class tagdbCachedNode;
      friend class ScenarioPlayer;
      friend class TagdbScenarioPlayer;
      friend class tagdbInfo;

      tagdbStore * _store;
      NodeType _type;
      tagdbId _id;
      int _depth;
      int _usedKey;
      int _refCount;
      Boolean _dirty;
      Boolean _cached;
      tagdbKey *_key[CacheDegree+1];
      tagdbRecord *_ptr[CacheDegree+1];
  };

// -----------------------------------------------------------------------------
// Smart pointer on a TagdbNode.
// Because TagdbNode can be deleted at any moment (i.e. removed from the cache),
// Creating a TagdbNodeRef on a TagdbNode allows to keep it alive for a time
// -----------------------------------------------------------------------------
  class  ExportedBytagdb tagdbNodeRef {
    public:
      tagdbNodeRef();
      virtual ~tagdbNodeRef();
      Status get(tagdbRecord *&);
      Status set(tagdbRecord *);
      Status update();
      Status remove();
      Status remove(tagdbNodeRef &);
      Status release();
      void dup(tagdbNode *, int index=0);
      tagdbKey    *&key()     { return _node->_key[_index]; }
      tagdbRecord *&ptr()     { return _node->_ptr[_index]; }
      int           lastKey() { return _index == (_node->_usedKey-1); }
    protected:
      friend class tagdbEngineBase;
      friend class tagdbItrBase;
      friend class tagdbStore;
      friend class ScenarioPlayer;
      friend class TagdbScenarioPlayer;
      tagdbNode *_node;
      int _index;
  };

  ///////////////////////////////////////////////////////////////////////
  class tagdbCachedNode : public tagdbNodeRef {
    public:
      tagdbCachedNode(tagdbNode *node);
      virtual ~tagdbCachedNode();
    protected:
      friend class tagdbEngineBase;
      friend class tagdbItrBase;
      friend class tagdbStore;
      friend class tagdbInfo;

      LinkedList _bucket;
      LinkedList _mru;
  };

  ///////////////////////////////////////////////////////////////////////
  class ExportedBytagdb tagdbItrBase : public tagdbNodeRef {
    public:      
      tagdbItrBase(tagdbEngineBase * iDb, tagdbKey *iPrefix);
      virtual ~tagdbItrBase();
      void clear();
      Status next(int &);
      tagdbKey *getKey();      
      
    protected:
    
      Status _set(tagdbRecord *);
      
      friend class tagdbEngineBase;
      friend class tagdbStore;
      friend class TagdbScenarioPlayer;
      
      tagdbEngineBase *_db;
      tagdbStore  *_store;
      tagdbNodeRef _lastRef;
      tagdbKey    *_prefix;

      // refresh iterator if underlying node changes
      void restartIterator(tagdbId);
      Boolean _updating;
      Boolean _restart;
      tagdbKey *_restartKey;
  };   

///////////////////////////////////////////////////////////////////////
  class ExportedBytagdb tagdbEngineBase
  {
    public:
      tagdbEngineBase(int, int, tagdbFileFactory iFileFactory);
      virtual ~tagdbEngineBase();

      void checkCacheSize(tagdbCheckCacheSizeFunction);
      void informOnFileAccess(tagdbFileAccessObjFunc*);
      
      Status open(const CATUnicodeString & iRoot, tagdbKeyFactory iKeyFactory, tagdbRecordFactory iRecordFactory);
      Status activate(const  CATUnicodeString & iRoot, int =0);
      Status close();
      Status start(TransMode=NoLock);
      Status commit();
      Status abort();
      
      Status set(tagdbKey &key, tagdbRecord *rec);
      Status get(tagdbKey &key, tagdbRecord *&rec);
      
      Status hasNormalyEnded();
      
    protected:           
      Status _getRef(tagdbKey &key, tagdbNodeRef &ref);
            
      friend class tagdbItrBase;
      friend class tagdbStore;
      friend class ScenarioPlayer;
      friend class TagdbScenarioPlayer;
      
      int _size;
      int _degree;
      int _storeCount;
      int _active;
      Boolean _aborting;
      TransMode _mode; 
      tagdbStore *_store;
      tagdbStore *_storeList[MaxTable];
      tagdbFileFactory _fileFactory;
      tagdbCheckCacheSizeFunction _checkCacheSize;      
      tagdbFileAccessObjFunc * _informOnFileAccess;      
  };

///////////////////////////////////////////////////////////////////////
  template <class TypeKey, class TypeRecord>  
  class tagdbEngine : public tagdbEngineBase
  {
    public:
      tagdbEngine(int iSz=Small, int iDg=MaxDegree, tagdbFileFactory iFF=tagdbLocalFile::newInstance) 
        : tagdbEngineBase( iSz, iDg, iFF)
        {}
        
      virtual ~tagdbEngine() {}
      
      using tagdbEngineBase::open;
      Status open(const CATUnicodeString& iRoot) 
        {return open(iRoot,TypeKey::newInstanceFromFile,TypeRecord::newInstanceFromFile); }
      
      Status getRef(TypeKey &iKey, tagdbNodeRef &oRef) 
        { return _getRef(iKey,oRef); }
      
      using tagdbEngineBase::set;
      Status set(TypeKey &iKey   , TypeRecord *iRec)   
        { return tagdbEngineBase::set(iKey,iRec); }
        
      using tagdbEngineBase::get;
      Status get(TypeKey &iKey, TypeRecord *&oRec)     
        {
          tagdbRecord * localRec = 0;
          Status rc = tagdbEngineBase::get(iKey,localRec);
          oRec = static_cast<TypeRecord*>(localRec);
          return rc;
        }
  }; 
  
  template <class TypeKey, class TypeRecord>    
  class tagdbItr : public tagdbItrBase 
  {
    
    public:      
      tagdbItr(tagdbEngine<TypeKey,TypeRecord> *iDb, TypeKey &iPrefix) 
        : tagdbItrBase(iDb,iPrefix.copy()) 
        {}
        
      // Lifecycle : iptrPrefix is stolen by tagdbItrBase and cannot be NULL
      tagdbItr(tagdbEngine<TypeKey,TypeRecord> *iDb, TypeKey *iptrPrefix) 
        : tagdbItrBase(iDb,iptrPrefix) 
        {} 
      virtual ~tagdbItr() {}
      
      using tagdbNodeRef::get;
      using tagdbItrBase::getKey;
        
      TypeKey *getKey()  
        { return static_cast<TypeKey*>(tagdbItrBase::getKey());}
        
      Status get(TypeRecord *& oRec)
        {
          tagdbRecord * localRec = 0;
          Status rc = tagdbNodeRef::get(localRec);
          oRec = static_cast<TypeRecord*>(localRec);
          return rc;
        }
      Status set(TypeRecord * iRecord) 
        { return _set(iRecord);}
  };
}


#endif

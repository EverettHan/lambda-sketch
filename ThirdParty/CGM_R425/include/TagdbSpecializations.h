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

#ifndef TAGDBSPECIALIZATIONS_H
#define TAGDBSPECIALIZATIONS_H

#include "Tagdb.h"
#include "CATILockBytes2.h"
#include <string.h>

namespace Tagdb
{


  class ExportedBytagdb tagdbBlobKey : public tagdbKey
  {
    public:
      tagdbBlobKey(const void *data, int len);

      virtual tagdbKey *copy();
      virtual int compare(tagdbKey *);
      virtual int match(tagdbKey *);
      virtual Status write(tagdbFile *);
      virtual void release();

      static  Status newInstanceFromFile(tagdbKey *&, tagdbFile *);
      static  tagdbBlobKey *newInstance(const void *, int, CleanMode );

      void    getData(const void *&data, int &len) {data=_data;len=_len;}

    protected:
      const void *_data;
      int         _len;
      CleanMode   _dup;
  };


  class ExportedBytagdb tagdbShaStringKey : public tagdbKey
  {
    public:
      tagdbShaStringKey(const char *str);

      virtual tagdbKey *copy();
      virtual int compare(tagdbKey *);
      virtual int match(tagdbKey *);
      virtual Status write(tagdbFile *);
      virtual void release();

      static Status newInstanceFromFile(tagdbKey *&, tagdbFile *);
      static tagdbShaStringKey* newInstance(const char *);

      const char *getString() {return _str;}

    protected:
      const char *_str;
      int _len;
      Boolean _dup;
  };
  
  class ExportedBytagdb tagdbFixedSizeBlobKey : public tagdbKey
  {   
    public:  
      
      virtual ~tagdbFixedSizeBlobKey() {};
      
      virtual int          getRealSize() = 0;   // can return 0 or the fixed size
      virtual const void * getData()     = 0;
      void getData(const void *&data, int &len) { data = getData() ; len = getRealSize();}
      
      virtual int compare(tagdbKey *);
      virtual int match(tagdbKey *);
      virtual Status write(tagdbFile *);        
      virtual void release();             
      
      static Status newInstanceFromFile(tagdbKey *&, tagdbFile *);        
      static tagdbFixedSizeBlobKey * newInstance(const void *iData, int iSize);
      
    protected:
      tagdbFixedSizeBlobKey() {}; 
  };
  
  template <int SizeBlob> 
  class ExportedBytagdb tagdbFixedSizeBlobKeyTempl : public tagdbFixedSizeBlobKey
  {
    public:
      tagdbFixedSizeBlobKeyTempl(const void * iData=NULL)
        { 
          _fixed_data[0] = 0;
          if (iData)
          {
            _fixed_data[0] = 1;
            memcpy(_fixed_data+1, iData, SizeBlob);       
          }
        }
    
      virtual tagdbKey *copy()
        {          
          tagdbFixedSizeBlobKeyTempl<SizeBlob> * newkey = new tagdbFixedSizeBlobKeyTempl<SizeBlob>();
          memcpy(newkey->_fixed_data, _fixed_data, SizeBlob+1);
          return newkey;
        }
                        
      const void * getData()
        { return (_fixed_data[0] == 1) ? (_fixed_data+1) : NULL; }
      
      virtual int getRealSize() 
        { return (_fixed_data[0] == 1) ? SizeBlob : 0; }
      
    protected:         
      char _fixed_data[SizeBlob+1];
      friend class tagdbFixedSizeBlobKey;
  }; 
  
  // class ExportedBytagdb tagdbLockBytesFile : public tagdbFile
  // {
    // public:
      // tagdbLockBytesFile();
      // virtual ~tagdbLockBytesFile();
      // virtual int isOpen();
      // virtual Status fileOpen(const char *name, FileMode mode);
      // virtual Status close();
      // virtual Status read(void *, int, int &);
      // virtual Status write(const void *, int);
      // virtual Status lock(const char *);
      // virtual Status unlock(const char *);
      // virtual Status fileRemove(const char *);
      // static tagdbFile *newInstance();
      // virtual Status buildILB(const char *name);
    // protected:
      // CATILockBytes2 *_lb;
      // ULARGE_INTEGER _offset;
  // };

  class  ExportedBytagdb tagdbStringKey : public tagdbKey
  {
    public:
      tagdbStringKey(const char *str);

      virtual tagdbKey *copy();
      virtual int compare(tagdbKey *);
      virtual int match(tagdbKey *);
      virtual Status write(tagdbFile *);
      virtual void release();

      static Status newInstanceFromFile(tagdbKey *&, tagdbFile *);
      static tagdbStringKey *newInstance(const char *);

      const char * getString(int * oLen=0) { if (oLen) *oLen=_len; return _str; }

    protected:
      const char *_str;
      int _len;
      Boolean _dup;
  };

  class ExportedBytagdb tagdbBlobRecord : public tagdbRecord
  {
    public:
      void getData(const void *&data, int &len) {data=_data;len=_len;}
      virtual Status write(tagdbFile *);
      virtual void release();
      static Status newInstanceFromFile(tagdbRecord *&, tagdbFile *);
      static tagdbBlobRecord *newInstance(const void *, int, CleanMode );
      tagdbBlobRecord(const void *data, int len);
    protected:
      const void *_data;
      int _len;
      CleanMode _dup;
  };


  class ExportedBytagdb tagdbBlobRecordDouble : public tagdbRecord
  {
    public :
      void getData(const void *&data, int &len);
      virtual Status write(tagdbFile *);
      virtual void release();
      static Status newInstanceFromFile(tagdbRecord *&, tagdbFile *);
      static tagdbBlobRecordDouble *newInstance(const void *str, int len, Boolean dup = False);
      tagdbBlobRecordDouble(const void *data, int len);
    protected:
      const void *_data;
      int _len;
      Boolean _dup;
  };

  // For key and value as string (i.e. char * ending with 0)
  class  ExportedBytagdb tagdbEngineStrBlb : public tagdbEngine<tagdbStringKey, tagdbBlobRecord>
  {
    public:
      tagdbEngineStrBlb(int iSz=Small, int iDg=MaxDegree, tagdbFileFactory iFF=tagdbLocalFile::newInstance);
      virtual ~tagdbEngineStrBlb() {}

      using tagdbEngine<tagdbStringKey,tagdbBlobRecord>::set;
      using tagdbEngine<tagdbStringKey,tagdbBlobRecord>::get;

      Status set(const char *key, const char *value);
      Status set(const char *key, const void *data, int len);
      Status get(const char *key, const char *&value);
      Status get(const char *key, const void *&data, int &len);
  };

  // For key and value as blobl (i.e. char * ending with 0)
  class  ExportedBytagdb tagdbEngineBlbBlb : public tagdbEngine<tagdbBlobKey, tagdbBlobRecord>
  {
    public:
      tagdbEngineBlbBlb(int iSz=Small, int iDg=MaxDegree, tagdbFileFactory iFF=tagdbLocalFile::newInstance);
      virtual ~tagdbEngineBlbBlb(){}

      using tagdbEngine<tagdbBlobKey, tagdbBlobRecord>::set;
      using tagdbEngine<tagdbBlobKey, tagdbBlobRecord>::get;

      // Status set(const void *iDataKey, int iLenKey, const void *iDataRecord, int iLenRecord);
      Status get(const void *iDataKey, int iLenKey, const void *&oDataRecord, int &oLenRecord);
  };
  
 
  class  ExportedBytagdb tagdbEngineFBlbBlb : public tagdbEngine<tagdbFixedSizeBlobKey, tagdbBlobRecord>
  {
    public:
      tagdbEngineFBlbBlb(int iSz=Small, int iDg=MaxDegree, tagdbFileFactory iFF=tagdbLocalFile::newInstance);
      virtual ~tagdbEngineFBlbBlb(){}    
  };

  class ExportedBytagdb tagdbItrStrBlb : public tagdbItr<tagdbStringKey, tagdbBlobRecord>
  {
    public:
      tagdbItrStrBlb(tagdbEngineStrBlb * iDb, tagdbStringKey &iPrefix)
        : tagdbItr<tagdbStringKey, tagdbBlobRecord>(iDb,iPrefix)
        {}
      tagdbItrStrBlb(tagdbEngineStrBlb * iDb, const char * istrPrefix=NULL)
        // Null string is not authorized in tagdbStringKey as it is reserved for the last element of the tree
        : tagdbItr<tagdbStringKey, tagdbBlobRecord>(iDb,(istrPrefix?tagdbStringKey::newInstance(istrPrefix):tagdbStringKey::newInstance("")))
        {}
      virtual ~tagdbItrStrBlb(){}

      using tagdbItr<tagdbStringKey, tagdbBlobRecord>::set;
      using tagdbItr<tagdbStringKey, tagdbBlobRecord>::get;

      Status get(const char *&value);
      Status set(const char *value);
      Status get(const void *&data, int &len);
      Status set(const void *data, int len);
  };  
}

typedef Tagdb::tagdbFixedSizeBlobKey TagdbFBlobKey;
typedef Tagdb::tagdbBlobKey          TagdbBlobKey ;
typedef Tagdb::tagdbShaStringKey     TagdbShaStringKey;
typedef Tagdb::tagdbShaStringKey     TagdbStringKeySha;
// typedef Tagdb::tagdbLockBytesFile    TagdbLockBytesFile;
typedef Tagdb::tagdbStringKey        TagdbStringKey ;
typedef Tagdb::tagdbBlobRecord       TagdbBlobRecord ;
typedef Tagdb::tagdbBlobRecordDouble TagdbBlobRecordDouble;
typedef Tagdb::tagdbEngineStrBlb     TagdbStrBlb;
typedef Tagdb::tagdbEngineBlbBlb     TagdbBlbBlb;
typedef Tagdb::tagdbEngineFBlbBlb    TagdbFBlbBlb;
typedef Tagdb::tagdbItrStrBlb        TagdbItrStrBlb;
typedef Tagdb::tagdbItr<TagdbBlobKey , TagdbBlobRecord>               TagdbItrBlbBlb;
typedef Tagdb::tagdbItr<TagdbFBlobKey, TagdbBlobRecord>               TagdbItrFBlbBlb;
typedef Tagdb::tagdbEngine<TagdbStringKeySha, TagdbBlobRecordDouble> TagdbShaDbl;


#endif // TAGDBSPECIALIZATIONS_H

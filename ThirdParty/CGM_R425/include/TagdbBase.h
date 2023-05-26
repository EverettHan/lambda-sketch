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

#ifndef TAGDBBASE_H
#define TAGDBBASE_H

#if defined(__Tagdb)
#define ExportedBytagdb DSYExport
#else
#define ExportedBytagdb DSYImport
#endif
#include "DSYExport.h"

#include <stdio.h>
#include "CATUnicodeString.h"
#include "CATOmxSR.h"
#include "CATIOmxBinaryStream.h"

namespace Tagdb
{    
  class tagdbFile;
  class tagdbKey;
  class tagdbRecord;
  
  typedef int (*tagdbCheckCacheSizeFunction)();
  
#define MXUTIL_API

// this must be an integral type wide enough to hold a pointer.
#if defined(PLATEFORME_DS64) && defined(_WINDOWS_SOURCE)
  typedef long long tagdbId;
#else
  typedef long tagdbId;
#endif

#ifdef _MOBILE_SOURCE 
  // pour limiter la conso mémoire du cache sur les devices avec peu de ressources.. on réduit le degree du bTree.. on fera plus de swapping en contrepartie.. mais le cache étant plus petit (théoriquement) pas de pb. 
  enum Constants { RootNode=0, MaxDegree=512, CacheDegree=512, Small=32, Medium=128, Large=512, CacheSize=512, MaxTable=16 };
#else
  enum Constants { RootNode=0, MaxDegree=512, CacheDegree=2048, Small=32, Medium=128, Large=512, CacheSize=2048, MaxTable=16 };
  //enum Constants { RootNode=0, MaxDegree=512, CacheDegree=512, Small=32, Medium=128, Large=512, CacheSize=512, MaxTable=16 };
#endif
  enum TransMode { Temporary, NoLock };
  enum FileMode  { Read, Write };
  enum NodeType  { PointerList, ValueList};
  enum Boolean   { False, True};
  enum Status    { Ok, Error, Timeout, Insert, Changed, NotOpen, NotActive, Aborting, NonRecoverable };
  enum CleanMode { AutoCleaned, CharArrayDeleteClean, FreeClean};

  typedef tagdbFile *(*tagdbFileFactory)();
  typedef Status (*tagdbKeyFactory)(tagdbKey *&, tagdbFile *);
  typedef Status (*tagdbRecordFactory)(tagdbRecord *&, tagdbFile *);

  ///////////////////////////////////////////////////////////////////////
  class tagdbFileAccessObjFunc
  {
    public:
    virtual void operator () (const CATUnicodeString& iFilePath, int iFileMode ) = 0; // Read, Write, Remove=Write+1
  };
  
  static tagdbRecord *id2ptr(tagdbId id) { return (tagdbRecord *)id; }
  static const tagdbId ptr2id(const tagdbRecord *ptr) { return (tagdbId)ptr; }
  
  ///////////////////////////////////////////////////////////////////////
  class  ExportedBytagdb tagdbKey {
    public:
      virtual tagdbKey *copy() =0;
      virtual int compare(tagdbKey *) =0;
      virtual int match(tagdbKey *) =0;
      virtual Status write(tagdbFile *) =0;
      virtual void release() =0;      
  };

  ///////////////////////////////////////////////////////////////////////
  class ExportedBytagdb tagdbRecord {
    public:
      virtual Status write(tagdbFile *) =0;
      virtual void release() =0;      
  };

  ///////////////////////////////////////////////////////////////////////
  class ExportedBytagdb tagdbFile {
    public:
      tagdbFile() {_fileInformOnFileAccess=NULL;}
      virtual ~tagdbFile() {}
      
      Status init( FileMode);
      void informOnFileAccess(tagdbFileAccessObjFunc * iPtf) {_fileInformOnFileAccess=iPtf;}
      
      Status readInteger(int &);
      Status readtagdbId(tagdbId &);
      Status readString(const char *&);
      Status readBytes(const void *&, int &);
      Status writeInteger(int);
      Status writetagdbId(tagdbId);
      Status writeString(const char *);
      Status writeBytes(const void *, int);
      
      Status open(const CATUnicodeString& iName,  FileMode mode)
        {
          if (_fileInformOnFileAccess) (*_fileInformOnFileAccess)(iName,mode);
          return fileOpen(iName,mode);
        }
      Status remove(const CATUnicodeString& iName)
        {
          if (_fileInformOnFileAccess) (*_fileInformOnFileAccess)(iName,((int)Write)+1);
          return fileRemove(iName);
        }
      
      virtual int isOpen() =0;      
      virtual Status close() =0;
      virtual Status read(void *, int, int &) =0;
      virtual Status write(const void *, int) =0;
      virtual Status fileOpen(const CATUnicodeString& iName,  FileMode) =0;
      virtual Status fileRemove(const CATUnicodeString& iName) =0;
      
    protected:
      
      Status bufferedRead(const void *, int,  Boolean);
      Status bufferedWrite(const void *, int,  Boolean);
      Status flush();
      
      int _pos, _len;
      FileMode _mode;
      Boolean _swap;
      #define  IO_Buf_Size 131072 // 128*1024 = 128K
      char _buf[IO_Buf_Size];
      tagdbFileAccessObjFunc* _fileInformOnFileAccess;   
      friend class tagdbFixedSizeBlobKey;
  };

  ///////////////////////////////////////////////////////////////////////
  class ExportedBytagdb tagdbLocalFile : public tagdbFile 
  {
    public:
      tagdbLocalFile();
      virtual ~tagdbLocalFile();
      
      virtual int isOpen();
      virtual Status fileOpen(const CATUnicodeString& iName, FileMode mode);
      virtual Status close();
      virtual Status read(void *, int, int &);
      virtual Status write(const void *, int);
      virtual Status fileRemove(const CATUnicodeString& );
      
      static tagdbFile *newInstance();
      
    protected:
      
      CATOmxSR<CATIOmxBinaryStream> _Streamer;      
  };
}

#define TagdbCommon Tagdb
typedef Tagdb::tagdbRecord TagdbRecord ;
typedef Tagdb::tagdbKey    TagdbKey ;
typedef Tagdb::tagdbId     TagDbId;

#endif

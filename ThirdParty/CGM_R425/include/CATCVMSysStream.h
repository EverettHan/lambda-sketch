// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef CATCVMSysStream_H
#define CATCVMSysStream_H

#include "CATCVMSysObjects.h"
#include "CATCVMDef.h"
#include "CATLISTP_CATMathDirection.h"
#include "ListPOfCATCVMObject.h"

#include "CATMathDebug.h"
#include "CATDataType.h"

class CATMathStream;
class CATCVMAtom;
class CATCVMHandle;
class CATCVMObject;
class CATCVMContainer;
class CATCVMSystem;
class CATCVMComponent;
class CATCVMPort;
class CATCVMAttribute;
class CATMathTransformation;
class CATMathPoint2D;
class CATMathTransformation2D;

#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif
#include "CATCVMVersionDefinition.h"



class ExportedByCATCVMSysObjects CATCVMSysStream
{
public:

    CATCVMSysStream(CATMathStream * ioMathStream);
    ~CATCVMSysStream();

//    virtual void WriteListDirection(CATLISTP(CATMathDirection) & iListDirection);
//    virtual void ReadListDirection(CATLISTP(CATMathDirection) & oListDirection);
    
    virtual void WriteInt(int iInt);
    virtual int  ReadInt();

    virtual void WriteULong(CATULONG32 iULong);
    virtual CATULONG32  ReadULong();

	  virtual double ReadDouble();
	  virtual void WriteDouble(double iDouble);

    virtual void WriteString(const char* iString, const char iReservedLabel[] = "");
    virtual void ReadString(char*& ioString, const char iReservedLabel[] = "");
    
    virtual void WriteUChar(unsigned char iUChar);
    virtual unsigned char ReadUChar();

	virtual void WriteUChar(const unsigned char* iUCharArray, const CATLONG32 iNbCell);
    virtual void ReadUChar(unsigned char* ioArrayUChar, const CATLONG32 iNbCell);

//    virtual void WriteAtom(CATCVMAtom * iCVMAtom);
//    virtual void ReadAtom(CATCVMAtom * ioCVMAtom);
    
//    virtual void WriteHandle(CATCVMHandle * iCVMHandle);
//    virtual void ReadHandle(CATCVMHandle * ioCVMHandle);
    
    virtual void WriteObject(CATCVMObject * iCVMObject);
    virtual void ReadObject(CATCVMObject * ioCVMObject);
    
    virtual void WriteType(CATCVMObject * iCVMObject);
    virtual CATCVMObjectType ReadType();
    
    virtual void WriteTag(CATCVMObject * iCVMObject);
    virtual CATULONG32 ReadTag();

	virtual void WriteTransformation(CATMathTransformation Transformation);
	virtual void ReadTransformation(CATMathTransformation &Transformation);
    
    void WriteCVMObject(CATCVMObject *  iCVMObject);
    CATCVMObject * ReadCVMObject(CATCVMContainer * iCVMContainer=NULL);

    void WriteObjectTagList(ListPOfCATCVMObject & iListCVMObject);
    void ReadObjectTagList(ListPOfCATCVMObject & iListCVMObject);

	void WriteBoolean(const CATBoolean iBoolean);
	void ReadBoolean(CATBoolean& ioBoolean);
 
    void WriteMathPoint2D (CATMathPoint2D  iPoint);
    void ReadMathPoint2D (CATMathPoint2D & iPoint);

    void WriteTransformation2D (CATMathTransformation2D iTransfo);
    void ReadTransformation2D (CATMathTransformation2D &Transfo);


/*
    virtual CATCVMObject * Read(CATCVMSystem * iOwner);
    virtual CATCVMObject * Read(CATCVMObjectType iType, CATCVMSystem * iOwner);
  */  
    void WriteAttributes(CATCVMObject * ioCVMObject);
    void ReadAttributes(CATCVMObject * ioCVMObject);
    void WriteAttribute(CATCVMAttribute * iAttribute);
    CATCVMAttribute *ReadAttribute(CATCVMObject * iCVMObject);

    virtual CATCVMSystem * GetSystem(CATULONG32 iTag,CATCVMContainer * iCVMContainer=NULL);
    virtual CATCVMSystem * GetSystem(CATULONG32 iTag, CATCVMSystem * iOwner);
    virtual CATCVMHandle * GetHandle(CATULONG32 iTag, CATCVMContainer * iCVMContainer=NULL);
    virtual CATCVMHandle * GetHandle(CATULONG32 iTag, CATCVMSystem * iOwner);
    
    void    SetPreCheckMode (int Imode);
    int  GetPreCheckMode ();
	
	
    // for cgmreplay 
    void SetContainer(CATCVMContainer * ioCVMContainer);

    void SetVersionNumber (CATCVMStreamVersionId iVersionNumber);
    CATCVMStreamVersionId GetVersionNumber ();

protected:

   // void SetContainer(CATCVMContainer * ioCVMContainer);
    CATCVMContainer * GetContainer();
 
private:

    CATMathStream * _MathStream;
    int _PreCheckMode;
    CATCVMContainer * _Container;
    CATCVMStreamVersionId _StreamVersion;
};

#endif

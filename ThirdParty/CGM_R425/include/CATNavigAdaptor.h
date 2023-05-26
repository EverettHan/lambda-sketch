/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATNavigAdaptor_H_
#define CATNavigAdaptor_H_

/**
 * @level Protected
 * @usage U1
 */

#include <CATOmnMain.h>

#include "CATEventSubscriber.h"

class CATNavigAdaptor ;
typedef CATNavigAdaptor* CATNavigAdaptorRef;
typedef CATNavigAdaptor* CATNavigAdaptor_ptr;


class ExportedByCATOmnMain CATNavigAdaptor : public CATEventSubscriber
{
public:
//    CATDeclareClass;
    // Macro systeme CATDeclareClass expansee : on met en place l'heritage des types
public :
    virtual CATMetaClass *              __stdcall GetMetaObject() const;
    virtual CATClassId                  IsA() const;
    virtual int                         IsAKindOf(CATClassId) const;
    static CATMetaClass *               __stdcall MetaObject();
    static const CLSID &                __stdcall ClassId();
    static CATClassId                   __stdcall ClassName();
    static CATBaseUnknown *             CreateItself();

protected:
    static void                         InitStaticMetaObject();

    // Meta object statique de la classe de base
    static CATMetaClass*                _static_meta_object;
    // Meta object terminal dynamique
    CATMetaClass*                       _meta_object;

public:

//    CATNavigAdaptor (CATClassId type,CATClassId super_type=0) ;
    CATNavigAdaptor( CATMetaClass* meta_object );
    virtual ~CATNavigAdaptor () ;
    
    // Association d'une donnee

    void SetData(void*);
    void* GetData(void);   

    // Association d'une marquage

    void SetMarked(int mark=1);
    int  GetMarked();   
	
//    CATNavigAdaptor (const CATNavigAdaptor& from);
//    CATNavigAdaptor& operator= (const CATNavigAdaptor& from);
private:
	void* _data;
	int   _mark;
};

#endif


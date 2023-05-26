/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATMarshalMac                                                            */
/*                                                                           */
/*  Usage Notes:                                                             */
/*  Macros for Mashalling Implememtation                                     */
/*===========================================================================*/
/*  Creation September 1996                                                  */
/*===========================================================================*/
#ifndef __CATMarshalMac
#define __CATMarshalMac

#include <stdlib.h>
#include <stdio.h>
#ifndef _WINDOWS_SOURCE
#include "CATUniStd.h"
#endif
#include "CATBaseUnknown.h"
#include "CATMacInterface.h"
#include "CATMarshallableCorba.h"
#include "CATCreateCorba.h"
#include "CATSerialize.h"
#include "CATMarshal.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "string.h"
/*TRAINIT_EXTERN(MARSHAL)*/

#define NoPointerOnClass

ExportedByJS0MRSHL void CATSysMshLogUnmarshalError(const char *iType,const char *iClasse,int ibd,const char *iMsg=NULL,const char *iRealClass=NULL);
////////////////////////////////////////////////////////////////////////////////
//
//     MARSHALING-DEMARSHALING MODULARISE
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// MarshalBegin (<parametre_1>,<parametre_2>,<parametre_3>)
//
//   Entrees :
//   --------
//    <parametre_1> : Data Packet Identifier
//    <parametre_2> : Current Class
//    <parametre_3> : Verification flag for the object existence (unused)
//                    NOVERIF : no verification
//                    VERIF   : verification
//
////////////////////////////////////////////////////////////////////////////////

#define MarshalBegin(id_paquet,name_class,flag)                          \
									 \
									 \
static int buffer_id=0;                                                  \
static int rc=0;                                                         \
buffer_id = id_paquet;                                                   \
									 \
/*tra_act_init=0;*/                                                      \
									 \
/* CATClassId of class */                                                \
  CATClassId uuname_object =                                             \
		     name_class::ClassName();           		 \
rc = CATMakeMarshalIdent(buffer_id,internal,uuname_object,Othis);        \
if (rc == 0) return 0;



////////////////////////////////////////////////////////////////////////////////
//
// MarshalArchiveBegin (<parametre_1>,<parametre_2>,<parametre_3>,<parametre_4>)
//
//   Entrees :
//   --------
//    <parametre_1> : Data Packet Identifier
//    <parametre_2> : Current Class
//    <parametre_3> : Storing class pointer
//    <parametre_4> : Verification flag for the object existence (unused)
//                    NOVERIF : no verification
//                    VERIF   : verification
//
////////////////////////////////////////////////////////////////////////////////

#define MarshalArchiveBegin(id_paquet,name_class,store_class,flag)       \
									 \
name_class *Othis = (name_class *) GetImpl();                            \
static CATMarshal store_class(CATMarshalStore) ;                         \
store_class = GetMarshalArchive(id_paquet);                              \
									 \
MarshalBegin(id_paquet,name_class,flag)



////////////////////////////////////////////////////////////////////////////////
//
//   MakeMarshalIdent(<parametre_1>,<parametre_2>,<parametre_3>)
//
//    <parametre_1> : internal: check if the object is already marshaled (1)
//
//    <parametre_2> : current class
//
//    <parametre_3> : flag
//
//
////////////////////////////////////////////////////////////////////////////////



#define   MakeMarshalIdent(internal,name_class,flag)                     \
{                                                                        \
  static int ML_rc=0 ;                                                   \
									 \
  /*tra_level = 0;*/                                                     \
  /*TRAWRITE(MARSHAL,"BEGIN Marshalling Object "#name_class"")*/         \
									 \
  /* CATClassId of class */                                              \
									 \
  CATClassId uuname_object =                                             \
		     name_class::ClassName();           		 \
									 \
									 \
  ExportMarshalBuffer (buffer_id, (char *) uuname_object ,               \
			    strlen(uuname_object));                      \
									 \
									 \
  /*---------------------------------------------------------*/          \
  /* Check Object Process                                    */          \
  /*---------------------------------------------------------*/          \
									 \
  ML_rc = GetMarshalIdentObject(buffer_id, (void *)Othis, &internal );   \
									 \
  if ( ML_rc == 0 )                                                      \
  {									 \
    /*tra_level = 2;*/                                                   \
    /*TRAWRITE(MARSHAL,""#name_class" already marshalled\n")*/           \
    /*tra_level = 0;*/                                                   \
    /*TRAWRITE(MARSHAL,"BEGIN Marshalling Object "#name_class"")*/       \
    return 0;                                                            \
  }                                                                      \
									 \
									 \
}

////////////////////////////////////////////////////////////////////////////////
//
//   MarshalBaseClass(<parametre_1>,<parametre_2>)
//
//   Entrees :
//   --------
//    <parametre_1> : current class
//
//    <parametre_2> : base class
//
////////////////////////////////////////////////////////////////////////////////

#define MarshalBaseClass(name_class,name_class_pere)                    \
{                                                                       \
  CATMarshallableCorba *pt_marshal;                                     \
  CATSerialize *pt_serialize;                                           \
									\
  CATMarshalBaseClass();                                                \
									\
  CATBaseUnknown::QueryInterface (name_class_pere::ClassId(),           \
		  CATMarshallableCorba::ClassId(),                      \
		  (void**)&pt_marshal );                                \
									\
  if (pt_marshal != NULL)                                               \
  {                                                                     \
     Othis->AddRef();                                                   \
     SetData(pt_marshal,Othis);                                         \
     /*pt_marshal->SetImpl(Othis);*/                                    \
		                                                        \
     /* Marshalling */                                                  \
     /* ----------- */                                                  \
     pt_marshal->Marshalling(buffer_id,1);                              \
     pt_marshal->Release();                                             \
  }                                                                     \
  else                                                                  \
  {                                                                     \
									\
     CATBaseUnknown::QueryInterface (name_class_pere::ClassId(),        \
		     CATSerialize::ClassId(),                           \
		     (void**)&pt_serialize );                           \
     if (pt_serialize != NULL)                                          \
     {                                                                  \
	Othis->AddRef();                                                \
	SetData(pt_serialize,Othis);                                    \
	/*pt_serialize->SetImpl(Othis);*/                               \
									\
        /* Marshalling */                                               \
	/*-------------*/                                               \
        pt_serialize->Marshalling(buffer_id,1);                         \
	/*delete pt_serialize;*/                                        \
	pt_serialize->Release();                                        \
     }                                                                  \
     else                                                               \
        return 0;                                                       \
  }                                                                     \
									\
}

////////////////////////////////////////////////////////////////////////////////
//
//   MarshalReference(<parametre_1>,<parametre_2>,)
//
//   Entrees :
//   --------
//    <parametre_1> : current class
//
//    <parametre_2> : reference the pointed object
//
//
////////////////////////////////////////////////////////////////////////////////

#define MarshalReference(name_class,pointeur_objet)                   \
{                                                                     \
   static int rc;                                                     \
                                                                      \
   rc = CATMarshalReference(pointeur_objet,buffer_id);                \
   if (rc == 0) return 0;                                             \
								      \
}

////////////////////////////////////////////////////////////////////////////////
//
//   MarshalAggregate(<parametre_1>,<parametre_2>,<parametre_3>)
//
//   Entrees :
//   --------
//    <parametre_1> : current class (used for debug)
//
//    <parametre_2> : aggregate class
//
//    <parametre_3> : aggregate object (and NOT pointer to object aggregate)
//
//
////////////////////////////////////////////////////////////////////////////////

#define MarshalAggregate(name_class,name_class_agr,objet)               \
{                                                                       \
									\
  CATMarshallableCorba *pt_marshal;                                     \
  CATSerialize *pt_serialize;                                           \
									\
  if ( 0 == strncmp(#name_class_agr,"CATString",9)){                    \
    CATMarshalAggregate(buffer_id,&objet,NULL);                         \
  }else if ( 0 == strncmp(#name_class_agr,"CATUnicodeString",16)){      \
    CATMarshalAggregate(buffer_id,&objet,NULL);                         \
  } else {								\
    CATBaseUnknown::QueryInterface (name_class_agr::ClassId(),          \
		  CATMarshallableCorba::ClassId(),                      \
		  (void**)&pt_marshal );                                \
									\
    if (pt_marshal != NULL)                                             \
    {                                                                   \
     /*objet.AddRef();*/                                                \
     /*SetData(pt_marshal,&objet);*/                                    \
     CATMarshalAggregate(buffer_id,&objet,pt_marshal);                  \
     pt_marshal->Marshalling (buffer_id,0);                             \
     pt_marshal->Release();                                             \
    }                                                                   \
    else                                                                \
    {                                                                   \
     CATBaseUnknown::QueryInterface (name_class_agr::ClassId(),         \
		     CATSerialize::ClassId(),                           \
		     (void**)&pt_serialize );                           \
                                                                        \
     if (pt_serialize != NULL)                                          \
     {                                                                  \
	/*objet.AddRef();*/                                             \
	/*SetData(pt_serialize,&objet);*/                               \
	CATMarshalAggregate(buffer_id,&objet,pt_serialize);             \
        pt_serialize->Marshalling (buffer_id,0);                        \
	pt_serialize->Release();                                        \
     }                                                                  \
     else                                                               \
     {                                                                  \
        printf("MarshalAggregate Null Pointer");                        \
        printf("Marshalling interface doesn't exist :"#name_class_agr"\n"); \
        return 0;                                                       \
     }                                                                  \
    }                                                                     \
  }									\
									\
}


////////////////////////////////////////////////////////////////////////////////
//
//   MarshalEnd(<parametre_1>)
//
//   Entrees :
//   --------
//    <parametre_1> : marshalled class name (for debug)
//
////////////////////////////////////////////////////////////////////////////////

#define MarshalEnd(name_class)                                        \
{                                                                     \
								      \
  /*tra_level = 0;*/                                                  \
  /*TRAWRITE(MARSHAL,"END Marshalling Object "#name_class"")*/        \
  /* CATClassId of class */                                                \
  CATClassId uuname_object =                                             \
		     name_class::ClassName();                            \
  CATMakeMarshalEnd(uuname_object,Othis,buffer_id);                   \
  return 0;                                                           \
								      \
								      \
}


////////////////////////////////////////////////////////////////////////////////
//
//   UnmarshalBegin(id_paquet,internal,name_class,pt)
//
//   Entrees :
//   --------
//
//    id_paquet  : Data Buffer Identifier
//
//    internal   : Already Unmarshalled Object (object with 2 fathers)
//
//    name_class : Current Class
//
//    pt         : Pointer to the object to update (or create)
//
////////////////////////////////////////////////////////////////////////////////

#define UnmarshalBegin(id_paquet,internal,name_class,pt)                 \
									 \
									 \
static int buffer_id;                                                    \
static int done;                                                         \
  /*tra_act_init=0;*/                                                    \
									 \
  buffer_id = id_paquet;                                                 \
									 \
  name_class *DL_var_empile_pt;                                          \
  int DL_ident_objet=0;                                                  \
									 \
  DL_var_empile_pt = (name_class *) CATCreateBegin (buffer_id, internal, \
                     pt,done ,DL_ident_objet);                           \
  if (DL_var_empile_pt != NULL)                                          \
     return DL_var_empile_pt;                                            \



////////////////////////////////////////////////////////////////////////////////
//
//   UnmarshalArchiveBegin(id_paquet,internal,name_class,load_class,pt)
//
//   Entrees :
//   --------
//
//    id_paquet  : Data Buffer Identifier
//
//    internal   : Already Unmarshalled Object (object with 2 fathers)
//
//    name_class : Current Class
//
//    load_class : Loading Class
//
//    pt         : Pointer to the object to update (or create)
//
////////////////////////////////////////////////////////////////////////////////

#define UnmarshalArchiveBegin(id_paquet,internal,name_class,load_class,pt) \
                                                                         \
name_class *Othis = (name_class *) GetImpl();                            \
static CATMarshal load_class(CATMarshalLoad) ;                           \
load_class = GetMarshalArchive(id_paquet);                               \
								      \
UnmarshalBegin(id_paquet,internal,name_class,pt)


////////////////////////////////////////////////////////////////////////////////
//
//   UnmarshalInsideBegin(id_paquet,internal,name_class,load_class,pt)
//
//   Entrees :
//   --------
//
//    id_paquet  : Data Buffer Identifier
//
//    internal   : Already Unmarshalled Object (object with 2 fathers)
//
//    name_class : Current Class
//
//    load_class : Loading Class
//
//    pt         : Pointer to the object to update (or create)
//
////////////////////////////////////////////////////////////////////////////////

#define UnmarshalInsideBegin(id_paquet,internal,name_class,load_class,pt) \
                                                                         \
static CATMarshal load_class(CATMarshalLoad) ;                           \
load_class = GetMarshalArchive(id_paquet);                               \
static int buffer_id = id_paquet;



////////////////////////////////////////////////////////////////////////////////
//
//   CreateBegin(id_paquet,internal,name_class,pt,done)
//
//   Entrees :
//   --------
//
//    id_paquet  : Data Buffer Identifier
//
//    internal   : Already Unmarshalled Object (object with 2 fathers)
//
//    name_class : Current Class
//
//    pt         : Pointer to the object to update (or create)
//
//    done       : Create already done if done =-1
//
////////////////////////////////////////////////////////////////////////////////

#define CreateBegin(id_paquet,internal,name_class,pt,done)               \
									 \
static int buffer_id;                                                    \
                                                                         \
  buffer_id = id_paquet;                                                 \
									 \
  name_class *DL_var_empile_pt;                                          \
  int DL_ident_objet=0;                                                  \
									 \
  DL_var_empile_pt = (name_class *) CATCreateBegin (buffer_id, internal, \
                     pt,done ,DL_ident_objet);                           \
									 \


////////////////////////////////////////////////////////////////////////////////
//
//   CreateArchiveBegin(id_paquet,internal,name_class,load_class,pt,done)
//
//   Entrees :
//   --------
//
//    id_paquet  : Data Buffer Identifier
//
//    internal   : Already Unmarshalled Object (object with 2 fathers)
//
//    name_class : Current Class
//
//    load_class : Loading Class
//
//    pt         : Pointer to the object to update (or create)
//
//    done       : Create already done if done =-1
//
////////////////////////////////////////////////////////////////////////////////

#define CreateArchiveBegin(id_paquet,internal,name_class,load_class,pt,done) \
                                                                         \
name_class *Othis = (name_class *) GetImpl();                            \
static CATMarshal load_class(CATMarshalLoad) ;                           \
load_class = GetMarshalArchive(id_paquet);                               \
									 \
CreateBegin(id_paquet,internal,name_class,pt,done)                       \
									 \
memcpy( &pt, &DL_var_empile_pt, sizeof(DL_var_empile_pt));



////////////////////////////////////////////////////////////////////////////////
//
//   CreateUnmarshalObject(<parametre_1>)
//
//   Entrees :
//   --------
//    <parametre_1> : reference a new object
//
////////////////////////////////////////////////////////////////////////////////
#define CreateUnmarshalObject(pointeur_objet_courant)                      \
{                                                                          \
  /* Save ident / pt to the object        t */                             \
  /* in the ident-Othis list                */                             \
									   \
  /*tra_level = 2;*/                                                       \
  /*TRAWRITE (MARSHAL,"CreateUnmarshalObject Put New Objet\n")*/           \
  /*TRAWRITEI (MARSHAL, */                                                 \
  /*     "CreateUnmarshalObject ident = \n",(int*) DL_ident_objet)*/       \
									   \
  CreateUnmarshalIdent ( DL_ident_objet , pointeur_objet_courant) ;        \
									   \
  /*TRAWRITE (MARSHAL,"CreateUnmarshalObject New Object Done\n")*/         \
}


////////////////////////////////////////////////////////////////////////////////
//
//UnmarshalBaseClass(name_class,name_class_pere,pt_objet_courant)
//
//   Entrees :
//   --------
//    name_class       : Current Class Name
//
//    name_class_pere  : Base Class Name to call to be Unmarshallede
//
//    pt_objet_courant : Pointeur to the Current Object
//
//
////////////////////////////////////////////////////////////////////////////////

#define UnmarshalBaseClass(name_class,name_class_pere,pt_objet_courant)    \
{                                                                          \
									   \
  /*---------------------------------------------------------*/            \
  /*  CLASS IDENTIFIER                                       */            \
  /*                                                         */            \
  /* Unmarshalling Method Process                            */            \
  /*---------------------------------------------------------*/            \
  /*                                                         */            \
									   \
  /* Receive Class UUNAME                */                                \
									   \
  char    * DL_uuname_classe1=NULL;                                        \
  int       DL_uuname_classe_long1=0;                                      \
									   \
  int RcCUGCN=0;                                                           \
  RcCUGCN=CATUnmarshalGetClassName(                                        \
	    buffer_id,&DL_uuname_classe1,&DL_uuname_classe_long1 );        \
									   \
									   \
  /*TRAWRITE (MARSHAL,i*/                                                  \
  /*                "UnmarshalBaseClass BaseClass: "#name_class_pere"\n")*/\
  /*TRAWRITE (MARSHAL,"UnmarshalBaseClass Class: "#name_class"\n") */      \
									   \
  if (RcCUGCN==0 && DL_uuname_classe1)                                     \
  {									   \
   /*---------------------------------------------------------*/           \
   /* Ask for Unmarshalling in Inheritage case                */           \
   /*---------------------------------------------------------*/           \
									   \
   CATMarshallableCorba *pt_demarshal=NULL;                                \
   CATCreateCorba *pt_create=NULL;                                         \
   CATSerialize *pt_serialize=NULL;                                        \
   int done=-2;                                                            \
									   \
									   \
									   \
   CATBaseUnknown::QueryInterface( DL_uuname_classe1,                      \
				    CATMarshallableCorba::ClassId(),       \
				      (void**)&pt_demarshal);              \
   if (pt_demarshal != NULL)                                               \
   {                                                                       \
      (name_class_pere *) pt_demarshal->                                   \
                             Unmarshalling(buffer_id,pt_objet_courant,1);  \
      /*delete pt_demarshal;*/                                             \
      pt_demarshal->Release();                                             \
   }                                                                       \
   else                                                                    \
   {                                                                       \
     CATBaseUnknown::QueryInterface( DL_uuname_classe1,                    \
				    CATCreateCorba::ClassId(),             \
				      (void**)&pt_create);                 \
      if (pt_create != NULL)                                               \
      {                                                                    \
                                           \
         (name_class_pere *) pt_create->                                   \
                           CreateObject(buffer_id,pt_objet_courant,1,done);\
                                           \
       /*if (done != -1)*/                                               \
       /*{*/                                                             \
	    CATBaseUnknown::QueryInterface (DL_uuname_classe1,             \
			    CATSerialize::ClassId(),                       \
			    (void**)&pt_serialize );                       \
            if (pt_serialize != NULL)                                      \
            {                                                              \
               (name_class_pere *)pt_serialize->                           \
                             Unmarshalling(buffer_id,pt_objet_courant,1);  \
               pt_serialize->Release();                                    \
            }else {                                                        \
               return 0;                                                   \
            }                                                              \
       /*}*/                                                               \
     /*delete pt_create;*/                                                 \
	pt_create->Release();                                              \
      }                                                                    \
      else                                                                 \
      {                                                                    \
         printf("UnmarshalBaseClass uuname_class: %s\n",DL_uuname_classe1);\
         printf("UnmarshalBaseClass: Unknown Unmarshalling Interface\n");  \
         CATSysMshLogUnmarshalError("base_class",#name_class,buffer_id ,    \
                             "Unmarshaling interface not found",           \
                             DL_uuname_classe1);                           \
         return 0;                                                         \
      }                                                                    \
   }                                                                       \
									   \
   /*tra_level = 2; */                                                     \
   /*TRAWRITE (MARSHAL,"UnmarshalBaseClass End: "#name_class_pere"\n")*/   \
									   \
    delete [] DL_uuname_classe1;                                           \
  }                                                                        \
  else                                                                     \
  {                                                                        \
  /*  TRAWRITE (MARSHAL,"UnmarshalBaseClass Null Pointer\n")*/             \
        CATSysMshLogUnmarshalError("base_class",#name_class,buffer_id );   \
  }                                                                        \
									   \
}

////////////////////////////////////////////////////////////////////////////////
//
//   UnmarshalReference  (name_class,objet_pointeur,objet_pointe)
//
//   Entrees :
//   --------
//    name_class:          Current Class
//
//    objet_pointe:        NULL if no object (to be created)
//                         or pointer to an object
//
//   Sorties :
//   --------
//    objet_pointeur:      Pointer to the object
//
//
////////////////////////////////////////////////////////////////////////////////



#define  UnmarshalReference(name_class,objet_pointeur,objet_pointe)        \
{                                                                          \
									 \
  /*---------------------------------------------------------*/          \
  /* Unmarshalling Method Process                            */          \
  /*---------------------------------------------------------*/          \
									 \
  /* Receive Class UUNAME                */                              \
									 \
  char      *DL_uuname_classe=NULL;                                      \
  int       DL_uuname_classe_long=0;                                     \
									 \
  int RcCUGCN=CATUnmarshalGetClassName                                   \
	    (buffer_id,&DL_uuname_classe,&DL_uuname_classe_long );       \
  if (RcCUGCN==0 && DL_uuname_classe)                                    \
  {                                                                      \
    static const char *null_pt="__NULL_POINTER";                         \
									 \
    if ((DL_uuname_classe_long == strlen (null_pt)) &&                   \
      (!memcmp(DL_uuname_classe,null_pt, strlen (null_pt))) )            \
    {                                                                    \
    /*TRAWRITE (MARSHAL,"UnmarshalReference Null Pointer\n")*/           \
      objet_pointeur = NULL;                                             \
    }else if ( 0 == strncmp(DL_uuname_classe,"CATString",9)){            \
      CATString *ML_pt=NULL;                                             \
      if (objet_pointe == NULL ) {                                       \
      CATString *ptstr1 = new CATString;                                 \
      if ( ptstr1 )                                                      \
      {                                                                  \
        /*++IK8 - 14:04:23*/                                             \
        /*ML_pt=ptstr1->Unmarshalling(buffer_id,NULL,0);*/               \
        ML_pt = CATStringUnmarshalling( *ptstr1, buffer_id, NULL, 0 );   \
        /*--IK8 - 14:04:23*/                                             \
      }                                                                  \
     } else {                                                            \
      /*++IK8 - 14:04:23*/                                               \
      /*ML_pt=((CATString*)objet_pointe)->Unmarshalling(buffer_id,(CATString*)objet_pointe,0);*/\
      ML_pt = CATStringUnmarshalling( *((CATString *)objet_pointe), buffer_id, (CATString*)objet_pointe, 0 );\
      /*--IK8 - 14:04:23*/                                               \
     }                                                                   \
     memcpy( &objet_pointeur, &ML_pt, sizeof(ML_pt));                    \
    }else if ( 0 == strncmp(DL_uuname_classe,"CATUnicodeString",16)){    \
    CATUnicodeString *ML_pt=NULL;                                        \
    if (objet_pointe == NULL ) {                                         \
      CATUnicodeString *ptstr1 = new CATUnicodeString;                   \
      if (ptstr1)                                                        \
      {                                                                  \
        /*++IK8 - 14:04:23*/                                             \
        /*ML_pt=ptstr1->Unmarshalling(buffer_id,NULL,0);*/               \
        ML_pt = CATUnicodeStringUnmarshalling( *ptstr1, buffer_id, NULL, 0 );\
        /*--IK8 - 14:04:23*/                                             \
      }                                                                  \
    } else {                                                             \
      /*++IK8 - 14:04:23*/                                               \
      /*ML_pt=((CATUnicodeString*)objet_pointe)->Unmarshalling(buffer_id,(CATUnicodeString*)objet_pointe,0);*/\
      ML_pt = CATUnicodeStringUnmarshalling( *((CATUnicodeString*)objet_pointe), buffer_id, (CATUnicodeString*)objet_pointe, 0 );\
      /*--IK8 - 14:04:23*/                                               \
    }                                                                    \
     memcpy( &objet_pointeur, &ML_pt, sizeof(ML_pt));                    \
    } else {                                                             \
    /*---------------------------------------------------------*/        \
    /*  Receive and Call to the Unmarshalling Method           */        \
    /*---------------------------------------------------------*/        \
									 \
      CATMarshallableCorba *pt_demarshal=NULL;                           \
      CATCreateCorba *pt_create=NULL;                                    \
      CATSerialize *pt_serialize=NULL;                                   \
      CATBaseUnknown *ML_pt=NULL;                                        \
      int done=-2;                                                       \
									 \
									 \
               								 \
    CATBaseUnknown::QueryInterface( DL_uuname_classe,                    \
				    CATMarshallableCorba::ClassId(),     \
				      (void**)&pt_demarshal);            \
    if (pt_demarshal != NULL)                                            \
    {                                                                    \
       ML_pt = pt_demarshal->Unmarshalling                               \
			  (buffer_id,(CATBaseUnknown *)objet_pointe,0);  \
       /*delete pt_demarshal; */                                         \
       pt_demarshal->Release();                                          \
    }                                                                    \
    else                                                                 \
    {                                                                    \
									 \
       CATBaseUnknown::QueryInterface( DL_uuname_classe,                 \
				       CATCreateCorba::ClassId(),        \
				       (void**)&pt_create);              \
       if (pt_create != NULL)                                            \
       {                                                                 \
	  ML_pt = pt_create->CreateObject                                \
		(buffer_id,(CATBaseUnknown *)objet_pointe,0,done);       \
	  if (done != -1)                                                \
	  {                                                              \
	     /*pt_serialize = (CATSerialize *)ML_pt->            */      \
	     /*                 QueryInterface("CATSerialize");  */      \
	     ML_pt->QueryInterface (CATSerialize::ClassId(),             \
			     (void**)&pt_serialize );                    \
	     if (pt_serialize != NULL)                                   \
	     {                                                           \
		pt_serialize->Unmarshalling                              \
		     (buffer_id,(CATBaseUnknown *)ML_pt,0);              \
		/*delete pt_serialize;*/                                 \
		pt_serialize->Release();                                 \
	     }                                                           \
	     else                                                        \
		return 0;                                                \
	  }                                                              \
      /*delete pt_create;  */                                            \
          pt_create->Release();                                          \
       }                                                                 \
       else                                                              \
       {                                                                 \
	  printf("UnmarshalReference NULL Unmarshal Pointer\n");         \
	  printf("UnmarshalReference Unknown Interface: "#name_class"\n"); \
          CATSysMshLogUnmarshalError("reference",#name_class,buffer_id , \
                             "Unmarshaling interface not found",         \
                             DL_uuname_classe);                          \
	  return 0;                                                      \
       }                                                                 \
      }                                                                  \
									 \
      memcpy( &objet_pointeur, &ML_pt, sizeof(ML_pt));                   \
									 \
    }                                                                    \
    delete [] DL_uuname_classe;                                          \
  }                                                                      \
  else                                                                   \
  {                                                                      \
    CATSysMshLogUnmarshalError("reference",#name_class,buffer_id);       \
  }                                                                      \
}

////////////////////////////////////////////////////////////////////////////////
//
//   UnmarshalAggregate (name_class,name_class_agregee,objet_pointeur)
//
//   Entrees :
//   --------
//    name_class:      Current Class Name
//
//    name_class_agr:  Aggregate Class Name
//
//
//   Sorties :
//   --------
//    objet_pointeur:  Pointer to the Aggregate Object
//
//
////////////////////////////////////////////////////////////////////////////////



#define  UnmarshalAggregate(name_class,name_class_agr,objet_pointeur)    \
{                                                                        \
									 \
  static char *DL_uuname_classe;                                         \
  static int  DL_uuname_classe_long = 0;                                 \
									 \
  int rcCUGCN=CATUnmarshalGetClassName                                   \
	    (buffer_id,&DL_uuname_classe,&DL_uuname_classe_long );       \
  if ( rcCUGCN == 0 )                                                    \
  {		                              				 \
  static char *uuname_null=NULL;                                         \
									 \
  if (DL_uuname_classe == uuname_null)                                   \
  {                                                                      \
    /*TRAWRITE (MARSHAL,"UnmarshalAggregate Pointer Null\n")*/           \
                                                                         \
  }else if ( 0 == strncmp(DL_uuname_classe,"CATString",9)){              \
                                                                         \
    CATUnmarshalCallAg(buffer_id,&objet_pointeur,(void*)&objet_pointeur);\
    /*((CATString*)&objet_pointeur)->Unmarshalling(buffer_id,(CATString*)&objet_pointeur,0);*/\
                                                                         \
                                                                         \
  }else if ( 0 == strncmp(DL_uuname_classe,"CATUnicodeString",16)){      \
                                                                         \
    CATUnmarshalCallAg(buffer_id,&objet_pointeur,(void*)&objet_pointeur);\
    /*((CATUnicodeString*)&objet_pointeur)->Unmarshalling(buffer_id,(CATUnicodeString*)&objet_pointeur,0);*/\
                                                                         \
                                                                         \
  } else {                                                               \
    /*---------------------------------------------------------*/        \
    /*  Search and Call to the Unmarshalling Method            */        \
    /*---------------------------------------------------------*/        \
									 \
    CATMarshallableCorba *pt_demarshal=NULL;                             \
    CATCreateCorba *pt_create=NULL;                                      \
    CATSerialize *pt_serialize=NULL;                                     \
    CATBaseUnknown *pt_object=NULL;                                      \
    int done=-2;                                                         \
									 \
									 \
    CATBaseUnknown::QueryInterface( DL_uuname_classe,                    \
				    CATMarshallableCorba::ClassId(),     \
				    (void**)&pt_demarshal);              \
									 \
    if (pt_demarshal != NULL)                                            \
    {                                                                    \
      /* (name_class_agr *)pt_demarshal->Unmarshalling     */            \
      /*	 (buffer_id,(CATBaseUnknown*)&objet_pointeur,0);*/       \
       CATUnmarshalCallAg(buffer_id,pt_demarshal,(void*)&objet_pointeur);       \
       pt_demarshal->Release();                                          \
    }                                                                    \
    else                                                                 \
    {                                                                    \
									 \
       CATBaseUnknown::QueryInterface( DL_uuname_classe,                 \
				       CATCreateCorba::ClassId(),        \
				       (void**)&pt_create);              \
       if (pt_create != NULL)                                            \
       {                                                                 \
	  CATUnmarshalCreateAg(buffer_id,pt_create,&objet_pointeur,done);       \
	  /*(name_class_agr *)pt_create->CreateObject                    */  \
          /*	    (buffer_id,(CATBaseUnknown *)&objet_pointeur,0,done);*/\
	     pt_object =(CATBaseUnknown*) &objet_pointeur;                                \
	     pt_object->QueryInterface (CATSerialize::ClassId(),         \
			     (void**)&pt_serialize );                    \
	     if (pt_serialize != NULL)                                   \
	     {                                                           \
		/*pt_serialize->Unmarshalling(buffer_id,          */     \
        	/*	     (CATBaseUnknown *)&objet_pointeur,1);*/     \
                CATUnmarshalCallAg(buffer_id,pt_serialize,(void*)&objet_pointeur);       \
		pt_serialize->Release();                                 \
	     }                                                           \
	     else                                                        \
		return 0;                                                \
	  pt_create->Release();                                          \
       }                                                                 \
       else                                                              \
       {                                                                 \
	  printf("UnmarshalAggregate DL_uuname_class:%s\n",              \
	         DL_uuname_classe );                                     \
	  printf("UnmarshalAggregateNULL pointer");                      \
	  printf("Unknown Unmarshalling Interface: "#name_class"\n");    \
          CATSysMshLogUnmarshalError("aggregate",#name_class,buffer_id,  \
                       "Unmarshalling interface not found",              \
                        DL_uuname_classe);                               \
	  return 0;                                                      \
       }                                                                 \
    }                                                                    \
									 \
  }                                                                      \
  if ( DL_uuname_classe)                                                 \
    delete [] DL_uuname_classe;                                          \
  }                                                                      \
  else                                                                   \
  {		                              				 \
    CATSysMshLogUnmarshalError("aggregate",#name_class,buffer_id);       \
  }                                                                      \
}

////////////////////////////////////////////////////////////////////////////////
//
//   CreateObjectEnd(name_class,pt_courant)
//
//   Entrees :
//   --------
//
//    name_class : Current Class Name
//    pt_courant : Pointer to the Current Object
//
////////////////////////////////////////////////////////////////////////////////

#define CreateObjectEnd(name_class,pt_courant)                        \
{                                                                     \
  return pt_courant;                                                  \
								      \
}
////////////////////////////////////////////////////////////////////////////////
//
//   UnmarshalEnd(name_class,pt_courant)
//
//   Entrees :
//   --------
//
//    name_class : Current Class Name
//    pt_courant : Pointer to the Current Object
//
////////////////////////////////////////////////////////////////////////////////

#define UnmarshalEnd(name_class,pt_courant)                           \
								      \
{                                                                     \
								      \
  CATMakeUnmarshalEnd(buffer_id);                                      \
  return pt_courant;                                                  \
								      \
								      \
}

#endif

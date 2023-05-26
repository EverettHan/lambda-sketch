// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATNewClassArray :
// MACRO utilise pour surcharge du new et du delete  
//
//=============================================================================
// Usage notes:
// La desallocation de la memoire utilisée pour la gestion des new et delete 
// est faite par l'appel au destructeur de CATNewArray au déchargement des libs
// sur le static Class::NewArray  
//  
//=============================================================================
// fEV. 98  Creation                          L. Rageul
#include <string.h>
#include <stdlib.h>

#ifndef __CATNewClassArray
#define __CATNewClassArray

#ifdef PLATEFORME_DS64

//IA64+
//
// A lot of changes in this header file for IA-64 support.
//
// Mainly "CATLONPTR" usage ( + "sizeof(CATLONPTR)" vs "[+,-,*,/][8,2]", ...
// + hard-coded length and factors earlier and only IA32/32 bits sizes+types
// purpose !!) to guarantee IA-32 backward compatibility.
//
// The same changes must also be applied to dual+mirror header file 
// "System\JS0CORBA.m\LocalInterfaces\CATNewClassArray2.h" 
//
//IA64-

#include <string.h>
#include <stdlib.h>
#include "CATDataType.h"


#ifndef CATNewClassArrayDeclare
#define CATNewClassArrayDeclare							\
public:                             		\
    void *operator new (size_t);						\
    void  operator delete(void *);						\
    static void  DeleteAlloc();							\
    static CATUINTPTR *ZoneArray;							\
    static CATUINTPTR *LastDirectBloc;							\
    static CATUINTPTR *NextFreeBloc;							\
    static unsigned int  NbFreeBloc;							\
    static unsigned int  NbNewFreeBloc;							\
/* //IA64C    static unsigned int  BlocSize;	//IA64+ */ static size_t  BlocSize; /* //IA64- */ \
    static unsigned int *DevStage;					\
    static unsigned int  DevStageNull

#endif

#ifndef CATNewClassArrayDefine
#define CATNewClassArrayDefine(CLASS,NBNEWBLOC)					\
CATUINTPTR  *CLASS::ZoneArray = NULL;						\
CATUINTPTR  *CLASS::LastDirectBloc = NULL;						\
CATUINTPTR  *CLASS::NextFreeBloc = NULL;						\
unsigned int   CLASS::NbFreeBloc = 0;							\
unsigned int   CLASS::NbNewFreeBloc = 0;							\
/* //IA64Cunsigned int   CLASS::BlocSize = 0; //IA64+ */ size_t   CLASS::BlocSize = 0;	/* //IA64- */	\
unsigned int  *CLASS::DevStage = NULL;							\
unsigned int   CLASS::DevStageNull = 0;				\
void *CLASS::operator new(size_t Size)						\
{										\
    if (!DevStage)                                                              \
    {                                                                           \
       CATDevelopmentStage(&DevStage);                                          \
       if (DevStage && *DevStage)                                               \
       {                                                                        \
          char *nomallocvarname=new char[strlen(#CLASS)+9];                     \
          if ( nomallocvarname )                                                \
          {                                                                     \
             nomallocvarname[0]='\0';                                           \
             strcat(nomallocvarname,"BLKALLOC");                                \
             strcat(nomallocvarname,#CLASS);                                    \
             if ( getenv(nomallocvarname) )                                     \
                DevStage=&DevStageNull;                                         \
             delete [] nomallocvarname;                                         \
          }                                                                     \
       }                                                                        \
    }                                                                           \
    if (DevStage && *DevStage) return(malloc(Size));				\
    if (ZoneArray == NULL)							\
    {										\
    	NbFreeBloc = 0;								\
    	NbNewFreeBloc = 0;							\
    	BlocSize = Size/sizeof(CATUINTPTR);							\
    	if (Size-sizeof(CATUINTPTR)*(Size/sizeof(CATUINTPTR))) BlocSize++;					\
    }										\
    if (!NbFreeBloc && !NbNewFreeBloc)						\
    {										\
	size_t 	Allocation = NBNEWBLOC*BlocSize*sizeof(CATUINTPTR)+/* Sizemin for 2 unsigned inter-blocs pounsigned inters+linkage embedded+at beginning of each zone+bloc */ 2 * sizeof(CATUINTPTR);	\
	NbFreeBloc += NBNEWBLOC;						\
	CATUINTPTR *NewZone = (CATUINTPTR*)malloc(Allocation);			\
	LastDirectBloc = NewZone+2-BlocSize;					\
	if (ZoneArray)								\
	{									\
		*NewZone = (CATUINTPTR)ZoneArray;					\
		CATUINTPTR *NextZone = (CATUINTPTR*)*(ZoneArray+1);			\
		*(ZoneArray+1) = (CATUINTPTR)NewZone;				\
		*(NewZone+1) = (CATUINTPTR)NextZone;				\
		*(NextZone) = (CATUINTPTR)NewZone;					\
		ZoneArray = NewZone;						\
	}									\
	else									\
	{									\
		ZoneArray = NewZone;						\
		*NewZone = (CATUINTPTR)NewZone;					\
		*(NewZone+1) = (CATUINTPTR)NewZone;				\
	}									\
    }										\
    if (NbFreeBloc)								\
    {										\
	NbFreeBloc+=-1;								\
	LastDirectBloc+=BlocSize;						\
	return (void *)LastDirectBloc;						\
    }										\
    CATUINTPTR *result = NextFreeBloc;						\
    NbNewFreeBloc+=-1;								\
    if (NextFreeBloc)								\
    {										\
	CATUINTPTR *PrevBloc = (CATUINTPTR*)*result;					\
	CATUINTPTR *NextBloc = (CATUINTPTR*)*(result+1);				\
	*(PrevBloc+1) = (CATUINTPTR)NextBloc;					\
	*(NextBloc) = (CATUINTPTR)PrevBloc;					\
	NextFreeBloc = NextBloc;					\
    }										\
    return (void *)result;							\
}										\
void CLASS::operator delete(void *BlocToFree)					\
{										\
    if (DevStage && *DevStage)							\
    {										\
       free(BlocToFree);							\
       return;									\
    }										\
    if (NbNewFreeBloc)								\
    {										\
	CATUINTPTR * PrevBloc = (CATUINTPTR*) *(NextFreeBloc );			\
	*(PrevBloc+1)  = (CATUINTPTR) ((CATUINTPTR*)BlocToFree);			\
	*((CATUINTPTR*)BlocToFree)  = (CATUINTPTR) PrevBloc ;				\
	*(((CATUINTPTR*)BlocToFree)+1) = (CATUINTPTR) NextFreeBloc;			\
	*(NextFreeBloc) = (CATUINTPTR) ((CATUINTPTR*)BlocToFree);			\
    }										\
    else									\
    {										\
	*((CATUINTPTR*)BlocToFree) = (CATUINTPTR)((CATUINTPTR*)BlocToFree);		\
	*(((CATUINTPTR*)BlocToFree)+1) = (CATUINTPTR)((CATUINTPTR*)BlocToFree);		\
    }										\
    NextFreeBloc = (CATUINTPTR*) BlocToFree ;					\
    NbNewFreeBloc ++;								\
}										\
void CLASS::DeleteAlloc()							\
{										\
    if (ZoneArray)								\
    {										\
	CATUINTPTR *RefZone = (CATUINTPTR*)ZoneArray;					\
	CATUINTPTR *IsZone = (CATUINTPTR*)*(RefZone+1);				\
	free (RefZone);								\
	while (((CATUINTPTR)IsZone) != ((CATUINTPTR)RefZone))				\
	{									\
		void *ZoneToDelete = (void*)IsZone;				\
		IsZone = (CATUINTPTR*)*((CATUINTPTR*)IsZone+1);			\
		free (ZoneToDelete);						\
	}									\
	ZoneArray = NULL;							\
    }										\
}

#endif

#else

#ifndef CATNewClassArrayDeclare
#define CATNewClassArrayDeclare							\
public:                             		\
    void *operator new (size_t);						\
    void  operator delete(void *);						\
    static void  DeleteAlloc();							\
    static unsigned int *ZoneArray;							\
    static unsigned int *LastDirectBloc;							\
    static unsigned int *NextFreeBloc;							\
    static unsigned int  NbFreeBloc;							\
    static unsigned int  NbNewFreeBloc;							\
    static unsigned int  BlocSize;							\
    static unsigned int *DevStage;                                                       \
    static unsigned int  DevStageNull

#endif

#ifndef CATNewClassArrayDefine
#define CATNewClassArrayDefine(CLASS,NBNEWBLOC)					\
unsigned int  *CLASS::ZoneArray = NULL;							\
unsigned int  *CLASS::LastDirectBloc = NULL;						\
unsigned int  *CLASS::NextFreeBloc = NULL;						\
unsigned int   CLASS::NbFreeBloc = 0;							\
unsigned int   CLASS::NbNewFreeBloc = 0;							\
unsigned int   CLASS::BlocSize = 0;							\
unsigned int  *CLASS::DevStage = NULL;							\
unsigned int   CLASS::DevStageNull = 0;   						\
void *CLASS::operator new(size_t Size)						\
{										\
    if (!DevStage)                                                              \
    {                                                                           \
       CATDevelopmentStage(&DevStage);                                          \
       if (DevStage && *DevStage)                                               \
       {                                                                        \
          char *nomallocvarname=new char[strlen(#CLASS)+9];                     \
          if ( nomallocvarname )                                                \
          {                                                                     \
             nomallocvarname[0]='\0';                                           \
             strcat(nomallocvarname,"BLKALLOC");                                \
             strcat(nomallocvarname,#CLASS);                                    \
             if ( getenv(nomallocvarname) )                                     \
                DevStage=&DevStageNull;                                         \
             delete [] nomallocvarname;                                         \
          }                                                                     \
       }                                                                        \
    }                                                                           \
    if (DevStage && *DevStage) return(malloc(Size));				\
    if (ZoneArray == NULL)							\
    {										\
    	NbFreeBloc = 0;								\
    	NbNewFreeBloc = 0;							\
    	BlocSize = Size/8;							\
    	if (Size-8*(Size/8)) BlocSize++;					\
    }										\
    if (!NbFreeBloc && !NbNewFreeBloc)						\
    {										\
	size_t 	Allocation = NBNEWBLOC*8*BlocSize+8;				\
	NbFreeBloc += NBNEWBLOC;						\
	unsigned int *NewZone = (unsigned int*)malloc(Allocation);				\
	LastDirectBloc = NewZone+2-2*BlocSize;					\
	if (ZoneArray)								\
	{									\
		*NewZone = (unsigned int)ZoneArray;					\
		unsigned int *NextZone = (unsigned int*)*(ZoneArray+1);				\
		*(ZoneArray+1) = (unsigned int)NewZone;					\
		*(NewZone+1) = (unsigned int)NextZone;					\
		*(NextZone) = (unsigned int)NewZone;					\
		ZoneArray = NewZone;						\
	}									\
	else									\
	{									\
		ZoneArray = NewZone;						\
		*NewZone = (unsigned int)NewZone;					\
		*(NewZone+1) = (unsigned int)NewZone;					\
	}									\
    }										\
    if (NbFreeBloc)								\
    {										\
	NbFreeBloc+=-1;								\
	LastDirectBloc+=2*BlocSize;						\
	return (void *)LastDirectBloc;						\
    }										\
    unsigned int *result = NextFreeBloc;							\
    NbNewFreeBloc+=-1;								\
    if (NextFreeBloc)								\
    {										\
	unsigned int *PrevBloc = (unsigned int*)*result;						\
	unsigned int *NextBloc = (unsigned int*)*(result+1);					\
	*(PrevBloc+1) = (unsigned int)NextBloc;						\
	*(NextBloc) = (unsigned int)PrevBloc;						\
	NextFreeBloc = NextBloc;						\
    }										\
    return (void *)result;							\
}										\
void CLASS::operator delete(void *BlocToFree)					\
{										\
    if (DevStage && *DevStage)							\
    {										\
       free(BlocToFree);							\
       return;									\
    }										\
    if (NbNewFreeBloc)								\
    {										\
	unsigned int * PrevBloc = (unsigned int*) *(NextFreeBloc );				\
	*(PrevBloc+1)  = (unsigned int) ((unsigned int*)BlocToFree);				\
	*((unsigned int*)BlocToFree)  = (unsigned int) PrevBloc ;					\
	*(((unsigned int*)BlocToFree)+1) = (unsigned int) NextFreeBloc;				\
	*(NextFreeBloc) = (unsigned int) ((unsigned int*)BlocToFree);				\
    }										\
    else									\
    {										\
	*((unsigned int*)BlocToFree) = (unsigned int)((unsigned int*)BlocToFree);				\
	*(((unsigned int*)BlocToFree)+1) = (unsigned int)((unsigned int*)BlocToFree);			\
    }										\
    NextFreeBloc = (unsigned int*) BlocToFree ;						\
    NbNewFreeBloc ++;								\
}										\
void CLASS::DeleteAlloc()							\
{										\
    if (ZoneArray)								\
    {										\
	unsigned int *RefZone = (unsigned int*)ZoneArray;						\
	unsigned int *IsZone = (unsigned int*)*(RefZone+1);					\
	free (RefZone);								\
	while (((unsigned int)IsZone) != ((unsigned int)RefZone))					\
	{									\
		void *ZoneToDelete = (void*)IsZone;				\
		IsZone = (unsigned int*)*((unsigned int*)IsZone+1);				\
		free (ZoneToDelete);						\
	}									\
	ZoneArray = NULL;							\
    }										\
}
#endif

#endif
#endif

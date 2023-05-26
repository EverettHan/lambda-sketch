//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997
//============================================================================
//
// macro CATLISTP_ODT(T):
//	This generate expands in a program that performs a basic call to all
//	the methods contained in the recommended interface.
//	The CATLISTP(T) class should have been generated using that header :
//	#include "CATLISTP_PublicInterface.h"
//	(it has all the recommended #define)
//
//============================================================================
//	
// Usage:
//	Edit a .cpp in a .mtst module in that style :
//
//	/*
//	** headers of collection-classes
//	*/
//	#include "CATLISTP_MyClass.h"
//	#include "CATLISTP_AnotherClass.h"
//	#include "CATLISTP_OneMoreClass.h"
//	/*
//	** headers for macro used to generate code
//	*/
//	#include "CATLISTP_BodyOfODT.h"
//	/*
//	** generation of code calling services of collection-classes
//	*/
//	CATLISTP_ODT(MyClass)
//	CATLISTP_ODT(AnotherClass)
//	CATLISTP_ODT(OneMoreClass)
//	int main()
//	{ 
//	  return 0 ;
//	} 
//
//============================================================================
// Mar. 97	Initial coding				Ph.Baucher
//============================================================================

#ifndef CATLISTP_BodyOfODT_H
#define CATLISTP_BodyOfODT_H

#include "CATAssert.h"
#include "CATCollec.h"


#define	CATLISTP_ODT(T)								\
static										\
int	CATLISTP_Sort##T( T*, T* )						\
{ return 0; } 									\
static										\
int	CATLISTP_Test_##T()							\
{										\
  /* test cdtors */								\
  CATLISTP(T)	L1;								\
  CATLISTP(T)	L2(L1);								\
  CATLISTP(T)	L3(100);							\
  T**	array = NULL ;								\
  CATLISTP(T)*	PL4 = new CATLISTP(T) ( array, 0 );				\
  delete PL4;									\
  L1 = L3 ;									\
  /* size */									\
  L1.Size(50);									\
  int	size = L1.Size();							\
  /* additions */								\
  L1.Append( (T*)0 );								\
  L1.Append( L2 );								\
  L1.InsertAt( size, (T*)0 );							\
  /* indexing */								\
  T*	ptr = L1[1];								\
  const CATLISTP(T)&	tmp = L1 ;						\
  ptr = tmp[1] ;								\
  CATAssert( L1.Locate( (T*)0 ) );							\
  /* removals */								\
  L1.Remove( L2 );								\
  L1.RemovePosition( size );							\
  L1.RemoveValue( (T*)0 ); 							\
  L1.RemoveNulls();								\
  L1.RemoveDuplicates();							\
  L1.RemoveAll();								\
  /* comparisons */								\
  CATAssert( L1 == L2 );								\
  CATAssert( !(L1 != L2) );							\
  CATLISTP(T)::Compare( L1, L2, &CATLISTP_Sort##T );				\
  /* moves */									\
  L1.Append( (T*)0 );								\
  L1.Append( (T*)0 );								\
  L1.Swap( 1, 2 );								\
  L1.QuickSort( &CATLISTP_Sort##T );						\
  /* miscellanous */								\
  L1.FillArray( array, 0 );							\
  L1.NbOccur( (T*)0 );								\
  CATLISTP(T)::Intersection( L1, L2, L3 );					\
  /* exit */									\
  return 0 ;									\
}										\
static										\
int	CATLISTP_Dummy##T = CATLISTP_Test_##T() ;



#endif

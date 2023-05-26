//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997
//============================================================================
//
// macro CATHDICO_ODT(T):
//	This macro expands in a program that performs a basic call to all
//	the methods contained in the recommended interface.
//	The CATHDICO(T) class should have been generated using that header :
//	#include "CATHDICO_PublicInterface.h"
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
//	#include "CATHDICO_MyClass.h"
//	#include "CATHDICO_AnotherClass.h"
//	#include "CATHDICO_OneMoreClass.h"
//	/*
//	** headers for macro used to generate code
//	*/
//	#include "CATHDICO_BodyOfODT.h"
//	/*
//	** generation of code calling services of collection-classes
//	*/
//	CATHDICO_ODT(MyClass)
//	CATHDICO_ODT(AnotherClass)
//	CATHDICO_ODT(OneMoreClass)
//	int main()
//	{ 
//	  return 0 ;
//	} 
//
//============================================================================
// Avr. 97	Initial coding				Ph.Baucher
//============================================================================

#ifndef CATHDICO_BodyOfODT_H
#define CATHDICO_BodyOfODT_H

#include "CATCollec.h"
#include "CATHashCodeIter.h"
#include "CATUnicodeString.h"
#include "CATAssert.h"


#define	CATHDICO_ODT(T)								\
static										\
int	CATHDICO_GlobalFunct##T( T* )						\
{ return 0; } 									\
static										\
int	CATHDICO_Test_##T()							\
{										\
  static									\
  CATUnicodeString	toto("toto");						\
  /* test cdtors */								\
  CATHDICO(T)	H1;								\
  CATHDICO(T)	H2(H1);								\
  CATHDICO(T)	H3(100);							\
  H1 = H3 ;									\
  /* insert */									\
  H1.Insert(toto, (T*)8 );							\
  /* size */									\
  int	Size = H1.Size();							\
  int	Dimension = H1.Dimension();						\
  int	Collisions = H1.Collisions();						\
  int	Unused = H1.Unused();							\
  /* locating */								\
  T*	Ptr = H1.Locate( toto );						\
  int	Bucket, Position ;							\
  Ptr = H1.LocatePosition( toto							\
			  , Bucket						\
			  , Position );						\
  Ptr = H1.Retrieve( Bucket							\
		    , Position							\
		    , &toto );							\
  Ptr = H1.Next( Bucket								\
		, Position );							\
  Ptr = H1.Next( &toto );							\
  /* removals */								\
  H1.Remove( toto );								\
  H1.RemovePosition( Bucket							\
		    , Position );						\
  H1.RemoveAll();								\
  /* comparisons */								\
  CATAssert( H1 == H2 );								\
  CATAssert( !(H1 != H2) );							\
  /* miscellanous */								\
  H1.PrintStats( cout );							\
  cout << H1 ;									\
  H1.PrintAddr( cout );								\
  /* apply */									\
  H1.ApplyGlobalFunct( &CATHDICO_GlobalFunct##T );				\
  H1.ApplyDelete();								\
  /* iterator */								\
  CATHashCodeIter	I ( H1.CreateIterator() );							\
  I.Beginning();								\
  /* exit */									\
  return 0 ;									\
}										\
static										\
int	CATHDICO_Dummy##T = CATHDICO_Test_##T() ;



#endif

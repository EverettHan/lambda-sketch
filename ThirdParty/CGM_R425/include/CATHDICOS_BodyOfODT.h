//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997
//============================================================================
//
// macro CATHDICOS_ODT(T):
//	This macro expands in a program that performs a basic call to all
//	the methods contained in the recommended interface.
//	The CATHDICOS(T) class should have been generated using that header :
//	#include "CATHDICOS_PublicInterface.h"
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
//	#include "CATHDICOS_MyClass.h"
//	#include "CATHDICOS_AnotherClass.h"
//	#include "CATHDICOS_OneMoreClass.h"
//	/*
//	** headers for macro used to generate code
//	*/
//	#include "CATHDICOS_BodyOfODT.h"
//	/*
//	** generation of code calling services of collection-classes
//	*/
//	CATHDICOS_ODT(MyClass)
//	CATHDICOS_ODT(AnotherClass)
//	CATHDICOS_ODT(OneMoreClass)
//	int main()
//	{ 
//	  return 0 ;
//	} 
//
//============================================================================
// Avr. 97	Initial coding				Ph.Baucher
//============================================================================

#ifndef CATHDICOS_BodyOfODT_H
#define CATHDICOS_BodyOfODT_H

#include "CATCollec.h"
#include "CATHashCodeIter.h"
#include "CATString.h"
#include "CATAssert.h"


#define	CATHDICOS_ODT(T)							\
static										\
int	CATHDICOS_GlobalFunct##T( T* )						\
{ return 0; } 									\
static										\
int	CATHDICOS_Test_##T()							\
{										\
  static									\
  CATString	toto("toto");     						\
  /* test cdtors */								\
  CATHDICOS(T)	H1;								\
  CATHDICOS(T)	H2(H1);								\
  CATHDICOS(T)	H3(100);							\
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
  H1.ApplyGlobalFunct( &CATHDICOS_GlobalFunct##T );				\
  H1.ApplyDelete();								\
  /* iterator */								\
  CATHashCodeIter	I ( H1.CreateIterator() );				\
  I.Beginning();								\
  /* exit */									\
  return 0 ;									\
}										\
static										\
int	CATHDICOS_Dummy##T = CATHDICOS_Test_##T() ;



#endif

//
// CATIA Version 5 Release 2 Framework Visualization
// Copyright Dassault Systemes 1999
//------------------------------------------------------------------------------
// Abstract : 	
//		
//------------------------------------------------------------------------------
// Usage :	
//------------------------------------------------------------------------------
// Class : SortedList
//------------------------------------------------------------------------------


// SortedList.h: interface for the SortedList class.
//
//////////////////////////////////////////////////////////////////////
#ifndef SORTEDLIST_H
#define SORTEDLIST_H

//Ia64+
#include "CATDataType.h"
//Ia64-
#include <stdio.h>
#include "SceneGraphManager.h"

class ExportedBySceneGraphManager DblInt
{
public :
//Ia64C  DblInt(int a=0,int b=0) { cle=a;val=b;};
//Ia64C  int cle;
//Ia64C  int val;
//Ia64+
  DblInt(CATINTPTR a=0,CATINTPTR b=0) { cle=a;val=b;};
  CATINTPTR cle;
  CATINTPTR val;
//Ia64-
};

class ExportedBySceneGraphManager SortedList  
{
public:
	SortedList();
	~SortedList();

  //Add one element into the sorted list 
  //INPUT:
  //    # ivalue: element to add
  //    # isortmode : 0 = add without sorting
  //                  1 = add with sorting
  void Add(DblInt ivalue, int isortmode=0);

  //Remove one element into the sorted list 
  //INPUT:
  //    # iindex: index of element to remove
  void Rem(int iindex);
  
  //Find one element within the list
  //INPUT:
  //     # ivalue : element to find
  //    
	//RETURN:
	//     # [0,...]the index table of the element if it exists in the list
	//     # -1 if the element doesn't exist
//Ia64C	int Find(int ivalue);
//Ia64+
	int Find(CATINTPTR ivalue);
//Ia64-

  //Sort the list
  void Sort(void);

  //Empty the structure
  void Empty(void);

  //Display the list
  void Display(void);

  //Get elem from position
  inline DblInt * operator [] (int i) const ;

  //Get the number of elements enclosed
  inline int GetSize(void);

private:
	DblInt *_Tab;
	int _Dim;
	int _Cursor;
  int _Nbr;

};

inline DblInt * SortedList::operator [] (int i) const { return ( (i>=0) && (i<_Nbr) ? &_Tab[i] : 0); }
inline int SortedList::GetSize(void) { return _Nbr;}


#endif



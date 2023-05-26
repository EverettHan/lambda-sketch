// LinkedList.h -- definition of nonpersistent class representing a
// linked list.
//
// Copyright (c) 1993 Matrix Division of Adra Systems, Inc.
// All Rights Reserved.
// This program contains proprietary and trade secret information of Matrix
// Division of Adra Systems, Inc.  Copyright notice is precautionary only
// and does not evidence any actual or intended publication of such program.
//
// $Log: LinkedList.h,v $
// Revision 1.1.1.1  2004/05/19  20:42:49  tewks
// new access cache prototype
//
// Revision 1.2  2003/04/29  17:18:32  tewks
// memory manager feature
//
// Revision 1.1  2002/09/13  11:57:49  tewks
// Initial revision
//
//
//

////////////////////////WARNING///////////////////////////////////////////////
// this module is linked into other shared libs. adding includes or references 
// to matrix things (VString, mxBoolean, etc) will likely break something
////////////////////////WARNING///////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

// $Id: LinkedList.h,v 1.1.1.1 2004/05/19 20:42:49 tewks Exp $

////////////////////////////////////////////////////////////////////////////////
/**
 * @level Protected
 * @usage U1
 */


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

////////////////////////////////////////////////////////////////////////////////

class LinkedList {

public:
  LinkedList();
  ~LinkedList();
  void link(LinkedList *list, void *ref = (void *)0);
  void unlink();  
  LinkedList *next() const { return _next; }
  LinkedList *prev() const { return _prev; }
  void *ref() const { return _ref; }
  void init();

private:
  LinkedList *_next;
  LinkedList *_prev;
  void *_ref;
};

#endif



// Copyright Dassault Systemes 2000
#ifndef CATCkePurify_H
#define CATCkePurify_H

#include "CATLifSpecs.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"

class ExportedByCATLifSpecs CATCkePurify
{

public :

  static int  purifyOn_; // 0 if no purify, 1 if something is asked for (Start/Bilan explicitely called)
                         // 2 if start/bilan forced, 3 if the number of destruction is controlled.
  static int  nbFuitesTolere_;

//	#ifdef CATCKEPurifyOn

  CATCkePurify ();
  virtual ~CATCkePurify ();
  // static object for triggering summary in destructor
  static CATCkePurify monstatic_;

  static void Start ();
  static void Push (const char *);
  static void Pop  (const char *);

  static void Bilan ();


  CATListOfCATUnicodeString ls_;
  CATListOfInt              li_;
  CATListOfInt              limax_;

  int theend;

//   static void PushForName(/*CATISpecObject*, */void *);
//   static void PopForName(void*);
//   static void BilanForName();
   //	int nameToUpdate_;
   CATListOfInt objs_;
   //	CATListOfCATUnicodeString names_;
//	#endif

	private: 
		static void Init ();
		static int initialized_;

};

#ifndef CNEXT_CLIENT

#define CATCKEPurifyOn

// #ifdef CATCKEPurifyOn

// macros
#define CATCKEPurifyStart   CATCkePurify::Start();
#define CATCKEPurifyCreate  CATCkePurify::Push(classeTracee_);
#define CATCKEPurifyCopy    CATCkePurify::Push(classeTracee_);
#define CATCKEPurifyDelete  CATCkePurify::Pop(classeTracee_);
#define CATCKEPurifyBilan   CATCkePurify::Bilan();

#define CATCKEPurifySetMode(x) CATCkePurify::purifyOn_ = x
#define CATCKEPurifyGetMode() CATCkePurify::purifyOn_
#define CATCKEPurifyNbFuites(x) CATCkePurify::nbFuitesTolere_ = x

#else

// macros
#define CATCKEPurifyStart  
#define CATCKEPurifyCreate 
#define CATCKEPurifyCopy 
#define CATCKEPurifyDelete  
#define CATCKEPurifyBilan       

#define CATCKEPurifySetMode(x)
#define CATCKEPurifyGetMode() 0
#define CATCKEPurifyNbFuites(x)

#endif

#endif

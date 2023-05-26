#ifndef CATICGMObject_SmartPointer_H_
#define CATICGMObject_SmartPointer_H_

/**
 * @COPYRIGHT DASSAULT SYSTEMES 2005
 */

/* -*-C++-*- */

//=============================================================================
// June  05  Creation                                                      AJD
//=============================================================================

// WARNING: These classes are not as smart as any smart class you might have seen before
// they just help you to delete the object
// useful in a code where you have mutiple return branches in the function

// smart pointer of any time you want
// eaxmple of usage for CATCGMJournalList ( though you should CATCGMVirtual_SmartPointer for CATCGMJournalList)
//    SmartPointerDefine( CATCGMJournalList); // define the smart class, only once
//    CATCGMJournalList *Jounal = new CATCGMJournalList( config, 0);
//    CATCGMJournalList__SmartPointer SmartJournal( Journal); // SmartJournal will take care of deletion
//    rest of the code as before

#define SmartPointerDefine( Type)                                         \
class Type##_SmartPointer {                                               \
public:                                                                   \
  Type##_SmartPointer ( Type * ip) { _p = ip; }                           \
  ~Type##_SmartPointer ( ) { delete _p; _p = 0; }                         \
private:                                                                  \
  Type##_SmartPointer ( const Type##_SmartPointer &);                     \
  Type##_SmartPointer& operator =( const Type##_SmartPointer &);          \
  Type *_p;                                                               \
};                                              

// utility to create the object, useful only if one object is there in the scope
#define SmartPointerCreate( Type, Pointer)       \
Type##_SmartPointer Type##_SmartPointerObject( Pointer);                   


// smart array pointer of any time you want

#define SmartArrayDefine( Type)                                         \
class Type##_SmartArray {                                               \
public:                                                                 \
  Type##_SmartArray ( Type * ip) { _p = ip; }                           \
  ~Type##_SmartArray ( ) { delete []_p; _p = 0; }                       \
private:                                                                \
  Type##_SmartArray ( const Type##_SmartArray &);                       \
  Type##_SmartArray& operator =( const Type##_SmartArray &);            \
  Type *_p;                                                             \
};                                              

// utility to create the object, useful only if one object is there in the scope
#define SmartArrayCreate( Type, Array)       \
Type##_SmartArray Type##_SmartArrayObject( Array);                   

class CATCGMVirtual;

// use for all the classes derived from CATCGMVirtual
// prefer this over SmartPointerDefine as only one class defination is active
// so CATCGMVirtual_SmartPointer and CATCGMVirtual_SmartArray are already there
SmartPointerDefine( CATCGMVirtual);
SmartArrayDefine( CATCGMVirtual);

class CATICGMObject;
class CATGeoFactory;

// use for all the classes derived from CATICGMObject
// prefer this over SmartPointerDefine as only one class defination is active
// removes the object with RemoveDependancies
// does not release the object
class CATICGMObject_SmartPointer
{
public:
  CATICGMObject_SmartPointer( CATICGMObject *ip) { _p = ip;}
  ~CATICGMObject_SmartPointer() {
    if( _p) {
      CATGeoFactory *factory=_p->GetContainer( FALSE);
      if(factory) factory->Remove(_p, CATICGMContainer::RemoveDependancies);
      _p =0;
    }
  }
private:
  CATICGMObject_SmartPointer( const CATICGMObject_SmartPointer&);
  CATICGMObject_SmartPointer& operator=( const CATICGMObject_SmartPointer&);
  CATICGMObject *_p;
};

#endif


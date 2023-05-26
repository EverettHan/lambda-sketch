////////////////////////////////////////////////////////////////////////////////

// COPYRIGHT DASSAULT SYSTEMES 2000

//
//	FrameWork COLLECTIONS	--	Dassault Systems (JAN96)
//
//	Macros :	1- CATSETV_DECLARE( T )
//	======
//			2- CATSETV_DECLARE_TN( T, N )
//
//			where T stands for a type name
//			  and N stands for a name appended to "CATSetVal"
//   (in the first case T and N are the same)
//
// Purpose : Generate body of a non-template class CATSetVal"N"
// =======  (list of instances of the class "T")
//
//
// Usage :  // 1- To generate the body of a class CATSetValCATMyClass,
// =====    //    create a file CATSetValMyClass.h containing those lines :
//          #ifndef CATSetValCATMyClass_h
//          #define CATSetValCATMyClass_h
//          //
//          // include declaration of class used for the elements
//          //
//          #include  <CATMyClass.h>
//          //
//          // define symbols for extra functionalities :
//          //
//          #define CATSETV_...
//          //
//          // define macro CATSETV_DECLARE :
//          //
//          #include  <CATSETV_Declare.h>
//          //
//          // declare class CATSetValCATMyClass :
//          //
//          CATSETV_DECLARE( CATMyClass )
//          //
//          #endif // CATSetValCATMyClass_h
//
//          // 2- Consult documentation "COLLECTIONS" (chapter List of Values)
//          //    to know the available functionalities
//
// Authors :  Philippe BAUCHER
// =======
//
////////////////////////////////////////////////////////////////////////////////

//
// 1- To produce declaration of functions for class CATSetVal...
//    ===========================================================
//
#ifndef  CATSETV_DECLARE
#define  CATSETV_DECLARE( T )  CATSETV_DECLARE_TN( T, T )
#endif
//
// Macro CATCOLLEC_ExportedBy is used for WindowsNT import/export DDL specifications
// 1- it should be defined to ExportedByXX0MODUL
// 2- but if not defined, it should not be kept as indesirable text :
#ifndef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy
#endif

#ifndef  CATSETV_DECLARE_TN
#define  CATSETV_DECLARE_TN( T, N )                              \
class CATCOLLEC_ExportedBy CATSetVal##N  : public CATCollecRoot  \
{                          /**********/                          \
  public :                                                       \
  /* CDTORS */                                                   \
  CATSetVal##N ();                                               \
  /* same way to grow from an initial alloc */                   \
  CATSetVal##N ( int iInitAlloc );                               \
  /* still maintain the additive mode : */                       \
  CATSetVal##N ( int iInitAlloc, int iExtensAlloc );             \
                                                                 \
  CATSetVal##N  ( const CATSetVal##N& iCopy );                   \
                                                                 \
  dclCATSETV_CtorFromArrayVals( T, N )                           \
  dclCATSETV_CtorFromArrayPtrs( T, N )                           \
                                                                 \
  ~CATSetVal##N ();                                              \
                                                                 \
  /* COPY OPERATOR */                                            \
  CATSetVal##N& operator= ( const CATSetVal##N& iCopy );         \
                                                                 \
  /* ADD ELEMENT(S) */                                           \
  int  Add ( const T& iAdd );                                    \
  dclCATSETV_AddSet( T, N )                                      \
                                                                 \
  /* GET NUMBER OF ELEMENTS */                                   \
  int  Size () const ;                                           \
                                                                 \
  /* INDEXATION OPERATORS */                                     \
  T operator[] ( int iPos ) const;                               \
                                                                 \
  /* LOCALIZE ELEMENT */                                         \
  dclCATSETV_Locate( T, N )                                      \
                                                                 \
  /* REMOVE ELEMENT(S) */                                        \
  dclCATSETV_RemoveValue( T, N )                                 \
  dclCATSETV_RemoveSet( T, N )                                   \
  dclCATSETV_RemovePosition( T, N )                              \
  void  RemoveAll ( CATCollec::MemoryHandling iMH                \
                    = CATCollec::ReleaseAllocation );            \
                                                                 \
  /* COMPARISON OPERATORS */                                     \
  int operator == ( const CATSetVal##N& iLV ) const ;            \
  int operator != ( const CATSetVal##N& iLV ) const ;            \
  dclCATSETV_gtOP( T, N )                                        \
  dclCATSETV_ltOP( T, N )                                        \
  dclCATSETV_geOP( T, N )                                        \
  dclCATSETV_leOP( T, N )                                        \
                                                                 \
  /* COMPARE STATIC FUNCTION */                                  \
  dclCATSETV_Compare( T, N )                                     \
                                                                 \
  /* CHANGE ELEMENT(S) */                                        \
  dclCATSETV_Replace( T, N )                                     \
                                                                 \
  /* MISCELLANEOUS */                                            \
  dclCATSETV_ArrayVals( T, N )                                   \
  dclCATSETV_ArrayPtrs( T, N )                                   \
  dclCATSETV_Contains( T, N )                                    \
  dclCATSETV_Intersection( T, N )                                \
                                                                 \
  /* APPLY */                                                    \
  dclCATSETV_ApplyMemberFunct( T, N )                            \
  dclCATSETV_ApplyMemberFunctConst( T, N )                       \
  dclCATSETV_ApplyGlobalFunct( T, N )                            \
                                                                 \
 private :                                                       \
  CATListPV _Sval;                                               \
};

#endif  // CATSETV_DECLARE_TN

//
// 2- To define required CATSETV_... symbols
//    =======================================
#ifdef CATSETV_RemoveSet
#ifndef CATSETV_RemoveValue
#define CATSETV_RemoveValue
#endif
#endif

#ifdef CATSETV_RemoveValue
#ifndef CATSETV_Locate
#define CATSETV_Locate
#endif
#ifndef CATSETV_RemovePosition
#define CATSETV_RemovePosition
#endif
#endif

#ifdef CATSETV_eqOP
#ifndef CATSETV_neOP
#define CATSETV_neOP
#endif
#endif

#ifdef CATSETV_ltOP
#ifndef CATSETV_geOP
#define CATSETV_geOP
#endif
#endif

#ifdef CATSETV_gtOP
#ifndef CATSETV_leOP
#define CATSETV_leOP
#endif
#endif

#ifdef CATSETV_Contains
#ifndef CATSETV_Locate
#define CATSETV_Locate
#endif
#endif

#undef  dclCATSETV_ostreamOP
#undef  dclCATSETV_CtorFromArrayVals
#undef  dclCATSETV_CtorFromArrayPtrs
#undef  dclCATSETV_AddSet
#undef  dclCATSETV_Locate
#undef  dclCATSETV_RemoveValue
#undef  dclCATSETV_RemoveSet
#undef  dclCATSETV_RemovePosition
#undef  dclCATSETV_leOP
#undef  dclCATSETV_geOP
#undef  dclCATSETV_ltOP
#undef  dclCATSETV_gtOP
#undef  dclCATSETV_Compare
#undef  dclCATSETV_Replace
#undef  dclCATSETV_ArrayVals
#undef  dclCATSETV_ArrayPtrs
#undef  dclCATSETV_Contains
#undef  dclCATSETV_Intersection
#undef  dclCATSETV_ApplyMemberFunc
#undef  dclCATSETV_ApplyMemberFunctConst
#undef  dclCATSETV_ApplyGlobalFunct

//
// 3- To prepare (non-)declaration of functions or class CATSetVal...
//    ================================================================
//
//  ==========
//  3-1 CDTORS
//  ==========
//
//   CtorFromArrayVals
//   -----------------
#ifndef CATSETV_CtorFromArrayVals
#define dclCATSETV_CtorFromArrayVals( T, N )
#else
#define dclCATSETV_CtorFromArrayVals( T, N )     \
CATSetVal##N ( T* iArray, int iSize );
#endif
//
//   CtorFromArrayPtrs
//   -----------------
#ifndef CATSETV_CtorFromArrayPtrs
#define dclCATSETV_CtorFromArrayPtrs( T, N )
#else
#define dclCATSETV_CtorFromArrayPtrs( T, N )     \
CATSetVal##N ( T** iArray, int iSize );
#endif

//  ==================
//  3-2 ADD ELEMENT(S)
//  ==================
//
//   AddSet
//   ------
#ifndef CATSETV_AddSet
#define dclCATSETV_AddSet( T, N )
#else
#define dclCATSETV_AddSet( T, N )                \
int  Add ( const CATSetVal##N& iConcat );
#endif

//  ====================
//  3-3 LOCALIZE ELEMENT
//  ====================
//
//   Locate
//   ------
#ifndef CATSETV_Locate
#define dclCATSETV_Locate( T, N )
#else
#define dclCATSETV_Locate( T, N )                \
int  Locate ( const T& iLocate ) const ;
#endif

//  =====================
//  3-4 REMOVE ELEMENT(S)
//  =====================
//
//   RemoveValue
//   -----------
#ifndef CATSETV_RemoveValue
#define dclCATSETV_RemoveValue( T, N )
#else
#define dclCATSETV_RemoveValue( T, N )           \
int RemoveValue ( const T& iRemove );
#endif
//
//   RemoveSet
//   ---------
#ifndef CATSETV_RemoveSet
#define dclCATSETV_RemoveSet( T, N )
#else
#define dclCATSETV_RemoveSet( T, N )      \
int Remove ( const CATSetVal##N& iSubstract );
#endif
//
//   RemovePosition
//   --------------
#ifndef CATSETV_RemovePosition
#define dclCATSETV_RemovePosition( T, N )
#else
#define dclCATSETV_RemovePosition( T, N )     \
void RemovePosition ( int iPos );
#endif

//  ========================
//  3-5 COMPARISON OPERATORS
//  ========================
//
//   leOP
//   ----
#ifndef CATSETV_leOP
#define dclCATSETV_leOP( T, N )
#else
#define dclCATSETV_leOP( T, N )                    \
int operator <= ( const CATSetVal##N& iLV ) const ;
#endif
//
//   geOP
//   ----
#ifndef CATSETV_geOP
#define dclCATSETV_geOP( T, N )
#else
#define dclCATSETV_geOP( T, N )                    \
int operator >= ( const CATSetVal##N& iLV ) const ;
#endif
//
//   ltOP
//   ----
#ifndef CATSETV_ltOP
#define dclCATSETV_ltOP( T, N )
#else
#define dclCATSETV_ltOP( T, N )                   \
int operator < ( const CATSetVal##N& iLV ) const ;
#endif
//
//   gtOP
//   ----
#ifndef CATSETV_gtOP
#define dclCATSETV_gtOP( T, N )
#else
#define dclCATSETV_gtOP( T, N )                   \
int operator > ( const CATSetVal##N& iLV ) const ;
#endif

//  ===========================
//  3-9 COMPARE STATIC FUNCTION
//  ===========================
#ifndef CATSETV_Compare
#define dclCATSETV_Compare( T, N )
#else
#define dclCATSETV_Compare( T, N )                    \
static int  Compare ( const CATSetVal##N& iLV1,       \
                      const CATSetVal##N& iLV2,       \
                      int  (*iPFCompare) ( T*, T* ) );
#endif

//  ======================
//  3-6 REPLACE ELEMENT(S)
//  ======================
#ifndef CATSETV_Replace
#define dclCATSETV_Replace( T, N )
#else
#define dclCATSETV_Replace( T, N )      \
int Replace  ( int  iPos, const T& iReplace );
#endif

//  ==================
//  3-7  MISCELLANEOUS
//  ==================
//
//   ArrayVals
//   ---------
#ifndef CATSETV_ArrayVals
#define dclCATSETV_ArrayVals( T, N )
#else
#define dclCATSETV_ArrayVals( T, N )      \
void Array  ( T* ioArray ) const ;
#endif
//
//   ArrayPtrs
//   ---------
#ifndef CATSETV_ArrayPtrs
#define dclCATSETV_ArrayPtrs( T, N )
#else
#define dclCATSETV_ArrayPtrs( T, N )      \
void Array  ( T** ioArray ) const ;
#endif
//
//   Contains
//   --------
#ifndef CATSETV_Contains
#define dclCATSETV_Contains( T, N )
#else
#define dclCATSETV_Contains( T, N )         \
int Contains ( const CATSetVal##N& iTest );
#endif
//
//   Intersection
//   ------------
#ifndef CATSETV_Intersection
#define dclCATSETV_Intersection( T, N )
#else
#define dclCATSETV_Intersection( T, N )               \
static void Intersection ( const CATSetVal##N& iL1,   \
                           const CATSetVal##N& iL2,   \
                           CATSetVal##N& ioResult );
#endif

//  =======================
//  3-8  APPLY AN OPERATION
//  =======================
//
//   ApplyMemberFunct
//   ----------------
#ifndef CATSETV_ApplyMemberFunct
#define dclCATSETV_ApplyMemberFunct( T, N )
#else
#define dclCATSETV_ApplyMemberFunct( T, N )       \
typedef  int  (T::*PtrMbrFunct) () ;              \
int ApplyMemberFunct ( PtrMbrFunct iPF ,          \
                       int  iFrom  = 1 ,          \
                       int  iTo    = 0 ,          \
                       T**  iPLast = 0 ,          \
                       int* iPRC   = 0 ) const ;
#endif
//
//   ApplyMemberFunctConst
//   ---------------------
#ifndef CATSETV_ApplyMemberFunctConst
#define dclCATSETV_ApplyMemberFunctConst( T, N )
#else
#define dclCATSETV_ApplyMemberFunctConst( T, N )         \
typedef  int (T::*PtrMbrFunctConst) () const ;           \
int ApplyMemberFunctConst ( PtrMbrFunctConst iPF,        \
                            int   iFrom  = 1    ,        \
                            int   iTo    = 0    ,        \
                            T**   iPLast = 0    ,        \
                            int*  iPRC   = 0    ) const ;
#endif
//
//   ApplyGlobalFunct
//   ----------------
#ifndef CATSETV_ApplyGlobalFunct
#define dclCATSETV_ApplyGlobalFunct( T, N )
#else
#define dclCATSETV_ApplyGlobalFunct( T, N )       \
typedef  int  (*PtrGlbFunct) (T*) ;               \
int  ApplyGlobalFunct ( PtrGlbFunct iPF  ,        \
                        int   iFrom  = 1 ,        \
                        int   iTo    = 0 ,        \
                        T**   iPLast = 0 ,        \
                        int*  iPRC   = 0 ) const ;
#endif


//  =========================
//  3-14 NEW-DELETE OPERATORS
//  =========================
/*
#include <stddef.h>

# undef  dclCATSETV_NewDeleteOP
# define dclCATSETV_NewDeleteOP( T, N )                    \
  private:                                                 \
    static CATDYNMRYPool*& CATDYNMRY_Pool_For_Class ();    \
    static int&  CATDYNMRY_AllocatedCount ();              \
    static int&  CATDYNMRY_FreedCount ();                  \
                                                           \
  public:                                                  \
    static void* operator new ( size_t iSizeOfObject );   \
    static void operator delete ( void*  iAddrOfObject, size_t iSizeOfObject );
*/
//
// 4- Required includes and forward declarations
//    ==========================================
//
#include "CATCollec.h"
#include "CATCollecRoot.h"
#include "CATListPV.h"
#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:05:06 [Replace forward declaration of standard streams with iosfwd.h] **/
 #include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class  ostream ;
#endif //_CAT_ANSI_STREAMS

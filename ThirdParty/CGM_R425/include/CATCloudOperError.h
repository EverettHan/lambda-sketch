//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1998
//==============================================================================================================
// File: CATCloudOperError.h
//==============================================================================================================
// Usage:
//==============================================================================================================
// 06-Dec-2004 - JLH - Déportation de la définition de la classe à la fin du fichier afin de compiler
//                     correctement sur aix et de pouvoir générer la documentation des macros sans problème sur
//                     windows.
// 01-Dec-2004 - JLH - Add CATCloudRelease et CATCloudDestroy
// 29-May-2000 - STA - Update for mkman + Add CATCloudNew4
// 19-May-2000 - STA - Correction CATCloudDeclareNew1
// ??-May-2000 - STA - Add CATCloudNew macros
// ??-Sep-1999 - STA - Création
//==============================================================================================================

#ifndef CATCloudOperError_h
#define CATCloudOperError_h

/**
 * DSECAAFutureExposure_Level L1
 * DSECAAFutureExposure_Usage U3
 */

#include "ExportedByCATCloudBasicResources.h"
#include "CATErrors.h"
#include "CATCloudOperErrorTool.h" // cf. CLOUDEDITORERRCATALOG & ERR_InsufficientMemory

class ExportedByCATCloudBasicResources CATCloudOperError ;

// La définition de la classe est déportée en fin de fichier.
// En effet, la macro CATDeclareError contient déjà le ";" final.
// Or la syntaxe "CATDeclareError (...) ;" ne compile pas sur aix.
// D'autre part, si nous ne mettons pas ce ";", tout se passe bien à la compilation, mais la génération de la
// documentation des macros ne fonctionne alors plus !!!
// STA avait initialement mis le ";" sous compilation conditionnelle du type :
//   #ifdef _WINDOWS_SOURCE
//   ;
//   #endif // pour que mkman ne se perde pas dans les macros ! et que ca compile sur unix !@#$%!! NON MAIS....
// Enfin... sans commentaire.
// Le fait de déporter la définition de la classe en fin de fichier résoud tous les problèmes.

//==============================================================================================================
// Allocation macros
//==============================================================================================================

/**
 * Useful macro to allocate an instance of a given class with a default constructor.<br>
 * <b>Usage:</b>
 * <dl><dl>
 * <dt>When you have to write:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = new Class () ;
 * <dt>if (!InstancePtr) {
 * <dl><dt>...</dl>
 * <dt>}
 * <dt>...
 * <dt>if (InstancePtr) delete InstancePtr ;
 * <dt>// or equivalent as Release, Destroy or RequestDelayedDestruction
 * <dt>InstancePtr = NULL ;
 * </dl>
 * </code>
 * <dt>you can write the equivalent code as follow:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = NULL ;
 * <dt>CATCloudNew (Class, InstancePtr) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * <dt>or:
 * <code>
 * <dl>
 * <dt>CATCloudDeclareNew (Class, InstancePtr) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * </dl></dl>
 *
 * @param TheClass
 * Any class name with a default constructor.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudDeclareNew
 * @see CATCloudNew1, CATCloudNew2, CATCloudNew3, CATCloudNew4, CATCloudNew5
 * @see CATCloudDelete, CATCloudRelease, CATCloudDestroy, CATCloudRequestDelayedDestruction
 */

#define CATCloudNew(TheClass,TheInstancePtr) \
  TheInstancePtr = new TheClass ; \
  if (!TheInstancePtr) CATThrowInformation (CATCloudOperError, ERR_InsufficientMemory, CLOUDEDITORERRCATALOG) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 1 argument.<br>
 * <b>Usage:</b>
 * <dl><dl>
 * <dt>When you have to write:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = new Class (Arg1) ;
 * <dt>if (!InstancePtr) {
 * <dl><dt>...</dl>
 * <dt>}
 * <dt>...
 * <dt>if (InstancePtr) delete InstancePtr ;
 * <dt>// or equivalent as Release, Destroy or RequestDelayedDestruction
 * <dt>InstancePtr = NULL ;
 * </dl>
 * </code>
 * <dt>you can write the equivalent code as follow:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = NULL ;
 * <dt>CATCloudNew (Class, InstancePtr, Arg1) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * <dt>or:
 * <code>
 * <dl>
 * <dt>CATCloudDeclareNew (Class, InstancePtr, Arg1) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * </dl></dl>
 *
 * @param TheClass
 * Any class name with a constructor with 1 argument.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudDeclareNew1
 * @see CATCloudNew, CATCloudNew2, CATCloudNew3, CATCloudNew4, CATCloudNew5
 * @see CATCloudDelete, CATCloudRelease, CATCloudDestroy, CATCloudRequestDelayedDestruction
 */

#define CATCloudNew1(TheClass,TheInstancePtr,Arg1) \
  TheInstancePtr = new TheClass (Arg1) ; \
  if (!TheInstancePtr) CATThrowInformation (CATCloudOperError, ERR_InsufficientMemory, CLOUDEDITORERRCATALOG) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 2 arguments.<br>
 * <b>Usage:</b>
 * <dl><dl>
 * <dt>When you have to write:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = new Class (Arg1, Arg2) ;
 * <dt>if (!InstancePtr) {
 * <dl><dt>...</dl>
 * <dt>}
 * <dt>...
 * <dt>if (InstancePtr) delete InstancePtr ;
 * <dt>// or equivalent as Release, Destroy or RequestDelayedDestruction
 * <dt>InstancePtr = NULL ;
 * </dl>
 * </code>
 * <dt>you can write the equivalent code as follow:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = NULL ;
 * <dt>CATCloudNew (Class, InstancePtr, Arg1, Arg2) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * <dt>or:
 * <code>
 * <dl>
 * <dt>CATCloudDeclareNew (Class, InstancePtr, Arg1, Arg2) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * </dl></dl>
 *
 * @param TheClass
 * Any class name with a constructor with 2 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudDeclareNew2
 * @see CATCloudNew, CATCloudNew1, CATCloudNew3, CATCloudNew4, CATCloudNew5
 * @see CATCloudDelete, CATCloudRelease, CATCloudDestroy, CATCloudRequestDelayedDestruction
 */

#define CATCloudNew2(TheClass,TheInstancePtr,Arg1,Arg2) \
  TheInstancePtr = new TheClass (Arg1, Arg2) ; \
  if (!TheInstancePtr) CATThrowInformation (CATCloudOperError, ERR_InsufficientMemory, CLOUDEDITORERRCATALOG) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 3 arguments.<br>
 * <b>Usage:</b>
 * <dl><dl>
 * <dt>When you have to write:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = new Class (Arg1, Arg2, Arg3) ;
 * <dt>if (!InstancePtr) {
 * <dl><dt>...</dl>
 * <dt>}
 * <dt>...
 * <dt>if (InstancePtr) delete InstancePtr ;
 * <dt>// or equivalent as Release, Destroy or RequestDelayedDestruction
 * <dt>InstancePtr = NULL ;
 * </dl>
 * </code>
 * <dt>you can write the equivalent code as follow:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = NULL ;
 * <dt>CATCloudNew (Class, InstancePtr, Arg1, Arg2, Arg3) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * <dt>or:
 * <code>
 * <dl>
 * <dt>CATCloudDeclareNew (Class, InstancePtr, Arg1, Arg2, Arg3) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * </dl></dl>
 *
 * @param TheClass
 * Any class name with a constructor with 3 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @param Arg3
 * The 3rd argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudDeclareNew3
 * @see CATCloudNew, CATCloudNew1, CATCloudNew2, CATCloudNew4, CATCloudNew5
 * @see CATCloudDelete, CATCloudRelease, CATCloudDestroy, CATCloudRequestDelayedDestruction
 */

#define CATCloudNew3(TheClass,TheInstancePtr,Arg1,Arg2,Arg3) \
  TheInstancePtr = new TheClass (Arg1, Arg2, Arg3) ; \
  if (!TheInstancePtr) CATThrowInformation (CATCloudOperError, ERR_InsufficientMemory, CLOUDEDITORERRCATALOG) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 4 arguments.<br>
 * <b>Usage:</b>
 * <dl><dl>
 * <dt>When you have to write:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = new Class (Arg1, Arg2, Arg3, Arg4) ;
 * <dt>if (!InstancePtr) {
 * <dl><dt>...</dl>
 * <dt>}
 * <dt>...
 * <dt>if (InstancePtr) delete InstancePtr ;
 * <dt>// or equivalent as Release, Destroy or RequestDelayedDestruction
 * <dt>InstancePtr = NULL ;
 * </dl>
 * </code>
 * <dt>you can write the equivalent code as follow:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = NULL ;
 * <dt>CATCloudNew (Class, InstancePtr, Arg1, Arg2, Arg3, Arg4) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * <dt>or:
 * <code>
 * <dl>
 * <dt>CATCloudDeclareNew (Class, InstancePtr, Arg1, Arg2, Arg3, Arg4) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * </dl></dl>
 *
 * @param TheClass
 * Any class name with a constructor with 4 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @param Arg3
 * The 3rd argument to give to the constructor.
 * @param Arg4
 * The 4th argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudDeclareNew4
 * @see CATCloudNew, CATCloudNew1, CATCloudNew2, CATCloudNew3, CATCloudNew5
 * @see CATCloudDelete, CATCloudRelease, CATCloudDestroy, CATCloudRequestDelayedDestruction
 */

#define CATCloudNew4(TheClass,TheInstancePtr,Arg1,Arg2,Arg3,Arg4) \
  TheInstancePtr = new TheClass (Arg1, Arg2, Arg3, Arg4) ; \
  if (!TheInstancePtr) CATThrowInformation (CATCloudOperError, ERR_InsufficientMemory, CLOUDEDITORERRCATALOG) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 5 arguments.<br>
 * <b>Usage:</b>
 * <dl><dl>
 * <dt>When you have to write:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = new Class (Arg1, Arg2, Arg3, Arg4, Arg5) ;
 * <dt>if (!InstancePtr) {
 * <dl><dt>...</dl>
 * <dt>}
 * <dt>...
 * <dt>if (InstancePtr) delete InstancePtr ;
 * <dt>// or equivalent as Release, Destroy or RequestDelayedDestruction
 * <dt>InstancePtr = NULL ;
 * </dl>
 * </code>
 * <dt>you can write the equivalent code as follow:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = NULL ;
 * <dt>CATCloudNew (Class, InstancePtr, Arg1, Arg2, Arg3, Arg4, Arg5) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * <dt>or:
 * <code>
 * <dl>
 * <dt>CATCloudDeclareNew (Class, InstancePtr, Arg1, Arg2, Arg3, Arg4, Arg5) ;
 * <dt>...
 * <dt>CATCloudDelete (InstancePtr) ;
 * <dt>// or equivalent as CATCloudRelease, CATCloudDestroy or CATCloudRequestDelayedDestruction
 * </dl>
 * </code>
 * </dl></dl>
 *
 * @param TheClass
 * Any class name with a constructor with 5 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @param Arg3
 * The 3rd argument to give to the constructor.
 * @param Arg4
 * The 4th argument to give to the constructor.
 * @param Arg5
 * The 5th argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudDeclareNew5
 * @see CATCloudNew, CATCloudNew1, CATCloudNew2, CATCloudNew3, CATCloudNew4
 * @see CATCloudDelete, CATCloudRelease, CATCloudDestroy, CATCloudRequestDelayedDestruction
 */

#define CATCloudNew5(TheClass,TheInstancePtr,Arg1,Arg2,Arg3,Arg4,Arg5) \
  TheInstancePtr = new TheClass (Arg1, Arg2, Arg3, Arg4, Arg5) ; \
  if (!TheInstancePtr) CATThrowInformation (CATCloudOperError, ERR_InsufficientMemory, CLOUDEDITORERRCATALOG) ;

//==============================================================================================================
// Declaration and allocation macros.
//==============================================================================================================

/**
 * Useful macro to allocate an instance of a given class with a default constructor.
 * @param TheClass
 * Any class name with a default constructor.
 * @param TheInstancePtr
 * The returned declared and allocated pointer to an instance of TheClass.
 * @exception CATCloudOperError
 * if not enough memory to perform allocation.
 * @see CATCloudNew
 * @see CATCloudDeclareNew1, CATCloudDeclareNew2, CATCloudDeclareNew3, CATCloudDeclareNew4, CATCloudDeclareNew5
 */

#define CATCloudDeclareNew(TheClass,TheInstancePtr) \
  TheClass* TheInstancePtr = NULL ; \
  CATCloudNew (TheClass, TheInstancePtr) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 1 argument.
 * @param TheClass
 * Any class name with a constructor with 1 argument.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudNew1
 * @see CATCloudDeclareNew, CATCloudDeclareNew2, CATCloudDeclareNew3, CATCloudDeclareNew4, CATCloudDeclareNew5
 */

#define CATCloudDeclareNew1(TheClass,TheInstancePtr,Arg1) \
  TheClass* TheInstancePtr = NULL ; \
  CATCloudNew1 (TheClass, TheInstancePtr, Arg1) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 2 arguments.
 * @param TheClass
 * Any class name with a constructor with 2 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudNew2
 * @see CATCloudDeclareNew, CATCloudDeclareNew1, CATCloudDeclareNew3, CATCloudDeclareNew4, CATCloudDeclareNew5
 */

#define CATCloudDeclareNew2(TheClass,TheInstancePtr,Arg1,Arg2) \
  TheClass* TheInstancePtr = NULL ; \
  CATCloudNew2 (TheClass, TheInstancePtr, Arg1, Arg2) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 3 arguments.
 * @param TheClass
 * Any class name with a constructor with 3 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @param Arg3
 * The 3rd argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudNew3
 * @see CATCloudDeclareNew, CATCloudDeclareNew1, CATCloudDeclareNew2, CATCloudDeclareNew4, CATCloudDeclareNew5
 */

#define CATCloudDeclareNew3(TheClass,TheInstancePtr,Arg1,Arg2,Arg3) \
  TheClass* TheInstancePtr = NULL ; \
  CATCloudNew3 (TheClass, TheInstancePtr, Arg1, Arg2, Arg3) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 4 arguments.
 * @param TheClass
 * Any class name with a constructor with 4 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @param Arg3
 * The 3rd argument to give to the constructor.
 * @param Arg4
 * The 4th argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudNew4
 * @see CATCloudDeclareNew, CATCloudDeclareNew1, CATCloudDeclareNew2, CATCloudDeclareNew3, CATCloudDeclareNew5
 */

#define CATCloudDeclareNew4(TheClass,TheInstancePtr,Arg1,Arg2,Arg3,Arg4) \
  TheClass* TheInstancePtr = NULL ; \
  CATCloudNew4 (TheClass, TheInstancePtr, Arg1, Arg2, Arg3, Arg4) ;

/**
 * Useful macro to allocate an instance of a given class with a constructor with 5 arguments.
 * @param TheClass
 * Any class name with a constructor with 5 arguments.
 * @param TheInstancePtr
 * The returned allocated pointer to an instance of TheClass.
 * @param Arg1
 * The 1st argument to give to the constructor.
 * @param Arg2
 * The 2nd argument to give to the constructor.
 * @param Arg3
 * The 3rd argument to give to the constructor.
 * @param Arg4
 * The 4th argument to give to the constructor.
 * @param Arg5
 * The 5th argument to give to the constructor.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudNew4
 * @see CATCloudDeclareNew, CATCloudDeclareNew1, CATCloudDeclareNew2, CATCloudDeclareNew3, CATCloudDeclareNew4
 */

#define CATCloudDeclareNew5(TheClass,TheInstancePtr,Arg1,Arg2,Arg3,Arg4,Arg5) \
  TheClass* TheInstancePtr = NULL ; \
  CATCloudNew5 (TheClass, TheInstancePtr, Arg1, Arg2, Arg3, Arg4, Arg5) ;

//==============================================================================================================
// Desallocation macros.
//==============================================================================================================

/**
 * Useful macro to delete a pointer to an instance.
 * @param TheInstancePtr
 * The allocated pointer to delete.
 * @see CATCloudNew, CATCloudDeclareNew
 */

#define CATCloudDelete(TheInstancePtr) \
  if (TheInstancePtr) { \
    delete TheInstancePtr ; \
    TheInstancePtr = NULL ; \
  }

/**
 * Useful macro to delete (by a call to the Release method) a pointer to an instance.
 * @param TheInstancePtr
 * The allocated pointer to delete.
 * @see CATCloudNew, CATCloudDeclareNew
 */

#define CATCloudRelease(TheInstancePtr) \
  if (TheInstancePtr) { \
    TheInstancePtr->Release() ; \
    TheInstancePtr = NULL ; \
  }

/**
 * Useful macro to delete (by a call to the Destroy method) a pointer to an instance.
 * @param TheInstancePtr
 * The allocated pointer to delete.
 * @see CATCloudNew, CATCloudDeclareNew
 */

#define CATCloudDestroy(TheInstancePtr) \
  if (TheInstancePtr) { \
    TheInstancePtr->Destroy() ; \
    TheInstancePtr = NULL ; \
  }

/**
 * Useful macro to delete (by a call to the RequestDelayedDestruction method) a pointer to an instance.
 * @param TheInstancePtr
 * The allocated pointer to delete.
 * @see CATCloudNew, CATCloudDeclareNew
 */

#define CATCloudRequestDelayedDestruction(TheInstancePtr) \
  if (TheInstancePtr) { \
    TheInstancePtr->RequestDelayedDestruction() ; \
    TheInstancePtr = NULL ; \
  }

//==============================================================================================================
// Array Allocation and desallocation macros.
//==============================================================================================================

/**
 * Useful macro to allocate an array of instances of a given class with a default constructor.
 * <b>Usage:</b>
 * <dl><dl>
 * <dt>When you have to write:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = new Class [NbItems] ;
 * <dt>if (!InstancePtr) {
 * <dl><dt>...</dl>
 * <dt>}
 * <dt>...
 * <dt>if (InstancePtr) delete [] InstancePtr ;
 * <dt>InstancePtr = NULL ;
 * </dl>
 * </code>
 * <dt>you can write the equivalent code as follow:
 * <code>
 * <dl>
 * <dt>Class* InstancePtr = NULL ;
 * <dt>CATCloudArrayNew (Class, InstancePtr, NbItems) ;
 * <dt>...
 * <dt>CATCloudArrayDelete (InstancePtr) ;
 * </dl>
 * </code>
 * <dt>or:
 * <code>
 * <dl>
 * <dt>CATCloudArrayDeclareNew (Class, InstancePtr, NbItems) ;
 * <dt>...
 * <dt>CATCloudArrayDelete (InstancePtr) ;
 * </dl>
 * </code>
 * </dl></dl>
 *
 * @param TheClass
 * Any class name with a default constructor.
 * @param TheInstancePtr
 * The returned allocated pointer to the array of instances of TheClass.
 * @param NbItems
 * The number of items to allocate.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudArrayDeclareNew, CATCloudArrayDelete
 */

#define CATCloudArrayNew(TheClass,TheInstancePtr,NbItems) \
  TheInstancePtr = new TheClass[NbItems] ; \
  if (!TheInstancePtr) CATThrowInformation (CATCloudOperError, ERR_InsufficientMemory, CLOUDEDITORERRCATALOG) ;

/**
 * Useful macro to declare and allocate an array of instances of a given class with a default constructor.
 * @param TheClass
 * Any class name with a default constructor.
 * @param TheInstancePtr
 * The returned allocated pointer to the array of instances of TheClass.
 * @param NbItems
 * The number of items to allocate.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudArrayNew, CATCloudArrayDelete
 */

#define CATCloudArrayDeclareNew(TheClass,TheInstancePtr,NbItems) \
  TheClass* TheInstancePtr = NULL ; \
  CATCloudArrayNew (TheClass, TheInstancePtr, NbItems) ;

/**
 * Useful macro to declare and allocate an array of instances of a given class with a default constructor.
 * @param TheClass
 * Any class name with a default constructor.
 * @param TheInstancePtr
 * The returned allocated pointer to the array of instances of TheClass.
 * @param NbItems
 * The number of items to allocate.
 * @exception CATCloudOperError
 * If not enough memory to perform allocation.
 * @see CATCloudArrayNew, CATCloudArrayDelete
 */

/**
 * Useful macro to delete an array.
 * @param TheInstancePtr
 * The array to delete.
 * @see CATCloudArrayNew, CATCloudArrayDeclareNew
 */

#define CATCloudArrayDelete(TheInstancePtr) \
  if (TheInstancePtr) { \
    delete [] TheInstancePtr ; \
    TheInstancePtr = NULL ; \
  }

//==============================================================================================================
// Error management macros.
//==============================================================================================================

/**
 * Useful macro to throw an instance of an error class with a type set to CATErrorTypeCritical.
 * @param TheErrorClass
 * The error class.<br>
 * <b>Legal values</b>: This class must derive from CATError
 * @param TheMessageKey
 * The NLS message key (with form ERR_xxxx).
 * @param TheMessageCatalog
 * The NLS catalog name.
 * @see CATThrowFatal, CATThrowWarning, CATThrowInformation
 * @see CATCloudOperError, CATError
 */

#define CATThrowCritical(TheErrorClass,TheMessageKey,TheMessageCatalog) \
  { \
    TheErrorClass* TheErrorPtr = new TheErrorClass (TheMessageKey, TheMessageCatalog) ; \
    TheErrorPtr->SetInformationOnErrorType (CATErrorTypeCritical) ; \
    CATThrow (TheErrorPtr) ; \
  }

/**
 * Useful macro to throw an instance of an error class with a type set to CATErrorTypeFatal.
 * @param TheErrorClass
 * The error class.<br>
 * <b>Legal values</b>: This class must derive from CATError
 * @param TheMessageKey
 * The NLS message key (with form ERR_xxxx).
 * @param TheMessageCatalog
 * The NLS catalog name.
 * @see CATThrowCritical, CATThrowWarning, CATThrowInformation
 * @see CATCloudOperError, CATError
 */

#define CATThrowFatal(TheErrorClass,TheMessageKey,TheMessageCatalog) \
  { \
    TheErrorClass* TheErrorPtr = new TheErrorClass (TheMessageKey, TheMessageCatalog) ; \
    TheErrorPtr->SetInformationOnErrorType (CATErrorTypeFatal) ; \
    CATThrow (TheErrorPtr) ; \
  }

/**
 * Useful macro to throw an instance of an error class with a type set to CATErrorTypeWarning.
 * @param TheErrorClass
 * The error class.<br>
 * <b>Legal values</b>: This class must derive from CATError
 * @param TheMessageKey
 * The NLS message key (with form ERR_xxxx).
 * @param TheMessageCatalog
 * The NLS catalog name.
 * @see CATThrowCritical, CATThrowFatal, CATThrowInformation
 * @see CATCloudOperError, CATError
 */

#define CATThrowWarning(TheErrorClass,TheMessageKey,TheMessageCatalog) \
  { \
    TheErrorClass* TheErrorPtr = new TheErrorClass (TheMessageKey, TheMessageCatalog) ; \
    TheErrorPtr->SetInformationOnErrorType (CATErrorTypeWarning) ; \
    CATThrow (TheErrorPtr) ; \
  }

/**
 * Useful macro to throw an instance of an error class with a type set to CATErrorTypeInformation.
 * @param TheErrorClass
 * The error class.<br>
 * <b>Legal values</b>: This class must derive from CATError
 * @param TheMessageKey
 * The NLS message key (with form ERR_xxxx).
 * @param TheMessageCatalog
 * The NLS catalog name.
 * @see CATThrowCritical, CATThrowFatal, CATThrowWarning
 * @see CATCloudOperError, CATError
 */

#define CATThrowInformation(TheErrorClass,TheMessageKey,TheMessageCatalog) \
  { \
    TheErrorClass* TheErrorPtr = new TheErrorClass (TheMessageKey, TheMessageCatalog) ; \
    TheErrorPtr->SetInformationOnErrorType (CATErrorTypeInformation) ; \
    CATThrow (TheErrorPtr) ; \
  }

//==============================================================================================================
// Error class for all cloud operators.
//==============================================================================================================

/**
 * Usefull error class for all Cloud operators.<br>
 * <b>Usage:</b>
 * <code>
 * <dl><dl>
 * <dt>if (<i>"some error occurs"</i>) {
 * <dl>
 * <dt><b>CATThrow</b> (new CATCloudOperError (message key, message catalog)) ;
 * <dt>// or use a macro <b>CATThrow<i>Style</i></b>
 * <dt><b>CATThrow<i>Style</i></b> (CATCloudOperError, message key, message catalog) ;
 * </dl>
 * <dt>}
 * </dl></dl>
 * </code>
 *
 * @see CATThrowInformation, CATThrowWarning, CATThrowFatal, CATThrowCritical.
 * @see CLOUDEDITORERRCATALOG.
 * @see CATCloudOperErrorTool.
 */

class ExportedByCATCloudBasicResources CATCloudOperError : public CATError
{
public :

  /**
   * Implemente standard CATError class
   * @see CATError
   */
  CATDeclareError (CATCloudOperError, CATError)

} ;

#endif

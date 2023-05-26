
// COPYRIGHT DASSAULT SYSTEMES 1999

 /** 
  * @nodoc 
  * Switches used by the macros to declare classes which implement 
  * hash table of pointers to a user-defined type X.
  * <br><b>Role</b>
  * Each #define statement acts as a switch which triggers
  * the declaration and the definition of a method within a
  * hash table class. This lets you create hash table classes
  * with just the functionalities which are appropriate to
  * your problem, thereby sparing memory. 
  * If you want the full set of available
  * functionalities, you should include this file in your hash table class 
  * declaration file. This will cause all hash table methods to be defined for
  * your hash table class.
  */
#define	CATHDICO_Retrieve
/**
 * @nodoc
 */
#define	CATHDICO_Locate
/**
 * @nodoc
 */
#define	CATHDICO_LocatePosition
/**
 * @nodoc
 */
#define	CATHDICO_Next
/**
 * @nodoc
 */
#define	CATHDICO_NextPosition
/**
 * @nodoc
 */
#define	CATHDICO_Remove
/**
 * @nodoc
 */
#define	CATHDICO_RemovePosition
/**
 * @nodoc
 */
#define	CATHDICO_RemoveAll
/**
 * @nodoc
 */
#define	CATHDICO_Dimension
/**
 * @nodoc
 */
#define	CATHDICO_Collisions
/**
 * @nodoc
 */
#define	CATHDICO_Unused
/**
 * @nodoc
 */
#define	CATHDICO_PrintStats
/**
 * @nodoc
 */
#define	CATHDICO_PrintAddr
/**
 * @nodoc
 */
#define	CATHDICO_ApplyMemberFunct
/**
 * @nodoc
 */
#define	CATHDICO_ApplyMemberFunctConst
/**
 * @nodoc
 */
#define	CATHDICO_ApplyGlobalFunct
/**
 * @nodoc
 */
#define	CATHDICO_ApplyDelete
/**
 * @nodoc
 */
#define	CATHDICO_ostreamOP

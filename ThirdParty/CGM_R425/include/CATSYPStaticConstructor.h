#ifndef CATSYPStaticConstructor_H
#define CATSYPStaticConstructor_H

/** @ingroup groupUIVCoreTools
 * @defgroup groupUIVCoreToolsStaticConstructor UIVCoreTools Static Constructor
 * The <b>UIVCoreTools Static Constructor</b> groups macros that can
 * be used to implement static constructors for classes in C++.
 *
 * You can think of a static constructor as a constructor that is
 * called only once for a given class when the first instance of the
 * class is built and that can be used to initialize things (including
 * static members) that must only be initialized once.
 *
 * The C++ language does not offer anything like that that's why the
 * macros of this group exist.
 *
 * @par Usage
 * To use this infrastructure you have to:
 *   - create a private static member function that takes no argument. 
 *     This function will be the static constructor.
 *   - in the code of every constructors of the class use the 
 *     @ref STATIC_CONSTRUCTOR macro.
 *   - use the @ref STATIC_CONSTRUCTOR_DEF in the source file that
 *     defines the constructors, before the definition of these
 *     constructors.
 *
 * @par Example
 * If the header file contains:
 * @code
 * #ifndef A_H
 * #define A_H
 *
 * class A
 * {
 * public:
 *   A();
 *   A(int);
 *   A(A&);
 * private:
 *   // Static constructor
 *   static void initA();
 * };
 *
 * #endif // A_H
 * @endcode
 *
 * @par
 * The source file is:
 * @code
 * #include <A.h>
 * #include <CATSYPStaticConstructor.h>
 *
 * STATIC_CONSTRUCTOR_DEF(A, initA);
 *
 * A::A() 
 * {
 *   STATIC_CONSTRUCTOR(A, initA);
 *   ...
 * }
 * 
 * A::A(int) 
 * {
 *   STATIC_CONSTRUCTOR(A, initA);
 *   ...
 * }
 * 
 * A::A(A&) 
 * {
 *   STATIC_CONSTRUCTOR(A, initA);
 *   ...
 * }
 *
 * void A::initA()
 * {
 *   // this function will only be called once when the first instance
 *   // of A is created.
 *   ...
 * }
 *
 * @endcode
 *
 * @par Limitations
 * All the constructors have to be defined in the same source file.<br/>
 * This is due to the fact that @ref STATIC_CONSTRUCTOR_DEF uses a
 * variable that is static (so private to the compilation unit).
 *
 * @par Thread Safety
 * As of today, this infrastructure is NOT thread-safe. If the
 * constructors are called from different threads, then there is a
 * risk that the function used as a static constructor is called
 * mutliple times.
 *
 * @par
 * Making this infrastructure thread-safe (and still efficient) is
 * simple but has been to done (and tested).
 */



/** @ingroup groupUIVCoreToolsStaticConstructor
 * Macro that must be used in all the constructors of the class to
 * call the static function used as a static constructor.
 *
 * The macro @ref STATIC_CONSTRUCTOR_DEF that defines the flag
 * indicating that the function has already been called must appear
 * before the first occurence of this macro in the source file.
 *
 * @param clazz the symbol of the class
 *
 * @param staticMemberFunction the symbol of the member function of @a
 * clazz to call as a static constructor. It must take no
 * argument. Its returned value is ignored and should be @c void.
 *
 * @see groupUIVCoreToolsStaticConstructor
 * @see STATIC_CONSTRUCTOR_DEF
 */
#define STATIC_CONSTRUCTOR(clazz, staticMemberFunction) \
  do {                                                  \
    if (!__##clazz##__##staticMemberFunction##__called) {   \
      __##clazz##__##staticMemberFunction##__called = 1;    \
      clazz::staticMemberFunction();                        \
    }                                                   \
  } while(0)

/** @ingroup groupUIVCoreToolsStaticConstructor
 * Macro that defines the flag indicating that the function has
 * already been called.
 *
 * It must appear before @ref STATIC_CONSTRUCTOR.
 *
 * It should not be used in an header file (unless you know what you
 * are doing) since it declares a local variable that is only seen by
 * the compilation unit (it is static).
 *
 * @param clazz the symbol of the class
 *
 * @param staticMemberFunction the symbol of the member function of @a
 * clazz to call as a static constructor. It must take no
 * argument. Its returned value is ignored and should be @c void.
 *
 * @see groupUIVCoreToolsStaticConstructor
 * @see STATIC_CONSTRUCTOR
 */
#define STATIC_CONSTRUCTOR_DEF(clazz, staticMemberFunction)         \
  static int __##clazz##__##staticMemberFunction##__called = 0;  

#endif // CATSYPStaticConstructor_H

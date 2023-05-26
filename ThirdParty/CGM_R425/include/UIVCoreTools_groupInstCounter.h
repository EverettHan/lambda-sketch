/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation group that aggregates instance counter debug tool.
 */

#error should not be included; only there for doxygen

/** @ingroup groupUIVCoreTools
 * @defgroup groupUIVCoreToolsInstanceCounter UIVCoreTools Instance Counter
 * The <b>UIVCoreTools Instance Counter</b> groups macros that can
 * be used to detect leaks.
 *
 * @par Overview
 * A class using an instance counter calls explictely this instance
 * counter in all its constructor and in its destructor. When the @c
 * UIVCoreTools shared library is unloaded, counters that are not a @c
 * 0 trigger the print of a trace to @c stdout that specifies the
 * number of instances that still exists of classes. Note that the
 * traces is printed in @c stdout so that it is visible in the @c
 * .traces file of @c ODT.
 * 
 * @par
 * Counters are instantiated, incremented and decremented using
 * macros. Those macros are empty when the option @c -dev of @c mkmk
 * is not used. As a consequence <b>counters are only avaiable on
 * classes built using @c mkmk @c -dev</b>. For example the counters
 * are not available in the BSF.
 *
 * @par
 * The instance counter is an instance of the @ref
 * CATSYPCheckInstanceCounter. This instance is created by the @ref
 * CREATE_INSTANCE_COUNTER macro. This macro should be put in the
 * class implementation file before any constructor/destructor.<br/>
 * In each constructor @ref INC_INSTANCE_COUNTER macro must be used
 * (as first line of the constructor) and in the destructor @ref
 * DEC_INSTANCE_COUNTER must be used.
 *
 * @par Example
 * If the header file contains the class:
 * @code
 * class MyClass {
 * public:
 *   MyClass();
 *   MyClass(int);
 *   MyClass(const MyClass &);
 *   ~MyClass();
 * };
 * @endcode
 *
 * @par
 * Then the implementation file should contain:
 * @code
 * ...
 * #include <CATSYPCheck.h>
 * ...
 *
 * CREATE_INSTANCE_COUNTER(MyClass);
 *
 * MyClass::MyClass() {
 *   INC_INSTANCE_COUNTER(MyClass);
 *   ...
 * }
 *
 * MyClass::MyClass(int) {
 *   INC_INSTANCE_COUNTER(MyClass);
 *   ...
 * }
 *
 * MyClass::MyClass(const MyClass &) {
 *   INC_INSTANCE_COUNTER(MyClass);
 *   ...
 * }
 *
 * MyClass::~MyClass() {
 *   DEC_INSTANCE_COUNTER(MyClass);
 *   ...
 * }
 * @endcode
 * 
 * @par
 * If the @c MyClass is leaking with two instances still in memory,
 * the traces printed in @c stdout are:
 * @verbatim
CATSYPCheckInstanceCounter: Possible leak on class MyClass, there is 2 instances that still exists!@endverbatim
 */

// COPYRIGHT DASSAULT SYSTEMES 2012
//=============================================================================
//
// CATCAfrVariablesServices
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
//                                                                          VV6
//=============================================================================

#ifndef CATCAfrVariablesServices_H
#define CATCAfrVariablesServices_H

#include "CATAfrComponentsModel.h"

class CATUnicodeString;

/**
 * Utility class to manage CAfr global variables using C++ code.
 *
 * You do not have to create an object of this type. You can use
 * directly the static member functions defined by it.
 *
 * Using this services, you can create a new CAfr global variable, get the
 * value of a previously created CAfr global variable, modify the value of
 * a previously created CAfr global variable, or even delete a CAfr global
 * variable.
 */
class ExportedByCATAfrComponentsModel CATCAfrVariablesServices
{

public:
  /**
   * Create a new CAfr global variable.
   * You can't create a CAfr global variable with a name that is
   * already used.
   *
   * i_name: name of the variable to create. Can't be an empty string.
   * i_value: the value to give to the variable.
   *
   * return 1 in case of success, 0 otherwise.
   */
  static int CreateGlobalVariable(const CATUnicodeString & i_name, const CATUnicodeString & i_value);

  /**
   * Modify the value of a previously created CAfr global variable.
   *
   * i_name: name of the variable to modify. Can't be an empty string.
   * i_newValue: the new value to set to the variable.
   *
   * return 1 in case of success, 0 otherwise.
   */
  static int SetGlobalVariableValue(const CATUnicodeString & i_name, const CATUnicodeString & i_newValue);

  /*
   * Verify the existance of a previously created CAfr global variable.
   *
   * i_name: name of the variable to get the value. Can't be an empty string.
   *
   * return 1 if the variable exists, 0 otherwise.
   */
  static int IsExistingGlobalVariable(const CATUnicodeString & i_name);

  /**
   * Get the value of a previously created CAfr global variable.
   *
   * i_name: name of the variable to get the value. Can't be an empty string.
   * o_value: the retrieved value of the variable on success.
   *
   * return 1 in case of success, 0 otherwise.
   */
  static int GetGlobalVariableValue(const CATUnicodeString & i_name, CATUnicodeString & o_value);

  /**
   * Delete the given CAfr global variable.
   *
   * i_name: name of the variable to delete. Can't be an empty string.
   *
   * return 1 in case of success, 0 otherwise.
   */
  static int DeleteGlobalVariable(const CATUnicodeString & i_name);

private:
  // Constructor and destructor are declared private so that this class
  // behaves like a namespace for the static member functions
  CATCAfrVariablesServices();
  virtual ~CATCAfrVariablesServices();
  // Copy constructor and assignement operator not implemented
  CATCAfrVariablesServices(const CATCAfrVariablesServices &);
  CATCAfrVariablesServices & operator= (const CATCAfrVariablesServices &);

};

#endif

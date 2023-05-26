#ifndef DSYINSINFRA_PROTECTEDINTERFACES_DSYINSLISTINSTALLSAPI_H_
#define DSYINSINFRA_PROTECTEDINTERFACES_DSYINSLISTINSTALLSAPI_H_

#include <string>
#include <vector>

#include "DSYInsListInstallsAPIModule.h"

/**
 * Helper class to scan V6 installations made by the DS installer
 * To use the lib:
 *   LINK_WITH = DSYInsListInstallsAPI
 * Please contact the Installation team before using
 */

/**
 * Represents an installation
 * All strings are UTF-8 encoded
 */
struct ExportedByDSYInsListInstallsAPI DSYInsListInstallsItem {
  DSYInsListInstallsItem(std::string iGAlevel, std::string iInstallationType, std::string iHFLevel, std::string iIdent, std::string iPath);

  std::string _GALevel;
  std::string _InstallationType;
  std::string _HFLevel;
  std::string _Ident;
  std::string _Path;
};

/**
 * Usage
 * - Filter installations using Set__() functions
 * - Call GetInstallations() to get a list of existing installations
 */
class ExportedByDSYInsListInstallsAPI DSYInsListInstallsAPI {

  public:

    // Filter on GA level. Syntax is generally a letter + numbers
    // e.g. B420
    void SetGALevel(const std::string & iGALevel);

    // Filter on InstallationType
    // e.g. Desktop
    // Note: '*' can be used to substitute the end of the Installation Type
    // e.g. Desk* will both match Desktop and DesktopCloud
    void SetInstallationType(const std::string & iInstallationType);

    // Filter on HF level
    // e.g. 420.1
    void SetHFLevel(const std::string & iHFLevel);

    // Get existing installations
    // Each call scans the registry
    std::vector<DSYInsListInstallsItem> GetInstallations() const;

  private:

    // Filters
    std::string _GALevel;
    std::string _InstallationType;
    std::string _HFLevel;
};

#endif // DSYINSINFRA_PROTECTEDINTERFACES_DSYINSLISTINSTALLSAPI_H_

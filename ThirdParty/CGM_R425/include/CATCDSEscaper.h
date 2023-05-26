//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014/02/10
//===================================================================

#ifndef CATCDSEscaper_H
#define CATCDSEscaper_H

#include "CATCDSJSON.h"

#include <string>

class ExportedByJSON CATCDSEscaper
{
public:
  explicit CATCDSEscaper(std::string& result);

private:
  CATCDSEscaper(const CATCDSEscaper&);
  CATCDSEscaper& operator=(const CATCDSEscaper&);

public:
  void Escape(std::string const &str);
  void EscapeString(std::string const &str);

private:
  void Escape(std::string const &str, int start);
  void DoEscape(std::string const &str, int current, std::string const &pattern);

private:
  std::string& result_;
  int index_;
};

#endif /*CATCDSEscaper_H*/

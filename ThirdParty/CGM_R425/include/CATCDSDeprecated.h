//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014/08/07
//===================================================================

#ifndef CATCDSDeprecated_H
#define CATCDSDeprecated_H

#if defined(_MSC_VER) && (_MSC_VER >= 1500)
# define CATCDS_DEPRECATED_IMPL(msg, decl) __declspec(deprecated(msg)) decl
#else
# define CATCDS_DEPRECATED_IMPL(msg, decl) decl
#endif

#define CATCDS_DEPRECATED_IMPL_FW(fw, date, msg, decl) CATCDS_DEPRECATED_IMPL("\n" \
                                                                     "###############################################################################\n" \
                                                                     fw "\n" \
                                                                     "################################  DEPRECATED  #################################\n" \
                                                                     "###############################################################################\n" \
                                                                     "#########################  please migrate your code   #########################\n" \
                                                                     "######################### deprecated since " date " #########################\n" \
                                                                     "###############################################################################\n" \
                                                                     "###############################################################################\n" \
                                                                     "##\n" \
                                                                     "## " msg "\n" \
                                                                     "##\n" \
                                                                     "###############################################################################\n" \
                                                                     "###############################################################################\n" \
                                                                     , decl)
#ifndef CATCDS_DEPRECATED
#define CATCDS_DEPRECATED(date, msg, decl) CATCDS_DEPRECATED_IMPL_FW("##################################  CATCDS  ###################################", \
                                                             date, msg, decl)
#endif

#endif /*CATCDSDeprecated_H*/

#ifndef CATIOLogger_H
#define CATIOLogger_H

#include "CATSGUtil.h"
#ifdef SG_COMPOSITES_MULTIOS

#include <sstream>
#ifndef _WINDOWS_SOURCE
#include <iostream>
#endif //!_WINDOWS_SOURCE

class CATIOLogger
{
public:
    inline void LogI(const char* iMsg) {
#ifdef _WINDOWS_SOURCE
        OutputDebugStringA(iMsg);
#else // _WINDOWS_SOURCE
        std::cerr << iMsg;
#endif // !_WINDOWS_SOURCE
    }

    //    inline void LogI(const char* iMsg, const float iValue) {
    //        std::stringstream stream;
    //        stream << iMsg << std::scientific << iValue << std::endl;
    //        LogI(stream.str().c_str());
    //    }

    inline void LogI(const char* iMsg, CATSG::int32 iValue) {
        std::stringstream stream;
        stream << iMsg << iValue << std::endl;
        LogI(stream.str().c_str());
    }

    inline void LogI(const char* iMsg, CATSG::uint32 iValue) {
        std::stringstream stream;
        stream << iMsg << iValue << std::endl;
        LogI(stream.str().c_str());
    }

    //#ifdef PLATEFORME_DS64
    //    inline void LogI(const char* iMsg, CATSG::int64 iValue) {
    //        std::stringstream stream;
    //        stream << iMsg << iValue << std::endl;
    //        LogI(stream.str().c_str());
    //    }
    //
    //    inline void LogI(const char* iMsg, CATSG::uint64 iValue) {
    //        std::stringstream stream;
    //        stream << iMsg << iValue << std::endl;
    //        LogI(stream.str().c_str());
    //    }
    //#else // PLATEFORME_DS64
    //    inline void LogI(const char* iMsg, CATSG::long32 iValue) {
    //        std::stringstream stream;
    //        stream << iMsg << iValue << std::endl;
    //        LogI(stream.str().c_str());
    //    }
    //
    //    inline void LogI(const char* iMsg, CATSG::ulong32 iValue) {
    //        std::stringstream stream;
    //        stream << iMsg << iValue << std::endl;
    //        LogI(stream.str().c_str());
    //    }
    //#endif // !PLATEFORME_DS64
    //
    //    inline void LogI(const char* iMsg, const void* iPtr) {
    //        std::stringstream stream;
    //        stream << iMsg << static_cast<void*>(iPtr) << std::endl;
    //        LogI(stream.str().c_str());
    //    }

    inline void LogI(const char* iMsg, double iValue1, double iValue2, double iValue3) {
        std::stringstream stream;
        stream.precision(20);
        stream << iMsg << std::scientific << iValue1 << " " << iValue2 << " " << iValue3 << std::endl;
        LogI(stream.str().c_str());
    }

    inline void LogI(const char* iMsg, double iValue) {
        std::stringstream stream;
        stream.precision(20);
        stream << iMsg << std::scientific << iValue << std::endl;
        LogI(stream.str().c_str());
    }
};

#endif//SG_COMPOSITES_MULTIOS
#endif//CATIOLogger_H

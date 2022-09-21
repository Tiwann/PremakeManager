#pragma once
#include <cassert>
#define PremanAssert(msg) assert(msg)

#if defined(_WIN32)
    #if defined(_WIN64)
        #define PREMAN_WINDOWS
    #else
        #error "This program only can run on x64"
    #endif
#elif defined(__unix__)
    #define PREMAN_UNIX
#elif defined(__APPLE__)
    #define PREMAN_APPLE
#endif


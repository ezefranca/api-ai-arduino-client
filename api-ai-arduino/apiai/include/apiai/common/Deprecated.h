#ifndef DEPRECATED_H
#define DEPRECATED_H

//#include <type_info>

#ifdef __GNUC__
    #define DEPRECATED __attribute__ ((deprecated))
#elif defined(_MSC_VER)
    #define DEPRECATED __declspec(deprecated)
#else
    #define DEPRECATED
    #pragma warning("DEPRECATED is not defined")
#endif

#ifdef __GNUC__
    #define PUSH_DEPRECATED_WARNING() \
        _Pragma("GCC diagnostic push") \
        _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")

    #define POP_DEPRECATED_WARNING() \
        _Pragma("GCC diagnostic pop")
#elif defined(_MSC_VER)
    #define PUSH_DEPRECATED_WARNING() \
        __pragma(warning( push, 0 )) \
        __pragma(warning( disable: warning-code, 0 ))

    #define POP_DEPRECATED_WARNING() \
        __pragma(warning( pop ))
#else
    #define PUSH_DEPRECATED_WARNING()
    #define POP_DEPRECATED_WARNING()

    #pragma warning("PUSH_DEPRECATED_WARNING and POP_DEPRECATED_WARNING is not defined")
#endif

#define IGNODE_DEPRECATED_WARNING(__CODE__) \
    PUSH_DEPRECATED_WARNING() \
    __CODE__ \
    POP_DEPRECATED_WARNING()

#endif // DEPRECATED_H

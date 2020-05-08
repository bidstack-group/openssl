#if not __ANDROID__
    #error "This header file should only be used for building Android native library."
#endif

#ifdef __ARM_ARCH
    #if __ARM_ISA_A64
        #define SIXTY_FOUR_BIT_LONG
        #undef SIXTY_FOUR_BIT
        #undef THIRTY_TWO_BIT
    #elif __ARM_ISA_ARM
        #undef SIXTY_FOUR_BIT_LONG
        #undef SIXTY_FOUR_BIT
        #define THIRTY_TWO_BIT
    #else
        #error "Cannot determine ARM architecture"
    #endif //__ARM_ISA_ARM
#elif __i386 //__ARM_ARCH
    #undef SIXTY_FOUR_BIT_LONG
    #undef SIXTY_FOUR_BIT
    #define THIRTY_TWO_BIT
#elif __x86_64
    #define SIXTY_FOUR_BIT_LONG
    #undef SIXTY_FOUR_BIT
    #undef THIRTY_TWO_BIT
#else
    #error "Unsupported arch"
#endif //__ARM_ARCH


#if not __ANDROID__
    #error "This header file should only be used for building Android native library."
#endif

#ifdef __ARM_ARCH
    #if __ARM_ISA_A64
        #define PLATFORM "platform: android-arm64"
        #define DATE "built on: Fri Jan 17 12:19:37 2020 UTC"
        static const char compiler_flags[] = {
            'c','o','m','p','i','l','e','r',':',' ','c','l','a','n','g',' ',
            '-','f','P','I','C',' ','-','p','t','h','r','e','a','d',' ',' ',
            '-','t','a','r','g','e','t',' ','a','a','r','c','h','6','4','-',
            'l','i','n','u','x','-','a','n','d','r','o','i','d',' ','-','g',
            'c','c','-','t','o','o','l','c','h','a','i','n',' ','/','o','p',
            't','/','a','n','d','r','o','i','d','-','n','d','k','-','r','2',
            '0','b','/','t','o','o','l','c','h','a','i','n','s','/','a','a',
            'r','c','h','6','4','-','l','i','n','u','x','-','a','n','d','r',
            'o','i','d','-','4','.','9','/','p','r','e','b','u','i','l','t',
            '/','l','i','n','u','x','-','x','8','6','_','6','4',' ','-','-',
            's','y','s','r','o','o','t','=','/','o','p','t','/','a','n','d',
            'r','o','i','d','-','n','d','k','-','r','2','0','b','/','p','l',
            'a','t','f','o','r','m','s','/','a','n','d','r','o','i','d','-',
            '2','1','/','a','r','c','h','-','a','r','m','6','4',' ','-','W',
            'a','l','l',' ','-','O','3',' ','-','D','O','P','E','N','S','S',
            'L','_','U','S','E','_','N','O','D','E','L','E','T','E',' ','-',
            'D','O','P','E','N','S','S','L','_','P','I','C',' ','-','D','_',
            '_','A','N','D','R','O','I','D','_','A','P','I','_','_','=','2',
            '1',' ','-','i','s','y','s','t','e','m',' ','/','o','p','t','/',
            'a','n','d','r','o','i','d','-','n','d','k','-','r','2','0','b',
            '/','s','y','s','r','o','o','t','/','u','s','r','/','i','n','c',
            'l','u','d','e','/','a','a','r','c','h','6','4','-','l','i','n',
            'u','x','-','a','n','d','r','o','i','d',' ','-','i','s','y','s',
            't','e','m',' ','/','o','p','t','/','a','n','d','r','o','i','d',
            '-','n','d','k','-','r','2','0','b','/','s','y','s','r','o','o',
            't','/','u','s','r','/','i','n','c','l','u','d','e',' ','-','D',
            'N','D','E','B','U','G',' ','-','D','_','_','A','N','D','R','O',
            'I','D','_','A','P','I','_','_','=','2','1','\0'
        };
    #elif __ARM_ISA_ARM
        #define PLATFORM "platform: android-arm"
        #define DATE "built on: Fri Jan 17 12:10:45 2020 UTC"
        static const char compiler_flags[] = {
            'c','o','m','p','i','l','e','r',':',' ','c','l','a','n','g',' ',
            '-','f','P','I','C',' ','-','p','t','h','r','e','a','d',' ',' ',
            '-','t','a','r','g','e','t',' ','a','r','m','v','7','a','-','l',
            'i','n','u','x','-','a','n','d','r','o','i','d','e','a','b','i',
            ' ','-','g','c','c','-','t','o','o','l','c','h','a','i','n',' ',
            '/','o','p','t','/','a','n','d','r','o','i','d','-','n','d','k',
            '-','r','2','0','b','/','t','o','o','l','c','h','a','i','n','s',
            '/','a','r','m','-','l','i','n','u','x','-','a','n','d','r','o',
            'i','d','e','a','b','i','-','4','.','9','/','p','r','e','b','u',
            'i','l','t','/','l','i','n','u','x','-','x','8','6','_','6','4',
            ' ','-','-','s','y','s','r','o','o','t','=','/','o','p','t','/',
            'a','n','d','r','o','i','d','-','n','d','k','-','r','2','0','b',
            '/','p','l','a','t','f','o','r','m','s','/','a','n','d','r','o',
            'i','d','-','2','1','/','a','r','c','h','-','a','r','m',' ','-',
            'W','a','l','l',' ','-','O','3',' ','-','D','O','P','E','N','S',
            'S','L','_','U','S','E','_','N','O','D','E','L','E','T','E',' ',
            '-','D','O','P','E','N','S','S','L','_','P','I','C',' ','-','D',
            '_','_','A','N','D','R','O','I','D','_','A','P','I','_','_','=',
            '2','1',' ','-','i','s','y','s','t','e','m',' ','/','o','p','t',
            '/','a','n','d','r','o','i','d','-','n','d','k','-','r','2','0',
            'b','/','s','y','s','r','o','o','t','/','u','s','r','/','i','n',
            'c','l','u','d','e','/','a','r','m','-','l','i','n','u','x','-',
            'a','n','d','r','o','i','d','e','a','b','i',' ','-','i','s','y',
            's','t','e','m',' ','/','o','p','t','/','a','n','d','r','o','i',
            'd','-','n','d','k','-','r','2','0','b','/','s','y','s','r','o',
            'o','t','/','u','s','r','/','i','n','c','l','u','d','e',' ','-',
            'D','N','D','E','B','U','G',' ','-','D','_','_','A','N','D','R',
            'O','I','D','_','A','P','I','_','_','=','2','1','\0'
        };
    #else
        #error "Cannot determine ARM architecture"
    #endif //__ARM_ISA_ARM
#elif __i386
    #define PLATFORM "platform: android-x86"
    #define DATE "built on: Fri Jan 17 11:09:15 2020 UTC"
    static const char compiler_flags[] = {
        'c','o','m','p','i','l','e','r',':',' ','c','l','a','n','g',' ',
        '-','f','P','I','C',' ','-','p','t','h','r','e','a','d',' ',' ',
        '-','t','a','r','g','e','t',' ','i','6','8','6','-','l','i','n',
        'u','x','-','a','n','d','r','o','i','d',' ','-','g','c','c','-',
        't','o','o','l','c','h','a','i','n',' ','/','o','p','t','/','a',
        'n','d','r','o','i','d','-','n','d','k','-','r','2','0','b','/',
        't','o','o','l','c','h','a','i','n','s','/','x','8','6','-','4',
        '.','9','/','p','r','e','b','u','i','l','t','/','l','i','n','u',
        'x','-','x','8','6','_','6','4',' ','-','-','s','y','s','r','o',
        'o','t','=','/','o','p','t','/','a','n','d','r','o','i','d','-',
        'n','d','k','-','r','2','0','b','/','p','l','a','t','f','o','r',
        'm','s','/','a','n','d','r','o','i','d','-','2','1','/','a','r',
        'c','h','-','x','8','6',' ','-','W','a','l','l',' ','-','O','3',
        ' ','-','f','o','m','i','t','-','f','r','a','m','e','-','p','o',
        'i','n','t','e','r',' ','-','D','O','P','E','N','S','S','L','_',
        'U','S','E','_','N','O','D','E','L','E','T','E',' ','-','D','O',
        'P','E','N','S','S','L','_','P','I','C',' ','-','D','_','_','A',
        'N','D','R','O','I','D','_','A','P','I','_','_','=','2','1',' ',
        '-','i','s','y','s','t','e','m',' ','/','o','p','t','/','a','n',
        'd','r','o','i','d','-','n','d','k','-','r','2','0','b','/','s',
        'y','s','r','o','o','t','/','u','s','r','/','i','n','c','l','u',
        'd','e','/','i','6','8','6','-','l','i','n','u','x','-','a','n',
        'd','r','o','i','d',' ','-','i','s','y','s','t','e','m',' ','/',
        'o','p','t','/','a','n','d','r','o','i','d','-','n','d','k','-',
        'r','2','0','b','/','s','y','s','r','o','o','t','/','u','s','r',
        '/','i','n','c','l','u','d','e',' ','-','D','N','D','E','B','U',
        'G',' ','-','D','_','_','A','N','D','R','O','I','D','_','A','P',
        'I','_','_','=','2','1','\0'
    };
#elif __x86_64
    #define PLATFORM "platform: android-x86_64"
    #define DATE "built on: Fri Jan 17 12:33:44 2020 UTC"
    static const char compiler_flags[] = {
        'c','o','m','p','i','l','e','r',':',' ','c','l','a','n','g',' ',
        '-','f','P','I','C',' ','-','p','t','h','r','e','a','d',' ',' ',
        '-','t','a','r','g','e','t',' ','x','8','6','_','6','4','-','l',
        'i','n','u','x','-','a','n','d','r','o','i','d',' ','-','g','c',
        'c','-','t','o','o','l','c','h','a','i','n',' ','/','o','p','t',
        '/','a','n','d','r','o','i','d','-','n','d','k','-','r','2','0',
        'b','/','t','o','o','l','c','h','a','i','n','s','/','x','8','6',
        '_','6','4','-','4','.','9','/','p','r','e','b','u','i','l','t',
        '/','l','i','n','u','x','-','x','8','6','_','6','4',' ','-','-',
        's','y','s','r','o','o','t','=','/','o','p','t','/','a','n','d',
        'r','o','i','d','-','n','d','k','-','r','2','0','b','/','p','l',
        'a','t','f','o','r','m','s','/','a','n','d','r','o','i','d','-',
        '2','1','/','a','r','c','h','-','x','8','6','_','6','4',' ','-',
        'W','a','l','l',' ','-','O','3',' ','-','D','O','P','E','N','S',
        'S','L','_','U','S','E','_','N','O','D','E','L','E','T','E',' ',
        '-','D','O','P','E','N','S','S','L','_','P','I','C',' ','-','D',
        '_','_','A','N','D','R','O','I','D','_','A','P','I','_','_','=',
        '2','1',' ','-','i','s','y','s','t','e','m',' ','/','o','p','t',
        '/','a','n','d','r','o','i','d','-','n','d','k','-','r','2','0',
        'b','/','s','y','s','r','o','o','t','/','u','s','r','/','i','n',
        'c','l','u','d','e','/','x','8','6','_','6','4','-','l','i','n',
        'u','x','-','a','n','d','r','o','i','d',' ','-','i','s','y','s',
        't','e','m',' ','/','o','p','t','/','a','n','d','r','o','i','d',
        '-','n','d','k','-','r','2','0','b','/','s','y','s','r','o','o',
        't','/','u','s','r','/','i','n','c','l','u','d','e',' ','-','D',
        'N','D','E','B','U','G',' ','-','D','_','_','A','N','D','R','O',
        'I','D','_','A','P','I','_','_','=','2','1','\0'
    };
#else
    #error "Unsupported arch"
#endif //__ARM_ARCH


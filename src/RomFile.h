
#include "profiles/MacPlus_Rom.h"
#include "profiles/MacII_Rom.h"

#ifdef MACII
#define ROMDATA MacII_ROM
#define ROMLEN  MacII_ROM_len
#else
#define ROMDATA MacPlus_ROM
#define ROMLEN  MacPlus_ROM_len
#endif

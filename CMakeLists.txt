cmake_minimum_required (VERSION 2.6)
project (MinivMac)

set ( BASE_SOURCES
	src/M68KCpuEmulator.c
	src/M68KInstructionTable.c
	src/GlobalGlue.c
	src/ViaEmulator.c
	src/IwmEmulator.c
	src/SccEmulator.c
	src/RtcEmulator.c
	src/RomEmulator.c
	src/ScsiEmulator.c
	src/SonyEmulator.c
	src/ScreenEmulator.c
	src/MouseEmulator.c
	src/KeyboardEmulator.c
	src/SoundEmulator.c
)

set ( X11_SOURCES
	src/platforms/X11.c
)

set ( MAIN_SOURCES
	src/ProgramMain.c
)

add_library (minivmac_base ${BASE_SOURCES})
add_library (minivmac_x11 ${X11_SOURCES})
target_link_libraries(minivmac_x11 X11)
target_link_libraries(minivmac_x11 dl)


add_executable(minivmac ${MAIN_SOURCES})
target_link_libraries(minivmac minivmac_base)
target_link_libraries(minivmac minivmac_x11)

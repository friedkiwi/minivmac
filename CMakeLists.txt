cmake_minimum_required (VERSION 3.0)

project (MinivMac)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -DMACII")

set ( BASE_SOURCES
	src/M68KCpuEmulator.c
	src/M68KInstructionTable.c
	src/GlobalGlue.c
	src/ViaEmulator.c
	src/Via2Emulator.c
	src/IwmEmulator.c
	src/SccEmulator.c
	src/RtcEmulator.c
	src/RomEmulator.c
	src/ScsiEmulator.c
	src/SonyEmulator.c
	src/ScreenEmulator.c
	src/MouseEmulator.c
	src/KeyboardEmulator.c
	src/AdbEmulator.c
	src/SoundEmulator.c
	src/AppleSoundEmulator.c
	src/VideoCardEmulator.c
)

set ( SDL_SOURCES
	src/platforms/SDL_WithRom.c
)

set ( MAIN_SOURCES
	src/ProgramMain.c
)

add_subdirectory(SDL2)


add_library (minivmac_base ${BASE_SOURCES})
add_library (minivmac_uisdl ${SDL_SOURCES})
target_link_libraries(minivmac_uisdl SDL2-static  )

add_executable(minivmac ${MAIN_SOURCES})
target_link_libraries(minivmac minivmac_base)
target_link_libraries(minivmac minivmac_uisdl)

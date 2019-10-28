cmake_minimum_required (VERSION 3.0)

project (MinivMac)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -DMACII")

if (WIN32)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DGUI_WINDOWS")
endif()

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

set ( WIN_SOURCES
	src/platforms/Windows_WithRom.c
)

set ( MAIN_SOURCES
	src/ProgramMain.c
)


add_library (minivmac_base ${BASE_SOURCES})
add_executable(minivmac ${MAIN_SOURCES})
target_link_libraries(minivmac minivmac_base)

if (WIN32)
	set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
	add_library (minivmac_uiwin ${WIN_SOURCES})
	target_link_libraries(minivmac minivmac_uiwin)
	target_link_libraries(minivmac winmm)
else()
	add_subdirectory(SDL2)
	add_library (minivmac_uisdl ${SDL_SOURCES})
	target_link_libraries(minivmac_uisdl SDL2-static)
	target_link_libraries(minivmac minivmac_uisdl)
endif()

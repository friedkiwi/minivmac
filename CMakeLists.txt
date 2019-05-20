cmake_minimum_required (VERSION 3.0)

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

set ( SDL_SOURCES
	src/platforms/SDL.c
)

set ( WINDOWS_SOURCES
	src/platforms/Windows.c
)


set ( MAIN_SOURCES
	src/ProgramMain.c
)

find_package(SDL)

add_library (minivmac_base ${BASE_SOURCES})

if(SDL_FOUND)
	set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -DOS_UNIX -DGUI_SDL -I${SDL_INCLUDE_DIR}")
	add_library(minivmac_uisdl ${SDL_SOURCES})
	target_link_libraries(minivmac_uisdl ${SDL_LIBRARY})
	message ("Building SDL version")
endif()


find_package(X11)

if(X11_FOUND)
	set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -DOS_UNIX -DGUI_X11")
	add_library (minivmac_uix11 ${X11_SOURCES})
	target_link_libraries(minivmac_uix11 X11)
	target_link_libraries(minivmac_uix11 dl)
endif()

if(WIN32)
	set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -DGUI_WINDOWS")
	add_library (minivmac_uiwindows ${WINDOWS_SOURCES})
endif()



if (X11_FOUND)
	add_executable(minivmac_x11 ${MAIN_SOURCES})
	target_link_libraries(minivmac_x11 minivmac_base)
	target_link_libraries(minivmac_x11 minivmac_uix11)
endif()

if (SDL_FOUND)
	add_executable(minivmac_sdl ${MAIN_SOURCES})
	target_link_libraries(minivmac_sdl minivmac_base)
	target_link_libraries(minivmac_sdl minivmac_uisdl) 
endif()

if (WIN32)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-subsystem,windows")
	add_executable(minivmac ${MAIN_SOURCES})
	target_link_libraries(minivmac minivmac_uiwindows)
	target_link_libraries(minivmac minivmac_base)
	target_link_libraries(minivmac winmm)
endif()

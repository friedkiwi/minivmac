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

set ( SDL2_SOURCES 
	src/platforms/SDL2.c
)

set ( MAIN_SOURCES
	src/ProgramMain.c
)

find_package(SDL)
find_package(SDL2)

add_library (minivmac_base ${BASE_SOURCES})

if(SDL_FOUND)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DGUI_SDL -I${SDL_INCLUDE_DIR}")
	add_library(minivmac_uisdl ${SDL_SOURCES})
	target_link_libraries(minivmac_uisdl ${SDL_LIBRARY})
endif()

add_library (minivmac_uix11 ${X11_SOURCES})

target_link_libraries(minivmac_uix11 X11)
target_link_libraries(minivmac_uix11 dl)




add_executable(minivmac ${MAIN_SOURCES})
target_link_libraries(minivmac minivmac_base)
target_link_libraries(minivmac minivmac_uix11)

if (${SDL_FOUND})
	add_executable(minivmac_sdl ${MAIN_SOURCES})
	target_link_libraries(minivmac_sdl minivmac_base)
	target_link_libraries(minivmac_sdl minivmac_uisdl) 
endif()

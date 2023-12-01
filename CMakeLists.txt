cmake_minimum_required(VERSION 3.26)
project(infa_proj_2023)

set(CMAKE_CXX_STANDARD 17)
set(GTK3_INCLUDE_DIRS "C:/msys64/mingw64/include/gtkmm-3.0")
set(GTK3_LIBRARY_DIRS "C:/msys64/mingw64/lib/gtkmm-3.0/include")
find_package(PkgConfig REQUIRED)
pkt_check_modules(GTK3 REQUIRED gtk+-3.0)
#set(PKG_CONFIG_EXECUTABLE "C:/path/to/pkg-config.exe")
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_definitions(${GTK_CFLAGS_OTHER})

target_link_libraries(infa_proj_2023 ${GTK3_LIBRARIES})

add_executable(infa_proj_2023 main.cpp
        Czytelnik.cpp
        Czytelnik.h
        Adres.cpp
        Adres.h
        RejestrCzytelnikow.cpp
        RejestrCzytelnikow.h
        main.cpp
        gui.cpp
        gui.h
        katalog.cpp
        katalog.h
        ksiazka.cpp
        ksiazka.h
        mainrej.cpp
        wypozyczanie.cpp
        wypozyczanie.h
)

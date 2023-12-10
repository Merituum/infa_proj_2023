cmake_minimum_required(VERSION 3.26)
project(infa_proj_2023)

set(CMAKE_CXX_STANDARD 17)

#sciezka z bibliotekami
#set(BIBLIOTEKI_DIR ${CMAKE_SOURCE_DIR/biblioteki})
#set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:./biblioteki/pkg-config-lite-0.28-1")

find_package(PkgConfig REQUIRED)
pkg_search_module(GTKMM REQUIRED gtkmm+-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
target_link_libraries(infa_proj_2023 ${GTKMM_LIBRARIES})



#pliki .cpp
set(SOURCES
        Adres.cpp
        Czytelnik.cpp
#        gui.cpp
        katalog.cpp
        ksiazka.cpp
        main.cpp
        mainrej.cpp
        RejestrCzytelnikow.cpp
        wypozyczanie.cpp
)

#pliki naglowkowe

set(HEADERS
        Adres.h
        Czytelnik.h
#        gui.h
        katalog.h
        ksiazka.h
        RejestrCzytelnikow.h
        wypozyczanie.h
)

#pliki wykonywawcze
add_executable(infa_proj_2023 ${SOURCES} ${HEADERS})
target_link_libraries(infa_proj_2023 ${GTK3_LIBRARIES})
#ustawienia sciezek include - nie wiem czy to potrzebne
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK_3_LIBRARY_DIRS})
#add_executable(infa_proj_2023 main.cpp
#        Czytelnik.cpp
#        Czytelnik.h
#        Adres.cpp
#        Adres.h
#        RejestrCzytelnikow.cpp
#        RejestrCzytelnikow.h
#        main.cpp
#        gui.cpp
#        gui.h
#        katalog.cpp
#        katalog.h
#        ksiazka.cpp
#        ksiazka.h
#        mainrej.cpp
#        wypozyczanie.cpp
#        wypozyczanie.h
#)

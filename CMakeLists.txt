cmake_minimum_required(VERSION 3.12)
project(infa_proj_2023)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /bin)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
# Dodaj pliki źródłowe dołączane do kompilacji

include(FetchContent)
        #GIT_REPOSITORY https://github.com/SFML/SFML.git
        #GIT_TAG 2.6.x)
        #FetchContent_MakeAvailable(SFML)
set(SOURCE_FILES
        main.cpp
        katalog.cpp
        ksiazka.cpp
        RejestrCzytelnikow.cpp
        Adres.cpp
        wypozyczanie.cpp
        Czytelnik.cpp
        gui.cpp
)

# Dodaj pliki nagłówkowe
set(HEADER_FILES
        katalog.h
        ksiazka.h
        RejestrCzytelnikow.h
        Adres.h
        wypozyczanie.h
        Czytelnik.h
        gui.h

)

#target_link_libraries(Fajnanse PRIVATE sfml-graphics ImGui-SFML::ImGui-SFML)
add_executable(Infa_proj_2023 ${SOURCE_FILES} ${HEADER_FILES})
install(TARGETS Infa_proj_2023 DESTINATION bin)

# Jeśli korzystasz z CMake w wersji 3.19 lub nowszej, możesz użyć poniższej komendy
# target_precompile_headers(NazwaTwojegoProgramu PRIVATE ${HEADER_FILES})

# Dodaj dodatkowe flagi kompilacji, biblioteki itp., jeśli są potrzebne

# Przykład dodania flagi dla kompilacji w trybie debug
# target_compile_options(NazwaTwojegoProgramu PRIVATE -g)

# Przykład dodania zewnętrznej biblioteki (np. Boost)
# find_package(Boost REQUIRED)
# target_include_directories(NazwaTwojegoProgramu PRIVATE ${Boost_INCLUDE_DIRS})
# target_link_libraries(NazwaTwojegoProgramu PRIVATE ${Boost_LIBRARIES})

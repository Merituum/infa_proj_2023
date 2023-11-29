cmake_minimum_required(VERSION 3.26)
project(Rejstracjaczytelnikow)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rejstracjaczytelnikow main.cpp
        Czytelnik.cpp
        Czytelnik.h
        Adres.cpp
        Adres.h
        RejestrCzytelnikow.cpp
        RejestrCzytelnikow.h
        main.cpp
)

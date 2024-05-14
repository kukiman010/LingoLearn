cmake_minimum_required(VERSION 3.10)

project(opensslTest)

# Определим стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найдем Qt5 и Qt6 библиотеки.
# По идее, эти пути должны быть указаны пользователем системы или в CMakeLists.txt.

find_package(Qt5 COMPONENTS Network REQUIRED)

# Попробуем найти Qt6, если она установлена.
find_package(Qt6 COMPONENTS Network QUIET)

# Указание исходных и заголовочных файлов
set(SOURCES
    main.cpp
    sslworker.cpp
)

set(HEADERS
    sslworker.h
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Добавление глобальных настроек компилятора
target_compile_definitions(${PROJECT_NAME} PRIVATE QT_DEPRECATED_WARNINGS)

# Указание зависимости от Qt библиотек
if (Qt5_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Network)
elseif (Qt6_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Network)
endif()

# Настройка для платформы Windows
if(WIN32)
    include_directories("C:/Program Files/OpenSSL/include")
    link_directories("C:/Program Files/OpenSSL/lib")
    target_link_libraries(${PROJECT_NAME} PRIVATE ssl crypto)
elseif(UNIX)
    include_directories("/home/sysadm/qt_project/openssl/include/openssl")
    link_directories("/home/sysadm/qt_project/openssl/lib64")
    target_link_libraries(${PROJECT_NAME} PRIVATE ssl crypto dl pthread)
endif()

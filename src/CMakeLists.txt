cmake_minimum_required(VERSION 3.10)

set(EXE_NAME calculator_executable)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.h")


add_executable(${EXE_NAME} 
    ${SOURCES}
    ${HEADERS})



target_link_libraries(${EXE_NAME} PUBLIC  project_options)

target_link_libraries(${EXE_NAME}
    PRIVATE
        Qt::Core
        Qt::Widgets
)



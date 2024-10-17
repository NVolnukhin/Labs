QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        circle.cpp \
        command_add_figure.cpp \
        command_delete_by_number.cpp \
        command_delete_by_perimeter.cpp \
        command_exit.cpp \
        command_input_manager.cpp \
        command_output_params.cpp \
        command_output_perimeters.cpp \
        command_output_summary_perimeter.cpp \
        command_sort_by_perimeter.cpp \
        facade.cpp \
        figures.cpp \
        figures_composite.cpp \
        figures_factory.cpp \
        float_input_manager.cpp \
        integer_input_manager.cpp \
        main.cpp \
        points.cpp \
        polygon.cpp \
        rectangle.cpp \
        triangle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstract_figures_factory.h \
    circle.h \
    command_add_figure.h \
    command_delete_by_number.h \
    command_delete_by_perimeter.h \
    command_exit.h \
    command_input_manager.h \
    command_output_params.h \
    command_output_perimeters.h \
    command_output_summary_perimeter.h \
    command_sort_by_perimeter.h \
    commands.h \
    facade.h \
    figures.h \
    figures_composite.h \
    figures_factory.h \
    float_input_manager.h \
    integer_input_manager.h \
    points.h \
    polygon.h \
    rectangle.h \
    triangle.h

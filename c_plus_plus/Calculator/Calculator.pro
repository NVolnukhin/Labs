QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator_result.cpp \
    evaluator.cpp \
    function.cpp \
    function_cos.cpp \
    function_ctg.cpp \
    function_sin.cpp \
    function_sqrt.cpp \
    function_tg.cpp \
    main.cpp \
    mainwindow.cpp \
    operator.cpp \
    operator_division.cpp \
    operator_minus.cpp \
    operator_multiplication.cpp \
    operator_plus.cpp \
    operator_pow.cpp \
    simple_calculator.cpp \
    token.cpp \
    tokenizer.cpp

HEADERS += \
    base_calculator.h \
    calculator_result.h \
    command.h \
    command_calculate.h \
    command_factory.h \
    evaluator.h \
    facade.h \
    function.h \
    function_cos.h \
    function_ctg.h \
    function_sin.h \
    function_sqrt.h \
    function_tg.h \
    mainwindow.h \
    operator.h \
    operator_division.h \
    operator_minus.h \
    operator_multiplication.h \
    operator_plus.h \
    operator_pow.h \
    property.h \
    simple_calculator.h \
    token.h \
    tokenizer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

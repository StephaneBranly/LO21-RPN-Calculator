QT += widgets

SOURCES += \
    main.cpp \
    src/connector/connector.cpp \
    src/interface/mainwindow.cpp \
    src/interface/widgets/commandline/commandline.cpp \
    src/interface/widgets/keyboard/keyboard.cpp \
    src/interface/widgets/pile/pile.cpp \
    src/interface/widgets/programmes/programmes.cpp \
    src/interface/widgets/variables/variables.cpp \
    src/observer/observer.cpp \
    src/observer/subject.cpp

FORMS += \
    src/interface/mainwindow.ui \
    src/interface/widgets/commandline/commandline.ui \
    src/interface/widgets/keyboard/keyboard.ui \
    src/interface/widgets/pile/pile.ui \
    src/interface/widgets/programmes/programmes.ui \
    src/interface/widgets/variables/variables.ui \

HEADERS += \
    src/connector/connector.h \
    src/interface/mainwindow.h \
    src/interface/widgets/commandline/commandline.h \
    src/interface/widgets/keyboard/keyboard.h \
    src/interface/widgets/pile/pile.h \
    src/interface/widgets/programmes/programmes.h \
    src/interface/widgets/variables/variables.h \
    src/engine/pile/pile.h \
    src/engine/pile/item.h \
    src/engine/pile/pile.h \
    src/observer/observer.h \
    src/observer/subject.h

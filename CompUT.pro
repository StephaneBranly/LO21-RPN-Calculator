QT += widgets

SOURCES += \
    main.cpp \
    src/interface/mainwindow.cpp \
    src/interface/widgets/commandline/commandline.cpp \
    src/interface/widgets/keyboard/keyboard.cpp \
    src/interface/widgets/pile/pile.cpp \
    src/interface/widgets/varsprogs/varsprogs.cpp

FORMS += \
    src/interface/MainWindow.ui \
    src/interface/widgets/commandline/commandline.ui \
    src/interface/widgets/keyboard/Keyboard.ui \
    src/interface/widgets/pile/pile.ui \
    src/interface/widgets/varsprogs/varsprogs.ui

HEADERS += \
    src/interface/mainwindow.h \
    src/interface/widgets/commandline/commandline.h \
    src/interface/widgets/keyboard/keyboard.h \
    src/interface/widgets/pile/pile.h \
    src/interface/widgets/varsprogs/varsprogs.h

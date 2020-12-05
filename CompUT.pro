QT += widgets

SOURCES += \
    main.cpp \
    src/connector/connector.cpp \
    src/engine/pile/expression.cpp \
    src/engine/pile/expressionmanager.cpp \
    src/interface/mainwindow.cpp \
    src/interface/widgets/commandline/commandline.cpp \
    src/interface/widgets/keyboardfunctions/keyboardfunctions.cpp \
    src/interface/widgets/keyboardnumeric/keyboardnumeric.cpp \
    src/interface/widgets/pile/pile.cpp \
    src/interface/widgets/programmes/programmes.cpp \
    src/interface/widgets/variables/variables.cpp \
    src/litteral/lentiere.cpp \
    src/litteral/litteral.cpp \
    src/litteral/lnumerique.cpp \
    src/litteral/lrationelle.cpp \
    src/litteral/lreelle.cpp \
    src/observer/observer.cpp \
    src/observer/subject.cpp

FORMS += \
    src/interface/mainwindow.ui \
    src/interface/widgets/commandline/commandline.ui \
    src/interface/widgets/keyboardfunctions/keyboardfunctions.ui \
    src/interface/widgets/keyboardnumeric/keyboardnumeric.ui \
    src/interface/widgets/pile/pile.ui \
    src/interface/widgets/programmes/programmes.ui \
    src/interface/widgets/variables/variables.ui \

HEADERS += \
    src/connector/connector.h \
    src/engine/pile/CompException.h \
    src/engine/pile/expression.h \
    src/engine/pile/expressionmanager.h \
    src/interface/mainwindow.h \
    src/interface/widgets/commandline/commandline.h \
    src/interface/widgets/keyboardfunctions/keyboardfunctions.h \
    src/interface/widgets/keyboardnumeric/keyboardnumeric.h \
    src/interface/widgets/pile/pile.h \
    src/interface/widgets/programmes/programmes.h \
    src/interface/widgets/variables/variables.h \
    src/engine/pile/pile.h \
    src/engine/pile/item.h \
    src/engine/pile/pile.h \
    src/litteral/lentiere.h \
    src/litteral/litteral.h \
    src/litteral/lnumerique.h \
    src/litteral/lrationelle.h \
    src/litteral/lreelle.h \
    src/observer/observer.h \
    src/observer/subject.h

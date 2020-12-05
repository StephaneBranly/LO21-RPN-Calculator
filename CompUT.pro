QT += widgets

SOURCES += \
    main.cpp \
    src/connector/connector.cpp \
    src/engine/computerengine.cpp \
    src/engine/expression/expression.cpp \
    src/engine/expression/expressionmanager.cpp \
    src/engine/expression/litterales/lentiere.cpp \
    src/engine/expression/litterales/lnumerique.cpp \
    src/engine/expression/litterales/lrationnelle.cpp \
    src/engine/expression/litterales/lreelle.cpp \
    src/engine/stack/stack.cpp \
    src/interface/mainwindow.cpp \
    src/interface/widgets/commandline/commandline.cpp \
    src/interface/widgets/keyboardfunctions/keyboardfunctions.cpp \
    src/interface/widgets/keyboardnumeric/keyboardnumeric.cpp \
    src/interface/widgets/pile/pile.cpp \
    src/interface/widgets/programmes/programmes.cpp \
    src/interface/widgets/variables/variables.cpp \
    src/observer/observer.cpp \
    src/observer/subject.cpp \

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
    src/engine/computerengine.h \
    src/engine/expression/litterales/lentiere.h \
    src/engine/expression/litterales/lnumerique.h \
    src/engine/expression/litterales/lrationnelle.h \
    src/engine/expression/litterales/lreelle.h \
    src/engine/operator/operator.h \
    src/engine/exception/CompException.h \
    src/engine/expression/expression.h \
    src/engine/expression/expressionmanager.h \
    src/engine/stack/stack.h \
    src/interface/mainwindow.h \
    src/interface/widgets/commandline/commandline.h \
    src/interface/widgets/keyboardfunctions/keyboardfunctions.h \
    src/interface/widgets/keyboardnumeric/keyboardnumeric.h \
    src/interface/widgets/pile/pile.h \
    src/interface/widgets/programmes/programmes.h \
    src/interface/widgets/variables/variables.h \
    src/observer/observer.h \
    src/observer/subject.h

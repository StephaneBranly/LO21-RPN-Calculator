QT += widgets

SOURCES += \
    main.cpp \
    src/connector/connector.cpp \
    src/engine/computerengine.cpp \
    src/engine/expression/atommanager.cpp \
    src/engine/expression/expression.cpp \
    src/engine/expression/expressionabstractfactory.cpp \
    src/engine/expression/expressionfactory.cpp \
    src/engine/expression/expressionmanager.cpp \
    src/engine/expression/litterales/latom.cpp \
    src/engine/expression/litterales/latomfactory.cpp \
    src/engine/expression/litterales/lexpression.cpp \
    src/engine/expression/litterales/lexpressionfactory.cpp \
    src/engine/expression/litterales/linteger.cpp \
    src/engine/expression/litterales/lintegerfactory.cpp \
    src/engine/expression/litterales/lnumerical.cpp \
    src/engine/expression/litterales/lprogram.cpp \
    src/engine/expression/litterales/lrational.cpp \
    src/engine/expression/litterales/lreal.cpp \
    src/engine/expression/litterales/lrealfactory.cpp \
    src/engine/expression/operator/operator.cpp \
    src/engine/expression/operator/operatorarithmetic.cpp \
    src/engine/expression/operator/operatorfactory.cpp \
    src/engine/expression/operator/operatorsdefinition.cpp \
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
    src/engine/expression/atommanager.h \
    src/engine/expression/expressionabstractfactory.h \
    src/engine/expression/expressionfactory.h \
    src/engine/expression/litterales/latom.h \
    src/engine/expression/litterales/latomfactory.h \
    src/engine/expression/litterales/lexpression.h \
    src/engine/expression/litterales/lexpressionfactory.h \
    src/engine/expression/litterales/linteger.h \
    src/engine/expression/litterales/lintegerfactory.h \
    src/engine/expression/litterales/lnumerical.h \
    src/engine/expression/litterales/lprogram.h \
    src/engine/expression/litterales/lrational.h \
    src/engine/expression/litterales/lreal.h \
    src/engine/expression/litterales/lrealfactory.h \
    src/engine/expression/operator/operator.h \
    src/engine/exception/CompException.h \
    src/engine/expression/expression.h \
    src/engine/expression/expressionmanager.h \
    src/engine/expression/operator/operatorarithmetic.h \
    src/engine/expression/operator/operatorfactory.h \
    src/engine/expression/operator/operatorsdefinition.h \
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

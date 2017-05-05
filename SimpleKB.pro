#
# ReplacementSolution Virtual Keyboard
#
QT += qml quick gui gui-private core-private

#
# Common files
#
HEADERS += \
    simplekbplugin.h \
    simplekbinputcontext.h

SOURCES += \
    simplekbplugin.cpp \
    simplekbinputcontext.cpp \
    main.cpp

CONFIG += pluginmode
#
# Build as a Plugin
#
pluginmode:{
    TEMPLATE = lib
    TARGET  = simplekb
    INSTALL_PATH = $$[QT_INSTALL_PLUGINS]/platforminputcontexts
    target.path = $$INSTALL_PATH
    INSTALLS += target
    CONFIG += plugin
    CONFIG += link_pkgconfig
    OTHER_FILES += SimpleKB.json
}
!pluginmode:{
    TEMPLATE = app
    SOURCES += main.cpp
}

RESOURCES += \
    qml.qrc


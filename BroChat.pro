QT += core network xml widgets webkitwidgets websockets svg

CONFIG += c++11

Debug:TARGET = $$join(TARGET,,,d)
DESTDIR = ../bin

include(external/qxmpp-master/qxmpp.pri)

LIBS += -L../bin $${QXMPP_LIBS}
INCLUDEPATH += $${QXMPP_INCLUDEPATH}

INCLUDEPATH += src/providers src/

HEADERS += \
    src/qchatservice.h \
    src/qchatmessage.h \
    src/qsettingsdialog.h \
    src/qchatsmile.h \
    src/settingsconsts.h \
    src/qchatupdateserver.h \
    src/qchatstatistic.h \
    src/qbrochatview.h \
    src/providers/qtwitchchat.h \
    src/providers/qsc2tvchat.h \
    src/providers/qgoodgamechat.h \
    src/providers/qcybergamechat.h \
    src/providers/qaceschat.h \
    src/providers/qgamerstvchat.h \
    src/providers/qfunstreamchat.h \
    src/providers/qstreamboxchat.h \
    src/providers/qhitboxchat.h \
    src/providers/qgipsyteamchat.h \
    src/providers/qrealltvchat.h \
    src/providers/qyoutubechat.h \
    src/providers/qlivecodingchat.h \
    src/coremediator.h

SOURCES += \
    src/main.cpp \
    src/qchatservice.cpp \
    src/qchatmessage.cpp \
    src/qsettingsdialog.cpp \
    src/qchatsmile.cpp \
    src/qchatupdateserver.cpp \
    src/qchatstatistic.cpp \
    src/qbrochatview.cpp \
    src/providers/qtwitchchat.cpp \
    src/providers/qsc2tvchat.cpp \
    src/providers/qgoodgamechat.cpp \
    src/providers/qcybergamechat.cpp \
    src/providers/qaceschat.cpp \
    src/providers/qgamerstvchat.cpp \
    src/providers/qfunstreamchat.cpp \
    src/providers/qstreamboxchat.cpp \
    src/providers/qhitboxchat.cpp \
    src/providers/qgipsyteamchat.cpp \
    src/providers/qrealltvchat.cpp \
    src/providers/qyoutubechat.cpp \
    src/providers/qlivecodingchat.cpp \
    src/coremediator.cpp

RESOURCES += \
    resources/resources.rc

win32:RC_FILE = resources/ico.rc

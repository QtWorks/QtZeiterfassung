TEMPLATE = subdirs

SUBDIRS += plugins \
           zeiterfassung \
           zeiterfassungcorelib \
           zeiterfassungguilib

plugins.depends += zeiterfassungcorelib zeiterfassungguilib
zeiterfassung.depends += zeiterfassungcorelib zeiterfassungguilib
zeiterfassungguilib.depends += zeiterfassungcorelib

include(installs.pri)
win32: include(installs_win32.pri)

OTHER_FILES += .dockerignore \
               .travis.yml \
               Dockerfile

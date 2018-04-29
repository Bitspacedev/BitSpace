set PATH=%PATH%;C:\devel\qt5.9.2-static\bin
cd %cd%
qmake "USE_UPNP=1" "USE_IPV6=1" bitspace-qt.pro
make -j3 -f Makefile.Release
pause
build_qt_static.bat
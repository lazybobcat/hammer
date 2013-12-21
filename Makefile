#############################################################################
# Makefile for building: hammer
# Generated by qmake (3.0) (Qt 5.0.2) on: ven. d�c. 20 20:49:05 2013
# Project:  hammer.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -spec linux-g++-64 -o Makefile hammer.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -m64 -pipe -O2 -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -O2 -Wall -W -fPIE $(DEFINES)
INCPATH       = -I/usr/share/qt5/mkspecs/linux-g++-64 -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS) -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -llua -ldl 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = .obj/

####### Files

SOURCES       = main.cpp \
		controllers/playercontroller.cpp \
		entities/textnode.cpp \
		entities/spritenode.cpp \
		entities/soundnode.cpp \
		entities/scenenode.cpp \
		entities/quadtree.cpp \
		entities/particlenode.cpp \
		entities/entity.cpp \
		entities/emitternode.cpp \
		events/commandqueue.cpp \
		events/command.cpp \
		GUI/widget.cpp \
		GUI/lineedit.cpp \
		GUI/label.cpp \
		GUI/container.cpp \
		GUI/button.cpp \
		lua/SLB.cpp \
		lua/luaexposal.cpp \
		resources/soundplayer.cpp \
		resources/scriptplayer.cpp \
		resources/particle.cpp \
		resources/musicplayer.cpp \
		resources/animation.cpp \
		resources/affectors.cpp \
		states/titlestate.cpp \
		states/statestack.cpp \
		states/state.cpp \
		states/paralleltask.cpp \
		world.cpp \
		utils.cpp \
		datatables.cpp \
		application.cpp \
		entities/playerentity.cpp \
		states/gamestate.cpp \
		entities/creature.cpp \
		controllers/aicontroller.cpp \
		entities/uihealthpoints.cpp \
		wave.cpp \
		entities/combattextnode.cpp \
		states/pausestate.cpp \
		entities/cameranode.cpp \
		entities/boss.cpp \
		controllers/bosscontroller.cpp \
		states/gameoverstate.cpp \
		states/introstate.cpp \
		entities/object.cpp 
OBJECTS       = .obj/main.o \
		.obj/playercontroller.o \
		.obj/textnode.o \
		.obj/spritenode.o \
		.obj/soundnode.o \
		.obj/scenenode.o \
		.obj/quadtree.o \
		.obj/particlenode.o \
		.obj/entity.o \
		.obj/emitternode.o \
		.obj/commandqueue.o \
		.obj/command.o \
		.obj/widget.o \
		.obj/lineedit.o \
		.obj/label.o \
		.obj/container.o \
		.obj/button.o \
		.obj/SLB.o \
		.obj/luaexposal.o \
		.obj/soundplayer.o \
		.obj/scriptplayer.o \
		.obj/particle.o \
		.obj/musicplayer.o \
		.obj/animation.o \
		.obj/affectors.o \
		.obj/titlestate.o \
		.obj/statestack.o \
		.obj/state.o \
		.obj/paralleltask.o \
		.obj/world.o \
		.obj/utils.o \
		.obj/datatables.o \
		.obj/application.o \
		.obj/playerentity.o \
		.obj/gamestate.o \
		.obj/creature.o \
		.obj/aicontroller.o \
		.obj/uihealthpoints.o \
		.obj/wave.o \
		.obj/combattextnode.o \
		.obj/pausestate.o \
		.obj/cameranode.o \
		.obj/boss.o \
		.obj/bosscontroller.o \
		.obj/gameoverstate.o \
		.obj/introstate.o \
		.obj/object.o
DIST          = /usr/share/qt5/mkspecs/features/spec_pre.prf \
		/usr/share/qt5/mkspecs/common/shell-unix.conf \
		/usr/share/qt5/mkspecs/common/unix.conf \
		/usr/share/qt5/mkspecs/common/linux.conf \
		/usr/share/qt5/mkspecs/common/gcc-base.conf \
		/usr/share/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt5/mkspecs/common/g++-base.conf \
		/usr/share/qt5/mkspecs/common/g++-unix.conf \
		/usr/share/qt5/mkspecs/qconfig.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_bootstrap.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_platformsupport.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qmldevtools.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_quickparticles.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/share/qt5/mkspecs/features/qt_functions.prf \
		/usr/share/qt5/mkspecs/features/qt_config.prf \
		/usr/share/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/share/qt5/mkspecs/features/spec_post.prf \
		/usr/share/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt5/mkspecs/features/default_pre.prf \
		/usr/share/qt5/mkspecs/features/unix/default_pre.prf \
		/usr/share/qt5/mkspecs/features/resolve_config.prf \
		/usr/share/qt5/mkspecs/features/default_post.prf \
		/usr/share/qt5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt5/mkspecs/features/warn_on.prf \
		/usr/share/qt5/mkspecs/features/wayland-scanner.prf \
		/usr/share/qt5/mkspecs/features/testcase_targets.prf \
		/usr/share/qt5/mkspecs/features/exceptions.prf \
		/usr/share/qt5/mkspecs/features/yacc.prf \
		/usr/share/qt5/mkspecs/features/lex.prf \
		hammer.pro \
		hammer.pro
QMAKE_TARGET  = hammer
DESTDIR       = 
TARGET        = hammer


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: hammer.pro /usr/share/qt5/mkspecs/linux-g++-64/qmake.conf /usr/share/qt5/mkspecs/features/spec_pre.prf \
		/usr/share/qt5/mkspecs/common/shell-unix.conf \
		/usr/share/qt5/mkspecs/common/unix.conf \
		/usr/share/qt5/mkspecs/common/linux.conf \
		/usr/share/qt5/mkspecs/common/gcc-base.conf \
		/usr/share/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt5/mkspecs/common/g++-base.conf \
		/usr/share/qt5/mkspecs/common/g++-unix.conf \
		/usr/share/qt5/mkspecs/qconfig.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_bootstrap.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_platformsupport.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qmldevtools.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_quickparticles.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/share/qt5/mkspecs/features/qt_functions.prf \
		/usr/share/qt5/mkspecs/features/qt_config.prf \
		/usr/share/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/share/qt5/mkspecs/features/spec_post.prf \
		/usr/share/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt5/mkspecs/features/default_pre.prf \
		/usr/share/qt5/mkspecs/features/unix/default_pre.prf \
		/usr/share/qt5/mkspecs/features/resolve_config.prf \
		/usr/share/qt5/mkspecs/features/default_post.prf \
		/usr/share/qt5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt5/mkspecs/features/warn_on.prf \
		/usr/share/qt5/mkspecs/features/wayland-scanner.prf \
		/usr/share/qt5/mkspecs/features/testcase_targets.prf \
		/usr/share/qt5/mkspecs/features/exceptions.prf \
		/usr/share/qt5/mkspecs/features/yacc.prf \
		/usr/share/qt5/mkspecs/features/lex.prf \
		hammer.pro
	$(QMAKE) -spec linux-g++-64 -o Makefile hammer.pro
/usr/share/qt5/mkspecs/features/spec_pre.prf:
/usr/share/qt5/mkspecs/common/shell-unix.conf:
/usr/share/qt5/mkspecs/common/unix.conf:
/usr/share/qt5/mkspecs/common/linux.conf:
/usr/share/qt5/mkspecs/common/gcc-base.conf:
/usr/share/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt5/mkspecs/common/g++-base.conf:
/usr/share/qt5/mkspecs/common/g++-unix.conf:
/usr/share/qt5/mkspecs/qconfig.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_bootstrap.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_platformsupport.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_qmldevtools.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_quickparticles.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/share/qt5/mkspecs/features/qt_functions.prf:
/usr/share/qt5/mkspecs/features/qt_config.prf:
/usr/share/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/share/qt5/mkspecs/features/spec_post.prf:
/usr/share/qt5/mkspecs/features/exclusive_builds.prf:
/usr/share/qt5/mkspecs/features/default_pre.prf:
/usr/share/qt5/mkspecs/features/unix/default_pre.prf:
/usr/share/qt5/mkspecs/features/resolve_config.prf:
/usr/share/qt5/mkspecs/features/default_post.prf:
/usr/share/qt5/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt5/mkspecs/features/warn_on.prf:
/usr/share/qt5/mkspecs/features/wayland-scanner.prf:
/usr/share/qt5/mkspecs/features/testcase_targets.prf:
/usr/share/qt5/mkspecs/features/exceptions.prf:
/usr/share/qt5/mkspecs/features/yacc.prf:
/usr/share/qt5/mkspecs/features/lex.prf:
hammer.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++-64 -o Makefile hammer.pro

qmake_all: FORCE

dist: 
	@test -d .obj/hammer1.0.0 || mkdir -p .obj/hammer1.0.0
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .obj/hammer1.0.0/ && (cd `dirname .obj/hammer1.0.0` && $(TAR) hammer1.0.0.tar hammer1.0.0 && $(COMPRESS) hammer1.0.0.tar) && $(MOVE) `dirname .obj/hammer1.0.0`/hammer1.0.0.tar.gz . && $(DEL_FILE) -r .obj/hammer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_wayland-server-header_make_all:
compiler_wayland-server-header_clean:
compiler_wayland-client-header_make_all:
compiler_wayland-client-header_clean:
compiler_wayland-code_make_all:
compiler_wayland-code_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

.obj/main.o: main.cpp application.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		controllers/playercontroller.h \
		events/command.h \
		events/category.h \
		states/statestack.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		lua/luaexposal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o main.cpp

.obj/playercontroller.o: controllers/playercontroller.cpp controllers/playercontroller.h \
		events/command.h \
		events/category.h \
		events/commandqueue.h \
		entities/playerentity.h \
		entities/entity.h \
		entities/scenenode.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/playercontroller.o controllers/playercontroller.cpp

.obj/textnode.o: entities/textnode.cpp entities/textnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		utils.h \
		resources/animation.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/textnode.o entities/textnode.cpp

.obj/spritenode.o: entities/spritenode.cpp entities/spritenode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/spritenode.o entities/spritenode.cpp

.obj/soundnode.o: entities/soundnode.cpp entities/soundnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/soundnode.o entities/soundnode.cpp

.obj/scenenode.o: entities/scenenode.cpp entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		utils.h \
		resources/animation.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/scenenode.o entities/scenenode.cpp

.obj/quadtree.o: entities/quadtree.cpp entities/quadtree.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/quadtree.o entities/quadtree.cpp

.obj/particlenode.o: entities/particlenode.cpp entities/particlenode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/particle.h \
		resources/affectors.h \
		datatables.h \
		entities/boss.h \
		entities/creature.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/animation.h \
		entities/emitternode.h \
		entities/combattextnode.h \
		utils.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/particlenode.o entities/particlenode.cpp

.obj/entity.o: entities/entity.cpp entities/entity.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h \
		datatables.h \
		entities/boss.h \
		entities/creature.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/entity.o entities/entity.cpp

.obj/emitternode.o: entities/emitternode.cpp entities/emitternode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		resources/particle.h \
		entities/particlenode.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/affectors.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/emitternode.o entities/emitternode.cpp

.obj/commandqueue.o: events/commandqueue.cpp events/commandqueue.h \
		events/command.h \
		events/category.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/commandqueue.o events/commandqueue.cpp

.obj/command.o: events/command.cpp events/command.h \
		events/category.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/command.o events/command.cpp

.obj/widget.o: GUI/widget.cpp GUI/widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/widget.o GUI/widget.cpp

.obj/lineedit.o: GUI/lineedit.cpp GUI/lineedit.h \
		GUI/widget.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/lineedit.o GUI/lineedit.cpp

.obj/label.o: GUI/label.cpp GUI/label.h \
		GUI/widget.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/label.o GUI/label.cpp

.obj/container.o: GUI/container.cpp GUI/container.h \
		GUI/widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/container.o GUI/container.cpp

.obj/button.o: GUI/button.cpp GUI/button.h \
		GUI/widget.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		utils.h \
		resources/animation.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/button.o GUI/button.cpp

.obj/SLB.o: lua/SLB.cpp lua/SLB.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/SLB.o lua/SLB.cpp

.obj/luaexposal.o: lua/luaexposal.cpp lua/luaexposal.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		resources/resourceidentifiers.h \
		entities/creature.h \
		entities/entity.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/animation.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		world.h \
		entities/textnode.h \
		resources/musicplayer.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/luaexposal.o lua/luaexposal.cpp

.obj/soundplayer.o: resources/soundplayer.cpp resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/soundplayer.o resources/soundplayer.cpp

.obj/scriptplayer.o: resources/scriptplayer.cpp resources/scriptplayer.h \
		lua/SLB.hpp \
		resources/resourceidentifiers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/scriptplayer.o resources/scriptplayer.cpp

.obj/particle.o: resources/particle.cpp resources/particle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/particle.o resources/particle.cpp

.obj/musicplayer.o: resources/musicplayer.cpp resources/musicplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/musicplayer.o resources/musicplayer.cpp

.obj/animation.o: resources/animation.cpp resources/animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/animation.o resources/animation.cpp

.obj/affectors.o: resources/affectors.cpp resources/affectors.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/affectors.o resources/affectors.cpp

.obj/titlestate.o: states/titlestate.cpp states/titlestate.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		utils.h \
		resources/animation.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/titlestate.o states/titlestate.cpp

.obj/statestack.o: states/statestack.cpp states/statestack.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/statestack.o states/statestack.cpp

.obj/state.o: states/state.cpp states/state.h \
		states/stateidentifiers.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		states/statestack.h \
		controllers/playercontroller.h \
		events/command.h \
		events/category.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/state.o states/state.cpp

.obj/paralleltask.o: states/paralleltask.cpp states/paralleltask.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/paralleltask.o states/paralleltask.cpp

.obj/world.o: world.cpp world.h \
		entities/textnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		resources/musicplayer.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/animation.h \
		entities/creature.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h \
		utils.h \
		utils.inl \
		entities/boss.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/world.o world.cpp

.obj/utils.o: utils.cpp utils.h \
		resources/animation.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/utils.o utils.cpp

.obj/datatables.o: datatables.cpp datatables.h \
		resources/resourceidentifiers.h \
		entities/boss.h \
		entities/creature.h \
		entities/entity.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/animation.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		world.h \
		entities/textnode.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		resources/musicplayer.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/datatables.o datatables.cpp

.obj/application.o: application.cpp application.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		controllers/playercontroller.h \
		events/command.h \
		events/category.h \
		states/statestack.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		lua/luaexposal.h \
		utils.h \
		resources/animation.h \
		utils.inl \
		states/titlestate.h \
		states/gamestate.h \
		world.h \
		entities/textnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/entity.h \
		entities/soundnode.h \
		entities/creature.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h \
		states/pausestate.h \
		states/gameoverstate.h \
		states/introstate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/application.o application.cpp

.obj/playerentity.o: entities/playerentity.cpp entities/playerentity.h \
		entities/entity.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h \
		entities/cameranode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/playerentity.o entities/playerentity.cpp

.obj/gamestate.o: states/gamestate.cpp states/gamestate.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		world.h \
		entities/textnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/animation.h \
		entities/creature.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gamestate.o states/gamestate.cpp

.obj/creature.o: entities/creature.cpp entities/creature.h \
		entities/entity.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		controllers/aicontroller.h \
		utils.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/creature.o entities/creature.cpp

.obj/aicontroller.o: controllers/aicontroller.cpp controllers/aicontroller.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/creature.h \
		entities/entity.h \
		entities/scenenode.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/aicontroller.o controllers/aicontroller.cpp

.obj/uihealthpoints.o: entities/uihealthpoints.cpp entities/uihealthpoints.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/uihealthpoints.o entities/uihealthpoints.cpp

.obj/wave.o: wave.cpp wave.h \
		entities/creature.h \
		entities/entity.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		world.h \
		entities/textnode.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		resources/musicplayer.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		utils.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/wave.o wave.cpp

.obj/combattextnode.o: entities/combattextnode.cpp entities/combattextnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		utils.h \
		resources/animation.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/combattextnode.o entities/combattextnode.cpp

.obj/pausestate.o: states/pausestate.cpp states/pausestate.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		world.h \
		entities/textnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/animation.h \
		entities/creature.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h \
		utils.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/pausestate.o states/pausestate.cpp

.obj/cameranode.o: entities/cameranode.cpp entities/cameranode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		utils.h \
		resources/animation.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/cameranode.o entities/cameranode.cpp

.obj/boss.o: entities/boss.cpp entities/boss.h \
		entities/creature.h \
		entities/entity.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		world.h \
		entities/textnode.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		resources/musicplayer.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h \
		datatables.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/boss.o entities/boss.cpp

.obj/bosscontroller.o: controllers/bosscontroller.cpp controllers/bosscontroller.h \
		controllers/aicontroller.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/bosscontroller.o controllers/bosscontroller.cpp

.obj/gameoverstate.o: states/gameoverstate.cpp states/gameoverstate.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		world.h \
		entities/textnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/animation.h \
		entities/creature.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h \
		utils.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gameoverstate.o states/gameoverstate.cpp

.obj/introstate.o: states/introstate.cpp states/introstate.h \
		states/state.h \
		states/stateidentifiers.h \
		resources/resourceidentifiers.h \
		resources/resourceholder.h \
		resources/musicplayer.h \
		resources/soundplayer.h \
		resources/scriptplayer.h \
		lua/SLB.hpp \
		world.h \
		entities/textnode.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/spritenode.h \
		entities/playerentity.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/animation.h \
		entities/creature.h \
		entities/emitternode.h \
		resources/particle.h \
		entities/combattextnode.h \
		entities/particlenode.h \
		resources/affectors.h \
		entities/uihealthpoints.h \
		entities/cameranode.h \
		controllers/playercontroller.h \
		controllers/aicontroller.h \
		controllers/bosscontroller.h \
		wave.h \
		utils.h \
		utils.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/introstate.o states/introstate.cpp

.obj/object.o: entities/object.cpp entities/object.h \
		entities/scenenode.h \
		events/commandqueue.h \
		events/command.h \
		events/category.h \
		entities/entity.h \
		entities/soundnode.h \
		resources/soundplayer.h \
		resources/resourceholder.h \
		resources/resourceidentifiers.h \
		resources/animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/object.o entities/object.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:



include_directories( ${QT_QTGUI_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_INCLUDE_DIR} .. ../core)

set( musicwidgettest_SRCS
    MusicWidget.cpp
    MusicWidgetTest.cpp

    ../core/Bar.cpp
    ../core/Chord.cpp
    ../core/Clef.cpp
    ../core/Global.cpp
    ../core/KeySignature.cpp
    ../core/Note.cpp
    ../core/Part.cpp
    ../core/PartGroup.cpp
    ../core/Sheet.cpp
    ../core/Staff.cpp
    ../core/StaffElement.cpp
    ../core/StaffSystem.cpp
    ../core/TimeSignature.cpp
    ../core/Voice.cpp
    ../core/VoiceBar.cpp
    ../core/VoiceElement.cpp

    ../Engraver.cpp
    ../Renderer.cpp
    ../MusicStyle.cpp
)

kde4_add_executable(musicwidgettest TEST ${musicwidgettest_SRCS})
target_link_libraries(musicwidgettest ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY})

########### next target ###############

set(SheetTest_test_SRCS
    SheetTest.cpp
    ../core/Global.cpp
    ../core/Part.cpp
    ../core/Sheet.cpp
    ../core/PartGroup.cpp
    ../core/Bar.cpp
    ../core/Voice.cpp
    ../core/Staff.cpp
    ../core/VoiceBar.cpp
    ../core/StaffElement.cpp
    ../core/Clef.cpp
    ../core/StaffSystem.cpp
    ../core/VoiceElement.cpp
    ../core/KeySignature.cpp
    ../core/TimeSignature.cpp
    ../core/Note.cpp
    ../core/Chord.cpp
)

kde4_add_unit_test(SheetTest TESTNAME shapes-musicshape-SheetTest ${SheetTest_test_SRCS})
target_link_libraries(SheetTest ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY})


########### next target ###############

set(VoiceBarTest_test_SRCS
    VoiceBarTest.cpp
    ../core/Global.cpp
    ../core/VoiceBar.cpp
    ../core/VoiceElement.cpp
    ../core/Sheet.cpp
    ../core/Bar.cpp
    ../core/PartGroup.cpp
    ../core/Part.cpp
    ../core/StaffSystem.cpp
    ../core/Staff.cpp
    ../core/StaffElement.cpp
    ../core/Voice.cpp
    ../core/Clef.cpp
    ../core/KeySignature.cpp
    ../core/TimeSignature.cpp
    ../core/Note.cpp
    ../core/Chord.cpp
)

kde4_add_unit_test(VoiceBarTest TESTNAME shapes-musicshape-VoiceBarTest ${VoiceBarTest_test_SRCS})
target_link_libraries(VoiceBarTest ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY})

########### next target ###############

set(MusicXmlWriterTest_test_SRCS
    MusicXmlWriterTest.cpp
    ../core/Global.cpp
    ../core/MusicXmlWriter.cpp
    ../core/Part.cpp
    ../core/Sheet.cpp
    ../core/PartGroup.cpp
    ../core/Bar.cpp
    ../core/Voice.cpp
    ../core/Staff.cpp
    ../core/VoiceBar.cpp
    ../core/StaffElement.cpp
    ../core/Clef.cpp
    ../core/StaffSystem.cpp
    ../core/VoiceElement.cpp
    ../core/Chord.cpp
    ../core/Note.cpp
    ../core/KeySignature.cpp
    ../core/TimeSignature.cpp
)

kde4_add_unit_test(MusicXmlWriterTest TESTNAME shapes-musicshape-MusicXmlWriterTest ${MusicXmlWriterTest_test_SRCS})
target_link_libraries(MusicXmlWriterTest ${QT_QTTEST_LIBRARY} ${KOODF_LIBS})


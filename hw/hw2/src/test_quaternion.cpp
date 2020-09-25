#include <QtTest/QtTest>
#include "quaternion.h"
#include <iostream>

class TestQuaternion: public QObject
{
    Q_OBJECT
    void testCreate();
    // void testAdd();
    // void testSub();
    // void testMult();
    // void testDiv();
};


void TestQuaternion::testCreate(){
    Quaternion q = Quaternion(1.0, 2.0, 3.0, 4.0);
    QVERIFY(q.getRe() == 1.0);
    QVERIFY(q.getIm(0) == 2.0);
    QVERIFY(q.getIm(1) == 3.0);
    QVERIFY(q.getIm(2) == 4.0);
}
//void TestQuaternion



QTEST_GUILESS_MAIN( TestQuaternion );
#include "test_quaternion.moc"
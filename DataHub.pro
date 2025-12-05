
QT       += core gui widgets


CONFIG += c++17


TARGET = DataHub

TEMPLATE = app


SOURCES += main.cpp


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

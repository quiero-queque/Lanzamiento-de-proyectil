#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

#include "funciones.hpp"

class MenuWidget : public QWidget {
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);
signals:
    void irJuego();
    void irLibre();
    void irInstrucciones();
    void salir();
};

class ModoJuegoWidget : public QWidget {
    Q_OBJECT
public:
    explicit ModoJuegoWidget(QWidget *parent = nullptr);
    void reiniciar();
signals:
    void irMenu();
private slots:
    void verificarRespuesta();
private:
    void cargarNivel();

    int        m_nivel;
    DatosNivel m_datos;

    QLabel      *m_lblNivel;
    QLabel      *m_lblPlaneta;
    QLabel      *m_lblEnunciado;
    QLabel      *m_lblFeedback;
    QLineEdit   *m_inputRespuesta;
    QPushButton *m_btnVerificar;
    QPushButton *m_btnMenu;
};

class ModoLibreWidget : public QWidget {
    Q_OBJECT
public:
    explicit ModoLibreWidget(QWidget *parent = nullptr);
signals:
    void irMenu();
private slots:
    void calcular();
private:
    QDoubleSpinBox *m_spinVelocidad;
    QDoubleSpinBox *m_spinAngulo;
    QComboBox      *m_comboPlaneta;
    QPushButton    *m_btnCalcular;
    QPushButton    *m_btnMenu;

    QLabel         *m_lblTiempo;
    QLabel         *m_lblAlcance;
    QLabel         *m_lblAltura;

    QLineSeries    *m_series;
    QChart         *m_chart;
    QChartView     *m_chartView;
    QValueAxis     *m_axisX;
    QValueAxis     *m_axisY;
};

class InstruccionesWidget : public QWidget {
    Q_OBJECT
public:
    explicit InstruccionesWidget(QWidget *parent = nullptr);
signals:
    void irMenu();
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;
private:
    QStackedWidget      *m_stack;
    MenuWidget          *m_menu;
    ModoJuegoWidget     *m_juego;
    ModoLibreWidget     *m_libre;
    InstruccionesWidget *m_instrucciones;
};

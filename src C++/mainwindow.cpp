#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QApplication>
#include <QPainter>
#include <QString>
#include <cmath>

// menu principal
MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent) {
    auto *lay = new QVBoxLayout(this);
    lay->setAlignment(Qt::AlignCenter);
    lay->setSpacing(14);

    auto *titulo = new QLabel("Lanzamiento Parabolico", this);
    QFont f = titulo->font();
    f.setPointSize(20);
    f.setBold(true);
    titulo->setFont(f);
    titulo->setAlignment(Qt::AlignCenter);

    auto *sub = new QLabel("gravedad variable - 9 planetas", this);
    sub->setAlignment(Qt::AlignCenter);

    auto *btnJuego = new QPushButton("Jugar",         this);
    auto *btnLibre = new QPushButton("Modo Libre",    this);
    auto *btnInstr = new QPushButton("Instrucciones", this);
    auto *btnSalir = new QPushButton("Salir",         this);

    for (auto *b : {btnJuego, btnLibre, btnInstr, btnSalir})
        b->setFixedWidth(200);

    lay->addWidget(titulo);
    lay->addWidget(sub);
    lay->addSpacing(20);
    lay->addWidget(btnJuego, 0, Qt::AlignCenter);
    lay->addWidget(btnLibre, 0, Qt::AlignCenter);
    lay->addWidget(btnInstr, 0, Qt::AlignCenter);
    lay->addWidget(btnSalir, 0, Qt::AlignCenter);

    connect(btnJuego, &QPushButton::clicked, this, &MenuWidget::irJuego);
    connect(btnLibre, &QPushButton::clicked, this, &MenuWidget::irLibre);
    connect(btnInstr, &QPushButton::clicked, this, &MenuWidget::irInstrucciones);
    connect(btnSalir, &QPushButton::clicked, this, &MenuWidget::salir);
}

// modo juego por niveles
ModoJuegoWidget::ModoJuegoWidget(QWidget *parent) : QWidget(parent), m_nivel(0) {
    auto *lay = new QVBoxLayout(this);

    m_lblNivel = new QLabel(this);
    QFont fn = m_lblNivel->font();
    fn.setBold(true);
    fn.setPointSize(13);
    m_lblNivel->setFont(fn);
    m_lblNivel->setAlignment(Qt::AlignCenter);

    m_lblPlaneta = new QLabel(this);
    m_lblPlaneta->setAlignment(Qt::AlignCenter);

    m_lblEnunciado = new QLabel(this);
    m_lblEnunciado->setWordWrap(true);
    m_lblEnunciado->setAlignment(Qt::AlignCenter);

    auto *rowResp = new QHBoxLayout();
    auto *lblInput = new QLabel("Tu respuesta:", this);
    m_inputRespuesta = new QLineEdit(this);
    m_inputRespuesta->setPlaceholderText("ej: 23.45");
    m_inputRespuesta->setFixedWidth(140);
    m_btnVerificar = new QPushButton("Verificar", this);
    rowResp->addStretch();
    rowResp->addWidget(lblInput);
    rowResp->addWidget(m_inputRespuesta);
    rowResp->addWidget(m_btnVerificar);
    rowResp->addStretch();

    m_lblFeedback = new QLabel(this);
    m_lblFeedback->setAlignment(Qt::AlignCenter);
    QFont ff = m_lblFeedback->font();
    ff.setBold(true);
    m_lblFeedback->setFont(ff);

    m_btnMenu = new QPushButton("Volver al menu", this);

    lay->addWidget(m_lblNivel);
    lay->addWidget(m_lblPlaneta);
    lay->addSpacing(10);
    lay->addWidget(m_lblEnunciado);
    lay->addSpacing(20);
    lay->addLayout(rowResp);
    lay->addWidget(m_lblFeedback);
    lay->addStretch();
    lay->addWidget(m_btnMenu, 0, Qt::AlignRight);

    connect(m_btnVerificar,   &QPushButton::clicked,      this, &ModoJuegoWidget::verificarRespuesta);
    connect(m_inputRespuesta, &QLineEdit::returnPressed,  this, &ModoJuegoWidget::verificarRespuesta);
    connect(m_btnMenu,        &QPushButton::clicked,      this, &ModoJuegoWidget::irMenu);

    cargarNivel();
}

void ModoJuegoWidget::reiniciar() {
    m_nivel = 0;
    m_btnVerificar->setEnabled(true);
    cargarNivel();
}

void ModoJuegoWidget::cargarNivel() {
    m_datos = obtener_nivel(m_nivel);
    m_lblNivel->setText(QString("Nivel %1 / 9").arg(m_nivel + 1));
    m_lblPlaneta->setText(
        QString("Planeta: %1  |  Gravedad: %2 m/s2")
            .arg(QString::fromStdString(lista_planeta[m_datos.planeta].getnombre()))
            .arg(lista_planeta[m_datos.planeta].getgravedad(), 0, 'f', 2)
    );
    m_lblEnunciado->setText(QString::fromStdString(m_datos.enunciado));
    m_lblFeedback->clear();
    m_inputRespuesta->clear();
    m_inputRespuesta->setFocus();
}

void ModoJuegoWidget::verificarRespuesta() {
    bool ok;
    float resp = m_inputRespuesta->text().replace(',', '.').toFloat(&ok);
    if (!ok) {
        m_lblFeedback->setStyleSheet("color: orange");
        m_lblFeedback->setText("Ingresa un numero valido.");
        return;
    }

    if (std::fabs(resp - m_datos.esperado) < 0.05f) {
        m_nivel++;
        if (m_nivel >= 9) {
            m_lblFeedback->setStyleSheet("color: green");
            m_lblFeedback->setText("Completaste los 9 niveles!");
            m_btnVerificar->setEnabled(false);
        } else {
            cargarNivel();
            m_lblFeedback->setStyleSheet("color: green");
            m_lblFeedback->setText("Correcto! Siguiente nivel cargado.");
        }
    } else {
        m_lblFeedback->setStyleSheet("color: red");
        m_lblFeedback->setText(
            QString("Incorrecto. Respuesta esperada: %1").arg(m_datos.esperado, 0, 'f', 3)
        );
    }
}

// modo libre
ModoLibreWidget::ModoLibreWidget(QWidget *parent) : QWidget(parent) {
    auto *lay = new QHBoxLayout(this);

    auto *panel = new QGroupBox("Parametros", this);
    auto *vl    = new QVBoxLayout(panel);

    auto *lblV = new QLabel("velocidad inicial (m/s)", this);
    m_spinVelocidad = new QDoubleSpinBox(this);
    m_spinVelocidad->setRange(1.0, 500.0);
    m_spinVelocidad->setValue(30.0);

    auto *lblA = new QLabel("angulo (grados)", this);
    m_spinAngulo = new QDoubleSpinBox(this);
    m_spinAngulo->setRange(1.0, 89.0);
    m_spinAngulo->setValue(45.0);

    auto *lblP = new QLabel("planeta", this);
    m_comboPlaneta = new QComboBox(this);
    for (int i = 0; i < 9; i++)
        m_comboPlaneta->addItem(QString::fromStdString(lista_planeta[i].getnombre()));

    m_btnCalcular = new QPushButton("Calcular", this);
    m_btnMenu     = new QPushButton("Volver al menu", this);

    m_lblTiempo  = new QLabel("tiempo: --",     this);
    m_lblAlcance = new QLabel("alcance: --",    this);
    m_lblAltura  = new QLabel("altura max: --", this);

    vl->addWidget(lblV);
    vl->addWidget(m_spinVelocidad);
    vl->addWidget(lblA);
    vl->addWidget(m_spinAngulo);
    vl->addWidget(lblP);
    vl->addWidget(m_comboPlaneta);
    vl->addWidget(m_btnCalcular);
    vl->addSpacing(10);
    vl->addWidget(m_lblTiempo);
    vl->addWidget(m_lblAlcance);
    vl->addWidget(m_lblAltura);
    vl->addStretch();
    vl->addWidget(m_btnMenu);
    panel->setFixedWidth(220);

    // grafico de la trayectoria
    m_series = new QLineSeries();

    m_chart = new QChart();
    m_chart->addSeries(m_series);
    m_chart->legend()->hide();
    m_chart->setTitle("Trayectoria");

    m_axisX = new QValueAxis();
    m_axisX->setTitleText("distancia (m)");
    m_axisX->setLabelFormat("%.0f");
    m_axisX->setRange(0, 100);

    m_axisY = new QValueAxis();
    m_axisY->setTitleText("altura (m)");
    m_axisY->setLabelFormat("%.0f");
    m_axisY->setRange(0, 50);

    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_chart->addAxis(m_axisY, Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);

    m_chartView = new QChartView(m_chart, this);
    m_chartView->setRenderHint(QPainter::Antialiasing);

    lay->addWidget(panel);
    lay->addWidget(m_chartView);

    connect(m_btnCalcular, &QPushButton::clicked, this, &ModoLibreWidget::calcular);
    connect(m_btnMenu,     &QPushButton::clicked, this, &ModoLibreWidget::irMenu);
}

void ModoLibreWidget::calcular() {
    float v = static_cast<float>(m_spinVelocidad->value());
    float a = static_cast<float>(m_spinAngulo->value());
    int   idx = m_comboPlaneta->currentIndex();
    float g   = lista_planeta[idx].getgravedad();

    float t  = calcular_tiempo(v, a, g);
    float xm = calcular_alcancemax(v, a, g);
    float ym = calcular_alturamax(v, a, g);

    m_lblTiempo ->setText(QString("tiempo: %1 s")     .arg(t,  0, 'f', 2));
    m_lblAlcance->setText(QString("alcance: %1 m")    .arg(xm, 0, 'f', 2));
    m_lblAltura ->setText(QString("altura max: %1 m") .arg(ym, 0, 'f', 2));

    // actualizar puntos del grafico
    m_series->clear();
    std::vector<QPointF> puntos = calcular_trayectoria(v, a, g);
    for (const QPointF &p : puntos)
        m_series->append(p);

    m_axisX->setRange(0, xm * 1.05f);
    m_axisY->setRange(0, ym * 1.25f);
}

// instrucciones
InstruccionesWidget::InstruccionesWidget(QWidget *parent) : QWidget(parent) {
    auto *lay = new QVBoxLayout(this);
    lay->setAlignment(Qt::AlignCenter);

    auto *titulo = new QLabel("Instrucciones", this);
    QFont f = titulo->font();
    f.setBold(true);
    f.setPointSize(15);
    titulo->setFont(f);
    titulo->setAlignment(Qt::AlignCenter);

    auto *texto = new QLabel(
        "El juego tiene 9 niveles, uno por cada planeta del sistema solar.\n\n"
        "En cada nivel se te da un enunciado con velocidad y angulo fijos.\n"
        "Debes calcular a mano el valor pedido usando las formulas de\n"
        "movimiento parabolico y escribir el resultado.\n\n"
        "Formulas disponibles:\n"
        "  Tiempo de vuelo:  t = 2*v*sin(angulo) / g\n"
        "  Altura maxima:    y = v^2 * sin^2(angulo) / 2g\n"
        "  Alcance maximo:   x = v^2 * sin(2*angulo) / g\n"
        "  Altura en t:      y = v*t*sin(angulo) - g*t^2/2\n"
        "  Alcance en t:     x = v*t*cos(angulo)\n\n"
        "El margen de error aceptado es 0.05.\n"
        "El numero PI esta aproximado a 3.1416.",
        this
    );
    texto->setAlignment(Qt::AlignCenter);
    texto->setWordWrap(true);

    auto *btnMenu = new QPushButton("Volver al menu", this);
    btnMenu->setFixedWidth(160);

    lay->addWidget(titulo);
    lay->addSpacing(10);
    lay->addWidget(texto);
    lay->addSpacing(20);
    lay->addWidget(btnMenu, 0, Qt::AlignCenter);

    connect(btnMenu, &QPushButton::clicked, this, &InstruccionesWidget::irMenu);
}

// ventana principal con el QStackedWidget
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Lanzamiento Parabolico");
    resize(900, 560);

    m_stack         = new QStackedWidget(this);
    m_menu          = new MenuWidget(this);
    m_juego         = new ModoJuegoWidget(this);
    m_libre         = new ModoLibreWidget(this);
    m_instrucciones = new InstruccionesWidget(this);

    m_stack->addWidget(m_menu);           // 0
    m_stack->addWidget(m_juego);          // 1
    m_stack->addWidget(m_libre);          // 2
    m_stack->addWidget(m_instrucciones);  // 3
    setCentralWidget(m_stack);

    connect(m_menu, &MenuWidget::irJuego, this, [this]{
        m_juego->reiniciar();
        m_stack->setCurrentIndex(1);
    });
    connect(m_menu, &MenuWidget::irLibre,         this, [this]{ m_stack->setCurrentIndex(2); });
    connect(m_menu, &MenuWidget::irInstrucciones, this, [this]{ m_stack->setCurrentIndex(3); });
    connect(m_menu, &MenuWidget::salir,           qApp, &QApplication::quit);

    connect(m_juego,         &ModoJuegoWidget::irMenu,     this, [this]{ m_stack->setCurrentIndex(0); });
    connect(m_libre,         &ModoLibreWidget::irMenu,     this, [this]{ m_stack->setCurrentIndex(0); });
    connect(m_instrucciones, &InstruccionesWidget::irMenu, this, [this]{ m_stack->setCurrentIndex(0); });
}

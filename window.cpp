#include "window.h"
#include <QApplication>
#include <QMouseEvent>
#include <QPalette>
#include <QPaintEvent>
#include <QPainter>

Window::Window(QWidget *parent)
    : QWidget{parent},
      m_rubberband(NULL),
      m_in_rubberband(false)
{
    setGeometry(0, 0, 400, 400);
    QPalette pal = QPalette();

    pal.setColor(QPalette::Window, Qt::black);
    
    setAutoFillBackground(true); 
    setPalette(pal);
}


void Window::mousePressEvent(QMouseEvent *event)
{
    m_in_rubberband = true;
    m_rubberband_handle = event->pos();
    m_rubberband_anchor = event->pos();
    if (!m_rubberband) {
        m_rubberband = new QRubberBand(QRubberBand::Rectangle, this);
    }
    m_rubberband->setGeometry(QRect(m_rubberband_anchor, QSize()));
    m_rubberband->show();
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
    if (m_in_rubberband) {
        int x = event->pos().x(), y = event->pos().y();
        m_rubberband_handle = QPoint(x, y);
        m_rubberband->setGeometry(QRect(m_rubberband_anchor, m_rubberband_handle).normalized());
    }
}

void Window::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (m_in_rubberband) {
        m_in_rubberband = false; 
        m_rubberband->hide();
    }
}

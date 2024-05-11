#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QRubberBand>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint m_rubberband_anchor;
    QPoint m_rubberband_handle;
    QRubberBand *m_rubberband;
    bool m_in_rubberband;
};

#endif // WINDOW_H

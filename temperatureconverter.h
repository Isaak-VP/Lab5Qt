#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <QMainWindow>

class QComboBox;
class QLineEdit;

class TemperatureConverter : public QMainWindow {
    Q_OBJECT

public:
    explicit TemperatureConverter(QWidget *parent = nullptr);

private slots:
    void convertTemperature();

private:
    QComboBox *comboBoxFrom;
    QComboBox *comboBoxTo;
    QLineEdit *lineEditInput;
    QLineEdit *lineEditOutput;
};

#endif // TEMPERATURECONVERTER_H

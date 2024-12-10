#include "temperatureconverter.h"
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDoubleValidator>

TemperatureConverter::TemperatureConverter(QWidget *parent) : QMainWindow(parent) {
    auto *layout = new QVBoxLayout;

    comboBoxFrom = new QComboBox;
    comboBoxFrom->addItems({"Цельсій", "Кельвін", "Фаренгейт"});
    layout->addWidget(comboBoxFrom);

    comboBoxTo = new QComboBox;
    comboBoxTo->addItems({"Цельсій", "Кельвін", "Фаренгейт"});
    layout->addWidget(comboBoxTo);

    lineEditInput = new QLineEdit;
    lineEditInput->setValidator(new QDoubleValidator(-1000, 1000, 2, this));
    layout->addWidget(lineEditInput);

    lineEditOutput = new QLineEdit;
    lineEditOutput->setReadOnly(true);
    layout->addWidget(lineEditOutput);

    auto *convertButton = new QPushButton("Конвертувати");
    layout->addWidget(convertButton);

    auto *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(convertButton, &QPushButton::clicked, this, &TemperatureConverter::convertTemperature);
}

void TemperatureConverter::convertTemperature() {
    double input = lineEditInput->text().toDouble();
    QString fromUnit = comboBoxFrom->currentText();
    QString toUnit = comboBoxTo->currentText();

    double result = 0.0;
    if (fromUnit == "Цельсій" && toUnit == "Кельвін") {
        result = input + 273.15;
    } else if (fromUnit == "Цельсій" && toUnit == "Фаренгейт") {
        result = input * 9 / 5 + 32;
    } else if (fromUnit == "Кельвін" && toUnit == "Цельсій") {
        result = input - 273.15;
    } else if (fromUnit == "Кельвін" && toUnit == "Фаренгейт") {
        result = (input - 273.15) * 9 / 5 + 32;
    } else if (fromUnit == "Фаренгейт" && toUnit == "Цельсій") {
        result = (input - 32) * 5 / 9;
    } else if (fromUnit == "Фаренгейт" && toUnit == "Кельвін") {
        result = (input - 32) * 5 / 9 + 273.15;
    } else {
        result = input;  // якщо одиниці однакові
    }

    lineEditOutput->setText(QString::number(result, 'f', 2));
}

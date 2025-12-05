#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFont>

// Класс для создания красивой кнопки меню
class MenuButton : public QPushButton {
public:
    MenuButton(const QString &title, const QString &description, QWidget *parent = nullptr)
        : QPushButton(parent) {

        // Настройка текста: Жирный заголовок + описание
        QString text = QString("<b>%1</b><br><small>%2</small>").arg(title, description);
        this->setText(text);

        // Устанавливаем высоту и стиль
        this->setMinimumSize(250, 150);
        this->setStyleSheet(
            "QPushButton {"
            "  background-color: #4A90E2;" // Синий цвет как на картинке
            "  color: white;"
            "  border-radius: 10px;"
            "  padding: 10px;"
            "  text-align: left;"
            "}"
            "QPushButton:hover {"
            "  background-color: #357ABD;" // Темнее при наведении
            "}"
            );
    }
};

// Главное окно приложения
class MainWindow : public QWidget {
public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // Настройка окна
        this->setWindowTitle("DataHub ВУЗ-ов РК");
        this->resize(900, 600);
        this->setStyleSheet("background-color: #F0F2F5;"); // Светлый фон

        // Основная разметка (Сетка)
        QGridLayout *layout = new QGridLayout(this);
        layout->setSpacing(20);

        // Заголовок
        QLabel *header = new QLabel("DataHub ВУЗ-ов \"РК\"", this);
        header->setStyleSheet("font-size: 24px; font-weight: bold; color: #333;");
        header->setAlignment(Qt::AlignCenter);
        layout->addWidget(header, 0, 0, 1, 3); // Занимает всю ширину сверху

        // --- Создание кнопок (6 разделов) ---

        // 1. Об университете
        createButton(layout, 1, 0, "1. Об университете", "Миссия, история, лидерство");

        // 2. Академ. программы
        createButton(layout, 1, 1, "2. Академ. программы", "Перечень курсов и программ");

        // 3. Приём и поступление
        createButton(layout, 1, 2, "3. Приём и поступление", "Требования, сроки, гранты");

        // 4. 3D-тур
        createButton(layout, 2, 0, "4. 3D-тур", "Виртуальное путешествие");

        // 5. Международное сотрудничество
        createButton(layout, 2, 1, "5. Сотрудничество", "Программы обмена");

        // 6. Функция сравнения
        createButton(layout, 2, 2, "6. Сравнение", "Сравнить вузы и программы");
    }

private:
    // Вспомогательная функция для добавления кнопки в сетку
    void createButton(QGridLayout *layout, int row, int col, const QString &title, const QString &desc) {
        MenuButton *btn = new MenuButton(title, desc, this);
        layout->addWidget(btn, row, col);

        // Подключаем нажатие кнопки к простой функции (лямбда-выражение)
        connect(btn, &QPushButton::clicked, [=]() {
            QMessageBox::information(this, "Раздел выбран", "Вы перешли в раздел:\n" + title);
            // В будущем здесь будет код открытия нового окна
        });
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
